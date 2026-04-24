#include <stdio.h>
int password_auditor(char password[100]) {
    int i = 0;
    if (password[i] == '\0') {
        return 0;
    }
    else if (password[i] >= 'A' && password[i] <= 'Z') {
        return 1 + password_auditor(password+1);
    }
    else {
        return password_auditor(password+1);
    }
}
int digit_auditor(char password[100]) {
    int i = 0;
    if (password[i] == '\0') {
        return 0;
    }
    else if (password[i] >= '0' && password[i] <= '9') {
        return 1 + digit_auditor(password+1);
    }
    else {
        return digit_auditor(password+1);
    }
}
int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);
    int x = password_auditor(password);
    printf("The password entered has %d uppercase letters.\n", x);
    printf("The password entered has %d digits", digit_auditor(password));
}
