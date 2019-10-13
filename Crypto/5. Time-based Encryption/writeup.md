# Time-based Encryption
> > Crypto - 500 pts
> 
> We have received intelligence of a time-based encryption system
> and gained access to the source code of the system.
> 
> In addition, we managed to extract parts of the system output.
> Can you help us decrypt the contents of the message?
> 
> ```
> First 8 bytes of key stream: {670289626, 1178390405}
> Encrypted data: "A54948D10E7FA6580699F7FCAEEC724DC02ACB54D55642FD12CE7B7AB18ED7B5875509C91E67A658438ABAB09FF16208D72CDA45C91F48FF41DD7E7BBACBCCAE865E47C05733AC4D439DBFFC80F96808D336CC45DD5E40FF41DE786CAC8E84B2965245C9127DA44F0D8EECFC83EC7258C162810FCC485BB407D37F71F185CBEE88544B8A1D66AF461782BBB9C4F96206DA2CC34C845945F40FD17E7BBAD695F4D5081F904C2BF70A0B9FA2AC98A22907C52FD90EDD5642F44FD47E30B584C6EE844E45C90F7AAE4F4C8AB2F283EC6B448D3EC74ED55443FE0487202AE8D892F7D60C1A8B5B5BA6584383B7AECBFC7308D72C8E46D75E4BFD41DC7E6DFF89D6B8874F13852E7A97622288BDEDD2E36247ED36C154E44B44E80ECD4E66B09ED69E87555DD71463BA75029CB7A596B6"
> ```
> 
> [encrypter.c](./encrypter.c)

## Writeup

By reading the source code, we can see that the encryption scheme only uses 28 bits of the entropy from the time call, meaning it can be brute-forced.

Brute-forcing the key yields the correct sequence of key bytes, resulting in the key stream that can be XOR'd with the cipher text to yield the plaintext containing the flag:
```
UiTHAck19{do_not_throw_your_entropy_away}.
```
