class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        double ans = 1;
        if (n < 0) {
            nn = -1 * nn;
        }
        while (nn > 0) {
            if (nn % 2 == 0) {
                nn = nn / 2;
                x = x * x;
            }
            else {
                nn = nn - 1;
                ans = ans * x;
            }
        }
        if (n < 0) {
            ans = 1 / ans;
        }
        return ans;
    }
};