# Echo
> Pwn - 100 pts

> I've written a program to echo your input back at you. Just give it some input, and you get it right back. <br>

> I wrote it in C with the formatted print function and I am very proud <br>

## Writeup 

folder -> Echo <br>
The program outputs the user's inputs, but does not check for format strings. Therefore data can be read by inputting f.ex `%s` which will result in the flag.
FLAG: `UiTHack19{I_heard_you_wanted_a_string}`
