#include<iostream>
#include<climits>

using namespace std;

class heap_ {
  int cap,curr_size;
  int *harr;
  public:
    heap_(int c) {
      cap = c;
      harr = new int(c);
      curr_size = 0;
    }

    void insert_(int val);
    int get_p(int i) {return (i-1)/2;}
    int left(int i) {return 2*i+1;}
    int right(int i) {return 2*i+2;}
    int get_min() {return harr[0];}
    int extract_min();
    void decrease(int idx,int v);
    void delete_(int idx);
    void heapify(int idx);
};

void heap_::insert_(int val) {
  if(curr_size == cap) {
    cout<<"HEAP FULL!!"<<endl;
    return;
  }
  harr[curr_size++] = val;
  int idx = curr_size - 1;
  while(idx > 0 && harr[get_p(idx)] > harr[idx]) {
      swap(harr[get_p(idx)],harr[idx]);
      idx = get_p(idx);
  }
}

void heap_::decrease(int idx,int val) {
  harr[idx] = val;
  while(idx > 0 && harr[get_p(idx)] > harr[idx]) {
      swap(harr[get_p(idx)],harr[idx]);
      idx = get_p(idx);
  }
}

void heap_::delete_(int idx) {
  decrease(idx,INT_MIN);
  extract_min();
}

int heap_::extract_min() {
  if(curr_size == 0) {
    cout<<"HEAP is Empty!!";
    return INT_MIN;
  }
  int temp = harr[0];
  harr[0] = harr[curr_size - 1];
  curr_size--;
  heapify(0);
  return temp;
}

void heap_::heapify(int idx) {
  int s = idx;
  int l = left(idx);
  int r = right(idx);
  if(l < curr_size && harr[l] < harr[s]) s = l;
  if(r < curr_size && harr[r] < harr[s]) s = r;

  if(s != idx) {
    swap(harr[idx],harr[s]);
    heapify(s);
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
