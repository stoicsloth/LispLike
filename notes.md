# What is the switch statement, and how does it work?
The switch statement compares on expression against other cases, when a case matching the expression is found, the statements following the successful case are executed. 

```C
switch (x)
{
    case 0:
        puts("x is 0");
        break;
    case 1: 
        puts("x is 1");
        break;
    default:
        puts("x is something else");
        break;
}
```

# What is the break keyword, and what does it do?
The break statement is used to terminate a while, do, for, or switch statement. It terminates only the innermost loop or switch statement that it is in. 

# What is the continue keyword and what does it do?
The continue keyword terminates an iteration of a loop and the program begins the next iteration. 
 
# What does the typdef keyword do exactly?
Used to create new names for data types. Creating a new name for the type does not cause the old name to cease to exist. 

```C
typedef unsigned char byte_type;
typedef double real_number_type;
```

You can use typedef to make a new name for the type while defining the type, as in structs:

```C
typedef struct fish
{
    float weight;
    float length;
} fish_type; 

To make a type definition of an array, the type of the element must be provided along with the number of elements:

```C
typedef char array_of_bytes [5];
array_of_bites five_bytes = {0, 1, 2, 3, 4};
```
## fputs
Writes every character from the null-terminated string *str* to the output stream *stream*, as if by repeatedly executing fputc. The terminating null character from str is not written. 

Parameters:
    - str : null-terminated character string to be written
    - stream : output stream

The related function *puts* appends a newline character to the output, while *fputs* writes the string unmodified. 

## fgets
Reads at most ```count - 1``` characters from the given file stream and stores them in the character array pointed to by str. Parsing stops if end-of-file occurs or a newline character is found, in which case str will contain that newline character. 

Parameters:
    - str : pointer to an element of a char array
    - count : maximum number of characters to write (typically the length of str)
    - stream : file stream to read the data from)
