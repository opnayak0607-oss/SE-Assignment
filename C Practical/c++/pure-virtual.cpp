#include<iostream>
using namespace std;
class Parent{
	public:
		virtual void display()=0;
		void add(int x,int y)
		{
			cout<<"\n add="<<x+y;
		}
};
class Child:public Parent{
	public:
		void display(){
			cout<<"\n child class method called";
		}
};
main(){
	Child c1;
	c1.display();
	c1.add(24,45);
}