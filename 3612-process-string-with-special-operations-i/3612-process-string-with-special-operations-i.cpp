class Solution {
private:
   void Reverse(string &s)
   {
        int n=s.size();
        int i=0,j=n-1;
        while(i<=j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
   }
public:
    string processStr(string s) {
        string res="";
        int i=0;
        int n=s.size();
        while(i<n)
        {
            if(s[i]=='#')
            {
                res=res+res;
            }
            else if(s[i]=='*')
            {
               res = res.substr(0, res.size() - 1);
            }
            else if(s[i]=='%')Reverse(res);
            else res+=s[i];
            i++;
        }
        return res;
        
    }
};