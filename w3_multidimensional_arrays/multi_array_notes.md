# Multidimensional Arrays

## What is a multidimensional array?

A multidimensional array is an array of arrays. Can be thought of as a table (has rows and columns)

## Simple example of a multidimensional array

```c++

int main (){
  int foo[2][3]  = {{2,3,4},{5,6,7}};
  // First field field is how many rows (how many arrays you create)
  // Second field is how many columns (how many values you add to each array)


  std::cout << foo[0][2]; // -> 4

  int multTable[5][5] =
    {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    }

    std::cout << multTable[3][2] -> 18

}

```

## Print a Multidimensional array

```c++

int main (){
  int bar[2][3]  = {{1,2,3},{7,8,9}};

  // To print we need to loop, first loop through each row

  for (int row=0; row < 2, row++){
    for (int col=0; col < 3; col++){
      std::cout << bar[row][column] << " ";
    }
    std::cout<< endl; // Insert new line only after looping through all values in the 'row'
  }
}
```

## Create a Multiplication table

```c++
const int SIZE = 12;
void fillTable(int array[][SIZE], int size);
// Must indicate the size of all dimensions past first one
void displayTable(int array[][SIZE], int size);


int main(){
  int table[SIZE][SIZE];
  fillTable(table, SIZE);
  displayTable(table, SIZE);

  return 0;
}


void fillTable(int array[][SIZE], int size){
  for (int x = 0; x < size; x++ ){
    for (int y = 0; y < size; y++){
      array[x][y] = (x + 1)* (y + 1);
    }
  }
};
void displayTable(int array[SIZE], int size){
  for (int x = 0; x < size; x++){
    for (int y = 0; y < size; y++){
      std::cout << std::setw(4) << array[x][y];
    }
    std::cout << std::endl;
  }
};
```
