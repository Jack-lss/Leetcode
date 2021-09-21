/*
 * @lc app=leetcode.cn id=913 lang=cpp
 *
 * [913] 猫和老鼠
 *
 * https://leetcode-cn.com/problems/cat-and-mouse/description/
 *
 * algorithms
 * Hard (40.23%)
 * Likes:    96
 * Dislikes: 0
 * Total Accepted:    1.8K
 * Total Submissions: 4.5K
 * Testcase Example:  '[[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]'
 *
 * 两个玩家分别扮演猫（Cat）和老鼠（Mouse）在无向图上进行游戏，他们轮流行动。
 *
 * 该图按下述规则给出：graph[a] 是所有结点 b 的列表，使得 ab 是图的一条边。
 *
 * 老鼠从结点 1 开始并率先出发，猫从结点 2 开始且随后出发，在结点 0 处有一个洞。
 *
 * 在每个玩家的回合中，他们必须沿着与他们所在位置相吻合的图的一条边移动。例如，如果老鼠位于结点 1，那么它只能移动到 graph[1]
 * 中的（任何）结点去。
 *
 * 此外，猫无法移动到洞（结点 0）里。
 *
 * 然后，游戏在出现以下三种情形之一时结束：
 *
 *
 * 如果猫和老鼠占据相同的结点，猫获胜。
 * 如果老鼠躲入洞里，老鼠获胜。
 * 如果某一位置重复出现（即，玩家们的位置和移动顺序都与上一个回合相同），游戏平局。
 *
 *
 * 给定 graph，并假设两个玩家都以最佳状态参与游戏，如果老鼠获胜，则返回 1；如果猫获胜，则返回 2；如果平局，则返回 0。
 *
 *
 *
 *
 *
 *
 * 示例：
 *
 * 输入：[[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
 * 输出：0
 * 解释：
 * 4---3---1
 * |   |
 * 2---5
 * \ /
 * 0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= graph.length <= 200
 * 保证 graph[1] 非空。
 * 保证 graph[2] 包含非零元素。
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int catMouseGame(vector<vector<int>> &graph)
    {
        enum {
            DRAW = 0, MOUSE, CAT, MAX
        };
        int n = graph.size();
        // 6个点，6x6x3种状态
        vector<vector<vector<int>>> degree(n, vector(n, vector(MAX, 0)));
        vector<vector<vector<int>>> color(n, vector(n, vector(MAX, 0)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                degree[i][j][1] = graph[i].size();
                degree[i][j][2] = graph[j].size();
                for (int k : graph[j]) {
                    if (k == 0) {
                        degree[i][j][2]--;
                        break;
                    }
                }
            }
        }
        queue<tuple<int, int, int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int t = 1; t <= 2; t++) {
                color[0][i][t] = MOUSE;
                q.emplace(0, i, t, MOUSE);
                color[i][i][t] = CAT;
                q.emplace(i, i, t, CAT);
            }
        }
        auto parents = [&](int m, int c, int t) {
            vector<tuple<int, int, int>> res;
            if (t == 2) {
                for (auto m1 : graph[m]) {
                    res.emplace_back(m1, c, 3 - t);
                }
                return res;
            } else {
                for (auto c1 : graph[c]) {
                    if (c1 != 0) {
                        res.emplace_back(m, c1, 3 - t);
                    }
                }
                return res;
            }
        };
        while (!q.empty()) {
            auto [i, j, t, c] = q.front();
            q.pop();
            for (auto parent : parents(i, j, t)) {
                auto [i1, j1, t1] = parent;
                if (color[i1][j1][t1] == DRAW) {
                    if (t1 == c) {
                        color[i1][j1][t1] = c;
                        q.emplace(i1, j1, t1, c);
                    } else {
                        degree[i1][j1][t1]--;
                        if (degree[i1][j1][t1] == 0) {
                            color[i1][j1][t1] = c;
                            q.emplace(i1, j1, t1, c);
                        }
                    }
                }

            }
        }
        return color[1][2][1];

    }
};
// @lc code=end

