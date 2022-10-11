#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_USERS 10
#define ADMIN_UID 0
#define UNAME_MAX_LENGTH 200

char buffer[NUM_USERS][UNAME_MAX_LENGTH];
int uid[NUM_USERS + 1];
int *currUID = &uid[0];
int savedUsers = 0;

void rootLogin() {
    system("/bin/sh");
}

void menu() {
    puts("1. Add user");
    puts("2. Login");
    puts("3. Exit");
    printf("> ");
}

//Gets a "unique" UID seed for all users in this DB in a terrible way
int getUIDseed(int unameLength)
{
	//Because 4 is a nice number and is fun :)
	int uid = 4;
	for (int i = 0; i < unameLength; i++)
	{
	//Because 4 is a nice number and is fun :)
		uid = (uid * 4);
	}
	//If the UID was to be negative make it positive.
	if (uid < 0)
	{
		uid = uid * -1;
	}
	return uid;
}

//
void login()
{
	//If you access login directory the curr_uid will automatically be 0 therefore shell access is gained
	int found = 0;
	char username[UNAME_MAX_LENGTH];
	printf("Login as user: ");
    	scanf("%s", username);
    		
    	//For the number of space in the database (Max Users) , if the UID of the matching user is the admin UID, login as root otherwise  
	for(int i = 0; i < NUM_USERS; i++)
	    {
		if(buffer[i] != NULL)
		{
		    //check if the username matches any username in the database (buffer)
		    if(strcmp(buffer[i], username) == 0)
		    {
		    	printf("Loop: %d\n", i);
		    	printf("UID: %d\n", uid[i + 1]);
		      	found = 1;
			printf("Welcome %s!\n Current user ID: %d\n", username, uid[i + 1]);
			//If the user is an admin
			if(uid[i] == ADMIN_UID)
			{
				rootLogin();
			}
		    }
		}
	    }
	    if(!found)
	    {
		printf("User %s not found\n", username);
	    }
}

//Set all elements of the UID array to -1
void initUIDArr()
{
	for(int i = 1; i < NUM_USERS; i++)
	{
		uid[i] = -1;
	}
}

void add_user()
{
	char username[UNAME_MAX_LENGTH];
	printf("Username: ");
	//Gets the username from the user
	gets(username);
	//Copies the username into the buffer
	strcpy(buffer[savedUsers], username);	
	//If it is the first user in the DB
	if(savedUsers == 0)
	{
		//Create the "UID seed"
		*currUID = getUIDseed(strlen(username));
	}
	else
	{
		//Ensures every user  is unique without the need to double check
		*currUID = *currUID + 1;
	}
	uid[savedUsers + 1] = *currUID;
	printf("\nUser ID: %d\n", *currUID);
	printf("%s added to the DB\n", username);
	savedUsers++;
		printf("Saved Users: %d\n", savedUsers);
}

int main() 
{
	int choice = -1;
	initUIDArr();
	if(savedUsers == 0)
	{
		printf("You are the first user to use this database, please create your account\n");
		add_user();
	}
	//Loop the menu until input is no longer valid
	menu();
	while(1) 
	{
		scanf("%d", &choice);
		if(choice  == 1) {
		    add_user();
		    choice = 0;
		} else if(choice == 2) {
		    login();
		    choice = 0;
		} else if(choice == 3){
		    exit(1);
        }
    }
    return 0;
}
