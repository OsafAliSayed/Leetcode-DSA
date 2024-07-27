class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int i = 0;
        if (mp.find(0) != mp.end()) {
            for (int j = 0; j < mp[0]; j++) {
                nums[i] = 0;
                i++;
            }
        }
        if (mp.find(1) != mp.end()) {
            for (int j = 0; j < mp[1]; j++) {
                nums[i] = 1;
                i++;
            }
        }
        if (mp.find(2) != mp.end()) {
            for (int j = 0; j < mp[2]; j++) {
                nums[i] = 2;
                i++;
            }
        }
    }
};