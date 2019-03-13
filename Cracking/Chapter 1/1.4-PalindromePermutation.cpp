/* Palindrome Permutation:
Given a string, write a function to check if its a permutation of a palindrome.

Solution: space O(1), time O(n)
Obs.: The solution consider a case sensitive string, so T is different of t.
*/

#include <iostream>
#include <string>

#define ASCII 256

bool isPalindromePermutation(std::string inString){
  char counter[ASCII] = {0};  //supposing it's an ascii string

  for(char& c : inString)
    counter[c]++;

  int flag = 0;
  for(int i = 0; i < ASCII; i++ )
    if(counter[i] % 2 != 0){
      flag++;
      if(flag > 1)
        return false;
    }

  return true;
}

int main(int argc, char const *argv[]) {
  std::string myString;

  std::cout << "Enter a string: ";
  std::cin >> myString;

  std::cout << "This is a palindrome permutation?: "
                << isPalindromePermutation(myString) << std::endl;

  return 0;
}
