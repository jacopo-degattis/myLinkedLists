#include <iostream>
#include <stdlib.h>
#include "lib/linkedlist/linkedlist.h"

using namespace std;

void printRandom(node* value) {
  cout<<value->s->age<<"|";
}

int main() {

  student* s = new student;
  s->first_name = "Jack";
  s->last_name = "Test";
  s->age = 21;
  
  student* s1 = new student;
  s1->first_name = "Mario";
  s1->last_name = "Prova";
  s1->age = 20;

  student* s2 = new student;
  s2->first_name = "Luigi";
  s2->last_name = "Easy";
  s2->age = 15;

  LinkedList* list = new LinkedList();
  list->append(s);
  list->prepend(s2);
  list->append(s1);
  list->print();
  
  cout<<"=========="<<endl;
  
  cout<<"old get value "<<list->get(1)->first_name<<endl;

  student* new_student = new student;
  new_student->first_name = "SOS";
  new_student->last_name = "LOL";
  new_student->age = 45;

  list->set(1, new_student);
  
  cout<<"new get value "<<list->get(1)->first_name<<endl;
  
  cout<<"current arr size => "<<list->size()<<endl;
  
  LinkedList* reversed = list->reverse();
  
  cout<<"== reversed list == "<<endl;
  
  reversed->print();
      
  cout<<endl;
      
  reversed->remove(1);
  
  cout<<"after deletion"<<endl;
  
  reversed->print();
  
  cout<<"\n=== callback ==="<<endl;
  
  reversed->forEach(printRandom);
  
  cout<<"\n=== lambda callback ==="<<endl;
  
  reversed->forEach([](node* value) {
    cout<<value->s->age<<"|";
  });
  
  return 0;
}
