// NxN tic-tac-toes
#include <iostream>
using namespace std;

// The following 3 functions are helper functions to convert
// between 1D and 2D array indices.  The grid itself is stored
// as a 1D array.  However, for printing, checking who won,
// etc. it may be easier to write loops that generate separate
// row/column indices (i.e. treating the array like a 2D array).
// The functions below should be written using the hints in the
// writeup for performing the appropriate arithmetic conversion
// between 1D- and 2D-indices, and can then be called in any
// of the other functions when you find yourself wanting to 
// convert one to the other.

/**
 * Helper function - Given the grid array and its dimension
 *    as well as a particular row (r) and column (c), this
 *    function performs the arithmetic to convert r and c
 *    to a 1D index and returns that character in the grid.
 *    For example, for dim = 3 and r = 2, c = 1, this function
 *    should compute the corresponding index: 7 and return
 *    grid[7].
 *
 * Use this function wherever you generate, row/column
 *    indices and want to access that element in the grid.
 *    Pass the row/column indices as r and c, respectively.
 *
 */
char getEntryAtRC(char grid[], int dim, int r, int c);
/**
 * Helper function - Given a 1D index returns the row
 * that corresponds to this 1D index.  Use this in
 * conjunction with idxToCol() anytime you have a 1D index
 * and want to convert to 2D indices.
 */
int idxToRow(int idx, int dim);

/**
 * Helper function - Given a 1D index returns the column
 * that corresponds to this 1D index.  Use this in
 * conjunction with idxToRow() anytime you have a 1D index
 * and want to convert to 2D indices.
 */
int idxToCol(int idx, int dim);

/** Should print the tic-tac-toe board in a nice grid
 *  format as shown below:
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O'
 *         (the letter oh), or '?'.
 */
void printTTT(char grid[], int dim);

/** 
 * Should check if any player has won the game yet.
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *
 * Return value:
 *   Should return 1 if 'X' has won, 2 if 'O' has won, or 0 (zero)
 *   if the game is still undecided.
 * 
 */
int checkForWinner(char grid[], int dim);
/** 
 * Should check if there is no possible way any player can win.
 * More specifically, if there does not exist a row, column,
 * or diagonal that can still have 3 of a kind, then the game
 * will be a draw.
 * 
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *
 * Return value:
 *   Return true if no player can win given the current 
 *   game state, false otherwise.
 */
bool checkForDraw(char grid[], int dim);
 

/**********************************************************
 *  Write your implementations for each function prototyped
 *  above in the space below
 **********************************************************/

char getEntryAtRC(char grid[], int dim, int r, int c)
{
    return grid[(r * dim) + c];
}

int idxToRow(int idx, int dim)
{
  for (int i = 1; i <= dim; i++){ // check index in all rows using for loop
    if (idx < (i * dim)){ // if idx number is less than i*dim, then its in the ith row
      return (i-1); // the "first" row is classified as the 0th row, not the 1st row
    }
  }
}

int idxToCol(int idx, int dim)
{
    return idx % dim; // the remainder of idx/dim gives the column
}

void printTTT(char grid[], int dim)
{
  // outer loop generates rows
  for (int i = 0; i < dim; i++){

    // columns (entries)
    for (int j = 0; j < dim; j++){
      if (j != dim - 1){
        cout << " " << getEntryAtRC(grid, dim, i, j) << " |";
      }
      else {
        cout << " " << getEntryAtRC(grid, dim, i, j) << " ";
      }
    }
    
    cout << endl;

    // columns (seperator dashes (-))
    if (i != dim - 1){
      for (int k = 0; k < (3 * dim - 1 + dim); k++){
      cout << "-";
      }
      cout << endl;
    }
  }
}

