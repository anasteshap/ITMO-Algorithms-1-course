#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> naiveSearch (string& p, string& t) {
    vector<int> answer{};
    for (int i = 0; i < t.size(); ++i) {
        int j = 0;
        for (; j < p.size(); ++j) {
            if (t[i + j] != p[j]) {
                break;
            }
        }
        if (j == p.size()) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}


int main() {

    ifstream fin("search1.in");
    ofstream fout("search1.out");

    string p, t;
    fin >> p >> t;

    vector<int> ans = naiveSearch(p, t);

    fout << ans.size() << '\n';
    for (int el : ans) {
        fout << el << " ";
    }

    return 0;
}
