class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> p(n, 1);
        p[0] = p[1] = 0;
        for (int i = 2; i * i < n; i++) {
            if (p[i]) {
                for (int j = i * i; j < n; j+=i) {
                    p[j] = 0;
                }
            }
        }
        int cnt = 0;
        for(int i = 2;i < n;i++){
            if(p[i]) cnt++;
        }
        return cnt;
    }
};