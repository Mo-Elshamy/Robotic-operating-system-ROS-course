#include <iostream>
using namespace std;

int main(){

    int x,i;
    cin>>x;
    for(i=1; i <= x ;i++){
        cout<< (i + (x-i))<<endl;
    }
    
    return 0;
}