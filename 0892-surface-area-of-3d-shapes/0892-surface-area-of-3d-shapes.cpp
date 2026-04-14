class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalArea = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int height = grid[i][j];
                
                if (height > 0) {
                    totalArea += (4 * height) + 2;
                    if (j > 0) {
                        totalArea -= 2 * min(height, grid[i][j - 1]);
                    }
                    if (i > 0) {
                        totalArea -= 2 * min(height, grid[i - 1][j]);
                    }
                }
            }
        }
        
        return totalArea;
    }
};