#include<iostream>
#include<vector>

using namespace std;

void setzero(vector<vector<int>> &matrix)
{
            int rownum = matrix.size();
            if (rownum == 0)  return;
            int colnum = matrix[0].size();
            if (colnum == 0)  return;

            bool hasZeroFirstRow = false, hasZeroFirstColumn = false;

            for (int j = 0; j < colnum; ++j) {
                if (matrix[0][j] == 0) {
                    hasZeroFirstRow = true;
                    break;
                }
            }

            for (int i = 0; i < rownum; ++i) {
                if (matrix[i][0] == 0) {
                    hasZeroFirstColumn = true;
                    break;
                }
            }

            for (int i = 1; i < rownum; ++i) {
                for (int j = 1; j < colnum; ++j) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

            for (int i = 1; i < rownum; ++i) {
                for (int j = 1; j < colnum; ++j) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
                }
            }

            if (hasZeroFirstRow) {
                for (int j = 0; j < colnum; ++j) {
                    matrix[0][j] = 0;
                }
            }
            if (hasZeroFirstColumn) {
                for (int i = 0; i < rownum; ++i) {
                    matrix[i][0] = 0;
                }
            }
}

int main()
{
  vector<vector<int>> arr = {{0,1},{1,1}};
  setzero(arr);
  for(int i=0;i<arr.size();i++)
  {
    for(int j=0;j<arr[i].size();j++)
      cout<<arr[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
