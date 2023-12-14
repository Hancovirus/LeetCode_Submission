class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> diff(n, vector<int>(m, 0));
        vector<int> onesRow(m, 0);
        vector<int> onesCol(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    onesRow[j]++;
                    onesCol[i]++;
                } else {
                    onesRow[j]--;
                    onesCol[i]--;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                diff[i][j] = onesRow[j] + onesCol[i];
            }
        }

        return diff;
    }
};