class Solution {
public:
    int solve(string s, int index, unordered_map<int, int>& memo) {
        if (index > s.size() || s[index] == '0') {
            return 0;
        }
        if (index == s.size()) {
            return 1;
        }

        if (memo.find(index) != memo.end()) {
            return memo[index];
        }

        int ans = 0;

        if (s[index] == '1' 
        || (s[index] == '2' && s[index + 1] <= '6' && s[index + 1] >= '0')) {
            ans += solve(s, index + 2, memo);
        }
        ans += solve(s, index + 1, memo);

        memo[index] = ans;
        return ans;
    }

    int numDecodings(string s) {
        unordered_map<int, int> memo;
        return solve(s, 0, memo);
    }
};