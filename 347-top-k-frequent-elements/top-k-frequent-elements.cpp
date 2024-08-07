class Solution {
public:
    
    static bool compare(pair<int,int> p1, pair<int,int> p2) {
        return p1.second < p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, function<bool(pair<int, int>, pair<int, int>)>> pq(compare);
        for (auto itr: mp) {
            pq.push(itr);
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};