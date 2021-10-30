#include <stdlib.h>
#include <iostream>
// TODO: move utils function to utils.cpp
// #include "../utils.cpp"
#include "linkedlist.h"

// TODO: remove, just for testing purposes
using namespace std;

// Add to the end of the list
void LinkedList::append(student* s) {
  if (this->head == NULL) {
    node* temp = new node;
    temp->s = s;
    temp->next = NULL;
    this->head = temp;
  } else {
    node* temp = head;
    
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    
    node* new_node = new node;
    new_node->s = s;
    new_node->next = NULL;
    temp->next = new_node;
    
  }
}

// Add to the top of the list
void LinkedList::prepend(student* s) {
  if (this->head == NULL) {
    node* temp = new node;
    temp->s = s;
    temp->next = NULL;
    this->head = temp;
  } else {
    node* new_node = new node;
    new_node->s = s;
    new_node->next = head;
    head = new_node;
  }
}

student* LinkedList::get(int index) {
  int iter = 0;
  node* temp = this->head;
  
  while (temp != nullptr) {

    if (iter == index)
      return temp->s;
    
    temp = temp->next;
    iter++;
  }
  
  return NULL;
}

void LinkedList::set(int index, student* s) {
  int iter = 0;
  node* temp = this->head;
  
  while (temp != nullptr) {
    
    if (iter == index) {
      temp->s = s;
      return;
    }
    
    temp = temp->next;
    iter++;
  }
}

void LinkedList::remove(int index) {
  int counter = 0;
  node* temp = head;
  
  while (temp != nullptr) {

    if (counter == index-1) {
      
      // check length
      if (counter+1 == this->size()-1) {
        // in this case i'm removing the last item of the list
        delete temp->next;
        temp->next = NULL;
      } else if (counter+1 < this->size()-1) {
        // in this case i'm removing an elment in the middle
        node* next_node = temp->next->next;
        delete temp->next;
        temp->next = next_node;
      }
    }

    
    counter++;
    temp = temp->next;
  }
}

// or length ? or both ?
int LinkedList::size() {
  node* temp = head;
  int current_size = 0;
  
  while (temp != nullptr) {
    current_size++;
    temp = temp->next;
  }
  
  return current_size;
}

// TODO: return new LinkedLIst obj or apply edit on current object and void return ?
LinkedList* LinkedList::reverse() {
  // Reverse linked list
  
  node* temp = head;
  LinkedList* reversed = new LinkedList;
  
  while (temp != nullptr) {
    reversed->prepend(temp->s);
    temp = temp->next;
  }
  
  return reversed;
}

void LinkedList::print() {
  node* temp = this->head;

  while (temp != nullptr) {
    cout<<temp->s->first_name<<"_"<<temp->s->last_name<<"("<<temp->s->age<<")"<<endl;
    temp = temp->next;
  }
}
