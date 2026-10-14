#include <iostream>
#include <vector>


int* HiSize (int count) {
  int* arr = new int[count];
  for (int i = 0; i < count; i++) {
    std::cin >> arr[i];
  }
  return arr;
}

int** MidSize (int*& ArrCount, int count) {
  int** arr = new int*[count];
  for (int i = 0; i < count; i++) {
    arr[i] = new int[ArrCount[i]];
    for (int j = 0; j < ArrCount[i]; j++) {
      std::cin >> arr[i][j];
    }
  }
  return arr;
}

int*** CreateMultyMatrix (int**& MatrixCount, int*& ArrCount, int count) {
  int*** arr = new int**[count];
  for (int i = 0; i < count; i++) {
    arr[i] = new int*[ArrCount[i]];
    for (int j = 0; j < ArrCount[i]; j++) {
      arr[i][j] = new int[MatrixCount[i][j]];
      for (int k = 0; k < MatrixCount[i][j]; k++) {
        std::cin >> arr[i][j][k];
      }
    }
  }
  return arr;
}

int SumMultyMatrix (int**& MatrixCount, int*& ArrCount, int count) {
  int sum = 0;
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < ArrCount[i]; j++) {
      sum += MatrixCount[i][j];
    }
  }
  return sum;
}

void* Buffer(int***& MultyMatrix, int**& MatrixCount, int*& ArrCount, int count,
             int typeLong) {
  int total = SumMultyMatrix(MatrixCount, ArrCount, count);
  int len = total * typeLong;
  void* compact = new char[len];
  int ptr = 0;
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < ArrCount[i]; j++) {
      for (int k = 0; k < MatrixCount[i][j]; k++) {
        std::memcpy((char*)compact + ptr, &MultyMatrix[i][j][k], typeLong);
        ptr += typeLong;
      }
    }
  }
  void** basket = new void*[7];
  basket[0] = compact;
  basket[1] = new int{typeLong};
  basket[2] = new int{total};
  basket[3] = ArrCount;
  basket[4] = MatrixCount;
  basket[5] = new int{count};
  basket[6] = nullptr;
  return basket;
}

void* UnpackBuffer(void* basketVoid) {
  void** basket = (void**)basketVoid;
  void* compact = basket[0];
  int typeLong = *(int*)basket[1];
  int* ArrCount = (int*)basket[3];
  int** MatrixCount = (int**)basket[4];
  int count = *(int*)basket[5];
  int*** MultyMatrix = new int**[count];
  int ptr = 0;
  for (int i = 0; i < count; i++) {
    MultyMatrix[i] = new int*[ArrCount[i]];
    for (int j = 0; j < ArrCount[i]; j++) {
      MultyMatrix[i][j] = new int[MatrixCount[i][j]];
      for (int k = 0; k < MatrixCount[i][j]; k++) {
        std::memcpy(&MultyMatrix[i][j][k], (char*)compact + ptr, typeLong);
        ptr += typeLong;
      }
    }
  }

  basket[6] = MultyMatrix;
  return basket;
}

void PrintMultyMatrix(int***& restoredMultyMatrix, int**& MatrixCount, int*& ArrCount, int count) {
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < ArrCount[i]; j++) {
      for (int k = 0; k < MatrixCount[i][j]; k++) {
        std::cout << restoredMultyMatrix[i][j][k] << " ";
      }
      std::cout << "\n";
    }
  }
}

int main() {
  // int*** используется для создания 3 мерного массива в котором мы можем хранить что угодно
  // void* используется для хранения метаданных этого массива то есть его размер размер его словев и строк а так же его сжатую версию для отправки(изначально все его массивы находились в разных кусках памяти но мы их все помпактно складываем и можем пересылать сразу с данными нужными для его распаковки, в нем хранятся типы int int* int** для этого и нужен void*)
  int count;
  std::cin >> count;
  int* ArrCount = HiSize(count);
  int** MatrixCount = MidSize(ArrCount, count);
  int*** MultyMatrix = CreateMultyMatrix(MatrixCount, ArrCount, count);
  int total = SumMultyMatrix(MatrixCount, ArrCount, count);
  std::cout << "Total elements: " << total << "\n\n";
  void* basket = Buffer(MultyMatrix, MatrixCount, ArrCount, count, 4);
  basket = UnpackBuffer(basket);
  int*** restoredMatrix = (int***)((void**)basket)[6];
  std::cout << "Restored matrix:\n";
  PrintMultyMatrix(restoredMatrix, MatrixCount, ArrCount, count);
  void** basketArr = (void**)basket;
  delete[] static_cast<char*>(basketArr[0]);
  delete (int*)basketArr[1];
  delete (int*)basketArr[2];
  delete (int*)basketArr[5];
  delete[] basketArr;
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < ArrCount[i]; j++) {
      delete[] MultyMatrix[i][j];
      delete[] restoredMatrix[i][j];
    }
    delete[] MultyMatrix[i];
    delete[] restoredMatrix[i];
    delete[] MatrixCount[i];
  }
  delete[] MultyMatrix;
  delete[] restoredMatrix;
  delete[] MatrixCount;
  delete[] ArrCount;
}


