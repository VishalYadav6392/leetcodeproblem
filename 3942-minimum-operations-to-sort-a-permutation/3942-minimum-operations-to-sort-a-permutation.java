class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int ans = Integer.MAX_VALUE;

        // ascending rotation check: nums[i] = (k + i) % n
        int k = nums[0];
        boolean asc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n) {
                asc = false;
                break;
            }
        }
        if (asc) {
            int cost = (k == 0) ? 0 : Math.min(n - k, k + 2);
            ans = Math.min(ans, cost);
        }

        // descending rotation check: nums[i] = (m - i) mod n
        int m = nums[0];
        boolean desc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (((m - i) % n) + n) % n) {
                desc = false;
                break;
            }
        }
        if (desc) {
            int kk = (m + 1) % n;
            int cost = (kk == 0) ? 1 : 1 + Math.min(kk, n - kk);
            ans = Math.min(ans, cost);
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}