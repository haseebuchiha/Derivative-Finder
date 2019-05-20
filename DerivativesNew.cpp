#include<iostream>
#include<string>
using namespace std;

int main() {
	//take a character array 
	string eq;
	cin >> eq;
	
	string eqnew;

	for (int i = 0; i < eq.length(); i++)
	{
		//if you find a variable
		if ((eq[i] >= 'a' && eq[i] <= 'z') || (eq[i] >= 'A' && eq[i] <= 'Z'))
		{
			string power;
			string coeff;
			//cout << "found a variable" << endl;
			//look to the left of the variable
			if (eq[i - 1] >= '0' && eq[i - 1] <= '9')
			{
				//cout << "i found a number" << endl;
				coeff = eq[i - 1];
			}
			else
			{
				coeff = "1";
			}
			//cout << coeff << endl;

			//Look to the right
			int j = 2;
			if (eq[i + 1] == '^')
			{
				while (eq[i + j] != '+' && eq[i + j] != '-' && eq[i + j] != '\0')
				{
					if (eq[i + j] >= '0' && eq[i + j] <= '9')
					{	
						//cout << "i found power" << endl;
						power += eq[i + j];
					}
					j++;
				}
			}
			else
			{
				power = "1";
			}

			//Now you have the power and the coefficient
			//cout << power << endl;
			int coeffNum = stoi(coeff);
			int powerNum = stoi(power);
			//Multiply coefficient and the power
			coeffNum *= powerNum;
			//Subtract 1 from the power
			powerNum -= 1;
			
			//if the power of the polynomial is 1
			if (powerNum == 0)
			{
				eqnew += to_string(coeffNum); //Make the variable disappear
			}
			else
			{
				eqnew += to_string(coeffNum) + eq[i] + "^" + to_string(powerNum); //Write to the new string
			}

			//Conditions for signs after the polynomials 
			{
				if (eq[i + 1] == '\0')
				{
					break;
				}
				if (eq[i + j] == '\0')
				{
					break;
				}
				if (eq[i + 1] == '+')
				{
					eqnew += '+';
				}
				else if (eq[i + j] == '+')
				{
					eqnew += '+';
				}
				if (eq[i + 1] == '-')
				{
					eqnew += '-';
				}
				else if (eq[i + j] == '-')
				{
					eqnew += '-';
				}
			}
		}
	}
	cout <<"After derivation "<<eqnew;
	return 0;
}