#ifndef INVESTMENTCLASS_H
#define INVESTMENTCLASS_H

#include <string>

class InvestmentAccount {
public:
    InvestmentAccount(double initialAmount, double annualInterestRate);
    InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit);

    double getEndingBalance(int numberOfYears) const;
    double getInterestEarned(int numberOfYears) const;
    std::string getEndingBalanceFormatted(int numberOfYears) const;
    std::string getInterestEarnedFormatted(int numberOfYears) const;
    std::string getYearlyInterestFormatted(int year) const;
    double getYearlyInterest(int year) const; // Add this declaration

    double getInitialAmount() const;
    double getMonthlyDeposit() const;
    double getAnnualInterestRate() const;

    double round(double value, int places) const;
    std::string format(double value) const;

private:
    double initialAmount;
    double monthlyDeposit;
    double annualInterestRate;

    double calculateMonthlyInterest(double balance) const;
};

#endif //INVESTMENTCLASS_H
