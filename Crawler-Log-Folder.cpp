class Solution {
public:
    int minOperations(vector<string>& logs) {
        if(logs.size()<=0) return 0;
        int cnt =0;
        for(int i=0; i<logs.size(); i++){
            if(logs[i]=="../"){
                if(cnt>0) cnt--;
            }
                else if(logs[i]=="./") continue;
                else cnt++;
        }
        return cnt;
    }
};