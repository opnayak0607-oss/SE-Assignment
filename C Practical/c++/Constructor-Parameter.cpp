#include<iostream>
using namespace std;
class AreaofCircle{
	public:
	int r;
	AreaofCircle(){
		cout<<"\n Enter radius";
		cin>>r;
	}
	AreaofCircle(int radius){
		r=radius;
	}
	void findArea(){
		float a=3.14*r*r;
		cout<<"\n area of circle="<<a;
	}
};
main(){
	AreaofCircle a1;
	a1.findArea();
	AreaofCircle a2(20)
	a2.findArea(); 
}