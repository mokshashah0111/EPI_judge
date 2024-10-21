#include <string>
#include<sstream>

#include "test_framework/generic_test.h"
using std::string;
string ShortestEquivalentPath(const string& path) {
  // TODO - you fill in here.
  string result="";
  std::stringstream ss(path);
  string token="";
  std::stack<string>st;
  while(getline(ss,token,'/')){
    if(token == "" || token == "."){
      continue;
    }
    if(token != ".."){
      st.push(token);
    }
    else if(!st.empty()){
      st.pop();
    }
  }
  if(st.empty())return "/";
  while(!st.empty()){
    result = "/"+st.top()+result;
    st.pop(); 
  }
  return result;
  return "";
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"path"};
  return GenericTestMain(args, "directory_path_normalization.cc",
                         "directory_path_normalization.tsv",
                         &ShortestEquivalentPath, DefaultComparator{},
                         param_names);
}
