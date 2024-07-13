class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        int n = s.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(s[i]=='(') st.push(i);
            else if(s[i] == ')')
            {
                int start = st.top()+1;
                int end = i;

                reverse(s.begin()+start, s.begin()+end);
                st.pop();
            }
        }
        for(auto &ch: s){
            if(ch!='(' && ch!=')') ans+=ch;
        }
        return ans;
    }
};