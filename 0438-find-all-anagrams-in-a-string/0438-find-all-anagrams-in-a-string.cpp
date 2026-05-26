class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        int n1=s1.size();
        int n2=s2.size();
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        vector<int>ans;
       if(n1>n2)return ans;
        for(auto ch :s1)
        {
            freq1[ch-'a']++;
        }
        int right=0,left=0;
        while(right<n1)
        {
            freq2[s2[right]-'a']++;
            right++;
        }
        while(right<n2)
        {
            if(freq1==freq2){
                ans.push_back(left);
            }
            freq2[s2[left]-'a']--;
            left++;
            freq2[s2[right]-'a']++;
            right++;
        }
        if(freq1==freq2) ans.push_back(left);
        return ans;

    }
};