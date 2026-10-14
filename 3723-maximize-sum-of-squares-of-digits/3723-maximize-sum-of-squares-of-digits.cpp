class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";
        int q = sum / 9, r = sum % 9;
        string res(q, '9');
        if (r) res += char('0' + r);
        res.append(num - res.size(), '0');
        return res;
    }
};