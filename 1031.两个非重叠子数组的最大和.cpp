/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */

// @lc code=start
class Solution
{
public:
    int maxSumTwoNoOverlap(vector<int> &nums, int L, int M)
    {
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
        int res = nums[L + M - 1], Lmax = nums[L - 1], Mmax = nums[M - 1];
        for (int i = L + M; i < nums.size(); ++i) {
            // 两种方法同时进行
            // Lmax 前移一个
            Lmax = max(Lmax, nums[i - M] - nums[i - L - M]);
            // Mmax 前移一个
            Mmax = max(Mmax, nums[i - L] - nums[i - L - M]);
            res = max(res, max(Lmax + nums[i] - nums[i - M], Mmax + nums[i] - nums[i - L]));
        }
        return res;
    }
};
// @lc code=end

