class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> sol;
        int c1 = 0, c2 = 0, r1 = INT_MIN, r2 = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (c1 == 0 && r2 != nums[i]) {
                r1 = nums[i];
                c1++;
            }
            else if (c2 == 0 && r1 != nums[i]) {
                r2 = nums[i];
                c2++;
            }
            else if (r1 == nums[i]) {
                c1++;
            }
            else if (r2 == nums[i]) {
                c2++;
            }
            else {
                c1--;
                c2--;
            }
        }
        cout << r1 << ": " << c1 << ", " << r2 << ": " << c2 << endl;
        c1 = 0;
        c2 = 0;
        for (auto itr: nums) {
            if (itr == r1) c1++;
            if (itr == r2) c2++;
        }

        if (c1 > (nums.size() / 3)) {
            sol.push_back(r1);
        }

        if (c2 > (nums.size() / 3)) {
            sol.push_back(r2);
        }
        return sol;
    }
};