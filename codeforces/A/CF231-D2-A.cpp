#include <bits/stdc++.h>
#include <numeric>

int findProblems(std::vector<std::vector<int>>& arr) {
    int result = 0;
    for (auto& a : arr) {
        if (std::accumulate(a.begin(), a.end(), 0) >= 2) {
            result++;
        }
    }

    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        arr[i] = {x, y, z};
    }

    int result = findProblems(arr);
    std::cout << result << "\n";
    return 0;
}