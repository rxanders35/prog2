#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T> class LinkedList {
public:
  struct Node {
    T data;
    Node *next;
    Node *prev;
    Node() {
      next = nullptr;
      prev = nullptr;
    }
    Node(const T &val) {
      data = val;
      next = nullptr;
      prev = nullptr;
    }
  };

  Node *head;
  Node *tail;
  int node_count;
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
    if (other->head == nullptr) {
      return;
    }
    Node *other_curr = other->head;
    head = new Node(other_curr->data);
    tail = head;
    node_count = 1;
    other_curr = other_curr->next;
    while (other_curr != nullptr) {
      Node *new_node = new Node(other_curr->data);
      new_node->prev = tail;
      tail->next = new_node;
      tail = new_node;
      node_count++;
      other_curr = other_curr->next;
    }
  }

  ~LinkedList() { Clear(); }

  // Behaviors
  void PrintForward() {
    Node *curr = head;
    while (curr != nullptr) {
      std::cout << curr->data << std::endl;
      curr = curr->next;
    }
  }

  void PrintReverse() {
    Node *curr = tail;
    while (curr != nullptr) {
      std::cout << curr->data << std::endl;
      curr = curr->prev;
    }
  }

  void PrintForwardRecursive(Node *node) {
    if (node == nullptr) {
      return;
    }
    std::cout << node->data << std::endl;
    PrintForwardRecursive(node->next);
  }

  void PrintReverseRecursive(Node *node) {
    if (node == nullptr) {
      return;
    }
    std::cout << node->data << std::endl;
    PrintReverseRecursive(node->prev);
  }
  // Accessors
  int NodeCount() { return this->node_count; }

  void FindAll(std::vector<Node *> &vectOUT, T val) {
    Node *curr = head;
    while (curr != nullptr) {
      Node curr = curr->next;
      if (curr->data == val) {
        vectOUT.push_back(curr);
      }
      curr = curr->next;
    }
  }

  Node *Find(T val) {
    Node *curr = head;
    while (curr != nullptr) {
      if (curr->data == val) {
        return curr;
      }
      curr = curr->next;
      // leave it this way for now
      // or it could be totally correct!
    }
    return nullptr;
  }

  Node *GetNode(int idx) {
    if (idx < 0 || idx >= node_count) {
      throw std::out_of_range("idx out of range");
    }
    Node *curr = head;
    for (int i = 0; i < idx; i++) {
      curr = curr->next;
      // THIS MIGHT WORK
    }
    return curr;
  }

  const Node *GetNode(int idx) const {
    if (idx < 0 || idx >= node_count) {
      throw std::out_of_range("idx out of range");
    }
    Node *curr = head;
    for (int i = 0; i < idx; i++) {
      curr = curr->next;
      // THIS MIGHT WORK
    }
    return curr;
  }

  Node *GetHead() { return head; }
  const Node *GetHead() const { return head; }
  Node *GetTail() { return tail; }
  const Node *GetTail() const { return tail; }

  // Insertions
  void AddHead(T val) {
    Node *newHead = new Node(val);
    newHead->next = head;
    if (head != nullptr) {
      head->prev = newHead;
    }
    head = newHead;
    if (node_count == 0) {
      tail = newHead;
    }
    node_count++;
  }

  void AddTail(T val) {
    Node *newTail = new Node(val);
    newTail->prev = tail;
    if (tail != nullptr) {
      tail->next = newTail;
    }
    tail = newTail;
    if (node_count == 0) {
      tail = newTail;
    }
    node_count++;
  }

  void AddNodesHead(T arr[], int arr_size) {
    for (int i = arr_size - 1; i >= 0; i--) {
      AddHead(arr[i]);
    }
  }

  void AddNodesTail(T arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
      AddHead(arr[i]);
    }
  }

  void InsertAfter(Node *prev_node, T val) {
    if (prev_node == nullptr) {
      return;
    }
    Node *n = new Node(val);
    n->prev = prev_node;
    n->next = prev_node->next;
    prev_node->next = n;
    if (n->next != nullptr) {
      n->next->prev = n;
    } else {
      tail = n;
    }
    node_count++;
  }

  void InsertBefore(Node *next_node, T val) {
    if (next_node == nullptr) {
      return;
    }
    Node *n = new Node(val);
    n->next = next_node;
    n->prev = next_node->prev;
    n->prev->next = n;
    if (n->prev != nullptr) {
      next_node->prev = n;
    } else {
      head = n;
    }
    node_count++;
  }

  void InsertAt(int idx, T val) {
    if (idx < 0 || idx > node_count) {
      throw std::out_of_range("idx out of range");
    }
    if (idx == 0) {
      AddHead(tail);
      return;
    }
    Node *curr = GetNode(idx - 1);
    InsertAfter(curr, val);
  }

  // Removals

  bool RemoveHead() {
    if (head == nullptr) {
      return false;
    }
    Node *temp = head;
    head = head->next;
    if (head != nullptr) {
      head->prev = nullptr;
    } else {
      tail = nullptr;
    }
    delete temp;
    node_count--;
    return true;
  }

  bool RemoveTail() {
    if (tail == nullptr) {
      return false;
    }
    Node *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
    node_count--;
    return true;
  }

  int Remove(T val) {
    int num_removed = 0;
    Node *curr = head;
    while (curr != nullptr) {
      Node *next = curr->next;
      if (curr->data == val) {
        if (curr == head) {
          head = next;
        } else {
          curr->prev->next = next;
        }

        if (curr == tail) {
          tail = curr->prev;
        } else {
          next->prev = curr->prev;
        }
        delete curr;
        num_removed++;
        node_count--;
      }
      curr = next;
    }
    return num_removed;
  }

  bool RemoveAt(int idx) {
    if (idx < 0 || idx >= node_count) {
      return false;
      Node *curr = GetNode(idx);
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
      delete curr;
      return true;
    }
  }

  void Clear() {
    while (head != nullptr) {
      Node *next = head->next;
      delete head;
      head = next;
    }
    tail = nullptr;
    node_count = 0;
  }

  T &operator[](int idx) {
    if (idx < 0 || idx > node_count) {
      throw std::out_of_range("idx out of range");
    }
    return GetNode(idx)->data;
  }

  const T &operator[](int idx) const {
    if (idx < 0 || idx > node_count) {
      throw std::out_of_range("idx out of range");
    }
    return GetNode(idx)->data;
  }

  LinkedList<T> &operator=(const LinkedList<T> &other) {
    if (this != &other) {
      Clear();
      // the joy of helper functions!!!!
      Node *curr = other->head;
      while (curr != nullptr) {
        AddTail(curr->data);
        curr = curr->next;
      }
    }
    return *this;
  }

  bool operator==(const LinkedList<T> &other) const {
    if (node_count != other.node_count) {
      return false;
    }
    Node *curr = head;
    Node *other_curr = other_curr->head;
    while (curr != nullptr) {
      if (curr->data != other_curr->data) {
        return false;
      }
      curr = curr->next;
      other_curr = other_curr->next;
    }
    return true;
  }
};
