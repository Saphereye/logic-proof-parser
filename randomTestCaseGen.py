import os
import random
from secrets import choice

text = ""
for i in range(10000):
    if (i % 2 == 0):
        text += random.choices(list("qwertyuiopasdfghjklzxcvbnm"))[0]
    else:
        text += random.choice(list("~+*>"))[0]

print(text, end='')