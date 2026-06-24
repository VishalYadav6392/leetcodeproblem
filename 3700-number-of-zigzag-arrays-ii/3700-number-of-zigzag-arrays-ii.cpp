class Solution {
public:
    static const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();

        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        int S = 2 * m;

        vector<long long> init(S, 0);

        // length = 2
        for (int v = 0; v < m; v++) {
            init[v] = v;                  // up[v]
            init[m + v] = m - 1 - v;      // down[v]
        }

        if (n == 2) {
            long long ans = 0;

            for (long long x : init)
                ans = (ans + x) % MOD;

            return ans;
        }

        Matrix T(S, vector<long long>(S, 0));

        for (int v = 0; v < m; v++) {

            // newUp[v] = sum down[x], x < v
            for (int x = 0; x < v; x++)
                T[v][m + x] = 1;

            // newDown[v] = sum up[x], x > v
            for (int x = v + 1; x < m; x++)
                T[m + v][x] = 1;
        }

        Matrix P = power(T, n - 2);

        vector<long long> finalState(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                finalState[i] =
                    (finalState[i] + P[i][j] * init[j]) % MOD;
            }
        }

        long long ans = 0;

        for (long long x : finalState)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};