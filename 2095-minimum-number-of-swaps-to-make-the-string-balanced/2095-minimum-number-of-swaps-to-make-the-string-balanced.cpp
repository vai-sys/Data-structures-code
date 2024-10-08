class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int swap=0;
        for(auto c:s){
           if(c=='['){
            st.push(c);
           }
           else{
            if(!st.empty()){
                st.pop();
            }
            else{
                swap++;
               st.push('[');
            }
           } 


        }
        return swap;
    }
};