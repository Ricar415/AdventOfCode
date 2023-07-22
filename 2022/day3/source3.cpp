#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char find_copy(string first, string second){
    for (int i = 0; i < first.length(); i++){
        for(int j = 0; j < second.length(); j++){
            if(first[i] == second[j]){return first[i];}
        }
    }
    return '!';
};

int get_priority(char x){
    int result = int(x);
    if(result < 97){
        result -= 38;
    }
    else{
        result -= 96;
    }
    return result;

};

int main(){
    cout << "Starting program\n";
    fstream inputFile;
    inputFile.open("/home/ricar/Downloads/aoc_2022_3_input", ios::in);
    if (inputFile.is_open()){
        char x;
        string ln;
        int priority = 0;  

        while (getline(inputFile, ln)){
            string first = ln.substr(0,ln.length()/2);
            string second  =  ln.substr(ln.length()/2,ln.length()/2);
            priority += get_priority(find_copy(first, second));
        }
        cout << "Total priority: " << priority;
        inputFile.close();
    }
};
