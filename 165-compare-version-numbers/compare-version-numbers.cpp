class Solution {
public:
    int getVersion(string& version) {
        int val = 0;
        if (version.length() != 0) {
            int i = 0;
            while (i < version.length() && version[i] != '.') {
                i++;
            }
            val = stoi(version.substr(0, i));
            if (i != version.length()) {
                version = version.substr(i + 1);
            }
            else {
                version = "";
            }
        }
        return val;
    }
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        while (true) {
            int val1 = getVersion(version1);
            int val2 = getVersion(version2);
            
            if (val1 < val2) {
                return -1;
            }
            if (val1 > val2) {
                return 1;
            }
            if (val1 == val2 && version1.length() == 0 && version2.length() == 0) {
                break;
            } 

        }

        return 0;
    }
};