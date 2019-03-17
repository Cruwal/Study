/* String Rotaion:
Assume you have a method isSubstring wich checks if one word is substring of
another. Given two strings, s1 and s2, write code to check if s2 is a rotation
of s1 using one call to isSubstring (e.g., "waterbottle" is a rotation of
"erbottlewat")

*/

#include <iostream>
#include <string>

bool isRotation(std::string s1, std::string s2){
  if(s1.length() != s2.length())
    return false;

  std::string aux = s1 + s1;

  //isSubstring
  std::size_t found = aux.find(s2);
  if(found != std::string::npos)
    return true;
  else
    return false;
}

int main(int argc, char const *argv[]) {
  std::string s1, s2;

  std::cout << "Enter s1 string: ";
  std::cin >> s1;

  std::cout << "Enter s2 string: ";
  std::cin >> s2;

  std::cout << std::endl;

  if(isRotation(s1, s2))
    std::cout << "Is a rotation" << std::endl;
  else
    std::cout << "Isn't a rotation" << std::endl;

  return 0;
}
