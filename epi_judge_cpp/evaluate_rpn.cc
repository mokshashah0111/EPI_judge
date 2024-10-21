#include <string>

#include "test_framework/generic_test.h"
using std::string;
int Evaluate(const string& expression) {
  // TODO - you fill in here.
  std::stack<int>st;
  // int store_result;
  int i = 1;
  string currentNumber;
  string newExpression = expression;
  newExpression.erase(std::remove(newExpression.begin(), newExpression.end(),',') , newExpression.end());
  for(int i = 0 ; i<newExpression.length() ; i++){
    if(isdigit(newExpression[i])){
      currentNumber += newExpression[i];
    }
    else{
      if(!currentNumber.empty()){
        st.push(stoi(currentNumber));
        currentNumber.clear();
      }
      if(!st.empty()){

        int second = st.top();
        st.pop();
        int first = st.top();
        st.pop();

        switch(newExpression[i]){
          case '+':
            st.push(second+first);
            break;
          case '-':
            st.push(first - second);
            break;
          case 'x':
            st.push(first*second);
            break;
          case '/':
            st.push(first/second);
            break;
        }
      }
    }
  }
  if (!currentNumber.empty()) {
    st.push(std::stoi(currentNumber));
  }
  return st.top();
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"expression"};
  return GenericTestMain(args, "evaluate_rpn.cc", "evaluate_rpn.tsv", &Evaluate,
                         DefaultComparator{}, param_names);
}
