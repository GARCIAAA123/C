//
// Created by Adrian Garcia on 5/9/23.
//
#include <stdio.h>

int main() {
    float salaries[12];
    float taxes[12];
    float taxRate;
    float limit;
    float higherTaxRate;
    float sumIncome;

    printf("Enter tax rate: ");
    scanf("%f", &taxRate);
    printf("Enter income limit: ");
    scanf("%f", &limit);
    printf("Enter tax rate for income over the limit: ");
    scanf("%f", &higherTaxRate);

    for (int i = 0; i < 12; ++i) {
        printf("Enter income for month %d: ", i + 1);
        scanf("%f", &salaries[i]);

        sumIncome += salaries[i];

        if (sumIncome <= limit){                        //Checks that the total amount of salary it is not over the limit
            taxes[i] = salaries[i] * (taxRate /100);
        }
        else if (sumIncome - salaries[i] < limit) {     //Checks that the total amount of salary it is not over the limit
            float lower_rate = limit - (sumIncome - salaries[i]); // It creates a variable to tax the money that it won't go over
            float higher_rate = salaries[i] - lower_rate; // It creates a variable to tax the salary that it will go over
            taxes[i] = (lower_rate * (taxRate/100)) + (higher_rate * (higherTaxRate / 100)); // Add everything to the array of taxes

        } else {
            taxes[i] = salaries[i] * (higherTaxRate / 100); //  Only gets in here if the salary it is already over the limit
        }
    }

    printf("month   income     tax\n");
    for (int i = 0; i < 12; ++i) {
        printf("%-7d %-10.2f %-6.2f\n", i + 1, salaries[i], taxes[i]);
    }

    return 0;
}
