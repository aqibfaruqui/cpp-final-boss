#include <bits/stdc++.h>

std::pair<int, int> findOne(std::vector<std::vector<int>>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                return {i, j};
            }
        }
    }

    return {};
}

int beautifulMatrix(std::vector<std::vector<int>>& arr) {
    std::pair<int, int> coords = findOne(arr);
    return std::abs(2 - coords.first) + std::abs(2 - coords.second);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::vector<int>> arr;
    int a, b, c, d, e;
    for (int i = 0; i < 5; i++) {
        std::cin >> a >> b >> c >> d >> e;
        arr.push_back({a, b, c, d, e});
    }

    int result = beautifulMatrix(arr);
    std::cout << result << "\n";
    return 0;
}