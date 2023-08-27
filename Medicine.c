#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine
{
    int id;
    char name[100];
    float price;
    int quantity;
};

struct Customer
{
    int id;
    char name[100];
    char address[200];
};

struct Supplier
{
    int id;
    char name[100];
    char contact[20];
};

//Add Medicine
void addMedicine()
{
    FILE *file = fopen("medicines.dat", "ab+");
    struct Medicine medicine;
    printf("Enter medicine ID: ");
    scanf("%d", &medicine.id);
    printf("Enter medicine name: ");
    scanf("%s", medicine.name);
    printf("Enter medicine price: ");
    scanf("%f", &medicine.price);
    printf("Enter quantity: ");
    scanf("%d", &medicine.quantity);
    fwrite(&medicine, sizeof(struct Medicine), 1, file);
    printf("Medicine added successfully!\n");
    fclose(file);
}

//Display Medicine
void displayMedicines()
{
    struct Medicine medicine;
    FILE *file = fopen("medicines.dat", "ab+");
    printf("Medicine List:\n");

    while (fread(&medicine, sizeof(struct Medicine), 1, file) == 1)
    {
        printf("ID: %d\t Name: %s\t Price: %.2f\t Quantity: %d\n",
               medicine.id, medicine.name, medicine.price, medicine.quantity);
    }
    fclose(file);
}

