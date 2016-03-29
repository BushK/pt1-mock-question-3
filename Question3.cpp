///////////////////////////////////////////////////////////////////////////////////////////////////
//                         COMPUTER METHODS 3 PRACTICAL TEST 1 (MOCK)
// Name:Kabo Onesmo Mabusha
// Student No: 21576451
// Date: 2016/03/29
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

// ***** QUESTION 3 ******
// Question 3 has 3 parts
// 3.1 Using the MINIMAL "Fraction" class provided, overload the greater than operator to work with
//     objects of class Fraction as a NON-MEMBER FUNCTION.   You may modify the Fraction class to 
//     demonstrate friendship.  DO NOT USE FLOATING POINT MATH!!!
// 3.2 Overload two functions called "add" which take two arguements, an integer and a fraction (in 
//     either order) and return a fraction.  
// 3.3 create a driver program to test your overloaded > operators and your overloaded 

class Fraction {
private:
	int num;				// numerator;
	int denom;				// denominator;
public:
	Fraction(int n, int d) : num(n), denom(d) { };
	friend int operator > (Fraction fract1, Fraction fract2);
	void print() { cout << num << "/" << denom; };
	friend Fraction add(int Wnumber, Fraction f);
	friend Fraction add(Fraction f, int Wnumber);
};

Fraction add(int Wnumber, Fraction f) {
	Fraction Result((Wnumber * f.denom) + f.num, f.denom);
	return Result;
}
Fraction add(Fraction f, int Wnumber) {
	return add(Wnumber, f);
}
//A function that cross multiplies to create common denominator then compares numerator
int operator > (Fraction fract1, Fraction fract2) {
	int num1, num2;
	num1 = fract1.num * fract2.denom;
	num2 = fract2.num * fract1.denom;
	if (num1 > num2)
		return 1;
	else
	return 0;
}

int main() {
	Fraction fract1(8, 10);
	Fraction fract2(3, 4);
	if (fract1 > fract2)
		cout << "It is greater" << endl;
	cout << endl;
	cout << endl;
	Fraction Result = add(1, fract1);
	Result.print();
	cout << endl;
	cout << endl;
	Result = add(fract2, 1);
	Result.print();
	cout << endl;
	cout << endl;
}