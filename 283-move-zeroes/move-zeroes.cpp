class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count_zero = 0;
        int track = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count_zero++;
            }
            else {
                int temp = nums[i];
                nums[i] = nums[track];
                nums[track] = temp;
                track++;
            }
        }
        
    }
};