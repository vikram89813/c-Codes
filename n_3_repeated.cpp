#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int sol(vector<int> &A) {
  int n=A.size();
  int element1=INT_MAX,element2=INT_MAX;
  int count1=0,count2=0,i;
  for(i=0;i<n;i++){
    	if(count1>0 && A[i]==element1){
    		count1+=1;
    	}else if(count2>0 && A[i]==element2){
    		count2+=1;
    	}else if(count1==0){
    		element1=A[i];
    		count1=1;
    	}else if(count2==0){
    		element2=A[i];
    		count2=1;
    	}else{
    		count1--;
    		count2--;
    	}
   }
   int check,freq=0;
   if(count1==0 && count2==0) {
    	return -1;
    }
    else
    check=element1;
	for(i=0;i<n;i++){
    	if(A[i]==check)
    		freq++;
    }
    if(freq>1)
    	return check;
    check=element2;
    freq=0;
    for(i=0;i<n;i++){
    	if(A[i]==check)
    		freq++;
    }
    if(freq>1)
    	return check;
    return -1;
 }

int main()
{
  vector<int> arr = {1,4,4,2,5};
  int res = sol(arr);
  cout<<res<<endl;
  return 0;
}
