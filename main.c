#include <stdio.h>
#include "LinkedListLib.c"
#include <string.h>


/// Small method for a unit test, checks if two objects are equal, if so they passed.
/// \param expected, the expected output
/// \param actual, the actual output
/// \param testName, the name of the test
void Test(int expected, int actual, const char* testName){
    if(expected == actual){
        printf("%s : PASSED\n", testName);
    }else {
        printf("%s : FAILED expected: %d actual: %d\n", testName, expected, actual);
    }
}

//_________________________All Test_________________________________

void TestAddOne(){
    int i = 10;
    LIST *list = Init();
    Add(list, &i);
    int *result = Get(list, 0);
    Test(i, *result, "Add One Value");
    DestroyList(list);
}

void TestMultipleValue(){
    int i = 10;
    int x = 23;
    int y = -24;
    int z = 34;
    LIST *list = Init();
    Add(list, &i);
    Add(list, &x);
    Add(list, &y);
    Add(list,&z);
    int *result = Get(list, 2);
    Test(y, *result, "Add Multiple Values");
    DestroyList(list);
}

void TestIndexOf(){
    int i = 10;
    int x = 23;
    int y = -24;
    int z = 34;
    LIST *list = Init();
    Add(list, &i);
    Add(list, &x);
    Add(list, &y);
    Add(list,&z);

    //[10,23,-24,34]
    int result = IndexOf(list, &y);
    Test(3, result, "IndexOf Included int"); //Index of returns the location from which it was added,
    //not index of it in an array.
}

void TestIndexOfFail(){ //This should return -1
    int i = 10;
    int x = 23;
    int y = -24;
    int z = 34;
    LIST *list = Init();
    Add(list, &i);
    Add(list, &x);
    Add(list, &y);

    //[10,23,-24,34]
    int result = IndexOf(list, &z);
    Test(-1, result, "IndexOf Fail int"); //Index of returns the location from which it was added,
    //not index of it in an array.
}





//___________________________Main Below (Entry Point)________________

/// Main function
/// \return 0
int main() {
    TestAddOne();
    TestMultipleValue();
    TestIndexOf();
    TestIndexOfFail();
    return 0;
}