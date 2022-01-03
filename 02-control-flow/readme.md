### 02 - Control Flow

- A statement is followed by a semicolon, while a block (compound statement) is surrounded by braces

- Variables can also be declared inside block

- `if` tests expression to be zero (false) or non-zero (true)

- Always use braces for `if` / `else` blocks (to avoid confusion when writing nested `if`s)

- switch-case
    * Expression used in cases must be a constant expression
    * Each case must end with a `break` if execution of remaining cases after the match has been found is not desired
    * `default` is optional

- Use comma operator (`,`) in for loop for multiple initialization and increments
    * Use it sparingly; mostly used in macros to have multiple expressions in one line
    * Use is also recommended when the two or more expressions are very much related

- `for` and `while` loop test termination condition first, whereas `do-while` loop tests termination condition after executing the body

- Use `break` for early exit (from loops); It only exits from inner-most loop / switch !

- Use `continue` to skip remaining statements in the loop body for current iteration and execute next iteration

- `goto` is infinitely abusable; a good use is to break out of nested loops, all at once or in some occasions while writing cleanup code.
    * The scope of goto is limited to a function (entire function)