#include<iostream>
using namespace std;
class Parent{
	public:
		virtual void display(){
			cout<<"\n Parent class method called";
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
}