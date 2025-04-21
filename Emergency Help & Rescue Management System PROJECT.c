#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Function prototypes
void mainMenu();
void signUp();
void login();
void adminLogin();
void userDashboard(char username[]);
void showServices();
void requestHelp(char username[]);
void viewAllUsers();

// Main Function
int main() {
    mainMenu();
    return 0;
}

// Main Menu
void mainMenu() {
    int choice;
    do {
        system("cls");
        printf("%s===========================================\n", CYAN);
        printf("     EMERGENCY RESCUE MANAGEMENT SYSTEM    \n");
        printf("===========================================\n%s", RESET);
        printf("%s1. Sign Up\n", GREEN);
        printf("2. Login\n");
        printf("3. Admin Login\n");
        printf("4. Exit\n");
        printf("-------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: signUp(); break;
            case 2: login(); break;
            case 3: adminLogin(); break;
            case 4: exit(0);
            default: printf("%sInvalid choice! Try again.%s\n", RED, RESET);
        }
        system("pause");
    } while (1);
}

// Sign Up Function
void signUp() {
    char username[50], password[50];
    FILE *fp;

    system("cls");
    printf("%s============== SIGN UP ===================\n", BLUE);
    printf("Enter new username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter new password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    fp = fopen("users.txt", "a");
    if (fp == NULL) {
        printf("%sError opening users.txt!%s\n", RED, RESET);
        return;
    }
    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);
    printf("%s✅ Sign Up successful!%s\n", GREEN, RESET);
}

// Login Function
void login() {
    char username[50], password[50], fileUser [50], filePass[50];
    int found = 0;
    FILE *fp;

    system("cls");
    printf("%s=============== LOGIN ====================\n", BLUE);
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("%sError opening users.txt!%s\n", RED, RESET);
        return;
    }

    while (fscanf(fp, "%s %s", fileUser , filePass) != EOF) {
        if (strcmp(username, fileUser ) == 0 && strcmp(password, filePass) == 0) {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (found) {
        printf("%s✅ Login successful!%s\n", GREEN, RESET);
        system("pause");
        userDashboard(username);
    } else {
        printf("%s❌ Incorrect username or password!%s\n", RED, RESET);
    }
}

// Admin Login
void adminLogin() {
    char username[50], password[50];

    system("cls");
    printf("%s=============== ADMIN LOGIN ==============\n", BLUE);
    printf("Enter admin username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter admin password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    if (strcmp(username, "admin") == 0 && strcmp(password, "12345") == 0) {
        printf("%s✅ Admin access granted!%s\n", GREEN, RESET);
        system("pause");
                viewAllUsers(); // Corrected function call
    } else {
        printf("%s❌ Invalid admin credentials!%s\n", RED, RESET);
    }
}

// User Dashboard
void userDashboard(char username[]) {
    int choice;
    do {
        system("cls");
        printf("%s===========================================\n", CYAN);
        printf("           USER DASHBOARD (%s)             \n", username);
        printf("===========================================\n%s", RESET);
        printf("%s1. View Emergency Services\n", GREEN);
        printf("2. Request Emergency Help\n");
        printf("3. Logout\n");
        printf("-------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: showServices(); break;
            case 2: requestHelp(username); break;
            case 3: return; // Logout
            default: printf("%sInvalid choice! Try again.%s\n", RED, RESET);
        }
        system("pause");
    } while (1);
}


void showServices() {
    system("cls");
    printf("%s===========================================\n", CYAN);
    printf("         LIST OF EMERGENCY SERVICES        \n");
    printf("===========================================\n%s", RESET);
    printf(" %-20s %-20s %-15s\n", "Service", "Location", "Contact");
    printf("-------------------------------------------------------------\n");
    printf("%s Fire Service         Dhaka City         199%s\n", GREEN, RESET);
    printf("%s Police Station       Uttara             999%s\n", GREEN, RESET);
    printf("%s Hospital             Dhanmondi          10666%s\n", GREEN, RESET);
    printf("%s Ambulance            Mohakhali          017xxxxxxx1%s\n", GREEN, RESET);
    printf("%s RAB-1                Banani             017xxxxxxx2%s\n", GREEN, RESET);
    printf("%s Highway Patrol       Dhaka-Chattogram   013xxxxxxx3%s\n", GREEN, RESET);
    printf("%s Gas Emergency        Titas Gas          16496%s\n", GREEN, RESET);
    printf("%s Electricity          DPDC Help Center   16116%s\n", GREEN, RESET);
    printf("%s Women Help Line      All Areas          109%s\n", GREEN, RESET);
    printf("%s Child Help Line      All Areas          1098%s\n", GREEN, RESET);
    printf("-------------------------------------------------------------\n");
}


void requestHelp(char username[]) {
    char area[50], contact[20], issue[100];
    int service;
    FILE *log, *info;

    char *services[] = {
        "Fire Service", "Police Station", "Hospital", "Ambulance", "RAB-1",
        "Highway Patrol", "Gas Emergency", "Electricity", "Women Help Line", "Child Help Line"
    };

    char *locations[] = {
        "Dhaka City", "Uttara", "Dhanmondi", "Mohakhali", "Banani",
        "Dhaka-Chattogram", "Titas Gas", "DPDC Center", "All Areas", "All Areas"
    };

    char *contacts[] = {
        "199", "999", "10666", "017xxxxxxx1", "017xxxxxxx2",
        "013xxxxxxx3", "16496", "16116", "109", "1098"
    };

    system("cls");
    printf("%s=========== EMERGENCY HELP REQUEST ==========%s\n", CYAN, RESET);

    for (int i = 0; i < 10; i++) {
        printf("%d. %-20s | %-15s | %s\n", i + 1, services[i], locations[i], contacts[i]);
    }

    printf("Select service number: ");
    scanf("%d", &service);
    getchar();

    if (service < 1 || service > 10) {
        printf("%sInvalid service!%s\n", RED, RESET);
        return;
    }

    printf("Enter your area: ");
    fgets(area, sizeof(area), stdin);
    area[strcspn(area, "\n")] = 0;

    printf("Enter your contact number: ");
    fgets(contact, sizeof(contact), stdin);
    contact[strcspn(contact, "\n")] = 0;

    printf("Describe the emergency issue: ");
    fgets(issue, sizeof(issue), stdin);
    issue[strcspn(issue, "\n")] = 0;

    info = fopen("info.txt", "a");
    if (info == NULL) {
        printf("%sError opening info.txt!%s\n", RED, RESET);
        return;
    }
       fprintf(info, ":User    %s\nArea: %s\nContact: %s\nIssue: %s\n\n", username, area, contact, issue);
    fclose(info);

    log = fopen("alert_log.txt", "a");
    if (log == NULL) {
        printf("%sError opening alert_log.txt!%s\n", RED, RESET);
        return;
    }
    fprintf(log, "ALERT from %s → %s | Location: %s | Contact: %s\n",
            username, services[service - 1], locations[service - 1], contacts[service - 1]);
    fclose(log);

    printf("%s✅ Alert sent to %s successfully!%s\n", GREEN, services[service - 1], RESET);
}

void viewAllUsers() {
    FILE *fp;
    char user[50], pass[50];

    system("cls");
    printf("%s============== REGISTERED USERS ==============%s\n", CYAN, RESET);
    fp = fopen("users.txt", "r");

    if (fp == NULL) {
        printf("%sError opening users.txt!%s\n", RED, RESET);
        return;
    }

    while (fscanf(fp, "%s %s", user, pass) != EOF) {
        printf("Username: %s | Password: %s\n", user, pass);
    }

    fclose(fp);
    printf("-----------------------------------------------\n");
}


