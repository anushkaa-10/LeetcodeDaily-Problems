class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int cnt=0;
        int counter =0;
        if(x>y){
            for (int i = 1; i < s.size(); ++i) {
                if (s.substr(i-1, 2) == "ab") {
                    cnt++;
                    s.erase(i-1, 2);
                    i -= 2;
                    if (i < 0) i = 0;
                }
            }
            for(int i=1; i<s.size(); ++i){
                if(s.substr(i-1, 2)=="ba"){
                    counter++;
                    s.erase(i-1,2);
                    i -=2;
                    if (i < 0) i = 0;
                }
            }
        }
        else{

            for(int i=1; i<s.size(); i++){
                if(s.substr(i-1, 2)=="ba"){
                    s.erase(i-1,2);
                    counter++;
                    i-=2;
                    if (i < 0) i = 0;
                }
            }
            for(int i=1; i<s.size(); i++){
                if(s.substr(i-1, 2)=="ab"){
                    s.erase(i-1,2);
                    cnt++;
                    i-=2;
                    if (i < 0) i = 0;
                }
            }
        }
        int ans = x*cnt + y*counter;
        return ans;
    }
};