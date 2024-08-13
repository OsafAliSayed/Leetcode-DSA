class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        list<int> li;
        for (int i = 0; i < nums.size(); i++) {
            if (!li.empty() && li.front() <= i - k) {
                li.pop_front();
            }

            while (!li.empty() && nums[li.back()] <= nums[i]) {
                li.pop_back();
            }
            li.push_back(i);
            if (i >= k - 1) res.push_back(nums[li.front()]);
        }
        return res;

    }
};