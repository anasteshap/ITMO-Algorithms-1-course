#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix(string s) {
    vector<int> pi(s.size());

    for (int i = 1; i < s.size(); ++i) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}


vector<int> kmp(string& p, string& t) {
    vector<int> ans{};
    vector<int> pref = prefix(p + "#" + t);

    for (int i = 0; i < t.size(); ++i)
        if (pref[p.size() + i + 1] == p.size())
            ans.push_back(i - (int)p.size() + 2);
    return ans;
}



int main() {

    freopen("search2.in", "r", stdin);
    freopen("search2.out", "w", stdout);

    string p, t;
    cin >> p >> t;

    vector<int> ans = kmp(p, t);
    cout << ans.size() << '\n';
    for (int el : ans) {
        cout << el << " ";
    }

    return 0;
}
