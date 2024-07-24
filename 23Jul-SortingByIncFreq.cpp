class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;

        for (int num : nums) {
            mp[num]++;
        }
        sort(nums.begin(),nums.end(),[&](int a, int b){
            if(mp[a]!=mp[b]) return mp[a]<mp[b];
            else return b<a;
        });
        return nums;
    }
};