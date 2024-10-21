#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
#include<iostream>
struct BalanceHeight{
  int height;
  bool balanced;
};
BalanceHeight checkBalance(const unique_ptr<BinaryTreeNode<int>>& root){
  if(!root) return {true,-1};
  auto leftResult = checkBalance(root->left);
  if(!leftResult.balanced){
    return {false,0};
  }
  auto rightResult = checkBalance(root->right);
  if(!rightResult.balanced){
    return{false,0};
  }
  bool is_balanced = abs(leftResult.height - rightResult.height) <=1;
  // int max = leftResult.height < rightResult.height ? rightResult.height : leftResult.height;
  int height =std::max(leftResult.height,rightResult.height)+1;
  return {is_balanced,height};
}
bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.+
  return checkBalance(tree).balanced;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
