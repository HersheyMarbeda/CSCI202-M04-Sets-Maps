    // /***************************************************************************
    //  *                                                                         *
    //  *   Progammer: Hershey Marbeda                                            *
    //  *   Instructor: Dr. Carver                                                *
    //  *   Course: CSCI 202-Data Structures and Algorithms                       *
    //  *   Due Date: 11.18.2024                                                  *
    //  *   College: Ivy Tech Community College                                   *
    //  *                                                                         *
    //  *   ------------------------- About the Program ------------------------- *
    //  *   File Name: M04-1-RandomWords-HBM.cpp                                  *
    //  *   Import Filename: Random-Words.txt                                     *
    //  *   Program Assignment Name: US States and Capitals                       *
    //  *   Last Date Updated: 11.13.2024                                         *
    //  *                                                                         *
    //  *   Program Assignment Description:                                       *
    //  *   This program reads the file US-States-With-Capitals.txt               *
    //  *   and stores the data in a vector of structs.                           *
    //  *   The program then ask the user to enter a state name and               *
    //  *   the program will display the full name and capital of the state.      *
    //  *                                                                         *
    //  ****************************************************************************/

#include <iostream>
#include <fstream>    // To open files
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

void toReadFile(set<string> &randomWords, map<string, int> &wordCount)
{
    ifstream randomWordsFile("Random-Words.txt");
    string random_Words;
    int word_Count_in_File = 0;
    
    if (!randomWordsFile)
    {
        cerr << "Error opening file." << endl;
        exit(1);
    }
    
    while (randomWordsFile >> random_Words)
    {
        randomWords.insert(random_Words);  // Insert word into the set
        wordCount[random_Words]++;         // Increment the word count
        word_Count_in_File++;
    }
    
   // cout << "Total words read from file: " << word_Count_in_File << endl;
}

bool compareByFirstLetter(const string &a, const string &b)
{
    return a[0] < b[0];  // Compare based on the first character
}

int main()
{
    // Table Headings
    cout << string(100, '*') << endl
         << "\t\t\t\t\t\tRandom Words using Sets and Maps\n"
         << "\t\t\t\t\t\tProgramming Assignment: M04.1: Sets and Maps\n"
         << string(100, '*') << endl;
    
            
    // Declaration of Variables and Sorts
    set<string> randomWords;  // Set to hold unique words
    map<string, int> wordCount;  // Map to hold word count
    toReadFile(randomWords, wordCount);
    
    // Copy the set into a vector for sorting
    vector<string> sortedWords(randomWords.begin(), randomWords.end());
    
    // Sort the vector based on the first letter of each word
    sort(sortedWords.begin(), sortedWords.end(), compareByFirstLetter);
    
    
    // Display the random words
    cout << "\nRandom Words in the txt file" << endl;
    cout << string(50, '-') << endl;
    
    
    for (int i = 1; const auto &randomWord : randomWords)
    {
        cout << i << ". " << randomWord << endl;  // Print each word in the set
        i++;
    }
    
    
    // Display the duplicate words (those with count > 1)
    cout << string(50, '-') << endl;
    cout << "\nDuplicate Words: " << endl;
    cout << string(50, '-') << endl;
    
    for ( int i = 1; const auto &entry : wordCount)
    {
        if (entry.second > 1)  // If a word appears more than once
        {
            cout << i << ". " << entry.first << " appears " << entry.second << " times." << endl;
        }
        
        i++;
    }
    
    cout << endl << endl;
    return 0;
}
