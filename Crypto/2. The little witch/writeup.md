# The little witch
> >Crypto - 150 pts
>
>The little witch need to clean her room, and she wants the magic spell to do so.
>The magic spell is hexed in the spell book. Please help the little witch unhex the spell.
>```
>5569544861636b31397b4865785f69745f616c6c5f617761795f6461726c696e7d
>```

## Writeup
This is a hexadecimal encoded string. 

To solve in terminal:

`echo 5569544861636b31397b4865785f69745f616c6c5f617761795f6461726c696e7d | xxd -r -p`

Yielding `UiTHack19{Hex_it_all_away_darlin}`
