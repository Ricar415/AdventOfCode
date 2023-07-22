
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    cout << "Starting program\n";
    fstream inputFile;
    inputFile.open("/home/ricar/Downloads/aoc_2022_6_input", ios::in);
    if (inputFile.is_open()){
        string ln;
        int containedCount = 0;
        char x;
        
        char c1 = (char)0;
        char c2 = (char)0;
        char c3 = (char)0;
        char c4 = (char)0;

        int index = 0;
        while (inputFile.get(x)){
            index++;
            c1 = c2;
            c2 = c3;
            c3 = c4;
            c4 = x;
            if (c1 != (char)0 && c1 != c2 && c1 != c3 && c1 != c4 && c2 != c3 && c2 != c4 && c3 != c4){
                cout << index;
                break;
            }
        }
        inputFile.close();
    }
}
