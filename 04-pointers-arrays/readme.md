### 03 - Pointers and Arrays

- A pointer is a 32-bit variable that contains address of a variable

- If pointer is advanced by 1, it will actually advance as many bytes as held by underlying data structure

- `&` (address-of operator) cannot be applied to constant expressions, constants and register variables

- `*` (indirection or dereferencing operator) accesses the object the pointer points to

- The syntax of the declaration for a variable mimics the syntax of expressions in which the variable might appear

- A void pointer cannot be dereferenced

- Use `char` pointer instead of `void` pointer as generic pointer

- Name of an array is pointer to its first element
    * array name is not a variable, hence its underlying address cannot be changed
    * pointer pointing to string literal may not modify its contents
    ```c
    int a = 5;

    char *s = "hello";
    s = (char *) &a;        /* allowed */
    s[3] = 'v';             /* not allowed */

    char s[] = "hello";
    s = (char *) &a;        /* not allowed */
    s[3] = 'v';             /* allowed */
    ```

- Accessing arrays using pointer arithmetic is usually faster than accessing array index

- Accessing arrays / pointers using negative index is not illegal

- Function parameters are actually never an array, rather just a pointer
    ```c
    /* both are equivalent, while latter is more preferred */
    int strlen(char s[]);
    int strlen(char* s);
    ```

- It is guaranteed that 0 is never a valid address
    * Symbolic constant `NULL` has a value 0

- Valid operations on pointers:
    * pointer + integer
    * pointer - integer
    * pointer - pointer (use `ptrdiff_t` as type for safely hold large values)
    * pointer = integer value
    * pointer = pointer
    * `<`, `<=`, `>`, `>=`, `==`, `!=` (among pointers pointing to same elements of array)
    * `==` and `!=` works against `NULL`
    * Behavior is undefined for comparison between pointers that do not point to elements of same array
    * Assign pointer of one type to pointer of another type without cast (only supported for `void *`)

- `sizeof` returns a value of type `size_t`

- Useful functions in `string.h`
    * `strlen`
    * `strcmp`, `strncmp`
    * `strcpy`, `strncpy`
    * `strcat`, `strncat`

- In multidimensional array, right-most index refers to column (or varies fastest)
    * array initialization:
    ```c
    /* number of cols is necessary */
    int arr[][2] = {
        {4, 5},
        {6, 7},
        {8, 9}
    }
    ```
    * when passed to a function, function parameter must indicate column size; e.g. `void func(int arr[][10]) {}` or `void func(int (*arr)[10]) {}`
    * in general, only first dimension is free, rest of them needs to be specified
    * careful:
    ```c
    /* pointer to array of 10 integers */
    void func(int (*arr)[10]) {}
    /* array of 10 pointer to integers (since precedence of [] is higher than *) */
    void func(int *arr[10]) {}
    ```

- Array of pointers vs multidimensional arrays - former allows unequal column sizes

- Command line arguments:
    * `argc` is the first argument to main - number of arguments passed (including program's name)
    * `argv` is the second argument to main - array of character pointers (argv[0] is program's name)
    * argv[argc] is guaranteed to be a `NULL`

- Functions are not variables, but we can define pointers to them
    * careful:
    ```c
    /* func returns pointer to int */
    int *func();
    /* func is a pointer to function */
    int (*func)();
    ```