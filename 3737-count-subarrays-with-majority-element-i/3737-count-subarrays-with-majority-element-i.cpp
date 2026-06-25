class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int len=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
             int cnt=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]==target)
                {
                    cnt++;
                }
                len=j-i+1;
                if(2*cnt>len)ans++;

            }
        }
        return ans;
    }
};