// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct ITEM {
     T value;
     ITEM* next;
     ITEM* prev;
  };
  ITEM* head, * tail;
  TPQueue::ITEM* create(const T& value) {
     ITEM* item = new ITEM;
     item -> value = value;
     item -> next = nullptr;
     return item;
  }

 public:
  TPQueue() {
     head = tail = nullptr;
  }
  ~TPQueue() {
     while (head) {
       rmHead();
     }
  }
  void push(const T& value) {
     ITEM* t = head;
     ITEM* item = create(value);
     while (t && t -> value.prior >= value.prior) {
       t = t -> next;
     }
     if (!t && head) {
       tail -> next = item;
       item -> prev = tail;
       tail = item;
     } else if (!t && !head) {
       head = tail = item;
     } else if (!t -> prev) {
       head -> prev = item;
       item -> next = head;
       head = item;
     } else {
       t -> prev -> next = item;
       item -> prev = t->prev;
       item -> next = t;
       t -> prev = item;
     }
  }
  T rmHead() {
     if (head) {
       ITEM* temp = head −> next;
       T data = head −> value;
       delete head;
       head = temp;
       return value;
     }
  }
  T pop() {
    if (head) {
      rmHead();
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
