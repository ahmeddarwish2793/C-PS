#include <string>
#include <vector>

class GraphNode {
 public:
  GraphNode(std ::string label = "", int nr = -1)
      : label_{label}, node_nr_{nr} {}

  void add_undirected_edge(GraphNode* neighbor) {
    adj_list_.push_back(neighbor);
  }

  std::string label_;
  int node_nr_;
  std::vector<GraphNode*> adj_list_;  // meine Nachbarn
};

class Graph {
 public:
  std::vector<GraphNode> nodes_;
  int n_ = 0;  // #Knoten
  int m_ = 0;  // #Kanten

  void add_node(std::string label) { nodes_.push_back(GraphNode(label, n_++)); }
};

int main() {
  Graph vrr;

  vrr.add_node("Wanne-Eickel");
  vrr.add_node("Herne");
  // ...
}