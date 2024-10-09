class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<char>st;
        for(auto ch:s){
            if(ch=='('){
                 st.push(ch);

            }
           
            if(!st.empty() && ch==')'){
                st.pop();
            }
            else if(st.empty() && ch==')'){
                count++;
                
            }
        }
        return  count + st.size();
    }
};