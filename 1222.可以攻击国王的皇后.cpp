/*
 * @Author: your name
 * @Date: 2021-10-11 20:29:50
 * @LastEditTime: 2021-10-11 20:42:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\1222.可以攻击国王的皇后.cpp
 */
/*
 * @lc app=leetcode.cn id=1222 lang=cpp
 *
 * [1222] 可以攻击国王的皇后
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
    {
        vector<vector<int>> ans;

        map<pair<int, int>, bool>M;

        for (auto q : queens)
            M[ {q[0], q[1]}] = true;

        int kr = king[0], kc = king[1];

        // top
        for (int r = kr; r >= 0; r--) {
            if (M.find({r, kc}) != M.end()) {
                ans.push_back({r, kc});
                break;
            }
        }

        // down
        for (int r = kr; r < 8; r++) {
            if (M.find({r, kc}) != M.end()) {
                ans.push_back({r, kc});
                break;
            }
        }

        // left
        for (int c = kc; c >= 0; c--) {
            if (M.find({kr, c}) != M.end()) {
                ans.push_back({kr, c});
                break;
            }
        }

        // right
        for (int c = kc; c < 8; c++) {
            if (M.find({kr, c}) != M.end()) {
                ans.push_back({kr, c});
                break;
            }
        }

        // top left
        int c = kc;
        for (int r = kr; r >= 0 and c >= 0; r--) {
            if (M.find({r, c}) != M.end()) {
                ans.push_back({r, c});
                break;
            }
            c--;
        }

        // top right
        for (int r = kr, c = kc; r >= 0 and c < 8; r--, c++) {
            if (M.find({r, c}) != M.end()) {
                ans.push_back({r, c});
                break;
            }
        }

        // bottom left
        for (int r = kr, c = kc; r<8 and c >= 0; r++, c--) {
            if (M.find({r, c}) != M.end()) {
                ans.push_back({r, c});
                break;
            }
        }

        // bottom right
        for (int r = kr, c = kc; r < 8 and c < 8; r++, c++) {
            if (M.find({r, c}) != M.end()) {
                ans.push_back({r, c});
                break;
            }
        }

        return ans;
    }
};
// @lc code=end

