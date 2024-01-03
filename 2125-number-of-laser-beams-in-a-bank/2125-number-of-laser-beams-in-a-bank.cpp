class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int sum = 0;
        int prev = 0;
        for (int i = 0; i < bank[0].size(); i++) {
            if (bank[0][i] == '1') 
                prev++;
        }
        for (int i = 1; i < bank.size(); i++) {
            int curr = 0;
            for (int j = 0; j < bank[i].size(); j++) {
                if (bank[i][j] == '1') 
                    curr++;
            }
            if (curr != 0) {
                sum += curr * prev;
                prev = curr;
            }
        }
        return sum;
    }
};