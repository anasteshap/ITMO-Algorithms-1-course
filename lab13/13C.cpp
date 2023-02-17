#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix(string& s) {
    vector<int> p(s.size());

    for (int i = 1; i < s.size(); ++i) {
        int j = p[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }

        if (s[i] == s[j]) {
            ++j;
        }
        p[i] = j;
    }
    return p;
}

int main() {

    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    string s;
    cin >> s;

    vector<int> p = prefix(s);
    for (int el : p)
        cout << el << " ";

    return 0;
}