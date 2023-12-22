class Solution {
public:
    int maxScore(string s) {
        int left = 0;
        int right = 0;
        if (s[0] == '0') {
            left++;
        }
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1') {
                right++;
            }
        }
        int max = left + right;
        for (int i = 1; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                right--;
            } else if (s[i] == '0') {
                left++;
            }

            if (left + right > max) {
                max = left + right;
            }
        }
        return max;
    }
};