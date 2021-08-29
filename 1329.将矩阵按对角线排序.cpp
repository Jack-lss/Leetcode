/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 *
 * [1329] 将矩阵按对角线排序
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int m=mat.size()-1;
        int n=0;
        if (!mat.empty()) {
            n=mat[0].size()-1;
        }else {
            return mat;
        }

        int maxLength=m>n?n:m;
        priority_queue<int> priority;
        vector<pair<int, int>> queue;
        int i=m-1;
        int j=0;
        for(;i>=0;--i){
            queue.emplace_back(i,j);
        }
        i=0;j=1;
        for (;j<n;++j) {
            queue.emplace_back(i,j);
        }
        for (;i<queue.size();++i) {
            int c=queue[i].first;
            int k=queue[i].second;
            while (c<=m && k<=n) {
                priority.push(mat[c][k]);
                c++;k++;
            }
            --c;--k;
            while (c>=0 && k>=0) {
                mat[c--][k--]=priority.top();priority.pop();
            }
        }
        return mat;
    }
};
// @lc code=end

