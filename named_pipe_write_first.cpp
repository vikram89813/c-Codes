#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>

using namespace std;

int main() {
  int fd;
  string fifo_p = "\\tmp\\myfifo";
  mkfifo(fifo_p.c_str(),0666);
  char arr[100];
  while(1) {
    fd = open(fifo_p.c_str(),O_WRONLY);
    string str;
    cin>>str;
    write(fd,str.c_str(),str.size()+1);
    close(fd);
    fd = open(fifo_p.c_str(),O_RDONLY);
    read(fd,arr,100);
    close(fd);
    cout<<arr<<endl;
  }
}
