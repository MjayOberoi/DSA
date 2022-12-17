class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<long long> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!="+" && s[i]!="-" && s[i]!="*" && s[i]!="/"){
                st.push(stoi(s[i]));
            }else{
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                if(s[i]=="+"){
                    st.push(op1+op2);
                }else if(s[i]=="-"){
                    st.push(op1-op2);
                }else if(s[i]=="*"){
                    st.push((long long)op1*op2);
                }else if(s[i]=="/"){
                    st.push(op1/op2);
                }
            }
        }
        return st.top();
    }
};