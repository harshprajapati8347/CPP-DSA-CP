// Heap Sort
#include <iostream>
using namespace std;
void heapify(int a[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) // Build heap (rearrange array)
        heapify(a, n, i);                // Heapify root element to get highest element at root
    for (int i = n - 1; i >= 0; i--)     // One by one extract an element from heap
    {
        swap(a[0], a[i]); // Move current root to end
        heapify(a, i, 0); // call max heapify on the reduced heap
    }
}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << " ";
}
int main()
{
    int a[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);
    heapSort(a, n);
    cout << "Sorted array is:";
    printArray(a, n);
}