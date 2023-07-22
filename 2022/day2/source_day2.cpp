#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int fscore(char opponent, char player);

int main(){
    cout << "Starting program\n";
    fstream inputFile;
    inputFile.open("/home/ricar/Downloads/aoc_2022_2_input", ios::in);
    if (inputFile.is_open()){
        string ln;
        int score = 0;
        while (getline(inputFile, ln)){
            score += fscore(ln[0],ln[2]);
        }
        cout << "Total score:\t" << score;
        inputFile.close();
    }
};

int fscore(char opponent, char player){
    int score_n = 0;
    switch(player){
        case 'X':
            score_n += 1;
            if(opponent == 'A'){
                score_n += 3;
            } else if (opponent == 'B'){
                score_n += 0;
            } else if (opponent == 'C'){
                score_n += 6;
            } else {
                return -1;
            }
            break;
        case 'Y':
            score_n += 2;
            if(opponent == 'A'){
                score_n += 6;
            } else if (opponent == 'B'){
                score_n += 3;
            } else if (opponent == 'C'){
                score_n += 0;
            } else {
                return -1;
            }
            break;
        case 'Z':
            score_n += 3;
            if(opponent == 'A'){
                score_n += 0;
            } else if (opponent == 'B'){
                score_n += 6;
            } else if (opponent == 'C'){
                score_n += 3;
            } else {
                return -1;
            }
            break;
        default:
            return -1;
            break;
    }
    return score_n;
};
