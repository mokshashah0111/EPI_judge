#include "binary_tree_with_parent_prototype.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

int getLength(BinaryTreeNode<int>* node){
  int depth =0;
  while(node->parent){
    depth+=1;
  }
  return depth;
}
BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& node0,
                         const unique_ptr<BinaryTreeNode<int>>& node1) {
  // TODO - you fill in here.
  int depth0 = getLength(node0.get());
  int depth1 = getLength(node1.get());
  // if(node0->parent){
  //   depth0+=1;
  // }
  // else{
  //   Lca(node0,node1);
  // }
  // if(node1->parent){
  //   depth1+=1;
  // }
  // else{
  //   Lca(node0,node1);
  // }

  if(depth0==depth1){
    while(node0==node1){
      node0->parent;
      node1->parent;
    }
    return node0.get();
  }
  else{
    if(depth1 > depth0){
      while(depth1 == depth0){
        node1->parent;
        depth1--;
      }
    }
    else{
      node0->parent;
      depth0--;
    }
    while(depth0 == depth1){
      node0->parent;
      node1->parent;
    }
    return node0.get();
  }
  return nullptr;
}
int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return Lca(node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor_with_parent.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}
