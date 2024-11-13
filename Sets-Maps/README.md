# Assignment Description
1. Write a program that reads words from a text file and displays all unique words in ascending order.
2. Write a program to store pairs of each state and its capital in a map. Your program should prompt the user to enter a state and display the capital of that state.

## My Method
1. I used a `<set>` to store random words from the text file. Following the instructions, I organized the words by their first letter to display them in ascending order. Additionally, I identified which words were duplicated and counted how many times they appeared. In total, I created a text file with 50 random words.
2. I used a `<map>` to store state abbreviations and their corresponding capitals from the text file. I also hardcoded the state abbreviations along with the full names of the states. I believe that using a `<map>` for this problem is effective since it is a key-value structure. In this case, I treated the abbreviation (e.g., "CA") as the key, paired with the state's capital (e.g., "Sacramento").  However, I encountered a challenge when trying to read the file with the full names of the states. Some states have two names, which made it difficult to sort them in the `<map>`. To simplify the process, I decided to hardcode the abbreviations along with their full state names (e.g., `{"CA", "California"}`).
