#include<iostream>
using namespace std;
class Maths{
	public:
		int x,y,a,b;
		Maths(int m,int n){
			x=m;
			y=n;
		}
		void printfData(){
			cout<<"\n x="<<x<<"\t y="<<y;
		}
		
};
main(){
	Maths *m1 = new Maths(12,23);
	m1->printfData();
}