#include <iostream>
using namespace std;

int main (){

    int i=1 , x , y ,even=0,odd=0;
    for(i; i<= 8 ;i++){
        if(i%2 == 0){
            cin>>x;
            cout<<" ";
            even = even + x;
        }
        else{
            cin>>y;
            cout<<" ";
            odd = odd + y;
        }
        
    }
    cout<<odd<<" "<<even<<endl;

    return 0;
}