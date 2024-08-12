#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;

    for (int i = n - 1; i >= 0; i--) {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swaps++;
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;
        }
    }

    cout << "After Using bubble sort: " <<endl;
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
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;

    bubble_sort(arr, n);
    return 0;
}
