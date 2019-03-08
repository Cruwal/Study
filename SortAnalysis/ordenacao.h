#ifndef _ORDENACAO_
#define _ORDENACAO_

#include <string>
#include <fstream>


// This class mantain a group of ordenation algorithms for performance analyis
class Ordenacao{
private:
  // std::fstream mNumbersFile;
  int mNumberOfIntegers;
  int *mVecNumbers;
  std::string mFileName;

  int *copyVector();
  void readNumbers();
  void writeInFile( std::ofstream& inFile, int *inVector );

public:
  // Ordenacao();
  Ordenacao(std::string inFileName = "", int inNumberOfIntegers = 1000);

  void generateNumbers();
  void bubbleSort( std::string = "", int printNumbers = 0 );
  void insertionSort( std::string = "", int printNumbers = 0 );
  void mergeSort( std::string = "", int printNumbers = 0 );


};


#endif
