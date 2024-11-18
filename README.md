<div align="center">

# 📜 ft_printf

Because `ft_putnbr()` and `ft_putstr()` Aren't Enough

</div>

Welcome to **ft_printf**! This project involves creating our own version of the versatile `printf()` function. Through this, we delve into variadic functions, formatted output, and memory management, gaining a strong foundation in custom C function implementation.

<div align="center">

## 🚀 How to Clone the Project

</div>

To clone this project, use the following command:

```bash
git clone git@github.com:SirAlabar/ft_printf.git
```

<div align="center">

## 📂 Project Structure

</div>

This project follows a standardized directory structure:
```
ft_printf/
├── Makefile          # Build configuration
├── libft/            # Custom C library with helper functions
├── src/              # Source files directory
│   ├── ft_printf.c   # Core printf implementation
│   ├── ft_format.c   # Format specifier handling
│   ├── ft_utils.c    # Helper functions
│   ├── bonus/        # Bonus features implementation
│   │   ├── ft_printf_bonus.c
│   │   ├── ft_format_bonus.c
│   │   └── ft_utils_bonus.c
│   └── main.c        # Main program file
└── include/          # Header files directory
    ├── ft_printf.h         # Main header file
    └── ft_printf_bonus.h   # Bonus features header
```

<div align="center">

### Key Components:

</div>

```c
// ft_printf.h
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

/* Main function */
int     ft_printf(const char *format, ...);

/* Format handling */
int     ft_format(const char *format, unsigned int *i, va_list args);

/* Output utilities */
int     ft_putchar(char c);
int     ft_putstr(char *s);

/* Flag structure for bonus features */
typedef struct s_flags
{
    int     width;
    int     precision;
    int     minus;
    int     zero;
    int     hash;
    int     space;
    int     plus;
    char    type;
}   t_flags;

#endif
```

The project follows the 42 School's Norm, maintaining clean and standardized code. Each file contains specific functionality:

* `ft_printf.c`: Main function implementation and variadic argument handling
* `ft_format.c`: Handles different format specifiers (%c, %s, %p, %d, %i, %u, %x, %X)
* `ft_putchar.c` & `ft_putstr.c`: Basic output utilities for characters and strings
* `Makefile`: Manages compilation with rules for all, clean, fclean, and re

This modular structure ensures easy maintenance and clear separation of concerns. 🗂️

You can find the full source code at [SirAlabar/ft_printf](https://github.com/SirAlabar/ft_printf).

<div align="center">

## 🔹 Supported Conversions

</div>

Our `ft_printf` function handles a variety of conversions to closely mimic the original `printf()` function:

* `%c` - Prints a single character
* `%s` - Prints a string
* `%p` - Prints a pointer address in hexadecimal format
* `%d` - Prints a decimal (base 10) integer
* `%i` - Prints an integer in base 10
* `%u` - Prints an unsigned decimal integer
* `%x` - Prints a number in lowercase hexadecimal format
* `%X` - Prints a number in uppercase hexadecimal format
* `%%` - Prints a literal `%` symbol

<div align="center">

## ⚙️ Project Fundamentals

</div>

This project helps to reinforce core C programming concepts:

* **Memory Management**: Managing memory carefully with `malloc` and `free` to prevent leaks and ensure efficient usage
* **Variadic Functions**: Using `va_start`, `va_arg`, and `va_end` to handle a variable number of arguments, a central feature in the `printf()` function
* **Format Parsing**: Breaking down format strings into individual conversions and options, keeping parsing efficient and organized
* **Code Modularity**: Splitting each conversion into dedicated functions to keep the codebase modular, readable, and easily maintainable

<div align="center">

## 🌟 Bonus Features

</div>

For an advanced version of `ft_printf`, we added bonus features that enhance the functionality and versatility of our function:

* **Flag Management**: Supports the `-`, `0`, `.`, and field width flags under all conversions, aligning with the flexibility of the original `printf()`
* **Additional Flags**: Implements support for the `#`, `+`, and space (` `) flags, providing even more control over formatting

**Note**: Bonus features are only evaluated if the mandatory part is fully functional.

<div align="center">

## 🛠️ Compilation and Usage

</div>

To compile and use `ft_printf`, run the following commands:

1. **Compile**:
```bash
make
```

2. **Clean up**:
* To remove object files: `make clean`
* To remove the library: `make fclean`
* To recompile: `make re`

<div align="center">

## 📝 Examples

</div>

Here are some examples of how to use ft_printf:

```c
#include "ft_printf.h"

int main(void)
{
    // Basic usage
    ft_printf("Hello, %s!\n", "world");
    
    // Numbers and hexadecimal
    ft_printf("Number: %d, Hex: %x\n", 42, 255);
    
    // Pointer address
    int *ptr = &(int){42};
    ft_printf("Pointer: %p\n", (void *)ptr);
    
    // Bonus features
    ft_printf("Formatted: %+10d\n", 42);    // Width and plus flag
    ft_printf("Hex with prefix: %#x\n", 255); // Hash flag
    
    return (0);
}
```

Output:
```
Hello, world!
Number: 42, Hex: ff
Pointer: 0x7fff5fbff8ac
Formatted:       +42
Hex with prefix: 0xff
```


---
Made with ❤️ by [SirAlabar](https://github.com/SirAlabar)

</div>
