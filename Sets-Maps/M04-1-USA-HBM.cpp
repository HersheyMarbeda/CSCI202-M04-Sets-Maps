    // /***************************************************************************
    //  *                                                                         *
    //  *   Progammer: Hershey Marbeda                                            *
    //  *   Instructor: Dr. Carver                                                *
    //  *   Course: CSCI 202-Data Structures and Algorithms                       *
    //  *   Due Date: 11.18.2024                                                  *
    //  *   College: Ivy Tech Community College                                   *
    //  *                                                                         *
    //  *   ------------------------- About the Program ------------------------- *
    //  *   File Name: M04-1-USA-HBM.cpp                                           *
    //  *   Import Filename: US-States-With-Capitals.txt                          *
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
#include <sstream>    // For istringstream
#include <vector>     // For storing states
#include <map>        // For sortation
#include <algorithm>  // For transform() function alt: <cctype>

using namespace std;

struct State
{
    string state_Abbreviation;
    string state_FullName;
    string state_Capital;
};

// Hardcoded map for state abbreviation to full name
map<string, string> stateAbbreviationToFullName =
{
    {"AL", "Alabama"}, {"AK", "Alaska"}, {"AZ", "Arizona"}, {"AR", "Arkansas"},
    {"CA", "California"}, {"CO", "Colorado"}, {"CT", "Connecticut"}, {"DE", "Delaware"},
    {"FL", "Florida"}, {"GA", "Georgia"}, {"HI", "Hawaii"}, {"ID", "Idaho"},
    {"IL", "Illinois"}, {"IN", "Indiana"}, {"IA", "Iowa"}, {"KS", "Kansas"},
    {"KY", "Kentucky"}, {"LA", "Louisiana"}, {"ME", "Maine"}, {"MD", "Maryland"},
    {"MA", "Massachusetts"}, {"MI", "Michigan"}, {"MN", "Minnesota"}, {"MS", "Mississippi"},
    {"MO", "Missouri"}, {"MT", "Montana"}, {"NE", "Nebraska"}, {"NV", "Nevada"},
    {"NH", "New Hampshire"}, {"NJ", "New Jersey"}, {"NM", "New Mexico"}, {"NY", "New York"},
    {"NC", "North Carolina"}, {"ND", "North Dakota"}, {"OH", "Ohio"}, {"OK", "Oklahoma"},
    {"OR", "Oregon"}, {"PA", "Pennsylvania"}, {"RI", "Rhode Island"}, {"SC", "South Carolina"},
    {"SD", "South Dakota"}, {"TN", "Tennessee"}, {"TX", "Texas"}, {"UT", "Utah"},
    {"VT", "Vermont"}, {"VA", "Virginia"}, {"WA", "Washington"}, {"WV", "West Virginia"},
    {"WI", "Wisconsin"}, {"WY", "Wyoming"}
};

void toReadFile(vector<State> &states)
{
    ifstream state_file("US-States-With-Capitals.txt");
    string line;
    
    if (!state_file)
    {
        cerr << "\nThere's an error in opening the file!\n";
        exit(1);
    }
    
    // To read the file line by line
    while (getline(state_file, line))
    {
        State state;
        string abbreviation;
        istringstream iss(line);
        
        // Read the state abbreviation
        iss >> abbreviation;
        
        // Reads the remaining part of the line as the capital
        getline(iss, state.state_Capital);
        
        // Trim leading space in state_Capital if needed
        if (!state.state_Capital.empty() && state.state_Capital[0] == ' ')
        {
            state.state_Capital.erase(0, 1); // Remove leading space
        }
        
        // Get the full state name from the map using abbreviation
        state.state_FullName = stateAbbreviationToFullName[abbreviation];
        
        // Set the abbreviation
        state.state_Abbreviation = abbreviation;
        states.push_back(state);
    }
    
    state_file.close();
}


// Function to display the states
//void displayStates(const vector<State> &states)
//{
//    cout << "\nState Abbreviation" << setw(20) << "Full State Name" << setw(20) << "Capital" << endl
//         << string(80, '-') << endl;
//    
//    for (const auto& state : states)
//    {
//        cout << setw(25) << left << state.state_Name
//             << setw(25) << left << state.state_FullName
//             << setw(20) << left << state.state_Capital << endl;
//    }
//    
//    cout << string(80, '-') << endl;
//}

int main()
{
    // Table Headings
    cout << string(100, '-') << endl
         << "\t\t\t\t\t\tU.S. States and Capitals using Vectors and Maps\n"
         << "\t\t\t\t\t\tProgramming Assignment: M04.1: Sets and Maps\n"
         << string(100, '-') << endl;
    
    // Variables
    string state_Name;
    
    do
    {
        vector<State> states;
        toReadFile(states);
        
        // Maps to store abbreviation-to-state information
        map<string, State> stateCapitalMap;
        
        // Vector to store abbreviation-to-fullname pairs
        vector<pair<string, string>> stateFullNameMap;
        
        // Populate the map with state abbreviation as the key and State object as the value
        for (const auto &state : states)
        {
            stateCapitalMap[state.state_Abbreviation] = state;
            
            // Store the pair of abbreviation and full name in the vector
            stateFullNameMap.push_back(make_pair(state.state_Abbreviation, state.state_FullName));
        }
        
        cout << "\nEnter a State Name (Abbreviation ONLY; type 'QUIT' to exit): ";
        cin >> state_Name;
        
        // Convert input to uppercase to match map keys
        transform(state_Name.begin(), state_Name.end(), state_Name.begin(), ::toupper);
        
        // Exit condition if the user enters 'QUIT'
        if (state_Name == "QUIT")
        {
            cout << "\nThank you for using the program!\n";
            break;
        }
        
        // Input validation loop
        while (stateCapitalMap.find(state_Name) == stateCapitalMap.end())
        {
            cout << "\nInvalid State Name! Please enter a valid State Name: ";
            cin >> state_Name;
            transform(state_Name.begin(), state_Name.end(), state_Name.begin(), ::toupper);
            
            // Exit condition if the user enters 'QUIT'
            if (state_Name == "QUIT")
            {
                cout << "\nThank you for using the program!\n";
                break;
            }
        }
        
            // Display the full state name and capital based on user input
        if (stateCapitalMap.find(state_Name) != stateCapitalMap.end())
        {
            const State &selectedState = stateCapitalMap[state_Name];
            cout << "\nState Abbreviation: " << state_Name << endl
                 << "Full State Name: " << selectedState.state_FullName
                 << "\nCapital: " << selectedState.state_Capital << endl;
        }
        
    } while (state_Name != "QUIT");
    
    cout << endl << endl;
    return 0;
}
