# Sphinx
>> Reverse Engineering - 150 pts
>
> In Greek mythology the sphinx has the head of a human, the body of a lion and the wings of an eagle and is known to be treacherous and merciless. <br>
> This one is less scary, but just as cruel. <br>



## Writeup 

folder -> Sphinx <br>
The program prompts the user for an answer to a riddle, but will never give up the flag. Instead the flag can be found by reading the binary with xxd or strings, and grep-ing for "UiT" <br>
FLAG: `UiTHack19{the_sphinx_is_a_meanie}`