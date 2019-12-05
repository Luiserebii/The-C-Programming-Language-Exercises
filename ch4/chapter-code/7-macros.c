//Defining a macro for an infinite loop
#define forever for (;;) 

//max macro that takes arguments
//NOTE: This can be dangerous, arguments passed that give side-effects can double
#define max(A, B) ((A) > (B) ? (A) : (B)) 

//This is similarly dangerous, and not really good
#define square(x) x * x

//To undefine a macro, use #undef
#define meme 1
#undef meme

//# can be used before a macro parameter name to transform the content into a quoted string
//  As an invocation example: 
//    dprint(x/y);   --- expands into --->   printf("x/y" " = %g\n");
//  where the strings are concatenated by the compiler.
#define dprint(expr) printf(#expr " = %g\n", expr)

//## can be used to concatenate two macro arguments
//  As an invocation example:
//    paste(name, 1)   --- expands into --->   name1
#define paste(front, back) front ## back

//Conditional inclusion is possible using preprocessor control statements
// 
//  One way is header-related:
//  
//    #if !defined(MEME)
//    #define MEME
//
//    #endif
//
//  Another sequence might test a macro variable on what to include:
//
//    #if SYSTEM == SYSV
//        #define HDR "sysv.h"
//    #elif SYSTEM == BSD
//        #define HDR "bsd.h"
//    #elif SYSTEM == MSDOS
//        #define HDR "msdos.h"
//    #else
//        #define HDR "default.h"
//    #endif
//    #include HDR
