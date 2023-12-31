#include "monty.h"

/**
 * err - Prints the appropriate error message based on error codes
 * @error_code: The error codes are the following:
 * (1) => More than one file or no file given to the program.
 * (2) => Provided file is unreadable.
 * (3) => Provided file contains invalid instruction.
 * (4) => Program  un able to malloc more memory.
 * (5) => Parameter passed to the instruction "push" is not an int
 * (6) => The stack it empty for pint
 * (7) => The stack it empty for pop
 * (8) => The stack is too short for operations
 */
void err(int error_code, ...)
{
    va_list ag;
    char *op;
    int l_num;

    va_start(ag, error_code);
    switch (error_code)
    {
    case 1:
        fprintf(stderr, "USAGE: monty file\n");
        break;
    case 2:
        fprintf(stderr, "Error: Can't open file %s\n",
                va_arg(ag, char *));
        break;
    case 3:
        l_num = va_arg(ag, int);
        op = va_arg(ag, char *);
        fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
        break;
    case 4:
        fprintf(stderr, "Error: malloc failed\n");
        break;
    case 5:
        fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
        break;
    default:
        break;
    }
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * more_err - handles errors
 * @error_code: The error codes are the following:
 * (6) => The stack it empty for the pint
 * (7) => The stack it empty for the pop
 * (8) => The stack is too short for operation
 * (9) => Division by zero
 */
void more_err(int error_code, ...)
{
    va_list ag;
    char *op;
    int l_num;

    va_start(ag, error_code);
    switch (error_code)
    {
    case 6:
        fprintf(stderr, "L%d: can't pint, stack empty\n",
                va_arg(ag, int));
        break;
    case 7:
        fprintf(stderr, "L%d: can't pop an empty stack\n",
                va_arg(ag, int));
        break;
    case 8:
        l_num = va_arg(ag, unsigned int);
        op = va_arg(ag, char *);
        fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
        break;
    case 9:
        fprintf(stderr, "L%d: division by zero\n",
                va_arg(ag, unsigned int));
        break;
    default:
        break;
    }
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors
 * @error_code: The error codes are the following:
 * (10) ~> The number inside node is out side ASCII bounds
 * (11) ~> The stack is empty
 */
void string_err(int error_code, ...)
{
    va_list ag;
    int l_num;

    va_start(ag, error_code);
    l_num = va_arg(ag, int);
    switch (error_code)
    {
    case 10:
        fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
        break;
    case 11:
        fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
        break;
    default:
        break;
    }
    free_nodes();
    exit(EXIT_FAILURE);
}