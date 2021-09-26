/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss;
        ss << path;
        string readcache;
        vector<string> filename;
        while( getline(ss,readcache,'/') ){
            if( readcache == "" ){
                continue;
            }
            else if( readcache == "." ){
                continue;
            }
            else if( readcache == ".." ){
                if( filename.size() > 0 )
                    filename.pop_back();
            }
            else{
                filename.push_back(readcache);
            }
        }

        string ans="";

        for(int i=0 ; i < filename.size() ; i++ ){
            ans.append("/" + filename[i] );
        }
        if( ans == "" ){
            return "/";
        }
        return ans;
    }
};
// @lc code=end

