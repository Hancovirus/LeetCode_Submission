class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = -1;
        int len = 0;

        for (int end = 0; end < s.size(); end++) {
            if (s[end] == ' ') {
                if (end - start - 1 != 0) {
                    len = end - start - 1;
                }
                start = end;
            }
        }
        int temp = s.size() - start - 1;
        if (temp > 0) {
            len = temp;
        }
        return len;
    }
};