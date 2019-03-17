/* Zero Matrix:
Write an algorithm such that if an element in a MxN matrix is O, its entire row
and column are set to Zero


Space: O(1), time: O(MN)
*/

#include <iostream>
#include <random>

void printMatrix(int **matrix, int nRow, int nCol){
  for(int i = 0; i < nRow; i++){
    for(int j = 0; j < nCol; j++)
      std::cout << matrix[i][j] << " ";
    std::cout << std::endl;
  }
}

void clearCol(int **matrix, int pos, int nRow){
  for(int i = 0; i < nRow; i++)
    matrix[i][pos] = 0;
}

void clearRow(int **matrix, int pos, int nCol){
  for(int i = 0; i < nCol; i++)
    matrix[pos][i] = 0;
}

void setZero(int **matrix, int nRow, int nCol){
  bool zeroRow = false;
  bool zeroCol = false;

  //serching 0 in the first column
  for(int i = 0; i < nRow; i++)
    if(matrix[i][0] == 0){
      zeroCol = true;
      break;
    }

  //serching 0 in the first row
  for(int i = 0; i < nCol; i++)
    if(matrix[0][i] == 0){
      zeroRow = true;
      break;
    }

  for(int i = 1; i < nRow; i++)
    for(int j = 1; j < nCol; j++)
      if(matrix[i][j] == 0){
        matrix[0][j] = 0; //flag the position in the first row
        matrix[i][0] = 0; //and colmumn
      }

  for(int i = 0; i < nCol; i++)
    if(matrix[0][i] == 0)
      clearCol(matrix, i, nRow);

  for(int i = 0; i < nRow; i++)
    if(matrix[i][0] == 0)
      clearRow(matrix, i, nCol);

  if(zeroRow)
    clearRow(matrix, 0, nCol);

  if(zeroCol)
    clearCol(matrix, 0, nRow);

}

int main(int argc, char const *argv[]) {
  int row, col, **matrix;

  std::cout << "Digite a dimensao da linha: ";
  std::cin >> row;
  std::cout << "Digite a dimensao da coluna: ";
  std::cin >> col;

  matrix = new int* [row];
  for(int i = 0; i < row; i++)
    matrix[i] = new int[col];

  std::random_device rd;
  std::uniform_int_distribution<int> dist(0, 9); //Random matrix

  for(int i = 0; i < row; i++)
    for(int j = 0; j < col; j++)
      matrix[i][j] = dist( rd );

  printMatrix(matrix, row, col);

  setZero(matrix, row, col);
  std::cout << std::endl;

  printMatrix(matrix, row, col);


  for(int i = 0; i < row; i++)
    delete[] matrix[i];
  delete matrix;
  return 0;
}
