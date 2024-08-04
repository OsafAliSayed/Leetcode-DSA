class Solution {
public:
    void solver(vector<int>& candidates, vector<vector<int>>& sol, vector<int>& temp, int n, int ind, int target) {
        if (target == 0) {
            sol.push_back(temp);
            return;
        }
        
        for (int i = ind; i < n; i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            temp.push_back(candidates[i]);
            solver(candidates, sol, temp, n, i + 1, target - candidates[i]);
            temp.pop_back();
        }
        // solver(candidates, sol, temp, n, ind + 1, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> sol;
        vector<int> temp;
        solver(candidates, sol, temp, candidates.size(), 0, target);
        return sol;
    }
};