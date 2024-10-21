#include <memory>

#include "list_node.h"
#include "test_framework/generic_test.h"
using std::shared_ptr;

int lengthList(shared_ptr<ListNode<int>>L){
  shared_ptr<ListNode<int>> current = L;
  int length = 1;
  while(current->next){
    current= current->next;
    length++;
  }
  return length;
}
shared_ptr<ListNode<int>> CyclicallyRightShiftList(shared_ptr<ListNode<int>> L,
                                                   int k) {
  if(!L)return nullptr;
  shared_ptr<ListNode<int>> tail = L;
  int length = 1;

  while(tail->next){
    tail = tail->next;
    length++;
  }
  if(k%length == 0 || k==0)return L;
  k = k%length;
  tail->next= L;
  shared_ptr<ListNode<int>> new_tail = tail;
  int new_steps = length-k;
  while(new_steps--){
    new_tail= new_tail->next;
  }
  shared_ptr<ListNode<int>>new_head = new_tail->next;
  new_tail->next = nullptr;
  return new_head;
  
  // TODO - you fill in here.
  // return nullptr;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "k"};
  return GenericTestMain(
      args, "list_cyclic_right_shift.cc", "list_cyclic_right_shift.tsv",
      &CyclicallyRightShiftList, DefaultComparator{}, param_names);
}
