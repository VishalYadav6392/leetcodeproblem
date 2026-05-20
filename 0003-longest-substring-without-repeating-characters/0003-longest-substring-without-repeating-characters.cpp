class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0,right=0;
        int maxlen=0;
        unordered_map<char,int>mp;
        while(right<n)
        {
            
            while( mp.find(s[right])!=mp.end())
            {
                mp.erase(s[left]);
                left++;
            }
            mp[s[right]]++;
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};