/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for(int i=0; i<nums.size(); ++i)
        {
            auto it=hashtable.find(target-nums[i]);
            if(it!=hashtable.end())
                return {it->second, i};

            // 先找再去添加，避免找到自己
            hashtable[nums[i]]=i;
        }
        // 找不到就返回空
        return {};
    }
};
// @lc code=end

