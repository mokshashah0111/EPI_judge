#include "binary_tree_node.h"
#include "test_framework/generic_test.h"

int sumHelper(const unique_ptr<BinaryTreeNode<int>>& root, int partial_path_sum){
  // int partial_path_sum = 0;
  if(!root) return 0;
  partial_path_sum = (partial_path_sum*2) +root->data;
  if(root->left== nullptr && root->right == nullptr) 
  {
    return partial_path_sum;
  }
  // if(!root->left) return partial_path_sum;
  // if(!root->right) return partial_path_sum;

  return sumHelper(root->left,partial_path_sum) + sumHelper(root->right,partial_path_sum);
}
int SumRootToLeaf(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  return sumHelper(tree,0);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "sum_root_to_leaf.cc", "sum_root_to_leaf.tsv",
                         &SumRootToLeaf, DefaultComparator{}, param_names);
}
