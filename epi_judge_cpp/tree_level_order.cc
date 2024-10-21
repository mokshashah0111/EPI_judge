#include <memory>
#include <vector>
#include<queue>


#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
using std::unique_ptr;
using std::vector;

vector<vector<int>> BinaryTreeDepthOrder(
    const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  if(!tree) return {};
  std::queue<const BinaryTreeNode<int>*>q;
  vector<vector<int>>result;
  q.emplace(tree.get());
  while(!q.empty()){
    int levelsize = q.size();
    vector<int>currentLevel;
    for(int i = 0 ; i<levelsize ; i++){
      const BinaryTreeNode<int>*currentNode = q.front();   
      q.pop();
      currentLevel.push_back(currentNode->data);
      if(currentNode->left){
        q.emplace(currentNode->left.get());
      }
      if(currentNode->right){
        q.emplace(currentNode->right.get());
      }
    }
    result.push_back(currentLevel);
  }
  return result;
  return {};
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "tree_level_order.cc", "tree_level_order.tsv",
                         &BinaryTreeDepthOrder, DefaultComparator{},
                         param_names);
}
