# Assignment Description
1. Write a program that reads words from a text file and displays all the nonduplicate words in ascending order.
2. Write a program to store pairs of each state and its capital in a map. Your program should prompt the user to enter a state and should display the capital for the state.

## My Method
1. I used <map> to store the capitals in the txt file. Then, I hardcoded the state abbreviations and state full names. I think that using <map> in this problem is a great way since the <map> is a key-pair structure. In the problem, I assumed that the abbreviation (eg. CA) is a key and is pair to state's capital (eg. Sacramento). The only thing I had a problem is when I tried to read the file with full state name. There are some states that has two names and it wouldn't really going to help me to sort three string in <map> so, I hardcoded it. (eg. {"CA", "California"}. 
