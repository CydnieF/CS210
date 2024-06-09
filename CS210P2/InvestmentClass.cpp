#include "InvestmentClass.h"
#include <cmath>
#include <iomanip>
#include <sstream>

InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate)
    : initialAmount(initialAmount), annualInterestRate(annualInterestRate), monthlyDeposit(0) {}

InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit)
    : initialAmount(initialAmount), annualInterestRate(annualInterestRate), monthlyDeposit(monthlyDeposit) {}

double InvestmentAccount::getInitialAmount() const {
    return initialAmount;
}

double InvestmentAccount::getMonthlyDeposit() const {
    return monthlyDeposit;
}

double InvestmentAccount::getAnnualInterestRate() const {
    return annualInterestRate;
}

double InvestmentAccount::round(double value, int places) const {
    const int multiplier = pow(10, places);
    double roundedValue = static_cast<int>(value * multiplier + 0.5);
    roundedValue = static_cast<double>(roundedValue) / multiplier;
    return roundedValue;
}

std::string InvestmentAccount::format(double value) const {
    std::ostringstream stream;
    stream << "$" << std::fixed << std::setprecision(2) << value;
    return stream.str();
}

double InvestmentAccount::calculateMonthlyInterest(double balance) const {
    return balance * ((annualInterestRate / 100) / 12);
}

double InvestmentAccount::getEndingBalance(int numberOfYears) const {
    double balance = initialAmount;
    for (int month = 1; month <= numberOfYears * 12; ++month) {
        balance += monthlyDeposit;
        balance += calculateMonthlyInterest(balance);
    }
    return balance;
}

double InvestmentAccount::getInterestEarned(int numberOfYears) const {
    double balance = initialAmount;
    double totalInterest = 0;

    for (int month = 1; month <= numberOfYears * 12; ++month) {
        balance += monthlyDeposit;
        double interest = calculateMonthlyInterest(balance);
        totalInterest += interest;
        balance += interest;
    }

    return totalInterest;
}

std::string InvestmentAccount::getEndingBalanceFormatted(int numberOfYears) const {
    return format(round(getEndingBalance(numberOfYears), 2));
}

std::string InvestmentAccount::getInterestEarnedFormatted(int numberOfYears) const {
    return format(round(getInterestEarned(numberOfYears), 2));
}

double InvestmentAccount::getYearlyInterest(int year) const {
    double balance = initialAmount;
    double yearStartBalance;
    double yearEndBalance;
    double yearlyInterest = 0;

    for (int month = 1; month <= year * 12; ++month) {
        if (month == 1) {
            yearStartBalance = balance;
        }
        balance += monthlyDeposit;
        double interest = calculateMonthlyInterest(balance);
        balance += interest;

        if (month % 12 == 0) {
            yearEndBalance = balance;
            yearlyInterest = yearEndBalance - yearStartBalance - (monthlyDeposit * 12);
            yearStartBalance = yearEndBalance;
        }
    }

    return yearlyInterest;
}

std::string InvestmentAccount::getYearlyInterestFormatted(int year) const {
    return format(round(getYearlyInterest(year), 2));
}
