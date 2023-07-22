#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    cout << "Starting program\n";
    fstream inputFile;
    inputFile.open("/home/ricar/Downloads/aoc_2022_5_input", ios::in);
    if (inputFile.is_open()){
        string ln;
        int containedCount = 0;
        vector<vector<char>> containers;
        bool containersCreated = false;
        bool containerRead = true;

        while (getline(inputFile,ln)){
            if(containerRead && (ln[1] == '1')){
                containerRead = false;
                for(int i = 0; i < containers.size(); i++){
                    if(containers[i].size()==0){
                        containers.erase(containers.begin()+i);
                    }
                    reverse(containers[i].begin(), containers[i].end());
                }
            }
            if(containerRead){
                for(int i = 1; i < ln.length(); i += 2){
                    if(!containersCreated){
                        vector<char> aux;
                        containers.push_back(aux);
                    }    
                    if(ln[i] != ' '){
                        containers[(i-1)/2].push_back(ln[i]);
                    }
                }
                containersCreated = true;
            } else if (ln[0] == 'm') {
                int i1 = ln.find(' ');
                ln = ln.substr(i1+1, ln.length()-i1); 
                i1 = ln.find(' ');
                int ntimes = stoi(ln.substr(0, i1));  
                i1 = ln.find(' ');
                ln = ln.substr(i1+1, ln.length()-i1); 
                i1 = ln.find(' ');
                ln = ln.substr(i1+1, ln.length()-i1); 
                i1 = ln.find(' ');
                int nfrom = stoi(ln.substr(0, i1));  
                i1 = ln.find(' ');
                ln = ln.substr(i1+1, ln.length()-i1); 
                i1 = ln.find(' ');
                ln = ln.substr(i1+1, ln.length()-i1); 
                i1 = ln.find(' ');
                int nto = stoi(ln.substr(0, i1));  
                for(int i = 0; i < ntimes; i++){
                    containers[nto-1].push_back(containers[nfrom-1].back());
                    containers[nfrom-1].pop_back();
                }
            }
        }
        for(int i = 0; i < containers.size(); i++){
            for(int j = 0; j < containers[i].size(); j++){
                cout << containers[i][j]; 
            }
            cout << "\n";
        }
        inputFile.close();
    }
}
