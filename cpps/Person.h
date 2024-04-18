#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "wstring_handler.h"

using namespace std;

static wstring nullws(L""); 

class Person;
class Ancester {
friend ostream &operator<<(ostream&, const Ancester&);
friend wistream &operator>>(wistream&, Ancester&);
public:
    Ancester() : name(nullws), sex(nullws), death_time(nullws), ID_number(nullws) { }
    inline void set_name(const wstring &n) { name = n; } 
    inline void set_sex(const wstring &sx) { sex = sx; }
    inline void set_death_time(const wstring &dt) { death_time = dt; }
    inline void set_id(const wstring &id) { ID_number = id; }
    inline void add_heir(Person &p) { heirs.push_back(p); }
    void remove_heir(const Person*);
private:
    wstring name;
    wstring sex;
    wstring death_time;
    wstring ID_number;
    vector<Person> heirs;  // 采用智能指针，可共享Person对象
    
};

inline void Ancester::remove_heir(const Person *p) 
{  
    auto it = find(heirs.begin(), heirs.end(), *p);
    if (it != heirs.end()) {    // 判断被删除的人是否存在
        heirs.erase(it);
    }
}

ostream &operator<<(ostream &os, const Ancester &anc)
{
    static const string comma("，");
    os << to_byte_string(anc.name) << comma << to_byte_string(anc.sex) << comma 
       << "于" << to_byte_string(anc.death_time) << "去世" << comma 
       << "生前身份证号码：" << to_byte_string(anc.ID_number) << "。";
    return os;
}
wistream &operator>>(wistream &in, Ancester &anc)
{
    in >> anc.name >> anc.sex >> anc.death_time >> anc.ID_number; 
    if (!in) {
        anc = Ancester();
    }
    return in;
}


class Person {
friend ostream &operator<<(ostream&, const Person&);
friend wistream &operator>>(wistream&, Person&);
friend bool operator==(const Person&, const Person&);
friend bool operator!=(const Person&, const Person&);   // 重载了相等运输算符，一般就应该重载不等运算符
public:   
    // 普通构造函数，同时也是默认构造函数
    Person(const wstring &nam = nullws, const wstring &sx = nullws, const wstring &bir = nullws, 
           const wstring &add = nullws, const wstring &id = nullws, const wstring &rel = nullws, const bool gu = false) :
        name(nam), sex(sx), birthday(bir), address(add), 
        ID_number(id), relation(rel), give_up(gu) { }
    // 拷贝构造函数
    Person(const Person &p) :
        name(p.name), sex(p.sex), birthday(p.birthday), address(p.address), 
        ID_number(p.ID_number), relation(p.relation), give_up(p.give_up) { }
    inline void set_name(const wstring &n) { name = n; } 
    inline void set_sex(const wstring &sx) { sex = sx; }
    inline void set_birthday(const wstring &bir) { birthday = bir; }
    inline void set_address(const wstring &add) { address = add; }
    inline void set_id(const wstring &id) { ID_number = id; }
    inline void set_relation(const wstring &rel) { relation = rel; }
    inline void set_giveUp(bool gu) { give_up = gu; }
private: 
    wstring name;
    wstring sex;
    wstring birthday;
    wstring address;
    wstring ID_number;
    wstring relation;
    bool give_up;
};


ostream &operator<<(ostream &os, const Person &p)
{
    static const wstring comma(L"，");
    os << to_byte_string(p.name) << to_byte_string(comma) << to_byte_string(p.sex) << to_byte_string(comma) << "生于" << to_byte_string(p.birthday)
       << to_byte_string(comma) << "公民身份号码：" << to_byte_string(p.ID_number) << "。";
    return os;
}

wistream &operator>>(wistream &in, Person &p)
{
    in >> p.name >> p.sex >> p.birthday >> p.address 
       >> p.ID_number >> p.relation;
    if (!in) {
        p = Person();
    }
    return in;
}

bool operator==(const Person &lp, const Person &rp)
{
    return lp.ID_number == rp.ID_number;
}

bool operator!=(const Person &lp, const Person &rp)
{
    return !(lp == rp);
}
#endif