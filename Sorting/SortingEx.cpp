#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <exception>
#include <set>
#include <map>

void printArray(std::vector<int> &arr) {
	int size = arr.size();
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << " ]\n";
}

void printArray2(std::vector<int> &arr, int size) {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << " ]\n";
}

void swap(std::vector<int> &arr, int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
    return;
}

int Partition01(std::vector<int> &arr) {
	int size = arr.size();
    int left = 0;
    int right = size - 1;
    int count = 0;
    while (left < right) {
        while (arr[left] == 0)
            left += 1;

        while (arr[right] == 1)
            right -= 1;

        if (left < right) {
            swap(arr, left, right);
            count += 1;
        }
    }
    return count;
}

void Partition012(std::vector<int> &arr) {
	int size = arr.size();
    int left = 0;
    int right = size - 1;
    int i = 0;
    while (i <= right) {
        if (arr[i] == 0) {
            swap(arr, i, left);
            i += 1;
            left += 1;
        } else if (arr[i] == 2) {
            swap(arr, i, right);
            right -= 1;
        } else {
            i += 1;
        }
    }
}

// Testing code
int main1() {
    std::vector<int> arr = { 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1 };
    Partition01(arr);
    printArray(arr);
    std::vector<int> arr2 = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    Partition012(arr2);
    printArray(arr2);
}

void RangePartition(std::vector<int> &arr, int lower, int higher) {
    int size = arr.size();
    int start = 0;
    int end = size - 1;
    int i = 0;
    while (i <= end) {
        if (arr[i] < lower) {
            swap(arr, i, start);
            i += 1;
            start += 1;
        } else if (arr[i] > higher) {
            swap(arr, i, end);
            end -= 1;
        } else {
            i += 1;
        }
    }
}

// Testing code
int main2() {
    std::vector<int> arr = { 1, 21, 2, 20, 3, 19, 4, 18, 5, 17, 6, 16, 7, 15, 8, 14, 9, 13, 10, 12, 11 };
    RangePartition(arr, 9, 12);
    printArray(arr);
}

int minSwaps(std::vector<int> &arr, int val) {
	int size = arr.size();
    int swapCount = 0;
    int first = 0;
    int second = size - 1;
    int temp;
    while (first < second) {
        if (arr[first] <= val)
            first += 1;
        else if (arr[second] > val)
            second -= 1;
        else {
            temp = arr[first];
            arr[first] = arr[second];
            arr[second] = temp;
            swapCount += 1;
        }
    }
    return swapCount;
}

void seperateEvenAndOdd(std::vector<int> &data) {
	int size = data.size();
    int left = 0, right = size - 1;
    while (left < right) {
        if (data[left] % 2 == 0)
            left++;
        else if (data[right] % 2 == 1)
            right--;
        else {
            swap(data, left, right);
            left++;
            right--;
        }
    }
}

bool AbsMore(int value1, int value2, int ref) {
    return (std::abs(value1 - ref) > std::abs(value2 - ref));
}

void AbsBubbleSort(std::vector<int> &arr, int ref) {
	int size = arr.size();
    for (int i = 0; i < (size - 1); i++) {
        for (int j = 0; j < (size - i - 1); j++) {
            if (AbsMore(arr[j], arr[j + 1], ref)) {
                swap(arr, j, j + 1);
            }
        }
    }
}

// Testing code
int main3() {
    std::vector<int> array = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
    int ref = 5;
    AbsBubbleSort(array, ref);
    printArray(array);
}

bool EqMore(int value1, int value2, int A) {
    value1 = A * value1 * value1;
    value2 = A * value2 * value2;
    return value1 > value2;
}

void ArrayReduction(std::vector<int> &arr) {
	int size = arr.size();
    std::sort(arr.begin(), arr.end());
    int count = 1;
    int reduction = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] - reduction > 0) {
            reduction = arr[i];
            count += 1;
        }
    }
    std::cout << "Total number of reductions " << count << std::endl ;
}

// Testing code
int main4() {
    std::vector<int> arr = { 5, 1, 1, 1, 2, 3, 5 };
    ArrayReduction(arr);
    return 0;
}
/*
 * void SortFrequency(std::vector<int> &arr) { HashMap<Integer,
 * Integer> ht = new HashMap<Integer, Integer>(); int value; for (int i = 0; i <
 * size; i++) { if (ht.containsKey(arr[i])) { ht.put(arr[i], ht.get(arr[i]) +
 * 1); } else { ht.put(arr[i], 1); } } ht.sort ht.SortFrequency(arr, size);
 * 
 * // User is recommended to write his own sorting function. // For convenience
 * author is using inbuilt functions.
 * 
 * for key,value in reversed(sorted(mp.iteritems(), key = lambda (k, v):(v,k))):
 * for i in range(value): print key ,
 * 
 * // Testing code arr = [2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12] SortFrequency(arr)
 * 
 */

