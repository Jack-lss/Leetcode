/*
 * @Author: your name
 * @Date: 2021-10-14 19:22:24
 * @LastEditTime: 2021-10-14 20:52:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\1653.使字符串平衡的最少删除次数.cpp
 */
/*
 * @lc app=leetcode.cn id=1653 lang=cpp
 *
 * [1653] 使字符串平衡的最少删除次数
 */

// @lc code=start
class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> char_stack;
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='b')
                char_stack.push(s[i]);
            else
            {
                if(!char_stack.empty())
                {
                    cnt++;
                    char_stack.pop();
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

