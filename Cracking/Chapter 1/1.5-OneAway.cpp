/* One Away:
There are three types of edits tha can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function
to check if they are on edit (or zero edits) away.

Solution: Space O(1)
          Time O(n)
*/

#include <iostream>
#include <string>


// go through the biggest string and verify if the character are differents.
bool lessThenTwoFunction(std::string bigger, std::string smaller){

  int nEdits = 0;
  for(int i = 0, j = 0; i < bigger.length(); i++, j++){
    if(bigger[i] != smaller[j]){
      // std::cout << "As strings são diferentes em: " << i << ", " << j << std::endl;
      nEdits++;
      if(nEdits > 1)
        return false;

      if(bigger.length() != smaller.length())
        j--;  //Doesn't change the position of the smaller string in the next comparison
              // if the strings have differents lentgths
    }

  }

  return true;
}

bool isLessThenTwoEdit(std::string inStringA, std::string inStringB){
  if(inStringA.length() > inStringB.length()){
    if(inStringA.length() - inStringB.length() < 2)
      return lessThenTwoFunction(inStringA, inStringB);
  }
  else if(inStringB.length() - inStringA.length() < 2)
    return lessThenTwoFunction(inStringB, inStringA);

  return false;
}

int main(int argc, char const *argv[]) {
  std::string stringA, stringB;

  std::cout << "Enter a string: ";
  std::cin >> stringA;

  std::cout << "Enter a second string: ";
  std::cin >> stringB;

  std::cout << "The string contains less then 2 edits? "
            << isLessThenTwoEdit(stringA, stringB) << std::endl;

  return 0;
}
