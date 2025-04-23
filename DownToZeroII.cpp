int downToZero(int n) {
    if (n == 0) return 0;

    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == 0) break;

        if (dist[curr - 1] == -1) {
            dist[curr - 1] = dist[curr] + 1;
            q.push(curr - 1);
        }

        for (int i = 2; i * i <= curr; ++i) {
            if (curr % i == 0) {
                int next = max(i, curr / i);
                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
    }

    return dist[0];
}
