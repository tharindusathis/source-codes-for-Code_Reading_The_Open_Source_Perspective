// client.cpp,v 1.6 2000/11/10 19:55:21 coryan Exp

#include "client_i.h"
#include "ace/Get_Opt.h"
#include "ace/Task.h"

ACE_RCSID(Simple, client, "client.cpp,v 1.6 2000/11/10 19:55:21 coryan Exp")

static const char *ior = "file://test.ior";
// Server IOR.

static int shutdown_server = 0;
// Flag to tell server to shutdown.

static CORBA::UShort call_count = 5;
// # of nested calls to be made.

static int quiet = 0;
// The test is quiet...

class Client_Task
{
public:
  Client_Task (client_ptr c,
               server_ptr s);
  int svc (void);

private:
  client_var client_;
  server_var server_;
};

Client_Task::Client_Task (client_ptr c,
                          server_ptr s)
  : client_ (client::_duplicate (c)),
    server_ (server::_duplicate (s))
{
}

int
Client_Task::svc (void)
{
  ACE_TRY_NEW_ENV
    {
      if (!quiet)
        ACE_DEBUG ((LM_DEBUG,
                    "(%t) Client_Task::svc calling start -> time to live = %d\n",
                    call_count));

      // Now, we can invoke an operation on the remote side.
      this->server_->start (this->client_.in (),
                            call_count,
                            ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Client_Task::svc");
      return -1;
    }
  ACE_ENDTRY;
  return 0;
}

static int
parse_args (int argc,
            char **argv)
{
  ACE_Get_Opt get_opts (argc, argv, "qxn:k:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'q':
        quiet = 1;
        break;

      case 'x':
        shutdown_server = 1;
        break;

      case 'n':
        call_count = ACE_OS::atoi (get_opts.optarg);
        break;

      case 'k':
        ior = get_opts.optarg;
        break;

      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s"
                           " [-n number of nested calls]"
                           " [-k ior]"
                           " [-q (quite)]"
                           " [-x (shutdown server)]"
                           "\n",
                           argv[0]),
                          -1);
      }

  if (ior == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "%s: no nested up calls server ior specified\n",
                       argv[0]),
                      -1);

  // Indicates successful parsing of command line.
  return 0;
}

int
main (int argc,
      char **argv)
{
  ACE_TRY_NEW_ENV
    {
      CORBA::ORB_var orb = CORBA::ORB_init (argc,
                                            argv,
                                            0,
                                            ACE_TRY_ENV);
      ACE_TRY_CHECK;

      int result = parse_args (argc,
                               argv);
      if (result != 0)
        return result;

      CORBA::Object_var object = orb->resolve_initial_references ("RootPOA",
                                                                  ACE_TRY_ENV);
      ACE_TRY_CHECK;

      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (object.in (),
                                      ACE_TRY_ENV);
      ACE_TRY_CHECK;

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      poa_manager->activate (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      object = orb->string_to_object (ior,
                                      ACE_TRY_ENV);
      ACE_TRY_CHECK;

      server_var server = server::_narrow (object.in (),
                                           ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Create an client object to hand to the other side...
      client_i client_servant (quiet,
                               server.in ());

      client_var client_object = client_servant._this (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      Client_Task client_tasks (client_object.in (),
                                server.in ());

      client_tasks.svc ();

      if (shutdown_server)
        {
          server->shutdown (ACE_TRY_ENV);
          ACE_TRY_CHECK;
        }

      root_poa->destroy (1,
                         1,
                         ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "client::main");
      return -1;
    }
  ACE_ENDTRY;
  return 0;
}
