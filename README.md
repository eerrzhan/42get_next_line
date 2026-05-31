# get_next_line

**get_next_line** is a project developed as part of the 42 curriculum. The goal of this project is to implement a function that reads a file descriptor, returning one line at a time. The project demonstrates the ability to handle file input, memory management, and efficient string manipulation. It mimics the functionality of the standard C library function `getline`.

---

## Features

- **Read from File Descriptors**: Reads one line at a time from a given file descriptor, whether it's from a file or standard input (stdin).
- **Handles Multiple File Descriptors**: Can handle multiple open file descriptors simultaneously.
- **Memory Management**: Efficient memory usage, ensuring no memory leaks by properly freeing allocated memory after use.
- **End-of-File Handling**: Correctly handles the end of file (EOF) and returns `NULL` when there is no more data to read.

---

## Technologies Used

- **Language**: C
- **File I/O**: `read` system call.
- **Memory Management**: Manual memory allocation and deallocation (using `malloc` and `free`).
- **Makefile**: For automated compilation.

---

## How to Use

### Prerequisites

- A Unix-based system (Linux or macOS).
- A C compiler (e.g., `gcc`).

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/get_next_line.git
   cd get_next_line
2. Compile the library
   ```bash
   make
3. Use `get_next_line` in your code:
   ```bash
   #include "get_next_line.h"
   
   int main(void)
   {
       int fd = open("your_file.txt", O_RDONLY);  // Open your file
       char *line;
    
       while (get_next_line(fd, &line) > 0) {
         printf("%s\n", line);
         free(line);  // Don't forget to free the allocated memory
       }
       close(fd);  // Always close the file descriptor
       return (0);
   }

4. To compile your program with the `get_next_line` implementation:
   ```bash
   gcc -Wall -Wextra -Werror main.c get_next_line.a -o your_program

---

## How It Works

1. **Reading Line-by-Line**: `get_next_line` reads from the provided file descriptor and returns one line at a time. The line is dynamically allocated and must be freed by the caller.
2. **Buffer Management**: The function reads data into a static buffer, accumulating characters until a newline (`\n`) is encountered or the end of the file is reached.
3. **End-of-File**: The function returns `0` when the end of the file is reached and returns `NULL` when there is no more data to read.
4. **Multiple File Descriptors**: The function can be called multiple times for different file descriptors, with each call handling its own buffer.

---

## Project Rules

- Reimplement `get_next_line` using only the allowed C library functions.
- Handle memory allocation efficiently and free allocated memory after each line is processed.
- The function should work on multiple file descriptors simultaneously.
- Follow 42's Norminette coding standards.
- Properly handle edge cases like empty lines, long lines, and reading from stdin.

---

## License

This project is for educational purposes under the 42 Network. Redistribution is prohibited without prior authorization.

