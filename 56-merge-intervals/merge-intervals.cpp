class Solution {
public:
    static bool sortcol(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    void printVec(vector<int>& v) {
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " " ;
        }
        cout << endl;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> sol;
        sort(intervals.begin(), intervals.end(), sortcol);
        for (int i = 0; i < intervals.size(); i++) {
            if (sol.empty() || sol[sol.size() - 1][1] < intervals[i][0]) {
                sol.push_back(intervals[i]);
            }
            else {
                sol[sol.size() - 1][1] = max(sol[sol.size() - 1][1], intervals[i][1]);
            }
        }
        return sol;
    }
};