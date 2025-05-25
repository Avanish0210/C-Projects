#include <iostream>
using namespace std;

char board[3][3];
char symbol;


void draw(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<board[i][j]<<"     ";
            cout<<"     |     ";
        }
        cout<<endl;
        cout<<"\n -------------------------------------------\n";
    }

    cout<<"\n";
}

bool is_valid_move(int x, int y) {  // Function to check if the move is valid
    if(x<0 || x>2 || y<0 || y>2){
        cout<<"Invalid move. Try again.\n";
        return false;
    }
    if(board[x][y]!=' '){
        cout<<"Invalid move. Try again.\n";
        return false;
    }
    return true;
}

void player1_move(){
    int x ,y;
    while(true){
        cout<<"Player 1, enter your move (row and column): ";
        cin>>x>>y;
        if(is_valid_move(x,y)){
            board[x][y]='X';
            break;
        }
    }
}

void player2_move(){
    int x ,y;
    while(true){
        cout<<"Player 2, enter your move (row and column): ";
        cin>>x>>y;
        if(is_valid_move(x,y)){
            board[x][y]='O';
            break;
        }
    }
}


bool win(){
    //for rows
    for(int i=0;i<3;i++){
        if(board[i][0]!= ' ' &&board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            cout<<"Player "<<board[i][0]<<" wins!\n";
            return true;
        }
    }
    //for columns
    for(int i=0;i<3;i++){
        if(board[0][i] != ' ' && board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            cout<<"Player "<<board[0][i]<<" wins!\n";
            return true;
        }
    }
    //for diagonals
    if(board[0][0]!= ' ' && board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        cout<<"Player "<<board[0][0]<<" wins!\n";
        return true;
    }
    if(board[0][2]!= ' ' && board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        cout<<"Player "<<board[0][2]<<" wins!\n";
        return true;
    }

    // Check for draw
    bool tie= true;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' '){
                tie= false; // If there's an empty space, the game is not a draw
                break;
            }
        }
    }
    if(tie){
        cout<<"It's a draw!\n";
        return true; // Return true if it's a draw
    }
    return false; // No winner or draw yet
}

int main(){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=' '; // Initialize the board with empty spaces
        }
    }
    int x,y;
    while(true){
        draw();

        player1_move();
        draw();
        player2_move();
        draw();
        if(win()){
            break; // Exit the loop if there's a winner or a draw
        }
    }

}