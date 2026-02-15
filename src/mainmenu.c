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


   printf("                                 (   )                             (   )                        (   ) (   )     (   )\n");
   printf(" ___ .-. .-.     .--.     .---.   | |      .--.           ,--.      | | .-.     .--.     .---.   | |   | |_      | | .-.\n");
   printf("(   )   '   \\   /    \\   / .-, \\  | |    /  _  \\         /   |      | |/   \\   /    \\   / .-, \\  | |  (   __)    | |/   \\\n");
   printf(" |  .-.  .-. ; |  .-. ; (__) ; |  | |   . .' `. ;       / .' |      |  .-. .  |  .-. ; (__) ; |  | |   | |       |  .-. .\n");
   printf(" | |  | |  | | |  | | |   .'`  |  | |   | '   | |      / / | |      | |  | |  |  | | |   .'`  |  | |   | | ___   | |  | |\n");
   printf(" | |  | |  | | |  |/  |  / .'| |  | |   _\\_`.(___)    / /  | |      | |  | |  |  |/  |  / .'| |  | |   | |(   )  | |  | |\n");
   printf(" | |  | |  | | |  ' _.' | /  | |  | |  (   ). '.     /  `--' |-.    | |  | |  |  ' _.' | /  | |  | |   | | | |   | |  | |\n");
   printf(" | |  | |  | | |  .'.-. ; |  ; |  | |   | |  `\\ |    `-----| |-'    | |  | |  |  .'.-. ; |  ; |  | |   | ' | |   | |  | |\n");
   printf(" | |  | |  | | '  `-' / ' `-'  |  | |   ; '._,' '          | |      | |  | |  '  `-' / ' `-'  |  | |   ' `-' ;   | |  | |\n");
   printf("(___)(___)(___) `.__.'  `.__.'_. (___)   '.___.'          (___)    (___)(___)  `.__.'  `.__.'_. (___)   `.__.   (___)(___)\n");
   printf("\n\n\n");
   printf("\tPlease Select an Option:");
   printf("\n\n");

   for (i = 0; i < maxoptions; i++) {

      if (i == choice)  {printf("\t>>\t %s\n", options[i]);}
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

   while (running) {
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
            case 0: printf("hii"); break;
            case 1: printf("noo"); break;
            case 2: running = 0;   break;
         }
      }

   }
}
