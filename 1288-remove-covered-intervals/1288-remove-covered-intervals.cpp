class Solution {
public:
    bool static Cmp(vector<int>& a,vector<int>& b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0] < b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int rem=0;
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), Cmp);
        int count = 0;
        int maxEnd = -1;

        for (auto &interval : intervals) {

            if (interval[1] > maxEnd) {
                count++;
                maxEnd = interval[1];
            }
        }

        return count;
    }
};