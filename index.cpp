#include <iostream>
#include <ctime>
#include <random>
using namespace std;

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void show_board();
void get_x_player_choice();
void get_o_player_choice();
void get_computer_choice();
int count_board(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();

int main() {

    int mode;
    cout << "Enter 1 for Computer VS Player" << endl;
    cout << "Enter 2 for Player VS Player" << endl;
    
    cin >> mode;
    if(mode == 1) {
        computer_vs_player();
    }
    else if(mode == 2) {
        player_vs_player();
    }
    else {
        cout << "Please Enter a Valid Game Mode" << endl;
    }

    return 0;
}

void get_computer_choice() {
    srand(time(0));
    int choice;

    do {
        choice = rand() % 10;
    } while (board[choice] != ' ');
    board[choice] = 'O';
    
}

void get_x_player_choice() {
    while(1) {
        cout << "Select Your Position (1 - 9): ";
        int choice;
        cin >> choice;
        choice--;

        if(choice < 0 || choice > 8) {
            cout << "Invalid Choice!" << endl << "Please Select Your Position (1 - 9): ";
        } 
        else if(board[choice] != ' ') {
            cout << "Invalid Choice!" << endl << "Please select an empty position in the Board: ";
        }
        else {
            board[choice] = 'X';
            break;
        }
    }
}


void get_o_player_choice() {
    while(1) {
        cout << "Select Yout Position (1 - 9): ";
        int choice;
        cin >> choice;
        choice--;

        if(choice < 0 || choice > 8) {
            cout << "Invalid Choice!" << endl << "Please Select Your Position (1 - 9): ";
        } 
        else if(board[choice] != ' ') {
            cout << "Invalid Choice!" << endl << "Please select an empty position in the Board: ";
        }
        else {
            board[choice] = 'O';
            break;
        }
    }
}

int count_board(char symbol) {
    int total = 0;
    for(int i=0; i<9; i++) {
        if(board[i] == symbol) {
            total++;
        }
    }
    return total;
}

char check_winner() {
    if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ') {
        return board[0];
    }
    if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ') {
        return board[3];
    }
    if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ') {
        return board[6];
    }

    if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ') {
        return board[0];
    }
    if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ') {
        return board[1];
    }
    if(board[2] == board[5] && board[5] == board[8] && board[2] != ' ') {
        return board[2];
    }

    if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ') {
        return board[0];
    }

    if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ') {
        return board[2];
    }

    if(count_board('X') + count_board('O') < 9) {
        return 'C';
    }
    else return 'D';
}

void computer_vs_player() {
    string player_name;
    cout << "Enter your Name: ";
    cin >> player_name;

    while(1) {
        system("cls");
        show_board();
        if(count_board('X') == count_board('O')) {
            cout << player_name << "'s turn." << endl;
            get_x_player_choice();
        }
        else {
            get_computer_choice();
        }
        char winner = check_winner();
        if(winner == 'X') {
            system("cls");
            show_board();
            cout <<player_name << " has won the game." << endl;
            break;
        }
        else if(winner == 'O') {
            system("cls");
            show_board();
            cout <<"Computer won the game." << endl;
            break;
        }
        else if(winner == 'D') {
            cout << "Game is Draw." << endl;
            break;
        }
    }
}

void player_vs_player() {
    string x_player_name, o_player_name;
    cout << "Enter X Player Name: ";
    cin >> x_player_name;

    cout << "Enter O Player Name: ";
    cin >> o_player_name;

    while(1) {
        system("cls");
        show_board();
        if(count_board('X') == count_board('O')) {
            cout << x_player_name << "'s turn" << endl;
            get_x_player_choice();
        }
        else {
            cout << o_player_name << "'s turn" << endl;
            get_o_player_choice();
        }
        char winner = check_winner();
        if(winner == 'X') {
            system("cls");
            show_board();
            cout << x_player_name <<" has won the game." << endl;
            break;
        }
        if(winner == 'O') {
            system("cls");
            show_board();
            cout << o_player_name <<" has won the game." << endl;
            break;
        }
        else if(winner == 'D') {
            cout << "Game is Draw." << endl;
            break;
        }
    }
}

void show_board() {
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[0] << "  |   " << board[1] <<  "  |   " << board[2] << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[3] << "  |   " << board[4] <<  "  |   " << board[5] << endl;
    cout << "--------------------" << endl;
    cout << "   " << "   |   " << "   |   " << endl;
    cout << "   " << board[6] << "  |   " << board[7] <<  "  |   " << board[8] << endl;
}