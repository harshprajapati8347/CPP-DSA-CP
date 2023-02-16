// 621. Task Scheduler
// Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

// However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

// Return the least number of units of times that the CPU will take to finish all the given tasks.

// Example 1:

// Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
// Output: 16
// Explanation: 
// One possible solution is
// A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A

//! Algorithm: Greedy
// 1. Count the frequency of each task
// 2. Find the most frequent task, say it's A
// 3. Put A in the slot first, then put other tasks in the slot
// 4. If there are more than one task with the same frequency as A, append them after A
// 5. Max(
//      the most frequent task is frequent enough to force some idle slots, 
//      the most frequent task is not frequent enough to force idle slots
//    )

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        // 1. Count the frequency of each task
        int freq[26] = {0};
        for (char c : tasks)
        {
            freq[c - 'A']++;
        }
        sort(freq, freq + 26);
        // 2. Find the most frequent task, say it's A
        int maxFreq = freq[25];
        // 3. Put A in the slot first, then put other tasks in the slot
        int idleSlots = (maxFreq - 1) * n; 
        // 4. If there are more than one task with the same frequency as A, append them after A
        // 5. Max(
        //      the most frequent task is frequent enough to force some idle slots,
        //      the most frequent task is not frequent enough to force idle slots
        //    )
        for (int i = 24; i >= 0; i--)
        {
            idleSlots -= min(maxFreq - 1, freq[i]);
        }
        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};

int main()
{
    Solution s;
    vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int n = 2;
    cout << s.leastInterval(tasks, n) << endl;
    return 0;
}