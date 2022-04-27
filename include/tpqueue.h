// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
  struct ITEM {
     T value;
     ITEM* next;
     ITEM* prev;
  };
  ITEM* head;
  ITEM* tail;
  TPQueue::ITEM* create(const T& value) {
     ITEM* item = new ITEM;
     item -> value = value;
     item -> next = nullptr;
     item -> prev = nullptr;
     return item;
  }

 public:
  TPQueue() {
     head = nullptr;
     tail = nullptr;
  }
  ~TPQueue() {
     while (head)
     pop();
  }
  void push(const T& value) {
     ITEM* item = create(value);
     ITEM* t = head;
     while (t && t->value.prior >= value.prior)
       t = t -> next;
     if (!t && !head) {
       head = tail = item;
     } else if (!t -> prev) {
       head -> prev = item;
       item -> next = head;
       head = item;
     } else if (!t && head) {
       tail -> next = item;
       item - >prev = tail;
       tail = item;
     } else {
       t -> prev -> next = item;
       item -> prev = t -> prev;
       item -> next = t;
       t -> prev = item;
     }
  }
  bool isEmpty() {
     if (!head || !tail) {
       return 1;
     } else {
       return 0;
     }
  }
  T pop() {
    if (isEmpty() == 1) {
       throw std::string("Empty!");
     }
     ITEM* t = head->next;
     if (t) {
       t -> prev = nullptr;
     }
     T value = head->value;
     delete head;
     head = t;
     if (!head) {
       tail = nullptr;
      }
      return value;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
