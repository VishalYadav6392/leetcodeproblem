class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr=(hour==12?0:30*hour)+0.5*minutes;
        double mn=6*minutes;
        double ans=abs(hr-mn);
        return min(ans, 360 - ans);
        
    }
};