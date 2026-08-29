#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int low, int high, int pivotindex) {
    int pivot = arr[pivotindex];
    swap(arr[pivotindex], arr[high]); // Move pivot to end
    int i = low; // Index of smaller element

    for (int j = low; j <= high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <pivot) {
            swap(arr[j], arr[i]);
            i++; // increment index of smaller element
            
        }
    }
    swap(arr[i], arr[high]);
    return i;
};
int quickselect(vector<int>& arr, int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivotindex = low + (high - low) / 2; // Choose middle element as pivot
    pivotindex = partition(arr, low, high, pivotindex);

    if (k == pivotindex) {
        return arr[k];
    } else if (k < pivotindex) {
        return quickselect(arr, low, pivotindex - 1, k);
    } else {
        return quickselect(arr, pivotindex + 1, high, k);
    }
};
int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: "; 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    double median;
    if(n%2==1){
    int k=n/2;
    median= quickselect(arr,0,n-1,k);
    }
    else{
        int k1=n/2-1;
        int k2=n/2;
        median=(quickselect(arr,0,n-1,k1)+quickselect(arr,0,n-1,k2))/2.0;
    }
    cout<<"The median is: "<<median<<endl;
    return 0;
}