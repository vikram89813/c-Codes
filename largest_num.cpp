#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int myCompare(string X, string Y)
{
    string XY = X.append(Y);
    string YX = Y.append(X);
    return XY.compare(YX) > 0 ? 1: 0;
}

string cal(vector<int> &A)
{
   string str;
   vector<string> arr;
   for(int i = 0;i<A.size();i++)
     arr.push_back(to_string(A[i]));

   sort(arr.begin(), arr.end(), myCompare);
   str = arr[0];
    for (int i=1; i < arr.size() ; i++ )
        str += arr[i];
  string s;
  for(int i=0;i<A.size();i++)
  {
    s+='0';
  }
  if(!s.compare(str)) return "0";
  return str;
}

static bool compareNum(string a, string b) {
            return a + b > b + a;
}

string largestNumber(const vector<int> &num) {
            string result;
            vector<string> str;
            for (int i = 0; i < num.size(); i++) {
                str.push_back(to_string(num[i]));
            }
            sort(str.begin(), str.end(), compareNum);
            for (int i = 0; i < str.size(); i++) {
                result += str[i];
            }

            int pos = 0;
            while (result[pos] == '0' && pos + 1 < result.size()) pos++;

            return result.substr(pos);
}

int main()
{
  vector<int> arr = {0,0,0,0,0};
  //string str = cal(arr);
  string str = largestNumber(arr);
  cout<<str<<endl;
  return 0;
}
