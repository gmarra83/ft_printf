#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ft_printf.h" // Include il tuo ft_printf

#define BUFFER_SIZE 1024

// Funzione helper per confrontare ft_printf e printf
int test_printf(const char *format, ...)
{
    char expected[BUFFER_SIZE];
    char result[BUFFER_SIZE];
    va_list args1, args2;

    va_start(args1, format);
    va_start(args2, format);

    // Stampa l'output atteso
    int expected_len = vsnprintf(expected, BUFFER_SIZE, format, args1);

    // Reindirizza l'output di ft_printf su un buffer
    int pipefd[2];
    pipe(pipefd);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);

    int result_len = ft_printf(format, args2);
    fflush(stdout);
    read(pipefd[0], result, BUFFER_SIZE);
    close(pipefd[0]);

    va_end(args1);
    va_end(args2);

    // Confronta i risultati
    if (expected_len != result_len || strcmp(expected, result) != 0)
    {
        printf("Test failed for format: \"%s\"\n", format);
        printf("Expected: \"%s\" (len: %d)\n", expected, expected_len);
        printf("Result:   \"%s\" (len: %d)\n", result, result_len);
        return (1);
    }
    return (0);
}

// Test Suite
void run_tests()
{
    printf("Running tests for %%s...\n");

    // Test base senza flag
    test_printf("%s", "Hello, world!");

    // Test con flag '-'
    test_printf("%-20s", "Hello");

    // Test con flag '0' (non ha effetto con %s)
    test_printf("%020s", "Hello");

    // Test con larghezza
    test_printf("%10s", "Hello");

    // Test con precisione
    test_printf("%.5s", "Hello, world!");

    // Test con larghezza e precisione
    test_printf("%10.5s", "Hello, world!");

    // Test con flag '-', larghezza e precisione
    test_printf("%-10.5s", "Hello, world!");

    // Test con stringa vuota
    test_printf("%10s", "");

    // Test con puntatore a NULL
    test_printf("%s", NULL);

    // Test con larghezza e NULL
    test_printf("%10s", NULL);

    // Test con precisione e NULL
    test_printf("%.5s", NULL);

    // Test con flag '-', larghezza, precisione e NULL
    test_printf("%-10.5s", NULL);

    printf("All tests for %%s completed.\n");
}

int main()
{
    run_tests();
    return 0;
}
