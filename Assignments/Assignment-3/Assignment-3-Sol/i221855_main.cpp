#include<iostream>
#include"rational.h"
using namespace std;
int main()
{
	//Rational R1(10, 20);
	//Rational R4(20, 50);
	//Rational R2(5);
	//Rational R3(R1);
	Rational::initializeMaxRational(10, 5);
	Rational R1,R4;
	cout << "Enter R1 Values: " << endl;
	cin >> R1;
	cout << "Enter R2 Values: " << endl;
	cin >> R4;
	Rational R2(5);
	Rational R3(R1);
	int option = 0;
	cout << " CHOOSE THE OPTION YOU WANT TO PERFORM TO THE RATIONAL OBJECTS: " << endl;
	cout << "------------- ARITHMATIC OPERATORS ---------------" << endl;
	cout << "[1] ADDITION       " << endl;
	cout << "[2] SUBTRACTION    " << endl;
	cout << "[3] MULTIPLICATION " << endl;
	cout << "[4] DIVISION       " << endl;
	cout << endl;
	cout << "------------- COMPARISON OPERATORS ----------------" << endl;
	cout << "[5]  EQUALITY              " << endl;
	cout << "[6]  INEQUALITY            " << endl;
	cout << "[7]  GREATOR THAN          " << endl;
	cout << "[8]  LESS THAN             " << endl;
	cout << "[9]  GREATOR THAN EQUAL TO " << endl;
	cout << "[10] LESS THAN EQUAL TO    " << endl;
	cout << endl;
	cout << "---------------- UNARY OPERATORS--------------------" << endl;
	cout << "[11]  PRE-FIX INCREMENT " << endl;
	cout << "[12]  PRE-FIX DECREMENT " << endl;
	cout << "[13]  UNARY MINUS       " << endl;
	cout << "[14]  UNARY PLUS        " << endl;
	cout << "[15]  LOGICAL NOT       " << endl;
	cout << endl;
	cout << "--------------- ASSIGNMENT OPERATORS------------------" << endl;
	cout << "[16] ASSIGNMENT OPERATOR " << endl;
	cout << endl;
	cout << "------------ ARITHMATIC ASSIGNMENT OPERATORS----------" << endl;
	cout << "[17] ADDITION ASSIGNMENT       " << endl;
	cout << "[18] SUBTRACTION ASSIGNMENT    " << endl;
	cout << "[19] MULTIPLICATION ASSIGNMENT " << endl;
	cout << "[20] DIVISION ASSIGNMENT       " << endl;
	cout << endl;
	cout << "[21] EXIT                      " << endl;
	cin >> option;
	cin.ignore();
	cout << endl;
	Rational max = Rational::getMaxRational();
	cout << "Max Rational: " << max << endl;
	int total = Rational::getTotalRationals();
	cout << "Total Rationals: " << total << endl;
	cout << endl;
	switch (option)
	{
	case 1:
	{
		cout << "[1] ADDITION " << endl;
		Rational SUM = R4 + R1;
		cout << SUM << endl;
	}
	case 2:
	{
		cout << "[2] SUBTRACTION " << endl;
		Rational MINUS = (R4 - R1);
		cout << MINUS << endl;
	}
	case 3:
	{
		cout << "[3] MULTIPLICATION " << endl;
		Rational MULTIPLICATION = R4 * R1;
		cout << MULTIPLICATION;
	}
	case 4:
	{
		cout << "[4] DIVISION " << endl;
		Rational DIVISION = R4 / R1;
		cout << DIVISION << endl;
	}
	case 5:
	{
		cout << "[6]  EQUALITY" << endl;
		bool EQUALITY = R4 == R1;
		if (EQUALITY)
		{
			cout << "Both the rational fractions are equal!!" << endl << endl;

		}
		else
		{
			cout << "Both the rational fractions are not equal!!" << endl << endl;
		}
	}
	case 6:
	{
		cout << "[7]  INEQUALITY" << endl;
		bool INEQUALITY = (R4 != R1);
		if (INEQUALITY)
		{
			cout << "Both the rational fractions are Inequal!!" << endl << endl;
		}
		else
		{
			cout << "Both the rational fractions are equal!!" << endl << endl;
		}
	}
	case 7:
	{
		cout << "[8]  GREATOR THAN" << endl;
		bool GREATORTHAN = (R4 > R1);
		if (GREATORTHAN)
		{
			cout << "YES! R4 is greator than R1 !!" << endl << endl;
		}
		else
		{
			cout << "NO! R4 is not greator than R1 !!" << endl << endl;
		}
	}
	case 8:
	{
		cout << "[8]  LESS THAN" << endl;
		bool LESSTHAN = (R4 < R1);
		if (LESSTHAN)
		{
			cout << "YES! R4 is less than R1 !!" << endl << endl;
		}
		else
		{
			cout << "NO! R4 is not less than R1 !!" << endl << endl;
		}
	}
	case 9:
	{
		cout << "[9] GREATOR THAN EQUAL TO " << endl;
		bool GREATORTHANEQUALTO = (R4 >= R1);
		if (GREATORTHANEQUALTO)
		{
			cout << " YES! R4 is greator than equal to R1 !!" << endl << endl;
		}
		else
		{
			cout << " NO! R4 is not greator than equal to R1 !!" << endl << endl;
		}
	}
	case 10:
	{
		cout << "[10] LESS THAN EQUAL TO " << endl;
		bool LESSTHANEQUALTO = (R4 <= R1);
		if (LESSTHANEQUALTO)
		{
			cout << " YES! R4 is less than equal to R1 !!" << endl << endl;
		}
		else
		{
			cout << " NO! R4 is not less than equal to R1 !!" << endl << endl;
		}
	}
	case 11:
	{
		cout << "[11]  PRE-FIX INCREMENT" << endl;
		cout << ++R1;
	}
	case 12:
	{

		cout << "[12]  PRE-FIX DECREMENT" << endl;
		cout << --R1;


	}
	case 13:
	{
		Rational r13 = -R1;
		cout << "[13]  UNIARY MINUS " << endl;
		cout << r13;
		break;

	}
	case 14:
	{
		Rational r13 = +R1;
		cout << "[13]  UNIARY MINUS " << endl;
		cout << r13;
		break;
	}
	case 15:
	{
		bool a = !R1;
		if (a)
		{
			cout << "Logical Not Operator: R1 is zero" << endl;
		}
		else
		{
			cout << "Logical Not Operator: R1 is not zero" << endl;
		}
		break;
	}
	case 16:
	{
		cout << "[17] ASSIGNMENT OPERATOR " << endl;
		R1 = R2;
		cout << R1 << endl;
		cout << R2 << endl;
	}
	case 17:
	{
		cout << "[18] ADDITION ASSIGNMENT " << endl << endl;
		cout << "BEFORE ADDITION ASSIGNMENT: " << endl;
		cout << R1;
		cout << R2;

		R1 += R2;

		cout << "AFTER ADDITION ASSIGNMENT: " << endl;
		cout << R1;
		cout << R2;
	}
	case 18:
	{
		cout << "[19] SUBTRACTION ASSIGNMENT " << endl << endl;
		cout << "BEFORE SUBTRACTION ASSIGNMENT: " << endl;
		cout << R1;
		cout << R2;
		R1 -= R2;
		cout << "AFTER SUBTRACTION ASSIGNMENT: " << endl;
		cout << R1;
		cout << R2;
	}
	case 19:
	{
		cout << "[20] MULTIPLICATION ASSIGNMENT " << endl << endl;
		cout << "BEFORE MULTIPLICATION ASSIGNMENT: " << endl;
		cout << R1;
		cout << R2;
		R1 *= R2;
		cout << "AFTER MULTIPLICATION ASSIGNMENT: " << endl;
		cout << R1;
		cout << R2;
	}

	case 20:
	{
		exit(0);
	}
	default:
		cout << "INVALID INPUT!!" << endl;
	}
}