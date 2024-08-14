class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        string prefix = "";

        while (true) {
            if (strs[0].length() == 0) {
                return "";
            }
            char c = strs[0][i];
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j].length() == 0) {
                    return "";
                } 
                if (i >= strs[j].length() || c != strs[j][i]) {
                    return prefix;
                }
            }
            prefix = prefix + c;
            i++;
        }
        return prefix;
    }
};