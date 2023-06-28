#include <iostream>
#include <vector>
using namespace std;

int midPosition(int start, int end)
{

    return ((start + end) / 2);
}

void merge(vector<int> &array, int start, int end)
{
    int i = start;
    int middlePoint = midPosition(start, end);
    int j = middlePoint + 1;

    vector<int> temp;

    while (i <= middlePoint and j <= end)
    {
        if (array[i] < array[j])
        {
            temp.push_back(array[i]);
            i++;
        }
        else
        {
            temp.push_back(array[j]);
            j++;
        }
    }

    while (i <= middlePoint)
    {
        temp.push_back(array[i++]);
    }

    while (j <= end)
    {
        temp.push_back(array[j++]);
    }

    int k = 0 ;

    for(int idx = start;idx<=end;idx++){
        array[idx] = temp[k++];
    }

    return;
}

void mergeSort(vector<int> &array, int start, int end)
{

    // If array is empty or garbage size
    if (start >= end)
    {
        return;
    }

    

    int mid = midPosition(start, end);
    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, end);
    return merge(array, start, end);
}

int main()
{
    vector<int> arr = {8, 10, 4, 3, 7, 2,20, 11, 6, 5};
    // indexing start 0
    int start = 0;
    // indexing end the size of arr-1
    int end = arr.size() - 1;

    //call mergeSort function
    mergeSort(arr, start, end);

    //print mergeSorted Array
    for(int x : arr){
        cout<<x<<",";
    }

    cout<<endl;

    return 0;
}