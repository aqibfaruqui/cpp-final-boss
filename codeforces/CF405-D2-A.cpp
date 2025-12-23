#include <bits/stdc++.h>

/* 
 * Input
 * {3, 2, 1, 2} 
 *  |
 *  |  |     |
 *  |  |  |  |
 * 
 * Output 
 * {1, 2, 2, 3} 
 *           |
 *     |  |  |
 *  |  |  |  |
 */

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, n;
    std::cin >> n;
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a;
        arr[i] = a;
    }

    std::sort(arr.begin(), arr.end());
    std::string result = "";

    for (auto& r : arr) {
        result += std::to_string(r) + " ";
    }

    result.pop_back();
    std::cout << result << std::endl;

    return 0;
}