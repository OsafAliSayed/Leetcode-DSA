class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> sol;
        int l = 0, r = 0;
        while (l < m && r < n) {
            if (nums1[l] < nums2[r]) {
                sol.push_back(nums1[l]);
                l++;
            }
            else {
                sol.push_back(nums2[r]);
                r++;
            }
        }

        while (l < m) {
            sol.push_back(nums1[l]);
            l++;
        }

        while(r < n) {
            sol.push_back(nums2[r]);
            r++;
        }

        for (int i = 0; i < sol.size(); i++) {
            nums1[i] = sol[i];
        }
    }
};