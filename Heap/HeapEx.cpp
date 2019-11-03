
#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <queue>
#include <functional> // for greater<int>
#include <exception>
#include <algorithm>
#include <cmath>

int main1() {

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;;
    int arr[] = { 1, 2, 10, 8, 7, 3, 4, 6, 5, 9 };
    int value;

    for (int i : arr) {
        pq.push(i);
    }
    
    std::cout << "\n Dequeue elements of Priority Queue ::";
    while (pq.empty() == false) {
    	value = pq.top(); 
		pq.pop();
        std::cout << " " << value;
    }
    return 0;
}

int KthSmallest(int arr[], int size, int k) {
    std::sort(arr, arr+size);
    return arr[k - 1];
}

int KthSmallest2(int arr[], int size, int k) {
    int i = 0;
    int value = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;;
    
    for (i = 0; i < size; i++) {
        pq.push(arr[i]);
    }
    i = 0;
    while (i < size && i < k) {
        value = pq.top(); 
		pq.pop();
        i += 1;
    }
    return value;
}

bool isMinHeap(int arr[], int size) {
    int lchild, rchild;
    // last element index size - 1
    for (int parent = 0; parent < (size / 2 + 1); parent++) {
        lchild = parent * 2 + 1;
        rchild = parent * 2 + 2;
        // heap property check.
        if (((lchild < size) && (arr[parent] > arr[lchild])) || ((rchild < size) && (arr[parent] > arr[rchild])))
            return false;
    }
    return true;
}

bool isMaxHeap(int arr[], int size) {
    int lchild, rchild;
    // last element index size - 1
    for (int parent = 0; parent < (size / 2 + 1); parent++) {
        lchild = parent * 2 + 1;
        rchild = lchild + 1;
        // heap property check.
        if (((lchild < size) && (arr[parent] < arr[lchild])) || ((rchild < size) && (arr[parent] < arr[rchild])))
            return false;
    }
    return true;
}

