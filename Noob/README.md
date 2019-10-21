## Noob

**server:** `sparkly-unicorn.td.org.uit.no`
marielme HackerUnite
#### Noob1
Username <br>
noob1 -> rookie <br> 
password `hackers_unite` <br> 
Flag in rookie directory <br> 
Flag: `UiTHack19{rookie_no_more}`

#### Noob2
Username <br> 
noob2 -> newbie <br> 
password `noob2` <br> 
Flag in hidden text file <br> 
Flag: `UiTHack19{no_file_shall_hide_from_me}`

#### Noob3
Username <br> 
noob3 -> cubbie <br> 
password `noob3` <br> 
Use `find ./ -name flag.txt` to find file in a multiple directories  <br> 
Flag: `UiTHack19{pokemon_gonna_catch_them_aaaaaaall}` 

#### Noob4
Username <br> 
noob4 -> greenie <br> 
password `noob4` <br> 
Flag in large file. Need to locate the file first, yeeeah <br> 
Can grep flag, knowing it starts with UiT, or sort the file, go to U and read <br> 
scp user@host :path user@host :path ?
marielme@sparkly-unicorn:/home/greenie/tmp/.hidden/nothing_here/mabye_in_here
FLAG: `UiTHack19{I_hope_you_learned_how_to_search_inside_a_file}`

### Noob5
Username <br> 
noob5 -> fledgling <br> 
password `noob5` <br> 
Oh no, I put all my passwords in one file! The only thing I remember is that the right one ends in with "unicorn" <br>
Can grep for unicorn, or even better for unicorn}$ <br>
FLAG: `UiTHack19{rattiest_showered_leverages_clacking_vacate_libeled_unicorn}`

#### Noob6
Username <br> 
noob6 -> prospect <br> 
password `noob6` <br> 
Flag in file compressed 5 times with different algorithms. Need to use the file command to determine type and then decompress. <br>
A useful trick is to pipe the output of each decompression into the file command with e.g `tar -xOf flag | bzcat | file -`. <br>
This lets you iterate over decompressions and each time get the file type <br>
One-line solution: tar -xOf flag | bzcat | tar -xO | bzcat | zcat | tar -xO <br>
FLAG: `UiTHack19{so_much_compression_I_feel_claustrophobic}`
