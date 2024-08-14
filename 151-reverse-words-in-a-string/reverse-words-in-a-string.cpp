class Solution {
public:
    string reverseWords(string s) {

        string ans = "";
        while (true) {
            // remove extra space in start
            int i = 0;
            while (i < s.length() && s[i] == ' ') {
                i++;
            }
            s = s.substr(i, s.length());
            
            if (s == "") {
                break;
            }
             
            i = 0;
            while (i < s.length() && s[i] != ' ') {
                i++;
            }
            cout << s.substr(0, i) << endl;
            ans = ans.length() == 0 ? s.substr(0, i) : s.substr(0, i) + " " + ans;
            s = s.substr(i, s.length());
        }
        return ans;
    }
};