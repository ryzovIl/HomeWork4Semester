#include <windows.h>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <filesystem>
#include <iomanip>

using namespace std;

int main(int argc, char** argv)
{
    char s1[255];
    ifstream file("Text.txt");;
    int n = 0;
    cin >> n;
    n = (n - 1) * 6;
    file.seekg(n);
    file >> s1;
    cout << s1;

    file.close();
    return 0;
}