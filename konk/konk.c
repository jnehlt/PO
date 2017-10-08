//Program do konkatenacji n łańcuchów
//ograniczeniem jest stała SIZE_MAX która pilnuje aby nie zapełnić pamięci operacyjnej

#include "con.h"

int main(int argc, const char** argv)
{
    char* new_str = NULL;

    if(validate(argc, argv)) abort();
    init(&new_str);
    concatanate(&new_str, argv, argc);

    return 0;
}
