// #include <sstream>
// #include <iostream>

// int main(){
//     std::string s;
//     int x;

//     getline(std::cin, s);
//     std::stringstream(s) >> x;

//     // std::cin >> s;

//     std::cout << s << '\n';
//     std::cout << x << '\n';
// }

#include <iostream>
#include <string>

using namespace std;

void displayGrid(char aGrid[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "|\t" << aGrid[i][j] << "\t";
        }
        cout << "|\n";
    }
}

bool checkForWinner(char aGrid[3][3]){
    if(aGrid[0][0] == aGrid[0][1] && aGrid[0][0] == aGrid[0][2]){
        return true;
    }
    else if(aGrid[1][0] == aGrid[1][1] && aGrid[1][0] == aGrid[1][2]){
        return true;
    }
    else if(aGrid[2][0] == aGrid[2][1] && aGrid[2][0] == aGrid[2][2]){
        return true;
    }
    else if(aGrid[0][0] == aGrid[1][0] && aGrid[0][0] == aGrid[2][0]){
        return true;
    }
    else if(aGrid[0][1] == aGrid[1][1] && aGrid[0][1] == aGrid[2][1]){
        return true;
    }
    else if(aGrid[0][2] == aGrid[1][2] && aGrid[0][2] == aGrid[2][2]){
        return true;
    }
    else if(aGrid[0][0] == aGrid[1][1] && aGrid[0][0] == aGrid[2][2]){
        return true;
    }
    else if(aGrid[2][2] == aGrid[1][1] && aGrid[2][2] == aGrid[2][0]){
        return true;
    }

    return false;
}

bool checkForValidInput(int input, char aGrid[3][3]){
    if(input < 0 || input > 8){
        cout << "Please enter a number between 0 and 8\n";
        return false;
    }
    return true;
}

int main(){
    bool gameOver = false;
    bool xTurn = true;

    char grid[3][3];
    char ctr = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            grid[i][j] = ctr++ + '0';
        }
    }

    while(!gameOver){
        if(xTurn){
            cout << "It is X's turn\n";
        }else{
            cout << "It is O's turn\n";
        }
        int input = 0;

        

        displayGrid(grid);
        do {
            cout << "Enter a number to select that square\n";
            cin >> input;
        }while(!checkForValidInput(input, grid));

        
        int row = input / 3;
        int col = input % 3;
        
        if(xTurn){
            grid[row][col] = 'X';
        }else{
            grid[row][col] = 'O';
        }

        if(checkForWinner(grid)){
            if(xTurn){
                cout << "X is the winner!\n";
            }else{
                cout << "0 is the winner!\n";
            }
            exit(0);
        }

        xTurn = !xTurn;
    }
    return 0;
}
