# Pointers and Dynamic Memory

## Overview

This week we explore pointers. They are used for array access and allocating dynamic memory. Before reference parameters were added to the language, pointers were the only way to do pass-by-reference. The use of pointers can contribute to segmentation faults in programs when they are not properly used.

## Learning Outcomes

- Explain what a pointer is and how to define one
- Use pointers instead of subscripting to access array elements
- Use pointers to pass values to functions and return them
- Use pointers to allocate and manage dynamic memory
  properly
- Use pointers to avoid memory segmentation errors
- Understand the difference between a const pointer and a pointer to a const

## What is a pointer?

Variables are locations in memory that hold values that may be changed. Pointers are simply variables that
hold addresses.

## How do you define a pointer?

A pointer is defined by using the \* to indicate that it is a pointer, along with the type of thing that it will point to.

```c++
int * p1; //a variable that holds the address of an integer
float * p2; //a variable that holds the address of a float
string * p3; //a variable that holds the address of a string
```

## How do you save the address of a variable in a pointer?

You use & + the variable name. For example

```c++
int x = 4;
p1 = &x; //stores the address of x in pointer p1
```

## How do you dereference a pointer?

You use the dereference operator '\*', which accesses the contents of the address stored in the pointer

```c++
#include <iostream>
using std::cout, std::endl;
int main()
{
 int x = 5;
 int y = 6;
 int *p = &x;

 cout << &x << " = " << x << endl;
 cout << &y << " = " << y << endl;
 cout << &p << " = " << p << " and that contains " << *p << endl;

 return 0;
}

```

## How do you access an array using a pointer?

1. Add an array to a program

```c++
int main()
{
 // create a static array
 const int SIZE = 10;
 int theArray[SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

 // access it with subscript operator
 // theArray[i] means the location i elements
 // past the start of the array
 for (int i = 0; i < 6; i++)
 {
 std::cout << theArray[i] << " ";
 }

 std::cout << std::endl;
 return 0;
}

```

2. Add a pointer to a program and set it equal to the address of the first element in the array

```c++
#include <iostream>
int main()
{
 const int SIZE = 10;
 int theArray[SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

 // set pointer to start of array using name
 int * ptr1 = theArray;

 // set pointer to start of array using address of first element
 int * ptr2 = &(theArray[0]);

 // output contents of both pointers, showing they have same value
 std::cout << ptr1 << std::endl;
 std::cout << ptr2 << std::endl;

 std::cout << std::endl;
 return 0;
}
```

## How do you display the elements of an array with a pointer?

```c++
#include <iostream>
int main()
{
 const int SIZE = 10;
 int theArray[SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

 for (int * ptr = theArray; ptr < theArray+SIZE; ptr++)
 {
 std::cout << *ptr << " ";
 }

 std::cout << std::endl;
 return 0;
}
```

## How do you pass a parameters to a function using a pointer reference?

To pass by reference, you use an ampersand to indicate in the function declaration that the compiler is to set up an alias to the variable being passed instead of copying it.

To pass by pointer reference, instead of using a reference or alias to the item, a pointer is used, which is a variable that holds an address.

### Pass By Reference

```c++
#include <iostream>

void exchange(int &x, int &y)
{
 int temp = x;
 x = y;
 y = temp;
}

int main()
{
 int a = 6, b = 7;

 std::cout << "a is " << a << " and b is " << b << std::endl;
 exchange(a, b);
 std::cout << "a is " << a << " and b is " << b << std::endl;

 return 0;
}

```

### Pass By Pointer Reference

```c++
#include <iostream>

void exchange(int *x, int *y)
{
 // pointers must be dereferenced to access
 // the contents of the passed addresses
 int temp = *x;
 *x = *y;
 *y = temp;
}

int main()
{
 int a = 6, b = 7;

 std::cout << "a is " << a << " and b is " << b << std::endl;
 exchange(&a, &b);
 std::cout << "a is " << a << " and b is " << b << std::endl;

 return 0;
}
```

## What is Dynamic Memory?

- **Local variables**: Defined in a function and lasting as
  long as the function is running
- **Static variables**: Persist outside of the function they are defined in.
- **Dynamic memory**: Allocated by the system’s memory manager and persists until it is freed up. It can be created in one function and passed to another.

## How do you allocate memory?

To allocated memory, use the **new** operator. This operator requests memory from the memory manager. The
memory manager allocates a block of that size and returns its address. Since new returns an address, it is
necessary to have a pointer defined to save it.

For example, the following program requests space for a single integer and saves the returned address in the
pointer variable ptr. To access the contents of that location, it is necessary to use the dereference operator \*.
The value of 6 is then stored in that location and then it is displayed.

```c++
#include <iostream>
using std::cout, std::endl;
int main()
{
 int *ptr = new int;

 *ptr = 6;

 cout << "The address is " << ptr << endl;
 cout << "Its contents are " << *ptr << endl;

 delete ptr;

 return 0;
}
```

## How do you free memory once a program is done with it?

Free memory using the **delete** operator, which releases the allocated memory. If not freed up a memory leak occurs and eventually program will fail when there is no more memory available for allocation.

Once memory has been freed it can no longer be accessed by another variable.

## How do you dynamically allocate memory for an array?

```c++
#include <iostream>
using std::cout, std::cin;
int main()
{
 int length;
 cout << "Enter a length for your array: ";
 cin >> length;

 int *myArray = new int[length];

 for (int i = 0; i < length; i++)
 *(myArray + i) = 2 * i + 1;

 delete [] myArray;

 return 0;
}
```

This program allocates space for an array of any size as long as the program is running.

## How do you access array elements dynamically?

```c++
for (int i = 0; i < length; i++)
{
 cout << *(theArray +i) << " ";
}
```

## How do you pass an array to a function using a pointer?

```c++
void display3(int *theArray, int length)
{
 for (int i = 0; i < length; i++)
 {
 cout << *(theArray +i) << " ";
 }
 cout << endl;
}

```

Compare with passing by reference

```c++
void display2(int theArray[], int length)
{
 for (int i = 0; i < length; i++)
 {
 cout << theArray[i] << " ";
 }
 cout << endl;
}
```

## How do you return an array from a function?

In order to successfully create an array in a function and return it to main, it is necessary to create it dynamically using **new**.

```c++
int *create(int size)
{
 int *theArray = new int[size];
 for (int i = 0; i < size; i++)
 {
 *(theArray + i) = 2 * i + 1;
 }
 return theArray;
}
int main()
{
 int length = 6;
 int *ptr = create(length);

 for (int i = 0; i < length; i++)
 {
 cout << *(ptr +i) << endl;
 }

 delete [] ptr;

 return 0;
}
```

## What is the difference between a constant pointer and a pointer to a constant?

A pointer itself can be a constant (always contains the same address).

A pointer can be defined as a pointer to a constant so it cannot be dereferenced and the location it points to changed

```c++
const int p = 5;
 int q = 6;

 // ptr1 points to a const
 // can not change the value it points to
 int const *ptr1 = &p;

 ptr1 = &q; // but ptr is not a constant, so it can change

 // ptr2 is a constant, it can not be changed
 // but the thing it points to can be changed
 int * const ptr2 = &q;

 *ptr2 = 6;

 // const ptr to const
 // neither can be changed
 int const * const ptr3 = &q;
```

## How to safely pass an array to a function using a pointer?

When passing arrays, or other large objects, using pointers, it is important to safely pass them so they cannot be changed unless the called function is designed to change them.

```c++
void display(int const * const ptr, int length);
```
