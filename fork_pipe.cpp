#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<cstring>

using namespace std;

int main() {
  int fd1[2];
  int fd2[2];
  pid_t p;
  string str = "forgeeks.org";
  string in_str;

  if(pipe(fd1) == -1) {
    cout<<"Pipe failed!!"<<endl;
    return 1;
  }
  if(pipe(fd2) == -1) {
    cout<<"Pipe failed!!"<<endl;
    return 1;
  }
  cin>>in_str;
  p = fork();
  if(p < 0 ) {
    cout<<"fork failed!!"<<endl;
    return 1;
  }
  else if(p>0) {
    close(fd1[0]);
    char temp[100];
    write(fd1[1],in_str.c_str(),in_str.size()+1);
    close(fd1[1]);
    wait(NULL);
    close(fd2[1]);
    read(fd2[0],temp,100);
    close(fd2[0]);
    cout<<temp<<endl;
  } else {
    char tmp[100];
    close(fd1[1]);
    read(fd1[0],tmp,100);
    close(fd1[0]);
    int k = strlen(tmp);
    for(auto i : str) tmp[k++] = i;
    close(fd2[0]);
    write(fd2[1],tmp,k);
    close(fd2[1]);
    exit(0);
  }
}
