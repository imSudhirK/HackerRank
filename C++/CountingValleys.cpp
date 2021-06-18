#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {
  int vc=0, dc=0, uc=0;
  bool isV = false;
  for(int i=0; i<steps; i++){
    if(path[i] == 'U'){
      if(dc == uc){
        isV = false;
      }
      uc +=1;
    }
    else if(path[i] == 'D'){
      if(dc==uc){
        isV = true;
      }
      dc +=1;
    }
    if(dc==uc){
      if(isV){
        vc +=1; isV = false;
      }
      dc = uc = 0;
    }
  }
  return vc;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
