#include<stdio.h>
#include<string.h>

#define LINE 100

typedef struct 
{
    /* data */
    char name[50];
    char phoneNumber[15];
    char email[100];
} Contact;

void addContact(Contact *contacts, int *numContacts);
void loadContacts(Contact *contacts, int *numContacts);
void displayContacts(Contact *contacts, int numContacts);
void saveContacts(Contact *contacts, int numContacts);


int main(){

    Contact contacts[100];
    int numContacts = 0;

    loadContacts(contacts, &numContacts);

    printf("\n\n\n---------------Contact Management System---------------\n");
    int choice;
    do{
    printf("\n\n-----Operations-----\n");

        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("6. Save and Exit\n");
        printf("\n\nEnter your choice:[1,2,6]\t");
        scanf("%d",&choice);
        getchar();//consume newline left-over;


        switch (choice)
        {
        case 1:
        /* code */
            addContact(contacts,&numContacts);
            break;
        case 2:
        /* code */
            displayContacts(contacts,numContacts);
            break;
        case 6:
            /* code */
                saveContacts(contacts,numContacts);
                break;
        
        default:
        printf("Invalid choice, please try again.\n");
            break;
        }
    } while (choice != 6);
   
    

    return 0;
}

void addContact(Contact *contacts, int *numContacts){
    printf("Enter Contact Details\n\nEnter Name:\t");
    fgets(contacts[*numContacts].name,sizeof(contacts[*numContacts].name),stdin);
    contacts[*numContacts].name[strcspn(contacts[*numContacts].name,"\n")] = 0;
    printf("%s\n",contacts[*numContacts].name);

    printf("Enter Phone Number:\t");
    fgets(contacts[*numContacts].phoneNumber,sizeof(contacts[*numContacts].phoneNumber),stdin);
    contacts[*numContacts].phoneNumber[strcspn(contacts[*numContacts].phoneNumber,"\n")] = 0;

    printf("Enter Email:\t");
    fgets(contacts[*numContacts].email,sizeof(contacts[*numContacts].email),stdin);
    contacts[*numContacts].email[strcspn(contacts[*numContacts].email,"\n")] = 0;

    (*numContacts)++;
}

// Function to Display Contacts

void displayContacts(Contact *contacts, int numContacts){
    printf("\n\n---------------------Contacts---------------------\n\n");
    for (int i = 0; i < numContacts; i++)
    {

        /* code */
        printf("Name:\t%s\n",contacts[i].name);
        printf("Phone Number:\t%s\n",contacts[i].phoneNumber);
        printf("Email:\t%s\n",contacts[i].email);

        printf("\n---\n\n");

        
    }

    puts("\n----------------------------------------------------\n");
    

}

void saveContacts(Contact *contacts,int numContacts){
    FILE *file = fopen("contacts.txt","w");

    if (file == NULL)
    {
        /* code */
        printf("Could not open file.\n");
        return;
    }
    for (int i = 0; i < numContacts; i++)
    {
        /* code */
        fprintf(file,"Name:\t%s\n",contacts[i].name);
        fprintf(file,"Phone Number:\t%s",contacts[i].phoneNumber);
        fprintf(file,"Email:\t%s",contacts[i].email);
        
    }

    fclose(file);
    
    
}

void loadContacts(Contact *contacts, int *numContacts){
    FILE *file = fopen("contacts.txt", "r");
    if (!file)
    {
        /* code */
        printf("Could not open file.\n");
        return;
    }

    char line[LINE];
    while(fgets(line,sizeof(line),file)!= NULL){
        if (strncmp(line, "Name:",6) == 0){
            strcpy(contacts[*numContacts].name,line + 6);
            contacts[*numContacts].name[strcspn(contacts[*numContacts].name,"\n")] = 0;
        }
        else if(strncmp(line, "Phone Number:",14) == 0){
            strcpy(contacts[*numContacts].phoneNumber,line + 14);
            contacts[*numContacts].phoneNumber[strcspn(contacts[*numContacts].phoneNumber,"\n")] = 0;

        }

        else if(strncmp(line, "Email:",7) == 0){
            strcpy(contacts[*numContacts].phoneNumber,line + 7);
            contacts[*numContacts].email[strcspn(contacts[*numContacts].email,"\n")] = 0;

        (*numContacts)++;
        }
        
    }

    fclose(file);


    
}