class Solution {
public:
    int GCD(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    int findGCD(vector<int>& nums) {
         int mn = nums[0];
        int mx = nums[0];

        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
        }

        return GCD(mn, mx);
    }
};