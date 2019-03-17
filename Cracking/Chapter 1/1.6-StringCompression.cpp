/* String Compression:
Implement a method to perfom basic string compression using the counts of repeated
characters.[...]. If the "compressed" string would not become smaller than the
original string, your method should return the original.

*/

#include <iostream>
#include <string>


std::string compressString(std::string inString){
  char auxString[inString.length() + 1]; //one more for \0
  int counter = 1;
  char c = inString[0];

  auxString[0] = c;
  int j = 1;
  for(int i = 1; i < inString.length() && j < inString.length(); i++) {
    if(inString[i] == c)
      counter++;
    else{
      auxString[j++] = '0' + counter;
      c = inString[i];
      auxString[j++] = c;
      counter = 1;
    }
  }

  if(j >= inString.length())
    return inString;
  else{
    std::string result(auxString, j);
    return result;
  }
}

int main(int argc, char const *argv[]) {
  std::string myString;

  std::cout << "Enter a string: ";
  std::cin >> myString;

  std::cout << "The string compressed: " << compressString(myString) << std::endl;

  return 0;
}
