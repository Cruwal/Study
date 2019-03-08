#include <iostream>
#include "ordenacao.h"

int main(int argc, char const *argv[]) {

  Ordenacao myOrder("numbersFile", 100000);

  myOrder.generateNumbers();
  myOrder.bubbleSort();
  myOrder.insertionSort();
  myOrder.mergeSort();

  return 0;
}
