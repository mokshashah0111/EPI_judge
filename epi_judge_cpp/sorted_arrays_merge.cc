#include <vector>
#include<queue>
#include<tuple>
#include<functional>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
  // TODO - you fill in here.
  std::priority_queue<std::tuple<int,int,int>,vector<std::tuple<int,int,int>>,std::greater<std::tuple<int,int,int>>> minHeap;
  vector<int>result;
  for(int i = 0 ; i<sorted_arrays.size() ; i++){
    minHeap.emplace(sorted_arrays[i][0] , i,0);
  }
  while(!minHeap.empty()){

    auto [val,row,col] = minHeap.top();
    minHeap.pop();
    result.push_back(val);

    if(sorted_arrays[row].size() > col+1){
      minHeap.emplace(sorted_arrays[row][col+1],row,col+1);
    }
  }
  return result;
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sorted_arrays"};
  return GenericTestMain(args, "sorted_arrays_merge.cc",
                         "sorted_arrays_merge.tsv", &MergeSortedArrays,
                         DefaultComparator{}, param_names);
}
