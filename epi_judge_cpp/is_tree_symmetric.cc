#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

bool symmetricHelp(const unique_ptr<BinaryTreeNode<int>>& left, unique_ptr<BinaryTreeNode<int>>& right){
  if(left==NULL || right == NULL){
    return left==right;
  }
  if(left->data != right->data){
    return false;
  }
  return (symmetricHelp(left->left , right->right) && symmetricHelp(left->right, right->left));
}
bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  return (tree==NULL || symmetricHelp(tree->left,tree->right));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_symmetric.cc", "is_tree_symmetric.tsv",
                         &IsSymmetric, DefaultComparator{}, param_names);
}
