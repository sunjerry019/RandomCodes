#include <bits/stdc++.h>

using namespace std;

int  _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

/* This function sorts the input array and returns the
   number of inversions in the array */
int mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid, inv_count = 0;
  if (right > left)
  {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;

    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);

    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}

/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
int merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  int inv_count = 0;

  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];

     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i);
    }
  }

  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];

  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];

  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}

int main()
{
    int n;
    char words[100000][11];
    vector<string> words2;
    map<string, int> wordsmap;
    int arr[100000];
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%s", words[i]);
        words2.push_back(string(words[i]));
        //cout << words2[i] << " ";
        transform(words2[i].begin(), words2[i].end(), words2[i].begin(), ::tolower);
        //cout << words2[i] << endl;
    }
    sort(words2.begin(), words2.end());
    for(int i=0;i<n;i++)
    {
        //cout << words2[i] << " " << i << endl;
        wordsmap[words2[i]] = i;
    }
    for(int i=0;i<n;i++)
    {
        string temp = string(words[i]);
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        arr[i] = wordsmap[temp];
    }
    printf("%d\n", mergeSort(arr, n));
    return 0;
}

/*int total = 0;
    for(int i=0;i<n;i++)
    {
        string a = string(words[i]);
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        for(int j=(i+1);j<n;j++)
        {
            string b = string(words[j]);
            transform(b.begin(), b.end(), b.begin(), ::tolower);
            if(a<b) total++;
        }
    }
    printf("%d", total);*/
