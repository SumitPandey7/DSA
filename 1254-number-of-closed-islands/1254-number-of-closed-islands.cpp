class Solution {
public:
    bool bfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<bool>>& vis) {
        vis[i][j] = true;

        queue<pair<int, int>> q;
        q.push({i, j});

        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};
        bool flag = true;
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nrow = dx[k] + row;
                int ncol = dy[k] + col;

                if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m) {
                    flag = false;
                } else if (!vis[nrow][ncol] && grid[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 0) {
                    cnt += bfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};