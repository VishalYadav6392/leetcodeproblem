class Solution {
public:
    long long sumAndMultiply(int n) {
        int num = n;
        long long sum = 0;
        long long place = 1;
        long long newN = 0;

        while (num > 0) {
            int digit = num % 10;
            num = num / 10;

            if (digit == 0)
                continue;

            sum += digit;
            newN += place * digit;
            place *= 10;
        }

        return sum * newN;
    }
};