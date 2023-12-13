class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) {
            return s;
        }

        // Create a 2D DP array to store palindrome information
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        int maxLength = 1;
        int start = 0;

        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                isPalindrome[i][i + 1] = true;
                maxLength = 2;
                start = i;
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                    isPalindrome[i][j] = true;
                    maxLength = len;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};