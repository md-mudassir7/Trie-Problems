#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 9; //binary form of 9 is 0000....1001 which is of 32 bits
    //To check if the ith bit is set or not 
    int i;
    cin>>i;

    //let i = 3 we right shift n by i places so that our ith bit of n is at rightmost position 
    // then we and it with 1 to check if its set or not

    cout<<((n>>i)&1)<<endl;
    
    //To turn on ith bit

    //let i = 3 we left shift 1 by i places so that our bit(1) of is at position i now 
    // then we or n it with 1 to set the ith bit of n


    cout<<((1<<i)|1 );
    
    return 0;
}