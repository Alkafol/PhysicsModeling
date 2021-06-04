#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	long double PI = 3.1415;
	long double alpha, burningSpeed, rocketMass, fuelMass, gasesSpeed;
	cout << "Enter angle, gases burning speed, rocket mass, fuel mass, gases speed" << endl;
	cin >> alpha >> burningSpeed >> rocketMass >> fuelMass >> gasesSpeed;
	alpha = alpha * PI / 180;
	long double currentSpeedX = 0;
	long double currentSpeedY = 0;
	long double acceleration = 0;
	long double currentSpeed = 0;
	long double x0 = 0;
	long  double y0 = 0;
	const long double G = 6.67 * pow(10, -11);
	const int R = 6371302;
	long double earthMass = 5.97 * pow(10, 24);
	long double g;

	while (y0 >= 0) {
		g = (G * earthMass) / pow(y0 + R, 2);
		if (fuelMass > 0) {
			acceleration = burningSpeed * gasesSpeed / (rocketMass + fuelMass);
		}
		else {
			acceleration = 0;
		}
		//cout << acceleration << " - acceleration" << endl;
		currentSpeedX = currentSpeedX + cos(alpha) * acceleration;
		currentSpeedY = currentSpeedY + sin(alpha) * acceleration - g;
		//cout << currentSpeedX << " - currentSpeedX" << endl;
		//cout << currentSpeedY << " - currentSpeedY" << endl;
		currentSpeed = sqrt(pow(currentSpeedX, 2) + pow(currentSpeedY, 2));

		x0 = x0 + currentSpeedX;
		y0 = y0 + currentSpeedY;

		fuelMass -= burningSpeed;
		if (fuelMass < 0) {
			fuelMass = 0;
		}
		cout << "xCoordinate " << x0 << " yCoordinate " << y0 << " currentSpeed " << currentSpeed << " fuelMass " << fuelMass << endl;

	}

	return 0;
}