int checkForWinner(char grid[], int dim)
{
  // There are three ways to win: diagonal lines, horizontal lines, vertical lines
  // We must cover all possible scenarios

  int numX_1 = 0; // numX counts how many X entries in row/column/diagonal
  int numO_1 = 0; // numO counts how many O entries in row/column/diagonal

  // Diagonal line: Two possible scenarios (Main Diagonal or Inverted Diagonal)
  // Check Main Diagonal:

  for (int i = 0; i < dim; i++){
    for (int j = 0; j < dim; j++){
      if ((getEntryAtRC(grid, dim, i, j) == 'X') && (i == j)){
        // all main diagonal entries are where row = columns
        numX_1++;
      } 
      else if ((getEntryAtRC(grid, dim, i, j) == 'O') && (i == j)){
        numO_1++;
      }
    }

    if (numX_1 == dim){
      return 1; // player X wins
    }
    else if (numO_1 == dim){
      return 2; // player O wins
    }
  }

  int numX_2 = 0;
  int numO_2 = 0;

  // Check Inverted Diagonal:

  for (int i = 0; i < dim; i++){
    for (int j = 0; j < dim; j++){
      if ((getEntryAtRC(grid, dim, i, j) == 'X') && (i == dim - j - 1)){
        // all inverted diagonal entries are where row = dimension - col - 1
        numX_2++;
      }
      if ((getEntryAtRC(grid, dim, i, j) == 'O') && (i == dim - j - 1)){
        numO_2++;
      }
      if (numX_2 == dim){
        return 1; // player X wins
      }
      else if (numO_2 == dim){
        return 2; // player O wins
      }
    }
  }  

  // Check Horizontal line:

  for (int i = 0; i < dim; i++){
    int numX_3 = 0;
    int numO_3 = 0;

    for (int j = 0; j < dim; j++){
      if (getEntryAtRC(grid, dim, i, j) == 'X'){
        numX_3++;
      }
      else if (getEntryAtRC(grid, dim, i, j) == 'O'){
        numO_3++;
      }
    }

    if (numX_3 == dim){
      return 1; // player X wins
    }
    else if (numO_3 == dim){
      return 2; // player O wins
    }
  }

  // Check Vertical line:

  for (int j = 0; j < dim; j++){
    int numX_4 = 0;
    int numO_4 = 0;

    for (int i = 0; i < dim; i++){
      if (getEntryAtRC(grid, dim, i, j) == 'X'){
        numX_4++;
      }
      if (getEntryAtRC(grid, dim, i, j) == 'O'){
        numO_4++;
      }
    }

    if (numX_4 == dim){
      return 1; // player X wins
    }
    else if (numO_4 == dim){
      return 2; // player O wins
    }
  }

  return 0;

}

// Create 3 helper functions to break down checking for draw into smaller tasks
// Checking diagonally, horizontally, and vertically

bool diagonalDraw(char grid[], int dim){
  int numX_5 = 0;
  int numO_5 = 0;

  // Main Diagonal

  for(int i = 0; i < dim; i++){
    for (int j = 0; j < dim; j++){
      if ((i == j) && getEntryAtRC(grid, dim, i, j) == 'X'){
        numX_5++;
      }
      if ((i == j) && getEntryAtRC(grid, dim, i, j) == 'O'){
        numO_5++;
      }
    }
  }

  if (numX_5 == 0 || numO_5 == 0){
    return false;
  }

  int numX_6 = 0;
  int numO_6 = 0;

  // Inverse Diagonal

  for(int i = 0; i < dim; i++){
    for (int j = 0; j < dim; j++){
      if ((i == dim - j - 1) && getEntryAtRC(grid, dim, i, j) == 'X'){
        numX_6++;
      }
      if ((i == dim - j - 1) && getEntryAtRC(grid, dim, i, j) == 'O'){
        numO_6++;
      }
    }
  }

  if (numX_6 == 0 || numO_6 == 0){
    return false;
  }

  return true;
}

bool horizontalDraw(char grid[], int dim){
  for (int i = 0; i < dim; i++){
    int numX_7 = 0;
    int numO_7 = 0; // reset counts for every row

    for (int j = 0; j < dim; j++){
      if (getEntryAtRC(grid, dim, i, j) == 'X'){
        numX_7++;
      }
      if (getEntryAtRC(grid, dim, i, j) == 'O'){
        numO_7++;
      }
    }
    if (numO_7 == 0 || numX_7 == 0){
      return false;
    }
  }
  return true;
}

