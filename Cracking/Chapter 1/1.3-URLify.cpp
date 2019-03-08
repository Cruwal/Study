/*
URLify: Write a method to replace all spaces in a string with '%20'. You may
assume that the string has sufficient spaces at the end to hold the additional
characters, and that you are given the "true" length of the string.

time O(n), space O(1)

Obs.: the '\0' continues preserved at the and of string
*/

#include <iostream>
#include <string>

void URLify(std::string& inString, int size){de
  for(int i = inString.length() - 1; i >= 0; i--){
    inString[i] = inString[--size];

    if(inString[i] == ' '){
      inString[i--] = '0';
      inString[i--] = '2';
      inString[i] = '%';
    }
  }
}

int main(int argc, char const *argv[]) {
  std::string myString;
  int size;

  std::cout << "Digite a string: ";
  std::getline(std::cin, myString);
  std::cout << "Tamanho da string: ";
  std::cin >> size;

  URLify(myString, size);
  std::cout << "String URLified: " << myString << std::endl;

  return 0;
}
