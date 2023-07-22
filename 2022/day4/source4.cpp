#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    cout << "Starting program\n";
    fstream inputFile;
    inputFile.open("/home/ricar/Downloads/aoc_2022_4_input", ios::in);
    if (inputFile.is_open()){
        string ln;
        int containedCount = 0;
    
        while (getline(inputFile,ln)){
            int first = stoi(ln.substr(0,ln.find('-')));
            int second = stoi(ln.substr(ln.find('-')+1, ln.find(',')));
            string sub = ln.substr(ln.find(','), ln.length()-ln.find('-'));
            int third = stoi(sub.substr(sub.find(',')+1, sub.find('-')));
            int fourth = stoi(sub.substr(sub.find('-')+1, sub.length() - sub.find('-')));
            if((first <= third && second >= fourth) || (third <= first && fourth >= second)){
                containedCount ++;
            }
        }
        cout << "Total contained in themselves: " << containedCount;
        inputFile.close();
    }
};
