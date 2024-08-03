class Solution {
public:
    void solver(vector<int>& nums, vector<int>& currSol, vector<vector<int>>& sol, int ind, int n) {
        sol.push_back(currSol);
        for (int i = ind; i < n; i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            currSol.push_back(nums[i]);
            solver(nums, currSol, sol, i + 1, n);
            currSol.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> currSol;
        sort(nums.begin(), nums.end());
        solver(nums, currSol, sol, 0, nums.size());
        return sol;
    }
};