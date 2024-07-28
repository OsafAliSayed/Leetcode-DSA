class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                return vector<int>({mp[nums[i]], i});
            }
            else {
                mp[target - nums[i]] = i;
            }
        }
        return vector<int>({});
    }
};