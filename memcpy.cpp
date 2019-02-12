#include<iostream>
#include<string.h>

using namespace std;

void memcpy(void* dst,void* src, size_t n) {
  char *csrc = (char *)src;
  char *cdst = (char *)dst;

  if(csrc == cdst)
    return;

  if(cdst > csrc) {
    csrc = csrc + n -1;
    cdst = cdst + n -1;
    while(n--)
    {
      *cdst-- = *csrc--;
    }
  }
  else {
    while(n--)
    {
      *cdst++ = *csrc++;
    }
  }
}

int main()
{
  char src[20] = "KUMARVIKRAM";
  char dst[20];
  memcpy(src+5,src,strlen(src)+1);
  cout<<src<<endl;
  return 0;
}
