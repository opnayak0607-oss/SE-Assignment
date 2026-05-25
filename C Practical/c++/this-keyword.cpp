#include<iostream>
using namespace std;
class Maths{
	public:
		int x,y;
		Maths(int a=0,int b=0){
			this->x=x;
			this->y=y;
		}
		
		void printData(){
			cout<<"\n x="<<this->x<<"\t y="<<this->y;
		}
};
main(){
	Maths m1(12,3);
	m1.printData();
	Maths m2(2,3);
	m2.printData();
}