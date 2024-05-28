#include <bits/stdc++.h>
using namespace std;

            // => This Code By : Mohamed Mohsen <=//

                // 5
void print_arr(int size, int arr[]) {

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout<<endl;
}

void reverse_arr(int size, int arr[]) {
    int arr2[size];
               // 3
    for (int i = size-1; i >= 0; i--)
    {
         arr2[size-(i+1)] = arr[i];
    }


    for (int i = 0; i < size; i++)
    {
        arr[i] = arr2[i];
    }
    cout << "Array After Reverse : ";

    print_arr(size,arr);
}

int sum_arr(int size, int arr[]){
    int all =0;

    for (int i = 0; i < size; i++)
        all =all + arr[i];

    cout<<"Sum Of Array : " <<all<<endl;
    return all;
}

int max_arr(int size, int arr[]){
    int maxOfElement = arr[0];

    for (int i = 1; i < size; i++){
        if(arr[i] > maxOfElement){
            maxOfElement=arr[i];
        }
    }
    cout<<"Max Of Array : " << maxOfElement<<endl;
    return maxOfElement;
}

int min_arr(int size, int arr[]){
    int minOfElement =arr[0];
    for (int i = 1; i < size; i++){
        if(arr[i] < minOfElement){
            minOfElement=arr[i];
        }
    }
    cout<<"Min Of Array : " << minOfElement<<endl;
    return minOfElement;
}


                     // 5
int sequential_search(int num,int size, int arr[]){
    // Liner_Search
    for (int i = 0; i < size; i++){
        if(arr[i] == num){

          cout<< "Number " <<num<< " Is In Array Index : "<< i <<endl;
            return i;
        }
    }
    cout<< "Number Not Found"<<endl;
}



//Needed To Binary Search//
void Sort_arr(int size, int arr[]){
    // Selection Sort -> O(n^2)

    for(int i = 0; i < size;i++){
        for (int j = i+1; j < size; j++) {
            int temp=0;
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int Binary_search(int num,int size, int arr[]){

    Sort_arr(size,arr);// 1 2 3 4 5

    int left=0,right=size-1;

    while(left<=right){
        int mid =(left+right)/2; // 2
            // 3
        if(arr[mid]==num){
          cout<< "Number "<<num<< " Is In Array Index : "<< mid<<endl;
            return mid;
        }

        else if (num > arr[mid]){
            left =mid+1;
        }

        else if (num < arr[mid]){
            right =mid-1;
        }
    }


    cout<< "Number Not Found "<<endl;
    return -1;
}

int* insert_arr(int num,int size, int arr[]) {

    size++;
    arr[(size)-1] = num;

    print_arr(size,arr);

 return  arr;
}

int* delete_arr(int index,int &size, int arr[]) {

        for(int i =index;i<(size-1);i++)
            arr[i]=arr[i+1];
        arr[size-1]=NULL;
        size--;
        print_arr(size,arr);
        return arr;


}

int main() {
    int arr_size = 5;
    int arr[arr_size+5] = {1,2,3,4,5};

    print_arr(arr_size,arr);
    cout << endl;
    reverse_arr(arr_size,arr);
    cout << endl;
    sum_arr(arr_size,arr);
    cout << endl;
    max_arr(arr_size,arr);
    cout << endl;
    min_arr(arr_size,arr);
    cout << endl;
    sequential_search(5,arr_size,arr);
    cout << endl;
    Binary_search(5,arr_size,arr);
    cout << endl;
    delete_arr(0,arr_size,arr);
    cout << endl;
    insert_arr(10,arr_size,arr);
}
