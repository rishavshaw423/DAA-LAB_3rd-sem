#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 * COMPLEXITY ANALYSIS OF HEAP SORT
 * ---------------------------------
 * Heap Sort works in two phases:
 *
 * 1. Build Max Heap phase:
 *    - We call heapify() on every non-leaf node, starting from the last
 *      non-leaf node (n/2 - 1) up to the root (index 0).
 *    - Although each call to heapify() can take O(log n) in the worst case,
 *      a tighter analysis (accounting for the fact that most nodes are near
 *      the bottom of the tree, where heapify does very little work) shows
 *      that building the entire heap takes O(n) time overall, not O(n log n).
 *
 * 2. Extract-Max / Sorting phase:
 *    - We repeatedly swap the root (maximum element) with the last element
 *      of the heap, reduce the heap size by 1, and call heapify() on the
 *      new root to restore the heap property.
 *    - This is done (n - 1) times, and each heapify() call takes O(log n).
 *    - So this phase takes O(n log n).
 *
 * Overall Time Complexity:
 *    - Build heap:      O(n)
 *    - Heapify n times: O(n log n)
 *    - TOTAL:           O(n log n)   -- for Best, Average, AND Worst case.
 *      (Unlike Quick Sort, Heap Sort has NO O(n^2) worst case, because the
 *       heap structure is always balanced.)
 *
 * Space Complexity:
 *    - O(1) extra space (in-place sorting) if we ignore the recursion stack
 *      used by heapify (which is O(log n) due to recursion depth, or O(1)
 *      if implemented iteratively).
 *
 * Heap Sort is NOT a stable sort (equal elements may not retain their
 * original relative order), and it is not adaptive (does not perform
 * better on nearly-sorted input, unlike Insertion Sort).
 */

// Heapify a subtree rooted at index i, where n is the size of the heap
void heapify(int arr[], int n, int i) {
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and recursively heapify the affected subtree
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main Heap Sort function
void heapSort(int arr[], int n) {
    // Build max heap (rearrange array) -- O(n)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract elements from the heap -- O(n log n)
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   // Move current root (max) to the end
        heapify(arr, i, 0);     // Call heapify on the reduced heap
    }
}

int main() {
    int n;
    cout << "Enter number of random elements (N): ";
    cin >> n;

    int *arr = new int[n];

    // 1. Generate N random elements and store them in a file
    srand((unsigned int)time(0));
    ofstream outFile("heap_input_data.txt");
    if (!outFile) {
        cout << "Error creating input file." << endl;
        return 1;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;   // random numbers between 0 and 9999
        outFile << arr[i] << " ";
    }
    outFile.close();
    cout << "Generated " << n << " random elements and stored them in 'heap_input_data.txt'." << endl;

    // 2. Read the elements back from the file
    int *data = new int[n];
    ifstream inFile("heap_input_data.txt");
    if (!inFile) {
        cout << "Error opening input file." << endl;
        return 1;
    }
    for (int i = 0; i < n; i++) inFile >> data[i];
    inFile.close();

    // 3. Sort using Heap Sort
    heapSort(data, n);

    // 4. Write the sorted elements to an output file
    ofstream outSorted("heapsort_output.txt");
    for (int i = 0; i < n; i++) outSorted << data[i] << " ";
    outSorted.close();
    cout << "Sorted elements written to 'heapsort_output.txt'." << endl;

    // 5. Display first few and last few sorted elements as a preview
    int preview = (n < 10) ? n : 10;
    cout << "\nFirst " << preview << " sorted elements: ";
    for (int i = 0; i < preview; i++) cout << data[i] << " ";
    cout << "\nLast " << preview << " sorted elements: ";
    for (int i = n - preview; i < n; i++) cout << data[i] << " ";
    cout << endl;

    cout << "\nTime Complexity of Heap Sort: O(n log n) in best, average, and worst case." << endl;
    cout << "Space Complexity: O(1) auxiliary (in-place)." << endl;

    delete[] arr;
    delete[] data;
    return 0;
}