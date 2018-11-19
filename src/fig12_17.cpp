// Fig. 12.17: fig12_17.cpp
// Processing Employee derived-class objects with static binding 
// then polymorphically using dynamic binding.
#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h" 
#include "CommissionEmployee.h"  
#include "BasePlusCommissionEmployee.h" 
#include <typeinfo>
using namespace std;

void virtualViaPointer(const Employee* const); // prototype
void virtualViaReference(const Employee&); // prototype
Employee* addEmployeeFromUser();
void printSummary(vector<Employee *>);
void printSalaries(vector<Employee *>, int);

int main() {
		// create derived-class objects                        
	SalariedEmployee salariedEmployee{
	 "John", "Smith", "111-11-1111", 800};
	CommissionEmployee commissionEmployee{
	 "Sue", "Jones", "333-33-3333", 10000, .06};
	BasePlusCommissionEmployee basePlusCommissionEmployee{
	 "Bob", "Lewis", "444-44-4444", 5000, .04, 300};

	// create and initialize vector of three base-class pointers        
	vector<Employee *> employees{&salariedEmployee, &commissionEmployee,
	&basePlusCommissionEmployee};

	vector<Employee *> adresses;

	Employee* ptr;

	while(1){
		cout << fixed << setprecision(2); // set floating-point formatting

		int menu_option;

		cout << "Welcome to the best c++ program you'll ever use! Press 1 to view a summary of users, or 2 to input a new user, or 3 to print salaries to be paid" << endl;
		cin >> menu_option;

		switch (menu_option){
		 	case 1:{
		 		printSummary(employees);
		 		break;
		 	}
		 	case 2:{
		 		adresses.push_back(ptr);
		 		ptr = addEmployeeFromUser();
		 		employees.push_back(ptr);
		 		break;
		 	}
		 	case 3:{
		 		printSalaries(employees,3);
		 		break;
		 	}
		}
	}
}

// call Employee virtual functions toString and earnings off a   
// base-class pointer using dynamic binding                   
void virtualViaPointer(const Employee* const baseClassPtr) {
   cout << baseClassPtr->toString()
      << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}

// call Employee virtual functions toString and earnings off a  
// base-class reference using dynamic binding                
void virtualViaReference(const Employee& baseClassRef) {
   cout << baseClassRef.toString()
      << "\nearned $" << baseClassRef.earnings() << "\n\n";
}

Employee* addEmployeeFromUser(){
   cout << "Enter 1 for salaried employee, 2 for commissionned employee, and 3 for the other one :)" << endl;

   int employee_type = 0;

   cin >> employee_type;

   switch (employee_type){

      case 1:{

         string first_name;
         string last_name;
         string ss_no;
         double salary;


         cout << "First Name" << endl;
         cin >> first_name;
         cout << "Last Name" << endl;
         cin >> last_name;
         cout << "Social Security Number" << endl;
         cin >> ss_no;
         cout << "Salary" << endl;
         cin >> salary;

         SalariedEmployee *ptr = new SalariedEmployee(first_name,last_name,ss_no,salary);
         return ptr;
         break;
      }

      case 2:{

         string first_name;
         string last_name;
         string ss_no;
         double sales;
         double rate;

         cout << "First Name" << endl;
         cin >> first_name;
         cout << "Last Name" << endl;
         cin >> last_name;
         cout << "Social Security Number" << endl;
         cin >> ss_no;
         cout << "Sales (Gross)" << endl;
         cin >> sales;
         cout << "Commission Rate" << endl;
         cin >> rate;

         CommissionEmployee *ptr = new CommissionEmployee(first_name,last_name,ss_no,sales,rate);
         return ptr;
         break;
      }

      case 3:{

         string first_name;
         string last_name;
         string ss_no;
         double sales;
         double rate;
         double salary;

         cout << "First Name" << endl;
         cin >> first_name;
         cout << "Last Name" << endl;
         cin >> last_name;
         cout << "Social Security Number" << endl;
         cin >> ss_no;
         cout << "Sales (Gross)" << endl;
         cin >> sales;
         cout << "Commission Rate" << endl;
         cin >> rate;
         cout << "Salary" << endl;
         cin >> salary;

         BasePlusCommissionEmployee *ptr = new BasePlusCommissionEmployee(first_name,last_name,ss_no,sales,rate,salary);
         return ptr;
         break;
      }
   }
}

void printSummary(vector<Employee *> employees){
   	for (int i = 0; i < employees.size(); ++i){   	
   		cout << employees.at(i)->toString() << endl;
   		cout << "\n" << endl;
   	}
}

void printSalaries(vector<Employee *> employees, int weeks){
	double total_salaries = 0;

	for (int i = 0; i < employees.size(); ++i){
		const type_info& what_type = typeid(employees.at(i));
		if (what_type == typeid(employees.at(0))){
			cout << "you just did the thing" << endl;//total_salaries += employees.at(i)->earnings();
		}
		if (what_type == typeid(employees.at(2))){
			cout << "you just did the thing again" << endl;//total_salaries += employees.at(i)->getBaseSalary();
		}
	}
	total_salaries *= weeks;
	cout << "The total amount of salaries for the next " << weeks << " weeks is " << total_salaries << "." << endl;
}


/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
