/*
 * @lc app=leetcode.cn id=1054 lang=cpp
 *
 * [1054] 距离相等的条形码
 */

// @lc code=start
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> hashtable;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> maxHeap;
        
        for(auto it=barcodes.begin(); it!=barcodes.end(); ++it){
            hashtable[*it]++;
        }
        for(auto it=hashtable.begin(); it!=hashtable.end(); ++it){
            maxHeap.push({it->second, it->first});
        }
        vector<int> res;
        while(maxHeap.size() >=2){
            auto it1=maxHeap.top();maxHeap.pop();
            auto it2=maxHeap.top();maxHeap.pop();
            res.push_back(it1.second);
            res.push_back(it2.second);
            if(it1.first>1){
                maxHeap.push({it1.first-1, it1.second});
                maxHeap.push({it2.first-1, it2.second});
            }
        }
        res.push_back(maxHeap.top().second);
        return res;
    }
};
// @lc code=end

