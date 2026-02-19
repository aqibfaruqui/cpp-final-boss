#include <bits/stdc++.h>

int backtrack(int no_questions, int difference, int total) {
    if (no_questions == 0) return difference == total ? 1 : 0;

    return backtrack(no_questions - 1, difference, total - 1) + 
           backtrack(no_questions - 1, difference, total + 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s1, s2;
    std::cin >> s1 >> s2;

    int pos1 = 0.0;
    for (auto &c : s1) {
        if (c == '+') pos1++;
        if (c == '-') pos1--;
    }

    int no_questions = 0;
    int pos2 = 0.0;
    for (auto &c : s2) {
        if (c == '+') pos2++;
        if (c == '-') pos2--;
        if (c == '?') no_questions++;
    }

    int difference = pos1 - pos2;

    /* How many choices of '+' or '-' for {no_questions} add up to {difference}? */

    double result = difference == 0 ? 1.0 : 0.0;

    if (no_questions != 0) {
        int valid = backtrack(no_questions, difference, 0);
        result = valid / std::pow(2.0, no_questions);
    }

    std::cout << std::fixed << std::setprecision(12);
    std::cout << result << "\n";
    return 0;
}