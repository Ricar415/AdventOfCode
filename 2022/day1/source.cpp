#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    cout << "Starting program\n";
    fstream inputFile;
    inputFile.open("/home/ricar/Downloads/aoc_2022_1_input", ios::in);
    if (inputFile.is_open()){
        
        char x;
        string ln;
        bool endLineCheck = false;

        int currentCaloriesCount = 0;
        int currentIndex = 0;
        int maxCaloriesCount = 0;
        int maxCaloriesIndex = 0;

        while (inputFile.get(x)){
            if(x == '\n'){
                if(!endLineCheck){
                    int number = stoi(ln);
                    ln = "";
                    currentCaloriesCount += number;
                } else { 
                    if(currentCaloriesCount > maxCaloriesCount){
                        maxCaloriesCount = currentCaloriesCount;
                        maxCaloriesIndex = currentIndex;
                    }
                    currentIndex ++;
                    currentCaloriesCount = 0;
                }
                endLineCheck = true;
            } else {
                endLineCheck = false;
                ln.push_back(x);
            }
        }
        cout << "Max calories counted at index:\t" << maxCaloriesIndex << " with value:\t" << maxCaloriesCount << "\n";
        inputFile.close();
    }
};
