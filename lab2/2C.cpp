#include <iostream>
#include <fstream>

using namespace std;

long long kol = 0;
void merge(long long* arr, long first, long pivot, long last);
void mergeSort(long long* arr, long first, long last);

int main()
{
    long long n;
    ifstream fin;
    ofstream fout;
    fin.open("inversions.in");
    fout.open("inversions.out");

    fin >> n;
    long long* arr = new long long[n];
    for (int i = 0; i < n; i++)
        fin >> arr[i];

    mergeSort(arr, 0, n);
    fout << kol;

    fin.close();
    fout.close();

    return 0;
}


void merge(long long* arr, long first, long pivot, long last)
{
    long i = 0, j = 0;
    long len_of_left_side = pivot - first; // расст между текущ расположением эл-та (pivot - 1) и местом,  
                                          // куда его надо переместить (first), + 1
    long long* buf = new long long[last - first];

    while (first + i < pivot && pivot + j < last)
    {
        if (arr[first + i] <= arr[pivot + j])
        {
            buf[i + j] = arr[first + i];
            i++;
        }
        else
        {
            buf[i + j] = arr[pivot + j];
            j++;
            kol += len_of_left_side - i; // счетчик инверсий
        }
    }

    while (first + i < pivot)
    {
        buf[i + j] = arr[first + i];
        i++;
    }

    while (pivot + j < last)
    {
        buf[i + j] = arr[pivot + j];
        j++;
        kol += len_of_left_side - i; // счетчик инверсий
    }

    for (i = 0; first + i < last; i++)
        arr[first + i] = buf[i];
}

void mergeSort(long long* arr, long first, long last)
{
    if (first + 1 >= last)
        return;
    long mid = (first + last) / 2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid, last);
    merge(arr, first, mid, last);
}