bool verticalDraw(char grid[], int dim){
  for (int j = 0; j < dim; j++){
    int numX_8 = 0;
    int numO_8 = 0; // reset counts for every column

    for (int i = 0; i < dim; i++){
      if (getEntryAtRC(grid, dim, i, j) == 'X'){
        numX_8++;
      }
      if (getEntryAtRC(grid, dim, i, j) == 'O'){
        numO_8++;
      }
    }
    if (numO_8 == 0 || numX_8 == 0){
      return false;
    }
  }
  return true;
}

bool checkForDraw(char grid[], int dim)
{
  if (verticalDraw(grid, dim) && horizontalDraw(grid,dim) && diagonalDraw(grid, dim)){
    return true;
  }
  return false;
}



/**********************************************************
 *  Complete the indicated parts of main(), below. 
 **********************************************************/
int main()
{
   // This array holds the actual board/grid of X and Os. It is sized 
  // for the biggest possible case (11x11), but you should only 
  // use dim^2 entries (i.e. if dim=3, only use 9 entries: 0 to 8)
  char tttdata[121];
  
  // dim stands for dimension and is the side length of the 
  // tic-tac-toe board i.e. dim x dim (3x3 or 5x5). 
  int dim;
  // Get the dimension from the user
  cin >> dim;
  
  int dim_sq = dim*dim;

  for(int i=0; i < dim_sq; i++){
    tttdata[i] = '?';
  }

  // Print one of these messages when the game is over
  // and before you quit
  const char xwins_msg[] = "X player wins!";
  const char owins_msg[] = "O player wins!";
  const char draw_msg[] =  "Draw...game over!";
  
  bool done = false;
  char player = 'X';
  // Show the initial starting board
  printTTT(tttdata, dim);

  int playerInput;
    int turns = 0;

    cout << "Player X enter your square choice [0-" << dim_sq - 1 << "]: " << endl;
    cin >> playerInput;

  while(!done){

    //**********************************************************
    // Get the current player's input (i.e. the location they want to
    // choose to place their mark [X or O]) and update the tttdata array.
    // Be sure to follow the requirements defined in the guide/writeup
    // for quitting immediately if the user input is out-of-bounds 
    // (i.e. not in the range 0 to dim_sq-1) as well as continuing to 
    // prompt for an input if the user chooses locations that have already
    // been chosen (already marked with an X or O).
    //**********************************************************

    // Add your code here for getting input

    

    
      

      while(tttdata[playerInput] == 'X' || tttdata[playerInput] == 'O'){
        if(playerInput < 0 || playerInput > dim_sq - 1){
          break;
        }
        cout << "Already marked with an X or O, enter choice again: ";

        cin >> playerInput;
      }

      if (playerInput < 0 || playerInput > dim_sq - 1){
        break;
      }

      tttdata[playerInput] = player;
      printTTT(tttdata, dim);

      if (turns % 2 == 0){
        player = 'O';
      }
      else {
        player = 'X';
      }

      if (checkForWinner(tttdata, dim) == 1){
        done = true;
        cout << xwins_msg << endl;
        return 0;
      }
      if (checkForWinner(tttdata, dim) == 2){
        done = true;
        cout << owins_msg << endl;
        return 0;
      }
      if (checkForDraw(tttdata, dim)){
        done = true;
        cout << draw_msg << endl;
        return 0;
      }
      
      turns++;
      cout << "Player " << player << " enter your square choice [0-" << dim_sq - 1 << "]: ";
      cout << endl;
      cin >> playerInput;
      
      


    // Show the updated board if the user eventually chose a valid location
    // (i.e. you should have quit the loop and program by now without any 
    //  other output message if the user chosen an out-of-bounds input).
    printTTT(tttdata, dim);

    //**********************************************************
    // Complete the body of the while loop to process the input that was just
    //  received to check for a winner or draw and update other status, as 
    //  needed. 
    // 
    // To match our automated checkers' expected output, you must output 
    // one of the messages defined above using *one* of the cout commands 
    // (under the appropriate condition) below:
    //   cout << xwins_msg << endl;  OR
    //   cout << owins_msg << endl;  OR
    //   cout << draw_msg << endl;
    //
    // Note: Our automated checkers will examine a specific number of lines
    //  at the end of the program's output and expect to see the updated board
    //  and game status message.  You may certainly add some debug print  
    //  statements during development but they will need to be removed to 
    //  pass the automated checks.
    //**********************************************************







  } // end while

  return 0;
}
