# C++ Array Algorithms

## Unordered Array Algorithms

**Arrays** are sequential locations in memory that contain similar items. Arrays can be sorted or unsorted.

**Unordered Arrays** contain values in no particular order. Items can be appended to the end or inserted in the middle.

### Example code for appending with error checking:

```c++
void append(int array, int size, int &count, int value){
  if (count >= size){
    //Throw an exception
    //or increase array size
  }
  array[count++] = value;
}
```

_Constant O(1) efficiency_

### Example Code for inserting into an array with error checking

```c++
void insert(int array[], int size, int &count, int index, int value)
{
 if (count >= size)
 {
 // throw an exception
 // or increase array size
 }

 // move all values at locations >= insertion index
 for (int i = count; i > index; i--)
 {
 array[i] = array[i-1];
 }

 // add value at the appropriate location
 array[index] = value;
 count++;
}
```

_O(N) - linear time_

### Example Code for removing and returning the last added item with error checking

```c++
int removeLast(int array[], int size, int &count)
{
 if (count == 0)
 {
 // throw an exception
 }
 return array[--count];
}
```

_O(1) or constant order_

### Example code for removing an item from a specific location in an unordered array

```c++
int removeItem(int array[], int size, int &count, int index)
{
 if (count == 0)
 {
 // throw an exception
 }

 int value = array[index];
 count -= 1;
 for (int i = index; i < count; i++)
 {
 array[i] = array[i+1];
 }

 return value;
}
```

_O(N) - linear time (number of steps scales with the number of items in the array)_
