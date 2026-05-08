class Solution {
public:
    bool backspaceCompare(string s, string t) {

        int ind1 = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '#')
            {
                s[ind1] = s[i];
                ind1++;
            }
            else if(ind1 > 0)
            {
                ind1--;
            }
        }

        int ind2 = 0;

        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] != '#')
            {
                t[ind2] = t[i];
                ind2++;
            }
            else if(ind2 > 0)
            {
                ind2--;
            }
        }

        if(ind1 != ind2) return false;

        for(int i = 0; i < ind1; i++)
        {
            if(s[i] != t[i])
                return false;
        }

        return true;
    }
};