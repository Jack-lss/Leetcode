/*
 * @lc app=leetcode.cn id=1665 lang=cpp
 *
 * [1665] 完成所有任务的最少初始能量
 */

// @lc code=start
bool comp(vector<int> &a, vector<int> &b){
    return a[1] - a[0] > b[1] - b[0];
}

class Solution
{
public:
    int minimumEffort(vector<vector<int>> &tasks)
    {
        int actual_sums = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            actual_sums += tasks[i][0];
        }
        int minimum_sums = actual_sums;
        int C = 0;
        sort(tasks.begin(), tasks.end(), comp);
        for (int i = 0; i < tasks.size(); ++i) {
            C = tasks[i][1] - actual_sums;
            minimum_sums = C >= 0 ? minimum_sums + C : minimum_sums;
            actual_sums = (C >= 0 ? actual_sums + C : actual_sums) - tasks[i][0];
        }

        return minimum_sums;
    }
};
// @lc code=end

