#include<iostream>
using namespace std;

class Father{
	private:
		int c;
	public:
		void add(int a,int b)
		{
			c = a + b;
			cout << c << endl;
		}
		virtual void speak()
		{
			cout << "this is father" << endl;
		}
};

class Son : public Father{
	public:
		void speak()
		{
			cout << "this is son" << endl;
		}
	
};


int main()
{
	Father baba;
	baba.add(1,2);
	
	Son son;
	Father *son1 = &son;
	son1->add(2,5);
	son1->speak();
	
	//Father *son2 = new Son();
	//son2->add(2,5);
	//son2->speak();

}