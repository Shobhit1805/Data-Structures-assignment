#include <iostream>
using namespace std;
void compute_address_3d(int dataTypeSize, int rows, int cols, int depth, bool isRowMajor, int baseAddress, int i, int j, int k) {
    int address;
    if (isRowMajor) {
        address = baseAddress + ((i * cols * depth) + (j * depth) + k) * dataTypeSize;
    } else {
        address = baseAddress + ((k * rows * cols) + (j * rows) + i) * dataTypeSize;
    }

    cout << "The address of the element at (" << i << ", " << j << ", " << k << ") is: " << address << endl;
}

int main() {
    string dataType;
    cout << "Enter the data type (int, char, float, etc.): ";
    cin >> dataType;
    int dataTypeSize;
    if (dataType == "int") {
        dataTypeSize = sizeof(int);
    } else if (dataType == "char") {
        dataTypeSize = sizeof(char);
    } else if (dataType == "float") {
        dataTypeSize = sizeof(float);
    } else if (dataType == "double") {
        dataTypeSize = sizeof(double);
    } else {
        cout << "Unsupported data type!" << endl;
        return 1;
    }

    int rows, cols, depth;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    cout << "Enter the depth (number of layers): ";
    cin >> depth;

   string memoryArrangement;
    cout << "Enter the memory arrangement (ROW or COLUMN): ";
    cin >> memoryArrangement;
    bool isRowMajor = (memoryArrangement == "ROW");

    int baseAddress;
    cout << "Enter the base address of the array: ";
    cin >> baseAddress;

    int i, j, k;
    cout << "Enter the index of the element (i, j, k): ";
    cin >> i >> j >> k;

    compute_address_3d(dataTypeSize, rows, cols, depth, isRowMajor, baseAddress, i, j, k);

    return 0;
}
