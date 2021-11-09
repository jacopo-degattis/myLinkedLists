#include <iostream>
#include <stdlib.h>
#include "../utils.cpp"

using namespace std;

#ifndef LINKEDLIST
#define LINKEDLIST

  struct student {
    const char* first_name;
    const char* last_name;
    int age;
    float note;
  };
  
  template <typename T>
  struct node {
    // T* s;
    T s; // Removed * read line 32
    struct node<T>* next;
    bool operator == (const node<T>* list_node) const {
      return (
        this->s->first_name == list_node->s->first_name &&
        this->s->last_name == list_node->s->last_name &&
        this->s->age == list_node->s->age &&
        this->s->note == list_node->s->note
      );
    }
  };
  
  // Removed * from get, append and preprend
  // this way you can also add numbers directly from method
  // without pasing through variable
  
  // include a way to also add pointer ? yes or no ?
  
  template <class T>
  class LinkedList {
    private:
      node<T>* head;
    public:
      LinkedList();
      int size();
      void print();
      bool isEmpty();
      void remove(int);
      T get(int);
      LinkedList<T>* clone();
      bool contains(T*);
      LinkedList<T>* reverse();
      void append(T);
      void prepend(T);
      void set(int, T);
      void forEach(void (*func)(T));
      LinkedList<T> slice(int, int);
  };
  
  template <class T>
  LinkedList<T>::LinkedList() {
    this->head = NULL;
  }
  
  template <class T> 
  // Add to the end of the list
  void LinkedList<T>::append(T s) {
    if (this->head == NULL) {
      node<T>* temp = new node<T>;
      temp->s = s;
      temp->next = NULL;
      this->head = temp;
    } else {
      node<T>* temp = head;
      
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      
      node<T>* new_node = new node<T>;
      new_node->s = s;
      new_node->next = NULL;
      temp->next = new_node; 
    }
  }

  // Split array in sub-arrays
  template <class T>
  LinkedList<T> LinkedList<T>::slice(int start, int end) {
    int counter = 0;
    node<T>* temp = this->head;
    LinkedList<T> sliced_list;

    while (temp != nullptr) {
      if (counter >= start && counter <= end) {
        sliced_list.append(temp->s);
      }
      
      temp = temp->next;
      counter++;
    }

    return sliced_list;
  }
  
  template <class T>
  // this parameter is an address to callback function that take one parameter of type node (current node)
  void LinkedList<T>::forEach(void (*func)(T)) {
    // callback is a function
    // T result = NULL;
    node<T>* temp = head;
    
    while (temp != nullptr) {
      // result = func(temp);
      func(temp->s);
      temp = temp->next;
    }
    
    // return result;
  }
    
  template <class T>
  bool LinkedList<T>::contains(T* s) {
    bool found = false;
    node<T>* temp = this->head;
    
    while (temp != nullptr) {
    
      if (temp->s == s) {
        found = true;
        break;
      }
    
      temp = temp->next;
    }
    
    return found;
  }
  
  template <class T>
  // Add to the top of the list
  void LinkedList<T>::prepend(T s) {
    if (this->head == NULL) {
      node<T>* temp = new node<T>;
      temp->s = s;
      temp->next = NULL;
      this->head = temp;
    } else {
      node<T>* new_node = new node<T>;
      new_node->s = s;
      new_node->next = head;
      head = new_node;
    }
  }
  
  template <class T>
  T LinkedList<T>::get(int index) {
    int iter = 0;
    node<T>* temp = this->head;
    
    if (index > this->size()-1) {
      throw std::invalid_argument("index is greater than list length");
    }
    
    while (temp != nullptr) {
  
      if (iter == index)
        return temp->s;
      
      temp = temp->next;
      iter++;
    }
    
    return -1;
  }
  
  template <class T>
  LinkedList<T>* LinkedList<T>::clone() {
    node<T>* temp = this->head;
    LinkedList* cloned = new LinkedList;
    
    while (temp != nullptr) {
      cloned->append(temp->s);
      temp = temp->next;
    }
    
    return cloned;
  }
  
  template <class T>
  void LinkedList<T>::set(int index, T s) {
    int iter = 0;
    node<T>* temp = this->head;
    
    while (temp != nullptr) {
      
      if (iter == index) {
        temp->s = s;
        return;
      }
      
      temp = temp->next;
      iter++;
    }
  }
  
  // bool LinkedList::contains(node* item) {
    
  //   // TODO: add direct return value from forEach
  //   this->forEach([item](node* value) {
  //     if (value == item) return true;
  //   });
    
  //   return false;
  // }
  
  template <class T>
  bool LinkedList<T>::isEmpty() {
    return this->size() == 0;
  }
  
  template <class T>
  void LinkedList<T>::remove(int index) {
    int counter = 0;
    node<T>* temp = head;
    
    if (this->size() == 1) {
      delete temp;
    } else {
      while (temp != nullptr) {
    
        if (counter == index-1) {
          
          // check length
          if (counter+1 == this->size()-1) {
            // in this case i'm removing the last item of the list
            delete temp->next;
            temp->next = NULL;
          } else if (counter+1 < this->size()-1) {
            // in this case i'm removing an elment in the middle
            node<T>* next_node = temp->next->next;
            delete temp->next;
            temp->next = next_node;
          }
        }
        
        counter++;
        temp = temp->next;
      }
    }
  }
  
  template <class T>
  // or length ? or both ?
  int LinkedList<T>::size() {
    node<T>* temp = head;
    int current_size = 0;
    
    while (temp != nullptr) {
      current_size++;
      temp = temp->next;
    }
    
    return current_size;
  }
  
  template <class T>
  // TODO: return new LinkedLIst obj or apply edit on current object and void return ?
  LinkedList<T>* LinkedList<T>::reverse() {
    // Reverse linked list
    
    node<T>* temp = head;
    LinkedList* reversed = new LinkedList;
    
    while (temp != nullptr) {
      reversed->prepend(temp->s);
      temp = temp->next;
    }
    
    return reversed;
  }

  template <class T>
  void LinkedList<T>::print() {
    node<T>* temp = this->head;
    
    while (temp != nullptr) {
      
      cout<<"|"<<temp->s;
      
      temp = temp->next;
    }
    cout<<"|"<<endl;
  }

  // template <class T>
  // TODO: this print is specific for struct
  // TODO: how to adapt base on data type 
  // void LinkedList<T>::print() {
  //   node<T>* temp = this->head;
  
  //   while (temp != nullptr) {
  //     cout<<"|"<<temp->s->first_name<<"_"<<temp->s->last_name<<"("<<temp->s->age<<")";
  //     temp = temp->next;
  //   }
  //   cout<<"|"<<endl;
  // }
  
#endif
