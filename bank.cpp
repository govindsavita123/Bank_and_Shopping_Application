bank::bank(){
	system("clear");

	cout<<"\n.....WELCOME TO BANK OF INDIA.....\n"<<endl;
	cout<<"account holder name- "<<endl;
	cin>>name;
	cout<<"create password- "<<endl;
	cin>>password;
	acc=cnt;
	cnt++;
	bal=0;
}
bool bank::verify(){
	  string s;
	  cout<<"enter the password- "<<endl;
	  cin>>s;
	  if(s!=password){
	    cout<<"Incorrect password"<<endl;
		  return true;
	  }
	  return false;
}

void bank::deposit(){
	if(verify()){
	   return;
	}
	float amt;
	cout<<"enter deposit amount- "<<endl;
	cin>>amt;
	if(amt<0){
	  cout<<"Incorrect amount...."<<endl;
	  return;
	}
	bal+=amt;

}
void bank::withdraw(){

	if(verify()){
	   return;
	}
	float amt;
	cout<<"enter withdraw amount- "<<endl;
	cin>>amt;
	if(amt<0){
	  cout<<"Incorrect amount...."<<endl;
	  return;
	}

	if(amt>bal){
		cout<<"Insufficient balance..."<<endl;
	}
	else{  
		bal-=amt;
	}
}
void bank::balenq(){
	if(verify()){
	   return;
	}
	cout<<"balance- "<<bal<<endl;
}
void bank::detail(){
	if(verify()){
	   return;
	}
	cout<<"name-    "<<name<<endl;
	cout<<"accno-   "<<acc<<endl;
	cout<<"balance- "<<bal<<endl;
}
void bank::menu(){
	int n;
       system("clear");
       cout<<"\n................BANK SERVICES..............."<<endl;
	while(1){

		cout<<"\n1.deposit 2.withdraw 3.balenq 4.detail 5.exit"<<endl;
		n=0;
		cin>>n;
		switch(n){
			case 1:deposit();
			       break;
			case 2:withdraw();
			       break;
			case 3:balenq();
			       break;
			case 4:detail();
			       break; 
			default:
			       return;

		}  

	}

}
