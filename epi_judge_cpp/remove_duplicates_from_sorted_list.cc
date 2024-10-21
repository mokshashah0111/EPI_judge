#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
using std::shared_ptr;

shared_ptr<ListNode<int>> RemoveDuplicates(const shared_ptr<ListNode<int>>& L) {
  shared_ptr<ListNode<int>> current = L;
  shared_ptr<ListNode<int>>result = current;
 

  while (current)
  {
    shared_ptr<ListNode<int>>current_next = current->next;
    while(current_next && current_next->data == current->data){
      current_next = current_next->next;
    }
    current->next = current_next;
    current= current_next;
  }
  return L;
  
  
  // TODO - you fill in here.
  return nullptr;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "remove_duplicates_from_sorted_list.cc",
                         "remove_duplicates_from_sorted_list.tsv",
                         &RemoveDuplicates, DefaultComparator{}, param_names);
}
