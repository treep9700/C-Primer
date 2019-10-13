#ifndef C11_9_H_INCLUDED
#define C11_9_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class date {
public:
    friend ostream& operator<<(ostream&, const date&);     //运算符重载

    date() = default; /** C++11 新特性 default函数作用于类的特殊成员函数，为其自动生成默认的函数定义体，提高代码
                      的执行效率。C++11标准引入了一个新特性：default函数。程序员只需在类的特殊成员函数声明后
                      加上“=default;”，就可将该函数声明为 defaulted 函数，编译器将为显式声明的 defaulted 函数
                      自动生成函数体。    **********/
    date(string &ds);

    unsigned y() const {return year; }
    unsigned m() const {return month; }
    unsigned d() const {return day; }

private:
    unsigned year, month, day;
};

// 月份全称
const string month_name[]={"January","February","March","April","May","June","July","August","September","October","November","December"};

//月份简写
const string month_abbr[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","NOv","Dec"};

//每月天数
const int days[] = {0, 31,28,31,30,31,30,31,31,30,31,30,31};


/** 获取月份值，主要对"Jan 1, 2014", "February 1 2014"这两种情况进行处理 **/
inline int get_month(string &ds,int &end_of_month)     //该函数返回月份数字
{
    int i,j;
    for(i=0; i<12; i++){                       //先进行前缀匹配检查
    //检查每个宇符是否与月份简写相等
        for(j=0;j<month_abbr[i].size();j++)
            if(ds[j]!=month_abbr[i][j])//不是此月简写
                break;
            if(j==month_abbr[i].size())//与简写匹配
                break;
    }

    if(i== 12)     //与所有月份名都不相同
    throw invalid_argument("不是合法月份名");

    if(ds[j] == ' ') {
        end_of_month = j + 1;
        return i + 1;
    }

    for( ; j< month_name[i].size(); j++)
        if(ds[j]!=month_name[i][j])
            break;
        if(j == month_name[i].size() && ds[j] == ' ') {//月份全称
            end_of_month = j+1;
            return i+1;
        }
    throw invalid_argument("不是合法月份名");
}

inline int get_day(string &ds, int month, int&p){
    size_t q;

    int day = stoi(ds.substr(p), &q); //从p开始的部分转换为日期值
    if(day < 1 || day > days[month]){
        throw invalid_argument("不是合法日期值");
    }
    p += q;         //移动到日期值之后
    return day;
}

inline int get_year(string &ds,int &p) {
    size_t  q;

    int year =stoi(ds.substr(p),&q);//从p开始的部分转换为年
    if (p+q<ds.size())
    throw invalid_argument("非法结尾内容");

    return year;
}

date::date(string &ds) {
    int p;        //存储下标
    size_t q;
    int number;

    if((p = ds.find_first_of("0123456789"))==string::npos)
    throw invalid_argument("没有数字,非法日期");

    if(p > 0){     //月份名格式
        month = get_month(ds,p);
        day = get_day(ds,month,p);
        if (ds[p] != ' ' && ds[p] != ',')
            throw invalid_argument("非法间隔符1");
        p++;
        year = get_year(ds,p);
    } else {                      //月份值格式
        number = stoi(ds,&q);
        p = q;

        if( number >= 1 && number <= 12 && ds[p++] == '/' ) {
            month = number;
        day = get_day(ds,month,p);
        if (ds[p++]!= '/')           //这里为什么要有 p++
            throw invalid_argument("非法间隔符2");
        year = get_year(ds, p);
        } else {
            if(ds[p+1] <= 127 && ds[p+1] >= 0){              //间隔符不是汉字，则抛出异常
                //p++;
                throw invalid_argument("非法间隔符3");
            }

            year = number;

            //月份值格株式
            p += 3;                //指向月份数字,每个汉字在string中占三个字节
            string substring = ds.substr(p);
            month = stoi(substring, &q);
            p = q;

            if(month<1 || month>12)
                throw invalid_argument("不是合法月份值");
            if(substring[p] <= 127 && substring[p] >= 0)
                throw invalid_argument("非法间隔符");

            p += 3;
            day = get_day(substring, month, p);
            if(substring[p] <= 127 && substring[p] >= 0){
                throw invalid_argument("非法结尾");
            }
            if(p + 3 != substring.size())
                throw invalid_argument("非法结尾");
        }
    }
}

ostream&operator<<(ostream& out,const date&d) {
    out <<d.y() <<  "年" << d.m() << "月" << d.d() << "日" << endl;
    return out;
}

#endif // 11_9_H_INCLUDED
