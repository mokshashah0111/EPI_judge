#include <vector>
#include<queue>

#include "test_framework/generic_test.h"
using std::vector;

vector<int> KLargestInBinaryHeap(const vector<int>& A, int k) {
  // TOD<O - you fill in here.
  vector<int>result;
  std::priority_queue<int , vector<int>,std::greater<int>>minHeap;
  for(int i = 0 ; i<A.size() ; i++){
    if(minHeap.size() <k){
      minHeap.push(A[i]);
    }
    else if(A[i] > minHeap.top()){
      minHeap.pop();
      minHeap.push(A[i]);
    }
  }
  while(!minHeap.empty()){
    result.push_back(minHeap.top());
    minHeap.pop();
  }
  return result;
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "k_largest_in_heap.cc", "k_largest_in_heap.tsv",
                         &KLargestInBinaryHeap, UnorderedComparator{},
                         param_names);
}
