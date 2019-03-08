/*
Check Permutation: Given two strings, write a method to decide if one  is a
permutaton of the other

checkPermutation: time O(n), space O(1);

*/

#include <iostream>
#include <string>

bool checkPermutation(std::string inStringA, std::string inStringB){
  if(inStringA.length() != inStringB.length())
    return false;

  int counter[256]; // Assuming an ASCII string
  for(int i = 0; i < inStringA.length(); i++)
    counter[inStringA[i]]++;

  for(int i = 0; i < inStringB.length(); i++)
    if(--counter[inStringB[i]] < 0)
      return false;

  return true;
}

int main(int argc, char const *argv[]) {
  std::string firstString, secondString;

  std::cout << "Digite a primeira string: ";
  // getline for input with spaces
  std::getline(std::cin, firstString);
  std::cout << "Digite a segunda string: ";
  std::getline(std::cin, secondString);

  std::cout << "São permutações?: " << checkPermutation(firstString, secondString);
  std::cout << std::endl;

  return 0;
}
