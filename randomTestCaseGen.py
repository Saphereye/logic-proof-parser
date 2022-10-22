import random

infix = ""
for i in range(1_000_000):
    infix += ((i+1)%2)*random.choices(list("abcdefghijklmnopqrstuvwxyz"))[0] + (i%2)*random.choice(list("~+*>"))[0]

with open("InfixText.txt","w") as file:
    file.write(infix)
