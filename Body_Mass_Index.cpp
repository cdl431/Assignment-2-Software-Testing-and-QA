#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate BMI
double calculateBMI(int feet, int inches, double pounds) {
    int totalInches = feet * 12 + inches;
    double meters = totalInches * 0.0254;
    double kg = pounds * 0.453592;

    double bmi = kg / (meters * meters);
    return round(bmi * 10) / 10.0; // round to 1 decimal
}

// Function to get category
string getCategory(double bmi) {
    if (bmi < 18.5)
        return "Underweight";
    else if (bmi <= 24.9)
        return "Normal weight";
    else if (bmi <= 29.9)
        return "Overweight";
    else
        return "Obese";
}

// Simple test function (TDD idea)
void runTests() {
    cout << "Running tests...\n";

    // Test BMI calculation
    double bmi = calculateBMI(5, 10, 160);
    if (bmi > 22 && bmi < 24)
        cout << "BMI test passed\n";
    else
        cout << "BMI test failed\n";

    // Boundary tests
    if (getCategory(18.4) == "Underweight") cout << "Test 1 passed\n";
    if (getCategory(18.5) == "Normal weight") cout << "Test 2 passed\n";
    if (getCategory(25.0) == "Overweight") cout << "Test 3 passed\n";
    if (getCategory(30.0) == "Obese") cout << "Test 4 passed\n";
}

int main() {
    runTests(); // TDD: run tests first

    int feet, inches;
    double pounds;

    cout << "\nEnter height (feet): ";
    cin >> feet;

    cout << "Enter height (inches): ";
    cin >> inches;

    cout << "Enter weight (pounds): ";
    cin >> pounds;

    double bmi = calculateBMI(feet, inches, pounds);
    string category = getCategory(bmi);

    cout << "\nBMI: " << bmi << endl;
    cout << "Category: " << category << endl;

    return 0;
}