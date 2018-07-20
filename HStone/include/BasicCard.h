/*************************************************************************
	> File Name: BasicCard.h
	> Author: Yeze
	> Mail: a@b.com
	> Created Time: 2015年03月11日 星期三 23时28分09秒
 ************************************************************************/

#ifndef _BASICCARD_H
#define _BASICCARD_H
using std::cout;
using std::string;

class BasicCard {
private:
    string cName;
    string cDescription;
    int cost;
//    string cPicPath;
public:
    BasicCard(const string& s1,const string& s2,int cost):\
    cName(s1),cDescription(s2),cost(cost){};
    BasicCard(): cName("NULL"), cDescription("Empty!"), cost(0) {};
    void print() const;
};

void BasicCard::print() const {
    cout<<cost<<"=========\n"<<cName<<"\n----------\n\n"\
    <<cDescription<<"\n=========="<<std::endl;
}
#endif
