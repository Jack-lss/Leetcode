/*
 * @lc app=leetcode.cn id=1812 lang=cpp
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
 */

// @lc code=start
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        if (coordinates[0]%2==0) {
            if (coordinates[1]%2==0) {
                return false;
            }else {
                return true;
            }
        }else {
            if (coordinates[1]%2==0) {
                return true;
            }else {
                return false;
            }
        }
    }
};
// @lc code=end

