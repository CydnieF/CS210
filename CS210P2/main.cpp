#include <iostream>
#include <iomanip>
#include "InvestmentClass.h"

using namespace std;

// Function prototypes
void displayOutput(const InvestmentAccount& accountWithoutDeposit, const InvestmentAccount& accountWithDeposit, int numberOfYears);
void getInput(double& initialAmount, double& monthlyDeposit, double& annualInterestRate, int& numberOfYears);

int main() {
    double initialAmount, monthlyDeposit, annualInterestRate;
    int numberOfYears;

    getInput(initialAmount, monthlyDeposit, annualInterestRate, numberOfYears);

    InvestmentAccount accountWithDeposit(initialAmount, annualInterestRate, monthlyDeposit);
    InvestmentAccount accountWithoutDeposit(initialAmount, annualInterestRate);

    displayOutput(accountWithoutDeposit, accountWithDeposit, numberOfYears);

    return 0;
}

void getInput(double& initialAmount, double& monthlyDeposit, double& annualInterestRate, int& numberOfYears) {
    cout << "Initial Investment Amount: ";
    cin >> initialAmount;
    while (initialAmount <= 0) {
        cout << "Please enter a positive amount: ";
        cin >> initialAmount;
    }

    cout << "Monthly Deposit: ";
    cin >> monthlyDeposit;
    while (monthlyDeposit < 0) {
        cout << "Please enter a non-negative amount: ";
        cin >> monthlyDeposit;
    }

    cout << "Annual Interest: ";
    cin >> annualInterestRate;
    while (annualInterestRate <= 0) {
        cout << "Please enter a positive percentage: ";
        cin >> annualInterestRate;
    }

    cout << "Number of Years: ";
    cin >> numberOfYears;
    while (numberOfYears <= 0) {
        cout << "Please enter a positive number of years: ";
        cin >> numberOfYears;
    }

    // Clear the newline character left in the input buffer after reading an integer
    cin.ignore();
}

void displayOutput(const InvestmentAccount& accountWithoutDeposit, const InvestmentAccount& accountWithDeposit, int numberOfYears) {
    cout << "**********************************" << endl;
    cout << "*********** Data Input ***********" << endl;

    // Format and display input values with two decimal places
    cout << "Initial Investment Amount: " << accountWithDeposit.format(accountWithDeposit.getInitialAmount()) << endl;
    cout << "Monthly Deposit: " << accountWithDeposit.format(accountWithDeposit.getMonthlyDeposit()) << endl;
    cout << "Annual Interest: " << accountWithDeposit.getAnnualInterestRate() << "%" << endl;
    cout << "Number of Years: " << numberOfYears << endl;
    cout << "Press any key to continue . . ." << endl;

    // Wait for any key press
    cin.get();

    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "==========================================================\n";
    cout << setw(15) << "Year" << setw(25) << "Year End Balance" << setw(25) << "Year End Earned Interest" << endl;
    cout << "----------------------------------------------------------\n";
    for (int year = 1; year <= numberOfYears; ++year) {
        cout << setw(15) << year << setw(25) << accountWithoutDeposit.getEndingBalanceFormatted(year) << setw(25) << accountWithoutDeposit.getYearlyInterestFormatted(year) << endl;
    }

    cout << "\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "==========================================================\n";
    cout << setw(15) << "Year" << setw(25) << "Year End Balance" << setw(25) << "Year End Earned Interest" << endl;
    cout << "----------------------------------------------------------\n";
    for (int year = 1; year <= numberOfYears; ++year) {
        cout << setw(15) << year << setw(25) << accountWithDeposit.getEndingBalanceFormatted(year) << setw(25) << accountWithDeposit.getYearlyInterestFormatted(year) << endl;
    }
}
