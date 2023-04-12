# C++ Array Algorithms

## Unordered Array Algorithms

**Arrays** are sequential locations in memory that contain similar items. Arrays can be sorted or unsorted.

**Unordered Arrays** contain values in no particular order. Items can be appended to the end or inserted in the middle.

### Appending to an Array with Error Checking

```c++
void append(int array, int size, int &count, int value){
  if (count >= size){
    //Throw an exception
    //or increase array size
  }
  array[count++] = value;
}
```

_**Time complexity**: Constant O(1) efficiency_

### Inserting into an array with error checking

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

_**Time complexity**: O(N) - linear time_

### Removing and returning the last added item with error checking

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

_Time complexity: O(1) or constant order_

### Removing an item from a specific location in an unordered array

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

_Time complexity: O(N) - linear time (number of steps scales with the number of items in the array)_

### Finding an item in an Unordered Array

```c++
bool find(int array[], int size, int count, int value)
{
 bool found = false;

 for (int i = 0; i < count && !found; i++)
 {
 if (array[i] == value)
 found = true;
 }
 return found;
}
// No error checking is required since function returns false if not found
```

_Time complexity: O(N)-linear time - directly related to the number of elements in the array_

### Finding and Removing an item in an Unordered Array (maintaining order)

```c++
bool removeValue(int array[], int size, int &count, int value)
{
 bool found = false;

 for (int i = 0; i < count && !found; i++)
 {
 if (array[i] == value)
 {
 count -= 1;
 for (int j = i; j < count; j++)
 {
 array[j] = array[j+1];
 }
 found = true;
 }
 }
 return found;
}

```

_Time complexity: O(N)-linear time - directly related to the number of elements in the array_

### Finding and removing an item in an Unordered Array (without maintaining order)

```c++
bool removeValue(int array[], int size, int &count, int value)
{
 bool found = false;

 for (int i = 0; i < count && !found; i++)
 {
  if (array[i] == value)
  {
  count -= 1;
  array[i] = array[count];
  found = true;
  }
 }
 return found;
}
```

_Time complexity: O(N)-linear time - directly related to the number of elements in the array_

## Ordered Array Algorithms

Ordered arrays are similar in all ways to unordered arrays, except that the elements are maintained
in a particular order, either from smallest to largest or largest to smallest. The following examples
will be using arrays sorted from largest to smallest.

### Adding new items to an Ordered Array

Since the array must be maintained in order, it is necessary to insert any new items in the
appropriate slot

```c++
void addItem(int array[], int size, int &count, int value)
{
 if (count >= size)
 {
 // throw and exception
 // or double the array and copy
 }
 // start at the last item in array
 int index = count-1;

 // move up all items smaller or until no more items
 while (index >= 0 && array[index] < value)
 {
 array[index+1] = array[index];
 index -= 1;
 }

 // place the new value and increment the count
 array[index+1] = value;
 count += 1;
}
```

_Time complexity: Since this algorithm copies on average count/2 items, it is an O(N) or linear algorithm_

### Binary Search: Finding items in an Ordered Array

```c++
bool binSearch(int array[], int size, int count, int value)
{
  int min = 0;
  int max = count - 1;
  bool found = false;

  while (max >= min && !found)
  {
    int mid = (min + max) / 2;
    if (array[mid] == value)
    {
      found = true;
    }
    else if (array[mid] > value)
    {
      min = mid + 1;
    }
    else
    {
      max = mid - 1;
    }
  }
  return found;
}

```

_Time complexity: Since this algorithm divides the array in ½ each time it checks a new location, the running time is log<sub>2</sub> of the number of items. This is written as O(log N)._

### Removing Items in an Ordered Array

```c++
bool binRemove(int array[], int size, int &count, int value)
{
  int min = 0;
  int max = count - 1;
  bool found = false;
  while (max >= min and !found)
  {
    int mid = (min + max) / 2;
    if (array[mid] == value)
    {
      count--;
      for (int i = mid; i < count; i++)
      {
        array[i] = array[i + 1];
      }
      found = true;
    }
    else if (array[mid] > value)
    {
      min = mid + 1;
    }
    else
    {
      max = mid - 1;
    }
  }

  return found;
}

```

_Time Complexity: This algorithm uses a binary search which is O(log N) and a compressing for loop which is O(N)_

## Sorting Algorithms

The three sorts described here are all O(N<sup>2</sup>). O( N log N) sorts will be covered in the future.

### What is stable sorting?

