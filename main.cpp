#include "node.h"
#include <iostream>

int main()
{
  auto n = Node::create('A');
  n->add_edge('B', 2);
  auto n2 = n->all_nodes['B'];
  std::cout << (n->all_nodes == n2->all_nodes) << std::endl;
  return 0;
}