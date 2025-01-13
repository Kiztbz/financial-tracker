#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define NAME_LENGTH 80
#define DESC_LENGTH 200

// Structure to store product details
typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESC_LENGTH]; // New field for product description
    float price;
    int quantity;
} Product;

// Global array to store products
Product products[MAX_PRODUCTS];
int productCount = 0;

// Function Prototypes
void addProduct();
void viewProducts();
void searchProduct();
void updateProduct();
void deleteProduct();
void processChoice(const char *choice);

// Function to process menu choices dynamically by name or number
void processChoice(const char *choice) {
    if (strcmp(choice, "1") == 0 || strcasecmp(choice, "add") == 0) {
        addProduct();
    } else if (strcmp(choice, "2") == 0 || strcasecmp(choice, "view") == 0) {
        viewProducts();
    } else if (strcmp(choice, "3") == 0 || strcasecmp(choice, "search") == 0) {
        searchProduct();
    } else if (strcmp(choice, "4") == 0 || strcasecmp(choice, "update") == 0) {
        updateProduct();
    } else if (strcmp(choice, "5") == 0 || strcasecmp(choice, "delete") == 0) {
        deleteProduct();
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
        printf("\n--- Product Management System ---\n");
        printf("1. Add Product (or type 'add')\n");
        printf("2. View Products (or type 'view')\n");
        printf("3. Search Product (or type 'search')\n");
        printf("4. Update Product (or type 'update')\n");
        printf("5. Delete Product (or type 'delete')\n");
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

// Function to add a new product
void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Error: Product list is full.\n");
        return;
    }

    Product p;
    p.id = productCount + 1;  // Assign a unique ID
    printf("Enter product name: ");
    scanf(" %[^\n]s", p.name);  // Read input with spaces
    printf("Enter product description: ");
    scanf(" %[^\n]s", p.description);  // Input description
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);

    products[productCount++] = p;
    printf("Product added successfully!\n");
}

// Function to view all products
void viewProducts() {
    if (productCount == 0) {
        printf("No products available.\n");
        return;
    }

    printf("\n%-5s %-20s %-20s %-10s %-10s\n", "ID", "Name", "Description", "Price", "Quantity");
    printf("---------------------------------------------------------------------------------\n");
    for (int i = 0; i < productCount; i++) {
        printf("%-5d %-20s %-20s %-10.2f %-10d\n", 
               products[i].id, products[i].name, products[i].description, 
               products[i].price, products[i].quantity);
    }
}

// Function to search for a product by name
void searchProduct() {
    char searchName[NAME_LENGTH];
    printf("Enter product name to search: ");
    scanf(" %[^\n]s", searchName);

    for (int i = 0; i < productCount; i++) {
        if (strcasecmp(products[i].name, searchName) == 0) { // Case-insensitive comparison
            printf("Product found:\n");
            printf("ID: %d, Name: %s, Description: %s, Price: %.2f, Quantity: %d\n",
                   products[i].id, products[i].name, products[i].description, 
                   products[i].price, products[i].quantity);
            return;
        }
    }
    printf("Product not found.\n");
}

// Function to update a product
void updateProduct() {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    Product *p = &products[id - 1];
    printf("Enter new name (current: %s): ", p->name);
    scanf(" %[^\n]s", p->name);
    printf("Enter new description (current: %s): ", p->description);
    scanf(" %[^\n]s", p->description);
    printf("Enter new price (current: %.2f): ", p->price);
    scanf("%f", &p->price);
    printf("Enter new quantity (current: %d): ", p->quantity);
    scanf("%d", &p->quantity);

    printf("Product updated successfully!\n");
}

// Function to delete a product
void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        products[i] = products[i + 1];
    }
    productCount--;
    printf("Product deleted successfully!\n");
}

