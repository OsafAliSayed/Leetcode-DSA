class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                temp.push_back(nums[i]);
            }
        }

        int i;
        for (i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }
        for (; i < nums.size(); i++) {
            nums[i] = 0;
        }
        
    }
};