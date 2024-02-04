#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits>

using namespace std;

class Employee {
private:
    string name;
    int age;
    double salary;
    char gender;

public:
    // Getter for name
    std::string getName() const {
        return name;
    }

    // Setter for name
    void setName(const std::string& newName) {
        name = newName;
    }

    // Getter for age
    int getAge() const {
        return age;
    }

    // Setter for age
    void setAge(int newAge) {
        age = newAge;
    }

    // Getter for salary
    double getSalary() const {
        return salary;
    }

    // Setter for salary
    void setSalary(double newSalary) {
        salary = newSalary;
    }

    // Getter for gender
    char getGender() const {
        return gender;
    }

    // Setter for gender
    void setGender(char newGender) {
        gender = newGender;
    }

    bool operator<(const Employee& other) const {
        return age < other.age;
    }
};

class ManageEmployees {
private:
    vector<Employee> employees;

public:
    ManageEmployees() {
        list();
    }

    void list() {
        int c;
        while (c != 5) {
            cout << "Enter your choice:\n"
                 << "1) Add new employee\n"
                 << "2) Print all employees\n"
                 << "3) Delete by age\n"
                 << "4) Update Salary by name\n"
                 << "5) Exit" << endl;
            cin >> c;

            switch (c) {
                case 1:
                    addEmployee();
                    break;
                case 2:
                    printEmployees();
                    break;
                case 3:
                    layoffEmployees();
                    break;
                case 4:
                    updateSalary();
                    break;
                case 5:
                    cout << "Exiting program. Goodbye!" << endl;
                    return; // Return instead of exit(0)
                default:
                    cout << "Invalid input, please enter correct input\n";
                    break;
            }
        }
    }

    void addEmployee() {
        string name;
        int age;
        double salary;
        char gender;

        cout << "Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        transform(name.begin(), name.end(), name.begin(), ::tolower);

        cout << "Age: ";
        cin >> age;

        cout << "Gender: ";
        cin >> gender;
        gender = toupper(gender);

        cout << "Salary: ";
        cin >> salary;

        if (!validateInput(age, "Age", [](int value) { return value > 0; }) ||
            !validateInput(salary, "Salary", [](double value) { return value > 0; }) ||
            !validateInput(gender, "Gender", [](char value) { return value == 'M' || value == 'F'; })) {
            cout << "Invalid input\n";
            return;
        }

        Employee e;
        e.setName(name);
        e.setAge(age);
        e.setGender(gender);
        e.setSalary(salary);

        if (!employees.empty()) {
            auto x = employees.back();
            employees.pop_back();
            employees.push_back(min(e, x));
            employees.push_back(max(e, x));
        } else {
            employees.push_back(e);
        }
    }

    void layoffEmployees() {
        int maxAge;
        cout << "Enter the max age for employees: ";
        cin >> maxAge;

        auto it = remove_if(employees.begin(), employees.end(),
                            [maxAge](const Employee& emp) { return emp.getAge() > maxAge; });

        employees.erase(it, employees.end());
    }

    void updateSalary() {
        string name;
        cout << "Enter employee name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        transform(name.begin(), name.end(), name.begin(), ::tolower);

        double newSalary;
        cout << "Enter new salary: ";
        cin >> newSalary;

        auto it = find_if(employees.begin(), employees.end(),
                          [name](const Employee& emp) { return emp.getName() == name; });

        if (it != employees.end()) {
            it->setSalary(newSalary);
            cout << "Salary updated successfully for employee " << name << endl;
        } else {
            cout << "Employee not found with name " << name << endl;
        }
    }

    void printEmployees() {
        cout << setw(15) << "Name" << setw(10) << "Age" << setw(10) << "Gender" << setw(15) << "Salary" << endl;

        for (const auto& employee : employees) {
            cout << setw(15) << employee.getName() << setw(10) << employee.getAge() << setw(10)
                 << employee.getGender() << setw(15) << employee.getSalary() << endl;
        }
    }

private:
    bool validateInput(int value, const string& message, function<bool(int)> condition) {
        if (!condition(value)) {
            cout << "Invalid " << message << endl;
            return false;
        }
        return true;
    }

    bool validateInput(double value, const string& message, function<bool(double)> condition) {
        if (!condition(value)) {
            cout << "Invalid " << message << endl;
            return false;
        }
        return true;
    }

    bool validateInput(char value, const string& message, function<bool(char)> condition) {
        if (!condition(value)) {
            cout << "Invalid " << message << endl;
            return false;
        }
        return true;
    }
};

int main() {
    ManageEmployees manager;

    return 0;
}
