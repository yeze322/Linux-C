/*************************************************************************
	> File Name: 7.1.cpp
	> Author: Yeze
	> Mail: a@b.com
	> Created Time: 2015年03月10日 星期二 22时11分20秒
 ************************************************************************/

#include<iostream>

class Sales_data {
public:
    inline std::string isbn() const; 
    Sales_data& combine(const Sales_data&);
    Sales_data(): units_sold(0),revenue(0.0) {}
private:
    double avg_price() const;
    unsigned units_sold;
    std::string bookNo;
    double revenue;
};
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&,const Sales_data&);
std::istream &read(std::istream&,Sales_data);

inline std::string Sales_data::isbn() const
{//got a implicit parameter:
 //(const Sales_data *const this)
    return bookNo; 
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
    //this is implicy pointer, but if we want to return itself, we still need call this explicy! 
    //"however we do need to use this to access the object as a whole"
}

int main()
{
    
}
