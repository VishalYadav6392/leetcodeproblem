class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        
        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));
        
        // Starting position
        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                
                if (board[i][j] == 'X' || board[i][j] == 'S')
                    continue;
                
                int best = -1;
                long long count = 0;
                
                // We can arrive here from:
                // down, right, down-right
                int dx[] = {1, 0, 1};
                int dy[] = {0, 1, 1};
                
                for (int k = 0; k < 3; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    
                    if (x >= n || y >= n || score[x][y] == -1)
                        continue;
                    
                    if (score[x][y] > best) {
                        best = score[x][y];
                        count = ways[x][y];
                    }
                    else if (score[x][y] == best) {
                        count = (count + ways[x][y]) % MOD;
                    }
                }
                
                // Cell is unreachable
                if (best == -1)
                    continue;
                
                int value = (board[i][j] == 'E')
                            ? 0
                            : board[i][j] - '0';
                
                score[i][j] = best + value;
                ways[i][j] = count % MOD;
            }
        }
        
        if (score[0][0] == -1)
            return {0, 0};
        
        return {score[0][0], ways[0][0]};
    }
};