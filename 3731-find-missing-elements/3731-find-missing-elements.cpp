class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int min=INT_MAX;
        int max=INT_MIN;
        for (auto it :nums)
        {
            if(it>max)max=it;
            if(it<min)min=it;
        }
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = min; i <= max; i++) {
            if (!st.count(i))
                ans.push_back(i);
        }

        return ans;
        
    }
};