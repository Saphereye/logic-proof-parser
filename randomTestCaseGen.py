import random
from tokenize import String

"""
BNF for our expression
E := I | (E + E) | (E * E) | (E > E) | (~ E)
"""
heightOfParseTree: int = 15

def randInfix(count: int) -> String:
    if count <= 1:
        return random.choice(list("abcdefghijklmnopqrstuvwxyz"))[0]
    else:
        case = random.randint(1, 4)
        if case == 1:
                return f"({randInfix(count-1)}*{randInfix(count-1)})"
        elif case == 2:
                return f"({randInfix(count-1)}+{randInfix(count-1)})"
        elif case == 3:
                return f"({randInfix(count-1)}>{randInfix(count-1)})"
        elif case == 4:
                return f"(~{randInfix(count-1)})"

infix = randInfix(heightOfParseTree)

with open("InfixText.txt","w") as file:
    file.write(infix)
