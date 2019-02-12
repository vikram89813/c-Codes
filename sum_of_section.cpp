#include<iostream>
using namespace std;

long long a[16];

int no_of_digit(long long a) {
  int c=0;
  while(a) {
    c++;
    a = a/10;
  }
  return c-1;
}

long long ceil_(long double num) {
    long long inum = (long long)num;
    if (num == (long double)inum) {
        return inum;
    }
    return inum + 1;
}

long double pow_(long double x,long long y) {
    long double temp;
    if( y == 0)
       return 1;
    temp = pow_(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}

void preprocess() {
  a[0] = 0, a[1] = 45;
  for (int i=2; i<=15; i++)
    a[i] = a[i-1]*10 + 45*ceil_(pow_(10,i-1));
}

long long sumOfDigitsFrom1ToN(long long n)
{
    if (n<10)
      return n*(n+1)/2;

    int d = no_of_digit(n);
    long long p = ceil_(pow_(10, d));
    int msd = n/p;
    return msd*a[d] + (msd*(msd-1)/2)*p +
           msd*(1+n%p) + sumOfDigitsFrom1ToN(n%p);
}

int main()
{
    int T;
    cin>>T;
    preprocess();
    for(int t=1;t<=T;t++) {
      long long a,b;
      cin>>a>>b;
      long long s1 = sumOfDigitsFrom1ToN(b);
      long long s2 = sumOfDigitsFrom1ToN(a-1);
      cout<<"#"<<t<<" "<<(s1-s2)<<endl;
    }
    return 0;
}

