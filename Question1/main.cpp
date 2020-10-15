//Name- Tasfique Enam
//Student ID- 5886429

#include <iostream>
using namespace std;

class City;

class Customer
{
	friend void display(Customer, City);
	private:
		string ID;
		string name;

	public:
		Customer();
		Customer(string, string);
		void setID(string);
		void setName(string);
		string getID();
		string getName();
};

Customer::Customer(){}

Customer::Customer(string ID, string name)
{
	this->ID=ID;
	this->name=name;
}

void Customer::setID(string ID)
{
	this->ID=ID;
}

void Customer::setName(string name)
{
	this->name=name;
}

string Customer::getID()
{
	return ID;
}

string Customer::getName()
{
	return name;
}

class City
{
	friend void display(Customer, City);
	private:
		string city;
		string state;
		string postal;

	public:
		City();
		City(string, string, string);
		void setCity(string);
		void setState(string);
		void setPostal(string);
		string getCity();
		string getState();
		string getPostal();
};

City::City(){}

City::City(string city, string state, string postal)
{
	this->city=city;
	this->state=state;
	this->postal=postal;
}

void City::setCity(string city)
{
	this->city=city;
}

void City::setState(string state)
{
	this->state=state;
}

void City::setPostal(string postal)
{
	this->postal=postal;
}

string City::getCity()
{
	return city;
}

string City::getState()
{
	return state;
}

string City::getPostal()
{
	return postal;
}

void display(Customer cust, City city)
{
	if(&cust!=NULL)
	{
		cout << "Customer ID : " << cust.getID() << endl;
		cout << "Name : " << cust.getName() << endl << endl;
	}
	if(&city!=NULL)
	{
		cout << "City Name : " << city.getCity() << endl;
		cout << "State : " << city.getState() << endl;
		cout << "Postal Code : " << city.getPostal() << endl << endl;
	}
}

int main()
{
	Customer customer1;

	string ID;
	string name;
	cout << "Enter Customer ID" << endl;
	cin >> ID;
	cout << "Enter Customer Name" << endl;
	cin >> name;
	customer1.setID(ID);
	customer1.setName(name);


    cout << "Enter Customer ID 2" << endl;
	cin >> ID;
	cout << "Enter Customer Name 2" << endl;
	cin >> name;
	Customer customer2;
	customer2.setID(ID);
	customer2.setName(name);


	string cityName;
	string state;
	string postal;
	cout << "Enter City Name" << endl;
	cin >> cityName;
	cout << "Enter State" << endl;
	cin >> state;
	cout << "Enter Postal Code" << endl;
	cin >> postal;
	City city1;
	city1.setCity(cityName);
	city1.setState(state);
	city1.setPostal(postal);


	cout << "Enter City Name 2" << endl;
	cin >> cityName;
	cout << "Enter State 2" << endl;
	cin >> state;
	cout << "Enter Postal Code 2" << endl;
	cin >> postal;
	City city2;
	city2.setCity(cityName);
	city2.setState(state);
	city2.setPostal(postal);

	display(customer1, city1);
	display(customer2, city2);
	return 0;
}
