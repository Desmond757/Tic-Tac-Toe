#include <iostream>
#include <pthread.h>
using namespace std;

int main(){
    string Board[3][3] = {{" "," "," "},{" "," "," "},{" "," "," "}};
    string P1, P2, P1name, P2name;
    printf("WELCOME TO MY TIC-TAC-TOE GAME!!!\n"); 
    printf("Supported characters are X and 0!\n"); 

    // Player1 inputs
    cout<< "Player 1, enter your name and character choice, seperated by space: ";
    cin >> P1name >> P1;

    // Conditional statements for inputs:::
    if(P1 == "X" || P1 == "x"){
        P2 = "O";
    }
    else if (P1 == "O" || P1 == "o"){
        P2 = "X";
    }
    else{
        cout << "Invalid character input for "<<P1name << endl;
        return 0;
    }

    // Player2 inputs
    cout<< "Player 2, enter your name:";
    cin >> P2name;
    
    cout << P1name << ", you chose: " << P1 << endl;
    cout << P2name << ", you are: " << P2 << endl;

    // Create and Display Board
    // for (int row = 0; row < 3; row++){
    //     cout <<"+---+---+---+"<< endl;
    //     cout<<"| ";//<<endl;
    //     for (int col = 0; col < 3; col++){
    //         //cout<<"|"<<endl;
    //         cout<<Board[row][col]<< " | ";
    //     }
    //     cout<<endl;        
    // }
    // cout <<"+---+---+---+"<< endl;

    /* Take players input*/

    // Ask player to chose a position on the board (1-9)
    // Use position chosen to place character on the board 
    int P1position, P2position, position;
    // cout<< P1name << ", enter your position (1-9): ";
    // cin >> P1position;

    // //Conditional Statement for invalid input for position
    // if (P1position < 1 || P1position > 9){
    //     cout << "Invalid position input for " << P1position << "try again (1-9): ";
    //     cin >> P1position;
    // }
    // cout<< P2name << ", enter your position (1-9): ";
    // cin >> P2position;

    // //Conditional Statement for invalid input for position
    // if (P2position < 1 || P2position > 9){
    //     cout << "Invalid position input for " << P2position << "try again (1-9): ";
    //     cin >> P2position;
    // }
    // // Check if Player 1 and Player2 play to the same position
    // if(P1position == P2position){
    //     cout << P1name << " and " << P2name << " cannot play into the same position!" << endl;
    //     return 0;
    // }
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){

        }
        cout<< P1name << ", enter your position (1-9): ";
        cin >> P1position;
        //Conditional Statement for invalid input for position
        if (P1position < 1 || P1position > 9){
            cout << "Invalid position input for " << P1position << "try again (1-9): ";
            cin >> P1position;
        }
        cout<< P2name << ", enter your position (1-9): ";
        cin >> P2position;

        //Conditional Statement for invalid input for position
        if (P2position < 1 || P2position > 9){
            cout << "Invalid position input for " << P2position << "try again (1-9): ";
            cin >> P2position;
        }
        // Check if Player 1 and Player2 play to the same position
        if(P1position == P2position){
            cout << P1name << " and " << P2name << " cannot play into the same position!" << endl;
            return 0;
        }
        //Conditional statement position for Player1
        if(P1position == 1){
            Board[0][0] = P1;
        }
        if(P1position== 2){
            Board[0][1] = "X";
        }
        if(P1position == 3){
            Board[0][2] = "X";
        }
        if (P1position == 4){
            Board[1][0] = "X";
        }
        if (P1position == 5){
            Board[1][1] = "X";
        }
        if (P1position == 6){
            Board[1][2] = "X";
        }
        if (P1position == 7){
            Board[2][0] = "X";
        }
        if (P1position == 8){
            Board[2][1] = "X";
        }
        if (P1position == 9){
            Board[2][2] = "X";
        }

        //Conditional statement position for Player1
        if(P2position == 1){
            Board[0][0] = P2;
        }
        if(P2position== 2){
            Board[0][1] = P2;
        }
        if(P2position == 3){
            Board[0][2] = P2;
        }
        if(P2position == 4){
            Board[1][0] = P2;
        }
        if (P2position == 5){
            Board[1][1] = P2;
        }
        if (P2position == 6){
            Board[1][2] = P2;
        }
        if (P2position == 7){
            Board[2][0] = P2;
        }
        if (P2position == 8){
            Board[2][1] = P2;
        }
        if (P2position == 9){
            Board[2][2] = P2;
        }
    }

    // int row, col = 3;
    // if (Board[row][col] == "X" || Board[row][col] == "O" || 
    //     Board[row][col] == "x" || Board[row][col] == "o")
    // {
    //     cout << "Position already taken.";
    // }
    




    for (int row = 0; row < 3; row++){
        cout <<"+---+---+---+"<< endl;
        cout<<"| ";//<<endl;
        for (int col = 0; col < 3; col++){
            //cout<<"|"<<endl;
            cout<<Board[row][col]<< " | ";
        }
        cout<<endl;        
    }
    cout <<"+---+---+---+"<< endl;

    
   
    return 0; 
}