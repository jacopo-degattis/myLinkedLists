#include <iostream>
#include <stdlib.h>
#include "lib/linkedlist/linkedlist.h"

using namespace std;

int main() {
  LinkedList<int> int_list;

  int_list.append(10);
  int_list.append(1200);
  int_list.append(50);
  int_list.append(100);
  int_list.append(200);
  int_list.append(150);

  int_list.forEach([](int value) {
    cout<<"value => "<<value<<endl;
  });

  LinkedList<int> sliced_list = int_list.slice(1, 4);

  cout<<"\n* Sliced array \n"<<endl;
  sliced_list.forEach([](int value) {
    cout<<"value => "<<value<<endl;
  });
  
  cout<<"\n* Extend method \n"<<endl;
  
  // add constructor to support list = [1, 2, 3, 4, ...] or new List(1, 2, 3, 4, ...)
  
  LinkedList<int> original_list;
  original_list.append(1);
  original_list.append(2);
  original_list.append(13);
  
  LinkedList<int> other_list;
  other_list.append(14);
  other_list.append(15);
  other_list.append(26);
  
  cout<<"\n* Original list\n"<<endl;
  original_list.print();
  
  cout<<"\n* Exntend list\n"<<endl;
  other_list.print();
  
  original_list.extend(other_list);
  
  cout<<"\n* Original list after merge\n"<<endl;
  
  original_list.print();

  return 0;
}
