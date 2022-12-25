// Heap
// 692. Top K Frequent Words

// Given an array of strings words and an integer k, return the k most frequent strings.

// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

// Example 1:

// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> freq;
        for (auto w : words)
        {
            freq[w]++;
        }

        auto comp = [&](const pair<string, int> &a, const pair<string, int> &b)
        {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        // typedef priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(comp)> my_pq_t;

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp); // element, container, comparison

        for (auto w : freq)
        {
            pq.emplace(w.first, w.second);
            if (pq.size() > k)
                pq.pop();
        }

        vector<string> res;
        while (!pq.empty())
        {
            res.insert(res.begin(), pq.top().first);
            pq.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    vector<string> res = s.topKFrequent(words, k);
    for (auto r : res)
    {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}
