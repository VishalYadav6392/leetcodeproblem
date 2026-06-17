class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int maxP=nums[0];
        int minP=nums[0];
        int n=nums.size();
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            int n1=maxP*nums[i];
            int n2=minP*nums[i];
            int n3=nums[i];
            maxP=max(n3,max(n2,n1));
            minP=min(n3,min(n2,n1));
            ans=max(ans,maxP);
        }
        return ans;
    }
};