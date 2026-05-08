class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        int n = nums.size();

        int start = -1, end = -2;

        int maxi = nums[0];
        int mini = nums[n-1];

        for(int i = 1; i < n; i++)
        {
            maxi = max(maxi, nums[i]);

            if(nums[i] < maxi)
                end = i;
        }

        for(int i = n-2; i >= 0; i--)
        {
            mini = min(mini, nums[i]);

            if(nums[i] > mini)
                start = i;
        }

        return end - start + 1;
    }

};