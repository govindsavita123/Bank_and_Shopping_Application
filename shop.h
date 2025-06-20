class shop
{
	struct st{
	   string name;
	   float price,quantity;
	};
	struct st arr[10];
	int product;
	float amt;

	public:
	shop();
	void add_cart();
	void view_cart();
	void caltotal();
	void pay_bill(bank &);
	void remove_cart();
	void change_cart();
	void menu(bank &);
};
