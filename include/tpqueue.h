// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue{
 private:
struct ITEM {
    T value;
    ITEM* next;
};
ITEM* first;
ITEM* last;

 public:
    TPQueue() {
      first = nullptr;
      last = nullptr;
    }
    void push(T _val) {
      ITEM* tail = first;
      if (tail != nullptr) {
        ITEM* t = new ITEM;
        t -> value = _val;
        if (first->value.prior < t -> value.prior) {
          t -> next = last;
          first = t;
        }
        while (last != nullptr) {
          if ((last -> value.prior == t -> value.prior &&
            (last -> next == nullptr
            || last -> next -> value.prior < t -> value.prior)) ||
            (last -> value.prior > t -> value.prior &&
            ((last -> next != nullptr &&
            last -> next -> value.prior < t -> value.prior)
            || (last -> next == nullptr)))) {
            t -> next = last -> next;
            last -> next = t;
            return;
          }
          last = last -> next;
        }
      } else {
        last = new ITEM;
        first = last;
        last -> value = _val;
        last -> next = nullptr;
      }
    }
    T pop() {
      ITEM* t = first;
      first = first -> next;
      return (t -> value);
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
