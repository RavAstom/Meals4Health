#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // for arrow keys

#include "access.c"
#include "update.c"

/*
 * printmenu() displays the main menu & the options
*/

void printmenu (int choice) {
   
   int i;
   int maxoptions = 3;
   char options[][10] = {
      "Update",
      "Access",
      "Exit"
   };

   printf("\n");
   printf("   _____         _        ___    _____         _ _   _   \n");
   printf("  |     |___ ___| |___   | | |  |  |  |___ ___| | |_| |_ \n");
   printf("  | | | | -_| .'| |_ -|  |_  |  |     | -_| .'| |  _|   |\n");
   printf("  |_|_|_|___|__,|_|___|    |_|  |__|__|___|__,|_|_| |_|_|\n");
   printf("\n");
   printf("  ==========================================\n");
   printf("\t   Please Select an Option:");
   printf("\n  ==========================================\n\n");

   for (i = 0; i < maxoptions; i++) {
      
      if (i == choice)  {printf("\t>>\t %s\t      <<\n", options[i]);}
      else              {printf("\t\t %s\n", options[i]);}
   }
}




/*
 * mainmenu() provides the main menu functionality 
 *             which allows the user to access
 *             different features of the app.
 *
 *
*/ 
void mainmenu() {

   int running = 1;
   int choice = 0;
   int keypress;



   do {
      system("cls");
      printmenu(choice);
   
      keypress = getch();

      if (keypress == 224) { // arrow key first number
         keypress = getch();
      
         if       (keypress == 72 && choice > 0) {choice--;} // pressed up
         else if  (keypress == 80 && choice < 2) {choice++;} // pressed down
      }
      else if (keypress == 13) { // enter key
      
         switch (choice) {
            case 0: update();       break;
            case 1: printf("noo");  break;
            case 2: running = 0;    break;
         }
      }

   } while (running);
}
