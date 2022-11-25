// input : 1, 3, 2, 4, 5
// output : 2
// The net price change can be calculated as:
// • Month 1 : [1] and [ 3, 2, 4, 5 ], their respective averages, rounded down = 1 and 3, net price change = 2
// • Month 2 : [ 1, 3 ] and [ 2, 4, 5 ], averages = 2 and 3,
//                                                                        net price change = 1
// • Month 3 : [ 1, 3, 2 ] and [ 4, 5 ], averages = 2 and 4,
//                                                                        net price change = 2
// • Month 4 : [ 1, 3, 2, 4 ] and averages = 2 and 5,
//    net price change = 3 The minimum net price change is 1, and it occurs at month 2.
// return the earliest month with the minimum net price change.
#include <iostream>
#include <vector>
using namespace std;

int findEarliestMonth(vector<int> stockPrice){
    int n = stockPrice.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += stockPrice[i];
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        max += stockPrice[i];
    }
    int temp = max;
    for (int i = n; i < n; i++) {
        temp = temp - stockPrice[i - n] + stockPrice[i];
        if (temp > max) {
            max = temp;
        }
    }
    return sum - max;
}

int main()
{
    vector<int> stockPrice = {1, 3, 2, 4, 5};
    // expected output = 1
    cout << findEarliestMonth(stockPrice) << endl;
    
    return 0;
}