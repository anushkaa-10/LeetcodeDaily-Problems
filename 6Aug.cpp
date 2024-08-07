// instead of priority queue one can use vector array but then we also have to sort it.

class Solution {
public:
    int minimumPushes(string word) {
       unordered_map<char, int> mp;
       priority_queue<int> pq;

        for (char c : word) {
            mp[c]++;
        }

        for (auto &it : mp) {
            pq.push(it.second);
        }

        int cnt = 0;
        int ans = 0;
        int multiply = 1;

        while (!pq.empty()) {
            ans += multiply * pq.top();
            pq.pop();
            cnt++;
            if (cnt % 8 == 0) multiply++;
        }

        return ans;
    }
};