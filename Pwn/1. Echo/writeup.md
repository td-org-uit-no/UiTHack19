# Echo
> Pwn - 100 pts

> I've written a program to echo your input back at you. Just give it some input, and you get it right back. <br>

> I wrote it in C with the formatted print function and I am very proud <br>

## Writeup 

folder -> Sphinx <br>
The program prompts the user for an answer to a riddle, but will never give up the flag. Instead the flag can be found by reading the binary with xxd or strings, and grep-ing for "UiT" <br>
FLAG: `UiTHack19{the_sphinx_is_a_meanie}`