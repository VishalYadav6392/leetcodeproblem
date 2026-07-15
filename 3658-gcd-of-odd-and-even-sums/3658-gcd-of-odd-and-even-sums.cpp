class Solution {
    int helper(int a,int b)
    {
        if(b==0)return a;
        return helper(b,a%b);
    }
public:
    int gcdOfOddEvenSums(int n) {
        int a=n*(n+1);
        int b=n*n;
        return  helper(a,b);

    }
};