#include <stdio.h>
#include <string.h>

struct Order {
    int orderID;
    char customerName[50];
    char productName[50];
    int quantity;
    float unitPrice;
    char status[20];
};

float computeTotal(struct Order o) {
    return o.quantity * o.unitPrice;
}

void filterByStatus(struct Order orders[], int n, char *status) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(orders[i].status, status) == 0) {
            printf("\nOrder ID: %d\n", orders[i].orderID);
            printf("Customer: %s", orders[i].customerName);
            printf("Product: %s", orders[i].productName);
            printf("Quantity: %d\n", orders[i].quantity);
            printf("Unit Price: %.2f\n", orders[i].unitPrice);
            printf("Status: %s\n", orders[i].status);
            printf("Total: %.2f\n", computeTotal(orders[i]));
            found = 1;
        }
    }

    if (found == 0) {
        printf("No orders found with this status\n");
    }
}

int main() {
    struct Order orders[4];

    for (int i = 0; i < 4; i++) {
        printf("\nEnter details for order %d\n", i + 1);

        printf("Enter Order ID: ");
        scanf("%d", &orders[i].orderID);

        printf("Enter Customer Name: ");
        getchar();
        fgets(orders[i].customerName, 50, stdin);

        printf("Enter Product Name: ");
        fgets(orders[i].productName, 50, stdin);

        printf("Enter Quantity: ");
        scanf("%d", &orders[i].quantity);

        printf("Enter Unit Price: ");
        scanf("%f", &orders[i].unitPrice);

        printf("Enter Status (Pending/Shipped/Delivered): ");
        scanf("%s", orders[i].status);
    }

    printf("\nAll Orders:\n");
    for (int i = 0; i < 4; i++) {
        printf("\nOrder %d:\n", i + 1);
        printf("Order ID: %d\n", orders[i].orderID);
        printf("Customer: %s", orders[i].customerName);
        printf("Product: %s", orders[i].productName);
        printf("Quantity: %d\n", orders[i].quantity);
        printf("Unit Price: %.2f\n", orders[i].unitPrice);
        printf("Status: %s\n", orders[i].status);
        printf("Total Bill: %.2f\n", computeTotal(orders[i]));
    }

    char s[20];
    printf("\nEnter status to filter: ");
    scanf("%s", s);

    filterByStatus(orders, 4, s);

    return 0;
}
