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

vector<vector<int>> kmp(int a, string& s) {
    vector<int> pref = prefix(s);
    vector<vector<int>> ans(s.size() + 1, vector<int>(a));
    for (int i = 0; i < s.size() + 1; ++i)
        for (int j = 0; j < a; ++j)
            if (i > 0 && j + 'a' != s[i])
                ans[i][j] = ans[pref[i - 1]][j];
            else
                ans[i][j] = i + (j + 'a' == s[i]);
    return ans;
}


int main() {

    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> get_kmp = kmp(n, s);
    for (auto & vec: get_kmp) {
        for (int j: vec)
            cout << j << " ";
        cout << '\n';
    }

    return 0;
}
