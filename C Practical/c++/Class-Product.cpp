#include<iostream>
using namespace std;
class Product{
	//data member
	public:
	char pname[20];
	float price;
	char desc[30];

	public:
	//member function
	void getProductionInfo(){
		cout<<"\n Enter product name price and description";
		cin>>pname>>price>>desc;	
	}
	void showProductInfo(){
		cout<<"\n Product Name="<<pname;
		cout<<"\n price="<<price;
		cout<<"\n description="<<desc;
	}
};
main(){
	Product p1;
	p1.getProductionInfo();
	p1.showProductInfo();
}