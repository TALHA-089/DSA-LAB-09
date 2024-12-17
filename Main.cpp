#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

// Function Declarations
void binaryInsertionSort(int arr[], int n);
int binarySearch(int arr[], int low, int high, int key);
void generateRandomArray(int arr[], int n);
void printArray(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
chrono::duration<double> measureSortTime(void (*sortFunction)(int[], int), int arr[], int n);

// Main Function
int main() {
    int ARRAY_SIZE = 10000;
    srand(static_cast<unsigned int>(time(0)));

    int * randomArray = new int[ARRAY_SIZE];
    generateRandomArray(randomArray, ARRAY_SIZE);

    chrono::duration<double> binarySortTime = measureSortTime(binaryInsertionSort, randomArray, ARRAY_SIZE);
    chrono::duration<double> bubbleSortTime = measureSortTime(bubbleSort, randomArray, ARRAY_SIZE);
    chrono::duration<double> selectionSortTime = measureSortTime(selectionSort, randomArray, ARRAY_SIZE);

    cout << "Sorting Algorithm Comparison\n";
    cout << "------------------------------------------\n";
    cout << "Algorithm        | Time Complexity   | Time Taken (s)\n";
    cout << "------------------------------------------\n";
    cout << "Binary Sort      | O(n log n)        | " << binarySortTime.count() << "\n";
    cout << "Bubble Sort      | O(n^2)            | " << bubbleSortTime.count() << "\n";
    cout << "Selection Sort   | O(n^2)            | " << selectionSortTime.count() << "\n";

    delete[] randomArray;
    return 0;
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the index of the minimum element in the unsorted part
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Update the index of the minimum element
            }
        }

        // Swap the found minimum element with the first unsorted element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Function to generate a random array of size n
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

// Function to perform binary search to find the position
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid + 1;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;  // Return the correct position
}


// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to perform Binary Insertion Sort
void binaryInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        // Use binary search to find the position where key should be inserted
        int pos = binarySearch(arr, 0, i - 1, key);

        // Shift elements to the right to make space for the key
        for (int j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }

        // Insert the key at the found position
        arr[pos] = key;
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to measure execution time of a sorting algorithm
chrono::duration<double> measureSortTime(void (*sortFunction)(int[], int), int arr[], int n) {
    int* temp = new int[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    sortFunction(temp, n);
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    delete[] temp;
    return end - start;
}
