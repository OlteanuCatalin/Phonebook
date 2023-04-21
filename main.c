#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node {
    char name[100];
    char phone[100];
    struct Node* next;
};


struct Node* head = NULL;

void add_contact(char* name, char* phone) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    strcpy(new_node->name, name);
    strcpy(new_node->phone, phone);

    if (head == NULL || strcmp(head->name, name) > 0) {
        new_node->next = head;
        head = new_node;
        return;
    }

    struct Node* current = head;
    while (current->next != NULL && strcmp(current->next->name, name) < 0) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void search_contact(char* name) {
    struct Node* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Name: %s\n", current->name);
            printf("Phone: %s\n", current->phone);
            return;
        }
        current = current->next;
    }
    printf("Contact not found\n");
}

void delete_contact(char* name) {
    struct Node* current = head;
    struct Node* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Contact not found\n");
}

void list_contacts() {
    struct Node* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Phone: %s\n", current->phone);
        current = current->next;
    }
}

void edit_contact(char* name, char* new_phone) {
    struct Node* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            strcpy(current->phone, new_phone);
            printf("Contact edited successfully\n");
            return;
        }
        current = current->next;
    }
    printf("Contact not found\n");
}

int main(){
	char u_name[100];
    char u_phone[100];
    char new_phone[100];
    int choice;
while(1){

  
printf("\t\t**********WELCOME TO PHONEBOOK*************");

printf("\n\n\t\t\t  MENU\t\t\n\n");
printf("\t1.Add New   \t2.List   \t3.Exit  \n\t4.Modify \t5.Search\t6.Delete\t\n\n");
printf("\n\tPlease Enter the Number you Want to Choose\n");


switch(getchar())
{
    case '1':
    	
    	printf("\nPlease enter the name: ");
    	scanf("%s",&u_name);
    	printf("\nPlease enter the phone number: ");
    	scanf("%s", &u_phone);
		add_contact(u_name,u_phone);
    	break;
   	case '2': 
	   	list_contacts();
    	break;
    case '3': 
		exit(0);
    	break;
    case '4':
		printf("\nPlease enter the name of the contact you wish to edit:");
		scanf("%s",&u_name);
		printf("\nPlease enter the new phone number: ");
		scanf("%s", &new_phone);
		edit_contact(u_name,new_phone);
    	break;
    case '5': 
    	printf("\nEnter name: ");
        scanf("%s", u_name);
        search_contact(u_name);
    	break;
    case '6': 
		printf("\nEnter name: ");
        scanf("%s", u_name);
        delete_contact(u_name);
        break;
    default:
                printf("\nEnter 1 to 6 only");
                printf("\n Enter any key");
                getchar();


}
}
}