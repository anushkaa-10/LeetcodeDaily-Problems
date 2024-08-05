class Solution {
public:
bool distinct(vector<string>& arr, int i){
    return count(arr.begin(),arr.end(),arr[i])==1;
}
    string kthDistinct(vector<string>& arr, int k) {
        int cnt =0;
        for(int i=0; i<arr.size(); i++){
            if(distinct(arr,i)){
                cnt++;
                if(cnt==k){
                    return arr[i];
                }
            }
        }
        return "";
        
    }
};