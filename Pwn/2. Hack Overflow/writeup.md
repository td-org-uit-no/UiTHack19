# Hack Overflow
> Pwn - 150 pts

This is the registration form for the new hip site for hacker: Hack Overflow (get it?). <br>
There isn't a whole lot to do yet, but we will fix that. <br>

## Writeup 

folder -> Hack Overflow <br>
The program attempts to register the user with the given name and age. The name field can be overflowed, leaking into age and privileges. To solve it the age and is_admin variables need to be overwritten, but the age has to stay below 90. <br>
F.ex the name `aaaaaaaaaaaaaaaaEE` will work, overwriting both age and is_admin with 69. <br>
This gives access to the shell, where the flag can be read with `cat flag.txt` <br>
FLAG: `UiTHack19{always_check_your_buffers}`