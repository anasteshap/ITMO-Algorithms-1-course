#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n, temporary_int;
    float temporary_float;

    ifstream fin;
    ofstream fout;

    fin.open("sortland.in");
    fout.open("sortland.out");
    if (!fin.is_open() || !fout.is_open()) return 2134;

    fin >> n;
    int* identification_num = new int[n];
    float* M = new float[n];
    

    for (int i = 0; i < n; i++)
    {
        fin >> M[i];
        identification_num[i] = i + 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (M[i] > M[j])
            {
                temporary_float = M[j];
                M[j] = M[i];
                M[i] = temporary_float;

                temporary_int = identification_num[j];
                identification_num[j] = identification_num[i];
                identification_num[i] = temporary_int;
            }
        }
    }

    fout << identification_num[0] << " " << identification_num[n / 2] << " " << identification_num[n - 1];

    delete[] M;
    delete[] identification_num;
    fin.close();
    fout.close();

    return 0;
}