#include<iostream>
#include<climits>

using namespace std;

class heap_{
  int *harr;
  int curr_size;
  int cap;
  public:
 heap_(int c) {
   cap = c;
   curr_size = 0;
   harr = new int(cap);
 }
 int get_p(int i) {return (i-1)/2;}
 int get_l(int i) {return (2*i + 1);}
 int get_r(int i) {return (2*i + 2);}

 int get_min() {return harr[0];}
 int extract_min();
 void insert_(int val);
 void delete_(int i);
 void decrease(int i,int v);
 void heapify(int i);
};

void heap_::decrease(int i,int v) {
  harr[i] = v;
  while(i != 0 && harr[get_p(i)] > harr[i]) {
    swap(harr[i],harr[get_p(i)]);
    i = get_p(i);
  }
}

void heap_::delete_(int i) {
  decrease(i,INT_MIN);
  extract_min();
}

void heap_::insert_(int v) {
  if(curr_size == cap) {
    cout<<"HEAP FULL!!"<<endl;
    return;
  }
  harr[curr_size] = v;
  int i = curr_size;
  ++curr_size;
  while(i != 0 && harr[get_p(i)] > harr[i]) {
    swap(harr[i],harr[get_p(i)]);
    i = get_p(i);
  }
}

int heap_::extract_min() {
  if(curr_size == 0) {
    cout<<"HEAP EMPTY!!"<<endl;
    return INT_MIN;
  }
  int t = harr[0];
  harr[0] = harr[curr_size - 1];
  --curr_size;
  heapify(0);
  return t;
}

void heap_::heapify(int i) {
  int l = get_l(i);
  int r = get_r(i);
  int small = i;

  if(l < curr_size && harr[l] < harr[small]) small = l;
  if(r < curr_size && harr[r] < harr[small]) small = r;

  if(small != i) {
    swap(harr[i],harr[small]);
    heapify(small);
  }
}

int main()
{
    heap_ h(11);
    h.insert_(3);
    h.insert_(2);
    h.delete_(1);
    h.insert_(15);
    h.insert_(5);
    h.insert_(4);
    h.insert_(45);
    cout << h.extract_min() << " ";
    cout << h.get_min() << " ";
    h.decrease(2, 1);
    cout << h.get_min()<<endl;
    return 0;
}