A sort is said to be stable if two items with equal keys appear in the same order in the sorted output as they appear in the input data. As an example, if the people in a town were sorted into alphabetical order, and then sorted them by zip code, the
zip code sort would be stable if the people in each zip code were still in order. It would be unstable if the ordering of some people were changed.
Both bubble and insertion sort are stable. Selection sort is not, as shown in [this article](https://www.geeksforgeeks.org/stable-selection-sort/).

### Bubble Sort

Bubble sort makes multiple passes through the data; on each pass adjacent items are compared and swapped if they are in the wrong order. It continues making passes until
no swaps are needed, which indicates that the list is sorted. The names come from the way in which larger or smaller items bubble to the top of the array. It is too slow and impractical for most problems.

```c++
void bubbleSort(int theArray[], int count)
{
  // go through each element in turn
  for (int i = 0; i < count; i++)
  {
    // bubble up the next largest
    // last i are sorted
    for (int j = 0; j < count - 1 - i; j++)
    {
      // do a swap if necessary
      if (theArray[j] > theArray[j + 1])
      {
        swap(theArray[j], theArray[j + 1]);
      }
    }
  }
}
```

_Time Complexity: The inner comparison is done N\*N times since each loop is executed N times. If the data is random, then a swap will be done ½ of the time, thus the overall efficiency of the algorithm is O(N<sup>2</sup>)._

### Selection Sort

One major problem with bubble sort is the number of swaps it performs. Selection sort is similar in that each loop through the data it moves the largest item to the top of the array, then it repeats moving the next largest one.

Each pass through the data with selection sort finds the largest (or smallest) item and swaps it with the leftmost unsorted item. It then repeats with the remaining unsorted data.

```c++
void selectionSort(int array[], int count)
{
  // go through each location in turn
  for (int i = 0; i < count; i++)
  {
    // find the index of the next smallest
    int minIndex = i;
    for (int j = i + 1; j < count; j++)
    {
      if (array[j] < array[minIndex])
      {
        minIndex = j;
      }
    }
    // swap the next smallest with array[i]
    swap(array[i], array[minIndex]);
  }
}
```

_Time complexity: Inner comparison is done N\*N times since the outer loop is executed N times and the inner loop is executed on average N/2 times. Thus, selection sort is also O(N<sup>2</sup>)._

Selection sort is significantly more efficient than the bubble sort, since there are only N swaps
performed instead of the possible N\*N/4 swaps in the bubble sort.

Selection sort is the most effective sort when picking some number of the smallest or largest values, as when determining who won a race. Otherwise, it is also a poor choice.

### Insertion Sort

The most efficient of these three sorts is the Insertion Sort – it is also order N<sup>2</sup> but works well for
data that is already partially sorted.

The algorithm starts with a sorted subset of the array (one element to start with), then takes the next element and inserts it into that sorted subset in the proper place.

Note that this is the same algorithm for insertion that is used for maintaining ordered arrays.

```c++
void insertionSort(int array[], int count)
{
  // insert next value into sorted
  // start of the array
  for (int i = 1; i < count; i++)
  {
    int value = array[i];
    int j = i - 1;

    // now move items up to find the right place for value
    while (j >= 0 and array[j] > value)
    {
      array[j + 1] = array[j];
      j -= 1;
    }
    // found the place!
    // but decremented j once too many times ...
    array[j + 1] = value;
  }
}
```

_Time complexity: The time complexity of insertion sort is O(n<sup>2</sup>), where n is the number of elements to be sorted._

## Parallel Arrays

Parallel arrays are two or more arrays of the same length that contain related data, where the corresponding elements in each array are associated with each other. In other words, each array in a set of parallel arrays contains a different aspect of a data set, and the data in each array are related to the same position in the other arrays.

For example, consider a set of parallel arrays that store information about students. One array might store the names of the students, another array might store their student IDs, and a third array might store their grades on an exam. Each element in the arrays corresponds to a single student, so the first element in each array corresponds to the first student, the second element corresponds to the second student, and so on.

Using parallel arrays can make it easier to work with related data because you can access and manipulate the data in each array independently. However, it also requires careful management to ensure that the corresponding elements in each array remain synchronized.

### Defining Parallel Arrays

```c++
// Initialize Arrays Students and grades (two arrays)
const int SIZE = 7;
string names[SIZE];
int grades[SIZE];

int count = 0;
const string FLAG = "DONE";
string name;
do {
 cout << "Enter a student name, done to end: ";
 cin >> name;
 if (name != FLAG)
 {
 names[count] = name;
 cout << "Enter the grade for " << name << ": ";
 cin >> grades[count];
 count += 1;
 }
} while (name != FLAG && count < SIZE);

```

### Using Parallel Arrays

```c++
cout << "What name do you want? ";
cin >> name;
bool found = false;
for (int i = 0; i < SIZE && !found; i++)
{
 if ( names[i] == name )
 {
 cout << name << " has a grade of " << grades[i] << endl;
 found = true;
 }
}
if (!found)
{
 cout << "There was no student with that name, sorry." << endl;
}

```

### Sorting Parallel Arrays

```c++
#include <iostream>
#include <string>
using namespace std;

// parallel arrays to be sorted
int arr1[] = {5, 3, 1, 4, 2};
string arr2[] = {"apple", "banana", "orange", "peach", "grape"};

int main() {
    // length of arrays
    int n = sizeof(arr1) / sizeof(arr1[0]);

    // selection sort algorithm
    for (int i = 0; i < n-1; i++) {
        // find the minimum element in the remaining unsorted part of arr1
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr1[j] < arr1[min_idx]) {
                min_idx = j;
            }
        }

        // swap the minimum element in arr1 with the current element
        int temp1 = arr1[i];
        arr1[i] = arr1[min_idx];
        arr1[min_idx] = temp1;

        // swap the corresponding element in arr2
        string temp2 = arr2[i];
        arr2[i] = arr2[min_idx];
        arr2[min_idx] = temp2;
    }

    // print the sorted parallel arrays
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " " << arr2[i] << endl;
    }
    return 0;
}

```

## Exceptions

One problem when programming is how to handle exceptions – that is situations where something
goes wrong or a function or method is not able to return a valid value

### Justification

```c++
// getValue returns the contents of an array at a given location
// if the program is attempting to access past the end of the array
// an error occurs
int getValue(int const theArray[], int size, int index)
{
  if (index >= size)
  {
    cout << "Past the end" << endl;
    return -1;
  }
  return theArray[index];
}
int main()
{
  const int SIZE = 10;
  int value;
  int theArray[SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
  for (int i = 0; i < SIZE; i++)
  {
    cout << theArray[i] << " ";
  }
  cout << endl;

  if ((value = getValue(theArray, SIZE, 10)) == -1)
  {
    cout << "Error occurred" << endl;
  }
  else
  {
    cout << "That location contains " << value << endl;
  }

  return 0;
}
```

If an error occurs, the getValue function will return a -1. Unfortunately, since this is an integer
array, that is a possible legal value. So, the calling program might report an error when there
actually was none. Other than defining some more complicated return type that can contain both a return status and a
value, there is no good solution other than throwing an exception.

### Throwing an Exception

Throwing an exception means that the function does not return in the normal manner. Instead, the
runtime environment terminates the function and works its way up the call stack checking each
calling method in turn until it finds one that has set up an exception handler. If it reaches main
without finding an exception handler, main is terminated and the runtime program that calls main
will deal with the exception – not normally desirable.

### Catching an Exception

Example

```c++
#include <iostream>
#include <stdexcept>
using std::cout, std::endl, std::out_of_range, std::exception;
// getValue returns the contents of an array at a given location
// checking for accessing past the end of the array
int getValue(int const theArray[], int size, int index)
{
  if (index >= size)
  {
    throw out_of_range("Index past end of array");
  }
  return theArray[index];
}
int main()
{
  const int SIZE = 10;
  int value, theArray[SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
  for (int i = 0; i < SIZE; i++)
  {
    cout << theArray[i] << " ";
  }
  cout << endl;

  // this try block calls the function to see if an exception occurs
  // if not, it outputs the value in the array at that location
  try
  {
    value = getValue(theArray, SIZE, 10);

    cout << "The value is " << value << endl;
  }
  // this catch will catch any standard exception
  // and display the string that was part of its throw
  catch (exception &ex)
  {
    cout << "Caught exception with message: " << ex.what() << endl;
  }
  // once the try/catch is done, execution continues here
  cout << "After the catch" << endl;

  return 0;
}
```

When getValue is executed, if the index is past the end of the array, it throws an exception. In this
case, it was the exception std::out_of_range. This is an object of the class exception that requires a
string literal as an argument explaining why the exception what thrown. This message is displayed
by calling what() on the object. Notice that the parameter to catch is a reference of the type of
exception being looked for.

The try block simply executes the code inside the { }. If an exception is thrown by something inside
that block, then any catch methods are checked in turn. A catch is like any other overloaded
function in that the argument type determines which catch is used. For example, the following
try/catch block will check in turn for a standard exception and then anything.

Only one of the catch blocks will actually be executed. If none of them match the type of the
thrown object or there is no default catch ( ... ), then this program will terminate and
whoever called it will have to deal with the exception.

Once the exception has been handled, and assuming that the program is not terminated
with an exit or return, execution continues with the first line of code after the last catch.
