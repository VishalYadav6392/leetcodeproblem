class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        string t = "1" + s + "1";

        vector<char> type;
        vector<int> len;

        for (char c : t) {
            if (type.empty() || type.back() != c) {
                type.push_back(c);
                len.push_back(1);
            } else {
                len.back()++;
            }
        }

        int best = 0;

        for (int i = 1; i + 1 < (int)type.size(); i++) {
            if (type[i] == '1' &&
                type[i - 1] == '0' &&
                type[i + 1] == '0') {
                best = max(best, len[i - 1] + len[i + 1]);
            }
        }

        return ones + best;
    }
};