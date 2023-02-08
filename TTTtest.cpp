#include <iostream>
using namespace std;

int idxToRow(int idx, int dim);
int idxToCol(int idx, int dim);

int main(){

  //cout << 0%3 << endl;
  //cout << 1%3 << endl;
  //cout << 2%3 << endl;

  //int x, y;
  //cin >> x >> y;

  //cout << idxToCol(x, y);

  int dim;

  cin >> dim;
  // rows
  for (int i = 0; i < dim; i++){

    // columns (entries)
    for (int j = 0; j < dim; j++){
      cout << " " << "?" << " |";
    }
    cout <<'\b';  
    cout <<' ';
    cout << endl;

    // columns (seperator)
    for (int k = 0; k < 4*dim; k++){
      cout << "-";
    }
    cout << endl;

  }
  return 0;
}
  
  


int idxToRow(int idx, int dim){
  for (int i = 1; i <= dim; i++){
    if (idx < (i * dim)){
      return (i-1);
    }
  }
}

int idxToCol(int idx, int dim){
    return idx % dim; // the remainder of idx/dim gives the column
}
if (checkForDraw(tttdata, dim)){
        cout << draw_msg << endl;
        exit(0);
      }

      && verticalDraw(grid, dim) && horizontalDraw(grid, dim)