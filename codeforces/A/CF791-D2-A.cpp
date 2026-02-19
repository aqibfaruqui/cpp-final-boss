#include <bits/stdc++.h>

int findYears(int a, int b) {
    int years = 0;

    while (a <= b) {
        a *= 3;
        b *= 2;
        years++;
    }

    return years;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    std::cin >> a >> b;

    int result = findYears(a, b);

    std::cout << result << std::endl;
    return 0;
}
