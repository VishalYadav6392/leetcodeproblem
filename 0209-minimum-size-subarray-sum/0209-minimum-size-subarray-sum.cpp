class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right=0;
        int n=nums.size();
        int sum=0;
        int ans=INT_MAX;
        while(right<n)
        {
            sum+=nums[right];
            while(sum >=target)
            {
                ans=min(ans,right-left+1);
                sum-=nums[left];
                left++;
            }
           
            right++;
        }
        return ans==INT_MAX?0:ans;

    }
};