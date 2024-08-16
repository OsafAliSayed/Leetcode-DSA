class Solution {
public:
    string RLE (string s) {
        if (s == "") {
            return "1";
        }
        string ans = "";
        int i = 0;
        int j = 0;
        while (j < s.length()) {
            int count = 0;
            j = i;
            while (s[j] == s[i]) {
                j++;
                count++;
            }

            ans += to_string(count) + s[i];
            i = j;
        }
        return ans;
    }
    
    void solve(string& ans, string s, int i, int n) {
        if (i == n) {
            ans = RLE(s);
            return;
        }
        solve(ans, RLE(s), i + 1, n);
    }
    string countAndSay(int n) {
        string ans = "";
        for (int i = 1; i <= n; i++) {
            ans = RLE(ans);
        }
        return ans;
    }
};