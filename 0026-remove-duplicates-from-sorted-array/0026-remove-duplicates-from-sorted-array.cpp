class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=i+1;
        int res=1;
        while(j<n)
        {
            while(j<n && nums[j]==nums[j-1]) j++;
            if(j<n)
            {
               nums[i+1]=nums[j];
               i++;
               j++; 
               res++;
            }          
        }
        return res;
    }
};