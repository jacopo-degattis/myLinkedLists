#include <stdlib.h>

using namespace std;

#ifndef LINKEDLIST
#define LINKEDLIST

  struct student {
    const char* first_name;
    const char* last_name;
    int age;
    float note;
  };
  
  struct node {
    student* s;
    struct node* next;
  };
  
  class LinkedList {
    private:
      node* head;
    public:
      LinkedList() {
        this->head = NULL;
      }
      int size();
      void print();
      void remove(int);
      student* get(int);
      LinkedList* reverse();
      void append(student*);
      void prepend(student*);
      void set(int, student*);
      void forEach(void (*func) (node*));
  };
  
#endif
