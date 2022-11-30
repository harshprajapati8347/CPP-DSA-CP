// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction.If you cannot achieve any profit, return 0.

// Input : prices = [ 7, 1, 5, 3, 6, 4 ]
// Output : 5
// Explanation : Buy on day 2(price = 1) and sell on day 5(price = 6), profit = 6 - 1 = 5. Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) // [7,1,5,3,6,4]
        {
            if (prices[i] < minPrice) // 7<INT_MAX, 1<7, 5<1, 3<1, 6<1, 4<1
            {
                minPrice = prices[i]; // 7, 1
            }
            else if (prices[i] - minPrice > maxProfit) // 5-1>0, 3-1>0, 6-1>5, 4-1>5
            {
                maxProfit = prices[i] - minPrice; // 4, 5, 5
            }
        }
        return maxProfit; // 5
    }
};

int main()
{
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices);

    return 0;
}