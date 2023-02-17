#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    long long a, b;

    ifstream fin;
    ofstream fout;

    fin.open("aplusbb.in");
    fout.open("aplusbb.out");

    if (!fin.is_open() || !fout.is_open()) return 2134;

    fin >> a >> b;
    fout << a + b * b;

    fin.close();
    fout.close();

    return 0;
}