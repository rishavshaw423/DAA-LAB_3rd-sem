
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Station {
    long long distance, fuel;
};

int main() {
    long long D, F;
    int n;

    cout << "Enter target distance, initial fuel, station count: ";
    cin >> D >> F >> n;

    if (D < 0 || F < 0 || n < 0) {
        cout << "Invalid input.\n";
        return 0;
    }

    vector<Station> stations(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter station distance and fuel: ";
        cin >> stations[i].distance >> stations[i].fuel;

        if (stations[i].distance < 0 ||
            stations[i].distance > D || stations[i].fuel < 0) {
            cout << "Invalid station.\n";
            return 0;
        }
    }

    sort(stations.begin(), stations.end(),
         [](const Station& a, const Station& b) {
             return a.distance < b.distance;
         });

    priority_queue<long long> available;
    long long fuel = F, previous = 0;
    int stops = 0;

    for (int i = 0; i <= n; i++) {
        long long position = (i == n)
                           ? D : stations[i].distance;

        fuel -= position - previous;

        while (fuel < 0 && !available.empty()) {
            fuel += available.top();
            available.pop();
            stops++;
        }

        if (fuel < 0) {
            cout << "Target cannot be reached.\n";
            return 0;
        }

        if (i < n)
            available.push(stations[i].fuel);

        previous = position;
    }

    cout << "Minimum refuelling stops = " << stops << '\n';
    return 0;
}