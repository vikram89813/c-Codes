#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
  unordered_multimap<string,int> m;
  m.insert({"apple",1});
  m.insert({"apple",2});
  m.insert({"apple",3});
  m.insert({"apple",4});
  m.insert({"apple",5});
  m.insert({"apple",6});
  m.insert({"apple",7});
  m.insert({"samsung",4});
  m.insert({"samsung",5});
  m.insert({"samsung",6});
  auto it = m.equal_range("apple");
  for(auto itr = it.first;itr!=it.second;itr++)
    cout<<itr->first<<" "<<itr->second<<endl;
  //for(auto it = m.find("car");it!=m.end();it++) {
  //  cout<<"hello"<<endl;
  //  cout<<it->first<<" "<<it->second<<endl;
  //}
}
