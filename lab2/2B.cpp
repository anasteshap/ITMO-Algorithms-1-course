#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct num_of_person 
{
    int num;
    string country;
    string name;
};

void merge(struct num_of_person* arr, int first, int pivot, int last);
void mergeSort(struct num_of_person* arr, int first, int last);

int main()
{
    int n;
    ifstream fin("race.in");
    ofstream fout("race.out");
    
    fin >> n;
    struct num_of_person* people = new struct num_of_person[n];

    for (int i = 0; i < n; ++i) 
    {
        fin >> people[i].country >> people[i].name;
        people[i].num = i;
    }

    mergeSort(people, 0, n);

    string temp = "";
    for (int i = 0; i < n; ++i) 
    {
        if (people[i].country != temp) 
        {
            temp = people[i].country;
            fout << "=== " << people[i].country << " ===\n";
        }
        fout << people[i].name << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}

void merge(struct num_of_person* arr, int first, int mid, int last)
{
    int i = 0, j = 0;
    struct num_of_person* buf = new struct num_of_person[last - first];

    while (first + i < mid && mid + j < last)
    {
        if (arr[first + i].country <= arr[mid + j].country)
        {
            buf[i + j] = arr[first + i];
            i++;
        }
        else
        {
            buf[i + j] = arr[mid + j];
            j++;
        }
    }

    while (first + i < mid)
    {
        buf[i + j] = arr[first + i];
        i++;
    }

    while (mid + j < last)
    {
        buf[i + j] = arr[mid + j];
        j++;
    }

    for (i = 0; first + i < last; i++)
        arr[first + i] = buf[i];
}

void mergeSort(struct num_of_person* arr, int first, int last)
{
    if (first + 1 >= last)
        return;
    int mid = (first + last) / 2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid, last);
    merge(arr, first, mid, last);
}
