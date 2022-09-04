/*
  180 Daraga Training
  Session No : 1
  Problem : IS it prime
  By : Ahmed Gamal
  On : 4/09/2022
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    for (int i=2; i<n; i++){
        if (n%i == 0){ /// n-2 * times
            cout<<"not prime"<<endl;
            return 0;
        }
    }
    for (int i=2; i*i<=n; i++){
        if (n%i == 0){ /// sqrt(n)-1 * times
            cout<<"not prime"<<endl;
            return 0;
        }
    }


    cout<<"is prime"<<endl;
    return 0;
}
