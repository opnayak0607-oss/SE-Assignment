#include<iostream>
using namespace std;
class Maths{
	public:
		int a;
		static int s;
		Maths(int a){
			this->a=a;
			
			cout<<"\n a="<<a<<" s ="<<s;
		}
		
		static void printStatic(){
			cout<<"\n s="<<s;
		}
};
int Maths::s=10;
main(){
	Maths m1(12),m2(3),m3(4);
	Maths::printStatic();
}