class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        long double base = x;

        if (N < 0) {
            base = 1.0L / base;
            N = -N;
        }

        return power(base, N);
    }

    long double power(long double x, long long n) {
        if (n == 0) {
            return 1.0L;
        }

        long double p = power(x, n / 2);
        long double ans = p * p;

        if (n % 2 == 1) {
            ans *= x;
        }

        return ans;
    }
};