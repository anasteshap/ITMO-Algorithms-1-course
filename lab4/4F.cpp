#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> // для setprecision()

using namespace std;

float binary_research(vector<double>& arr, int n, double A)
{
    arr[0] = A;
    double left = 0, right = A;

    while (right - left > 0.00001) {
        arr[1] = (left + right) / 2;  //высота след лампочки
        bool isAbove = true;
        for (int i = 2; i < n; i++) {  // по формуле расчитываем значения для лампочек 3, 4, 5 ...
            arr[i] = 2 * (arr[i - 1] + 1) - arr[i - 2];
            if (arr[i] <= 0) {
                isAbove = false;
                break;
            }
        }

        if (isAbove) {
            right = arr[1];
        }
        else {
            left = arr[1];
        }
    }

    return arr[n - 1];
}

int main()
{
    // двоичный поиск по высоте второй лампочки
    ifstream fin("garland.in");
    ofstream fout("garland.out");

    int n;
    double A;

    fin >> n >> A;
    vector<double> arr(n);

    fout << fixed << setprecision(2) << binary_research(arr, n, A); // двоичая точность

    fin.close();
    fout.close();

    return 0;
}

