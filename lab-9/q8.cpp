
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Meeting {
    int start, end;
};

int main() {
    int n;
    cout << "Enter number of meetings: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of meetings.\n";
        return 0;
    }

    vector<Meeting> meetings(n);

    cout << "Enter start and end times:\n";

    for (int i = 0; i < n; i++) {
        cin >> meetings[i].start >> meetings[i].end;

        if (meetings[i].start > meetings[i].end) {
            cout << "Invalid meeting interval.\n";
            return 0;
        }
    }

    sort(meetings.begin(), meetings.end(),
         [](const Meeting& a, const Meeting& b) {
             if (a.start != b.start)
                 return a.start < b.start;
             return a.end < b.end;
         });

    priority_queue<int, vector<int>, greater<int>> endTimes;
    int maxRooms = 0;

    for (const Meeting& m : meetings) {
        while (!endTimes.empty() &&
               endTimes.top() <= m.start) {
            endTimes.pop();
        }

        endTimes.push(m.end);

        maxRooms = max(maxRooms, (int)endTimes.size());
    }

    cout << "Minimum number of rooms = " << maxRooms << '\n';
    return 0;
}