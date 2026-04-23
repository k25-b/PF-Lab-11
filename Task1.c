#include <stdio.h>
int totalPower(int floors) {
    if (floors == 1) {
        return  100;
    }
    if (floors>1) {
        return  100 + totalPower(floors - 1);
    }
}
int main() {
    printf("Enter the number of floors: "); //example 3 floors
    int floors;                             //return 100 + power(200)
    scanf("%d", &floors);                   //power(200) ==> return 100 + power(100)
    printf("%d",totalPower(floors));        //power(200) ==> 100 + 100
    return 0;                               //100+power(200) ==> 100 + 200 = 300
}
