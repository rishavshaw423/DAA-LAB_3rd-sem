
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int overlapLength(const string& a, const string& b) {
    int limit = min(a.size(), b.size());

    for (int len = limit; len > 0; len--) {
        if (a.compare(a.size() - len, len, b, 0, len) == 0)
            return len;
    }

    return 0;
}

string mergeStrings(const string& a, const string& b) {
    int overlap = overlapLength(a, b);
    return a + b.substr(overlap);
}

int main() {
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of strings.\n";
        return 0;
    }

    vector<string> s(n);

    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++)
        cin >> s[i];

    // Remove strings already contained in another input string.
    vector<bool> removed(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && s[j].find(s[i]) != string::npos) {
                if (s[j].size() > s[i].size() || j < i) {
                    removed[i] = true;
                    break;
                }
            }
        }
    }

    vector<string> current;
    for (int i = 0; i < n; i++) {
        if (!removed[i])
            current.push_back(s[i]);
    }

    while (current.size() > 1) {
        int bestI = 0, bestJ = 1;
        int bestOverlap = -1;

        for (int i = 0; i < (int)current.size(); i++) {
            for (int j = 0; j < (int)current.size(); j++) {
                if (i == j)
                    continue;

                int overlap = overlapLength(current[i], current[j]);

                if (overlap > bestOverlap) {
                    bestOverlap = overlap;
                    bestI = i;
                    bestJ = j;
                }
            }
        }

        string merged = mergeStrings(
            current[bestI], current[bestJ]
        );

        cout << "Merge \"" << current[bestI]
             << "\" and \"" << current[bestJ]
             << "\" -> \"" << merged << "\"\n";

        vector<string> next;

        for (int i = 0; i < (int)current.size(); i++) {
            if (i != bestI && i != bestJ)
                next.push_back(current[i]);
        }

        next.push_back(merged);
        current = next;
    }

    cout << "Greedy superstring = " << current[0] << '\n';
    cout << "Length = " << current[0].size() << '\n';

    return 0;
}