// find minimum sum of elements in an array of n elements after deleting m contiguous biggest elements
#include <iostream>
#include <vector>
using namespace std;

int minimizeMemory(vector<int> memory, int m) {
    int n = memory.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += memory[i];
    }
    int max = 0;
    for (int i = 0; i < m; i++) {
        max += memory[i];
    }
    int temp = max;
    for (int i = m; i < n; i++) {
        temp = temp - memory[i - m] + memory[i];
        if (temp > max) {
            max = temp;
        }
    }
    return sum - max;
}
int main()
{
    vector<int> memory = {4, 6, 10, 8, 2, 1};
    int m = 3;
    // expected output = 7
    
    cout << minimizeMemory(memory, m) << endl;

    
    return 0;
}