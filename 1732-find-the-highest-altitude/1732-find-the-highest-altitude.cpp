class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAlt=0;
        int ans=0;
        int n=gain.size();
        for(int i=0;i<n;i++)
        {
            int currAlt=currAlt+gain[i];
            ans=max(ans,currAlt);
        }
        return ans;

        
    }
};