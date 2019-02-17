#include "complex.h"

double getInput(string displayString) {
	double x;
	cout << displayString;
	cin >> x;
	cin.ignore();

	return x;
}

int main() {
	const int n = 10; // Number of iterations to check if number in mandlebrot

	double startx = getInput("Enter start X point: ");
	double stopx = getInput("Enter stop X point: ");
	if (startx >= stopx) {
		cout << "Error! starting X point must be less than stopping X point" << endl;
		cin.get();
		return 1;
	}

	double starty = getInput("Enter start Y point (will be complex component): ");
	double stopy = getInput("Enter start Y point (will be complex component): ");
	if (starty >= stopy) {
		cout << "Error! starting Y point must be less than stopping Y point" << endl;
		cin.get();
		return 1;
	}

	double stepsize =  getInput("Enter stepsize: ");
	if (stepsize <= 0) {
		cout << "Error! Stepsize must be a positive value. You entered: " << to_string(stepsize) << endl;
		cin.get();
		return 1;

	}

	complex c;
	double x;
	double y = stopy;
	while (y >= starty) {
		x = startx;
		cout << " ";
		while (x <= stopx) {
			c.setVals(x, y);
			if (accept(c, n)) {
				cout << "X";
			}
			else {
				cout << "_";
			}
			x += stepsize;
		}
		cout << endl;
		y -= stepsize;
	}

	cin.get();
	return 0;
}