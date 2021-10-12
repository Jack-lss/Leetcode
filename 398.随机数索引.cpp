/*
 * @Author: your name
 * @Date: 2021-10-12 18:55:50
 * @LastEditTime: 2021-10-12 19:01:04
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\398.随机数索引.cpp
 */
/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

// @lc code=start
class Solution
{
private:
    unordered_map<int, vector<int>> m;
public:
    Solution(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]].push_back(i);
    }

    int pick(int target)
    {
        auto picked = m[target];
        int n = picked.size();
        return picked[rand() % n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

