#include <memory>

#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;

bool areKeysinRange(const unique_ptr<BinaryTreeNode<int>>& tree, int lower_bound, int upper_bound){
  if(tree== nullptr) return true;
  else if((tree->data < lower_bound) ||( tree->data > upper_bound)){
    return false;
  }
  else{
    return (areKeysinRange(tree->left, lower_bound,tree->data) && areKeysinRange(tree->right, tree->data,upper_bound));
  }
}
bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  return areKeysinRange(tree, std::numeric_limits<int> ::min() , std::numeric_limits<int>::max());
  // return true;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_a_bst.cc", "is_tree_a_bst.tsv",
                         &IsBinaryTreeBST, DefaultComparator{}, param_names);
}
