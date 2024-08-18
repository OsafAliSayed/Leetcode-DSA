class Solution {
public:
    vector<int> generateLPS(string s) {
        vector<int> lps(s.size(), 0);
        int len = 0;
        int i = 1;
        while (i < s.size()) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    i++;
                }
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        vector<int> lps = generateLPS(needle);
        int i = 0; //iterator for haystack
        int j = 0; //iterator for needle

        // iterate only if the remaining portion of haystack is greater than the remaining portion of needle
        while (haystack.length() - i >= needle.length() - j) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == needle.length()) {
                return i - j;
            }

            else if (i < haystack.length() && haystack[i] != needle[j]) {
                // go to previous unmatch value if j != 0
                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }
        return -1;

        for (auto it: lps) {
            cout << it << " ";
        }
        return -1;
    }
};