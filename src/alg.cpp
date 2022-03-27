// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
  int EndOfArray = len - 1;
    while (arr[EndOfArray] > value) {
        EndOfArray -= 1;
    }
    int count = 0;
    for (int i = 0; i < EndOfArray - 1; i++) {
        for (int k = EndOfArray; k > i; k--) {
            if (arr[i] + arr[k] == value) {
                count += 1;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len; i++) {
        int low = i + 1;
        int up = len - 1;
        while (low < up) {
            int key = (low + up) / 2;
            if (arr[key] + arr[i] < value) {
                low = key + 1;
            } else {
                up = key;
            }
        }
        while (arr[low] + arr[i] == value) {
            count += 1;
            low += 1;
        }
    }
    return count;
}
