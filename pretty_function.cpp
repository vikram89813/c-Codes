#include<iostream>

using namespace std;

void pretty_helper(int **arr,int offset,int A,int size_)
{
  if(offset == size_-offset-1)
  {
    arr[offset][offset] = offset;
  }
  for(int i=offset;i<size_-offset-1;i++) arr[offset][i] = A;
  for(int i = offset;i<size_-offset-1;i++) arr[i][size_-offset-1] = A;
  for(int i = size_-offset-1;i>=offset;i--) arr[size_-offset-1][i] = A;
  for(int i = size_-offset-1;i>=offset;i--) arr[i][offset] = A;
}

void pretty(int A)
{
  int size_ = (2*A)-1;
  int t = A;

  int **arr = new int*[size_];
  for(int i=0;i<size_;i++)
    arr[i] = new int[size_];

  for(int offset=0;offset<t;offset++)
  {
    pretty_helper(arr,offset,A--,size_);
  }

  for(int i=0;i<size_;i++)
  {
    for(int j=0;j<size_;j++)
    {
      cout<<arr[i][j] <<" ";
    }
    cout<<endl;
  }
}

int main()
{
  pretty(4);
  return 0;
}
