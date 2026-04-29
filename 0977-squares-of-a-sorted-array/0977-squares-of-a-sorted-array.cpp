class Solution {
private:
    vector<int> Merge(vector<int>& arr1, vector<int>& arr2)
    {
        int i = arr1.size() - 1; 
        int j = 0;
        vector<int> merged;

        while(i >= 0 && j < arr2.size())
        {
            if(arr1[i] < arr2[j])
                merged.push_back(arr1[i--]);
            else
                merged.push_back(arr2[j++]);
        }

        while(i >= 0)
            merged.push_back(arr1[i--]);

        while(j < arr2.size())
            merged.push_back(arr2[j++]);

        return merged;
    }

public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> arr1, arr2;
        int i = 0, n = nums.size();

        while(i < n && nums[i] < 0)
        {
            arr1.push_back(nums[i]*nums[i]);
            i++;
        }

        while(i < n)
        {
            arr2.push_back(nums[i]*nums[i]);
            i++;
        }

        return Merge(arr1, arr2);
    }
};