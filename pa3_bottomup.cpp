class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int rows = grid.size(); //[0,1,2,3,...,rows]
        int cols = grid[0].size(); //[0][0,1,2,3,...,cols]
        int tennineseven = pow(10, 9) +7;
        vector<vector<long>> maxdp(rows, vector< long>(cols));
        vector<vector<long>> mindp(rows, vector< long>(cols));
        maxdp[0][0] = mindp[0][0] = grid[0][0];
        
// initilize first row
        for (int i=1; i < cols; i++) {
            maxdp[0][i] = maxdp[0][i-1] * grid[0][i];
            mindp[0][i] = maxdp[0][i-1] * grid[0][i];
cout << "init: " << maxdp[0][i] <<", " << mindp[0][i] << endl;
        }
        
// initilize first column
        for (int i=1; i < rows; i++) {
            maxdp[i][0] = maxdp[i-1][0] * grid[i][0];
            mindp[i][0] = maxdp[i-1][0] * grid[i][0];
cout << "init: " << maxdp[i][0] <<", " << mindp[i][0] << endl;
        }

        
        
        
        for (int i=1; i < rows; i++) {
            for (int j=1; j < cols; j++) {
// max of (max right or down, min right or down)
                maxdp[i][j] = max(max(maxdp[i-1][j] * grid[i][j], mindp[i-1][j] * grid[i][j]),
                                  max(maxdp[i][j-1] * grid[i][j], mindp[i][j-1] * grid[i][j]));
cout << "max: " << maxdp[i][j] <<", " << mindp[i][j] << endl;
                
// min of (max right or down, min right or down)
                mindp[i][j] = min(min(maxdp[i-1][j] * grid[i][j], mindp[i-1][j] * grid[i][j]),
                                  min(maxdp[i][j-1] * grid[i][j], mindp[i][j-1] * grid[i][j]));
cout << "min: " << maxdp[i][j] <<", " << mindp[i][j] << endl;
            }
        }
        
        
cout << "solution: " << maxdp[rows-1][cols-1] % tennineseven << endl;
// if solution is negative
        if (maxdp[rows-1][cols-1] < 0) {
            return -1;
        }
// if solution is non negative
        else {
            return maxdp[rows-1][cols-1] % tennineseven;
        }
    }
};
