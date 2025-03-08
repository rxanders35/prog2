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

  int NodeCount() { return this->node_count; }

  void FindAll(std::vector<int> &vectOUT, int n) {}
};
