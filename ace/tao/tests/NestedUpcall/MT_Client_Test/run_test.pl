eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# run_test.pl,v 1.14 2001/03/05 03:23:48 brunsch Exp
# -*- perl -*-

use lib '../../../../bin';
use PerlACE::Run_Test;

$status = 0;
$ior1file = PerlACE::LocalFile ("server1.ior");
$ior2file = PerlACE::LocalFile ("server2.ior");

# Make sure the files are gone
unlink $ior1file;
unlink $ior2file;

$SV1 = new PerlACE::Process ("server", "-o $ior1file");
$SV2 = new PerlACE::Process ("server", "-o $ior2file");
$CL = new PerlACE::Process ("client", "-f $ior1file -g $ior2file -n 2 -i 10 -s 5");

$SV1->Spawn ();
$SV2->Spawn ();

if (PerlACE::waitforfile_timed ($ior1file, 5) == -1) {
    print STDERR "ERROR: cannot find file <$ior1file>\n";
    $SV1->Kill ();
    $SV2->Kill ();
    exit 1;
}

if (PerlACE::waitforfile_timed ($ior2file, 5) == -1) {
    print STDERR "ERROR: cannot find file <$ior2file>\n";
    $SV1->Kill ();
    $SV2->Kill ();
    exit 1;
}

$client = $CL->SpawnWaitKill (60);

$server1 = $SV1->TerminateWaitKill (5);
$server2 = $SV2->TerminateWaitKill (5);

# Clean up
unlink $ior1file;
unlink $ior2file;

if ($client != 0) {
    print STDERR "ERROR: client returned $client\n";
    $status = 1;
}

if ($server1 != 0) {
    print STDERR "ERROR: server 1 returned $server1\n";
    $status = 1;
}

if ($server2 != 0) {
    print STDERR "ERROR: server 2 returned $server2\n";
    $status = 1;
}

exit $status;
