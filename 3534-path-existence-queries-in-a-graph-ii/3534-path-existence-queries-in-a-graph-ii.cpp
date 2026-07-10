class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {
        vector<pair<int, int>> nodes;

        // {value, original index}
        for (int i = 0; i < n; i++) {
            nodes.push_back({nums[i], i});
        }

        sort(nodes.begin(), nodes.end());

        vector<int> values(n);
        vector<int> pos(n);

        // values = sorted nums
        // pos[original index] = position in sorted array
        for (int i = 0; i < n; i++) {
            values[i] = nodes[i].first;
            pos[nodes[i].second] = i;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        vector<vector<int>> up(LOG, vector<int>(n));

        // up[0][i] = farthest node reachable
        // from i using exactly one edge
        for (int i = 0; i < n; i++) {
            int limit = values[i] + maxDiff;

            int j = upper_bound(
                values.begin(),
                values.end(),
                limit
            ) - values.begin() - 1;

            up[0][i] = j;
        }

        // Binary lifting
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto& query : queries) {
            int left = pos[query[0]];
            int right = pos[query[1]];

            if (left > right) {
                swap(left, right);
            }

            if (left == right) {
                ans.push_back(0);
                continue;
            }

            int current = left;
            int distance = 0;

            // Make the largest possible jumps
            // while still staying before right
            for (int k = LOG - 1; k >= 0; k--) {
                int next = up[k][current];

                if (next < right && next > current) {
                    current = next;
                    distance += (1 << k);
                }
            }

            // One final edge should reach right
            if (up[0][current] >= right) {
                ans.push_back(distance + 1);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};