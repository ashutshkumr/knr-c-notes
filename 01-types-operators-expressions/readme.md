### 01 - Types, Operators and Expressions

- Identifier / variable names
    * First character must be an alphabetical letter or `_`
    * Remaining characters must be an alphanumeric letter or `_`
    * Names starting with `_` are usually reserved for use in library routines
    * Convention is to use lower case separated by `_` for variable names
    * Convention is to use upper case separated by `_` for constants
    * Convention is to use short names for local variables and long names for external variables
    * Keywords can't be used as names
    * Uniqueness is guaranteed for 31 chars in internal names and 6 chars in external names

- Qualifiers - can be applied to basic data types
    * long int - at least 32 bits and no shorter than int
    * short int - at least 16 bits and no longer than int
    * signed int / char
    * unsigned int / char
    * long double
    * `limits.h` and `float.h` define limits
    * `const` - suggests that value won't be changed, but compiler may not raise error if change is actually attempted

- Constants
    * int - 1234
    * octal - 01234
    * hex - 0x1234
    * long int - 1234L or 1234l
    * unsigned long int - 1234UL
    * double - 123.4
    * float - 123.4F or 123.4f
    * char - 'A' or '\101' (octal for 65) or '\x41' (hex for 65)
    * string - "hello there" (internally ending in '\0')
    * concatenated string - "hello" "there" => "hello there"
    * enum - `enum boolean { TRUE FALSE }`, `enum months { JAN = 1, FEB, MAR, JUN = 6, JUL }`
        - By defaults, values are assigned starting with 0
        - Duplicate names not allowed
    * A constant expression only consists of constants and can be evaluated at compile time

- Declaration
    * Specifies a type, followed by a list of one or more names
    * A declaration may contain initialization as well
    * External / static variables are initialized to 0 by default
    * Automatic variables have undefined value when uninitialized

- Operators
    * `%` cannot be applied to float / double
    * Direction of truncation for `/` is machine-dependent for negative operands, as is the action of overflow / underflow
    * Numeric value of a relational or logical expression is either 0 (when false) or 1 (when true)

- Type Conversions
    * narrower to wider is automatically done
    * wider to narrower is worth a warning (as they lead to truncation or loss of information), but not illegal
    * `ctype.h` provides tests / conversions for character sets
    * C guarantees that standard printing chars will always be promoted to positive integer
    * Use `signed` / `unsigned` qualifiers for chars when non-character data needs to be stored
    * float is not automatically converted to double
    * Gotcha - `-1L < 1U` since `1U` will be promoted to `1L` but `-1L > 1UL` since `-1L` will be promoted to unsigned long.
    * In assignments, the value in RHS is converted to type of LHS
    * Use `cast` for explicit types; `(int) 4.56`

- Bitwise operators
    * `&` - bitwise AND (usually used to mask off bits)
    * `|` - bitwise OR (usually used to turn bits on)
    * `^` - bitwise exclusive OR
    * `~` - bitwise one's complement
    * `<<` - left shift (operand on left, non-negative shift count on right)
    * `>>` - right shift (operand on left, non-negative shift count on right)
    * Right shifting unsigned numbers always fills the vacated bits with 0
    * Right shifting signed numbers performs arithmetic shift (1 if negative, 0 if positive) - not always true

- Conditional expressions (ternary operator): `z = exp1 ? exp2 : exp3;` => `if (exp1) { z = exp2; } else { z = exp3; }`