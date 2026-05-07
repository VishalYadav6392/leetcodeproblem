class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a;
        stack<char> b;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '#') {
                if(!a.empty())
                    a.pop();
            }
            else {
                a.push(s[i]);
            }
        }

        for(int i = 0; i < t.size(); i++) {

            if(t[i] == '#') {
                if(!b.empty())
                    b.pop();
            }
            else {
                b.push(t[i]);
            }
        }

        if(a.size() != b.size())
            return false;

        while(!a.empty()) {

            if(a.top() != b.top())
                return false;

            a.pop();
            b.pop();
        }

        return true;
    }
};