class Solution {
public:
    map<char, int> mp {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}};
    int myAtoi(string s) {
        // remove white space first
        int i = 0;
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        s = s.substr(i, s.length() - i);

        long long num = 0;
        int sign = 1;
        i = 0;
        if (s[i] == '+') {
            sign = 1;
            i++;
        }
        else if (s[i] == '-') {
            sign = -1;
            i++;
        }

        while (i < s.length()) {
            if (num == 0 && s[i] == 0) {
                i++;
                continue;
            }
            if (num * sign > INT_MAX) {
                return INT_MAX;
            }
            if (num * sign < INT_MIN) {
                return INT_MIN;
            }
            // if character is not in map
            if (mp.find(s[i]) == mp.end()) {
                    num = num * (long long)sign;
                    if (num > INT_MAX) {
                        return INT_MAX;
                    }
                    else if (num < INT_MIN) {
                        return INT_MIN;
                    }
                    return num;
            }
            else {
                num = (long long)num * 10 + (long long)mp[s[i]];
            }
            i++;
        }
        num = num * (long long)sign;
        if (num > INT_MAX) {
            return INT_MAX;
        }
        else if (num < INT_MIN) {
            return INT_MIN;
        }
        else {
            return num;
        }
    }
};