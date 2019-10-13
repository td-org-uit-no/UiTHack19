# Use The Force, young padawan
> > Misc - 300 pts
>
> Something wrong with this picture, there is. A cover-up it must be. But of what I know not. Hmmmmmm.
> Some wisdom that may help you on your way, you SHAll have.
>
>```
>5AC152B6F8BKDB8BB12959548D542CB237C4A730K064BF88BBB8DD6E204912BAKAD
>```
>
>Herh herh herh. May you find the answers you seek, young padawan, and may the Force be with >you..


## Writeup

The hint given alongside the picture is SHA-256 hash digest, that when the K's in the string is removed (because we all know that hex encoded hash digests only uses numbers 0-9 and letters A-F, :information_desk_person: ), the hash can be easily decoded using an online hash crack website and yields the password ``supersecretpassword``.

The picture given shows a smiling dog, with nothing suspicious about it. Buuuut, as the good hackers we are, we all know that much can be hidden in pictures. With image steganography, a second hidden picture lies beneath. To help decrypt the picture, the hashed password can be used on a website. On the hidden picture, the flag is yield:

``UiTHack19{The_Force_is_strong_with_this_one}``
