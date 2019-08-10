# Use The Force, young padawan
> > Crypto - 300 pts
>
>Something wrong with this picture, there is. But what I know not. Hmmmmmm.
>Some wisdom that may help you on your way, here is.  
>
>```
>5AC152B6F8BKDB8BB12959548D542CB237C4A730K064BF88BBB8DD6E204912BAKAD
>```
>
>Herh herh herh. May you find the answers you seek, young padawan, and may the Force be with >you..


## Writeup

The hint given alongside the picture is an Hash SHA-256 encoded string, that when the K's in the string is removed (because we all know that hash encoding only goes from numbers 0-9 and letters A-F, :information_desk_person: ), the hash can be easily decoded on a hash decoder website and yields the password ``supersecretpassword``.

The picture given shows a smiling dog, with nothing suspicious about it. Buuuut, as the good hackers we are, we all know that much can be hidden in pictures. With steganography encryption, a second hidden picture lies beneath. To help decrypt the picture, the hashed password can be used on a website. On the hidden picture, the flag is yield:

``UiTHack19{The_Force_is_strong_with_this_one}``