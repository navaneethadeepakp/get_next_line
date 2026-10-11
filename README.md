# Get Next Line (GNL)

A custom C utility function designed to read and extract a single line from a file descriptor. This project demonstrates robust memory management, low-level file I/O operations, and the practical application of static variables for state preservation.

## Technical Highlights

*   **State Preservation:** Utilizes static variables to cache leftover data between function calls, ensuring no characters are lost during sequential reads across multiple buffer cycles.
*   **Memory Safety:** Strictly manages dynamic memory allocation (`malloc`, `free`) to guarantee zero memory leaks, even when reading massive files or encountering unexpected EOFs.
*   **Dynamic Buffer Handling:** Adapts dynamically to any `BUFFER_SIZE` defined at compile time, cleanly processing arbitrary chunk sizes.
*   **Concurrent Multi-FD Support (Bonus):** Expands the architecture using an array of static pointers to read from multiple file descriptors simultaneously without data stream contamination.

## Return Value:

Returns the read line (including the \n character).

Returns NULL if there is nothing left to read or an error occurs.

## Compilation Example:

Compile alongside your project files, defining the buffer size at runtime:

``` bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=50 get_next_line.c get_next_line_utils.c main.c
```
