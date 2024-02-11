#include <iostream>
#include <pthread.h>
using namespace std;
const int board_size = 3;
string  Board[board_size][board_size];
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
    cout << "P1 possition= " <<P1position << endl;
    cout << "P2 position = " <<P2position << endl;

return 0;
}