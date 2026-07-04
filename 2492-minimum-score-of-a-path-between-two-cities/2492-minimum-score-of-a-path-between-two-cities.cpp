class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];

            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }

        vector<int> visited(n + 1, 0);
        queue<int> q;

        q.push(1);
        visited[1] = 1;

        int ans = INT_MAX;

        while (!q.empty()) {
            int city = q.front();
            q.pop();

            for (auto &[nextCity, dist] : adj[city]) {
                ans = min(ans, dist);

                if (!visited[nextCity]) {
                    visited[nextCity] = 1;
                    q.push(nextCity);
                }
            }
        }

        return ans;
    }
};