#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// The idea is to make a vector of vectors of strings. Each element of this vector represents a folder
// if the string inside the vector is a number it is a file inside the folder
// if the string starts with f it represents a subfolder, with the number after the f representing the index that folder is in in the fileSystem.
// The first string of the

class folder{
 public:
    vector<string> files;
    int rootFolder = -1;
    string folderName;
    bool folderChecked = false;
    int size = 0;
};

vector<folder> fileSystem;
int currentFile = 0; // The file index we are currently on.
int currentMode = 0; // The mode we are currently on. 0 for command. 1 for reading command output.

int process_command(string ln);
void process_output(string ln);
int find_folder(string iFolderName);
void create_folder(string name);
void process_filetree();

int main(){
    cout << "Starting program\n";
    fstream inputFile;
    inputFile.open("/media/ricar/E/AdventOfCode/inputFiles/aoc_2022_7_input", ios::in);
    if (inputFile.is_open()){
        string ln;
        int containedCount = 0;
        char x;
        
        folder aux;
        aux.folderName = "/";
        fileSystem.push_back(aux);

        while (getline(inputFile, ln)){
            if(currentMode == 0 || ln.substr(0,1) == "$"){ currentMode = process_command(ln); }
            else { process_output(ln); }
        }
        inputFile.close();
        process_filetree();
    }
}

int process_command(string ln){
    if(ln.substr(0,4) == "$ cd"){
        if(ln.substr(5,1) == "/"){ currentFile = 0; return 0;}
        if(ln.substr(5,2) == ".." && currentFile != 0){ currentFile = fileSystem[currentFile].rootFolder; return 0;}
        int folderN = find_folder(ln.substr(5,ln.length()-5));
        if(folderN != -1){ currentFile = folderN; return 0;}
    }
    return -1;
}

void create_folder(string name){
    if(fileSystem[currentFile].folderChecked){ return; } 
    folder aux;
    aux.rootFolder = currentFile;
    aux.folderName = name;
    fileSystem.push_back(aux);
}

void process_output(string ln){
    if(ln.substr(0,3) == "dir"){
        create_folder(ln.substr(4, ln.length() -4));
        return;
    }
    fileSystem[currentFile].files.push_back(ln.substr(0, ln.find(' ')));
}

int find_folder(string name){
    for(int i = 0; i < fileSystem.size(); i++){
        if(fileSystem[i].folderName == name){ return i; }
    }
    return -1;
}

void process_filetree(){
    int count = 0;
    for(int i = fileSystem.size()-1; i >= 0; i--){
        for(int j = 0; j < fileSystem[i].files.size(); j++){
            fileSystem[i].size += stoi(fileSystem[i].files[j]);
        }
        if(fileSystem[i].rootFolder != -1){ fileSystem[fileSystem[i].rootFolder].size += fileSystem[i].size;}
    }
    for (int i = 0; i < fileSystem.size(); i++){
        cout << fileSystem[i].folderName << "\n";
        if( fileSystem[i].size < 100000){
            count += fileSystem[i].size;
        }

    }
    cout << count;
}
