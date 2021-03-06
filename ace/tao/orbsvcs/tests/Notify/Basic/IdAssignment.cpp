// IdAssignment.cpp,v 1.2 2000/08/22 21:41:21 pradeep Exp

#include "ace/Arg_Shifter.h"
#include "ace/Get_Opt.h"
#include "orbsvcs/CosNamingC.h"
#include "orbsvcs/CosNotifyCommC.h"
#include "IdAssignment.h"

ACE_RCSID (Notify_Tests, IdAssignment, "IdAssignment.cpp,v 1.2 2000/08/22 21:41:21 pradeep Exp")

IdAssignment::IdAssignment (void)
  :iter_ (3),
   ec_count_ (3),
   consumer_admin_count_ (3),
   supplier_admin_count_ (3)
{
}

IdAssignment::~IdAssignment ()
{
}

int
IdAssignment::parse_args(int argc, char *argv[])
{
    ACE_Arg_Shifter arg_shifter (argc, argv);

    char *current_arg = 0;
    while (arg_shifter.is_anything_left ())
    {
      if ((current_arg = arg_shifter.get_the_parameter ("-iter")))
        {
          this->iter_ = ACE_OS::atoi (current_arg);
          // The number of times to repeat the test
          arg_shifter.consume_arg ();
        }
      if ((current_arg = arg_shifter.get_the_parameter ("-ec_count")))
        {
          this->ec_count_ = ACE_OS::atoi (current_arg);
          arg_shifter.consume_arg ();
        }
      if ((current_arg = arg_shifter.get_the_parameter ("-ca_count")))
        {
          this->consumer_admin_count_ = ACE_OS::atoi (current_arg);
          arg_shifter.consume_arg ();
        }
      if ((current_arg = arg_shifter.get_the_parameter ("-sa_count")))
        {
          this->supplier_admin_count_ = ACE_OS::atoi (current_arg);
          arg_shifter.consume_arg ();
        }
      else if (arg_shifter.cur_arg_strncasecmp ("-?") == 0)
        {
          ACE_DEBUG((LM_DEBUG,
                     "usage: %s "
                     "-iter <count>",
                     "-ec_count <count>",
                     "-ca_count <count>",
                     "-sa_count <count>\n",
                     argv[0], argv[0]));

          arg_shifter.consume_arg ();

          return -1;
        }
      else
        {
            arg_shifter.ignore_arg ();
        }
    }
    return 0;
}

void
IdAssignment::init(int argc, char *argv[], CORBA::Environment &ACE_TRY_ENV)
{
  CORBA::ORB_var orb = CORBA::ORB_init(argc, argv, "", ACE_TRY_ENV);
  ACE_CHECK;

  CORBA::Object_var rootObj = orb->resolve_initial_references("NameService",
                                                              ACE_TRY_ENV);
  ACE_CHECK;

  if (CORBA::is_nil(rootObj.in()))
    {
      ACE_ERROR ((LM_ERROR,
                  " (%P|%t) Unable to resolve naming service !\n"));
      return;

    }
  CosNaming::NamingContext_var rootNC =
    CosNaming::NamingContext::_narrow(rootObj.in(), ACE_TRY_ENV);
  ACE_CHECK;

  CosNaming::Name name(1);
  name.length(1);
  name[0].id = CORBA::string_dup("NotifyEventChannelFactory");

  CORBA::Object_var obj = rootNC->resolve(name, ACE_TRY_ENV);
  ACE_CHECK;

  if (CORBA::is_nil(obj.in()))
    {
      ACE_ERROR((LM_ERROR,
                         " (%P|%t) Unable to locate Notify_Service \n"));
      return;
    }

  notify_factory_ = CosNotifyChannelAdmin::EventChannelFactory::_narrow(
                                                         obj.in(),
                                                         ACE_TRY_ENV);
  ACE_CHECK;

}

CosNotifyChannelAdmin::ChannelID
IdAssignment::create_ec(CORBA::Environment &ACE_TRY_ENV)
{
  CosNotifyChannelAdmin::ChannelID id;
  CosNotification::QoSProperties initial_qos;
  CosNotification::AdminProperties initial_admin;
  CosNotifyChannelAdmin::EventChannel_var ec =
    notify_factory_->create_channel(initial_qos,
                                   initial_admin,
                                   id,
                                   ACE_TRY_ENV);
//  ACE_CHECK_RETURN;

  return id;
}


void
IdAssignment::destroy_ec(CosNotifyChannelAdmin::ChannelID id,
                          CORBA::Environment &ACE_TRY_ENV)
{
  CosNotifyChannelAdmin::EventChannel_var ec =
    notify_factory_->get_event_channel(id, ACE_TRY_ENV);

  ACE_CHECK;

  if (CORBA::is_nil(ec.in()))
    {
      ACE_ERROR((LM_ERROR,
                 " (%P|%t) Unable to find event channel\n"));
      return;

    }

   ec->destroy(ACE_TRY_ENV);
   ACE_CHECK;
}

