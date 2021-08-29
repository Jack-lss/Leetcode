/*
 * @lc app=leetcode.cn id=1805 lang=cpp
 *
 * [1805] 字符串中不同整数的数目
 */

// @lc code=start
class Solution {
public:
    int numDifferentIntegers(string word) {
        regex reg ("[0-9]+");
        smatch m;
        unordered_set<string> result;

        while (regex_search (word, m, reg)) {
            for (string x:m) {
                for(auto it = x.begin(); it != x.end(); ){
                    if(*it == '0'){
                        x.erase(it);
                        it = x.begin();
                    }
                    else break;
                }
                result.insert (x);
            }
            word = m.suffix().str();
        }

        return result.size();
    }
};
// @lc code=end

