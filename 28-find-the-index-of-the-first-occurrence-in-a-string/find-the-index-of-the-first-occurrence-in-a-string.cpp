class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.length(); i++) {
            if (needle.length() > haystack.length() - i) {
                return -1;
            }
            if (needle[0] == haystack[i]) {
                int j = 0;
                while (j < needle.length()) {
                    if (needle[j] == haystack[i]) {
                        i++;
                        j++;
                    }
                    else {
                        i = i - j;
                        j = 0;
                        break;
                    }
                }
                if (j == needle.length()) {
                    return i - j;
                }
            }
        }
        return -1;
    }
};