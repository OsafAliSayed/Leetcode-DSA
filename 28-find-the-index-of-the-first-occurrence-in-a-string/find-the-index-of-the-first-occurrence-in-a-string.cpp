class Solution {
public:
    // Z Function implementation
    vector<int> zMatch(string s) {
        vector<int> z(s.size(), 0);
        int l = 0, r = 0;
        for (int i = 1; i < s.size(); i++) {
            if (i < r) {
                z[i] = z[i - l];

                if (i + z[i] > r) {
                    z[i] = r - i;
                }
            }
    
            while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) z[i]++;

            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    int strStr(string haystack, string needle) {
        string temp = needle + "$" + haystack;
        vector<int> z = zMatch(temp);
        for (auto itr: z) {
            cout << itr << " ";
        }
        for (int i = needle.length() + 1; i < z.size(); i++) {
            if (z[i] == needle.length()) return i - needle.length() - 1;
        }
        return -1;
    }
};