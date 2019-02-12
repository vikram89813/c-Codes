#include<iostream>
#include<any>
#include<vector>
#include<algorithm>
#include <execution>

int main() {
  std::vector<std::any> arr;
  arr.push_back(1);
  arr.push_back(10.56);
  std::cout<<std::any_cast<int>(arr[0])<<std::endl;
  std::cout<<std::any_cast<double>(arr[1])<<std::endl;
  std::vector v = {12,5,70,34,4676,4235425,657868,3456436,2324354};
  std::sort(std::execution::par, v.begin(), v.end());
  //for(auto i : arr1) std::cout<<i<<" ";
  //std::cout<<std::endl;
}
