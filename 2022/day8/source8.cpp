#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class tree{
public:
    int height  = 0;
    int heightt = 0;
    int heightb = 0;
    int heightr = 0;
    int heightl = 0;
    bool visible = false;
};

vector<vector<tree>> forest;
bool check_visible(int i, int j);

int main(){
    fstream inputFile;
    inputFile.open("/media/ricar/E/AdventOfCode/inputFiles/aoc_2022_8_input", ios::in);
    if (inputFile.is_open()){
        string ln;
        int containedCount = 0;
        char x;

        while (getline(inputFile, ln)){
            vector<tree> aux;
            for(int i = 0; i < ln.length(); i++){
                tree auxt;
                auxt.height = stoi(ln.substr(i,1));
                aux.push_back(auxt);
            }
            forest.push_back(aux);
        }
        inputFile.close();
        for(int i = forest.size()-1; i >= 0; i--){
            for(int j = forest[i].size()-1; j >= 0; j--){
                check_visible(i,j);
            }
        }
        for(int i = 0; i < forest.size(); i++){
            for(int j = 0; j < forest[i].size(); j++){
                check_visible(i,j);
            }
        }
        int visible = 0;
        for(int i = 0; i < forest.size(); i++){
            for(int j = 0; j < forest[i].size(); j++){
                cout << forest[i][j].heightr;
                if(forest[i][j].visible){ visible ++; }
            }
            cout << "\n";
        }
        cout << visible;
    }
}

bool check_visible(int i, int j){
    if(i == 0){ forest[i][j].heightt = forest[i][j].height; }
    if(j == 0){ forest[i][j].heightl = forest[i][j].height; }
    if(i == forest.size()-1){       forest[i][j].heightb = forest[i][j].height; }
    if(j == forest[0].size()-1){    forest[i][j].heightr = forest[i][j].height; }
    if(i == 0 || j == 0 || i == forest.size()-1 || j == forest[0].size()-1){
        forest[i][j].visible = true;
        return true;
    }
    forest[i][j].heightt = max(forest[i][j].height, forest[i-1][j].heightt);
    forest[i][j].heightb = max(forest[i][j].height, forest[i+1][j].heightb);
    forest[i][j].heightl = max(forest[i][j].height, forest[i][j-1].heightl);
    forest[i][j].heightr = max(forest[i][j].height, forest[i][j+1].heightr);
    if(    (forest[i][j].height > forest[i-1][j].heightt)
        || (forest[i][j].height > forest[i+1][j].heightb)
        || (forest[i][j].height > forest[i][j-1].heightl)
        || (forest[i][j].height > forest[i][j+1].heightr)){
        forest[i][j].visible = true;
        return true;
    }
    forest[i][j].visible = false;
    return false;
}
