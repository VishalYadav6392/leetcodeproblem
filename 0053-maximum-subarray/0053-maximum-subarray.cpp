class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int BestEnd=nums[0];
        int ans=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            int n1=BestEnd+nums[i];
            int n2=nums[i];
            BestEnd=max(n2,n1);
            ans=max(ans,BestEnd);
        }
        return ans;

        
    }
};