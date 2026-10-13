class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
         int n = nums.size();
        vector<long long> sq(n);
        for (int i = 0; i < n; i++) {
            sq[i] = 1LL * nums[i] * nums[i];
        }
        sort(sq.begin(), sq.end());

        int k = n / 2;  // number of subtracted elements
        long long result = 0;
        for (int i = 0; i < k; i++) result -= sq[i];
        for (int i = k; i < n; i++) result += sq[i];
        return result;
    }
};