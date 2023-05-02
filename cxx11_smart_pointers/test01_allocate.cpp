#include <memory>
#include <iostream>
#include "Person.h"

void test01_allocate() {

    Person *raw1;
    std::shared_ptr<Person> shared2, shared3, shared4;
    std::unique_ptr<Person> unique5, unique6;
    std::weak_ptr<Person> weak7, weak8, weak9, weak10;

    std::cout << "START testing allocation" << std::endl;

    //
    // Raw pointers
    //
    raw1 = new Person();   // WARN: "Clang-Tidy: Use auto when initializing with new to avoid duplicating the type name_"

    //
    // Shared pointers
    //
    // shared2 = new Person();   // ERROR: "No viable conversion from 'Person *' to 'std::shared_ptr<Person>'"
    shared3 = std::make_shared<Person>();
    shared4 = std::shared_ptr<Person>(new Person());   // BAD: This will perform two allocations. WARN: "Clang-Tidy: Use std::make_shared instead"

    //
    // Unique pointers
    //
    // unique5 = new Person();   // ERROR: "No viable conversion from 'Person *' to 'std::unique_ptr<Person>'"
    unique6 = std::unique_ptr<Person>(new Person());

    //
    // Weak pointers
    //
    // weak7 = new Person();   // ERROR: "No viable conversion from 'Person *' to 'std::weak_ptr<Person>'"
    // weak8 = raw1;   // ERROR: "No viable conversion from 'Person *' to 'std::weak_ptr<Person>'"
    // weak9 = unique6;   // ERROR: "No viable conversion from 'std::unique_ptr<Person>' to 'std::weak_ptr<Person>'"
    weak10 = shared4;

    std::cout << "FINISHED testing allocation" << std::endl;
}