// // #include <stdio.h>
// // #include <string.h>

// // // define max to limit the user or the users from making the array to lag or something when iterating on it

// // #define Max_Users 100

// // // length of username and password to prevent user from making weird and un real user name and password like large names or somthing like that
// // #define Max_UserName_Length 50

// // #define Max_Password_Length 50

// // char usernames[Max_Users][Max_UserName_Length];

// // char passwords[Max_Users][Max_Password_Length];

// // union UserStatus {
// //     int active;  // 0 or 1 indicating active or inactive
// // };

// // union UserStatus userStatus[Max_Users];


// // int UserCount = 0;

// // int main(){

// //     int choice;

// //     while(1){

// //         printf("Welcome To The SignIn/SignUp Screen:\n");
// //         printf("1- SignIn\n");
// //         printf("2- Don't Have An Account? SignUp\n");
// //         printf("3- Exit\n");
// //         printf("Enter Your Choice: \n");
// //         // we wll use scanf to expect an integer input and check that while to make it work as expected you know
// //         scanf("%d", &choice);

// //         if (choice == 1)
// //         {
// //             char InputUserName[Max_UserName_Length];
// //             char InputPassword[Max_Password_Length];

// //             printf("Enter Your Username: ");
// //             scanf("%s", InputUserName);
// //             printf("Enter Your Password: ");
// //             scanf("%s", InputPassword);

// //             int found = 0;
// //             for (int i = 0; i < UserCount; i++)
// //             {
// //                 if (strcmp(usernames[i], InputUserName) == 0 && strcmp(passwords[i], InputPassword) == 0){
// //                     found = 1;
// //                     break;
// //                 }
// //             }
            
// //             if (found){
// //                 printf("\nWelcome Home! It's me, Mahmoud, The Owner Of The Task Hahahahaha\n\n");
// //             }else{
// //                 printf("\nTry Again Theif It's Wrong. The Username Or Password Is Incorrect\n\n");
// //             }
// //         }else if (choice == 2){
// //             if (UserCount >= Max_Users){
// //                 printf("Sorry The Database Is Full\n\n");
// //                 continue;
// //             }

// //             char NewUserName[Max_UserName_Length];
// //             char NewPassword[Max_Password_Length];

// //             printf("Enter Username: ");
// //             scanf("%s", NewUserName);

// //             printf("Enter Password (at least 8 characters or numbers): ");
// //             scanf("%s", NewPassword);

// //             if (strlen(NewPassword) < 8 )
// //             {
// //                 printf("\nPassword Must Be At Least 8 Characters Or Numbers\n\n");
// //             }else{
// //                 strcpy(usernames[UserCount], NewUserName);
// //                 strcpy(passwords[UserCount], NewPassword);
// //                 UserCount++;
// //                 printf("\nAcoount Created Successfully! You Can Now SignIn\n\n");
// //             }
            



// //         }else if(choice == 3){
// //             printf("Exiting The Program, GoodBye!\n");
// //             break;
// //         }
        
// //         else{
// //             printf("\nInvalid Choice, Enter 1 Or 2 Or 3\n\n");
// //         }
        
// //     }

// //     return 0;
// // }

// the above code is the first task because loically i cant be agree with your logic

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define Max_Users 100
#define Max_UserName_Length 50
#define Max_Password_Length 50

char usernames[Max_Users][Max_UserName_Length];
char passwords[Max_Users][Max_Password_Length];

union UserStatus {
    int active;  
};

union UserStatus userStatus[Max_Users];

int UserCount = 0;

void toLowercase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int main(){

    int choice;

    while(1){

        printf("Welcome To The SignIn/SignUp Screen:\n");
        printf("1- SignIn\n");
        printf("2- Don't Have An Account? SignUp\n");
        printf("3- Exit\n");
        printf("Enter Your Choice: \n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            char InputUserName[Max_UserName_Length];
            char InputPassword[Max_Password_Length];

            printf("Enter Your Username: ");
            scanf("%s", InputUserName);
            printf("Enter Your Password: ");
            scanf("%s", InputPassword);

            int found = 0;
            for (int i = 0; i < UserCount; i++)
            {
                if (strcmp(usernames[i], InputUserName) == 0 && strcmp(passwords[i], InputPassword) == 0){
                    found = 1;
                    if (userStatus[i].active) {
                        printf("\nWelcome Home! It's me, Mahmoud, The Owner Of The Task Hahahahaha, MeanWhile Your Account Is Activate Now \n\n");
                    } else {
                        printf("\nAccount is not active. Please contact support.\n\n");
                    }
                    break;
                }
            }
            
            if (!found){
                printf("\nTry Again Thief! The Username Or Password Is Incorrect\n\n");
            }
        } else if (choice == 2){
            if (UserCount >= Max_Users){
                printf("Sorry The Database Is Full\n\n");
                continue;
            }

            char NewUserName[Max_UserName_Length];
            char NewPassword[Max_Password_Length];
            char IsActiveStr[10];

            printf("Enter Username: ");
            scanf("%s", NewUserName);

            do {
                printf("Enter Password (at least 8 characters or numbers): ");
                scanf("%s", NewPassword);

                if (strlen(NewPassword) < 8 ) {
                    printf("\nPassword Must Be At Least 8 Characters Or Numbers\n\n");
                }

            } while (strlen(NewPassword) < 8);

            printf("Choose Account Status (false or true, 0 or 1): ");
            scanf("%s", IsActiveStr);

            toLowercase(IsActiveStr);  
            int IsActive;
            if (strcmp(IsActiveStr, "true") == 0 || strcmp(IsActiveStr, "1") == 0) {
                IsActive = 1;
            } else if (strcmp(IsActiveStr, "false") == 0 || strcmp(IsActiveStr, "0") == 0) {
                IsActive = 0;
            } else {
                printf("\nInvalid choice for account status. Setting account as active by default.\n");
                IsActive = 1;
            }

            strcpy(usernames[UserCount], NewUserName);
            strcpy(passwords[UserCount], NewPassword);
            userStatus[UserCount].active = IsActive;
            UserCount++;
            printf("\nAccount Created Successfully! You Can Now SignIn\n\n");
        } else if(choice == 3){
            printf("Exiting The Program, GoodBye!\n");
            break;
        } else {
            printf("\nInvalid Choice, Enter 1 Or 2 Or 3\n\n");
        }
    }

    return 0;
}
