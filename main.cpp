#include <iostream>
#include <float.h>
using namespace std;

#define SOLVE_FOR 66.0
#define MARGIN_OF_ERROR 0.001

#define START_VALUE 1.0
#define END_VALUE 10.0
#define INCREMENT_VALUE 1.0

#define EQUATION_SIZE 9
#define EQUATION_1 ((((((((v[0] + 13.0) * v[1]) / v[2]) + v[3] + 12.0) * v[4]) - v[5] - 11.0 + v[6]) * v[7]) / v[8]) - 10.0
#define EQUATION_2 v[0] + ((13.0 * v[1]) / v[2]) + v[3] + (12.0 * v[4]) - v[5] - 11.0 + ((v[6] * v[7]) / v[8]) - 10.0
#define EQUATION EQUATION_2
#define PRINT_RESULT value << ": " << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << ", " << v[4] << ", " << v[5] << ", " << v[6] << ", " << v[7] << ", " << v[8]
#define NO_VALUE DBL_MAX

double current = DBL_MAX;

void excludeLoop(double * v) {
	if (v[EQUATION_SIZE - 1] != NO_VALUE) {
		double value = EQUATION;
		if ((value <= (SOLVE_FOR + MARGIN_OF_ERROR) && value >= (SOLVE_FOR - MARGIN_OF_ERROR)) || abs(value - SOLVE_FOR) < abs(current - SOLVE_FOR)) {
			current = value;
			cout << PRINT_RESULT << endl;
		}
	} else {
		for (double next = START_VALUE; next < END_VALUE; next += INCREMENT_VALUE) {
			int i;
			for (i = 0; i < EQUATION_SIZE && v[i] != NO_VALUE; i++) {
				if (next == v[i]) {
					i = -1;
					break;
				}
			}
			if (i != -1) {
				v[i] = next;
				excludeLoop(v);
				v[i] = NO_VALUE;
			}
		}
	}
}

int main()
{
	double * v = new double[EQUATION_SIZE];
	for (int i = 0; i < EQUATION_SIZE; i++) {
		v[i] = NO_VALUE;
	}

	excludeLoop(v);

	delete v;

	system("PAUSE");
	return 0;
}
