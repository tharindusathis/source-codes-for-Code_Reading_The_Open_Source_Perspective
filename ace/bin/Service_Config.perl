eval '(exit $?0)' && eval 'exec perl -pi -S $0 ${1+"$@"}'
    & eval 'exec perl -pi -S $0 $argv:q'
    if 0;

# Service_Config.perl,v 1.5 1998/12/30 03:34:27 levine Exp
#
# You may want to run the "find" command with this script, which maybe
# something like this:
#
# find . -type f \( -name "*.i" -o -name "*.h" -o -name "*.C" -o -name "*.cc" -o -name "*.c" -o -name "*.cpp" -o -name "*.hpp" -o -name "*.ipp" \) -print | xargs $ACE_ROOT/bin/Service_Config.perl

# The first three lines above let this script run without specifying the
# full path to perl, as long as it is in the user's PATH.
# Taken from perlrun man page.

s/ACE_Service_Config::run_reactor_event_loop/ACE_Reactor::run_event_loop/g;
s/ACE_Service_Config::end_reactor_event_loop/ACE_Reactor::end_event_loop/g;
s/ACE_Service_Config::reactor_event_loop_done/ACE_Reactor::event_loop_done/g;
s/ACE_Service_Config::run_proactor_event_loop/ACE_Proactor::run_proactor_event_loop/g;
s/ACE_Service_Config::end_proactor_event_loop/ACE_Proactor::end_proactor_event_loop/g;
s/ACE_Service_Config::proactor_event_loop_done/ACE_Proactor::event_loop_done/g;
s/ACE_Service_Config::run_reactorEx_event_loop/ACE_ReactorEx::run_event_loop/g;
s/ACE_Service_Config::end_reactorEx_event_loop/ACE_ReactorEx::end_event_loop/g;
s/ACE_Service_Config::reactorEx_event_loop_done/ACE_ReactorEx::event_loop_done/g;
s/ACE_Service_Config::reactor/ACE_Reactor::instance/g;
s/ACE_Service_Config::proactor/ACE_Proactor::instance/g;
s/ACE_Service_Config::reactorEx/ACE_ReactorEx::instance/g;
s/ACE_Service_Config::svc_rep/ACE_Service_Repository::instance/g;
s/ACE_Service_Config::thr_mgr/ACE_Thread_Manager::instance/g;
s/ACE_Service_Config::alloc/ACE_Allocator::instance/g;

