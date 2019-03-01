# sploit

All the sploit exercices are designed to be solvable with NX+ASLR
without being dependant on which libc is used. The idea is you should
only interact with stdin / stdout as if it was a remote service,
argv & env is not needed for exploitation.


Of course you can still do whatever you like, have fun!

It's build using:

``` bash
for x in *.c; do gcc $x -o new_$x -no-pie -fno-stack-protector; done;
rename.ul -- .c '' new*.c
```
