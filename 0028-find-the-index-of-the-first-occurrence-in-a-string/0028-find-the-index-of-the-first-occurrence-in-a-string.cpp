class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        bool found = true;
        for (int i = 0; i < n - m + 1; i++) {
            if (haystack[i] == needle[0]) {
                for (int j = 1; j < m; j++) {
                    if (haystack[i + j] != needle[j]) {
                        found = false;
                        break;
                    }
                }
                if (!found) {
                    found = true;
                } else {
                    return i;
                }
            }
        }
        return -1;
    }
};