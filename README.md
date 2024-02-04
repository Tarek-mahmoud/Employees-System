# Employee Management System

A C++ program for managing employees with basic functionalities. Allows adding new employees, viewing employee details, deleting employees based on age, and updating salaries by name.

## Table of Contents

- [Employee Class](#employee-class)
- [ManageEmployees Class](#manageemployees-class)
- [Main Function](#main-function)
- [Documentation](#documentation)

## Employee Class

The `Employee` class represents an individual employee with attributes such as name, age, salary, and gender.

### Public Member Functions

1. **getName():** Returns the name of the employee.
2. **setName(const std::string& newName):** Sets the name of the employee.
3. **getAge():** Returns the age of the employee.
4. **setAge(int newAge):** Sets the age of the employee.
5. **getSalary():** Returns the salary of the employee.
6. **setSalary(double newSalary):** Sets the salary of the employee.
7. **getGender():** Returns the gender of the employee.
8. **setGender(char newGender):** Sets the gender of the employee.
9. **operator<:** Overloaded less than operator for comparing employees based on age.

## ManageEmployees Class

The `ManageEmployees` class provides functionalities for managing a collection of employees.

### Public Member Functions

1. **ManageEmployees():** Constructor that initiates the program loop.
2. **list():** Displays a menu for user interaction and calls corresponding functions.
3. **addEmployee():** Adds a new employee to the collection.
4. **layoffEmployees():** Removes employees older than a specified age.
5. **updateSalary():** Updates the salary of an employee by their name.
6. **printEmployees():** Displays a formatted list of all employees.

### Private Member Functions

1. **validateInput(int value, const string& message, function<bool(int)> condition):** Validates integer input.
2. **validateInput(double value, const string& message, function<bool(double)> condition):** Validates double input.
3. **validateInput(char value, const string& message, function<bool(char)> condition):** Validates character input.

## Main Function

The `main()` function creates an instance of `ManageEmployees` to initiate the program.

## Documentation

This documentation provides a high-level overview of the classes and their functionalities in the Employee Management System. Feel free to enhance it further based on your specific needs.

---

Feel free to modify and expand the documentation as needed for your project.
