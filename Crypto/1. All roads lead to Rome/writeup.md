# All roads lead to Rome

> > Crypto - 100pts
>
>A team of archaeologists found this secret message, can you help to >uncover the content?
>```
>EsDRkmu19{lkli_mkockb_gkc_k_medso}
>```

## Writeup

This is a caesar chipher with a rotation of 10.

To solve:
`echo "EsDRkmu19{lkli_mkockb_gkc_k_medso}" | tr k-za-jK-ZA-J a-zA-Z`
or
`tr k-za-jK-ZA-J a-zA-Z < secret.txt`
Yielding `UiTHack19{baby_caesar_was_a_cutie}`

