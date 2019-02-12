#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

string input;
int dp[101][101];

int rec(int k,int num, int flag)
{
    if(num%8 == 0 && flag)
    {
        printf("YES\n%d\n",num);
        exit(0);
    }
    if(k == input.size()) return 0;
    if(dp[k][num] != -1) return dp[k][num];
    rec(k+1,num,flag);
    rec(k+1,((num*10)+(input[k]-'0'))%1000,1);
    return dp[k][num]=0;
}

int main()
{
  cin>>input;

  for(int i=0;i<101;i++)
    for(int j=0;j<101;j++)
      dp[i][j] = -1;

  rec(0,0,0);
  cout<<"NO"<<endl;
  return 0;
}
