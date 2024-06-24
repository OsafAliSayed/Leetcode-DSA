class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int maxLen = 0;
        int len = 0;
        int l = 0 , r = 0;
        while (r < s.length()) {
            if (mp.find(s[r]) == mp.end()) {
                mp[s[r]]++;
                len++;
                r++;
            }
            else {
                mp.erase(s[l]);
                l++;
                len--;
            }
            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};