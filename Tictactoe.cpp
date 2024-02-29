#include <iostream>
#include <pthread.h>
using namespace std;
const int board_size = 3;
string Board[board_size][board_size];
void Build_Board(){
    for(int row = 0; row < board_size; row++){
        for (int col = 0; col < board_size; col++){
            Board[row][col] = " ";
        }
        
    }
}
void display_Board(){
    for (int row = 0; row < 3; row++){
        cout <<"+---+---+---+"<< endl;
        cout<<"| ";//<<endl;
        for (int col = 0; col < 3; col++){
            //cout<<"|"<<endl;
            cout<<Board[row][col]<< " | ";
        }
        cout<<endl;        
    }
    cout <<"+---+---+---+"<< endl << endl;
}
void PlayersInput(string& P1, string& P1name, string& P2, string& P2name){

    do{
        // Player1 inputs
        cout<< "Player 1, enter your name and character choice, seperated by space: ";
        cin >> P1name >> P1;
        
        // Convert the character choice to uppercase
        for(size_t i = 0; i < P1.length(); i++){
            P1[i] = toupper(P1[i]);
        }
        // for (char& c : P1) {
        //     c = toupper(c);
        // }
        /*Check for invalid character input*/
        if(P1 == "X"){
            P2 = "O";
            break;
        }
        else if (P1 == "O"){
            P2 = "X";
            break;
        }
        else{
            cout << "Invalid character input for player "<< P1name << ". Try again." <<endl;
            //cin >> P1;
        }
    }while (true);
    
    // Player2 inputs
    cout<< "Player 2, enter your name: ";
    cin >> P2name;

    /*Print out players characters*/
    cout << P1name << ", you chose: " << P1 << endl;
    cout << P2name << ", you are: " << P2 << endl;
}

void assign_Position(int& P1position, int& P2position, string& P1name, string& P2name){
    do{
        cout<< P1name << ", enter your position (1-9): ";
        cin >> P1position;

        //Conditional Statement for invalid input for position
        if (P1position < 1 || P1position > 9){
            cout << "Invalid position input for " << P1name << " try again (1-9). \n";
            //cin >> P1position;
            continue;
        }

        cout<< P2name << ", enter your position (1-9): ";
        cin >> P2position;
        //Conditional Statement for invalid input for position
        while(P2position <= 1 || P2position >= 9){
            if(P2position < 1 || P2position > 9){
                cout << "Invalid position input for " << P2name << " try again (1-9): ";
            }
            cin >> P2position;
            //continue;
        }
        while(P1position == P2position){
            cout << P1name << " and " << P2name << " cannot play into the same position!" << endl;
            if(P1position == P2position){
            cout << P2name << " please enter a new position (1-9): ";
            }
            cin >> P2position;
            //continue;
        }
        break;
    }while(true);
}
void game(int& P1position, int& P2position, string& P1name, string& P2name, string& P1, string& P2){

    if(P1position == 1){
        Board[0][0] = P1;
    }
    if(P1position== 2){
        Board[0][1] = P1;
    }
    if(P1position == 3){
        Board[0][2] = P1;
    }
    if (P1position == 4){
        Board[1][0] = P1;
    }
    if (P1position == 5){
        Board[1][1] = P1;
    }
    if (P1position == 6){
        Board[1][2] = P1;
    }
    if (P1position == 7){
        Board[2][0] = P1;
    }
    if (P1position == 8){
        Board[2][1] = P1;
    }
    if (P1position == 9){
        Board[2][2] = P1;
    }
    if (P1position < 1 || P1position > 9){
        cout << "Invalid Position Input."<< endl;
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
void checkWin(int& P1position, int& P2position, string& P1, string& P2){
    //Check win for player 1
    if (Board[0][0] == P1 && Board[0][1] == P1 && Board[0][2] == P1){
        cout << P1 << "Wins!!!!" <<endl;
    }
    else if(Board[1][0] == P1 && Board[1][1] == P1 && Board[1][2] == P1){
        cout << P1 << "Wins!!!!" <<endl;
    }
    else if(Board[2][0] == P1 && Board[2][1] == P1 && Board[2][2] == P1){
        cout << P1 << "Wins!!!!" <<endl;
    }
    else{
        cout << "The game is a draw! Give it another try :))" << endl;
    }

    //Check win for Player 2
    if(Board[0][0] == P2 && Board[0][1] == P2 && Board[0][2] == P2){
        cout << P1 << "Wins!!!!" <<endl;
    }
    else if(Board[1][0] == P2 && Board[1][1] == P2 && Board[1][2] == P2){
        cout << P1 << "Wins!!!!" <<endl;
    }
    else if(Board[2][0] == P2 && Board[2][1] == P2 && Board[2][2] == P2){
        cout << P1 << "Wins!!!!" <<endl;
    }
    else{
        cout << "The game is a draw! Give it another try :))" << endl;
    }
    
}
int main(){
    /* declarations:::::::::*/
    int P1position, P2position;
    string P1, P2, P1name, P2name;
    printf("WELCOME TO MY TIC-TAC-TOE GAME!!!\n"); 
    printf("Supported characters are X and 0!\n\n"); 
    Build_Board();
    display_Board();
    PlayersInput(P1, P1name, P2, P2name);
    assign_Position(P1position, P2position, P1name, P2name);
    game(P1position, P2position, P1name, P2name, P1, P2);
    display_Board();
    checkWin(P1position, P2position, P1, P2);
    cout << "P1 possition= " <<P1position << endl;
    cout << "P2 position = " <<P2position << endl;

    // Game loop
    int moves = 0;
    while (moves < 9) { // Maximum of 9 moves in a Tic-Tac-Toe game

        // Alternate between player 1 and player 2
        if (moves % 2 == 0) {
            // cout << P1name << "'s turn:" << endl;
            assign_Position(P1position, P2position, P1name, P2name);
            game(P1position, P2position, P1name, P2name, P1, P2);
        } else {
            // cout << P2name << "'s turn:" << endl;
            assign_Position(P1position, P2position, P1name, P2name);
            game(P1position, P2position, P1name, P2name, P1, P2);
        }

        display_Board(); // Display the updated board after each move

        //moves++; // Increment the move count
    }
    cout << "The game is a draw!" << endl;

return 0;
}