void SortByOrder(std::vector<int> &arr, std::vector<int> &arr2) {
	int size = arr.size();
	int size2 = arr2.size();
    std::map<int, int> ht;
    int value;
    for (int i = 0; i < size; i++) {
        if (ht.find(arr[i]) != ht.end()) {
            value = ht[arr[i]];
            ht[arr[i]] = value + 1;
        } else {
            ht[arr[i]] = 1;
        }
    }

    for (int j = 0; j < size2; j++) {
        if (ht.find(arr2[j]) != ht.end()) {
            value = ht[arr2[j]];
            for (int k = 0; k < value; k++) {
                std::cout << arr2[j] << " ";
            }
            ht.erase(arr2[j]);
        }
    }

    for (int i = 0; i < size; i++) {
        if (ht.find(arr[i]) != ht.end()) {
            value = ht[arr[i]];
            for (int k = 0; k < value; k++) {
                std::cout << arr[i] << " ";
            }
            ht.erase(arr[i]);
        }
    }
    std::cout << std::endl;
}

// Testing code
int main5() {
    std::vector<int> arr = { 2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8 };
    std::vector<int> arr2 = { 2, 1, 8, 3 };
    SortByOrder(arr, arr2);
}

void merge(std::vector<int> &arr1, std::vector<int> &arr2) {
	int size1 = arr1.size();
	int size2 = arr2.size();

    int index = 0;
    while (index < size1) {
        if (arr1[index] <= arr2[0]) {
            index += 1;
        } else {
            // always first element of arr2 is compared.
            arr1[index] ^= arr2[0] ^= arr1[index] ^= arr2[0];
            index += 1;
            // After swap arr2 may be unsorted.
            // Insertion of the element in proper sorted position.
            for (int i = 0; i < (size2 - 1); i++) {
                if (arr2[i] < arr2[i + 1])
                    break;
                arr2[i] ^= arr2[i + 1] ^= arr2[i] ^= arr2[i + 1];
            }
        }
    }
}

// Testing code.
int main6() {
    std::vector<int> arr1 = { 1, 5, 9, 10, 15, 20 };
    std::vector<int> arr2 = { 2, 3, 8, 13 };
    merge(arr1, arr2);
    printArray(arr1);
    printArray(arr2);
}

bool checkReverse(std::vector<int> &arr) {
    int size = arr.size();
    int start = -1;
    int stop = -1;
    for (int i = 0; i < (size - 1); i++) {
        if (arr[i] > arr[i + 1]) {
            start = i;
            break;
        }
    }

    if (start == -1)
        return true;

    for (int i = start; i < (size - 1); i++) {
        if (arr[i] < arr[i + 1]) {
            stop = i;
            break;
        }
    }

    if (stop == -1)
        return true;

    // increasing property
    // after reversal the sub array should fit in the array.
    if (arr[start - 1] > arr[stop] || arr[stop + 1] < arr[start])
        return false;

    for (int i = stop + 1; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int min(int X, int Y) {
    if (X < Y) {
        return X;
    }
    return Y;
}

void UnionIntersectionSorted(std::vector<int> &arr1, std::vector<int> &arr2) {
    int size1 = arr1.size();
    int size2 = arr2.size();
    int first = 0, second = 0;
    std::vector<int> unionArr(size1 + size2, 0);
    std::vector<int> interArr(min(size1, size2), 0) ;
    int uIndex = 0;
    int iIndex = 0;

    while (first < size1 && second < size2) {
        if (arr1[first] == arr2[second]) {
            unionArr[uIndex++] = arr1[first];
            interArr[iIndex++] = arr1[first];
            first += 1;
            second += 1;
        } else if (arr1[first] < arr2[second]) {
            unionArr[uIndex++] = arr1[first];
            first += 1;
        } else {
            unionArr[uIndex++] = arr2[second];
            second += 1;
        }
    }

    while (first < size1) {
        unionArr[uIndex++] = arr1[first];
        first += 1;
    }

    while (second < size2) {
        unionArr[uIndex++] = arr2[second];
        second += 1;
    }
    printArray2(unionArr, uIndex);
    printArray2(interArr, iIndex);
}

void UnionIntersectionUnsorted(std::vector<int> &arr1, std::vector<int> &arr2) {
    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());
    UnionIntersectionSorted(arr1, arr2);
}

int main7() {
    std::vector<int> arr1 = { 1, 11, 2, 3, 14, 5, 6, 8, 9 };
    std::vector<int> arr2 = { 2, 4, 5, 12, 7, 8, 13, 10 };
    UnionIntersectionUnsorted(arr1, arr2);
    return 0;
}

int main()
{
	main1();
	main2();
	main3();
	main4();
	main5();
	main6();
	main7();
	return 0;
}