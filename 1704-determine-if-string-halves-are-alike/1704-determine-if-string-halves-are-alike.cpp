class Solution {
public:
    bool halvesAreAlike(string s) {
        int sum = 0;
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] == 'o' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u' 
            || s[i] == 'O' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'U')
                sum++;
        }
        for (int i = s.size() / 2; i < s.size(); i++) {
            if (s[i] == 'o' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u' 
            || s[i] == 'O' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'U')
                sum--;
        }
        if (!sum)
            return true;
        return false;
    }
};