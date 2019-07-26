#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Name {
	string firstName;
	string lastName;
};

struct Address {
	string city;
	string state;
	string zip;
};

struct CustomerInfo {
	Name name;
	Address address;
	string phoneNumber;
};

struct Date {
	string month;
	string day;
	string year;
};

struct Account {
	string balance;
	Date date;
};

struct Customer {
	Name name;
	Address address;
	Account account;
	CustomerInfo info;
};

Customer addCustomer(vector<Customer> &newC);
void viewCustomers(const Customer &customers);

int main() {
	vector<Customer> customer;
	Customer newCustomer;
	int task;
	bool cont = false;
	do{
		cout << "Please choose which task you would like to do: " << endl;
		cout << "'1': Add new customer, '2': View all customers, '0': Exit" << endl;
		cin >> task;
	
		if (task == 1) {
			newCustomer = addCustomer(customer);
			cont = true;
		}
		if (task == 2) {
			viewCustomers(newCustomer);
			cont = true;
		}
		else {
			cont = false;
		}
	} while (cont);
	
	return 0;
}

Customer addCustomer(vector<Customer> &newC) {
	Customer customer;
	cout << "Enter your first name: ";
	getline(cin, customer.info.name.firstName);
	cin.ignore();
	cout << "Enter your last name: ";
	getline(cin, customer.info.name.lastName);
	cin.ignore();

	cout << "Enter your phone number: ";
	getline(cin, customer.info.phoneNumber);
	cin.ignore();

	cout << "Enter your city: ";
	getline(cin, customer.info.address.city);
	cin.ignore();
	cout << "Enter your state: ";
	getline(cin, customer.info.address.state);
	cin.ignore();
	cout << "Enter your zip: ";
	getline(cin, customer.info.address.zip);
	cin.ignore();

	cout << "Enter your account balance: ";
	getline(cin, customer.account.balance);
	cin.ignore();
	cout << "Enter the last date due: " << endl;
	cout << "Month: ";
	getline(cin, customer.account.date.month);
	cin.ignore();
	cout << "Day: ";
	getline(cin, customer.account.date.day);
	cin.ignore();
	cout << "Year: ";
	getline(cin, customer.account.date.year);
	cin.ignore();

	newC.push_back(customer);
	return customer;
}

void viewCustomers(const Customer &customers) {
	cout << customers.name.firstName << " ";
	cout << customers.name.lastName << endl;
}
