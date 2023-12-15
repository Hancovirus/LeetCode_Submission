class Solution {
public:
    int mySqrt(int x) {
        if (x == 1 || x == 0) {
            return x;
        }

        int start = 1;
        int end = x;
        long long mid;

        while (start <= end) {
            mid = start + (end - start) / 2;
            long long square = mid * mid;
            if (square > x) {
                end = mid - 1;
            } else if (square < x) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        long long square = mid * mid;
        if (square > x) {
            return mid - 1;
        }
        return mid;
    }
};