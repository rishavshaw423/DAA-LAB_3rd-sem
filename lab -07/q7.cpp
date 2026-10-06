#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    int year;
    int type;
};

bool compare(Event a, Event b) {

    if (a.year != b.year)
        return a.year < b.year;

    // Death (-1) before birth (+1)
    return a.type < b.type;
}

int main() {

    int n;

    cout << "Enter number of people: ";
    cin >> n;

    vector<Event> events(2 * n);

    for (int i = 0; i < n; i++) {

        int birth, death;

        cout << "Enter birth and death year: ";
        cin >> birth >> death;

        events[2 * i] = {birth, +1};
        events[2 * i + 1] = {death, -1};
    }

    sort(events.begin(), events.end(), compare);

    int alive = 0;
    int maximum = 0;
    int bestYear = 0;

    for (auto event : events) {

        alive += event.type;

        if (alive > maximum) {

            maximum = alive;
            bestYear = event.year;
        }
    }

    cout << "\nBest year = "
         << bestYear << endl;

    cout << "Maximum people alive = "
         << maximum << endl;

    return 0;
}