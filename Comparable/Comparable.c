
#include <string.h>


/// Compares two string values
/// \param str1, first string to compare.
/// \param str2, second string to compare
/// \return -1 if str2 is bigger, 1 if str1 is bigger, 0 if strings are equal.
int compareString(char *str1, char *str2){ return strcmp(str1, str2);}


/// Compares int values to eachother
/// \param x
/// \param y
/// \return
int compareInt(const void *x, const void *y)
{
    return ((*(int *)x) - (*(int *)y));
}

