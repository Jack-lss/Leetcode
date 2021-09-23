/*
 * @lc app=leetcode.cn id=1518 lang=cpp
 *
 * [1518] 换酒问题
 */

// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int numdring = numBottles;
        while (numBottles >= numExchange)
        {
            numdring += numBottles / numExchange;
            numBottles = numBottles / numExchange + numBottles % numExchange;
        }
        return numdring;
    }
};
// @lc code=end

