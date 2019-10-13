# Constrained License Checker
> > Reverse Engineering 500 pts
> 
> An intelligence source was able to find a password encrypted file along with an application
> most likely used to confirm the validity of the password.
> 
> Sadly, we were not able to retrieve the source of the application, but we hope you can
> reverse engineer the application for us and crack the encryption.
> 
> Best of luck!
> 
> [flag.zip](./flag.zip)
> [checker](./checker)

## Writeup
Reversing the application binary, we can see that it performs a number of checks that constrains
the possible passwords significantly.
We can plug these constraints into Z3, allowing us to determine the password (as we have done in [solve.py](./src/solve.py))

If we use the password to decrypt `flag.zip`, we get the flag:
`UiTHack19{constraint_solving_is_pretty_cool}`
