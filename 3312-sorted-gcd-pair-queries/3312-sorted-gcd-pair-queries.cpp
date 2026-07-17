class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        // cnt[g] = numbers divisible by g
        vector<long long> cnt(mx + 1, 0);

        for (int g = 1; g <= mx; g++) {
            for (int j = g; j <= mx; j += g)
                cnt[g] += freq[j];
        }

        // exact[g] = number of pairs whose gcd is exactly g
        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long pairs = cnt[g] * (cnt[g] - 1) / 2;

            for (int j = 2 * g; j <= mx; j += g)
                pairs -= exact[j];

            exact[g] = pairs;
        }

        // prefix[g] = pairs with gcd <= g
        vector<long long> prefix(mx + 1, 0);

        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};