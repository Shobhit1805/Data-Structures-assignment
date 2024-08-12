#include<iostream>

using namespace std;

void selection_sort(int arr[], int n) {
    int comparisons = 0; 
    int swaps = 0; 

    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        if (mini != i) {
            swaps++;
            int temp = arr[mini];
            arr[mini] = arr[i];
            arr[i] = temp;
        }
    }

    cout << "After selection sort: " <<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
    cout << "Total comparisons: "<< comparisons <<endl;
    cout << "Total swaps: "<< swaps <<endl;
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout <<"Before selection sort: "<<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;

    selection_sort(arr, n);

    return 0;
}
