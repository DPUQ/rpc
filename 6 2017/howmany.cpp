/**
* Problem H: How many inversions?
* Status: YES
* Issue: Divide & Conquer (Merge sort)
*/

#include<bits/stdc++.h>
using namespace std;

long merge(long arr[], long temp[], long left, long mid, long right)
{
  long i, j, k;
  long inv = 0;
 
  i = left , j = mid, k = left;

  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
      inv = inv + (mid - i);
    }
  }
 
  while (i <= mid - 1)
    temp[k++] = arr[i++];

  while (j <= right)
    temp[k++] = arr[j++];

  for (i=left; i <= right; i++)
    arr[i] = temp[i];
 
  return inv;
}


long _mergeSort(long arr[], long temp[], long left, long right)
{
  long mid, inv = 0;
  if (right > left)
  {
    mid = (right + left)/2;
    inv  = _mergeSort(arr, temp, left, mid);
    inv += _mergeSort(arr, temp, mid+1, right);
    inv += merge(arr, temp, left, mid+1, right);
  }
  return inv;
}

long mergeSort(long arr[], long array_size)
{
    long *temp = (long *)malloc(sizeof(long)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}

int main(){
  long a[1000100];
  long n;
     while(cin >> n && n){
      	for(long  i=0; i < n; i++)
        	cin >> a[i];
       cout << mergeSort(a, n) << endl;
     }
	return 0;
}