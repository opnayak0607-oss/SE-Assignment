#include<iostream>
using namespace std;
class A{
	public:
		int a;
		void getA(){
			cout<<"\n Enter the value of a";
			cin>>a;
		}
};
class B{
	public:
		int b;
		void getB(){
			cout<<"\n Enter the value of b";
			cin>>b;
		}
};
class C : public A,public B{
	public:
		int c;
		void getC(){
			cout<<"\n Enter c";
			cin>>c;
		}
		void add(){
			cout<<"\n addition="<<a+b+c;
		}
};
main(){
	C c1;
	c1.getA();
	c1.getB();
	c1.getC();
	c1.add();
}