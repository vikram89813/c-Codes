#include<iostream>

using namespace std;

void rev(char* str, int size)
{
  int start = 0;
  int end = size-1;
  while(start<end)
  {
    swap(*(str+start),*(str+end));
    start++;
    end--;
  }
}

char * itoa(int num, char *str, int base)
{
  int i = 0;
  bool isneg = false;
  if(num == 0)
  {
    str[i++] = '0';
    str[i] = '\0';
    return str;
  }
  if(num<0 && base == 10)
  {
    num = -num;
    isneg = true;
  }
  while(num != 0 )
  {
    int rem = num % base;
    str[i++] = (rem > 9) ? (rem-10) + 'A' : rem+'0';
    num/=base;
  }
  if(isneg)
  {
    str[i++] = '-';
  }
  str[i] = '\0';
  rev(str,i);
  return str;
}

int main()
{
    char str[100];
    cout << "Base:10 " << itoa(1567, str, 10) << endl;
    cout << "Base:10 " << itoa(-1567, str, 10) << endl;
    cout << "Base:2 " << itoa(1567, str, 2) << endl;
    cout << "Base:8 " << itoa(1567, str, 8) << endl;
    cout << "Base:16 " << itoa(1567, str, 16) << endl;
    return 0;
}

