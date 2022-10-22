import os
import random
from secrets import choice
import threading

infix = ""
for i in range(1_000):
    infix += ((i+1)%2)*random.choices(list("abcd"))[0] + (i%2)*random.choice(list("~+*>"))[0]
print(infix, end='')
