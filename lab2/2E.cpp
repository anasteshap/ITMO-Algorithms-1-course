#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int k;

void findOrderStatistic(int* array, int l, int r);

int main()
{
    ifstream fin("kth.in");
    ofstream fout("kth.out");

    int n;
    fin >> n >> k;
    k--;

    int A, B, C;
    int* arr = new int[n] { 0 };

    fin >> A >> B >> C >> arr[0] >> arr[1];

    for (int i = 2; i < n; i++)
        arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;

    findOrderStatistic(arr, 0, n - 1);
    fout << arr[k];

    fin.close();
    fout.close();

    return 0;
}

void findOrderStatistic(int* array, int left, int right)
{
    if (left < right)
    {
        int mid = array[(left + right) / 2];
        int i = left;
        int j = right;

        while (i <= j)
        {
            while (array[i] < mid)
                i++;

            while (array[j] > mid)
                j--;

            if (i <= j)
            {
                swap(array[i], array[j]);
                i++;
                j--;
            }
        }

        if (k <= j)
            findOrderStatistic(array, left, j);
        else
            findOrderStatistic(array, i, right);
    }       
}
