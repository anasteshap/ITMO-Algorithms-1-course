#include <iostream>
#include <fstream>

using namespace std;

void merge(int* arr, int first, int pivot, int last);
void mergeSort(int* arr, int first, int last);

int main()
{
    int n;
    ifstream fin;
    ofstream fout;
    fin.open("sort.in");
    fout.open("sort.out");

    fin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        fin >> arr[i];

    mergeSort(arr, 0, n);

    for (int i = 0; i < n; i++)
        fout << arr[i] << " ";

    fin.close();
    fout.close();

    return 0;
}


void merge(int* arr, int first, int pivot, int last)
{
    int i = 0, j = 0;

    int* buf = new int[last - first];
    while (first + i < pivot && pivot + j < last)
    {
        if (arr[first + i] < arr[pivot + j])
        {
            buf[i + j] = arr[first + i];
            i++;
        }
        else
        {
            buf[i + j] = arr[pivot + j];
            j++;
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
    }

    for (i = 0; first + i < last; i++)
        arr[first + i] = buf[i];
}

void mergeSort(int* arr, int first, int last)
{
    if (first + 1 >= last)
        return;
    int mid = (first + last) / 2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid, last);
    merge(arr, first, mid, last);
}
