#include <iostream>
#include <cmath>
#include <valarray>

using namespace std;

int main() {
	double alpha, burningSpeed, rocketMass, fuelMass, earthMass, gasesSpeed; 
	cin >> alpha >> burningSpeed >> rocketMass >> fuelMass >> earthMass >> gasesSpeed;
	double currentSpeedX, currentSpeedY;
	double currentSpeed = 0;
	double x0 = 0;
	double y0 = 0;
	double G;

	while (fuelMass > 0) {
		if (x0 != 0) {
			G = (6.67 * pow(10, -11) * earthMass) / x0;
			cout << G;
		}
		else {
			G = 0;
		}
		double prevSpeed = currentSpeed;
		currentSpeed = burningSpeed * gasesSpeed / (rocketMass + fuelMass);
		currentSpeedX = cos(alpha) * currentSpeed;
		currentSpeedY = sin(alpha) * currentSpeed;

		x0 = x0 + currentSpeedX * 1 + cos(alpha) * (currentSpeed - prevSpeed) / 2;
		y0 = y0 + currentSpeedY * 1 + (sin(alpha) * (currentSpeed - prevSpeed) - G) / 2;

		alpha = atan(currentSpeedY / currentSpeedX);

		cout << "xCoordinate " << x0 << " yCoordinate " << y0 << " currentSpeed " << currentSpeed << " fuelMass " << fuelMass << endl;

		fuelMass -= burningSpeed;
	}

	return 0;
}
