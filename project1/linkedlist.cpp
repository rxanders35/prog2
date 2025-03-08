#include <cstdint>
#include <iostream>
#include <vector>

template <typename T> class LinkedList {
  struct Node {
    T data;
    Node *next;
    Node *prev;
  };

  Node *head;
  Node *tail;
  int node_count;

public:
  // Constructors
  LinkedList() {
    head = nullptr;
    tail = nullptr;
    node_count = 0;
  }

  LinkedList(const LinkedList<T> &other) {
    head = nullptr;
    tail = nullptr;
    node_count = 0;

    if (other.head == nullptr) {
      return;
    }

    head = new Node;
    head->data = other.head->data;
    head->next = nullptr;
    tail = head;
    node_count = 1;

    Node *curr = other.head->next;
    Node *recent = head;

    while (curr != nullptr) {
      Node *newNode = new Node;
      newNode->data = curr->data;
      newNode->next = nullptr;
      recent->next = newNode;
      recent = newNode;
      curr = curr->next;
      node_count++;
    }
    tail = recent;
    node_count = other.node_count;
  }

  ~LinkedList() {
    Node *curr = head;
    while (curr != nullptr) {
      Node *next = curr->next;
      delete curr;
      curr = next;
    }
    head = nullptr;
    tail = nullptr;
    node_count = 0;
  }
  // Behaviors
  void PrintForward() {
    Node *curr = head;
    while (curr != nullptr) {
      Node *next = curr->next;
      std::cout << curr->data << std::endl;
    }
  }

  void PrintReverse() {
    Node *curr = tail;
    while (curr != nullptr) {
      Node *prev = curr->prev;
      std::cout << curr->data << std::endl;
    }
  }

  void PrintForwardRecursive(Node *head) {
    if (head == nullptr) {
      return;
    }
    std::cout << head->data;
    PrintForwardRecursive(head->next);
  }

  void PrintReverseRecursive(Node *head) {
    if (head == nullptr) {
      return;
    }
    std::cout << tail->data;
    PrintForwardRecursive(tail->next);
  }
  // Accessors
  int NodeCount() { return this->node_count; }

  void FindAll(std::vector<int> &vectOUT, T val) {
    Node *curr = head;
    while (curr != nullptr) {
      Node *next = curr->next;
      if (next->data == val) {
        vectOUT.push_back(*next);
        // leave it this way for now
        // or it could be totally correct!
      }
    }
  }

  Node *Find(T val) {
    Node *curr = head;
    while (curr != nullptr) {
      bool found = false;
      Node *next = curr->next;
      if (next->data == val) {
        found = true;
        return *next;
      }
      if (!found) {
        return nullptr;
      }
      // leave it this way for now
      // or it could be totally correct!
    }
  }

  Node *GetNode(int idx) {
    Node *curr = head;
    if (curr != nullptr) {
      for (int i = 0; i < node_count; i++) {
        Node *next = curr->next;
        if (i == idx) {
          return *next;
          // THIS MIGHT WORK
        }
      }
    }
  }

  Node *GetNode(int idx) const {
    Node *curr = head;
    if (curr != nullptr) {
      for (int i = 0; i < node_count; i++) {
        Node *next = curr->next;
        if (i == idx) {
          return *next;
        }
      }
    }
  }

  Node *GetHead() { return *head; }
  Node *GetHead() const { return *head; }
  Node *GetTail() { return *tail; }
  Node *GetTail() const { return *tail; }

  // Insertions
  void AddHead(Node *newHead) {
    newHead->prev = nullptr;
    newHead->next = head;
    if (node_count != 0) {
      head->prev = newHead;
    }
  }

  void AddTail(Node *newTail) {
    newTail->next = nullptr;
    newTail->prev = tail;
    if (node_count != 0) {
      tail->next = newTail;
    }
  }

  void AddNodesHead(T arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
      Node n = {
          arr[i] // data
      };
      AddHead(n);
    }
  }

  void AddNodesTail(T arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
      Node n = {
          arr[i] // data
      };
      AddTail(n);
    }
  }

  void InsertAfter(Node *prev_node, T val) {
    Node n = {
        val // data
    };
    n->prev = prev_node;
    n->next = prev_node->next;
    prev_node->next = n;
    if (!n->GetTail()) {
      n->next->prev = n;
    }
  }

  void InsertBefore(Node *next_node, T val) {
    Node n = {
        val // data
    };
    n->prev = next_node->prev;
    n->next = next_node;
    if (!n->GetHead()) {
      n->prev->next = n;
    }
    next_node->prev = n;
  }
};