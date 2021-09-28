/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum = duration;
        timeSeries[0] += duration;
        for (int i = 1; i < timeSeries.size(); i++){
            sum += duration - max(0, timeSeries[i - 1] - timeSeries[i]);
            timeSeries[i] += duration;
        }
        return sum;
    }
};
// @lc code=end

