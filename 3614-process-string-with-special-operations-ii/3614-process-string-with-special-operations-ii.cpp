class Solution {
public:
    char processStr(string s, long long k) {

        int n = s.size();

        vector<long long> len(n + 1, 0);

        for (int i = 0; i < n; i++) {

            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                len[i + 1] = len[i] + 1;
            }
            else if (ch == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (ch == '#') {
                len[i + 1] = len[i] * 2;
            }
            else { // %
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n]) return '.';

        for (int i = n - 1; i >= 0; i--) {

            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {

                if (k == len[i])
                    return ch;
            }
            else if (ch == '#') {

                if (len[i] > 0)
                    k %= len[i];
            }
            else if (ch == '%') {

                if (len[i] > 0)
                    k = len[i] - 1 - k;
            }
            else { // '*'

                // nothing to do
            }
        }

        return '.';
    }
};