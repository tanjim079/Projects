#include<iostream>
#include<fstream>
using namespace std;

class base{
public:
    int m = 0, n = 0, i = 0;
    string preabs_A, preabs_E, preabs_H;
public:
    void attendancefile(){
        ofstream file("Attendance.txt");
        file << "Aditto: " << m << endl;
        file << "Era: " << n << endl;
        file << "Habiba: " << i << endl;
        file.close();
    }
    void count_A(){
        if (preabs_A == "p" || preabs_A == "P"){
            m++;
        }
        if (preabs_A == "a" || preabs_A == "A"){
            m;
        }
    }
    void count_E(){
        if (preabs_E == "p" || preabs_E == "P"){
            n++;
        }
        if (preabs_E == "a" || preabs_E == "A"){
            n;
        }
    }
    void count_H(){
        if (preabs_H == "p" || preabs_H == "P"){
            i++;
        }
        if (preabs_H == "a" || preabs_H == "A"){
            i;
        }
    }
    void takeattendance(){
        cout << "Aditto: ";
        cin >> preabs_A;
        cout << "Era: ";
        cin >> preabs_E;
        cout << "Habiba: ";
        cin >> preabs_H;
    }
    void readAttendance() {
        ifstream file("Attendance.txt");
        if (file.is_open()) {
            string temp;
            file >> temp >> m >> temp >> n >> temp >> i;
            file.close();
        }
    }
};

int main(){
    base a;
    a.readAttendance();
    cout << "Give p for Present and a for Absent" << endl << endl;
    a.takeattendance();
    a.count_A();
    a.count_E();
    a.count_H();
    a.attendancefile();
}
