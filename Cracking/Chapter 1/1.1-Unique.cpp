/* Is Unique: Implement  an algorithm to determine if a string has all Unique
characters. What if you cannot use an additional data structures?

O(1) for memory and O(n) for time

For solution without data structures:
space: O(1) because sort opertaes inplace
time: O(nlogn) because sort 

Another solution includes a hashtable
*/

#include <iostream>
#include <string>
#include <algorithm> // for sort;

bool isUnique(std::string inString){
  // considerando que são strings ASCII
  // Espaço não contabilizado

  int counter[256] = {0}; //Inicializando o vetor com zeros
  if(inString.length() > 256)
    return false;

  for(int i = 0; i < inString.length(); i++)
    if(++counter[inString[i]] > 1)
      return false;

  return true;
}

//without data structures
bool isUniqueWithoutData(std::string inString){
  if(inString.length() > 256)
    return false;

  std::sort(inString.begin(), inString.end());
  for(int i = 1; i < inString.length(); i++)
    if(inString[i - 1] == inString[i])
      return false;

  return true;
}

int main(int argc, char const *argv[]) {
  std::string myString;

  std::cout << "Digite a string: ";
  std::cin >> myString;
  std::cout << "Saída da funcao: " << isUnique(myString) << std::endl;
  std::cout << "Saída da função sem estrutura: " << isUniqueWithoutData(myString) << std::endl;

  return 0;
}
