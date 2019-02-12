#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include<array>

using namespace std;

double BuyAndSellStockTwiceConstantSpace(const vector<double>& prices) {
  array<double, 2> min_prices = {numeric_limits<double>::max(),
                                 numeric_limits<double>::max()},
                   max_profits = {0.0, 0.0};
  for (const double& price : prices) {
    for (int i = 1; i >= 0; --i) {
      max_profits[i] = max(max_profits[i], price - min_prices[i]);
      min_prices[i] =
          min(min_prices[i], price - (i - 1 >= 0 ? max_profits[i - 1] : 0.0));
    }
  }
  return max_profits[1];
}

int main()
{
  vector<double> a = {12,11,13,9,12,8,14,13,15};
  double ans = BuyAndSellStockTwiceConstantSpace(a);
  cout<<ans<<endl;
  return 0;
}
