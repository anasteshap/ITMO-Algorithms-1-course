#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int a = 0;
	int b = 0;

	ifstream fin;
	ofstream fout;

	fin.open("aplusb.in");
	fout.open("aplusb.out");

	if (!fin.is_open() || !fout.is_open()) return 1;

	fin >> a >> b;
	fout << a + b;

	fin.close();
	fout.close();

	return 0;
}