class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        
        const long long MOD = 1e9 + 7;
        
        vector<int> pos;
        vector<int> digit;
        
        // Store only non-zero digits and their positions
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }
        
        int n = digit.size();
        
        // prefix number
        vector<long long> preNum(n + 1, 0);
        
        // prefix digit sum
        vector<long long> preSum(n + 1, 0);
        
        // powers of 10
        vector<long long> power10(n + 1, 1);
        
        for (int i = 0; i < n; i++) {
            preNum[i + 1] = (preNum[i] * 10 + digit[i]) % MOD;
            preSum[i + 1] = preSum[i] + digit[i];
            power10[i + 1] = (power10[i] * 10) % MOD;
        }
        
        vector<int> ans;
        
        for (auto &q : queries) {
            
            int l = q[0];
            int r = q[1];
            
            // First non-zero position >= l
            int left = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            
            // First non-zero position > r
            int right = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
            
            if (left == right) {
                ans.push_back(0);
                continue;
            }
            
            int len = right - left;
            
            // Extract concatenated number
            long long x = (
                preNum[right] -
                (preNum[left] * power10[len]) % MOD +
                MOD
            ) % MOD;
            
            // Sum of selected digits
            long long sum = preSum[right] - preSum[left];
            
            ans.push_back((x * sum) % MOD);
        }
        
        return ans;
    }
};