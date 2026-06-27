class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Handle 1 separately
        if (freq.count(1)) {
            int cnt = freq[1];
            ans = max(ans, (cnt % 2 == 0) ? cnt - 1 : cnt);
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {
                if (!freq.count(cur))
                    break;

                if (freq[cur] == 1) {
                    len += 1;      // current becomes center
                    break;
                }

                // freq[cur] >= 2
                len += 2;

                long long nxt = cur * cur;

                // next value doesn't exist -> current should be center
                if (!freq.count(nxt)) {
                    len--;
                    break;
                }

                cur = nxt;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};