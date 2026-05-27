class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        if(n2>n1)return "";
        int minlen=INT_MAX;
        int start=0;
        vector<int>freq(128,0);
        for(auto ch:t)
        {
            freq[ch]++;
        }
        int left=0,right=0;
        int cnt=t.size();
        while(right<n1)
        {
            if(freq[s[right]]>0)cnt--;
            freq[s[right]]--;
            while(cnt==0){
                if(right-left+1<minlen)
                {
                    minlen=right-left+1;
                    start=left;
                }
                freq[s[left]]++;
                if(freq[s[left]]>0)
                {
                    cnt++;
                }
                left++;
            }
            right++;
        }
        return minlen==INT_MAX?"":s.substr(start,minlen);

    }
};