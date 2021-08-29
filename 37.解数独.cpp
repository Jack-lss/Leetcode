/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:

    bool lines[9][9];
    bool columns[9][9];
    bool blocks[3][3][9];
    vector<pair<int, int>> emptyMap;
    bool valid;

    void init(vector<vector<char>>& board){
        valid=false;
        memset(lines, false, sizeof(lines));
        memset(columns, false, sizeof(columns));
        memset(blocks, false, sizeof(blocks));
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[i].size(); ++j) {
                if (board[i][j]!='.') {
                    int num=board[i][j]-'0'-1;
                    lines[i][num]=true;
                    columns[j][num]=true;
                    blocks[i/3][j/3][num]=true;
                }else {
                    emptyMap.emplace_back(i,j);
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == emptyMap.size()) {
            valid = true;
            return;
        }

        int i= emptyMap[pos].first;
        int j= emptyMap[pos].second;
        for (int digit = 0; digit < 9 && !valid; ++digit) {
            if (!lines[i][digit] && !columns[j][digit] && !blocks[i / 3][j / 3][digit]) {
                lines[i][digit] = columns[j][digit] = blocks[i / 3][j / 3][digit] = true;
                board[i][j] = digit + '0' + 1;
                dfs(board, pos + 1);
                lines[i][digit] = columns[j][digit] = blocks[i / 3][j / 3][digit] = false;
            }
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        init(board);
        dfs(board, 0);

    }
};
// @lc code=end

