#include<iostream>
using namespace std;
class Maths{
	public:
		void area(int l){
			cout<<"\n area of square"<<l*l;
		}
		void area(int l,int b){
			cout<<"\n area of rectangle"<<l*b;
		}
};
main(){
	Maths m1;
	m1.area(12,3);
	m1.area(12);
}