/*
  180 Daraga Training
  Session No : 4
  Session : Binary search
  By : Ahmed Gamal
  On : 13/09/2022
*/

#include <iostream>

using namespace std;
int n, k, Uneed[1001], Uhave[1001];


bool isOk1(int x){
    int tempk = k;
    for(int i=0;i<n;i++){
        if(Uhave[i] < x*Uneed[i]){
            int diff = ((x*Uneed[i]) - Uhave[i]);
            if(tempk  >= diff)
                tempk -= diff; /// k = k-((x*Uneed) - Uhave);
            else
                return false;
        }
    }
    return true;
}


bool isOk(int x){ /// O(n)
    int tempK = k;
    for(int i=0; i<n; i++){
        int tun = x * Uneed[i];
        if (tun > Uhave[i]) {
           int dif = tun - Uhave[i];
           if (tempK >= dif){
                tempK -= dif; /// tempK = 10
           } else {
                return false;
           }
        }
    }
    return true;
}


/// O(nlogn)
int binarySearch(){
    int l=0, h = 2e3, mid;

    while(l<h){
        mid = (l+h+1)/2; /// go near h
        if(isOk(mid))
            l = mid;
        else
            h = mid - 1;
    }

    return l;
}


int main()
{

    cin>>n>>k;

    for(int i=0;i<n;i++)
        cin>>Uneed[i];

    for(int i=0;i<n;i++)
        cin>>Uhave[i];


    cout<<binarySearch();

    return 0;
}
