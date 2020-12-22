#include <iostream>
#include <string>
#include <iomanip>
#include "colormod.h" // namespace Color

using namespace std;

int main()

{    // Implement colored terminal output
    Color::Modifier red(Color::FG_RED);
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier green(Color::FG_GREEN);
    Color::Modifier cyan(Color::FG_CYAN);
    Color::Modifier lightRed(Color::FG_LIGHT_RED);
    Color::Modifier def(Color::FG_DEFAULT);

    // Display welcome text in a box of stars
    const int width = 38;
    const char c = '*';

    string horizontal_line(width, c);
    string horizontal_line_empty(c + string(width - 2, c) + c);

    cout << green;
    cout << horizontal_line << endl << horizontal_line_empty << endl;
    cout << c << setw(width - 2) << left << string("Welcome to the Cyclotron Simulator!") << c << endl;
    cout << horizontal_line_empty << endl << horizontal_line << endl;
    cout << def;

    cout << endl;
    cout << endl;


    double speedOfLight = 299792458;
    // Critical inputs
    double mass, charge, speed, radius, magneticFieldStrength;

    cout << "Before we start, I need to know what information you have" << endl;
    cout << "Are you missing any of the information below about the particle? (Y or N)" << endl;
    cout << endl;

    cout << "1) Mass of the particle" << endl;
    cout << "2) Charge of the particle" << endl;
    cout << "3) Speed of the particle" << endl;
    cout << "4) Radius of the path taken by the particle" << endl;
    cout << "5) Magentic Field Strength acting on the particle" << endl;
       
    string yesOrNo;
    cin >> yesOrNo;

    string missingInput;

    if (yesOrNo == "Y" || yesOrNo == "y") {
        int missingNumber;
        cout << "What input are you mssing? (1 2 3 4 or 5)" << endl;
        cin >> missingNumber;

        switch (missingNumber) {
        case 1:
            missingInput = "mass";
            break;
        case 2:
            missingInput = "charge";
            break;
        case 3:
            missingInput = "speed";
            break;
        case 4:
            missingInput = "radius";
            break;
        case 5:
            missingInput = "magnetic field strength";
            break;
       }
    }
    else {
        yesOrNo = "N";
    }

    // Case when all inputs are provided
    if (yesOrNo == "N") {
        cout << lightRed;

        cout << "What is the mass of the accelerating particle? (Leave answer in MeV/c^2)" << endl;
        cin >> mass;
        mass *= 1.79 * pow(10, -30);

        cout << "What is the charge of the accelerating particle? (Leave answer in quantized charge units)" << endl;
        cin >> charge;
        charge *= 1.602 * pow(10, -19);

        cout << "What is the speed of the accelerating particle? (Leave answer in terms of c)" << endl;
        cin >> speed;
        speed *= speedOfLight;

        cout << "What is the radius of the path taken by the particle? (Leave answer in terms of meters)" << endl;
        cin >> radius;

        cout << def;

        magneticFieldStrength = mass * speed / (fabs(charge) * radius);

        double nonRelAngularSpeed;
        nonRelAngularSpeed = speed / radius;

        double nonRelKMax;
        nonRelKMax = (pow(charge, 2) * pow(magneticFieldStrength, 2) * pow(radius, 2)) / (2 * mass);

        double lorentzFactor;
        lorentzFactor = 1 / pow(1 - pow(speed, 2) / pow(speedOfLight, 2), 0.5);

        double relAngularSpeed = 1 / lorentzFactor;

        double relativisticTotalEnergy;
        relativisticTotalEnergy = lorentzFactor * mass * pow(speedOfLight, 2);


        cout << endl;
        cout << endl;

        cout << cyan;
        cout << "The non-relativistic angular speed of the particle is " << nonRelAngularSpeed << " rad/s" << endl;
        cout << "The relativistic angular speed of the particle is " << relAngularSpeed << " rad/s" << endl;
        cout << "The non-relativistic maximum kinetic energy of the particle is " << nonRelKMax << " J" << endl;
        cout << "The Lorentz Factor of the particle is " << lorentzFactor << endl;
        cout << "The total relativistic energy of the particle is " << relativisticTotalEnergy << " J" << endl;
        cout << def;

        cout << endl;
        cout << endl;
        
        const int width = 24;
        const char c = '*';

        string horizontal_line(width, c);
        string horizontal_line_empty(c + string(width - 2, c) + c);

        cout << green;
        cout << horizontal_line << endl << horizontal_line_empty << endl;
        cout << c << setw(width - 2) << left << string("Hope this was helpful!") << c << endl;
        cout << horizontal_line_empty << endl << horizontal_line << endl;
        cout << def;

        cout << endl;
        cout << endl;

        return 0;
    }

    if (missingInput == "mass") {
        cout << lightRed;

        cout << "What is the charge of the accelerating particle? (Leave answer in quantized charge units)" << endl;
        cin >> charge;
        charge *= 1.602 * pow(10, -19);

        cout << "What is the speed of the accelerating particle? (Leave answer in terms of c)" << endl;
        cin >> speed;
        speed *= speedOfLight;

        cout << "What is the radius of the path taken by the particle? (Leave answer in terms of meters)" << endl;
        cin >> radius;

        cout << "What is the strength of the magnetic field acting on the particle? (Leave answers in Teslas)" << endl;
        cin >> magneticFieldStrength;

        cout << def;

        mass = magneticFieldStrength * (fabs(charge) * radius) / speed;

        double nonRelAngularSpeed;
        nonRelAngularSpeed = speed / radius;

        double nonRelKMax;
        nonRelKMax = (pow(charge, 2) * pow(magneticFieldStrength, 2) * pow(radius, 2)) / (2 * mass);

        double lorentzFactor;
        lorentzFactor = 1 / pow(1 - pow(speed, 2) / pow(speedOfLight, 2), 0.5);

        double relAngularSpeed = 1 / lorentzFactor;

        double relativisticTotalEnergy;
        relativisticTotalEnergy = lorentzFactor * mass * pow(speedOfLight, 2);

        cout << endl;
        cout << endl;

        cout << cyan;

        cout << "The mass of the particle is " << mass << " kg" << endl;
        cout << "The non-relativistic angular speed of the particle is " << nonRelAngularSpeed << " rad/s" << endl;
        cout << "The relativistic angular speed of the particle is " << relAngularSpeed << " rad/s" << endl;
        cout << "The non-relativistic maximum kinetic energy of the particle is " << nonRelKMax << " J" << endl;
        cout << "The Lorentz Factor of the particle is " << lorentzFactor << endl;
        cout << "The total relativistic energy of the particle is " << relativisticTotalEnergy << " J" << endl;
        
        cout << def;

        cout << endl;
        cout << endl;

        const int width = 24;
        const char c = '*';

        string horizontal_line(width, c);
        string horizontal_line_empty(c + string(width - 2, c) + c);

        cout << green;

        cout << horizontal_line << endl << horizontal_line_empty << endl;
        cout << c << setw(width - 2) << left << string("Hope this was helpful!") << c << endl;
        cout << horizontal_line_empty << endl << horizontal_line << endl;

        cout << def;

        cout << endl;
        cout << endl;

        return 0;
    }

    if (missingInput == "charge") {
        cout << lightRed;

        cout << "What is the mass of the accelerating particle? (Leave answer in MeV/c^2)" << endl;
        cin >> mass;
        mass *= 1.79 * pow(10, -30);

        cout << "What is the speed of the accelerating particle? (Leave answer in terms of c)" << endl;
        cin >> speed;
        speed *= speedOfLight;

        cout << "What is the radius of the path taken by the particle? (Leave answer in terms of meters)" << endl;
        cin >> radius;

        cout << "What is the strength of the magnetic field acting on the particle? (Leave answers in Teslas)" << endl;
        cin >> magneticFieldStrength;

        cout << def;

        charge = fabs(mass * speed / radius * magneticFieldStrength);

        double nonRelAngularSpeed;
        nonRelAngularSpeed = speed / radius;

        double nonRelKMax;
        nonRelKMax = (pow(charge, 2) * pow(magneticFieldStrength, 2) * pow(radius, 2)) / (2 * mass);

        double lorentzFactor;
        lorentzFactor = 1 / pow(1 - pow(speed, 2) / pow(speedOfLight, 2), 0.5);

        double relAngularSpeed = 1 / lorentzFactor;

        double relativisticTotalEnergy;
        relativisticTotalEnergy = lorentzFactor * mass * pow(speedOfLight, 2);

        cout << endl;
        cout << endl;

        cout << cyan;

        cout << "The charge of the particle is " << charge << " C" << endl;
        cout << "The non-relativistic angular speed of the particle is " << nonRelAngularSpeed << " rad/s" << endl;
        cout << "The relativistic angular speed of the particle is " << relAngularSpeed << " rad/s" << endl;
        cout << "The non-relativistic maximum kinetic energy of the particle is " << nonRelKMax << " J" << endl;
        cout << "The Lorentz Factor of the particle is " << lorentzFactor << endl;
        cout << "The total relativistic energy of the particle is " << relativisticTotalEnergy << " J" << endl;

        cout << def;

        cout << endl;
        cout << endl;

        const int width = 24;
        const char c = '*';

        string horizontal_line(width, c);
        string horizontal_line_empty(c + string(width - 2, c) + c);

        cout << green;

        cout << horizontal_line << endl << horizontal_line_empty << endl;
        cout << c << setw(width - 2) << left << string("Hope this was helpful!") << c << endl;
        cout << horizontal_line_empty << endl << horizontal_line << endl;

        cout << def;

        cout << endl;
        cout << endl;

        return 0;
    }

    if (missingInput == "speed") {
        cout << lightRed;

        cout << "What is the mass of the accelerating particle? (Leave answer in MeV/c^2)" << endl;
        cin >> mass;
        mass *= 1.79 * pow(10, -30);

        cout << "What is the charge of the accelerating particle? (Leave answer in quantized charge units)" << endl;
        cin >> charge;
        charge *= 1.602 * pow(10, -19);

        cout << "What is the radius of the path taken by the particle? (Leave answer in terms of meters)" << endl;
        cin >> radius;

        cout << "What is the strength of the magnetic field acting on the particle? (Leave answers in Teslas)" << endl;
        cin >> magneticFieldStrength;

        cout << def;

       speed = magneticFieldStrength * fabs(charge) * radius / mass;

        double nonRelAngularSpeed;
        nonRelAngularSpeed = speed / radius;

        double nonRelKMax;
        nonRelKMax = (pow(charge, 2) * pow(magneticFieldStrength, 2) * pow(radius, 2)) / (2 * mass);

        double lorentzFactor;
        lorentzFactor = 1 / pow(1 - pow(speed, 2) / pow(speedOfLight, 2), 0.5);

        double relAngularSpeed = 1 / lorentzFactor;

        double relativisticTotalEnergy;
        relativisticTotalEnergy = lorentzFactor * mass * pow(speedOfLight, 2);

        cout << endl;
        cout << endl;

        cout << cyan;

        cout << "The speed of the particle is " << speed << " m/s" << endl;
        cout << "The non-relativistic angular speed of the particle is " << nonRelAngularSpeed << " rad/s" << endl;
        cout << "The relativistic angular speed of the particle is " << relAngularSpeed << " rad/s" << endl;
        cout << "The non-relativistic maximum kinetic energy of the particle is " << nonRelKMax << " J" << endl;
        cout << "The Lorentz Factor of the particle is " << lorentzFactor << endl;
        cout << "The total relativistic energy of the particle is " << relativisticTotalEnergy << " J" << endl;

        cout << def;

        cout << endl;
        cout << endl;

        const int width = 24;
        const char c = '*';

        string horizontal_line(width, c);
        string horizontal_line_empty(c + string(width - 2, c) + c);

        cout << green;

        cout << horizontal_line << endl << horizontal_line_empty << endl;
        cout << c << setw(width - 2) << left << string("Hope this was helpful!") << c << endl;
        cout << horizontal_line_empty << endl << horizontal_line << endl;

        cout << def;

        cout << endl;
        cout << endl;

        return 0;
    }

    if (missingInput == "radius") {
        cout << lightRed;

        cout << "What is the mass of the accelerating particle? (Leave answer in MeV/c^2)" << endl;
        cin >> mass;
        mass *= 1.79 * pow(10, -30);

        cout << "What is the charge of the accelerating particle? (Leave answer in quantized charge units)" << endl;
        cin >> charge;
        charge *= 1.602 * pow(10, -19);

        cout << "What is the speed of the accelerating particle? (Leave answer in terms of c)" << endl;
        cin >> speed;
        speed *= speedOfLight;

        cout << "What is the strength of the magnetic field acting on the particle? (Leave answers in Teslas)" << endl;
        cin >> magneticFieldStrength;

        cout << def;

        radius = fabs(mass * speed / charge * magneticFieldStrength);

        double nonRelAngularSpeed;
        nonRelAngularSpeed = speed / radius;

        double nonRelKMax;
        nonRelKMax = (pow(charge, 2) * pow(magneticFieldStrength, 2) * pow(radius, 2)) / (2 * mass);

        double lorentzFactor;
        lorentzFactor = 1 / pow(1 - pow(speed, 2) / pow(speedOfLight, 2), 0.5);

        double relAngularSpeed = 1 / lorentzFactor;

        double relativisticTotalEnergy;
        relativisticTotalEnergy = lorentzFactor * mass * pow(speedOfLight, 2);

        cout << endl;
        cout << endl;

        cout << cyan;

        cout << "The radius of the path taken by the particle is  " << radius << " m" << endl;
        cout << "The non-relativistic angular speed of the particle is " << nonRelAngularSpeed << " rad/s" << endl;
        cout << "The relativistic angular speed of the particle is " << relAngularSpeed << " rad/s" << endl;
        cout << "The non-relativistic maximum kinetic energy of the particle is " << nonRelKMax << " J" << endl;
        cout << "The Lorentz Factor of the particle is " << lorentzFactor << endl;
        cout << "The total relativistic energy of the particle is " << relativisticTotalEnergy << " J" << endl;

        cout << def;

        cout << endl;
        cout << endl;

        const int width = 24;
        const char c = '*';

        string horizontal_line(width, c);
        string horizontal_line_empty(c + string(width - 2, c) + c);

        cout << green;

        cout << horizontal_line << endl << horizontal_line_empty << endl;
        cout << c << setw(width - 2) << left << string("Hope this was helpful!") << c << endl;
        cout << horizontal_line_empty << endl << horizontal_line << endl;

        cout << def;

        cout << endl;
        cout << endl;

        return 0;
    }

    if (missingInput == "magnetic field strength") {
        cout << lightRed;

        cout << "What is the mass of the accelerating particle? (Leave answer in MeV/c^2)" << endl;
        cin >> mass;
        mass *= 1.79 * pow(10, -30);

        cout << "What is the charge of the accelerating particle? (Leave answer in quantized charge units)" << endl;
        cin >> charge;
        charge *= 1.602 * pow(10, -19);

        cout << "What is the speed of the accelerating particle? (Leave answer in terms of c)" << endl;
        cin >> speed;
        speed *= speedOfLight;

        cout << "What is the radius of the path taken by the particle? (Leave answer in terms of meters)" << endl;
        cin >> radius;

        cout << def;

        magneticFieldStrength = mass * speed / (fabs(charge) * radius);

        double nonRelAngularSpeed;
        nonRelAngularSpeed = speed / radius;

        double nonRelKMax;
        nonRelKMax = (pow(charge, 2) * pow(magneticFieldStrength, 2) * pow(radius, 2)) / (2 * mass);

        double lorentzFactor;
        lorentzFactor = 1 / pow(1 - pow(speed, 2) / pow(speedOfLight, 2), 0.5);

        double relAngularSpeed = 1 / lorentzFactor;

        double relativisticTotalEnergy;
        relativisticTotalEnergy = lorentzFactor * mass * pow(speedOfLight, 2);

        cout << endl;
        cout << endl;

        cout << cyan;

        cout << "The magentic field operating on the particle has strength " << magneticFieldStrength << " T" << endl;
        cout << "The non-relativistic angular speed of the particle is " << nonRelAngularSpeed << " rad/s" << endl;
        cout << "The relativistic angular speed of the particle is " << relAngularSpeed << " rad/s" << endl;
        cout << "The non-relativistic maximum kinetic energy of the particle is " << nonRelKMax << " J" << endl;
        cout << "The Lorentz Factor of the particle is " << lorentzFactor << endl;
        cout << "The total relativistic energy of the particle is " << relativisticTotalEnergy << " J" << endl;

        cout << def;

        cout << endl;
        cout << endl;

        const int width = 24;
        const char c = '*';

        string horizontal_line(width, c);
        string horizontal_line_empty(c + string(width - 2, c) + c);

        cout << green;

        cout << horizontal_line << endl << horizontal_line_empty << endl;
        cout << c << setw(width - 2) << left << string("Hope this was helpful!") << c << endl;
        cout << horizontal_line_empty << endl << horizontal_line << endl;

        cout << def;

        cout << endl;
        cout << endl;

        return 0;
    }

    return 0;
}