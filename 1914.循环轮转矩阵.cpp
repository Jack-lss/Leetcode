/*
 * @Author: your name
 * @Date: 2021-10-16 15:34:49
 * @LastEditTime: 2021-10-16 15:46:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \leetcode\1914.循环轮转矩阵.cpp
 */
/*
 * @lc app=leetcode.cn id=1914 lang=cpp
 *
 * [1914] 循环轮转矩阵
 */

// @lc code=start
class Solution {
    vector<int> dir = { 0,-1, 1,0, 0,1, -1,0 } ;
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        int rLL=0,rUL = n-1,cLL = 0, cUL = m-1 ;
        
        while(rLL<=rUL && cLL <= cUL ){
            
            int k2 = k%( (rUL-rLL-1)*2 + 2*(cUL-cLL+1) ) ;
            
            for(int i=0;i<k2;i++)
                move(rLL,rUL,cLL,cUL,grid) ;
            
            rLL++;rUL--;
            cLL++;cUL--;
        }
        
        return grid;
    }

    void move(int rLL,int rUL,int cLL,int cUL,vector<vector<int>>& grid){
       
        int j2 = cUL;
        int i2 = rLL ;
        
        int d = 0 ;
        int prev=-1;
        
        do{
            swap(grid[i2][j2], prev) ; 
            
            int i3 = i2+dir[d],j3 =j2+dir[d+1] ;
            
            if( j3 < cLL || i3 < rLL || j3 > cUL || i3 > rUL )
                d+=2 ;
                    
            i2 = i2+dir[d] ;
            j2 = j2+dir[d+1] ;
            
        }while( (i2 != rLL) || (j2 != cUL ) ) ;
        
        grid[i2][j2] = prev ;
        
    }
};
// @lc code=end

