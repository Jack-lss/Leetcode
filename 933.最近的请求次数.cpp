/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */

// @lc code=start
class RecentCounter
{
private:
    int Count;
    vector<int> Current;
public:
    RecentCounter(): Count(0)
    {

    }

    int ping(int t)
    {
        Current.push_back(t);
        int start = t - 3000;
        for (auto it = Current.begin(); it != Current.end(); ++it){
            if (*it < start){
                it = Current.erase(it);
                --it;
            }
            else break;
        }
        return Current.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

