#include <iostream>
using namespace std;

int partition(int *arr, int s, int e){
    int pivot = arr[s];
    int count = 0;
    for (int i=s+1; i<=e; i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);
    int i = s;
    int j = e;
    while(i< pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int *arr, int s, int e){
    if (s>=e){
        return ;
    }
    int p = partition(arr, s, e);
    
    // left side sorting
    quickSort(arr, s, p-1);
    
    // right side sorting
    quickSort(arr, p+1, e);
}


int main() {
    int arr[10] = {2, 5, 1, 6, 9, 4, 23, 19, 8, 10};
    int n = 10;
    
    quickSort(arr, 0, n-1);
    for (int i=0; i<n; i++){
        cout<<" "<<arr[i]<< " ";
    }

    return 0;
}