#include<iostream>
using namespace std;
class Account{
	public:
		char accNo[16];
		char accHolder[50];
		char accEmail[50];
		float balance;
		
		void getInfo(){
			cout<<"\n Enter account holder name and email balance";
			cin>>accNo;
			cin>>accHolder;
			cin>>accEmail;
			cin>>balance;
		}
};
class Saving : private Account{
	public:
		void calcInterest(){
			getInfo();
			balance = balance +(balance *0.02);
		}
		void printfInfo(){
			cout<<"\n Accno"<<accNo;
			cout<<"\n Holder="<<accHolder;
			cout<<"\n current bal:"<<balance;
		}
};
class Current : private Account{
	public:
		void calcInterest(){
			getInfo();
		balance = balance - (balance *0.02);
		}
		void printfInfo(){
			cout<<"\n Accno"<<accNo;
			cout<<"\n Holder="accHolder;
			cout<<"\n email="<<accEmail;
			cout<<"\n current bal:"<<balance;
		}
};
main(){
	int ch;
	cout<<"\n press 1 for saving and press 2 for current\n Enter choice";
	cin>>ch;
	if(ch==1){
		Saving s1;
		s1.calcInterest();
		s1.printInfo();
	}
	else if(ch==2){
		Current c1;
		c1.calcInterest();
		c1.printfInfo();
	}
	else{
		cout<<"wrong Input";
	}
}