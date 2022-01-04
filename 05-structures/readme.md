### 05 - Structures

- Structure is a collection of one or more variables (of different types)

- Structures may be copied (when assigned or passed as function arguments) but not compared

- Various methods of declaration and initialization:
    ```c
    /* with struct tag */
    struct point {
        int x;
        int y;
    };
    /* struct init */
    struct point p1 = {x: 5, y: 6};
    /* automatic struct init */
    struct point p1a = {5, 6};
    /* init struct members later */
    struct point p2;
    p2.x = 100;
    p2.y = 200;
    /* without struct tag */
    struct {
        int x;
        int y;
    } p3 = {x: 500, y: 600};

    p2 = p1; /* valid */
    p3 = p1; /* invalid */
    ```

- Pointers to struct
    ```c
    struct point *p;
    (*p).x == p->x; /* true */
    ```

- A `sizeof` can not be used in a `#if` line, because the preprocessor does not parse type names

- Don't assume that the size of a structure is the sum of the sizes of its members.
    * Because of alignment requirements for different objects, there may be unnamed `holes` in a structure
    ```c
    /* might require 8 bytes instead of 5 bytes */
    struct {
        char c;
        int i;
    };
    ```

- It is illegal for a structure to contain an instance of itself
    ```c
    struct node {
        struct node *next; /* valid */
        struct node nextt; /* invalid */
    };
    ```

- `malloc` returns a pointer to object that meets allocation alignment requirements
    * Returns a pointer to `void`

- Use `typedef` for aliasing data types
    * Used to parameterize a program against portability problems (e.g. `size_t`)
    * Used to provide better documentation

    ```c
    typedef struct point {
        int x;
        int y;
    } Point;
    Point pt; /* equivalent to `struct point pt` */

    typedef struct point *PointPtr;
    PointPtr ptr; /* equivalent to `struct point *ptr` */
    ```

- `union` is a variable that may hold (at different times) objects of different types and sizes
    * compiler keeps track of size and alignment requirements (based on context of its usage)
    * size of a union variable is large enough to hold the underlying type with largest size
    * it is programmer's responsibility to keep track of which type is currently in use
    * it may only be initialized with a value of first member
    * apart from that, behaves similar to struct in all aspects

    ```c
    union number {
        int i;
        double d;
    };

    union number v[2];
    v[0].i = 50;
    v[1].d = 50.50;
    ```

- `bit field` is a set of adjacent bits within a single implementation-defined storage unit that we will call a `word`
    * fields may be declared only using `int`
    * `&` cannot be applied to them
    * hard to write portable code when this is used extensively
    * usually used to store flags, values larger than 1 bit and less than a byte and replacement for some bitwise operations

    ```c
    struct flag {
        unsigned a: 1;
        unsigned b: 3;
        unsigned c: 12;
    };

    struct flag f;
    f.a = 1;
    f.b = 7;
    f.c = 100;
    ```