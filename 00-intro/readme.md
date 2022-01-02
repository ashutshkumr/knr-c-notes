### 00 - Introduction

- A C program is usually written in a text file with `.c` file format and compiled like so (on unix-based OSes):
    ```sh
    # `cc` refers to the default C compiler on a given platform (e.g. gcc)
    cc source.c
    # previous step will produce an executable `a.out` by default
    # which can be run like so:
    ./a.out
    ```

- Upon executing `cc`, a C program goes through following transformations:
    * preprocessor - replaces all directives / macros and outputs a `.i` file
    * compiler - converts C program to assembly code and outputs a `.s` file
    * assembler - converts assembly code to machine code (`.o` file, a relocatable object program)
    * linker - combines all available `.o` files into a single executable

- Every C program consists of `functions` and `variables`. A function contains
    * `statements` that specify the computing operation to be done
    * `variables` that store the values used during computation

- `main` is a special function and must be present in every C program, as that's where any execution starts

- Comments are surrounded by `/*` and `*/`, and ignored by pre-processor / compiler.

- To use functions / variables defined elsewhere, one needs to use `#include <name-of-header-file.h>` in the beginning of the program
    ```c
    /* Before even compilation starts, pre-processor replaces this line
        with actual contents of `stdio.h` (which provides functions for standard I/O operations);
        hence, it's called a pre-processor directive and not a statement
    */
    #include <stdio.h>

    int main()
    {
        /* defined elsewhere and can only be used after including stdio.h */
        printf("hello\n");
    }
    ```

- All variables must be declared before they can be used and can be of following basic types:
    * char
    * int
    * float
    * double

- All statements are terminated by a semicolon

- Body of `while` loop executed as long as the condition in parenthesis holds true
    * Braces are required around the body if it consists of more than one statements

- Having only one statement per line is considered good practice

- `printf` is not part of C language, it's just one of many functions provided by C standard library
    * Each `%` in first argument to printf should match each of the remaining arguments (in most cases)
    * `%d` - integer
    * `%6d` - prints integer right justified (at least 6 char width)
    * `%-6d` - prints integer left justified (at least 6 char width)
    * `%ld` - long
    * `%x` - hexadecimal
    * `%o` - octal
    * `%f` - float
    * `%6.2f` - prints float right justified with two digits after decimal (at least 6 char width)
    * `%lf` - double
    * `%c` - char
    * `%s` - char string
    * `%%` - print % itself

- `for` loop is a generalization of `while` loop and consists of either or all of following in parentheses:
    * initialization - executed only once, before the loop body executed
    * condition - checked every time before loop body is executed
    * increment - executed every time after loop body is executed (till last line)
    * if break is encountered, increment is not executed

- `for` and `while` loops need not have a body and may be terminated using a semicolon.

- Symbolic constants are defined using `#define NAME value`

- Text input / output is dealt with as stream of characters in standard library
    * `getchar` reads the next input character and returns it as a value
    * `putchar` prints a character
    * `EOF` is a macro defined in stdio.h indicating end-of-file (a value which is not a `char`), hence whenever comparing variable to EOF, make sure it's defined as `int` instead of `char`

- In C, assignment is an expression as well. Hence, following is valid: `int a = b = 5;`

- `++i` historically was deemed more efficient than `i++` or `i += 1` but not anymore

- Compiler usually doesn't throw warning when `=` is used in place of `==`

- The condition containing multiple `||` or `&&` operator stops evaluation midway, as soon as the truth or falsehood is known (e.g. the whole condition won't necessarily be evaluated)

- `Definition` refers to the place where the variable is created or assigned storage; `declaration` refers to places where the nature of the variable is stated but no storage is allocated.

- A function is a convenient way to encapsulate some computation.
    * It's declaration (aka function prototype) implies the function signature without body. We can have multiple of these.
    * It's definition implies the function signature with body. Can be defined only once.
    * While definition can appear anywhere in program, declaration must appear before the function is actually called.
    * Declaration must match the definition.
    * The variables in parentheses (in function signature) are called formal arguments or parameters
    * When function is called, then whatever is enclosed within parentheses are called actual arguments (or just arguments)
    * Parameter names are optional in function prototype.
    * Arguments are always passed by value (unless passing an array name - which is a pointer to first element).

- `main` returns 0 to indicate success, and non-zero to indicate failure.

- A function that doesn't return anything should have a return type `void`

- A function that doesn't accept any arguments should use `void` in parentheses (to be compatible with old-style C)

- `\0` is a sequence of char (array of char) indicates end-of-string in C

- `automatic variables` are variables that are defined inside a given function, accessible only inside a given function, and are created (and destroyed) upon every function call

- `external variables` or `global variables` are defined exactly once, outside any of the function and must be declared as `extern` before being used inside a function.

    ```c
    int global_var;

    int sum()
    {
        extern int global_var;
        global_var = 500;
    }
    ```

    This is not mandatory if the global variable has been defined in the same source file before being referenced anywhere in the function.

* Conventionally, this is how braces are used
    ```c
    /* braces surrounding function body are usually on its own line */
    int main()
    {
        int i;
        /* opening brace surrounding loop / if-else body isn't provided on its own line */
        for (i = 0; i < 10; ++i) {
            if (i == 5) {
                break
            }
        }
    }
    ```