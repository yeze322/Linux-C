/*************************************************************************
	> File Name: 7.4_Person.cpp
	> Author: Yeze
	> Mail: a@b.com
	> Created Time: 2015年03月11日 星期三 21时00分41秒
 ************************************************************************/

#include<iostream>
#include<string>
using std::string;
class Person {
private:
    string name;
    string address;
public:
    inline void showPerson() const{
        std::cout<<name<<std::endl<<address<<std::endl;
    }
    string getName() const;
    //return the name and address should be const, because they don't change the value
};


string Person::getName() const{
    return name;
}
