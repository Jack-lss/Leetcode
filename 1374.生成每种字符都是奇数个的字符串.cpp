/*
 * @lc app=leetcode.cn id=1374 lang=cpp
 *
 * [1374] 生成每种字符都是奇数个的字符串
 */

// @lc code=start
class Solution
{
public:
    string generateTheString(int n)
    {
        string result(n, 'a');
        if (n % 2 == 0) {
            result.replace(0, 1, "b");
        }
        return result;
    }
};
// @lc code=end

