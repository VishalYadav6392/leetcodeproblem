class Solution {
    public int minOperations(String s) {
       int n = s.length();
        boolean sorted = true;
        for (int i = 0; i + 1 < n; i++) {
            if (s.charAt(i) > s.charAt(i + 1)) { sorted = false; break; }
        }
        if (sorted) return 0;
        if (n == 2) return -1;

        char mn = 'z', mx = 'a';
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c < mn) mn = c;
            if (c > mx) mx = c;
        }
        int cntMn = 0, cntMx = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == mn) cntMn++;
            if (s.charAt(i) == mx) cntMx++;
        }

        if (s.charAt(0) == mn || s.charAt(n - 1) == mx) return 1;
        if (s.charAt(0) == mx && s.charAt(n - 1) == mn && cntMn == 1 && cntMx == 1) return 3;
        return 2;
    }
}