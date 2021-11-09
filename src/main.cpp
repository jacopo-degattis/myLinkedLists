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

  return 0;
}
