#include<iostream>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

class bank;

#include "shop.h"
#include "bank.h"

#include "shop.cpp"
#include "bank.cpp"

int main(){
	bank bobj;
	shop sobj;
	int n;
	while(1){
		system("clear");
		cout<<"................SERVICES.................."<<endl;
		cout<<"\n1.bank service 2.shopping service 3.exit"<<endl;
		cin>>n;
		switch(n){

			case 1: bobj.menu();
				break;
			case 2:sobj.menu(bobj);
			       break;
			default:
			       cout<<"\n................THANK YOU.................\n"<<endl;
			       exit(0);

		}
	}
	return 0;

}
