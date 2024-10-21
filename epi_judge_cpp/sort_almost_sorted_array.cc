#include <vector>
#include<queue>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> SortApproximatelySortedData(
    vector<int>::const_iterator sequence_begin,
    const vector<int>::const_iterator& sequence_end, int k) {
  // TODO - you fill in here.
  vector<int>newVector(sequence_begin,sequence_end);
  vector<int>result;
  std::priority_queue<int,std::vector<int>,std::greater<int>>minHeap;
  int size = sequence_end - sequence_begin;
  for(int i = 0 ; i<size ; i++){
    if(minHeap.size() >=k){
      result.push_back(minHeap.top());
      minHeap.pop();
    }
    minHeap.push(newVector[i]);
  }
  while(!minHeap.empty()){
    result.push_back(minHeap.top());
    minHeap.pop();
  }
  return result;
  return {};
}
vector<int> SortApproximatelySortedDataWrapper(const vector<int>& sequence,
                                               int k) {
  return SortApproximatelySortedData(cbegin(sequence), cend(sequence), k);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sequence", "k"};
  return GenericTestMain(
      args, "sort_almost_sorted_array.cc", "sort_almost_sorted_array.tsv",
      &SortApproximatelySortedDataWrapper, DefaultComparator{}, param_names);
}
