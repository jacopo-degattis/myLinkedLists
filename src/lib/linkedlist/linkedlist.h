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
    bool operator == (const node* list_node) const {
      return (
        this->s->first_name == list_node->s->first_name &&
        this->s->last_name == list_node->s->last_name &&
        this->s->age == list_node->s->age &&
        this->s->note == list_node->s->note
      );
    }
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
      bool isEmpty();
      void remove(int);
      student* get(int);
      LinkedList* clone();
      // bool contains(node*);
      LinkedList* reverse();
      void append(student*);
      void prepend(student*);
      void set(int, student*);
      void forEach(void (*func) (node*));
  };
  
#endif
