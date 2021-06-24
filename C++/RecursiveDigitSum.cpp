#include<bits/stdc++.h>
using namespace std;

long long int digitSum(string s){
  long long int sum=0;
  for(auto c: s){
    sum += c-'0';
  }
  return sum;
}
int superDigit(string n, int k) {
  long long int  temp = k*digitSum(n);
  while(temp  > 10){
    temp = digitSum(to_string(temp));
  }
  return temp;
}

int main(){
  string s;
  int k;
  cin>>s>>k;
  cout<<superDigit(s,k);
}
