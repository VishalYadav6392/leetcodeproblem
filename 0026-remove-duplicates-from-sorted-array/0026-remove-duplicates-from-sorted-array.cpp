class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=1;
        if(n==1)return n;
        while(j<n)
        {
            while(j<n && nums[j]==nums[i]  )j++;
           
                i++;
                if(j<n)nums[i]=nums[j];
        }
        return i;
    }
};