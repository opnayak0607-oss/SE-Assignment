#include<iostream>
using namespace std;
class Test{
	private:
	int x;
	public:
		Test(){
			x=100;
		}
		friend void display(Test t1);
};
void display(Test t1){
	cout<<"\n Private data of class test x="<<t1.x;
}
main(){
	Test t1;
	display(t1);
}