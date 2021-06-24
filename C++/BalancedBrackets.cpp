#include<bits/stdc++.h>
using namespace std;

string isBalanced(string s) {
  stack<char> st;
  for(auto c: s){
    switch(c){
      case '(':
      case '{':
      case '[':
        st.push(c);
        break;
      case ')':
        if(st.empty() || st.top() != '('){
          return "NO";
        }
        else{
          st.pop();
          break;
        }
      case '}':
        if(st.empty() || st.top() != '{'){
          return "NO";
        }
        else{
          st.pop();
          break;
        }
      case ']':
        if(st.empty() || st.top() != '['){
          return "NO";
        }
        else{
          st.pop();
          break;
        }
      }
    }
  if(st.empty()){
    return "YES" ;
  }
  else return "NO";
}


int main(){
  int n;
  string s;
  cin>>n;
  for(int i=0;i<n; i++){
    cin>>s;
    cout<<isBalanced(s)<<endl;
  }
  return 0;
}
