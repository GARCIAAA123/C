//
// Created by Adrian Garcia on 5/9/23.
//

//
// Created by Adrian Garcia on 21/8/23.
//
#include <stdio.h>

int main() {

    float bus;
    printf("Enter price of bus ticket: ");
    scanf("%f", &bus);


    float taxi;
    printf("Enter price of taxi: ");
    scanf("%f", &taxi);


    float money;
    printf("How much money you have: ");
    scanf("%f" , &money);
    printf("You have %.2f euros left. \n" , money);


    int choice;
    while (money >= bus || money >= taxi){
        printf("Do you want to take \n");
        printf("1) Bus (%.2f) \n", bus);
        printf("2) Taxi (%.2f) \n", taxi);
        scanf("%d", &choice);

        if (choice == 1) {
            if (money < bus){
                printf("You chose bus \n");
                printf("You don't have enough money for bus \n");
                printf("You have %.2f euros left \n", money);
            }
            else{
                printf("You chose bus \n");
                money =  money - bus;
                printf("You have %.2f euros left \n", money);
            }
        }
        if (choice == 2) {
            if (money < taxi){
                printf("You chose taxi \n");
                printf("You don't have enough money for taxi \n");
                printf("You have %.2f euros left \n", money);
            }
            else{
                printf("You chose taxi \n");
                money = money - taxi;
                printf("You have %.2f money left \n", money);
            }

        }
        if(money < bus && money < taxi){
            printf("You need to walk. Bye");
            break;
        }
    }
    return 0;

}


