#include <iostream>
#include <string.h>
#include <set>
using namespace std;

int main(){
    string x ,y ;
    float grade_1 ,grade_2 ,avg;
    int id_1,id_2;
    cout<<"what is student 1 name:  ";
    cin>>x;        
    cout<<endl<<"his id: ";
    cin>>id_1;
    cout<<endl<<"his math exam grade: ";
    cin>>grade_1;

    cout<<endl<<"what is student 2 name:  ";
    cin>>y;        
    cout<<endl<<"his id: ";
    cin>>id_2;
    cout<<endl<<"his math exam grade: ";
    cin>>grade_2;

    avg =(grade_1+grade_2)/2;

    cout<<endl<<"Students grade in math"<<endl<< x <<" (with id "<< id_1 <<" ) got grade:"<<grade_1;
    cout<<endl<< y <<" (with id "<< id_2 <<" ) got grade:"<<grade_2;
    cout<<endl<<"Average grades is "<<avg << endl;

return 0;
}