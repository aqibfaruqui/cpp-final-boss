#include <bits/stdc++.h>

int compare(const std::string& s1, const std::string& s2) {
    int n = s1.size();
    
    for (int i = 0; i < n; i++) {
        if (std::tolower(s1[i]) > std::tolower(s2[i])) {
            return 1;
        } else if (std::tolower(s1[i]) < std::tolower(s2[i])) {
            return -1;
        }
    }

    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s1;
    std::string s2;

    std::getline(std::cin, s1);
    std::getline(std::cin, s2);

    int result = compare(s1, s2);

    std::cout << result << std::endl;
    return 0;
}