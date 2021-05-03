//leetcode 1594
//속도 줄이고 줄여서 겨우 맞췄음
//dfs 말고 다른걸로도 풀 수 있을것같은데 의견공유해주셈 ㅋ

class Solution {
public:
    int mod = pow(10,9) + 7;
    vector<long long> product;
    long long max = -1;
    void dfs(vector<vector<int>>& grid,int i, int j, int row, int column,long long production){
        
         
        production = grid[i][j]*production;
        if(production == 0){
             if(max < production)
                max = production;
            return;
        }
        
        if(i+1 == row && j +1 == column){
            if(max < production)
                max = production;
            return;
        }
        else if(j+1 == column )
         dfs(grid, i+1, j, row, column, production );
        else if(i+1 == row)
            dfs(grid, i, j+1, row, column, production );  
        else{           
            dfs(grid, i, j+1, row, column, production );
            dfs(grid, i+1, j, row, column, production );
        }       
        }
    
    int maxProductPath(vector<vector<int>>& grid) {
        int row  = grid.size(); // 세로
        int column = grid[0].size(); // 가로
        
        dfs(grid, 0 , 0, row, column, 1);
        
        
        max %= mod;
        
        return max;
    }
    
    
    
};