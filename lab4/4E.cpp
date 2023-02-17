#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int first_occurrence(vector<int>& arr, int inquiry)
{
    int left = 0, right = arr.size();
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (inquiry <= arr[mid])
            right = mid; // проверяем, какую часть нужно отбросить с поиска
        else left = mid + 1;
    }
    if (right >= arr.size())
        return -2;
    else if (arr[right] != inquiry)
        return -2;
    return right;
}

int last_occurrence(vector<int>& arr, int inquiry)
{
    int left = 0, right = arr.size();
    int mid;
    while (left + 1 < right) {
        mid = (left + right) / 2;
        if (inquiry < arr[mid])
            right = mid; // проверяем, какую часть нужно отбросить с поиска
        else left = mid;
    }
    if (right < arr.size() && arr[right - 1] == inquiry)
        return right - 1;
    else if (left >= 0 && arr[left - 1] == inquiry)
        return left;
    else
        return -2;
}

int main()
{
    ifstream fin("binsearch.in");
    ofstream fout("binsearch.out");

    int n, m;

    fin >> n; // n -  кол-во эл-тов в массиве
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) // заполняем массив чисел
        fin >> arr[i];

    fin >> m; // m - кол-во запросов

    int inquiry, first, last;
    for (int i = 0; i < m; i++) {
        fin >> inquiry;
        first = first_occurrence(arr, inquiry) + 1;
        last = last_occurrence(arr, inquiry) + 1;
        fout << first << " " << last << endl;
    }

    fin.close();
    fout.close();

    return 0;
}