int main2() {
    int arr[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
    std::cout << "Kth Smallest :: " << KthSmallest(arr, 8, 3) << std::endl;
    int arr2[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
    std::cout << "Kth Smallest :: " << KthSmallest2(arr2, 8, 3) << std::endl;
    int arr3[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
    std::cout << "isMaxHeap :: " << isMaxHeap(arr3, 8) << std::endl;
    int arr4[] = { 8, 7, 6, 5, 7, 5, 2, 1 };

    std::cout << "isMinHeap :: " << isMinHeap(arr4, 8) << std::endl;
    std::sort(arr4, arr4 + sizeof(arr4)/sizeof(int));
    std::cout << "isMinHeap :: " << isMinHeap(arr4, 8) << std::endl;
    return 0;
}

int KSmallestProduct(int arr[], int size, int k) {
    std::sort(arr, arr+size);// , size, 1);
    int product = 1;
    for (int i = 0; i < k; i++)
        product *= arr[i];
    return product;
}

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void QuickSelectUtil(int arr[], int lower, int upper, int k) {
    if (upper <= lower)
        return;

    int pivot = arr[lower];

    int start = lower;
    int stop = upper;

    while (lower < upper) {
        while (lower < upper && arr[lower] <= pivot) {
            lower++;
        }
        while (lower <= upper && arr[upper] > pivot) {
            upper--;
        }
        if (lower < upper) {
            swap(arr, upper, lower);
        }
    }

    swap(arr, upper, start); // upper is the pivot position
    if (k < upper)
        QuickSelectUtil(arr, start, upper - 1, k); // pivot -1 is the upper for left sub array.
    if (k > upper)
        QuickSelectUtil(arr, upper + 1, stop, k); // pivot + 1 is the lower for right sub array.
}

int KSmallestProduct3(int arr[], int size, int k) {
    QuickSelectUtil(arr, 0, size - 1, k);
    int product = 1;
    for (int i = 0; i < k; i++)
        product *= arr[i];
    return product;
}

int KSmallestProduct2(int arr[], int size, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;;
    int i = 0;
    int product = 1;
    for (i = 0; i < size; i++) {
        pq.push(arr[i]);
    }
    i = 0;
    while (i < size && i < k) {
        product *= pq.top(); 
		pq.pop();
        i += 1;
    }
    return product;
}

int main3() {
    int arr[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
    std::cout << "Kth Smallest product:: " << KSmallestProduct(arr, 8, 3) << std::endl;
    int arr2[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
    std::cout << "Kth Smallest product:: " << KSmallestProduct2(arr2, 8, 3) << std::endl;
    int arr3[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
    std::cout << "Kth Smallest product:: " << KSmallestProduct3(arr3, 8, 3) << std::endl;
}

void PrintLargerHalf(int arr[], int size) {
    std::sort(arr, arr+size);// , size, 1);
    for (int i = size / 2; i < size; i++)
        std::cout << (arr[i]);
    std::cout << std::endl;
}

void PrintLargerHalf2(int arr[], int size) {
    int product = 1;
    int value;
    std::priority_queue<int, std::vector<int>, std::less<int>> pq;;
    for (int i = 0; i < size; i++) {
        pq.push(arr[i]);
    }
   	int half = size/2;
    for (int i = 0; i < half; i++){
    	value = pq.top(); 
		pq.pop();
    	std::cout << value;
    }   
    std::cout << std::endl;
}

void PrintLargerHalf3(int arr[], int size) {
    QuickSelectUtil(arr, 0, size - 1, size / 2);
    for (int i = size / 2; i < size; i++)
        std::cout << arr[i];
    std::cout << std::endl;
}

int main4() {
    int arr[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
    PrintLargerHalf(arr, 8);
    int arr2[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
    PrintLargerHalf2(arr2, 8);
    int arr3[] = { 8, 7, 6, 5, 7, 5, 2, 1 };
    PrintLargerHalf3(arr3, 8);
    return 0;
}

void sortK(int arr[], int size, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;;
    int i = 0;
    for (i = 0; i < size; i++) {
        pq.push(arr[i]);
    }

    int* output = new int[size];
    int index = 0;

    for (i = k; i < size; i++) {
        output[index++] = pq.top(); 
		pq.pop();
        pq.push(arr[i]);
    }
    while (pq.size() > 0)
        output[index++] = pq.top(); 
		pq.pop();

    for (i = k; i < size; i++) {
        arr[i] = output[i];
    }
    std::cout << output << std::endl;
}

// Testing Code
int main5() {
    int k = 3;
    int arr[] = { 1, 5, 4, 10, 50, 9 };
    int size = sizeof(arr)/sizeof(int);
    sortK(arr, size, k);
    return 0;
}

int ChotaBhim(int cups[], int size) {
    int time = 60;
    std::sort(cups, cups+size);
    int total = 0;
    int index, temp;
    while (time > 0) {
        total += cups[0];
        cups[0] = ceil(cups[0] / 2.0);
        index = 0;
        temp = cups[0];
        while (index < size - 1 && temp < cups[index + 1]) {
            cups[index] = cups[index + 1];
            index += 1;
        }
        cups[index] = temp;
        time -= 1;
    }
    std::cout << "Total : " << total << std::endl;
    return total;
}

int ChotaBhim2(int cups[], int size) {
    int time = 60;
    std::sort(cups, cups + size);
    int total = 0;
    int i, temp;
    while (time > 0) {
        total += cups[0];
        cups[0] = ceil(cups[0] / 2.0);
        i = 0;
        // Insert into proper location.
        while (i < size - 1) {
            if (cups[i] > cups[i + 1])
                break;
            temp = cups[i];
            cups[i] = cups[i + 1];
            cups[i + 1] = temp;
            i += 1;
        }
        time -= 1;
    }
    std::cout << "Total : " << total << std::endl;
    return total;
}

int ChotaBhim3(int cups[], int size) {
    int time = 60;
    std::priority_queue<int, std::vector<int>, std::less<int>> pq;;
    int i = 0;
    for (i = 0; i < size; i++) {
        pq.push(cups[i]);
    }

    int total = 0;
    int value;
    while (time > 0) {
        value = pq.top(); 
		pq.pop();
        total += value;
        value = std::ceil(value / 2.0);
        pq.push(value);
        time -= 1;
    }
    std::cout << "Total : " << total << std::endl;
    return total;
}

int JoinRopes(int ropes[], int size) {
    std::sort(ropes, ropes+size, std::greater<>());
    int total = 0;
    int value = 0;
    int temp, index;
    int length = size;

    while (length >= 2) {
        value = ropes[length - 1] + ropes[length - 2];
        total += value;
        index = length - 2;

        while (index > 0 && ropes[index - 1] < value) {
            ropes[index] = ropes[index - 1];
            index -= 1;
        }
        ropes[index] = value;
        length--;
    }
    std::cout << "Total : " << total << std::endl;
    return total;
}

int JoinRopes2(int ropes[], int size) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;;
    int i = 0;
    for (i = 0; i < size; i++) {
        pq.push(ropes[i]);
    }

    int total = 0;
    int value = 0;
    while (pq.size() > 1) {
        value = pq.top(); 
		pq.pop();
        value += pq.top(); 
		pq.pop();
        pq.push(value);
        total += value;
    }
    std::cout << "Total : " << total << std::endl;
    return total;
}

int main6() {
    int cups[] = { 2, 1, 7, 4, 2 };
    ChotaBhim(cups, 5);
    int cups2[] = { 2, 1, 7, 4, 2 };
    ChotaBhim2(cups2, 5);
    int cups3[] = { 2, 1, 7, 4, 2 };
    ChotaBhim3(cups3, 5);

    int ropes[] = { 2, 1, 7, 4, 2 };
    JoinRopes(ropes, 5);
    int rope2[] = { 2, 1, 7, 4, 2 };
    JoinRopes2(rope2, 5);
    return 0;
}

/*
    * int kthAbsDiff(int arr[], int size, int k) { Sort(arr, size,1);
    * int diff[1000]; int index = 0; for (int i = 0; i < size - 1; i++) { for (int
    * j = i + 1; j < size; j++) diff[index++] = abs(arr[i] - arr[j]); } Sort(diff,
    * index); return diff[k - 1]; }
    * 
    * int kthAbsDiff(int arr[], int size, int k) { Sort(arr, size, 1); Heap hp; int
    * value = 0;
    * 
    * for (int i = k + 1; i < size - 1; i++) HeapAdd(&hp,(abs(arr[i] - arr[i + 1]),
    * i, i + 1)); heapify(hp);
    * 
    * for (int i = 0; i < k; i++) { tp = heapq.heappop(hp); value = tp[0]; src =
    * tp[1]; dst = tp[2]; if (dst + 1 < size) heapq.heappush(hp, (abs(arr[src] -
    * arr[dst + 1]), src, dst + 1)); } return value; }
    * 
    * int main7() { int arr[] = { 1, 2, 3, 4 };
    * std::cout << "", kthAbsDiff(arr, 4, 5)); return 0; }
*/

int kthLargestStream(int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;;
    int size = 0;
    int data = 0;
    while (true) {
        std::cout << "Enter data: ";
        // data = System.in.read();

        if (size < k - 1)
            pq.push(data);
        else {
            if (size == k - 1)
                pq.push(data);
            else if (pq.top() < data) {
                pq.push(data);
		pq.pop();
            }
            std::cout << "Kth larges element is :: " << pq.top() << std::endl;
        }
        size += 1;
    }
}

int main8() {
    kthLargestStream(3);
    return 0;
}
/*
    * int minJumps(int arr[], int size) { int *jumps = (int
    * *)malloc(sizeof(int) * size); //all jumps to maxint. int steps, j; jumps[0] =
    * 0;
    * 
    * for (int i = 0; i < size; i++) { steps = arr[i]; // error checks can be added
    * hear. j = i + 1; while (j <= i + steps && j < size) { jumps[j] =
    * min(jumps[j], jumps[i] + 1); j += 1; } std::cout << "%s", jumps); }
    * return jumps[size - 1]; } int main2() { int arr[]
    * = {1, 4, 3, 7, 6, 1, 0, 3, 5, 1, 10}; std::cout << "%d", minJumps(arr,
    * sizeof(arr) / sizeof(int))); return 0; }
    */