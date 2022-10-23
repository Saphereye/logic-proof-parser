# Profiling
## Goal
The of this exercise is to optimise the code but also keeping in mind the size.
A popular method of compiling usually is to replace a function call with body of function.
But this can lead to large files if the function has been called numerous times.

Using above mentioned techniques, `g++` is able to compile our `C++` code.
## Tools
We have used `gprof` as our profiler.
`gprof` is a profiling program which collects and arranges statistics of the program.
## Input
A randomised input(`1000` character long) was generated, each time using a small python script
```python
import os
import random
from secrets import choice

text = ""
for i in range(1_000_000):
    if (i % 2 == 0):
        text += random.choices(list("abcd"))[0]
    else:
        text += random.choice(list("~+*>"))[0]

print(text, end='')
```
which was later written into a text file using `python3 <name-of-above-file> > <output text-file>` in bash.
## Execution
The program was executed with the `-Os -O2`  as the final execution.

The `-Os` flag optimizes the size of the code. It disables some aggresive optimizations done by `-O2`  to save memory. For example replacing with body of code instead of a call function.

The program was run completely i.e. all the options in the menu were executed once and all truth values were given `1`)

## Profiler Output
### Call Table
| calls | Ts/call | Ts/call | name                                                                                       |
|-------|---------|---------|--------------------------------------------------------------------------------------------|
| 5     | 0.00    | 0.00    | Logic::printParseTree(Logic::Operator*, int, int*)                                         |
| 4     | 0.00    | 0.00    | Logic::getParseTreeHeight(Logic::Operator*)                                                |
| 4     | 0.00    | 0.00    | Logic::calcprefixToParseTree(std::__cxx11::basic_string, std::allocator >, unsigned long*) |
| 1     | 0.00    | 0.00    | _GLOBAL__sub_I_isDebugMode                                                                 |

### Call Graph
[![](https://mermaid.ink/img/pako:eNptkM0KwjAQhF-l7FlfIAfBfwUF0eLFeFiStQ22SUlTUMR3N7qW4k9O2d1vZmBuoJwmEJB5rPJktZU2iW94WLnMKCG0qasCrxv0NaWe6Jj0-4Nk1J4rb2zojiweMfN2eg3jVpBRhy_IZHl4iyadJZ3MJXVfkdP2rrBQvwybTBnlYfYvc48F-80Ymn_YtlTqljYGMDmHHpTkSzQ69nR76iSEnEqSIOJXoz9LkPYeOWyC212tAhF8Qz1oKo2BJgZjvSWIExZ13JI2wfk1F__q__4AXgR_-Q?type=png)](https://mermaid.live/edit#pako:eNptkM0KwjAQhF-l7FlfIAfBfwUF0eLFeFiStQ22SUlTUMR3N7qW4k9O2d1vZmBuoJwmEJB5rPJktZU2iW94WLnMKCG0qasCrxv0NaWe6Jj0-4Nk1J4rb2zojiweMfN2eg3jVpBRhy_IZHl4iyadJZ3MJXVfkdP2rrBQvwybTBnlYfYvc48F-80Ymn_YtlTqljYGMDmHHpTkSzQ69nR76iSEnEqSIOJXoz9LkPYeOWyC212tAhF8Qz1oKo2BJgZjvSWIExZ13JI2wfk1F__q__4AXgR_-Q)
## Analysis
All the functions after the optimisation are user made function. This points us to the fact that we can improve the efficiency of the program by improving the functions given in the table.
