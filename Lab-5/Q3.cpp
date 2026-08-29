#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Partition function using the last element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Recursive Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of random elements (N): ";
    cin >> n;

    int *arr = new int[n];

    // 1. Generate N random elements and store them in a file
    srand((unsigned int)time(0));
    ofstream outFile("input_data.txt");
    if (!outFile) {
        cout << "Error creating input file." << endl;
        return 1;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;   // random numbers between 0 and 9999
        outFile << arr[i] << " ";
    }
    outFile.close();
    cout << "Generated " << n << " random elements and stored them in 'input_data.txt'." << endl;

    // 2. Read the elements back from the file (demonstrates file-based workflow)
    int *data = new int[n];
    ifstream inFile("input_data.txt");
    if (!inFile) {
        cout << "Error opening input file." << endl;
        return 1;
    }
    for (int i = 0; i < n; i++) inFile >> data[i];
    inFile.close();

    // 3. Sort using Quick Sort
    quickSort(data, 0, n - 1);

    // 4. Write the sorted elements to an output file
    ofstream outSorted("quicksort_output.txt");
    for (int i = 0; i < n; i++) outSorted << data[i] << " ";
    outSorted.close();
    cout << "Sorted elements written to 'quicksort_output.txt'." << endl;

    // 5. Display first few and last few sorted elements as a preview
    int preview = (n < 10) ? n : 10;
    cout << "\nFirst " << preview << " sorted elements: ";
    for (int i = 0; i < preview; i++) cout << data[i] << " ";
    cout << "\nLast " << preview << " sorted elements: ";
    for (int i = n - preview; i < n; i++) cout << data[i] << " ";
    cout << endl;

    delete[] arr;
    delete[] data;
    return 0;
}