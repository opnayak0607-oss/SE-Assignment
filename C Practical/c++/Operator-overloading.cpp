#include<iostream>
using namespace std;
class Maths{
	public:
		int x,y;
		Maths(int a=0,int b=0){
			x=a;
			y=b;
		}
		Maths operator + (Maths &m2){
			Maths m3;
			m3.x = x + m2.x;
			m3.y = y + m3.y;
			return m3;
		}
		void printData(){
			cout<<"\n x="<<x<<"\t y="<<y;
		}
};
main(){
	Maths m1(12,3);
	m1.printData();
	Maths m2(2,3);
	m2.printData();
	Maths m3 =m1 +m2;
	m3.printData();
}