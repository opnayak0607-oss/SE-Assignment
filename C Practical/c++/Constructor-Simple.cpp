#include<iostream>
using namespace std;
class Maths{
	public:
		Maths(){
			cout<<"\n Default Constructor called";
		}
};
main(){
	Maths();
	Maths m1();
}