#include <stdio.h>
#include <stdlib.h>


/*******************************************************************************/
/*******************************************************************************/
/*
0)

Given the structure below:

Questions:
- What is the size of this struct?
- How does the memory layout look?
- Why does padding appear?
- How can you avoid padding?
*/

struct Example 
{
    char a;
    int  b;
    char c;
};
/*******************************************************************************/
/*******************************************************************************/


/*******************************************************************************/
/*******************************************************************************/
/*
1)

Declare a void pointer and determine its size.
Does the size of a void* depend on the architecture?
*/

void void_pointer_example()
{
    void *ptr;
    size_t size = sizeof(ptr);
    printf("Size of void*: %zu\n", size);
}
/*******************************************************************************/
/*******************************************************************************/
/*
2)
You are given the following C program.

1. Determine what values are printed on the console.
2. Identify which function modifies the variable `event_counter`.
3. Explain the difference between pass-by-value and pass-by-address in this example.
4. Explain why `inc_counter` can be used as a callback function in an embedded system.
*/

#include <stdio.h>
#include <stdint.h>

// TODO what is this?
typedef void (*counter_cb_t)(uint32_t *counter);

// TODO what is this?
void inc_counter(uint32_t *counter)
{
    (*counter)++;
}

// TODO what is this?
void on_event(counter_cb_t cb, uint32_t *counter)
{
    cb(counter);
}

// TODO what happens with counter? Is it pass by value or reference?
void inc_by_value(uint32_t counter)
{
    counter++;
}

int main(void)
{
    uint32_t event_counter = 5;

    on_event(inc_counter, &event_counter);
    printf("%lu\n", event_counter);

    inc_by_value(event_counter);
    printf("%lu\n", event_counter);

    return 0;
}

/*******************************************************************************/
/*******************************************************************************/
/*
3)

What is the size of an array of 10 integers?
(Assume sizeof(int) is 4bytes.)
*/

void array_size_example()
{
    int a[10];
    printf("Size of array: %zu\n", sizeof(a));
}
/*******************************************************************************/
/*******************************************************************************/


/*******************************************************************************/
/*******************************************************************************/
/*
4)

Explain why sizeof(a) in main is different from sizeof(b) inside function f.
What happens to arrays when passed as function parameters?
 Console output:
    40
    8
*/

#include <stdio.h>

void f(int b[10]) 
{
    printf("%zu\n", sizeof(b));
}

void sizeof_decay_example(void) 
{
    int a[10];
    printf("%zu\n", sizeof(a));
    f(a);
}


int main()
{
    sizeof_decay_example();
    return 0;

}
/*******************************************************************************/
/*******************************************************************************/
/*
5)

What happens in this code?
Is the behavior defined or undefined? Why?
*/

void out_of_bounds_example() 
{
    int arr[3] = {1, 2, 3};
    int *p = arr;

    printf("%d\n", *(p + 3));
}

/*******************************************************************************/
/*******************************************************************************/
/*
6)

What is the output of this function and why?
Explain the implicit type conversion rules involved.
*/

void foo(void)
{	
    unsigned int a = 6;
    int b = -20;
    (a + b > 6) ? printf("> 6") : printf("<= 6");
}
/*******************************************************************************/
/*******************************************************************************/


/*******************************************************************************/
/*******************************************************************************/

/*******************************************************************************/
/*******************************************************************************/


/*******************************************************************************/
/*******************************************************************************/
/*
7)

Explain what is wrong in the following code.
What happens when returning the address of a local variable?
Compare it with dynamically allocated memory (malloc).
Who is responsible for freeing the memory?
*/

int* createValue() 
{
    int x = 42;
    return &x;   
}

int* createValueDin() 
{
    int *p = malloc(sizeof(int));
    *p = 10;
    // free(p);
    return p;
}
/*******************************************************************************/
/*******************************************************************************/


/*******************************************************************************/
/*******************************************************************************/
/*
8)

What does the following declaration mean?

    int (*a[10])(int);

Explain clearly what 'a' represents.
*/

int (*a[10])(int);
/*******************************************************************************/
/*******************************************************************************/
9)
#include <stdio.h>

size_t len(int a[]) 
{
     return sizeof(a) / sizeof(a[0]);    
}


// why is the output 2?
int main()
{
   int x[10]; 
   printf("%zu\n", len(x));
    return 0;

}



/*******************************************************************************/
/*******************************************************************************/
/*
10)

Implement a function that returns the address of a static variable.
The static variable must retain its value across multiple function calls.
The solution must be memory-efficient and suitable for embedded systems
(e.g., 8-bit microcontrollers).
*/
/*******************************************************************************/
/*******************************************************************************/