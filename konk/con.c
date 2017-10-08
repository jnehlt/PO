
#include "con.h"

int validate(int argc, const char** argv)
{
    if(argv == NULL) abort();   //in case of argv adress error
    if(argc < 3)
    {
        if(argc == 2)
        {
            printf("There is nothing to concatanate\n");
            printf("%s\n\n", argv[1]);
            return 0;
        }
        printf("Insufficient number of arguments\n");
        abort();
    }
    
    return 0;
}

void init(char** new_str)
{
    if((*new_str = (char*)malloc(1)) == NULL)
    {
        printf("Problem with allocation\n");
        free(*new_str);
        abort();
    }
    **new_str = '\0';
}

void concatanate(char** new_str, const char** argv, const int argc)
{
    const unsigned SIZE_MAX = 5000; // max chars to concatanate is SIZE_MAX-1
    unsigned i = 1, size = 1;

    for(; i < argc; ++i)
    {
        if((size += strlen(argv[i])) > SIZE_MAX)
        {
            printf("List of arguments is too long\n");
            free(*new_str);
            abort();
        }

        if((*new_str = (char*)realloc(*new_str, size)) == NULL)
        {
            printf("Reallocation error\n");
            free(*new_str);
            abort();
        }
        strcat(*new_str, argv[i]);
    }

    printf("Done.\nCreated sentence have %u character(s)\n%s\n\n", size-1, *new_str);
    free(*new_str);
}
