# The unicorn jar
> > Web - 250pts
>
> What is the unicorns favorite food? I'll give you ha hint, it comes from a jar.
>
> The website is located at: `http://129.242.219.103:5656`
>
> Files: 
> [source code](./scr/)

## Writeup

The text provided should give a good hint to start inspecting the tokens and cookies on the website. When inspecting, one han see that as soon as one have provided a post request, one get a cookie. If you look closely, the value is `false`. If altered to `true`, one can press the flag button and access the falg site, yelding: 
`UiTHack19{cant_keep_my_hands_out_the_cookie_jar}` 