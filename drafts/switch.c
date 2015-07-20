#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <err.h>

#define DEBUG 0

int main(int argc, char **argv)
{
  int fd;
  void *storage[1024];
  unsigned int stored = 0;

  (void) argc, (void) argv;

  if (argc != 2)
    fd = 0;
  else if ((fd = open(argv[1], O_RDONLY)) < 0)
    err(EXIT_FAILURE, "open");

  while (1)
    {
      void **entries;
      unsigned int num;
      unsigned int space;

      if (read(fd, &num, sizeof num) != sizeof num || num == 0)
	break;
      space = num * sizeof *entries;

      if (DEBUG && num != 1)
      	fprintf(stderr, "%#.8x entries will require %#x memory.\n", num, space);

      if (!(entries = malloc(space)))
	err(EXIT_FAILURE, "malloc");

      /*
      ** Overflow doesn't occur when reading the data.
      ** This is because the original code looks like
      ** this:

      unsigned int i;

      for (i = 0; i < num; ++i)
	if (read(fd, &entries[i], sizeof *entries) < 0)
	  err(EXIT_FAILURE, "read entry");

      ** but it has been optimized to be faster when
      ** trying to write a proof of concept exploit:
      */

      char  *dest = (char *) entries;
      size_t todo = (size_t) num * sizeof *entries;

      if (DEBUG && num != 1)
      	fprintf(stderr, "writing %#zx bytes from %p to %p\n", todo, dest, dest+todo);

      while (todo > 0)
	{
	  ssize_t done;

	  if ((done = read(fd, dest, todo)) <= 0)
	    err(EXIT_FAILURE, "read entry %p + %zx, (%d)", dest, todo, fd);
	  dest += done;
	  todo -= done;
	}


      /*
      ** Back to the original code:
      */

      storage[stored++] = entries;

      if (stored >= sizeof storage / sizeof *storage)
	{

	  fprintf(stderr, "NO MORE SPACE - FREE\n");
	  while (stored)
	    free(storage[--stored]);

	}
    }

  fprintf(stderr, "All done. %d entries left - FREE\n", stored);

  while (stored)
    free(storage[--stored]);

  return 0;
}
