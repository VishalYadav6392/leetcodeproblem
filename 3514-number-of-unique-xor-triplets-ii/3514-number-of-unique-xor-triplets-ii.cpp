class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<int> present(MAXX, 0);
        for (int x : nums)
            present[x] = 1;

        vector<int> dp(MAXX, 0), ndp(MAXX, 0);
        dp[0] = 1;

        for (int step = 0; step < 3; step++) {
            fill(ndp.begin(), ndp.end(), 0);

            for (int x = 0; x < MAXX; x++) {
                if (!dp[x]) continue;

                for (int v = 0; v < MAXX; v++) {
                    if (present[v])
                        ndp[x ^ v] = 1;
                }
            }

            dp = ndp;
        }

        int ans = 0;
        for (int x = 0; x < MAXX; x++)
            if (dp[x]) ans++;

        return ans;
    }
};