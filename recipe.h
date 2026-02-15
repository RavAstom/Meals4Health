/* Recipe Structure
 * ---------------------------------------------------------
 *
 * RECIPE
 * |
 * | -> name            (20 characters)
 * | -> classification  (starter / main / dessert)
 * | -> ingredients
 * |     |
 * |     | -> quantity  (can be fractional)
 * |     | -> unit      (15 characters)
 * |     | -> item      (name of the item)
 * |
 * | -> instructions    (can have 15 max, with 70 characters max each)
 * | -> servings
 * |
 * ---------------------------------------------------------
 */

typedef struct ingredient {
   float quantity;
   char  unit[15 + 1];
   char  item[20 + 1];

} ingredient;

typedef struct recipe {
   char        name[20 + 1 /* '\0 '*/];
   char        classification[7 + 1];
   ingredient  ingredients[20];
   char        instructions[15][70 + 1];
   int         servings;

} recipe;
