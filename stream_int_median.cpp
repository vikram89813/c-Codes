/* output :
5
10
5
4
3
4
5
6
7
6
*/

#include<iostream>
#include<queue>

using namespace std;

void printMedian(int arr[],int size_) {
  priority_queue<int> max_heap;
  priority_queue<int,vector<int>,greater<int>> min_heap;
  vector<int> med;
  int curr_med = arr[0];
  med.push_back(arr[0]);
  max_heap.push(arr[0]);
  for(int i=1;i<size_;i++) {
    int t = arr[i];
    if(max_heap.size() > min_heap.size()) {
      if(t < curr_med) {
        min_heap.push(max_heap.top());
        max_heap.pop();
        max_heap.push(t);
        curr_med = (max_heap.top() + min_heap.top()) / 2;
        med.push_back(curr_med);
      } else {
        min_heap.push(t);
        curr_med = (max_heap.top() + min_heap.top()) / 2;
        med.push_back(curr_med);
      }
    } else if (max_heap.size() < min_heap.size()) {
      if(t > curr_med) {
        max_heap.push(min_heap.top());
        min_heap.pop();
        min_heap.push(t);
        curr_med = (max_heap.top() + min_heap.top()) / 2;
        med.push_back(curr_med);
      } else {
        max_heap.push(t);
        curr_med = (max_heap.top() + min_heap.top()) / 2;
        med.push_back(curr_med);
      }
    } else {
      if(t < curr_med) {
        max_heap.push(t);
        curr_med = max_heap.top();
        med.push_back(curr_med);
      } else {
        min_heap.push(t);
        curr_med = min_heap.top();
        med.push_back(curr_med);
      }
    }
  }
  for(auto k : med) cout<<k<<endl;
}

int main()
{
	int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
	int size = sizeof(A)/sizeof(A[0]);
	printMedian(A, size);
	return 0;
}

