#include <iostream>
#include <fstream>

using namespace std;

void AntiQuickSort(ifstream& fin, ofstream& fout);

int main()
{
    ifstream fin("antiqs.in");
    ofstream fout("antiqs.out");

    AntiQuickSort(fin, fout);

    fin.close();
    fout.close();

    return 0;
}

void AntiQuickSort(ifstream& fin, ofstream& fout)
{
    int n, temp;
    fin >> n;

    if (n == 1) 
        fout << "1\n";
    else
    {
        int* arr = new int[n];

        for (int i = 0; i < n; i++)
            arr[i] = i + 1;

        for (int i = 2; i < n; i++)
        {
            temp = arr[i / 2];
            arr[i / 2] = arr[i];
            arr[i] = temp;
        }

        for (int i = 0; i < n; i++)
            fout << arr[i] << " ";
        fout << "\n";

        delete[] arr;
    }
}