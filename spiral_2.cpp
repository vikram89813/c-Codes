#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void MatrixLayerInClockwise(int **arr,int offset,int A,int &num) {
  if (offset == A - offset - 1) {
    arr[offset][offset] = num;
    return;
  }

  for (int j = offset; j < A - offset - 1; ++j) {
    arr[offset][j] = num++;
  }
  for (int i = offset; i < A - offset - 1; ++i) {
    arr[i][A - offset - 1] = num++;
  }
  for (int j = A - offset - 1; j > offset; --j) {
    arr[A - offset - 1][j] = num++;
  }
  for (int i = A - offset - 1; i > offset; --i) {
    arr[i][offset] = num++;
  }
}

vector<vector<int>> MatrixInSpiralOrder(int A) {
  int** arr = new int*[A];
  for(int i = 0; i < A; ++i)
    arr[i] = new int[A];

  int num = 1;

  for (int offset = 0; offset < ceil(0.5 * A); ++offset) {
    MatrixLayerInClockwise(arr, offset,A,num);
  }

  vector<vector<int>> res;
  for(int i = 0;i<A;i++)
  {
    vector<int> temp;
    for(int j=0;j<A;j++)
    {
       temp.push_back(arr[i][j]);
    }
    res.push_back(temp);
  }
  return res;
}

int main()
{
  int n = 3;
  vector<vector<int>> res = MatrixInSpiralOrder(n);
  for(int i=0;i<res.size();i++)
  {
    for(int j=0;j<res[i].size();j++)
      cout<<res[i][j]<<" ";

    cout<<endl;
  }
  return 0;
}