//Modify Medicines
void modifyMedicine()
{
    int id;
    printf("Enter medicine id: ");
    scanf("%d", &id);

    struct Medicine medicine;
    int found = 0;
    FILE *file = fopen("medicines.dat", "rb+"); // Open the file in read/write mode

    while (fread(&medicine, sizeof(struct Medicine), 1, file) == 1)
    {
        if (medicine.id == id)
        {
            found = 1;

            printf("Enter new medicine name: ");
            scanf("%s", medicine.name);
            printf("Enter new medicine price: ");
            scanf("%f", &medicine.price);
            printf("Enter new quantity: ");
            scanf("%d", &medicine.quantity);

            fseek(file, -sizeof(struct Medicine), SEEK_CUR);
            fwrite(&medicine, sizeof(struct Medicine), 1, file);

            printf("Medicine modified successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("Medicine with ID %d not found.\n", id);
    }

    fclose(file);
}

//Delete Medicines
void deleteMedicine()
{
    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);

    struct Medicine medicine;
    int found = 0;
    FILE *file = fopen("medicines.dat", "rb");
    FILE *tempFile = fopen("temp.dat", "wb"); // Temporary file to hold non-deleted records

    while (fread(&medicine, sizeof(struct Medicine), 1, file) == 1)
    {
        if (medicine.id == id)
        {
            found = 1;
            printf("Medicine found and deleted.\n");
        }
        else
        {
            fwrite(&medicine, sizeof(struct Medicine), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (!found)
    {
        printf("Medicine with ID %d not found.\n", id);
    }
    else
    {
        remove("medicines.dat");             // Delete the old medicines.dat file
        rename("temp.dat", "medicines.dat"); // Rename temp.dat to medicines.dat
    }
}

//Add Supplier
void addSupplier()
{
    FILE *file = fopen("suppliers.dat", "ab+");
    struct Supplier supplier;
    printf("Enter supplier ID: ");
    scanf("%d", &supplier.id);
    printf("Enter supplier name: ");
    scanf("%s", supplier.name);
    printf("Enter supplier contact: ");
    scanf("%s", supplier.contact);
    fwrite(&supplier, sizeof(struct Supplier), 1, file);
    printf("Supplier added successfully!\n");
    fclose(file);
}

// Function to display suppliers
void displaySupplier()
{
    struct Supplier supplier;
    FILE *file = fopen("suppliers.dat", "ab+");
    printf("Supplier List:\n");

    while (fread(&supplier, sizeof(struct Supplier), 1, file) == 1)
    {
        printf("ID: %d\t Name: %s\t Contact: %s\n",
               supplier.id, supplier.name, supplier.contact);
    }
    fclose(file);
}


// Function to delete a supplier by ID
void deleteSupplier()
{
    int id;
    printf("Enter supplier ID to delete: ");
    scanf("%d", &id);

    struct Supplier supplier;
    int found = 0;
    FILE *file = fopen("suppliers.dat", "rb");
    FILE *tempFile = fopen("temp_suppliers.dat", "wb"); // Temporary file to hold non-deleted records

    while (fread(&supplier, sizeof(struct Supplier), 1, file) == 1)
    {
        if (supplier.id == id)
        {
            found = 1;
            printf("Supplier found and deleted.\n");
        }
        else
        {
            fwrite(&supplier, sizeof(struct Supplier), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (!found)
    {
        printf("Supplier with ID %d not found.\n", id);
    }
    else
    {
        remove("suppliers.dat");                       // Delete the old suppliers.dat file
        rename("temp_suppliers.dat", "suppliers.dat"); // Rename temp_suppliers.dat to suppliers.dat
    }
}


// Function to modify supplier details
void modifySupplier()
{
    int id;
    printf("Enter supplier ID to modify: ");
    scanf("%d", &id);

    struct Supplier supplier;
    int found = 0;
    FILE *file = fopen("suppliers.dat", "rb+"); // Open the file in read/write mode

    while (fread(&supplier, sizeof(struct Supplier), 1, file) == 1)
    {
        if (supplier.id == id)
        {
            found = 1;

            printf("Enter new supplier name: ");
            scanf("%s", supplier.name);
            printf("Enter new supplier contact: ");
            scanf("%s", supplier.contact);

            fseek(file, -sizeof(struct Supplier), SEEK_CUR);
            fwrite(&supplier, sizeof(struct Supplier), 1, file);

            printf("Supplier details modified successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("Supplier with ID %d not found.\n", id);
    }

    fclose(file);
}

//Add Customer
void addCustomer()
{
    FILE *file = fopen("customers.dat", "ab+");
    struct Customer customer;
    printf("Enter customer ID: ");
    scanf("%d", &customer.id);
    printf("Enter customer name: ");
    scanf("%s", customer.name);
    printf("Enter customer address: ");
    scanf("%s", customer.address);
    fwrite(&customer, sizeof(struct Customer), 1, file);
    printf("Customer added successfully!\n");
    fclose(file);
}

//Display customer
void displayCustomer()
{
    struct Customer customer;
    FILE *file = fopen("customers.dat", "ab+");
    printf("Customer List:\n");

    while (fread(&customer, sizeof(struct Customer), 1, file) == 1)
    {
        printf("ID: %d\t Name: %s\t Address: %s\n",
               customer.id, customer.name, customer.address);
    }
    fclose(file);
}

//Modify Customer
void modifyCustomer()
{
    int id;
    printf("Enter customer ID to modify: ");
    scanf("%d", &id);

    struct Customer customer;
    int found = 0;
    FILE *file = fopen("customers.dat", "rb+"); // Open the file in read/write mode

    while (fread(&customer, sizeof(struct Customer), 1, file) == 1)
    {
        if (customer.id == id)
        {
            found = 1;

            printf("Enter new customer name: ");
            scanf("%s", customer.name);
            printf("Enter new customer address: ");
            scanf("%s", customer.address);

            fseek(file, -sizeof(struct Customer), SEEK_CUR);
            fwrite(&customer, sizeof(struct Customer), 1, file);

            printf("Customer details modified successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("Customer with ID %d not found.\n", id);
    }

    fclose(file);
}

//Delete Customer
void deleteCustomer()
{
    int id;
    printf("Enter customer ID to delete: ");
    scanf("%d", &id);

    struct Customer customer;
    int found = 0;
    FILE *file = fopen("customers.dat", "rb");
    FILE *tempFile = fopen("temp_customers.dat", "wb"); // Temporary file to hold non-deleted records

    while (fread(&customer, sizeof(struct Customer), 1, file) == 1)
    {
        if (customer.id == id)
        {
            found = 1;
            printf("Customer found and deleted.\n");
        }
        else
        {
            fwrite(&customer, sizeof(struct Customer), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (!found)
    {
        printf("Customer with ID %d not found.\n", id);
    }
    else
    {
        remove("customers.dat");                       // Delete the old customers.dat file
        rename("temp_customers.dat", "customers.dat"); // Rename temp_customers.dat to customers.dat
    }
}



int main()
{
    int choice;
    do
    {
        printf("\n\n Medical Store Management \n\n");
        printf("1.  Add Medicines\n");
        printf("2.  Display Medicines\n");
        printf("3.  Modify Medicines\n");
        printf("4.  Delete Medicines\n");
        printf("5.  Add Suppliers\n");
        printf("6.  Display Suppliers\n");
        printf("7.  Modify Suppliers\n");
        printf("8.  Delete Suppliers\n");
        printf("9.  Add Customers\n");
        printf("10. Display Customers\n");
        printf("11. Modify Customers\n");
        printf("12. Delete Customers\n");
        printf("0.  Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addMedicine();
            break;
        case 2:
            displayMedicines();
            break;
        case 3:
            modifyMedicine();
            break;
        case 4:
            deleteMedicine();
            break;
        case 5:
            addSupplier();
            break;
        case 6:
            displaySupplier();
            break;
        case 7:
            modifySupplier();
            break;
        case 8:
            deleteSupplier();
            break;
        case 9:
            addCustomer();
            break;
        case 10:
            displayCustomer();
            break;
        case 11:
            modifyCustomer();
            break;
        case 12:
            deleteCustomer();
            break;
        case 0:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}
