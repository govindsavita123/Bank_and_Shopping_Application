class bank
{
	int acc;
	float bal;
	string name,password;
	static int cnt;
	public:
	bool verify();
	bank();
	void menu();
	void deposit();
	void withdraw();
	void balenq();
	void detail();
	friend void shop::pay_bill(bank &);

};
int bank::cnt=987652311;