CosNotifyChannelAdmin::AdminID
IdAssignment::create_supplier_admin (CosNotifyChannelAdmin::ChannelID channel_id,
                                     CORBA::Environment &ACE_TRY_ENV)
{
  CosNotifyChannelAdmin::AdminID adminid;
  CosNotifyChannelAdmin::InterFilterGroupOperator ifgop =
          CosNotifyChannelAdmin::OR_OP;

  CosNotifyChannelAdmin::EventChannel_var ec =
    notify_factory_->get_event_channel(channel_id, ACE_TRY_ENV);

  ACE_CHECK_RETURN (0);

  if (CORBA::is_nil(ec.in()))
    {
      ACE_ERROR((LM_ERROR,
                 " (%P|%t) Unable to find event channel\n"));
      return 0;

    }

  CosNotifyChannelAdmin::SupplierAdmin_var supplier_admin =
    ec->new_for_suppliers (ifgop, adminid, ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  if (CORBA::is_nil (supplier_admin.in()))
    ACE_ERROR_RETURN ((LM_ERROR,
                       " (%P|%t) Unable to create supplier admin\n"),0);

  ACE_DEBUG((LM_DEBUG, "created supplier admin\n"));

  return adminid;
}

CosNotifyChannelAdmin::AdminID
IdAssignment::create_consumer_admin (CosNotifyChannelAdmin::ChannelID channel_id,
                                     CORBA::Environment &ACE_TRY_ENV)
{
  CosNotifyChannelAdmin::AdminID adminid;
  CosNotifyChannelAdmin::InterFilterGroupOperator ifgop =
          CosNotifyChannelAdmin::OR_OP;

  CosNotifyChannelAdmin::EventChannel_var ec =
    notify_factory_->get_event_channel(channel_id, ACE_TRY_ENV);

  ACE_CHECK_RETURN (0);

  if (CORBA::is_nil(ec.in()))
    {
      ACE_ERROR((LM_ERROR,
                 " (%P|%t) Unable to find event channel\n"));
      return 0;

    }

  CosNotifyChannelAdmin::ConsumerAdmin_var consumer_admin =
    ec->new_for_consumers (ifgop, adminid, ACE_TRY_ENV);
  ACE_CHECK_RETURN (0);

  if (CORBA::is_nil (consumer_admin.in()))
    ACE_ERROR_RETURN ((LM_ERROR,
                       " (%P|%t) Unable to create consumer admin\n"),0);

  ACE_DEBUG((LM_DEBUG, "created consumer admin\n"));

  return adminid;
}


void
IdAssignment::destroy_consumer_admin (CosNotifyChannelAdmin::ChannelID channel_id,
                                      CosNotifyChannelAdmin::AdminID admin_id,
                                      CORBA::Environment &ACE_TRY_ENV)
{
  CosNotifyChannelAdmin::EventChannel_var ec =
    notify_factory_->get_event_channel(channel_id, ACE_TRY_ENV);

  ACE_CHECK;

  if (CORBA::is_nil(ec.in()))
    {
      ACE_ERROR((LM_ERROR,
                 " (%P|%t) Unable to find event channel\n"));
      return;

    }

  CosNotifyChannelAdmin::ConsumerAdmin_var consumer_admin =
    ec->get_consumeradmin (admin_id, ACE_TRY_ENV);
  ACE_CHECK;

  if (CORBA::is_nil (consumer_admin.in()))
    ACE_ERROR ((LM_ERROR,
                       " (%P|%t) Unable to get consumer admin\n"));

  consumer_admin->destroy(ACE_TRY_ENV);
  ACE_CHECK;

  ACE_DEBUG((LM_DEBUG, "destroyed consumer admin\n"));
}


void
IdAssignment::destroy_supplier_admin (CosNotifyChannelAdmin::ChannelID channel_id,
                                      CosNotifyChannelAdmin::AdminID admin_id,
                                      CORBA::Environment &ACE_TRY_ENV)
{
  CosNotifyChannelAdmin::EventChannel_var ec =
    notify_factory_->get_event_channel(channel_id, ACE_TRY_ENV);

  ACE_CHECK;

  if (CORBA::is_nil(ec.in()))
    {
      ACE_ERROR((LM_ERROR,
                 " (%P|%t) Unable to find event channel\n"));
    }

  CosNotifyChannelAdmin::SupplierAdmin_var supplier_admin =
    ec->get_supplieradmin (admin_id, ACE_TRY_ENV);
  ACE_CHECK;

  if (CORBA::is_nil (supplier_admin.in()))
    ACE_ERROR ((LM_ERROR,
                " (%P|%t) Unable to get supplier admin\n"));

  supplier_admin->destroy(ACE_TRY_ENV);
  ACE_CHECK;

  ACE_DEBUG((LM_DEBUG, "destroyed supplier admin\n"));
}

void
IdAssignment::run_test(CORBA::Environment &ACE_TRY_ENV)
{
  CosNotifyChannelAdmin::ChannelID* ec_id =
    new CosNotifyChannelAdmin::ChannelID [this->ec_count_];

  CosNotifyChannelAdmin::AdminID* consumer_admin_id =
    new CosNotifyChannelAdmin::AdminID [this->consumer_admin_count_];

  CosNotifyChannelAdmin::AdminID* supplier_admin_id =
    new CosNotifyChannelAdmin::AdminID [this->supplier_admin_count_];

  //*************** ************ ************ ************ ************

  int i;
  for (i = 0; i < this->iter_; ++i)
    {
      int ec_count;
      for (ec_count = 0; ec_count < this->ec_count_; ++ec_count)
        {
          ec_id [ec_count] = create_ec(ACE_TRY_ENV);
          ACE_CHECK;

          // connect <consumer_admin_count_> number of consumers to the current ec.
          for (int cons_count = 0; cons_count < this->consumer_admin_count_; ++cons_count)
            {
              consumer_admin_id [cons_count] = create_consumer_admin (ec_id [ec_count],
                                                                      ACE_TRY_ENV);
              ACE_CHECK;
            }

          // connect <supplier_admin_count_> number of suppliers to the current ec.
          for (int supp_count = 0; supp_count < this->supplier_admin_count_; ++supp_count)
            {
              supplier_admin_id [supp_count] = create_supplier_admin (ec_id [ec_count],
                                                                      ACE_TRY_ENV);
              ACE_CHECK;
            }
        }

      // destroy the ec, the admins should destroy too.
      for (ec_count = 0; ec_count < this->ec_count_; ++ec_count)
        {
          this->destroy_ec (ec_id [ec_count], ACE_TRY_ENV);
          ACE_CHECK;
        }

    } // for


  //*************** ************ ************ ************ ************ ************
  // repeat, but this time destroy the admins explicity
  for (i = 0; i < this->iter_; ++i)
    {
      int ec_count;
      for (ec_count = 0; ec_count < this->ec_count_; ++ec_count)
        {
          ec_id [ec_count] = create_ec(ACE_TRY_ENV);
          ACE_CHECK;

          int cons_count, supp_count;
          // connect <consumer_admin_count_> number of consumers to the current ec.
          for (cons_count = 0; cons_count < this->consumer_admin_count_; ++cons_count)
            {
              consumer_admin_id [cons_count] = create_consumer_admin (ec_id [ec_count],
                                                                      ACE_TRY_ENV);
              ACE_CHECK;
            }

          // connect <supplier_admin_count_> number of suppliers to the current ec.
          for (supp_count = 0; supp_count < this->supplier_admin_count_; ++supp_count)
            {
              supplier_admin_id [supp_count] = create_supplier_admin (ec_id [ec_count],
                                                                      ACE_TRY_ENV);
              ACE_CHECK;
            }
          // destroy the admins

          // destroy consumer admins
          for (cons_count = 0; cons_count < this->consumer_admin_count_; ++cons_count)
            {
              destroy_consumer_admin (ec_id [ec_count],consumer_admin_id [cons_count],
                                      ACE_TRY_ENV);
              ACE_CHECK;
            }

          // destroy supplier admins
          for (supp_count = 0; supp_count < this->supplier_admin_count_; ++supp_count)
            {
              destroy_supplier_admin (ec_id [ec_count], supplier_admin_id [supp_count],
                                       ACE_TRY_ENV);
              ACE_CHECK;
            }

        } // ec_count

      // destroy the ec,
      for (ec_count = 0; ec_count < this->ec_count_; ++ec_count)
        {
          this->destroy_ec (ec_id [ec_count], ACE_TRY_ENV);
          ACE_CHECK;
        }

    } // for

  //*************** ************ ************ ************ ************ ************
}

int main(int argc, char* argv[])
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      IdAssignment test;

      test.parse_args (argc, argv);

      test.init(argc, argv, ACE_TRY_ENV);
      ACE_TRY_CHECK;

      test.run_test(ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Caught exception:");
      return 1;
    }
  ACE_ENDTRY;
  ACE_DEBUG ((LM_DEBUG, "IdAssignment test suceeded\n"));
  return 0;
}
