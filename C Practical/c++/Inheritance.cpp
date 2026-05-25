#include<iostream>
using namespace std;
class Category{
	public:
		int catid;
		char catname[20];
		
		void getCategory(){
			cout<<"\n Enter Category";
			cin>>catname;
		}
};
class Product:public Category{
	public:
		char pname[20];
		float price;
		void getProduct(){
			getCategory();
			cout<<"\n Enter Product name and Price";
			cin>>pname>>price;
		}
		void printProduct(){
			cout<<"\n Category:"<<catname;
			cout<<"\n ProductName:"<<pname;
			cout<<"\n Price:"<<price;
		}
};
main(){
	Product p1;
	p1.getProduct();
	p1.printProduct();
}