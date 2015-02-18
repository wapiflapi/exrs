# exrs
Exercises for learning Reverse Engineering and Exploitation.

All binaries for these challenges are ELF 64-bit LSB executable, x86-64.

## reverse engineering

The goal is to run the chalenges like this `./rX password` and having them
print out `password OK`. It's reverse engineering, not cracking. So don't
patch the binnaries if you want to play by the rules. It gets really borring
if you don't anyway.

## sploit

All the sploit exercices are designed to be solvable with NX+ASLR
without being dependant on which libc is used. The idea is you should
only interact with stdin / stdout as if it was a remote service,
argv & env is not needed for exploitation.

The goal is of course to spawn a shell on each one. All of them are tested.


Of course you can still do whatever you like, have fun!
