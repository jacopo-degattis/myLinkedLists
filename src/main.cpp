#include <iostream>
#include <stdlib.h>
#include "lib/linkedlist/linkedlist.h"

using namespace std;

int main() {
  LinkedList<int> int_list;

  int_list.append(10);
  int_list.append(1200);

  int_list.forEach([](int value) {
    cout<<"value => "<<value<<endl;
  });

  return 0;
}
