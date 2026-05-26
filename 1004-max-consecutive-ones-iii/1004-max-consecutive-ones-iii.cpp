class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0,right=0;
        int cnt0=0;
        int ans=0;
        while(right<n)
        {
            if(nums[right]==0)cnt0++;
            while(cnt0>k)
            {
                if(nums[left]==0)cnt0--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};