
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <array>
using namespace std;

struct Character {
    int count;
    char ch;
};

struct Compare {
    bool operator()(const Character& a,
                    const Character& b) const {
        if (a.count != b.count)
            return a.count < b.count;
        return a.ch > b.ch;
    }
};

string reorganize(string s, int k) {
    if (k <= 1)
        return s;

    array<int, 256> freq{};
    for (unsigned char ch : s)
        freq[ch]++;

    priority_queue<Character, vector<Character>, Compare> pq;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0)
            pq.push({freq[i], (char)i});
    }

    // Stores character, remaining count, release position
    queue<array<int, 3>> cooldown;
    string result;

    for (int pos = 0; pos < (int)s.size(); pos++) {
        while (!cooldown.empty() &&
               cooldown.front()[2] <= pos) {
            auto item = cooldown.front();
            cooldown.pop();
            pq.push({item[1], (char)item[0]});
        }

        if (pq.empty())
            return "";

        Character current = pq.top();
        pq.pop();

        result += current.ch;
        current.count--;

        if (current.count > 0) {
            cooldown.push({
                (unsigned char)current.ch,
                current.count,
                pos + k
            });
        }
    }

    return result;
}

int main() {
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter K: ";
    cin >> k;

    if (k < 0) {
        cout << "K must be non-negative.\n";
        return 0;
    }

    string answer = reorganize(s, k);

    if (answer.empty() && !s.empty())
        cout << "No valid arrangement exists.\n";
    else
        cout << "Reorganized string = " << answer << '\n';

    return 0;
}