#!/usr/bin/env python3
import sys
import random

if len(sys.argv) < 2:
    print("Usage: ", sys.argv[0], "<number of flags>")

# get a list of random words
word_file = "/usr/share/dict/words"
with open(word_file) as file:
    words = [word for word in file.read().splitlines() if "'" not in word]

for _ in range(0, int(sys.argv[1])):
    flag = "UiTHack19{unicorn_"
    number_of_words = random.randint(3, 5)
    for _ in range(0, number_of_words - 1):
        flag += random.choice(words) + "_"
    flag += random.choice(words) + "}"
    print(flag)