#include <stdio.h>

struct Patient {
    char name[50];
    int age;
    char bloodType[5];
    int patientID;
    char diagnosis[100];
};

void displayAll(struct Patient p[], int n) {
    printf("\nAll Patient Records:\n");

    for (int i = 0; i < n; i++) {
        printf("\nPatient %d:\n", i + 1);
        printf("ID: %d\n", p[i].patientID);
        printf("Name: %s", p[i].name);
        printf("Age: %d\n", p[i].age);
        printf("Blood Type: %s\n", p[i].bloodType);
        printf("Diagnosis: %s", p[i].diagnosis);
    }
}

void searchByID(struct Patient p[], int n, int id) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (p[i].patientID == id) {
            printf("\nPatient Found:\n");
            printf("ID: %d\n", p[i].patientID);
            printf("Name: %s", p[i].name);
            printf("Age: %d\n", p[i].age);
            printf("Blood Type: %s\n", p[i].bloodType);
            printf("Diagnosis: %s", p[i].diagnosis);
            found = 1;
        }
    }

    if (found == 0) {
        printf("Patient not found\n");
    }
}

int main() {
    struct Patient p[5];

    for (int i = 0; i < 5; i++) {
        printf("\nEnter details for patient %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &p[i].patientID);

        printf("Enter Name: ");
        getchar();
        fgets(p[i].name, 50, stdin);

        printf("Enter Age: ");
        scanf("%d", &p[i].age);

        printf("Enter Blood Type: ");
        scanf("%s", p[i].bloodType);

        printf("Enter Diagnosis: ");
        getchar();
        fgets(p[i].diagnosis, 100, stdin);
    }

    displayAll(p, 5);

    int id;
    printf("\nEnter ID to search: ");
    scanf("%d", &id);

    searchByID(p, 5, id);

    return 0;
}
