// createfile.cpp,v 4.4 1998/08/01 00:57:17 gonzo Exp

#include <stdio.h>
#include <string.h>
#include "ace/ACE.h"

ACE_RCSID(Dump_Restore, createfile, "createfile.cpp,v 4.4 1998/08/01 00:57:17 gonzo Exp")

int 
main (int argc, char **argv)
{
  FILE *infile, *outfile;
  char buf[BUFSIZ];

  if ((infile = fopen (argv[1], "r")) == NULL)
    return -1;

  if ((outfile = fopen (argv[2], "w")) == NULL)
    return -1;

  int count = 0;
  while (::fgets (buf, BUFSIZ, infile))
    {
      buf[::strlen(buf) - 1] = '\0';
      fputs (buf, outfile);
      if (count % 2 == 0)
	fputs (" ", outfile);
      else
	fputs ("\n", outfile);
      count++;
    }
  fclose (outfile);
  fclose (infile);
}
