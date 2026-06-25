class FenwickTree {
    std::vector<int> tree;
public:
    FenwickTree(int size) {
        tree.assign(size + 1, 0);
    }
    void update(int i, int delta) {
        for (; i < tree.size(); i += i & (-i)) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & (-i)) sum += tree[i];
        return sum;
    }
};
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
     int n = nums.size();
        int offset = n + 1;
        FenwickTree bit(2 * n + 2);
        
        long long ans = 0;
        int current_balance = 0;
        
        bit.update(0 + offset, 1);
        
        for (int num : nums) {
            if (num == target) {
                current_balance += 1;
            } else {
                current_balance -= 1;
            }
            
            ans += bit.query(current_balance + offset - 1);
            bit.update(current_balance + offset, 1);
        }
        
        return ans;
  
    }
};