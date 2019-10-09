# The unicorn database
> > Web - 200pts
>
>Now the password is more secure than ever, in a sparkly and magical database. I bet you can't >get it now!
>
>The website is located at: `put something here`
>
>Files: 
>[source code](./scr/)

## Writeup

By mentioning the password beeing stored in a database, and the name of the challenge, one of the first things one would think of, is that the server doesn't handle their storing of password and usernames properly. When reading up on this, a commonly used SQL injection for gathering the first username and password stored in a database, is `' OR 1=1; --` . If inserting this in the username field, the website will register you as loged in, and yield the flag:
`UiTHack19{and_remember_kids_we_are_all_unicorns}`