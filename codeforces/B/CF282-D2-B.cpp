#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a;
    std::vector<int> g;
    
    for (int i = 0; i < n; i++) {
        int ai, gi;
        std::cin >> ai >> gi;
        a.push_back(ai);
        g.push_back(gi);
    }

    long difference = 0;
    std::string result = "";

    for (int i = 0; i < n; i++) {
        if (std::abs(difference - a[i]) <= 500) {
            result.push_back('A');
            difference -= a[i];
        } else if (std::abs(difference + g[i]) <= 500) {
            result.push_back('G');
            difference += g[i];
        } else {
            std::cout << "-1" << "\n";
            return 0;
        }
    }
    
    std::cout << result << "\n";
    return 0;
}