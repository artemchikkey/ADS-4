// Copyright 2021 NNTU-CS
#include <iostream>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right) {
        if (arr[left] + arr[right] == value) {
            count++;
            left++;
            right--;
        } else if (arr[left] + arr[right] < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
int binarySearch(int *arr, int left, int right, int value) {
    int count = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count++;
            int temp = mid - 1;
            while (temp >= 0 && arr[temp] == value) {
                count++;
                temp--;
            }
            temp = mid + 1;
            while (temp < right && arr[temp] == value) {
                count++;
                temp++;
            } 
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        count += binarySearch(arr, i + 1, len - 1, value - arr[i]);
    }
    return count;
}
