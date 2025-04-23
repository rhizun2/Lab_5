int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<tuple<int, int, int>> q;
    q.push({startX, startY, 0});
    visited[startX][startY] = true;

    while (!q.empty()) {
        auto [x, y, moves] = q.front();
        q.pop();

        if (x == goalX && y == goalY) return moves;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            while (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != 'X') {
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny, moves + 1});
                }
                nx += dx[d];
                ny += dy[d];
            }
        }
    }

    return -1;
}
