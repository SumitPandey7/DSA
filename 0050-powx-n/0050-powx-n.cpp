class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }

        return power(x, N);
    }

    double power(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }

        double p = power(x, n / 2);
        double ans = p * p;

        if (n % 2 == 1) {
            ans *= x;
        }

        return ans;
    }
};