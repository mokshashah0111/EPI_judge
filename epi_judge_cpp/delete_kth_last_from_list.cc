#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
using std::shared_ptr;

shared_ptr<ListNode<int>> reverseList(shared_ptr<ListNode<int>> head){
  shared_ptr<ListNode<int>> prev = nullptr;
  shared_ptr<ListNode<int>>next = nullptr;
  shared_ptr<ListNode<int>>current = head;

  while(current){
    next = current->next;
    current->next= prev;
    prev = current;
    current=next;
  }
  return prev;
}
// Assumes L has at least k nodes, deletes the k-th last node in L.
shared_ptr<ListNode<int>> RemoveKthLast(const shared_ptr<ListNode<int>>& L,
                                        int k) {
      shared_ptr<ListNode<int>>RL = reverseList(L);
      shared_ptr<ListNode<int>>current= RL;
      shared_ptr<ListNode<int>>result= current;
      int count=1;
      if(count==k){
        RL = RL->next;
        return reverseList(RL);
      }
      else{
        while(current && count!=k-1){
          current= current->next;
          count++;
        }
        if(current->next->next){
          current->next= current->next->next;
        }
        else{
          current->next= nullptr;
        }
        return reverseList(result);
      }
  // TODO - you fill in here.
  return nullptr;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "k"};
  return GenericTestMain(args, "delete_kth_last_from_list.cc",
                         "delete_kth_last_from_list.tsv", &RemoveKthLast,
                         DefaultComparator{}, param_names);
}
