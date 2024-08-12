#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            comparisons++;
            swaps++;
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
       
        if (j > 0) {
            comparisons++;
        }
    }

    cout << "After Using insertion sort: " <<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
    cout << "Total comparisons: " << comparisons <<endl;
    cout << "Total swaps: " << swaps <<endl;
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using insertion Sort: " <<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertion_sort(arr, n);
    return 0;
}
