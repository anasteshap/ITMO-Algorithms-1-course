#include <iostream>
#include <vector>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, a, b;
    std::cin >> n >> m;

    std::vector<int> degs(n, 0);
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b;
        degs[a - 1]++;
        degs[b - 1]++;
    }

    for (int deg : degs) {
        std::cout << deg << " ";
    }
    return 0;
}
