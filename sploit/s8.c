#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<err.h>

int		main(int argc, char **argv)
{
  char buffer[32];

  (void) argc, (void) argv;

  printf("Welcome Stranger\n");
  printf("What is your password?\n");

  if (read(0, buffer, 48) <= 0)
    err(EXIT_FAILURE, "read");

  printf("If you're cool you'll get a shell.\n");

  if (strcmp("pretend_you_dont_know_this", buffer) == 0)
    printf("neo\n");

  return 0;
}
