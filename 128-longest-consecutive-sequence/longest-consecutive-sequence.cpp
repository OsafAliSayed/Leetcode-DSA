class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //remove duplicates using set
        set<int, less<int>> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        set<int> s;
        int maxLen = 0;
        int len = 0;
        for(auto itr: st) {
            if (s.find(itr - 1) != s.end()) {
                len++;
            }
            else {
                len = 1;
            }
            maxLen = max(maxLen, len);
            s.insert(itr);
        }
        return maxLen;
    }
};