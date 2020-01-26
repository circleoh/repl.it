#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int> &arr, int start, int end)
{
  int pivot = arr[start], i=start+1, j=start;
  for (; i<=end; ++i) {
    if (arr[i] > pivot) {
      continue;
    } else {
    ++j;
    swap(arr[i], arr[j]);
    }
  }
  swap(arr[j], arr[start]);
  return j;
}

void quick_sort(vector<int> &arr, int start, int end)
{
  if (start < end) {
    int q = partition(arr, start, end);
    quick_sort(arr, start, q-1);
    quick_sort(arr, q+1, end);
  }
}

void QuickSort(vector<int> &arr, int left, int right)
{
  int pivot = arr[left]; int j=left, i=j+1;
  if (left < right) {
    for (; i<=right; ++i) {
      if (arr[i] < pivot) {
        ++j;
        swap(arr[i], arr[j]);
      }
    }
    swap(arr[j], arr[left]);
    
    QuickSort(arr, left, j-1);
    QuickSort(arr, j+1, right);
  }
}

void OriginalQuickSort(vector<int> &arr, int left, int right)
{
  if (left < right) {
    int pivot = arr[left], i=left+1, j=right;
    while (i < j) {
      while (i < right && arr[i] < pivot) ++i;
      while (j > left && arr[j] >= pivot) --j;
      if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[left]);
    
    OriginalQuickSort(arr, left, j-1);
    OriginalQuickSort(arr, j+1, right);
  }

}


int main()
{

  int num=0;
  vector<int> arr={4,1,5,2,3,7,2,3,6,3,1,8,1};
  
  OriginalQuickSort(arr, 0, arr.size()-1);
  for (auto i: arr) printf("%d ", i);
}
