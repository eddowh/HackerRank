#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


double calculate_expected_money(double profit_probability, double potential_profit, double potential_loss)
{
    return (profit_probability * potential_profit) - ((1.0 - profit_probability) * potential_loss);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    // initialize
    int n;
    int k;
    cin >> n >> k;

    double* profit_probabilities = new double[n];
    double* potential_profits = new double[n];

    // get all probabilities
    double profit_probability;
    for (int i = 0; i < n; i++) {
        cin >> profit_probability;
        profit_probabilities[i] = profit_probability;
    }

    // get all potential profit
    double potential_profit;
    for (int i = 0; i < n; i++) {
        cin >> potential_profit;
        potential_profits[i] = potential_profit;
    }

    // get all potential loss
    vector<double> expected_money;
    double potential_loss;
    double expected_value;
    for (int i = 0; i < n; i++) {
        cin >> potential_loss;
        // we can start calculating potential money made by each trade
        expected_value = calculate_expected_money(
                profit_probabilities[i],
                potential_profits[i],
                potential_loss
                );
        if (expected_value > 0) {
            expected_money.push_back(expected_value);
        }
    }

    delete [] profit_probabilities;
    delete [] potential_profits;

    // sort the vector
    std::sort(expected_money.begin(), expected_money.end());
    if (k > (int) expected_money.size()) {
        k = expected_money.size();
    }

    // max collective expected money
    double max_money = 0.0;
    for (std::vector<double>::iterator it = expected_money.end() - k; it != expected_money.end(); ++it) {
        max_money += *it;
    }

    std::cout << std::fixed << std::setprecision(2) << max_money << std::endl;

    return 0;
}
