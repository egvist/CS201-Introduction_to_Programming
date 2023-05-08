#include <iostream>
#include <string>
using namespace std;


int main()
{
	int countthe;
	int countq;
	double take_home_grade;
	double quiz_grade;
	string name;
	int the1, the2, the3, the4, the5, midterm, finalex, quiz1, quiz2, quiz3, quiz4;
	countthe = 0;
	countq = 0;
	cout << "The purpose of this program is to calculate your CS201 grade." << endl;

	
	cout << "What is your name? ";
	cin >> name;
		
	cout << "Hello "<<name<<", what are your midterm and final exam grades? ";
	cin >> midterm >> finalex;
	if (midterm == -100 || finalex == -100){
		cout << name << ", one of your midterm or final exam grade is -100, you will fail the course!" <<endl;
	}
	else if (midterm == -1){
		cout << name << ", you did not enter the midterm exam, you will fail the course!" << endl;}
	else if (finalex == -1){
		cout << name << ", you did not enter the final exam, you will fail the course!" << endl;
	}
	else { 
		double weighted_exam_avr =(0.30 * midterm + 0.30 * finalex) / 0.6;
		
		if (weighted_exam_avr < 30) {
			cout << name << ", your weighted exam average is less than 30, you will fail the course!" << endl;
		}
		else {
			
			cout << "What are the grades of your 5 take-home exams? ";
			cin >> the1 >> the2 >> the3 >> the4 >> the5;
			if (the1 == -100) {
				countthe += 1;}
			if (the2 == -100) {
				countthe += 1;}
			if (the3 == -100) {
				countthe += 1;}
			if (the4 == -100) {
				countthe += 1;}
			if (the5 == -100) {
				countthe += 1;}
			if (countthe >= 2) {
				cout << name << ", at least two of your THE grades are -100, you will fail the course!" << endl;}
			else {
				double submitted_take_home_avr =  0.01*(the1*3 + 4*(the2 + the3 + the4) + the5*5)/ 0.2;
				double ratiotakehome = submitted_take_home_avr / weighted_exam_avr;
				if (submitted_take_home_avr < 0) {
				    take_home_grade = submitted_take_home_avr ;}
				if (ratiotakehome <= 2) {
						take_home_grade = submitted_take_home_avr; } 
				else if (ratiotakehome < 3) {
					take_home_grade = submitted_take_home_avr * (3-ratiotakehome);}
				else if (ratiotakehome >= 3) {
					take_home_grade = 0; }
				cout << "What are the grades of your 4 quizzes? ";
				cin >> quiz1 >> quiz2 >> quiz3 >> quiz4;

				if (quiz1 == -100) {
					countq += 1;}
				if (quiz2 == -100) {
					countq += 1;}
				if (quiz3 == -100) {
					countq += 1;}
				if (quiz4 == -100) {
					countq += 1;}
				if (countq >= 2) {
					cout << name << ", at least two of your quiz grades are -100, you will fail the course!" << endl;}
				else if (countq + countthe >= 2) {
					cout << name << ", one of your THE and one of your quiz grades is -100, you will fail the course!" << endl; }
				else {
					double submitted_quiz_avr = 0.2*(quiz1+quiz2+quiz3+quiz4) / 0.8;
					double ratioquiz = submitted_quiz_avr/weighted_exam_avr;
					if (submitted_quiz_avr < 0) {
					    quiz_grade = submitted_quiz_avr;}
					else {
    					if (ratioquiz <= 2) {
    						quiz_grade = submitted_quiz_avr; }
    					else if (ratioquiz < 3) {
    						quiz_grade = submitted_quiz_avr * (3-ratioquiz); }
    					else if (ratioquiz >= 3) {
    						quiz_grade = 0 ; }
    					cout << name <<", your weighted exam average is: " << weighted_exam_avr << endl;
    					cout << name <<", your THE average is: " << submitted_take_home_avr << " and you will get " << take_home_grade << " of it." << endl;
    					cout << name <<", your quiz average is: " << submitted_quiz_avr << " and you will get " << quiz_grade << " of it." << endl;
    					double course_numberic_grade = quiz_grade * 0.2 + take_home_grade * 0.2 + midterm * 0.3 + finalex * 0.3;
    					cout << name <<", your grade for CS201 is: " << course_numberic_grade <<endl;
    					
    					return 0;
					}
				}
			}
		}
	}
}				
