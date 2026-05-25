#include<iostream>
using namespace std;
class Maths{
	public:
		int x,y;
		Maths(int m,int n){
			x=m;
			y=n;
		}
		Maths(const Maths &m1){
			x=m1.x;
			y=m1.y;
		}
		void printData(){
			cout<<"\n x="<<x<<"\t y= "<<y;
		}
};
main(){
	Maths m1(10,20);
	m1.printData();
	Maths m2=m1;
	m2.printData();
}