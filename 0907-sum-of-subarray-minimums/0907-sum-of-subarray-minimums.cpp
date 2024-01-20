class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> stk;

        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[i] < arr[stk.top()]) {
                stk.pop();
            }

            if (stk.empty()) {
                left[i] = i + 1;
            } else { 
                left[i] = i - stk.top(); 
            }
            stk.push(i);
        }

        while (!stk.empty()) {
            stk.pop();
        }

        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[i] <= arr[stk.top()]) {
                stk.pop();
            }

            if (stk.empty()) {
                right[i] = n - i;
            } else { 
                right[i] = stk.top() - i; 
            }
            stk.push(i);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = (result + static_cast<long long>(arr[i]) * left[i] * right[i]) % MOD;
        }

        return result;
    }
};