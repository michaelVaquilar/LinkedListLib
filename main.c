#include <stdio.h>
#include "LinkedListLib.c"
#include <string.h>


/// Small method for a unit test, checks if two objects are equal, if so they passed.
/// \param expected, the expected output
/// \param actual, the actual output
/// \param testName, the name of the test
void Test(void *expected, void *actual, const char* testName){
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

    Test(&i, Get(list, 0), "Add One Value");
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

    Test(&i, Get(list, 0), "Add Multiple Values");
    DestroyList(list);
}



//___________________________Main Below (Entry Point)________________

/// Main function
/// \return 0
int main() {
    TestAddOne();
    TestMultipleValue();
    return 0;
}