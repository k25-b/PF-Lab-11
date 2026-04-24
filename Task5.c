#include <stdio.h>
#include <string.h>

// inner structure
struct Department {
    char deptCode[10];
    char deptName[50];
};

// outer structure
struct Course {
    char courseCode[10];
    char courseName[60];
    int creditHours;
    struct Department dept;   // nested struct
};

// function to print courses of a specific department
void searchByDept(struct Course c[], int n, char code[]) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(c[i].dept.deptCode, code) == 0) {
            printf("\nCourse Code: %s\n", c[i].courseCode);
            printf("Course Name: %s", c[i].courseName);
            printf("Credit Hours: %d\n", c[i].creditHours);
            printf("Department Code: %s\n", c[i].dept.deptCode);
            printf("Department Name: %s", c[i].dept.deptName);
            found = 1;
        }
    }

    if (found == 0) {
        printf("No courses found for this department\n");
    }
}

int main() {
    struct Course c[3];

    // input
    for (int i = 0; i < 3; i++) {
        printf("\nEnter details for course %d\n", i + 1);

        printf("Enter Course Code: ");
        scanf("%s", c[i].courseCode);

        printf("Enter Course Name: ");
        getchar();
        fgets(c[i].courseName, 60, stdin);

        printf("Enter Credit Hours: ");
        scanf("%d", &c[i].creditHours);

        printf("Enter Department Code: ");
        scanf("%s", c[i].dept.deptCode);

        printf("Enter Department Name: ");
        getchar();
        fgets(c[i].dept.deptName, 50, stdin);
    }

    // display all
    printf("\nAll Courses:\n");
    for (int i = 0; i < 3; i++) {
        printf("\nCourse %d:\n", i + 1);
        printf("Course Code: %s\n", c[i].courseCode);
        printf("Course Name: %s", c[i].courseName);
        printf("Credit Hours: %d\n", c[i].creditHours);
        printf("Department Code: %s\n", c[i].dept.deptCode);
        printf("Department Name: %s", c[i].dept.deptName);
    }

    // search by department
    char code[10];
    printf("\nEnter Department Code to search: ");
    scanf("%s", code);

    searchByDept(c, 3, code);

    return 0;
}
