#include <iostream>
#include <time.h>
using namespace std;

int bubble(int* data, int size) {
  int swapCount = 0;
  for (int outer = 0; outer < size; outer++) {
    for (int inner = 0; inner < size-outer-1; inner++) {
      if (data[inner] > data[inner+1]) {
	swapCount++;
	int temp = data[inner+1];
	data[inner+1] = data[inner];
	data[inner] = temp;
      }
    }
  }
  return swapCount;
}

int sort(int size, bool print) {
  int* unsortedData = new int[size];
  int* sortedData = new int[size];
  for (int idx = 0; idx < size; idx++) {
    unsortedData[idx] = rand() % 100;
    sortedData[idx] = unsortedData[idx];
  }
  int swapCount = bubble(sortedData, size);
  if (print) {
    cout << "Bubble Sort (Swap Count " << swapCount << ")" << endl;
    for (int idx = 0; idx < size; idx++) {
      cout << "data[" << idx << "] = " << unsortedData[idx] << " - " << sortedData[idx] << endl;
    }
  }
  delete [] sortedData;
  delete [] unsortedData;
  return swapCount;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <size>" << endl;
    return 1;
  }
  srand (time(NULL));
  int size = atoi(argv[1]);
  cout << "Size: " << size << endl;

  float totalSwapCount = 0.0f;
  float iterationCount = 10000.0f;
  float maxSwapCount = std::numeric_limits<float>::min();
  float minSwapCount = std::numeric_limits<float>::max();
  
  for (int iteration = 0; iteration < iterationCount; iteration++) {
    float count = sort(size, false);
    if (count > maxSwapCount) {
      maxSwapCount = count;
    }
    if (count < minSwapCount) {
      minSwapCount = count;
    }
    totalSwapCount += count;
  }
  
  cout << "Bubble Sort:" << endl;
  cout << "# Iterations:    " << iterationCount << endl;
  cout << "# items to sort: " << size << endl;
  cout << "Total Swaps:     " << totalSwapCount << endl;
  cout << "Average Swaps:   " << totalSwapCount / iterationCount << endl;
  cout << "Min # swaps:     " << minSwapCount << endl;
  cout << "Max # swaps:     " << maxSwapCount << endl;
  return 0;
}
