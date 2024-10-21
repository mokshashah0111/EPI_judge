#include <string>

#include "test_framework/generic_test.h"
using std::string;
bool IsWellFormed(const string& s) {
  // TODO - you fill in here.
  std::stack<int>st;
  for(int i = 0; i<s.length() ; i++){
    if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
      st.push(s[i]);
    }
    else if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
      if(st.empty()){
        return false;
      }
      char c= st.top();
      st.pop();
      if((c=='(' && s[i] != ')') || (s[i] != ']' && c=='[') || (s[i]!='}' && c=='{')) {
        return false;
      }
    }
  }
  return st.empty();
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"s"};
  return GenericTestMain(args, "is_valid_parenthesization.cc",
                         "is_valid_parenthesization.tsv", &IsWellFormed,
                         DefaultComparator{}, param_names);
} 
