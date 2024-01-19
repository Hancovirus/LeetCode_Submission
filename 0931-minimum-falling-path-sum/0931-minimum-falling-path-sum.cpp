class Solution {
private:
    int solution(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& memo) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (memo[row][col] != INT_MAX)
            return memo[row][col];

        if (row == m - 1) {
            memo[row][col] = matrix[row][col];
            return memo[row][col];
        }

        int left = INT_MAX;
        int right = INT_MAX;

        if (col > 0)
            left = solution(matrix, row + 1, col - 1, memo);
        
        if (col < n - 1)
            right = solution(matrix, row + 1, col + 1, memo);

        memo[row][col] = min(solution(matrix, row + 1, col, memo), min(right, left)) + matrix[row][col];

        return memo[row][col];
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> memo(m, vector<int>(n, INT_MAX));
        int ans = INT_MAX;

        for (int i = 0; i < m; i++) {
            ans = min(ans, solution(matrix, 0, i, memo));
        }

        return ans;
    }
};