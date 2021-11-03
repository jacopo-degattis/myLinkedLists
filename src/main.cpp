#include <iostream>
#include <stdlib.h>
#include <cassert>
#include "lib/linkedlist/linkedlist.h"

using namespace std;

template <typename T>
void printRandom(node<T>* value) {
  cout<<value->s->age<<"|";
}

int main() {
  LinkedList<student>* list = new LinkedList<student>();

  student* s = new student;
  s->first_name = "Mario";
  s->last_name = "Rossi";
  s->age = 21;
  
  list->append(s);
  assert(list->size() == 1);
  
  student* s1 = new student;
  s1->first_name = "Luigi";
  s1->last_name = "Verdi";
  s1->age = 28;
  
  list->append(s1);
  assert(list->size() == 2);
  
  cout<<"* Original list\n"<<endl;
  list->print();
  
  cout<<"\n* Node in pos 1 (before set): "<<list->get(1)->first_name<<endl;
  assert(list->get(1) == s1);
  
  student* new_student = new student;
  new_student->first_name = "Giacomo";
  new_student->last_name = "Leopardi";
  new_student->age = 16;

  list->set(1, new_student);
  
  cout<<"* Node in pos 1 (after set): "<<list->get(1)->first_name<<endl;
  
  assert(list->size() == 2);
  
  cout<<"* Current list size => "<<list->size()<<endl;
  
  LinkedList<student>* reversed = list->reverse();
  
  cout<<"\n* Reversed list (bef. deletion)\n"<<endl;
  
  assert(reversed->get(0) == list->get(1));
  assert(reversed->get(1) == list->get(0));
  
  reversed->print();
            
  reversed->remove(1);
  
  cout<<"\n* Reversed list (aft. deletion)\n"<<endl;
  
  assert(reversed->get(0) == new_student);
  
  reversed->print();
  
  cout<<"\n* Age print with callback function\n"<<endl;
  
  reversed->forEach(printRandom);
  cout<<endl;
  
  cout<<"\n=== Age print with callback lambda function\n"<<endl;
  
  reversed->forEach([](node<student>* value) {
    cout<<value->s->age<<"|";
  });
  cout<<endl;
  
  cout<<"\n* Cloned list"<<endl;
  
  LinkedList<student>* cloned = reversed->clone();
  
  assert(cloned->get(0) == new_student);
  
  cloned->print();
  
  cout<<"\n* Is list empty\n"<<endl;
  
  cout<<"empty = "<<cloned->isEmpty()<<endl;
  
  return 0;
}
