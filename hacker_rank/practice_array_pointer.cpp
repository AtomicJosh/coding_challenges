#include<iostream>

int main(){
  int a[]={5,6,2,4,8,1,9};
  int *b;
  b = a;
  std::cout << *(b+2);
}
