#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> AddTwoNumbers(shared_ptr<ListNode<int>> L1,
                                        shared_ptr<ListNode<int>> L2) {
  // TODO - you fill in here.
  shared_ptr<ListNode<int>>current(new ListNode<int>);
  shared_ptr<ListNode<int>>result = current;
  int carry=0;
  int sum = 0;
  int value = 0;
  while(L1->next || L2->next || carry){
    sum = (L1 ? L1->data : 0) + (L2 ? L2->data : 0) + carry;
    carry = sum/10;
    value = sum%10;
    shared_ptr<ListNode<int>>newNode= make_shared<ListNode<int>>(value);
    result->next = newNode;
    result = result->next;

    L1 = L1 ? L1->next : nullptr;
    L2 = L2 ? L2->next : nullptr;
  }
  return current->next;
  return nullptr;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "int_as_list_add.cc", "int_as_list_add.tsv",
                         &AddTwoNumbers, DefaultComparator{}, param_names);
}
