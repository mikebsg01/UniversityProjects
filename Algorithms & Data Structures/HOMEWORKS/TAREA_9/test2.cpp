// C++ program to illustrate dynamic allocation
// and deallocation of memory using new and delete
#include <iostream>
#include <malloc.h>
using namespace std;

int main ()
{
    // Pointer initialization to null
    int* p = NULL;
    int* a = NULL;
 
    // Request memory for the variable
    // using new operator
    p = (int*) malloc(sizeof(int));
    if (!p)
        cout << "allocation of memory failed\n";
    else
    {
        // Store value at allocated address
        *p = 29;
        cout << "Value of p: " << *p << endl;
    }
 
    // Request block of memory
    // using new operator
    float *r = (float*) malloc(sizeof(float));
    *r = 75.25;
 
    cout << "Value of r: " << *r << endl;

    a = p;

    // freed the allocated memory
    free(p);
    p = NULL;
    free(r);

    cout << "valor P: " << (p == NULL ? 0 : *p) << endl;
    cout << "valor A: " << (a == NULL ? 0 : *a) << endl;
    cout << "valor R: " << (r == NULL ? 0 : *r) << endl;
 
    return 0;
}