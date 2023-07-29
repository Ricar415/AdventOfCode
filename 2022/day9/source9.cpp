#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// First try btw 
//            U(0) ^
//                 |
//               (+y)
//                |
//   L(3) <--(-x)---(+x)--> R(1)
//                |
//              (-y)
//               |
//          D(2) v

class motion{
public:
    int direction = -1;
    int val = 0;
};

class position{
public:
    int x = 0;
    int y = 0;
};

class rope{
public:
    position head, tail;
    vector<position> positions;
};

void move_rope(rope &irope, motion movement);
void move_head(rope &irope, int direction);
void move_tail(rope &irope);
void update_vals(rope &irope);

int maxX = 0;
int minX = 0;
int maxY = 0;
int minY = 0;

int main(){
    cout << "Starting program\n";
    fstream inputFile;
    inputFile.open("/media/ricar/E/AdventOfCode/inputFiles/aoc_2022_9_input", ios::in);
    vector<motion> directions;
    if (inputFile.is_open()){
        string ln;
        while (getline(inputFile,ln)){
            motion aux;
            aux.val = stoi(ln.substr(2,ln.length()-2));
            char auxc = ln[0];
            switch (auxc) {
                case 'U':
                    aux.direction = 0;
                    break;
                case 'R':
                    aux.direction = 1;
                    break;
                case 'D':
                    aux.direction = 2;
                    break;
                case 'L':
                    aux.direction = 3;
                    break;
                default:
                    aux.direction = -1;
                    cerr << "Direction reading error: " << ln << endl;
                    break;
            }
            //cout << ln << " -> " << aux.direction << ":" << aux.val << "\n";
            directions.push_back(aux);
        }
        inputFile.close();
    }
    rope irope;
    for(int i = 0; i < directions.size(); i++){
        move_rope(irope, directions[i]);
    }
    int count = 0;
    int visited[maxX+abs(minX)+1][maxY+abs(minY)+1] = {};
    for(int i = 0; i < irope.positions.size(); i++){
        int xIndex = abs(minX) + irope.positions[i].x - 1;
        int yIndex = abs(minY) + irope.positions[i].y - 1;
        if(visited[xIndex][yIndex] == 0){
            visited[xIndex][yIndex] = 1;
            count++;
        }
    }
    cout << count;
}

void move_rope(rope &irope , motion movement){
    for(int i = 0; i < movement.val; i++){
        move_head(irope, movement.direction);
        move_tail(irope);
        irope.positions.push_back(irope.tail);
        update_vals(irope);
        //cout << "(" << irope.head.x << "," << irope.head.y << "):(" << irope.tail.x << "," << irope.tail.y << ")\n";
    }
}

void move_head(rope &irope, int direction){
    switch(direction){
        case 0:
            irope.head.y++;
            break;
        case 1:
            irope.head.x++;
            break;
        case 2:
            irope.head.y--;
            break;
        case 3:
            irope.head.x--;
            break;
        default:
            break;
    }
}

void move_tail(rope &irope){
    if((irope.head.x - irope.tail.x) == 2){
        irope.tail.x++;
        if(irope.head.y < irope.tail.y){
            irope.tail.y--;
        }
        if(irope.head.y > irope.tail.y){
            irope.tail.y++;
        }
        return;
    }
    if((irope.head.x - irope.tail.x) == -2){
        irope.tail.x--;
        if(irope.head.y < irope.tail.y){
            irope.tail.y--;
        }
        if(irope.head.y > irope.tail.y){
            irope.tail.y++;
        }
        return;
    }
    if((irope.head.y - irope.tail.y) == 2){
        irope.tail.y++;
        if(irope.head.x < irope.tail.x){
            irope.tail.x--;
        }
        if(irope.head.x > irope.tail.x){
            irope.tail.x++;
        }
        return;
    }
    if((irope.head.y - irope.tail.y) == -2){
        irope.tail.y--;
        if(irope.head.x < irope.tail.x){
            irope.tail.x--;
        }
        if(irope.head.x > irope.tail.x){
            irope.tail.x++;
        }
        return;
    }
}

void update_vals(rope &irope){
    maxX = max(maxX, irope.tail.x);
    minX = min(minX, irope.tail.x);
    maxY = max(maxY, irope.tail.y);
    minY = min(minY, irope.tail.y);
};
