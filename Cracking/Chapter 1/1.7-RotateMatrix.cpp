/* Rotate Matrix:
Given an image represented by a NxN matrix, where each pixel is 4 bytes, write
a method to rotate the image by 90 degrees.

Space: O(1), time: O(n^2)
Observation: it's necessary to adjust the coordinates in inner iteration.
So, for example, img[2][2] is the new img[0][0]. Execute a matrix 4x4.
*/

#include <iostream>

void printImg(int** img, int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++)
      std::cout << img[i][j] << " ";
    std::cout << std::endl;
  }
}

void rotateImg(int **img, int size){
  int min,  max, aux, correct;

  for (int start = 0; start < size/2; start++) {
    min = start;
    max = size - 1 - start;

    for(int i = 0 + start; i < max; i++){
      correct = i - start;
      //correcting the index for the inner matrix

      aux = img[min][i];
      img[min][i] = img[max - correct][min];
      img[max - correct][min] = img[max][max - correct];
      img[max][max - correct] = img[i][max];
      img[i][max] = aux;
    }
  }
}

int main(int argc, char const *argv[]) {
  int **img, size;

  std::cout << "Qual o tamanho da imagem?:  ";
  std::cin >> size;

  img = new int* [size];
  for(int i = 0; i < size; i++)
    img[i] = new int[size];

  int k = 0;
  for(int i = 0; i < size; i++)
    for(int j = 0; j < size; j++)
      img[i][j] = k++;

  printImg(img, size);
  std::cout << std::endl;

  rotateImg(img, size);
  printImg(img, size);

  for(int i = 0; i < size; i++)
    delete[] img[i];

  delete img;
  return 0;
}
