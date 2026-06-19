class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int ND=arr[0];
        int OD=INT_MIN;
        int ans=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            int preND=ND;
            int preOD=OD;
            int v2;
            ND=max(arr[i],ND+arr[i]);
            if(preOD==INT_MIN)
            {
                v2=arr[i];
            }
            else v2=preOD+arr[i];
            OD=max(v2,preND);
            ans=max(ans,max(ND,v2));
        }
        return ans;
    }
};