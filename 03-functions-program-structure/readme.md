### 03 - Functions and Program Structure

- Communication between functions is either via arguments or return value (an through external variables)

- If the return type of function is omitted, int is assumed

- If there are no function parameters, the function may be called with any number of arguments, unless function signature contains `void` as a parameter.
    * e.g. `int get_time(void) {}`

- Calling function is free to ignore the returned value

- If a function returns nothing or a value of incorrect return type, then the calling function will get the garbage value (it's not a compilation error)

- If a function declaration does not exist, the declaration is automatically assumed based on the context it's used in (when the actual definition is defined in some other library) - compiler doesn't necessarily throw an error for such mismatches

- A function cannot be defined inside another function

- Common declarations should be kept in header files

- External `static` variables are only visible to the source file it is declared / defined in (i.e. same translation unit)
    * Hence, two different source files (i.e. different translation unit) may use same name for external static variables
    * `static` keyword can be applied to both variables and functions

- Internal `static` variables are internal to functions but are never destroyed until program stop executing (i.e. they retain their values across function calls)

- `register` variables advice compilers to store them in registers (for faster access / execution), but compiler may ignore it
    * Can only be applied to automatic variables and function parameters
    * It is not possible to take address of register variables (regardless of whether they are stored in register or not)

- Scope, visibility and life of a variables declared in block is limited to that block - i.e. it is possible to have two variables with same name in same function, as long as they belong to separate unrelated blocks

- Names of automatic variables and function parameters will hide external variables of the same name

- In the absence of explicit initialization, external and static variables are guaranteed to be initialized to zero; automatic and register variables have undefined (i.e., garbage) initial values.

- External and static variables must always be initialized with a constant expression, while automatic variables may be initialized using any expression

- Array initialization
    ```c
    /* length is automatically calculated */
    int a[] = {1, 2, 3, 4};

    /* these two are same */
    char c_arr[] = {'h', 'e', 'y', '\0'};
    char c_str[] = "hey";
    ```

- Recursion - a function may call itself
    * Each invocation gets a fresh set of automatic variables
    * Expensive in terms of storage and execution time
    * Expressive - compact code
    * Usually used with recursive data structures - e.g. tree

- Useful pre-processor directives
    ```c
    /* include standard headers */
    #include <stdio.h>
    /* include local header files */
    #include "file.h"
    /* define macro replacement */
    #define MAX 50
    /* define multiline macro replacement */
    #define MULTI a + b \
        c + d
    /* define macro with args - use parenthesis extensively to avoid mess up due to operator precedence */
    #define sum(a, b) ((a) + (b))
    /* define macro with string literal substitution */
    #define log(expr) printf(#expr " = %g", expr)
    log(x/y); /* will result in printf("x/y" " = %g", x/y); */
    /* define macro with concatenated args */
    #define paste(x, y) x ## y
    paste(name, 1) /* will create a token name1 */
    /* un-define macro */
    #undef MAX
    /* include contents of header only once */
    #if !defined(HDR_NAME)
    #define HDR_NAME
    /* contents of hdr_name.h go here */
    #endif
    /* specialized form of including header contents only once */
    #ifndef HDR_NAME
    #define HDR_NAME
    /* contents of hdr_name.h go here */
    #endif
    /* if / else */
    #if SYSTEM == SYSV
        #define HDR "sysv.h"
    #elif SYSTEM == BSD
        #define HDR "bsd.h"
    #elif SYSTEM == MSDOS
        #define HDR "msdos.h"
    #else
        #define HDR "default.h"
    #endif
    #include HDR
    ```