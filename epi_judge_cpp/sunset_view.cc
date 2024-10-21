#include <iterator>
#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> ExamineBuildingsWithSunset(
    vector<int>::const_iterator sequence_begin,
    const vector<int>::const_iterator& sequence_end) {
  // TODO - you fill in here.
  vector<int>result;
  std::stack<std::pair<int,int>>st;
  vector<int>building(sequence_begin,sequence_end);
  for(int i = 0 ; i<building.size() ; i++){
    while(!st.empty() && building[i] >= st.top().first){
      st.pop();
    }
    st.push({building[i],i});
  }
  while(!st.empty()){
    result.push_back(st.top().second);
    st.pop();
  }
  return result;
  return {};
}
vector<int> ExamineBuildingsWithSunsetWrapper(const vector<int>& sequence) {
  return ExamineBuildingsWithSunset(cbegin(sequence), cend(sequence));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"sequence"};
  return GenericTestMain(args, "sunset_view.cc", "sunset_view.tsv",
                         &ExamineBuildingsWithSunsetWrapper,
                         DefaultComparator{}, param_names);
}
