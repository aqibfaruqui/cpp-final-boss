#include <bits/stdc++.h>

void printhelper(const std::unordered_map<int, std::unordered_set<int>> &map) {
    for (auto it = map.begin(); it != map.end(); it++) {
        auto _set = it->second;
        std::cout << it->first << ": ";
        for (auto jt = _set.begin(); jt != _set.end(); jt++) {
            std::cout << *jt << ", ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int total_students, total_laces;
    std::cin >> total_students >> total_laces;

    std::unordered_map<int, std::unordered_set<int>> student_connections;

    while (total_laces--) {
        int a, b;
        std::cin >> a >> b;
        student_connections[a].insert(b);
        student_connections[b].insert(a);
    }

    int groups = 0;

    while (1) {
        std::vector<int> to_remove;

        for (auto it = student_connections.begin(); it != student_connections.end(); it++) {
            if (it->second.size() == 1) {
                to_remove.push_back(it->first);
            }
        }

        for (int i = 0; i < (int)to_remove.size(); i++) {
            if (student_connections[to_remove[i]].size() == 0) continue;

            std::unordered_set<int>::iterator it = student_connections[to_remove[i]].begin();
            student_connections[*it].erase(to_remove[i]);
            student_connections[to_remove[i]].clear();
        }

        if (to_remove.size()) {
            groups++;
        } else {
            break;
        }
    }

    std::cout << groups << "\n";
    return 0;
}