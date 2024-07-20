
// Created by Mohamed on 7/20/2024.
#ifndef LEARNING_CLSSTRING_H
#define LEARNING_CLSSTRING_H
#pragma once
#include <bits/stdc++.h>
using namespace std;
class clsstring{
    string _value;
public:
    clsstring(){
        _value="";
    }
    clsstring(string value){
        _value=value;
    }
    void set_value(string value){
        _value=value;
    }
    string value(){
        return _value;
    }
    static void first_letter_of_each_word(string name) {
        bool is_first_letter = true;
        for (int i = 0; i < name.size(); i++)
        {
            if (name.at(i) != ' ' && is_first_letter)
            {
                cout << name.at(i) << " ";
            }
            is_first_letter = (name.at(i) == ' ') ? true : false;
        }
    }
    void first_letter_of_each_words(){
        return first_letter_of_each_word(_value);
    }
    static void upper_first_letter_in_each_word(string &name){
        bool is_first_letter = true;
        for (int i = 0; i < name.size(); i++)
        {
            if (name.at(i) != ' ' && is_first_letter)
            {
                name.at(i)=toupper(name.at(i));
            }
            is_first_letter = (name.at(i) == ' ') ? true : false;

        }
    }
    void upper_first_letter_in_each_word(){
        upper_first_letter_in_each_word(_value);
    }

    static  void lower_first_letter_in_each_word (string &name) {
        bool is_first_letter = true;
        for (int i = 0; i < name.size(); i++)
        {
            if (name.at(i) != ' ' && is_first_letter)
            {
                name.at(i) = tolower(name.at(i));
            }
            is_first_letter = (name.at(i) == ' ') ? true : false;
        }

    }
    void lower_first_letter_in_each_word(){
        return lower_first_letter_in_each_word(_value);
    }

    static char invert_letters(char letter) {
        return isupper(letter) ? tolower(letter) : toupper(letter);
    }
    static void invert_letters_in_string(string &name) {

        for (int i = 0; i < name.size(); i++)
        {
            if(isalpha(name.at(i))) {
                name.at(i) = invert_letters(name.at(i));
            }
        }


    }
    void invert_letters_in_string(){
        return invert_letters_in_string(_value);
    }


    static vector<int> count_uppercase_lowercase(string name) {
        vector<int>upper_lower_count(2);
        for (int i = 0; i < name.size(); i++)
        {
            if (isalpha(name.at(i))  &&  isupper(name.at(i))) upper_lower_count[0]++;

            else if(isalpha(name.at(i))&& islower(name.at(i))) upper_lower_count[1]++;
        }
        return upper_lower_count;
    }
    void count_uppercase_lowercase(){

        vector<int>upper_lower_count(2);
        upper_lower_count=count_uppercase_lowercase(_value);
        cout<<"upper letters count is: "<<upper_lower_count[0]<<endl;
        cout<<"lower letters count is: "<<upper_lower_count[1]<<endl;

    }

    static int count_a_letter(string value,char letter){
        int count=0;
        for (int i = 0; i < value.size(); ++i) {
            if(value.at(i)==letter){
                count++;
            }
        }
        return count;
    }
    int count_a_letter(char letter_to_count){
        return count_a_letter(_value,letter_to_count);
    }

    static void print_words(string input) {
        string space = " ";
        short pos = 0;
        while ((pos = input.find(space)) != string::npos) {

            string word = input.substr(0, pos);
            if (word != "") {
                cout << word << endl;
            }


            input.erase(0, pos + space.length());
        }
        if(input!=""){
            cout << input << endl;
        }

    }
    void print_words(){
        return print_words(_value);
    }

    static short count_words(string input) {
        string space = " ";
        short pos = 0;
        short count = 0;
        while ((pos = input.find(space)) != string::npos) {

            string word = input.substr(0, pos);
            if (word != "") {
                count++;
            }

            input.erase(0, pos + space.length());
        }
        if (input != "") {
            count++;
        }

        return count;
    }
    short count_words(){
        return count_words(_value);
    }


    static void ReplaceWords(string &S1, string WordSerachFor, string ReplaceTo)
    {
        int pos;
        while ((pos = S1.find(WordSerachFor)) != string::npos) {

            S1 = S1.replace(pos, WordSerachFor.size(), ReplaceTo);

        }
    }
    void ReplaceWords(string WordSerachFor, string ReplaceTo){
        return ReplaceWords(_value,WordSerachFor,ReplaceTo);
    }
   static bool check_vowel(char letter) {
        switch (letter)
        {
            case 'a': case 'A':
            case 'e': case 'E':
            case 'i': case 'I':
            case 'o':case 'O':
            case 'u':case 'U':
                return 1;
                break;
            default:
                return 0;
                break;
        }
    }
     static short count_vowel(string input) {
        short count = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if (check_vowel(input.at(i))) {
                count++;
            }
        }
        return count;
    }
    short count_vowel(){
        return count_vowel(_value);
    }
    static void upper_all_string(string &input){
        for (int i = 0; i < input.size(); ++i) {
            if(islower(input.at(i))){
                input.at(i)=toupper(input.at(i));
            }
        }

    }
    void upper_all_string(){
        upper_all_string(_value);
    }

    static void lower_all_string(string &input){
        for (int i = 0; i < input.size(); ++i) {
            if(isupper(input.at(i))){
                input.at(i)=tolower(input.at(i));
            }
        }

    }
    void lower_all_string(){
        lower_all_string(_value);
    }
    static vector<string> Split(string S1, string Delim)
    {

        vector<string> vString;

        short pos = 0;
        string sWord; // define a string variable

        // use find() function to get the position of the delimiters
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word
            if (sWord != "")
            {
                vString.push_back(sWord);
            }

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;

    }

    vector<string> Split( string Delim)
    {
        return Split(_value, Delim);
    }

   static void reverse_word_in_string(string value){
        vector<string>words= Split(value," ");
        vector<string>::iterator end_words=words.end();
        while(end_words!=words.begin()){
            end_words--;
            cout<<*end_words<<" ";
        }
    }
    void reverse_word_in_string(){
        reverse_word_in_string(_value);
    }
    static string RemovePunctuations(string S1) {
        string S2 = "";

        for (short i = 0; i < S1.length(); i++) {
            if (!ispunct(S1[i])) {
                S2 += S1[i];
            }
        }

        return S2;

    }
    void RemovePunctuations(){
       _value=RemovePunctuations(_value);
    }

    };


#endif //LEARNING_CLSSTRING_H
