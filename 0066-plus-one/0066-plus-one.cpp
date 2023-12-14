class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        int increase = 1;
        for (int i = n; i >= 0; i--) {
            digits[i] += increase;
            increase--;
            if (digits[i] == 10) {
                digits[i] = 0;
                increase++;
            }
            if (increase == 0) {
                break;
            }
        }
        if (digits[0] == 0) {
            vector<int> temp;
            temp.push_back(1);
            temp.insert(temp.end(), digits.begin(), digits.end());
            return temp;
        }
        return digits;
    }
};