class Solution {
     int digitSum(int n)
    {
        int sum=0;
        while(n)
        {
            int d=n%10;
            n=n/10;
            sum+=d*d;
        }
        return sum;

    }
public:
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        while (fast!=1)
        {
            slow=digitSum(slow);
            fast=digitSum(fast);
            fast=digitSum(fast);
            if(slow==fast && slow!=1)
            {
                return false;
            }
        }
        return true;
    }
};