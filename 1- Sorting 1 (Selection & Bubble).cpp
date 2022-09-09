/*
  180 Daraga Training
  Session No : 1
  Session : Bubble & Selection
  By : Ahmed Gamal
  On : 4/09/2022
*/

#include <iostream>

using namespace std;

int arr[101],n;

void swapAB(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
  //  cout<< "inside Func" <<a<<" " <<b<<endl;
}

void printArray(){
    cout<<"Array values: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void bubbleSort(){                                      /// O(n^2)
    bool flag = false;
    for(int j=0; j<n; j++){                         /// O(n)
            flag = false;
        for(int i=0; i<n-1; i++){                   /// O(n)   >>> change to <n-j-1
            if(arr[i]>arr[i+1]){
                swapAB(arr[i],arr[i+1]);
                flag = true;
            }
        }
        if(flag==false){
            break;
        }
    }
}


void selectionSort(){                                   /// O(n^2)
    for(int i =0; i<n; i++){                         /// O(n)

        int mn = arr[i], mnIdx=i;
        for(int j=i; j<n; j++){                      ///O(n)
            if(arr[j]<mn){
                mn = arr[j];
                mnIdx = j;
            }
        }
        swapAB(arr[i],arr[mnIdx]);
   // cout<<mn<<" " << mnIdx <<endl;

    }
}
void swapAB1(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

void selectionSort1(){

    for(int i=0; i<n; i++){
        int temp = i;
        for(int j = i+1; j<n; j++){
            if (arr[j]<arr[temp]){
                temp = j;
            }
        }
        swapAB1(arr[temp], arr[i]);
    }
}



int main()
{
/*
    int a=5, b=6;
    cout<<a<<" "<<b<<endl;
    swapAB(a,b);
    cout<<a<<" "<<b<<endl;
  */
  /// 5
  /// 1 4 9 3 8

    cin>>n;
    for(int i=0; i<n; i++){ ///i >>  0,1,2,3,4
        cin>>arr[i];
    }
    printArray();
    selectionSort1();
    //bubbleSort();
    cout<<"After sort"<<endl;
    printArray();

    return 0;
}


