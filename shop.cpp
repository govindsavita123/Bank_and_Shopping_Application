shop::shop(){
	amt=0;
	product=0;
}

void shop::add_cart(){
	if(product==10){
		cout<<"your cart is full"<<endl;
		return;
	}

	cout<<"enter product name- ";
	cin>>arr[product].name;
ip1:
	cout<<"enter product price- ";
	cin>>arr[product].price;
	if(arr[product].price<1){
		cout<<"Incorrect price...."<<endl;
		goto ip1;
	}
ip2:
	cout<<"enter product quantity- ";
	cin>>arr[product].quantity;
	if(arr[product].quantity<1){
		cout<<"Incorrect quantity...."<<endl;
		goto ip2;
	}

	product++;    
}

void shop::view_cart(){
	if(product==0){
		cout<<"your cart is empty"<<endl;
		return;
	}
	system("clear");
	cout<<"\n-----------------YOUR CART DETAIL-----------------\n"<<endl;
	cout<<"s.no\tname\tprice\tquantity   total"<<endl; 
	for(int i=0;i<product;i++){
		cout<<i+1<<"\t"<<arr[i].name<<"\t"<<arr[i].price<<"\t"<<arr[i].quantity<<"\t   "<<((arr[i].price)*(arr[i].quantity))<<endl;        
	}
	caltotal();
	cout<<"\n--------------------------------------------------"<<endl;
	cout<<"total bill- "<<amt<<endl;
	cout<<"--------------------------------------------------"<<endl;

}

void shop::caltotal(){
	amt=0;
	for(int i=0;i<product;i++){
		amt+=(arr[i].price)*(arr[i].quantity);
	}
}

void shop::pay_bill(bank &b){

	if(product==0){
		cout<<"your cart is empty"<<endl;
		return;
	}
	if(b.verify()){
		return;
	}

	if(amt>b.bal){
		cout<<"Insufficient balance..."<<endl;
		return;
	}

	b.bal-=amt;
	cout<<"total bill- "<<amt<<endl;
	cout<<"sucessfully pay...."<<endl;
	product=0;
}

void shop::remove_cart(){
	if(product==0){
		cout<<"your cart is empty"<<endl;
		return;
	}
	string st;
	cout<<"enter product name-"<<endl;
	cin>>st;
	for(int i=0;i<product;i++){
		if(arr[i].name==st){
			memmove(arr+i,arr+i+1,sizeof(arr+i+1));
			product--;
			return;
		}
	}
	cout<<".....PRODUCT NOT FOUND...."<<endl;  
}

void shop::change_cart(){
	if(product==0){
		cout<<"your cart is empty"<<endl;
		return;
	}
	string st;
	int n;
	cout<<"enter product name-"<<endl;
	cin>>st;
	for(int i=0;i<product;i++){
		if(arr[i].name==st){
			cout<<"WHAT YOU WANT TO CHANGE.."<<endl;
			cout<<"1.price 2.quantity 3.exit"<<endl;
			cin>>n;
			switch(n){
				case 1:
                                       ip1:	cout<<"enter new price- "<<endl;
	                                        cin>>arr[i].price;
	                                        if(arr[i].price<1){
		                                cout<<"Incorrect price...."<<endl;
	                                  	goto ip1;
						}
                                           	break;
				case 2:
                                     ip2:       cout<<"enter new quantity- "<<endl;
				                cin>>arr[i].quantity;
			                 	if(arr[i].quantity<1){
					        cout<<"Incorrect quantity...."<<endl;
					        goto ip2;
						}
						break;
			}
			return;
		}
	}
	cout<<".....PRODUCT NOT FOUND...."<<endl;  
}

void shop::menu(bank &b){
	int n;
	system("clear");
	cout<<"\n.............WELCOME SHOP MART...........\n"<<endl;
	while(1){
		cout<<"\n1.add_cart    2.view_cart   3.paybill"<<endl;
		cout<<"4.remove_cart 5.change_cart 6.exit"<<endl;
		n=0;
		cin>>n;
		switch(n){
			case 1:add_cart();
			       break;
			case 2:view_cart();
			       break;
			case 3:pay_bill(b);
			       break;
			case 4:remove_cart();
			       break;
			case 5:change_cart();
			       break;
			default:
			       return;

		}   
	}

}
