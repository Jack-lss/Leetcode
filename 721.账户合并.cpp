/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map<string, int> emailToIndex;
        vector<vector<string>> res=accounts;
        vector<bool> isOld;

        for(int index=0; index<accounts.size(); ++index){
            isOld.push_back(false);
            int oldIndex=-1;
            for(int i=1; i<accounts[index].size(); ++i){
                if (!emailToIndex.count(accounts[index][i])) {
                    emailToIndex[accounts[index][i]]=index;
                }
                else {
                    isOld[index]=true;
                    oldIndex=emailToIndex[accounts[index][i]];
                    break;
                }
            }
            for(int i=1; i<accounts[index].size(); ++i){
                if (isOld[index]) {
                    emailToIndex[accounts[index][i]]=oldIndex;
                    if(find(accounts[oldIndex].begin(), accounts[oldIndex].end(), 
                        accounts[index][i]) == accounts[oldIndex].end()){
                        res[oldIndex].push_back(accounts[index][i]);
                    }
                }
            }
        }
        for(int index=0; index<isOld.size(); ++index){
            if (isOld[index]) {
                res.erase(res.begin()+index);
            }
        }
        return res;        
    }
};
// @lc code=end

