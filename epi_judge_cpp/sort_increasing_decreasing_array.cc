#include <vector>
#include<queue>
#include<tuple>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> SortKIncreasingDecreasingArray(const vector<int>& A) {
  // TODO - you fill in here.

  std::priority_queue<std::tuple<int ,int ,int>,vector<std::tuple<int,int,int>>,std::greater<std::tuple<int ,int ,int>>>minHeap;
  vector<vector<int>>sorted_array;
  vector<int>result;
  bool isIncreasing= true;
  int start = 0;

  for(int i = 1 ; i< A.size() ; i++){
    if(isIncreasing && A[i-1] > A[i]){
      sorted_array.emplace_back(A.begin()+start, A.begin()+i);
      isIncreasing = false;
      start = i;
    }
    else if(!isIncreasing && A[i-1] < A[i]){
      vector<int>decreasingSegment(A.begin()+start , A.begin()+i);
      std::reverse(decreasingSegment.begin(), decreasingSegment.end());
      sorted_array.emplace_back(decreasingSegment);
      start = i;
      isIncreasing = true;
    }
  }
  if(isIncreasing){
    sorted_array.emplace_back(A.begin()+start , A.end());
  }
  else{
    vector<int>decreasingSegment(A.begin()+start , A.end());
    std::reverse(decreasingSegment.begin(), decreasingSegment.end());
    sorted_array.emplace_back(decreasingSegment);
  }
  for(int i = 0; i<sorted_array.size() ; i++){
    minHeap.emplace(sorted_array[i][0] , i , 0);
  }
  while(!minHeap.empty()){
    auto[val,row,col] = minHeap.top();
    minHeap.pop();
    result.push_back(val);

    if(sorted_array[row].size() > col+1){
      minHeap.emplace(sorted_array[row][col+1] , row,col+1);
    }
  }
  return result;
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "sort_increasing_decreasing_array.cc",
                         "sort_increasing_decreasing_array.tsv",
                         &SortKIncreasingDecreasingArray, DefaultComparator{},
                         param_names);
}
