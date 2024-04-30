#pragma once
#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <unordered_map>
#include <utility>
#include <vector>

struct Node
{
  // Change to map, letter is key

  /// @brief Used to store all nodes at any given time, each is mapped to a
  /// letter
  static std::unordered_map<char, std::shared_ptr<Node>> all_nodes;

  /// @brief the label of a node (eg node A, B what ever)
  char label;

  /// @brief The nodes this node is connected too, this graph is not
  /// directional. (each edge is represented as a bidirectional edge), dont
  /// write to this directly, use the helper methods
  std::vector<std::pair<std::shared_ptr<Node>, int>> adj;
  static std::shared_ptr<Node> create(char p_label)
  {
    auto new_node = std::make_shared<Node>(Node(p_label));
    new_node->label = p_label;
    all_nodes[p_label] = new_node;
    return nullptr;
  }

  /// @brief Adds an edge to the node. (Edges are represented as two directional
  /// edges from source to dest and dest to source), source being this
  /// @param dest The destination node to add to, creates the node if it doesn't
  /// exist
  /// @param weight The weight of this edge
  /// @throws invalid_argument if the destination ptr was not set, should never
  /// actually happen.
  void add_edge(char dest, int weight);

  /// @brief Removes an edge
  /// @param dest The node to remove from
  void remove_edge(char dest);

  /// @brief DO NOT USE, USE THE CREATE STATIC METHOD, THIS IS SUPPOSED TO BE
  /// PRIVATE BUT GCC IS BEING CRINGE AND IM LAZY!
  Node() = delete;
  Node(char p_label)
    : label(p_label){};
};
