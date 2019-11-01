'''import random
with open('random_text.txt','r') as source:
    data = [ (random.random(), line) for line in source ]
data.sort()
with open('real_random_text.txt','w') as target:
    for _, line in data:
        target.write( line )'''

data = []
with open('aktive_medlemmer.txt', 'r') as file:
    for line in file:
        string = line.split(" ")
        name = string[1:]
        data.append(name)

with open('members.txt', 'w') as target:
    for i in data:
        target.write(str(i) + "\n")