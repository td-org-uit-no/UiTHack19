import random

with open('random_text.txt','r') as source:
    data = [ (random.random(), line) for line in source ]
data.sort()
with open('real_random_text.txt','w') as target:
    for _, line in data:
        target.write( line )

