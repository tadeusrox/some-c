#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* rotateArray(int* array, int length) {
  int* dup = calloc(length, sizeof(int));

  for(int i = 0; i <= length; i++) {
    dup[length - i] = array[i];
  }

  return dup;
}

int checkArrayEqual(int* array1, int* array2, int length) {
  int diff = length;

  for(int i = 0; i <= length; i++) {
    if(array1[i] == array2[i]) {
      diff--;
    }
  }

  return diff;
};

int checkArrayInverse(int* array1,  int* array2, int length) {
  return 0;
}

void testRotateArray() {
  srand(time(NULL));
  int length = rand() % 100 + 1;
  int* array = calloc(length, sizeof(int));

  for(int i = 0; i <= length; i++) {
    array[i] = rand();
  }

  int* rotatedArray = rotateArray(array, length);

  if(checkArrayEqual(array, rotatedArray, length) == 0) {
    printf("rotate array fail -> array not rotated\n");
  }

  if(checkArrayEqual(rotatedArray, rotateArray(rotatedArray, length), length) == 0) {
    printf("rotate array fail -> array rotated twice\n");
  }

  if(checkArrayInverse(rotatedArray, array, length) != 0) {
    printf("rotate array fail\n");
  }

  free(array);
  free(rotatedArray);
}

int main() {
  testRotateArray();

  return 0;
}
