#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int employee_id;
    double salary;

public:
    Employee(string name = "NULL", int employee_id = 0, double salary = 0)
        : name(name), employee_id(employee_id), salary(salary) {}

    virtual void monthlyBonus() {
        cout << "Salary of Employee: " << salary << endl;
    }
};

class Professor : public Employee {
    string department;

public:
    Professor(string name, int employee_id, double salary, string department)
        : Employee(name, employee_id, salary), department(department) {}

    void monthlyBonus() override {
        double bonus = 0.10 * salary;
        salary += bonus;
        cout << "10% monthly bonus of Professor: " << bonus << endl;
    }
};

class AdminStaff : public Employee {
    string position;

public:
    AdminStaff(string name, int employee_id, double salary, string position)
        : Employee(name, employee_id, salary), position(position) {}

    void monthlyBonus() override {
        double bonus = 0.05 * salary;
        salary += bonus;
        cout << "Monthly bonus of Admin Staff: " << bonus << endl;
    }
};

class Janitor : public Employee {
    int hoursWorked;

public:
    Janitor(string name, int employee_id, double salary, int hoursWorked)
        : Employee(name, employee_id, salary), hoursWorked(hoursWorked) {}

    void hourlyWages() {
        double janitorSalary = hoursWorked * 500;
        cout << "Janitor's salary is: " << janitorSalary << endl;
    }
};

int main() {
    Employee O1("Aditya", 102, 30000);
    O1.monthlyBonus();

    Professor P1("Modi", 103, 150000, "CS");
    P1.monthlyBonus();

    AdminStaff A1("Ayush", 104, 150000, "Data Analyst");
    A1.monthlyBonus();

    Janitor J1("Raju", 105, 120000, 8);
    J1.hourlyWages();

    return 0;
}
