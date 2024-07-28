class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target - nums[i]) != mp.end()) {
                return vector<int>({mp[target-nums[i]], i});
            }
            else {
                mp[nums[i]] = i;
            }
        }
        return vector<int>({});
    }
};