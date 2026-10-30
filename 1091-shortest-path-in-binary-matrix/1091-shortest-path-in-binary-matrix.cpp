class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        q.push({{0,0},1});
        vis[0][0] = 1;
        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            if(r == n-1 && c == n-1){
                return d;
            }

            for(int i = 0;i < 8;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];

                if(nr>=0 && nc >=0 && nr<n &&  nc<n && grid[nr][nc] == 0 && vis[nr][nc] == 0){
                        vis[nr][nc] = 1;
                        q.push({{nr,nc},d+1});
                }
            }
        }
        return -1;
    }
};