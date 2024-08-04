class Solution {
public:
    void solver(vector<int>& candidates, vector<vector<int>>& sol, vector<int>& temp, int n, int ind, int target) {
        if (ind == n) {
            if (target == 0) {
                sol.push_back(temp);
            }
            return;
        }
        if (candidates[ind] <= target) {
            temp.push_back(candidates[ind]);
            solver(candidates, sol, temp, n, ind, target - candidates[ind]);
            temp.pop_back();
        }
        solver(candidates, sol, temp, n, ind + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> temp;
        solver(candidates, sol, temp, candidates.size(), 0, target);
        return sol;
    }
};