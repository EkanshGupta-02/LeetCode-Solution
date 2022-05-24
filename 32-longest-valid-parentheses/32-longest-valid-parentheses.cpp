class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi=0;
        
        stack<int> st;
        st.push(-1);
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    maxi=max(maxi,i-st.top());
                }
            }
        }
        
        return maxi;
        
//         int maxians=0;
//         int left=0,right=0;
        
//         for(int i=0;i<s.length();i++){
//             if(s[i]=='('){
//                 left++;
//             }
//             else{
//                 right++;
//             }
//             if(left==right){
//                 maxians=max(maxians,2*right);
//             }
//             else if(right>=left){
//                 left=0;right=0;
//             }
//         }
        
//         left=0;right=0;
        
//         for(int i=s.length()-1;i>=0;i--){
//             if(s[i]=='('){
//                 left++;
//             }
//             else{
//                 right++;
//             }
//             if(left==right){
//                 maxians=max(maxians,2*left);
//             }
//             else if(left>=right){
//                 left=0;
//                 right=0;
//             }
//         }
        
//         return maxians;
    }
};