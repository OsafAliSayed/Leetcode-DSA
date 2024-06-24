class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int mp[26];
        for (int i = 0; i < s.length(); i++) {
            mp[s[i] - 'a']++;
            mp[t[i] - 'a']--;
        }
        for (int i = 0 ; i < sizeof(mp) / sizeof(mp[0]); i++) {
            if (mp[i] != 0) {
                return false;
            }
        }
        return true;
    }
};