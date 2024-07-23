//
// Created by Mohamed on 7/22/2024.
//

#ifndef LEARNING_CLSDATE_H
#define LEARNING_CLSDATE_H
#pragma once
#pragma warning (disable:4996)
#include <bits/stdc++.h>
#include "clsstring.h"

using namespace std;

class clsdate{
private:

    short _day;
    short _month;
    short _year;
    bool check_format(string date_format){
        int count_frontslash=0;
        int pos=0;
        while((pos=date_format.find('/'))!=string::npos){
            date_format.erase(0,pos+1);
            count_frontslash++;
        }
        if(count_frontslash!=2){
            return false;
        }
        return true;
    }
    static short gergorian_cal(short year,short month,short day) {

        int a = (14 - month) / 12;
        int y = year - a;
        int m = month + (12 * a) - 2;
        int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12))%7;
        return d;

    }
    enum encompare
    {
        before =-1,
        equal=0,
        after=1

    };
public:

    static clsdate today_date() {
        clsdate date;
        time_t t = time(0);
        tm* now = localtime(&t);
        date.set_year(now->tm_year + 1900);
        date.set_month(now->tm_mon + 1);
        date.set_day(now->tm_mday);
        return date;
    }
    clsdate(){
        time_t t = time(0);
        tm* now = localtime(&t);
        _year = now->tm_year + 1900;
        _month = now->tm_mon + 1;
        _day = now->tm_mday;
    }
    clsdate(string date_format){
        if(!check_format(date_format)){
            cout<<"please enter the write format";
            return;
        }
        vector <string> vDate;
        vDate = clsstring::Split(date_format, "/");
        _day = stoi(vDate[0]);
        _month = stoi(vDate[1]);
        _year = stoi(vDate[2]);
        if(!is_this_date_true(*this)){
            cout<<"the date is wrong";
            return;
        }
    }

    clsdate(int day,int month,int year){
     _day=day;
     _month=month;
     _year=year;
        if(!is_this_date_true(*this)){
            cout<<"the date is wrong";
            return;
        };
    }
    clsdate(int days,int year){
       vector<int>date= the_days_form_beginning_of_year_to_date(days,year);
        _day=date[0];
        _month=date[1];
        _year=date[2];
        if(!is_this_date_true(*this)){
            cout<<"the date is wrong";
            return;
        };
    }
     void set_day(int day){
        if(!is_day_true(day)){
            cout<<"enter a valid number of days for month "<<this->month()
            <<" there are only "<<the_number_of_days_in_month(this->year(),this->month())<<" days "<<endl;
            return ;
        }
      _day=day;

      }
    void set_month(int month){
        if(!is_month_true(month)){
            cout<<"enter a valid number of months  "<<endl;
            return;
        }
        _month=month;
    }
    void set_year(int year){
        if(!is_year_true(year)){
            cout<<"enter a valid number of year"<<endl;
            return;
        }
        _year=year;
    }
    int day(){
        return _day;
    }
    int month(){
        return _month;
    }
    int year(){
        return _year;
    }
    bool is_day_true(int day){
        if (the_number_of_days_in_month(this->year(), this->month()) < day||day<1) {
            return false;
        }
        return true;
    }
    bool is_month_true(int month){
        if (month < 1 || month>12) {
            return false;
        }
        return true;
    }
    bool is_year_true(int year){
        if ( year < 1) {
            return false;
        }
        return true;
    }

    bool is_this_date_true(clsdate date) {
        if (!is_month_true(date.month())) {
            return false;
        }
        if (!is_day_true(date.day())) {
            return false;
        }
        if (!is_year_true(date.year())) {
            return false;
        }
        return true;

    }


    static vector<int> the_days_form_beginning_of_year_to_date(short days,short year) {
        short remaining_days = days;
        short count_month = 1;
        int days_count = 0;
        vector<int>date(3);
        while (true)
        {
            short days_in_month =the_number_of_days_in_month(year, count_month);
            if (remaining_days > days_in_month) {
                remaining_days -= days_in_month;
                count_month++;
            }
            else {
                days_count=remaining_days ;
                break;

            }

        }
        date[0]=days_count;
        date[1]=count_month;
        date[2]=year;
        return date;
    }

   static bool leap_year(short year) {
        return (year%400==0||(year%4==0&&year%100!=0))? true: false;

    }
    bool leap_year(){
        return leap_year(_year);
    }
   static int the_number_of_days_in_year(short year) {

        return leap_year(year) ? 366 : 365;
    }
   static int the_number_of_hours_in_year(short year) {

        return the_number_of_days_in_year(year)*24;
    }
    static int the_number_of_min_in_year(short year) {

        return the_number_of_hours_in_year(year)*60;
    }
    static int the_number_of_sec_in_year(short year) {

        return the_number_of_min_in_year(year) * 60;
    }
     int the_number_of_days_in_year() {

        return the_number_of_days_in_year(_year);
    }
    int the_number_of_hours_in_year() {

        return the_number_of_hours_in_year(_year);
    }
    int the_number_of_min_in_year() {

        return the_number_of_min_in_year(_year);
    }
    int the_number_of_sec_in_year() {

        return the_number_of_sec_in_year(_year);
    }


   static int the_number_of_days_in_month(short year,short month) {
        if (month < 1 || month>12) {
            cout<<"month should be between 1 and 12";
            return 0;
        }
        if (month == 2) {
            return leap_year(year) ? 29 : 28;
        }
        int month_31[7] = { 1,3,5,7,8,10,12 };
        for (int i = 0; i < 7; i++)
        {
            if (month_31[i] == month) {
                return 31;
            }
        }
        return 30;
    }
   static int the_number_of_hours_in_month(short year, short month) {

        return the_number_of_days_in_month(year,month)*24;
    }
   static int the_number_of_min_in_month(short year, short month) {

        return the_number_of_hours_in_month(year,month)*60;
    }
   static int the_number_of_sec_in_month(short year,short month) {

        return the_number_of_min_in_month(year,month) * 60;
    }

     int the_number_of_days_in_month() {
         return the_number_of_days_in_month(_year,_month);
    }

     int the_number_of_hours_in_month() {
         return the_number_of_hours_in_month(_year,_month);
    }
     int the_number_of_min_in_month() {
         return the_number_of_min_in_month(_year,_month);

    }
      int the_number_of_sec_in_month() {

          return the_number_of_sec_in_month(_year,_month);
      }

   static string which_day_is_this_date(int day,int month,int year) {
        short day_index= gergorian_cal(year,month,day);
        switch (day_index)
        {
            case 0:
                return"sun";
            case 1:
                return"mon";
            case 2:
                return"tue";
            case 3:
                return"wed";
            case 4:
                return"thur";
            case 5:
                return"fri";
            case 6:
                return"sat";
            default:
                break;
        }

    }

    string which_day_is_this_date(){
        return which_day_is_this_date(_day,_month,_year);
    }
   static string month_name(short month) {
        string month_names[12]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
        return month_names[month - 1];
    }
   static void calendar_for_month( short year, short month) {
        int first_day = gergorian_cal(year, month, 1);
        int number_of_days = the_number_of_days_in_month(year, month);
        printf("\n________________%s_________________\n\n", month_name(month).c_str());
        printf("  sun  mon  tues  wed  thur  fri  sat \n");
        int space = 0;
        for (int i = 0; i < first_day; i++) {
            printf("     ");
            space++;
        }
        for (int i = 1; i <= number_of_days; i++) {
            space++;
            printf("%5d", i);
            if (space == 7) {
                space = 0;
                cout << endl;
            }

        }

    }
    string month_name(){
        return month_name(_month);
    }
    void calendar_for_month(){
        calendar_for_month(_year,_month);
    }
   static void calendar_for_year(short year) {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", year);
        printf("  _________________________________\n");
        for (int i = 1; i <=12; i++)
        {
            calendar_for_month(year, i);
            cout << endl;
        }

    }
    void calendar_for_year() {
        calendar_for_year(_year);
    }
   static short days_from_beg_of_year(short year,short month,short day ) {
        short days = day;
        for (short i = 1; i < month ; i++)
        {
            days += the_number_of_days_in_month(year, i);

        }
        return days;
    }
    short days_from_beg_of_year( ) {
        return days_from_beg_of_year(_year,_month,_day);
    }
    void add_days_to_date(int added_days) {
        int days = added_days + days_from_beg_of_year(this->year(),this->month(),this->day());
        this->set_month(1);
        while (true)
        {
            short month_days = the_number_of_days_in_month(this->year(), this->month());
            if (days>month_days) {
                days -= month_days;
                  this->set_month(++this->_month);
                if (this->month() > 12) {
                    this->set_month(1);
                    this->set_year(++this->_year);
                }
            }
            else {
                this->set_day(days);
                break;
            }

        }

    }
    static string compare_two_dates(clsdate date1, clsdate date2) {
        if (date1.year() > date2.year()) {
            return " date 1 is greater than date 2";
        }
        if (date1.year() < date2.year()) {
            return " date 2 is greater than date 1";
        }
        if (date1.year() == date2.year() && date1.month()>date2.month()) {
            return " date 1 is greater than date 2";
        }
        if (date1.year() == date2.year() && date1.month() < date2.month()) {
            return " date 2 is greater than date 1";
        }
        if (date1.year() == date2.year() && date1.month() == date2.month() &&date1.day()>date2.day()) {
            return " date 1 is greater than date 2";
        }
        if (date1.year() == date2.year() && date1.month() == date2.month() && date1.day() <date2.day()) {
            return " date 2 is greater than date 1";
        }
        else {
            return"they are equal";
        }
    }
    string compare_two_dates(clsdate date){
        return compare_two_dates(*this,date);
    }

   static bool is_last_day_in_month(clsdate date) {
        return (date.day() == the_number_of_days_in_month(date.year(), date.month()));
    }
   static bool is_last_month_in_year(clsdate date) {
        return (date.month()==12);
    }
    bool is_last_day_in_month(){
        return is_last_day_in_month(*this);
    }
    bool is_last_month_in_year() {
        return is_last_day_in_month(*this);
    }
    static void inc_date_by_one(clsdate &date) {
        if (is_last_day_in_month(date)) {
            if (is_last_month_in_year(date)) {
                date.set_day(1);
                date.set_month(1);
                date._year++;
            }

            else
            {
                date.set_day(1);
                date._month++;
            }

        }

        else {
            date._day++;
        }


    }
    void inc_date_by_one() {
        inc_date_by_one(*this);
    }
   static bool is_date1_before_date2(clsdate date1,clsdate date2) {

        return (date1.year() < date2.year()) ? true : (date1.year() == date2.year() && date1.month() < date2.month()) ? true :
                                                  (date1.year() == date2.year() && date1.month() ==
                                                  date2.month() && date1.day() < date2.day()) ? true : false;
    }
    bool is_date_before_date2(clsdate date){
        return is_date1_before_date2(*this,date);
    }
   static void swap_dates(clsdate &date1,clsdate &date2) {
        clsdate temp;
        temp = date1;
        date1 = date2;
        date2 = temp;
    }
    static int get_diffrence(clsdate date1,clsdate date2) {
        int days = 0;
        short swap_flag_sign = 1;
        if (!is_date1_before_date2(date1, date2)) {
            swap_dates(date1, date2);
            swap_flag_sign = -1;
        }
        while (is_date1_before_date2(date1,date2))
        {

            days++;
            inc_date_by_one(date1);
        }
        return days;

    }
    int get_diffrence(clsdate date){
        return get_diffrence(*this,date);
    }
    static int age_in_days(clsdate date){
        return get_diffrence(date,today_date());
    }
    int age_in_days(){
        return age_in_days(*this);
    }

    void inc_date_by_x( int days = 10) {
        for (int i = 0; i < days; i++)
        {
            inc_date_by_one(*this);

        }


    }
    void inc_date_by_one_week() {
        for (int i = 0; i < 7; i++)
        {
            inc_date_by_one(*this);

        }


    }
    void inc_date_by_x_week(int weeks=10) {
        for (int i = 0; i < weeks; i++)
        {
            inc_date_by_one_week();

        }

    }

    void inc_date_by_one_month_faster() {
        if (is_last_month_in_year(*this)) {
            this->set_month(1);
            this->_year++;
        }
        else {
            this->_month++;

        }
        if (this->day()> the_number_of_days_in_month(this->year(), this->month())) {
            this->set_day(the_number_of_days_in_month(this->year(), this->month()));

        }
    }
    void inc_date_by_x_month(int month=5) {
        for (int i = 0; i <month; i++)
        {
            inc_date_by_one_month_faster();

        }

    }
    void inc_date_by_one_year() {
        for (int i = 0; i < 12; i++)
        {
            inc_date_by_one_month_faster();

        }
    }
    void inc_date_by_x_years( int years = 10) {
        for (int i = 0; i < years; i++)
        {
            inc_date_by_one_year();
        }

    }
    void inc_date_by_x_years_faster( int years = 10) {
        this->set_year(this->year()+years);

    }
    void inc_date_by_one_decade() {
        inc_date_by_x_years( 10);


    }

    void inc_date_by_x_decades(int decades=10) {
        for (int i = 0; i < decades; i++)
        {
            inc_date_by_one_decade();

        }

    }
    void inc_date_by_x_decades_faster( int decades = 10) {
        this->set_year(this->year()+decades * 10);
    }
    void inc_date_by_one_century() {
        this->set_year(this->year()+100);
    }
    void inc_date_by_one_millennium() {
        this->set_year(this->year()+1000);

    }
    void dec_date_by_one() {
        if (this->day()==1) {
            if (this->month() == 1) {
                this->set_month(12);
                this->_year--;
                this->set_day(the_number_of_days_in_month(this->year(), this->month()));
            }
            else {
                this->_month--;
                this->set_day(the_number_of_days_in_month(this->year(), this->month()));

            }
        }


        else {
            this->_day--;
        }
    }

    void dec_date_by_x( int days = 10) {
        for (int i = 0; i < days; i++)
        {
            dec_date_by_one();

        }


    }

    void dec_date_by_one_week() {
        for (int i = 0; i < 7; i++)
        {
            dec_date_by_one();

        }


    }

    void dec_date_by_x_week(int weeks=10) {
        for (int i = 0; i < weeks; i++)
        {
            dec_date_by_one_week();

        }

    }


    void dec_date_by_one_month_faster() {
        if (this->month()==1) {
            this->set_month(12);
            this->_year--;

        }
        else {
            this->_month--;


        }

        if (this->day()>the_number_of_days_in_month(this->year(), this->month())) {
            this->set_day(the_number_of_days_in_month(this->year(), this->month()));

        }

    }

    void dec_date_by_x_month(int month=5) {
        for (int i = 0; i <month; i++)
        {
            dec_date_by_one_month_faster();

        }

    }

    void dec_date_by_one_year() {
        this->_year--;
    }

    void dec_date_by_x_years(int years = 10) {
        for (int i = 0; i < years; i++)
        {
            dec_date_by_one_year();
        }

    }

    void dec_date_by_x_years_faster(int years = 10) {
        this->set_year(this->_year-years);

    }

    void dec_date_by_one_decade() {
        this->set_year(this->_year-10);
    }

    void dec_date_by_x_decades(int decades=10) {
        for (int i = 0; i < decades; i++)
        {
            dec_date_by_one_decade();

        }

    }
    void dec_date_by_x_decades_faster(int decades = 10) {
        this->set_year(this->_year-decades*10);

    }
    void dec_date_by_one_century() {
        this->set_year(this->_year-100);

    }
    void dec_date_by_one_millennium() {
        this->set_year(this->_year-1000);

    }
    static string day_order_to_text(short day_index) {
        string days[]{ "sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
        return days[day_index];
    }
  static  bool is_end_week(clsdate date) {
        string day = day_order_to_text(gergorian_cal(date.year(),date.month(),date.day()));
        cout << "is it the end of the week? " << endl;
        if (day == "saturday") {
            return true;
        }
      return false;
    }
   static void until_end_week(clsdate date) {
        short index = gergorian_cal(date.year(), date.month(), date.day());
        cout << "days until end of week: " << 6 - index << " day(s)" << endl;
    }



   static bool is_weekend(clsdate date) {
        string day = day_order_to_text(gergorian_cal(date.year(), date.month(), date.day()));
        if (day == "saturday"|| day == "friday") {
            return true;
        }
       return false;
    }
    static void until_endmonth(clsdate date) {
        short day_of_month = the_number_of_days_in_month(date.year(), date.month());
        cout << "days until end of month: " <<day_of_month-date.day() << " day(s)"<<endl;
    }
   static bool is_bussniess_day(clsdate date) {
        string day = day_order_to_text(gergorian_cal(date.year(), date.month(), date.day()));
        cout << "is it business day? " << endl;
        if (day == "saturday" || day == "friday") {
            return false;
        }
       return true;
    }
    static void until_endyear(clsdate date) {
        cout << "days until end of year: " <<the_number_of_days_in_year(date.year())-
        days_from_beg_of_year(date.year(),date.month(),date.day()) << " day(s)" << endl;
    }
      bool is_end_week() {
          return is_end_week(*this);
    }
     void until_end_week() {
         until_end_week(*this);
     }

     bool is_weekend() {
         return is_weekend(*this);
    }
     void until_endmonth() {
        until_endmonth(*this);
    }
     bool is_bussniess_day() {
         return is_bussniess_day(*this);
    }
     void until_endyear() {
         until_endyear(*this);
    }
    static short calculate_vacation_days_from_to( clsdate date1,clsdate date2) {
        short vac_days = 0;
        while (is_date1_before_date2(date1, date2)) {
            if (is_weekend(date1)) {
                inc_date_by_one(date1);
                continue;
            }
            vac_days++;
            inc_date_by_one(date1);
        }
        return vac_days;
    }
    short calculate_vacation_days_from_to(clsdate date){
        return calculate_vacation_days_from_to(*this,date);
    }
  static bool date1_equal_date2(clsdate date1, clsdate date2) {

        return date1.day() == date2.day() && date1.month()== date2.month() && date1.year() == date2.year();
    }

    static bool date1_after_date2(clsdate date1, clsdate date2) {
        return !is_date1_before_date2(date1,date2)&&!date1_equal_date2(date1,date2);
    }
    bool date_equal_date2(clsdate date){
        return date1_equal_date2(*this,date);
    }
    bool date_after_date2(clsdate date) {
        return date1_after_date2(*this,date);
    }

    static encompare comparator_date(clsdate date1, clsdate date2) {
        if (is_date1_before_date2(date1, date2)) {
            return encompare::before;
        }
        if (date1_equal_date2(date1, date2)) {
            return encompare::equal;

        }
        else {
            return encompare::after;
        }
    }
    encompare comparator_date(clsdate date){
        return comparator_date(*this,date);
    }
    static bool does_overlap_of_two_periods(clsdate period1_start_date,clsdate period1_end_date,clsdate period2_start_date,clsdate period2_end_date) {

        if (comparator_date(period2_end_date, period1_start_date) ==before||
            comparator_date(period1_end_date, period2_start_date) ==before) {
            return false;
        }
        return true;

    }
   static int get_diff_of_period(clsdate period_start_date, clsdate period_end_date) {
        return get_diffrence(period_start_date, period_end_date);
    }
     int get_diff_of_period(clsdate period_end_date) {
        return get_diffrence(*this, period_end_date);
    }
    static bool checker_within_period(clsdate period_start_date,clsdate period_end_date,clsdate date_to_check) {
        if (comparator_date(period_start_date, date_to_check) == before &&
            comparator_date(period_end_date, date_to_check) == after) {
            return true;
        }
        if (comparator_date(period_start_date, date_to_check) == equal||
            comparator_date(period_end_date, date_to_check) == equal) {
            return true;
        }
        return false;
    }
    bool check_date_within_period(clsdate period_start_date,clsdate period_end_date) {
        return checker_within_period(period_start_date,period_end_date,*this);
    }

   static string date_to_string(clsdate date) {
        string date_str;
        date_str += to_string(date.day()) + "/";
        date_str += to_string(date.month()) + "/";
        date_str += to_string(date.year()) ;
        return date_str;

    }
    string date_to_string() {
        return date_to_string(*this);
    }

    void print(){
        cout<<date_to_string();
    }
};


#endif //LEARNING_CLSDATE_H
