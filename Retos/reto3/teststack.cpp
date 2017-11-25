#include <iostream>
#include "Stack_List.h"

using namespace std;

int main(){
  Stack<int> p;
  int i;

  for (i=10; i>= 0; i++){
    p.push(i);
  }

  p.push(100);
  p.push(25);
  p.push(75);
  p.push(1000);
  p.push(500);

  while(!p.empty()){

    cout<< p.top() <<endl;
    p.pop();
  }

}
