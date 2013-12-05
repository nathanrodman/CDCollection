//
//  a07.cpp
//  a07
//  Sources:
//  Created by Nathan Rodman on 11/27/13.
//  Copyright (c) 2013 Nathan Rodman. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int ARRAY_SIZE = 100;

// Prototypes
int loadData (string pathname);
void showAll (int count);
void showCDsByBand (int count, string name);
void showCDsByTitle (int count, string title);

struct CD
{
    string title;
    string bandName;
};

CD collection[ARRAY_SIZE];


int main()
{
    int count = 0;
    string fileName;
    char choice;
    string searchBand;
    string searchTitle;
    // Ask the user for the file name.
    // Send the file name to loadData, get the size back.
    // ShowAll, send the size to showAll
    // ask for input, q is quit, s is showall, t is search by title
    // b is search for band name.
    
    cout << "Welcome to Nathan's CD Collection" << endl;
    cout << "Please enter a file name to import: ";
    cin >> fileName;
    
    // opens file name and returns number of records
    count = loadData(fileName);
    cout << count << " records loaded successfully" << endl;
    
    cout << "Would you like to (Q)uit, Search (B)and, Search (T)itle, or (S)how All: ";
    cin >> choice;
    
    do {
        
        choice = tolower(choice);
        if (choice == 's'){
            showAll(count);
        }
        
        else if (choice == 'b'){
            cout << "Which band would you like to search for?: ";
            cin.ignore();
            getline(cin, searchBand);
            showCDsByBand(count, searchBand);
            
        }
        
        else if (choice == 't'){
            cout << "Which title would you like to search for?: ";
            cin.ignore();
            getline(cin, searchTitle);
            showCDsByTitle(count, searchTitle);
        }
        
        cout << "\nWould you like to (Q)uit, Search (B)and, Search (T)itle, or (S)how All: ";
        cin >> choice;
        
    }
    while (choice !='q'); // quits the do while loop and subsequently the program
    
    
    return 0;
}

int loadData (string pathname){
    // create an ifstream and open it using pathname.
    ifstream inputFile;
    inputFile.open(pathname);
    int index = 0;
    
    while(!inputFile.eof())
    {
        string dataIn;
        getline(inputFile, collection[index].title);
        getline(inputFile, collection[index].bandName);
        
        index++;
        
    }
    
    inputFile.close();
    
    return index; // returns the number in the collection
}

void showAll (int count)
{
    for (int i = 0; i < count; i++)
    {
        // cout statements for collection[i].title, collection[i].bandname
        cout << collection[i].title << endl;
        cout << collection[i].bandName << endl;
    }
}

void showCDsByBand (int count, string name){
    // need a for loop
    int j = 0;
    for(int i = 0; i < count; i++){
        if (collection[i].bandName.find(name) != string::npos) //npos = -1
        {
        // increment your counting variable
        // output "title (bandname)"

            cout << collection[i].title << ' ' << '(' << collection[i].bandName << ')' << endl;
            j++;
        }
        // done with loop, output counting variable
    }
    cout << "-- " << j << " record(s) found --";
}

void showCDsByTitle (int count, string title){
    int j = 0;
    for (int i = 0; i < count; i++){
        if (collection[i].title.find(title) != string::npos){
            cout << collection[i].title << ' ' << '(' << collection[i].bandName << ')' << endl;
            j++;
        }
    }
    cout << "-- " << j << " record(s) found --";
}
