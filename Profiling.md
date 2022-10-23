# Profiling
## Goal
The goal is to
- Find spots in our program which are slow, and thus helping us identify the real weak points
- Identify memory leaks, in order to stop building up of junk memory
## Tools
For runtime of each function we used `chrono` library of C++ on the given system. This library provide high accuracy data, which was useful to record information with even small inputs.

|OS Name|System Type|Processor|Usable Ram|
|:----|:----|:----|:----|
|Windows 10|x64-based|11th Gen Intel(R) Core(TM) i3-1115G4 @ 3.00GHz, 2995 Mhz, 2 Core(s), 4 Logical Processor(s)|7.65 GB|

For memory analysis of the program we used inbuilt memory analysis of Visual Studio on the given system. We chose this due to it's high accuracy and descriptive output, which helped us understand the code better.

|OS Name|System Type|Processor|Usable Ram|
|:----|:----|:----|:----|
|Windows 11|x64-based|Intel(R) Core(TM) i5-10300H CPU @ 2.50 GHz, 2496 Mhz, 4 Core(S), 8 Logical Processor(s)|3.10 GB|

## Input
A randomised input was generated each time using the given python script

```python
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
```

## Execution
The program was optimised with flags `-Os -O2`.

The `-Os` flag optimizes the size of the code. Whereas `-O2` optimizes for speed. Size optimization happens at the cost of speed. For example replacing with body of code instead of a call function.

For time analysis, each task was run `1000` times and the average was considered.
The following data was reveived
  
|Tree Height|No. of Atoms|Task 1 (ms)|Task 2 (ms)|Task 3 (ms)|Task 4 (ms)|Task 5 (ms)|  
|:----|:----|:----|:----|:----|:----|:----|  
|5|10|0.0047605|0.0079753|0.005358|0.008284|0.0054994|  
|5|12|0.0028622|0.0055984|0.009877|0.0060635|0.0086048|  
|10|119|0.0347532|0.0581992|0.0647751|0.0625164|0.0591974|  
|10|191|0.0478533|0.0898297|0.0969904|0.090525|0.0993498|  
|15|2425|0.189015|0.549159|0.615554|0.625281|0.609831|  
|15|3425|0.488783|0.9894795|1.60096|1.51223|1.44321|  
|17|4554|0.545341|1.4298|1.62267|1.4522|1.54193|  
|17|8894|0.500103|1.51216|1.62874|1.55287|1.555075|  
|18|11137|0.528771|1.99178|1.67444|1.53555|1.6110075|  
|20|46394|0.686642|1.47442|1.70191|1.61959|1.66694|  
|20|65619|0.513933|1.45734|1.73145|1.55454|1.50251|  

## Data in Graphical Manner
### Number of atoms Vs time taken graph
![Number of atoms Vs time taken](task_vs_time.jpeg)
### Task Dependency Graph
[![](https://mermaid.ink/img/pako:eNp1kV1LwzAUhv9KONdtaLY0WXMh7AsUFETFC1svwnq2FtdmZClslv1303YVBc3VOed93jdfLWxMjqBgZ_WhIPdPWU38mqeMkrt6W56IM-TRoq_eB2mRTuh10mvaHpG8WESvXwkShjdkPrbLdEp_YJ2pT_7mlz2_GNtVyim5xXJXOGK2f22w-m1YpzH1QOMK8qr3Df7jWo8uCKBCW-ky9_duOzEDV2CFGShf5tp-ZJDVF881h1w7XOelMxaUsw0GoBtnns_1ZuwHZlVq_4QVqK3eH_30oGtQLZxAhbMZFUkUSy54nCSCBXAGxSMaC84ZT-Qsmsgp55cAPo3xCYwyKeVUCBnHzBs7h49768VrPPZHehj-rv_CyxdUX4ig?type=png)](https://mermaid.live/edit#pako:eNp1kV1LwzAUhv9KONdtaLY0WXMh7AsUFETFC1svwnq2FtdmZClslv1303YVBc3VOed93jdfLWxMjqBgZ_WhIPdPWU38mqeMkrt6W56IM-TRoq_eB2mRTuh10mvaHpG8WESvXwkShjdkPrbLdEp_YJ2pT_7mlz2_GNtVyim5xXJXOGK2f22w-m1YpzH1QOMK8qr3Df7jWo8uCKBCW-ky9_duOzEDV2CFGShf5tp-ZJDVF881h1w7XOelMxaUsw0GoBtnns_1ZuwHZlVq_4QVqK3eH_30oGtQLZxAhbMZFUkUSy54nCSCBXAGxSMaC84ZT-Qsmsgp55cAPo3xCYwyKeVUCBnHzBs7h49768VrPPZHehj-rv_CyxdUX4ig)

This graph shows the dependency of each function. For example Prefix to parse tree requires the input infix to be converted top prefix first, hence it requires the function of the first task.
### Memory Usage (1343 atoms, Height 12)
![Memory Usage Table](memory_profile_1343.jpeg)
Each blue down arrow (▼) and the ID are the snapshots of the memory before the respective task.
### Call comparison between 1343 and 360 atoms
![Call comparison between 1343 and 360 atoms](call_comparison.jpeg)
This is a comparison between memory taken by a program with input of 1343 and 360 atoms repectively.
## Analysis
### Time Analysis
Until `4554` atoms, the time taken rises sharply. This is followed by decrease in the rate of change and it levels down to a linear relation with constant increase in time taken as number of atoms increase.

We can explain this linear increase with time complexity. As the algorithms traverse through each element/node, one can approximate them to be `O(n)`.

Furthermore, from the task dependency graph we can see that task 1 must have the least time, followed by task 2, followed by 3, 4 and 5.

One can observe sharp variations in data, which we consider as experimental error.
### Memory Analysis
In the above image "Memory Usage", one can see a sudden increase heap memory between ID 3 and 4 which corresponds to allocation of heap memory for the pointers of the binary parse tree.

As the program `main.exe` evaluates each component from scratch (as show in 'Task Dependency Graph'), it leads to multiple allocation of heap memory, which hasn't been freed.

Thus memory analysis helped us in uncovering memory leaks in our program.
## Conclusion
This exercise helped us see how our functions are behaving under stress. This helped us find the bottlenecks in our code and find out that naïve methods lead to memory leaks.


