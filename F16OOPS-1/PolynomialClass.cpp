/*
Title: Polynomial Class

Problem statement
Implement a polynomial class, that contains following functions -

1. setCoefficient -
This function sets coefficient for a particular degree value. If term with given degree is not there
in the polynomial, then corresponding term (with specified degree and value) is added. If the term is
already present in the polynomial, then previous coefficient value is replaced by given coefficient
value.

2. add -
Adds two polynomials and returns a new polynomial which has the result.

3. subtract -
Subtracts two polynomials and returns a new polynomial which has the result.

4. multiply -
Multiplies two polynomials and returns a new polynomial which has the result.

5. print -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of
degree. Print pattern for a single term : "x" And multiple terms should be printed separated by space.
For more clarity, refer sample test cases.
Note : Only keep those terms which have non - zero coefficients.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains count of the number of coefficients in polynomial 1(C1)
The next line of input has C1 degrees for polynomial 1.
The next line of input has C1 coefficients for polynomial 1.
The next line of input contains count of the number of coefficients in polynomial 2(C2)
The next line of input has C2 degrees for polynomial 2.
The next line of input has C2 coefficients for polynomial 2.
The next line of input has the choice for the function you want to implement.

Output Format:
The output will be printed in case of print function same as that of print function format.

Sample Input 1 :
P1 : 1x2 2x3 4x6
P2 : 3x4 1x2

Sample Output 1 :
P1 + P2 = 2x2 2x3 3x4 4x6

Sample Input 2 :
P1 : 1x2 2x3 4x6
P2 : 3x4 1x2

Sample Output 2 :
P1 - P2 = 2x3 -3x4 4x6
*/

#include<iostream>
using namespace std;

class Polynomial{
	public:
		int degree = 10;
		int *poly = new int[degree + 1];

		void setCoefficient(int degree, int coeff) {
			if(degree > this->degree) {
				int *temp = new int[degree];

				for(int i = 0; i < this->degree; i++) {
					temp[i] = poly[i];
				}

				poly = temp;
				this->degree = degree;
			}

			poly[degree] = coeff;
			return;
		}

		Polynomial add(Polynomial p) {
			Polynomial result;

			int i = 0;
			int j = 0;

			while(i <= this->degree && j <= p.degree) {
				result.setCoefficient(i, this->poly[i] + p.poly[j]);
				i++;
				j++;
			}

			while(i <= this->degree) {
				result.setCoefficient(i, this->poly[i]);
				i++;
			}

			while(j <= p.degree) {
				result.setCoefficient(j, p.poly[j]);
				j++;
			}

			return result;
		}

		Polynomial subtract(Polynomial p) {
			Polynomial result;

			int i = 0;
			int j = 0;

			while(i <= this->degree && j <= p.degree) {
				result.setCoefficient(i, this->poly[i] - p.poly[j]);
				i++;
				j++;
			}

			while(i <= this->degree) {
				result.setCoefficient(i, this->poly[i]);
				i++;
			}

			while(j <= p.degree) {
				result.setCoefficient(j, p.poly[j]);
				j++;
			}

			return result;
		}

		Polynomial multiply(Polynomial p) {
			Polynomial result;

			for(int i = 0; i <= this->degree; i++) {
				for(int j = 0; j <= p.degree; j++) {
					result.setCoefficient(i+j, result.poly[i+j] + this->poly[i] * p.poly[j]);
				}
			}

			return result;
		}

		void print() {
			for(int i = 0; i <= this->degree; i++) {
				if(this->poly[i] != 0) {
					cout << this->poly[i] << "x" << i << " ";
				}
			}
			cout << endl;
		}
};

int main() {
    int count1,count2,choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }

    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }

    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }

    cin >> choice;

    Polynomial result;

    switch(choice) {
		// Add
		case 1:
			result = first.add(second);
			result.print();
			break;

		// Subtract
		case 2 :
			result = first.subtract(second);
			result.print();
			break;

		// Multiply
		case 3 :
			result = first.multiply(second);
			result.print();
			break;
    }

    return 0;
}