#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 50
#define PASSWORD_LENGTH 20

// Structure to store user details
typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
    char password[PASSWORD_LENGTH];
} User;

// Global array to store users
User users[MAX_USERS];
int userCount = 0;

// Function prototypes
void addUser();
void viewUsers();
void searchUser();
void updateUser();
void deleteUser();
void processChoice(const char *choice);

// Function to process menu choices dynamically by name or number
void processChoice(const char *choice) {
    if (strcmp(choice, "1") == 0 || strcasecmp(choice, "add") == 0) {
        addUser();
    } else if (strcmp(choice, "2") == 0 || strcasecmp(choice, "view") == 0) {
        viewUsers();
    } else if (strcmp(choice, "3") == 0 || strcasecmp(choice, "search") == 0) {
        searchUser();
    } else if (strcmp(choice, "4") == 0 || strcasecmp(choice, "update") == 0) {
        updateUser();
    } else if (strcmp(choice, "5") == 0 || strcasecmp(choice, "delete") == 0) {
        deleteUser();
    } else if (strcmp(choice, "6") == 0 || strcasecmp(choice, "exit") == 0) {
        printf("Exiting...\n");
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

// Main menu
int main() {
    char choice[10];

    do {
        printf("\n--- User Management System ---\n");
        printf("1. Add User (or type 'add')\n");
        printf("2. View Users (or type 'view')\n");
        printf("3. Search User (or type 'search')\n");
        printf("4. Update User (or type 'update')\n");
        printf("5. Delete User (or type 'delete')\n");
        printf("6. Exit (or type 'exit')\n");
        printf("Enter your choice: ");
        scanf(" %s", choice);

        if (strcmp(choice, "6") == 0 || strcasecmp(choice, "exit") == 0) {
            processChoice(choice);
            break;
        }

        processChoice(choice);
    } while (1);

    return 0;
}

// Function to add a new user
void addUser() {
    if (userCount >= MAX_USERS) {
        printf("Error: User list is full.\n");
        return;
    }

    User u;
    u.id = userCount + 1;  // Assign a unique ID
    printf("Enter user name: ");
    scanf(" %[^\n]s", u.name);
    printf("Enter user email: ");
    scanf(" %[^\n]s", u.email);
    printf("Enter user password: ");
    scanf(" %[^\n]s", u.password);

    users[userCount++] = u;
    printf("User added successfully!\n");
}

// Function to view all users
void viewUsers() {
    if (userCount == 0) {
        printf("No users available.\n");
        return;
    }

    printf("\n%-5s %-20s %-30s %-10s\n", "ID", "Name", "Email", "Password");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < userCount; i++) {
        printf("%-5d %-20s %-30s %-10s\n", users[i].id, users[i].name, users[i].email, users[i].password);
    }
}

// Function to search for a user by name
void searchUser() {
    char searchName[NAME_LENGTH];
    printf("Enter user name to search: ");
    scanf(" %[^\n]s", searchName);

    for (int i = 0; i < userCount; i++) {
        if (strcasecmp(users[i].name, searchName) == 0) { // Case-insensitive comparison
            printf("User found:\n");
            printf("ID: %d, Name: %s, Email: %s, Password: %s\n",
                   users[i].id, users[i].name, users[i].email, users[i].password);
            return;
        }
    }
    printf("User not found.\n");
}

// Function to update a user
void updateUser() {
    int id;
    printf("Enter user ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > userCount) {
        printf("Invalid user ID.\n");
        return;
    }

    User *u = &users[id - 1];
    printf("Enter new name (current: %s): ", u->name);
    scanf(" %[^\n]s", u->name);
    printf("Enter new email (current: %s): ", u->email);
    scanf(" %[^\n]s", u->email);
    printf("Enter new password (current: %s): ", u->password);
    scanf(" %[^\n]s", u->password);

    printf("User updated successfully!\n");
}

// Function to delete a user
void deleteUser() {
    int id;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > userCount) {
        printf("Invalid user ID.\n");
        return;
    }

    for (int i = id - 1; i < userCount - 1; i++) {
        users[i] = users[i + 1];
    }
    userCount--;
    printf("User deleted successfully!\n");
}

