class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        while (true) {
            cout << version1 << " " << version2 << endl;
            int val1 = 0;
            int val2 = 0;
            if (version1.length() != 0) {
                int i = 0;
                while (i < version1.length() && version1[i] != '.') {
                    i++;
                }
                val1 = stoi(version1.substr(0, i));
                if (i != version1.length()) {
                    version1 = version1.substr(i + 1);
                }
                else {
                    version1 = "";
                }
            }
            if (version2.length() != 0) {
                int i = 0;
                while (i < version2.length() && version2[i] != '.') {
                    i++;
                }
                val2 = stoi(version2.substr(0, i));
                if (i != version2.length()) {
                    version2 = version2.substr(i + 1);
                }
                else {
                    version2 = "";
                }
            }
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