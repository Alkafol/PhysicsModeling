#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){

	double outerRadius, innerRadius, h, length, V0, eps, U, F, E;
	double q = -1.6 * pow(10, -19);
	double m = 9.1 * pow(10, -31);

	cin >> U >> outerRadius >> h >> length >> eps >> V0;

	double currentSpeedX, currentSpeedY;
	currentSpeedX = V0;
	currentSpeedY = 0;

	innerRadius = outerRadius - h;
	double r = (outerRadius + innerRadius) / 2;
	double x = 0;
	double y = r - innerRadius;
	double acceleration = 0;
	double currentSpeed = 0;

	int i = 0;
	while ((x <= length) && (r <= outerRadius) && (r >= innerRadius)) {

		E = U / (r * log(outerRadius / (outerRadius - h))); // E для бесконечно протяженной нити (цилиндра)
		F = q * E;

		acceleration = F / m;
		currentSpeedY += acceleration;
		r += currentSpeedY;
		x += currentSpeedX;
		y = r - innerRadius;
		currentSpeed = sqrt(pow(currentSpeedX, 2) + pow(currentSpeedY, 2));
		cout << "X: " << x << " Y: " << y << " Current speed (Y): " << currentSpeedY << " CurrentSpeed: " << currentSpeed << " Acceleration: " << acceleration << endl;

		++i;
	}

	return 0;
}
