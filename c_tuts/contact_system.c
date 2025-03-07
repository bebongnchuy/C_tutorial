#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure
typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} Contact;

// Function Prototypes
void addContact();
void searchContact();
void updateContact();
void deleteContact();
void displayContacts();
int main() {
    int choice;
    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Update Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Display All Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character

        switch(choice) {
            case 1: addContact(); break;
            case 2: searchContact(); break;
            case 3: updateContact(); break;
            case 4: deleteContact(); break;
            case 5: displayContacts(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 6);

    return 0;
}


void addContact() {
    FILE *fp;
    Contact c;
    
    fp = fopen("contacts.dat", "ab");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = 0; // Remove newline

    printf("Enter Phone: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = 0;

    printf("Enter Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = 0;

    fwrite(&c, sizeof(Contact), 1, fp);
    fclose(fp);

    printf("Contact added successfully!\n");
}


void searchContact() {
    FILE *fp;
    Contact c;
    char name[50];
    int found = 0;

    fp = fopen("contacts.dat", "rb");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter name to search: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    while(fread(&c, sizeof(Contact), 1, fp)) {
        if(strcasecmp(c.name, name) == 0) { // Case insensitive comparison
            printf("\nContact Found:\n");
            printf("Name: %s\n", c.name);
            printf("Phone: %s\n", c.phone);
            printf("Email: %s\n", c.email);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("No contact found with the name: %s\n", name);
    }

    fclose(fp);
}


void updateContact() {
    FILE *fp;
    Contact c;
    char name[50];
    int found = 0;

    fp = fopen("contacts.dat", "rb+");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter name to update: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    while(fread(&c, sizeof(Contact), 1, fp)) {
        if(strcasecmp(c.name, name) == 0) {
            printf("Enter new details:\n");

            printf("Name: ");
            fgets(c.name, sizeof(c.name), stdin);
            c.name[strcspn(c.name, "\n")] = 0;

            printf("Phone: ");
            fgets(c.phone, sizeof(c.phone), stdin);
            c.phone[strcspn(c.phone, "\n")] = 0;

            printf("Email: ");
            fgets(c.email, sizeof(c.email), stdin);
            c.email[strcspn(c.email, "\n")] = 0;

            fseek(fp, -sizeof(Contact), SEEK_CUR);
            fwrite(&c, sizeof(Contact), 1, fp);

            printf("Contact updated successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("No contact found with the name: %s\n", name);
    }

    fclose(fp);
}



void deleteContact() {
    FILE *fp, *temp;
    Contact c;
    char name[50];
    int found = 0;

    fp = fopen("contacts.dat", "rb");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    temp = fopen("temp.dat", "wb");
    if(temp == NULL) {
        printf("Error opening temporary file.\n");
        fclose(fp);
        return;
    }

    printf("Enter name to delete: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    while(fread(&c, sizeof(Contact), 1, fp)) {
        if(strcasecmp(c.name, name) == 0) {
            printf("Contact deleted successfully!\n");
            found = 1;
        } else {
            fwrite(&c, sizeof(Contact), 1, temp);
        }
    }
    if(!found) {
        printf("No contact found with the name: %s\n", name);
    }

    fclose(fp);
    fclose(temp);

    remove("contacts.dat");
    rename("temp.dat", "contacts.dat");
}



void displayContacts() {
    FILE *fp;
    Contact c;
    int count = 0;

    fp = fopen("contacts.dat", "rb");
    if(fp == NULL) {
        printf("Error opening file or no contacts available.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    while(fread(&c, sizeof(Contact), 1, fp)) {
        printf("\nName: %s\n", c.name);
        printf("Phone: %s\n", c.phone);
        printf("Email: %s\n", c.email);
        count++;
    }
    if(count == 0) {
        printf("No contacts available.\n");
    }

    fclose(fp);
}
