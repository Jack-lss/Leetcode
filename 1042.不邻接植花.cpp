/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */

// @lc code=start
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> G[N];
        for (int i=0; i<paths.size(); i++){//建立邻接表
            G[paths[i][0]-1].push_back(paths[i][1]-1);
            G[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        vector<int> answer(N,0);//初始化全部未染色
        for(int i=0; i<N; i++){
            set<int> color{1,2,3,4};
            for (int j=0; j<G[i].size(); j++){
                color.erase(answer[G[i][j]]);//把已染过色的去除
            }
            answer[i]=*(color.begin());//染色
        }
        return answer;
    }
};
// @lc code=end

