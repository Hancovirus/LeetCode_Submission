class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            swap(a, b);
        }
        int temp = 0;
        int n = a.size() - 1;
        int m = b.size() - 1;
        while (n >= 0 && m >= 0) {
            if (a[n] == '1' && b[m] == '1') {
                if (temp == 0) {
                    a[n] = '0';
                    temp = 1;
                } else {
                    a[n] = '1';
                }
                n--;
                m--;
            } else if (a[n] == '0' && b[m] == '0') {
                if (temp == 1) {
                    a[n] = '1';
                    temp = 0;
                }
                n--;
                m--;
            } else {
                if (temp == 0) {
                    a[n] = '1';
                } else {
                    a[n] = '0';
                }
                n--;
                m--;
            }
        }
        while (n >= 0 && temp == 1) {
            if (a[n] == '1') {
                a[n] = '0';
            } else {
                a[n] = '1';
                temp = 0;
            }
            n--;
        }
        if (temp == 1) {
            a = "1" + a;
        }
        return a;
    }
};