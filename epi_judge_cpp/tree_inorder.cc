#include <memory>
#include <vector>
#include<stack>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  std::stack<const BinaryTreeNode<int>*>st;
  const BinaryTreeNode<int>* current = tree.get();
  vector<int>result;
  while (current || !st.empty())
  {
    while(current){
      st.push(current);
      current = current->left.get();
    }
    current = st.top();
    st.pop();
    result.push_back(current->data);
    current = current->right.get(); 
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_inorder.cc", "tree_inorder.tsv",
                         &InorderTraversal, DefaultComparator{}, param_names);
}
