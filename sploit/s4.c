#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<err.h>

char	name[256];

int	main(int argc, char **argv)
{
  char	buffer[32];
  ssize_t nbb;

  (void) argc, (void) argv;

  printf("What is your name?\n");
  if ((nbb = read(0, name, sizeof name - 1)) <= 0)
    err(EXIT_FAILURE, "read");
  name[nbb] = 0;

  printf("Welcome %s\n", name);
  printf("What is your password?\n");

  if (read(0, buffer, 64) <= 0)
    err(EXIT_FAILURE, "read");

  printf("If you're cool you'll get a shell.\n");

  if (strcmp("pretend_you_dont_know_this", buffer) == 0)
    system("whoami # not sh :)");

  return 0;
}
