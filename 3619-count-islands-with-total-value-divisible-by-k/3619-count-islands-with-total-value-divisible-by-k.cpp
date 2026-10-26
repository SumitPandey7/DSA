class Solution {
public:
    bool bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis,
             int k) {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i,j});
        long long sum = 0;
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, 1, -1, 0};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            sum += grid[row][col];

            for (int p = 0; p < 4; p++) {
                int nr = dx[p] + row;
                int nc = dy[p] + col;
                if (nr >= 0 && nr < n && nc >= 0 &&
                    nc < m && !vis[nr][nc] && grid[nr][nc]>0) {
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }
        }
        return sum % k == 0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    cnt += bfs(i, j, grid, vis, k);
                }
            }
        }
        return cnt;
    }
};