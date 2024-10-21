#include "list_node.h"
#include "test_framework/generic_test.h"
shared_ptr<ListNode<int>> EvenOddMerge(const shared_ptr<ListNode<int>>& L) {
  if(!L) return nullptr;
  shared_ptr<ListNode<int>> even_head = L;
  shared_ptr<ListNode<int>> odd_head = L->next;
  shared_ptr<ListNode<int>> even = even_head;
  shared_ptr<ListNode<int>> odd = odd_head;

  while(odd && odd->next){
    even->next = odd->next;
    even = even->next;
    odd->next = even->next;
    odd = odd->next;
  }
  even->next = odd_head;
  return even_head;
  // TODO - you fill in here.
  return nullptr;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L"};
  return GenericTestMain(args, "even_odd_list_merge.cc",
                         "even_odd_list_merge.tsv", &EvenOddMerge,
                         DefaultComparator{}, param_names);
}
