#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <fstream>
using namespace std;


int main() {
    bool flag1, flag2, flag_quotes;
    int ch;
    int counter = 0;
    ifstream fin("comments.txt", ios::in);
    flag1 = 0;
    flag2 = 0;
    flag_quotes = 0;

    if (!fin) {
        cout << "Can not find" << endl;
        return 1;
    }
    ofstream fout("nocomments.txt");
    while ((ch = fin.get()) != EOF) {
        if (char(ch) == '"') {
            fout << char(ch);
            while ((ch = fin.get()) != '"') {
                fout << char(ch);
            }
            fout << char(ch);
        }
        if (char(ch) == '/'){
            while ((ch = fin.get()) != '\n');
        }
        if (char(ch) != '"' && char(ch) != '/')
            fout << char(ch);
    }
    fin.close();
    fout.close();
}