#include<iostream>
using namespace std;
char board[9] = {' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '};
void show_board();
void get_x_player_choice();
void get_o_player_choice();
int count_board(char symbol);
char check_winner();
void player_vs_player();


int main(){
    player_vs_player();
    return 0;
}

void show_board(){
    cout<<"\t\t\t"<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"\t\t\t"<<"   "<<board[0]<<"   |   "<<board[1]<<"   |   "<<board[2]<<endl;
    cout<<"\t\t\t"<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"\t\t\t"<<"------------------------"<<endl;
    cout<<"\t\t\t"<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"\t\t\t"<<"   "<<board[3]<<"   |   "<<board[4]<<"   |   "<<board[5]<<endl;
    cout<<"\t\t\t"<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"\t\t\t"<<"------------------------"<<endl;
    cout<<"\t\t\t"<<"   "<<"    |   "<<"    |   "<<endl;
    cout<<"\t\t\t"<<"   "<<board[6]<<"   |   "<<board[7]<<"   |   "<<board[8]<<endl;
    cout<<"\t\t\t"<<"   "<<"    |   "<<"    |   "<<endl;
}

void get_x_player_choice(){
    while(true){
        cout<<" select your position (1 - 9) : ";
        int choice;
        cin>>choice;
        choice--;
        if(choice < 0 || choice > 8 ){
            cout<<" Please select your position from (1 - 9)."<<endl;
        }
        else if(board[choice] != ' '){
            cout<<"Please select an empty position."<<endl;
        }
        else{
            board[choice]='X';
            break;
        }
    }
}

void get_o_player_choice(){
    while(true){
        cout<<"select your position (1 - 9) : ";
        int choice;
        cin>>choice;
        choice--;
        if(choice < 0 || choice > 8 ){
            cout<<" Please select your position from (1 - 9)."<<endl;
        }
        else if(board[choice] != ' '){
            cout<<"Please select an empty position."<<endl;
        }
        else{
            board[choice]='O';
            break;
        }
    }
}

int count_board(char s){
    int total=0;
    for(int i=0;i<9;i++){
        if(board[i] == s){
            total += 1 ;
        }
    }
    return total;
}

char check_winner(){
    if(board[0] == board[1] && board[1] == board[2] && board[0] != ' '){
        return board[0];
    }
    else if(board[3] == board[4] && board[4] == board[5] && board[3] != ' '){
        return board[3];
    }
    else if(board[6] == board[7] && board[7] == board[8] && board[6] != ' '){
        return board[6];
    }
    else if(board[0] == board[3] && board[3] == board[6] && board[0] != ' '){
        return board[0];
    }
    else if(board[1] == board[4] && board[4] == board[7] && board[1] != ' '){
        return board[1];
    }
    else if(board[2] == board[5] && board[5] == board[8] && board[2] != ' '){
        return board[2];
    }
    else if(board[0] == board[4] && board[4] == board[8] && board[0] != ' '){
        return board[0];
    }
    else if(board[2] == board[4] && board[4] == board[6] && board[2] != ' '){
        return board[2];
    }
    else if(count_board('X') + count_board('O') < 9){
        return 'C';
    }
    else{
        return 'D';
    }
}

void player_vs_player(){
    string x_player_name , o_player_name;
    cout<<"Enter X player name : ";
    cin>>x_player_name;
    cout<<"Enter O player name : ";
    cin>>o_player_name;
    while(true){
        system("cls");
        show_board();
        if(count_board('X') == count_board('O')){
            cout<<x_player_name<<"'s Turn";
            get_x_player_choice();
        }
        else{
            cout<<o_player_name<<"'s Turn";
            get_o_player_choice();
        }
        char winner = check_winner();
        if(winner == 'X'){
            system("cls");
            show_board();
            cout<< x_player_name <<" won the game!..."<<endl;
            break;
        }
        else if(winner == 'O'){
            system("cls");
            show_board();
            cout<< o_player_name <<" won the game!..."<<endl;
            break;
        }
        else if(winner == 'D'){
            show_board();
            cout<<"Game is draw ."<<endl;
            break;
        }
    }
}