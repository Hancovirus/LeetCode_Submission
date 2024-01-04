class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber > 0) {
            int num = (columnNumber - 1) % 26;
            ans = char('A' + num) + ans;
            columnNumber = (columnNumber - 1) / 26;
        }
        return ans;
    }
};