#include <iostream>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class RPS {
public:
    void home() {
        cout << endl << endl << endl;
        cout << "\t\t\t\t ------------------------------------------------" << endl;
        cout << "\t\t\t\t|          Rock Paper & Scissor                  |" << endl;
        cout << "\t\t\t\t ------------------------------------------------" << endl << endl;
        cout << "\t\t\t\t\t\t[1] Person vs Person" << endl;
        cout << "\t\t\t\t\t\t[2] Person vs Computer" << endl;
        cout << "\t\t\t\t\t\t[3] Instruction" << endl;
        cout << "\t\t\t\t\t\t[4] Exit" << endl;
        cout << "\t\t\t\t\t\tSelect option: ";
    }

public:
    string ROCK = "r";
    string PAPER = "p";
    string SCISSOR = "s";
    string input1, input2;
    string name1, name2;

public:
    void nameinput() {
        cout << endl << endl << endl;
        cout << "\t\t\t\t\t\tPlayer-1 name: ";
        cin >> name1;
        cout << "\t\t\t\t\t\tPlayer-2 name: ";
        cin >> name2;
    }

    void nameinputComputer() {
        cout << endl << endl << endl;
        cout << "\t\t\t\t\t\tPlayer-1 name: ";
        cin >> name1;
        name2 = "Computer";
    }

    void user1input() {
        cout << endl << endl << endl;
        cout << "\t\t\t\t\t\t" << name1 << "'s INPUT: ";
        cin >> input1;
    }

    void user2input() {
        cout << endl << endl << endl;
        cout << "\t\t\t\t\t\t" << name2 << "'s INPUT: ";
        cin >> input2;
    }

    void computerInput() {
        srand(time(0));
        int randomChoice = rand() % 3;

        if (randomChoice == 0) {
            input2 = ROCK;
        } else if (randomChoice == 1) {
            input2 = PAPER;
        } else {
            input2 = SCISSOR;
        }
    }

    void wrongdetect1() {
        cout << endl << endl << endl;
        while (input1 != "r" && input1 != "p" && input1 != "s") {
            cout << "\t\t\t\t\t\tInput r for ROCK, p for PAPER, s for SCISSOR" << endl << endl;
            cout << "\t\t\t\t\t\t" << name1 << "'s INPUT: ";
            cin >> input1;
        }
    }

    void wrongdetect2() {
        cout << endl << endl << endl;
        while (input2 != "r" && input2 != "p" && input2 != "s") {
            cout << "\t\t\t\t\t\tInput r for ROCK, p for PAPER, s for SCISSOR" << endl << endl;
            cout << "\t\t\t\t\t\t" << name2 << "'s INPUT: ";
            cin >> input2;
        }
    }
};

class decision : public RPS {
public:
    void showMove() {
        cout << endl << endl << endl;
        if (input1 == "r") {
            cout << "\t\t\t\t\t\t" << name1 << ": ROCK" << endl;
        }
        if (input1 == "p") {
            cout << "\t\t\t\t\t\t" << name1 << ": PAPER" << endl;
        }
        if (input1 == "s") {
            cout << "\t\t\t\t\t\t" << name1 << ": SCISSOR" << endl;
        }
        if (input2 == "r") {
            cout << "\t\t\t\t\t\t" << name2 << ": ROCK" << endl << endl;
        }
        if (input2 == "p") {
            cout << "\t\t\t\t\t\t" << name2 << ": PAPER" << endl << endl;
        }
        if (input2 == "s") {
            cout << "\t\t\t\t\t\t" << name2 << ": SCISSOR" << endl << endl;
        }
    }

    void win() {
        cout << endl << endl << endl;
        if (input1 == ROCK && input2 == PAPER) {
            cout << "\t\t\t\t\t\t" << name2 << " Wins! Paper wraps Rock." << endl;
        } else if (input1 == PAPER && input2 == SCISSOR) {
            cout << "\t\t\t\t\t\t" << name2 << " Wins! Scissors cut Paper." << endl;
        } else if (input1 == SCISSOR && input2 == ROCK) {
            cout << "\t\t\t\t\t\t" << name2 << " Wins! Rock smashes Scissors." << endl;
        } else if (input1 == ROCK && input2 == SCISSOR) {
            cout << "\t\t\t\t\t\t" << name1 << " Wins! Rock smashes Scissors." << endl;
        } else if (input1 == PAPER && input2 == ROCK) {
            cout << "\t\t\t\t\t\t" << name1 << " Wins! Paper wraps Rock." << endl;
        } else if (input1 == SCISSOR && input2 == PAPER) {
            cout << "\t\t\t\t\t\t" << name1 << " Wins! Scissors cut Paper." << endl;
        } else {
            cout << "\t\t\t\t\t\tIt's a tie!" << endl;
        }
    }
};

int main() {
    decision a;
    game:
    a.home();
    char choose = getch();

    if (choose == '1') {
        system("cls");
        a.nameinput();
        system("cls");
        a.user1input();
        a.wrongdetect1();
        system("cls");
        a.user2input();
        a.wrongdetect2();
        system("cls");
        a.showMove();
        a.win();
        cout << " \n\n\n\n\t\t\t\t\t\tPress any key to return home.";
        getch();
    }

    if (choose == '2') {
        system("cls");
        a.nameinputComputer();
        system("cls");
        a.user1input();
        a.wrongdetect1();
        system("cls");
        a.computerInput();
        system("cls");
        a.showMove();
        a.win();
        cout << " \n\n\n\n\t\t\t\t\t\tPress any key to return home.";
        getch();
    }

    if (choose == '3') {
        system("cls");
        cout << "\n\n\n\n\n\t\t\t\t Input \n\t\t\t\t [1] p for Paper \n\t\t\t\t [2] r for Rock \n\t\t\t\t [3] s for Scissor " << endl;
        cout << "\t\t\t\t Press any key to return home.";
        getch();
    }

    if (choose == '4') {
        exit(0);
    }

    do {
        system("cls");
        goto game;
    } while (getch());
}

