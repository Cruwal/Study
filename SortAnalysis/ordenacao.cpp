#include <iostream>

#include "ordenacao.h"
#include <random>
#include <chrono>
#include <climits>

Ordenacao::Ordenacao( std::string inFileName, int inNumberOfIntegers ) : mFileName( inFileName ),
                                                              mNumberOfIntegers( inNumberOfIntegers ){
  mVecNumbers = nullptr;
}

void Ordenacao::generateNumbers(){
  std::fstream numbersFile;

  if( mFileName.empty() )
    numbersFile.open( "numbersFile", std::ios::trunc | std::ios::out );
  else
    numbersFile.open( mFileName, std::ios::trunc | std::ios::out );

  std::random_device rd;
  std::uniform_int_distribution<int> dist(0, mNumberOfIntegers);
  for( int i = 0; i < mNumberOfIntegers; i++)
    numbersFile << dist( rd ) << std::endl;

  if( mVecNumbers != nullptr )
    delete[] mVecNumbers;

  readNumbers();

  numbersFile.close();
}

// #############################################################################

void Ordenacao::readNumbers(){
  std::ifstream numbersFile;

  numbersFile.open( mFileName );
  if( numbersFile.fail() )
    exit( 1 );

  mVecNumbers = new int[ mNumberOfIntegers ];
  int number, i = 0;
  while ( numbersFile >> number )
    mVecNumbers[i++] = number;

  numbersFile.close();
}

void Ordenacao::writeInFile( std::ofstream& inFile, int *inVector ){
  for( int i = 0; i < mNumberOfIntegers; i++)
    inFile << inVector[i] << std::endl;

  inFile << std::endl;
}

int* Ordenacao::copyVector(){
  int *myVec = new int[ mNumberOfIntegers ];
  for(int i = 0 ; i < mNumberOfIntegers; i++)
    myVec[i] = mVecNumbers[i];

  return myVec;
}

// #############################################################################

void Ordenacao::bubbleSort( std::string inFileName, int printNumbers ){

  if( inFileName.empty() )
    inFileName = "bubbleSort";

  std::ofstream bubbleSortFile( inFileName );

  if( bubbleSortFile.fail() )
    exit(2);

  int *bubbleVec = copyVector();

  int aux;
  auto start = std::chrono::high_resolution_clock::now(); //Start time counter

  for( int i = 0; i < mNumberOfIntegers; i++)
    for( int j = 0; j < mNumberOfIntegers - i - 1; j++)
      if( bubbleVec[j] > bubbleVec[j + 1] ){
        aux = bubbleVec[j + 1];
        bubbleVec[j + 1] = bubbleVec[j];
        bubbleVec[j] = aux;
      }

  auto end = std::chrono::high_resolution_clock::now(); // ends time counter
  std::chrono::duration<double, std::milli> elapsed = end - start;

  if( printNumbers )
    writeInFile( bubbleSortFile, bubbleVec );

  bubbleSortFile << "Execution time: " << elapsed.count() << " ms" << std::endl;

  bubbleSortFile.close();
  delete[] bubbleVec;
}

// #############################################################################

void Ordenacao::insertionSort( std::string inFileName, int printNumbers ){

  if( inFileName.empty() )
    inFileName = "insertionSort";

  std::ofstream insertionSortFile( inFileName );
  if( insertionSortFile.fail() )
    exit(2);

  int *insertionVec = copyVector();

  int key, j;
  auto start = std::chrono::high_resolution_clock::now();

  for( int i = 1; i < mNumberOfIntegers; i++ ){
    j = i;
    key = insertionVec[j];

    while( j > 0 && key < insertionVec[j-1]){
      insertionVec[j] = insertionVec[j - 1];
      j--;
    }
    insertionVec[j] = key;
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsed = end - start;

  if( printNumbers )
    writeInFile( insertionSortFile, insertionVec );

  insertionSortFile << "Execution time: " << elapsed.count() << " ms" << std::endl;

  insertionSortFile.close();
  delete[] insertionVec;
}

// #############################################################################

void merge(int *vector, int start, int middle, int end){
  int *leftVector, *rightVector;
  int leftVectorSize, rightVectorSize;

  leftVectorSize = middle - start + 2;
  rightVectorSize = end - middle + 1;

  leftVector = new int[ leftVectorSize ];
  rightVector = new int[ rightVectorSize ];

  int i = 0;
  for( i = 0; i < leftVectorSize - 1; i++ )
    leftVector[i] = vector[start + i];
  leftVector[i] = INT_MAX;

  for( i = 0; i < rightVectorSize - 1; i++ )
    rightVector[i] = vector[middle + 1 + i];
  rightVector[i] = INT_MAX;

  int j = 0, k = 0;
  for( int i = start; i <= end; i++ ){
    if( j < leftVectorSize && leftVector[j] <= rightVector[k] )
      vector[i] = leftVector[j++];
    else if( k < rightVectorSize )
      vector[i] = rightVector[k++];
  }

  delete[] leftVector;
  delete[] rightVector;
}

void realMergeSort(int *vector, int start, int end){
  if( start < end ){
    int middle = (start + end) / 2;
    realMergeSort(vector, start, middle);
    realMergeSort(vector, middle + 1, end);
    merge(vector, start, middle, end);
  }
}


void Ordenacao::mergeSort(std::string inFileName, int printNumbers ){
  if( inFileName.empty() )
    inFileName = "mergeSort";

  std::ofstream mergeSortFile( inFileName );
  if( mergeSortFile.fail() )
    exit(2);

  int *mergeSortVec = copyVector();

  auto start = std::chrono::high_resolution_clock::now();
  realMergeSort( mergeSortVec, 0, mNumberOfIntegers - 1 );
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::milli> elapsed = end - start;

  if( printNumbers )
    writeInFile( mergeSortFile, mergeSortVec );

  mergeSortFile << "Execution time: " << elapsed.count() << " ms" << std::endl;

  mergeSortFile.close();
  delete[] mergeSortVec;
}
