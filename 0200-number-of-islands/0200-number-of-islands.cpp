class Solution {
public:

    void dfs(int ux, int uy, vector<vector<char>>& grid) {    
        grid[ux][uy] = '0';
        static vector<int> direction = {0, 1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            int vx = ux + direction[i];
            int vy = uy + direction[i + 1];
            if (vx < 0 || vx >= grid.size() || 
                vy < 0 || vy >= grid[0].size() || 
                grid[vx][vy] == '0') {
                    continue;
                }
            dfs(vx, vy, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // 1. First traverser the matrix if find '1' then start a dfs, and increment count
        // 2. in the dfs, using a direction array find land and traverse the land recursively
        // to find more lands. direction array will do this in 4 directions. 

        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ux = i, uy = j;
                if (grid[ux][uy] == '1') {
                    dfs(ux, uy, grid);
                    count++;
                }
            }
        }

        return count;
    }
};