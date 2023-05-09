#include <iostream>

using namespace std;

//This function implements heapify functionality
void heapify(int arr[], int size, int root)
{
    int left_child = 2 * root + 1;
    int right_child = 2 * root + 2;
    int largest = root;

    if (left_child < size && arr[left_child] > arr[largest]) {
        largest = left_child;
    }

    if (right_child < size && arr[right_child] > arr[largest]) {
        largest = right_child;
    }

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, size, largest);
    }
}

// This function make a give array a heap and uses heapify function in it
void heapSort(int arr[], int size)
{
    int i = size / 2 - 1;
    while (i >= 0) {
        heapify(arr, size, i);
        i--;
    }

    int j = size - 1;
    while (j >= 0) {
        swap(arr[0], arr[j]);
        heapify(arr, j, 0);
        j--;
    }
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int heap_arr[] = { 4, 17, 3, 12, 9, 6 };
    int n = sizeof(heap_arr) / sizeof(heap_arr[0]);
    cout << "Input array" << endl;
    displayArray(heap_arr, n);

    heapSort(heap_arr, n);

    cout << "Sorted array" << endl;
    displayArray(heap_arr, n);
}
