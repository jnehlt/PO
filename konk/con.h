//con.h

#ifndef CON_H
#define CON_H
    
    extern int make_iso_compilers_happy;
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    void validate(int, const char**);
    void init(char**);
    void concatanate(char**, const char**, const int);

#endif
