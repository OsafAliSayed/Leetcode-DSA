/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Compare {
public:
    bool operator() (pair<int,int> p1, pair<int,int> p2) {
        if (p1.second == p2.second) {
            return p1.first >= p2.first;
        }
        else {
            return p1.second > p2.second;
        }
    }
};

class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        // vertical index: list of pair of elements and its depth 
        map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, Compare>> mp;
        // Node: vertical index : depth
        list<pair<TreeNode *, pair<int, int>>> q;
        q.push_back({root, {0, 0}});
        while (!q.empty()) {
            pair<TreeNode *, pair<int, int>> ele = q.front();
            q.pop_front();

            if (mp.find(ele.second.first) == mp.end()) {
                priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> temp;
                mp[ele.second.first] = temp;
            }
            
            mp[ele.second.first].push(make_pair(ele.first->val, ele.second.second));

            if (ele.first->left != NULL) {
                q.push_back({ele.first->left, {ele.second.first - 1, ele.second.second + 1}});
            }

            if (ele.first->right != NULL) {
                q.push_back({ele.first->right, {ele.second.first + 1, ele.second.second + 1}});
            }
        }

        for (auto q: mp) {
            vector<int> temp;
            while (!q.second.empty()) {
                temp.push_back(q.second.top().first) ;
                q.second.pop();
            }
            res.push_back(temp);
        }
        return res;
    }
};