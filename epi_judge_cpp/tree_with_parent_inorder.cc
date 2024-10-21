#include <vector>

#include "binary_tree_with_parent_prototype.h"
#include "test_framework/generic_test.h"
using std::vector;

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree){
  // TODO - you fill in here.
  vector<int>result;
  const BinaryTreeNode<int>* current = tree.get();
  const BinaryTreeNode<int>* prev = nullptr;
  while(current){
    const BinaryTreeNode<int>* next = current->parent;
    if(current->parent==prev){
      if(current->left){
        next = current->left.get();
      }
      else{
        result.push_back(current->data);
        next = current->right ? current->right.get() : current->parent;
      }
    }
    else if(current->left.get() == prev){
      result.push_back(current->data);
      next = current->right ? current->right.get() : current->parent;
    }
    else{
      next = current->parent;
    }
    prev= current;
    current = next;
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_with_parent_inorder.cc",
                         "tree_with_parent_inorder.tsv", &InorderTraversal,
                         DefaultComparator{}, param_names);
}
