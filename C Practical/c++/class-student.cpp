#include<iostream>
using namespace std;

class Student{
	
	char name[20];
	char email[30];

	public:
	void getstudentInfo(){
		cout<<"\n Enter Name and Email";
		cin>>name>>email;
	}
	void showstudentInfo(){
		cout<<"\n Name="<<name;
		cout<<"\n Email="<<email;
	}
};
main(){
	Student s1;
	s1.getstudentInfo();
	s1.showstudentInfo();
	}												