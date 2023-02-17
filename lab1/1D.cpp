#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n, temporary;

    ifstream fin;
    ofstream fout;

    fin.open("smallsort.in");
    fout.open("smallsort.out");

    if (!fin.is_open() || !fout.is_open()) return 2134;

    fin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; i++)
        fin >> array[i];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] > array[j])
            {
                temporary = array[j];
                array[j] = array[i];
                array[i] = temporary;
            }
        }
        fout << array[i] << " ";
    }
    fout << array[n - 1];

    delete[] array;
    fin.close();
    fout.close();

    return 0;
}