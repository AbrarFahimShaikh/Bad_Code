#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char name[50];
    char phone[20];
};

int main()
{
    struct Contact contacts[100];
    int num_contacts = 0;
    int choice, index, dlt_index;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Update Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Add contact
            if (num_contacts < 100)
            {
                printf("Enter name: ");
                scanf("%49s", contacts[num_contacts].name);
                printf("Enter phone number: ");
                scanf("%19s", contacts[num_contacts].phone);
                num_contacts++;
                printf("Contact has been added!\n");
            }
            else
            {
                printf("Sorry, the maximum number of contacts has been reached.\n");
            }
            break;

        case 2: // List contacts
            printf("Contacts: \n");
            for (int i = 0; i < num_contacts; i++)
            {
                printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
            }
            break;

        case 3: // Update contact
            printf("Enter the index of the contact to update: ");
            scanf("%d", &index);
            if (index >= 0 && index < num_contacts)
            {
                printf("Enter a new name: ");
                scanf("%49s", contacts[index].name);
                printf("Enter a new phone number: ");
                scanf("%19s", contacts[index].phone);
                printf("Contact has been updated!\n");
            }
            else
            {
                printf("Invalid index. Please enter a valid index.\n");
            }
            break;

        case 4: // Delete contact
            printf("Enter the index of the contact to delete: ");
            scanf("%d", &dlt_index);
            if (dlt_index >= 0 && dlt_index < num_contacts)
            {
                for (int i = dlt_index; i < num_contacts - 1; i++)
                {
                    strcpy(contacts[i].name, contacts[i + 1].name);
                    strcpy(contacts[i].phone, contacts[i + 1].phone);
                }
                num_contacts--;
                printf("Contact has been deleted.\n");
            }
            else
            {
                printf("Invalid index. Please enter a valid index.\n");
            }
            break;

        case 5: // Exit
            printf("Exiting.\n");
            exit(0);

        default:
            printf("Invalid choice. Please choose a valid option.\n");
        }
    }
    return 0;
}
