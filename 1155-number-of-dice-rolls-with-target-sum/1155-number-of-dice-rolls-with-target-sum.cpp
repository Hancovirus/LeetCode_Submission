#include <vector>

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1000000007;
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
        return recursion(n, k, target, memo) % MOD;
    }

private:
    int recursion(int n, int k, int target, vector<vector<int>>& memo) {
        const int MOD = 1000000007;
        if (n == 0) {
            return (target == 0) ? 1 : 0;
        }

        if (target <= 0) {
            return 0;
        }

        if (memo[n][target] != -1) {
            return memo[n][target];
        }

        int count = 0;
        for (int i = 1; i <= k; i++) {
            count = (count + recursion(n - 1, k, target - i, memo)) % MOD;
        }

        memo[n][target] = count;
        return count;
    }
};
