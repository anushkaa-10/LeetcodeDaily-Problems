class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = healths.size();
        unordered_map<int, pair<int, char>> mp;
        vector<int> copy(positions);

        for (int i = 0; i < n; i++) {
            mp[copy[i]] = {healths[i], directions[i]};
        }

        sort(positions.begin(), positions.end());

        stack<int> st;

        for (auto pos : positions) {

            if (st.empty())
                st.push(pos);

            else {
                int ptop = st.top();
                if (mp[ptop].second == mp[pos].second or
                    (mp[ptop].second == 'L' and mp[pos].second == 'R')) {
                    st.push(pos);
                } 
                else {
                    while (!st.empty() and (mp[ptop].second == 'R' and mp[pos].second == 'L')) {
                        if (mp[ptop].first ==
                            mp[pos].first) { 
                            mp[ptop].first = 0;
                            mp[pos].first = 0;
                            st.pop();
                            break;
                        } else if (mp[ptop].first >
                                   mp[pos].first) { 
                            mp[ptop].first = mp[ptop].first - 1;
                            mp[pos].first = 0;
                            break;
                        } else { 
                            mp[ptop].first = 0;
                            mp[pos].first = mp[pos].first - 1;
                            st.pop();
                            if(st.size()) ptop = st.top();
                        }
                    }
                    if (mp[pos].first > 0)
                        st.push(pos);
                }
            }
        }

        if (st.empty())
            return {};

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mp[copy[i]].first > 0)
                ans.push_back(mp[copy[i]].first);
        }

        return ans;
    }
};