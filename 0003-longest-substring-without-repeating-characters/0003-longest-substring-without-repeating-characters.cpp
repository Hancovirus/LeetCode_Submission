class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;

        map<int, int> mp;
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            if (mp.find(s[end]) != mp.end() && mp[s[end]] >= start) {
                start = mp[s[end]] + 1;
            }
            
            mp[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};