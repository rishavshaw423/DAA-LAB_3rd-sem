
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int id;
    double value, weight, lambda, density;
};

int main() {
    int n;
    double W, t;

    cout << "Enter number of items: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of items.\n";
        return 0;
    }

    cout << "Enter capacity and time: ";
    cin >> W >> t;

    if (W < 0 || t < 0) {
        cout << "Invalid capacity or time.\n";
        return 0;
    }

    vector<Item> a(n);

    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;
        cout << "Enter value, weight, decay rate: ";
        cin >> a[i].value >> a[i].weight >> a[i].lambda;

        if (a[i].weight <= 0 || a[i].lambda < 0) {
            cout << "Invalid item data.\n";
            return 0;
        }

        a[i].density =
            a[i].value / a[i].weight - a[i].lambda * t;
    }

    sort(a.begin(), a.end(), [](const Item& x, const Item& y) {
        return x.density > y.density;
    });

    double totalValue = 0;

    cout << fixed << setprecision(2);
    cout << "\nSelected fractions:\n";

    for (const Item& item : a) {
        if (W <= 0 || item.density <= 0)
            break;

        double taken = min(W, item.weight);
        double fraction = taken / item.weight;

        totalValue += taken * item.density;
        W -= taken;

        cout << "Item " << item.id
             << ": fraction = " << fraction
             << ", weight taken = " << taken << '\n';
    }

    cout << "Maximum value = " << totalValue << '\n';
    return 0;
}