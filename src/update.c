#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void login(int *isLoggedIn, int *firstAttempt) {

   char username[20 + 1];
   char password[20 + 1];

   system("cls");

   if (*firstAttempt)
      printf("Please enter your Username & Password %d \n\n", *firstAttempt);
   else
      printf("Try Again!\n\n");

   printf("Username: ");
   printf("\n");
   printf("Password: ");   // Print both 'Username' & 'Password'

   printf("\033[1A");      // Move cursor upwards to input username
   scanf("%s", username);

   printf("\rPassword: "); // Reprint Password:
   scanf("%s", password);


   if (!(strcmp(username, "admin") && strcmp(password, "ad1234")))
      *isLoggedIn = 1;
   else {
      *firstAttempt = 0;
   }
}

void updateMenu (int choice) {

   int i;
   int maxoptions = 13;
   char options[][25] = {
      "Add Food-Calorie Info",
      "View Food-Calorie Chart",
      "Save Calorie Info",
      "Load Calorie Info",
      "Add Recipe",
      "Modify Recipe",
      "Delete Recipe",
      "List Recipe Titles",
      "Scan Recipies",
      "Search Recipe by Title",
      "Export Recipies",
      "Import Recipies",
      "Return to Main Menu"
   };
   printf("\t _____       _     _       \n");
   printf("\t|  |  |___ _| |___| |_ ___ \n");
   printf("\t|  |  | . | . | .'|  _| -_|\n");
   printf("\t|_____|  _|___|__,|_| |___|\n");
   printf("\t      |_|                  \n");
   printf("\n");
   printf("\n===============================================\n");
   printf("\t   Please select an option");
   printf("\n===============================================\n\n");

   for (i = 0; i < maxoptions; i++) {

      if (i == 4 || 
          i == 7 || 
          i == 12)      {printf("\n");}

      if (i == choice)  {printf("\t>>  %s\n", options[i]);}
      else              {printf("\t    %s\n", options[i]);}
   }
}

void update() {
   
   int running = 1;
   
   int isLoggedIn = 0;
   int firstAttempt = 1; // firstAttempt is to know when to display the try again screen.
   
   int choice = 0;
   int keypress;

   do {
   
      if (!isLoggedIn) 
         login(&isLoggedIn, &firstAttempt);
      

      else {

         system("cls");
         updateMenu(choice);
         
         keypress = getch();

         if (keypress == 224) { // arrow key first number
            keypress = getch();
         
            if       (keypress == 72 && choice > 0) {choice--;} // pressed up
            else if  (keypress == 80 && choice < 12) {choice++;} // pressed down
         }
         else if (keypress == 13) { // enter key
         
            switch (choice) {
               case 0 : printf("1"); break;
               case 1 : printf("2"); break;
               case 2 : printf("3"); break;
               case 3 : printf("3"); break;
               case 4 : printf("3"); break;
               case 5 : printf("3"); break;
               case 6 : printf("3"); break;
               case 7 : printf("3"); break;
               case 8 : printf("3"); break;
               case 9 : printf("3"); break;
               case 10: printf("3"); break;
               case 11: printf("3"); break;
               case 12: running = 0; break;

            }
         }
      }

   } while (running);


}
