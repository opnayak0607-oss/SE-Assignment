#include<iostream>
// using namespace std;
int gVar = 100;

class Test{
	public:
		void display();
};
// to define function outside the class
void Test::display(){
	std::cout<<"\n Method define outside the class";
}
main(){
	// access global variable
	std::cout<<"\n gVar="<<::gVar;
	Test t1;
	t1.display();
}