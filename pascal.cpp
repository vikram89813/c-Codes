#include<iostream>
#include<vector>

using namespace std;

vector<int> GeneratePascalTriangle(int A) {
  vector<vector<int>> pascal_triangle;
  for (int i = 0; i <= A; ++i) {
    vector<int> curr_row;
    for (int j = 0; j <= i; ++j) {
      curr_row.emplace_back(0 < j && j < i
                                ? pascal_triangle.back()[j - 1] +
                                      pascal_triangle.back()[j]
                                : 1);
    }
    pascal_triangle.emplace_back(curr_row);
  }

  vector<int> sol;
  for(int i = 0;i<(pascal_triangle.back()).size();i++)
    sol.push_back(pascal_triangle.back()[i]);
  return sol;
}

int main()
{
  vector<int> res = GeneratePascalTriangle(3);
  for(int i : res)
    cout<<i<<" ";
  cout<<endl;
  return 0;
}
