#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<err.h>

int		main(int argc, char **argv)
{
  char *cmds[3];
  int i;

  (void) argc, (void) argv;

  i = 0;
  while (i < sizeof cmds / sizeof *cmds)
    {
      char *msg;
      int len;

      if (!(msg = malloc(1024)))
	err(EXIT_FAILURE, "malloc");

      strcpy(msg, "echo you: ");
      if ((len = read(0, msg + 10, 1024 - 10)) <= 0)
	err(EXIT_FAILURE, "read");

      msg[10+len-1] = 0;

      if (strspn(msg, ":0123456789abcdefghijklmnopqrstuvwxyz ") != 10+len-1)
	{
	  printf("I'm playing this safe. Only [:0-9a-z ].\n");
	  continue;
	}

      system(msg);
      cmds[i++] = msg;
      free(msg);
    }

  srandom(time(NULL));
  i = random() % (sizeof cmds / sizeof *cmds);
  printf("Lets do the %dth one again! That one was funny.\n", i);
  system(cmds[i]);

  return 0;
}
