# Baseball, softball, all ball
> > Crypto - 200 pts
>
>At the court playing some baseball, my friend and I came over this encrypted text.
>Can you help understand what it says? 
>
>[Secret.txt](./secret.txt)

## Writeup

This is four base64 encrypted lines, where each line need to be decrypted. 
To decode the lines, a base64 decoder tool found online can be used, 

or

` echo VWlUSGFjazE5e2lzX2Jhc2U2NF9hX2JhbGw/fQo== | base64 --decode`

in terminal. 

The third line yields the following flag:
`UiTHack19{is_base64_a_ball?}`
