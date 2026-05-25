#include<iostream>
using namespace std;
class Parent{
	public:
		Parent(){
			cout<<"\n parent class constructor called";
		}
		Parent(int z){
			cout<<"\n in parent class z="<<z;
		}
};
class Child :Parent{
	public:
		Child(){
			cout<<"\n child class constructor called";
		}
		Child(int x,int y,int z):Parent(z){
			cout<<"\n x="<<x<<"\t y="<<y;
		}
};
main(){
	Child c1;
	Child c2(1,2,3);
}