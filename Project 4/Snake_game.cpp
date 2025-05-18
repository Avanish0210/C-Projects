#include <iostream>
#include <conio.h>
#include <windows.h> // For Sleep()
#include <ctime>
using namespace std;

bool gameover;
const int width = 60;
const int height = 40;
int x, y;
int fruitx, fruity;
int tailx[100], taily[100];
int ntail;

enum direction{
    STOP = 0, LEFT , RIGHT , UP , DOWN
};
direction dir ;

int score;

void setup(){
    gameover = false;
    x = width / 2;
    y = height / 2;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;
    ntail = 0;
    dir = STOP;
    cout << "Game initialized!" << endl;
    
}

void draw(){
    // Alternative to system("cls") that works more reliably
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
    for(int i = 0;i < height;i++){
        for(int j=0;j < width;j++){
            if(i==0 || i==height-1 || j==0 || j==width-1){                cout<<"#"; // Draw the walls
            }else if(i==y && j==x){
                cout<<"O";// Draw the snake head
            }else if(i==fruity && j==fruitx){
                cout<<"F";
            }else {
                bool print = false;
                for(int k =0;k<ntail;k++){
                    if(tailx[k]==j && taily[k]==i){
                        cout<<"."; // Draw the snake tail
                        print = true;
                    }
                }
                if(!print){
                    cout<<" "; // Empty space
                }
            }

        }
        cout<<endl;
    }
    cout<<"Score: "<<score<<endl;

}

void keyboard_input(){
    if(kbhit()){
        char key = getch();
        switch(key){
            case 'a':
                if(dir != RIGHT)
                dir = LEFT;
                break;
            case 'd':
                if(dir != LEFT)
                    dir = RIGHT;
                break;
            case 'w':
                if(dir != DOWN)
                    dir = UP;
                break;
            case 's':
                if(dir != UP)
                    dir = DOWN;
                break;
            case 'x':
                gameover = true;
                break;
            default:
                break;
        }

        
    }
}
void logic(){
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x , prev2y;
    tailx[0]=x;
    taily[0]=y;
    for(int i=1;i<ntail;i++){
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch(dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
    }

    // Check for collision with walls
    if(x>=width) x=0; else if(x<0) x=width-1;
    if(y>=height) y=0; else if(y<0) y=height-1;

    // Check for collision with fruit
    if(x==fruitx && y==fruity){
        score += 10;
        fruitx = rand() % width;
        fruity = rand() % height;
        ntail++;
    }

    // Check for collision with tail
    for(int i =1;i<ntail;i++){
        if(tailx[i]==x && taily[i]==y){
            gameover = true; // Collision with tail
        
        }
    }
}
int main(){
    
    setup(); // Initialize game state
    // Debug message to confirm program start
    cout << "Snake game starting..." << endl;
    

    
    while(!gameover){
        draw();// Draw the game state
        keyboard_input(); // Get user input
        logic(); // Update game state
        Sleep(100); // Sleep for a short duration
    }
    // Game over messagedwss
    system("cls");
    cout << "Game Over!" << endl;
    cout << "Final Score: " << score << endl;
    return 0;
}