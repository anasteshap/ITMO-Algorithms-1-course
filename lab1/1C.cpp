#include <iostream>
#include <fstream>

using namespace std;

int max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

int main()
{
    int h, w;
    ifstream fin;
    ofstream fout;

    fin.open("turtle.in");
    fout.open("turtle.out");

    if (!fin.is_open() || !fout.is_open()) return 2134;

    fin >> h >> w;

    int** table = new int* [h];

    for (int i = 0; i < h; i++)
        table[i] = new int[w] {0};

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            fin >> table[i][j];
        }
    }

    for (int i = h - 1; i > 0; i--)
    {
        table[i - 1][0] += table[i][0];
    }

    for (int j = 0; j < w - 1; j++)
    {
        table[h - 1][j + 1] += table[h - 1][j];
    }

    for (int i = h - 2; i >= 0; i--)
    {
        for (int j = 1; j < w; j++)
        {
            table[i][j] += max(table[i + 1][j], table[i][j - 1]);
            if ((i == 0) && (j == w - 1))
                fout << table[i][j];
        }
    }

    for (int i = 0; i < h; i++)
        delete[] table[i];
    delete[] table;

    fin.close();
    fout.close();

    return 0;
}