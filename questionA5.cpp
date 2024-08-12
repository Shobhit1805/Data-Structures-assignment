#include <iostream>
using namespace std;


void compute_address(int dataTypeSize, int rows, int cols, bool isRowMajor, int baseAddress, int i, int j) {
    int address;
    if (isRowMajor) {
        address = baseAddress + (i * cols + j) * dataTypeSize;
    } else {
        address = baseAddress + (j * rows + i) * dataTypeSize;
    }
    
    cout << "The address of the element at (" << i << ", " << j << ") is: " << address << endl;
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

    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    string memoryArrangement;
    cout << "Enter the memory arrangement (ROW or COLUMN): ";
    cin >> memoryArrangement;
    bool isRowMajor = (memoryArrangement == "ROW");
    int baseAddress;
    cout << "Enter the base address of the array: ";
    cin >> baseAddress;

    
    int i, j;
    cout << "Enter the index of the element (i, j): ";
    cin >> i >> j;
    compute_address(dataTypeSize, rows, cols, isRowMajor, baseAddress, i, j);

    return 0;
}
