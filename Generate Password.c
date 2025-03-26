#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle an array using the Fisher-Yates algorithm
void fisher_yates(char *vetor, int tamanho) {
    int i, j;
    char temp;
    // Loop from the last element to the second element
    for (i = tamanho - 1; i > 0; i--) {
        // Generate a random index between 0 and i
        j = rand() % (i + 1);
        // Swap the elements at indices i and j
        temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

int main() {

    // Arrays containing possible characters for the password
    char letras_maiusculas[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Uppercase letters
    char letras_minusculas[] = "abcdefghijklmnopqrstuvwxyz"; // Lowercase letters
    char numero[] = "0123456789";                            // Numbers
    char caracteres_especiais[] = "!@#$%^&*()";              // Special characters

    // Initialize the random number generator with the current time
    srand(time(NULL));

    // Select one random character from each category
    char Letra = letras_maiusculas[rand() % 26]; // Random uppercase letter
    char letra = letras_minusculas[rand() % 26]; // Random lowercase letter
    char numeros = numero[rand() % 10];          // Random number
    char especiais = caracteres_especiais[rand() % 10]; // Random special character

    // Create a password array with a fixed size of 16
    char senha[16] = {Letra, letra, numeros, especiais};

    // Ask the user for the desired password length
    printf("Digite o tamanho da sua senha (max 16):\n"); // "Enter the length of your password (max 16):"
    int tamanho;
    scanf("%d", &tamanho);

    // Validate the password length
    if (tamanho > 16 || tamanho < 4) {
        printf("Erro: O tamanho da senha deve ser entre 4 e 16.\n"); // "Error: Password length must be between 4 and 16."
        return 1; // Exit the program with an error code
    }

    // Fill the rest of the password with random characters
    for (int i = 4; i < tamanho; i++) {
        int tipo = rand() % 4; // Randomly choose the type of character
        if (tipo == 0) {
            senha[i] = letras_maiusculas[rand() % 26]; // Add a random uppercase letter
        } else if (tipo == 1) {
            senha[i] = letras_minusculas[rand() % 26]; // Add a random lowercase letter
        } else if (tipo == 2) {
            senha[i] = numero[rand() % 10];           // Add a random number
        } else {
            senha[i] = caracteres_especiais[rand() % 10]; // Add a random special character
        }
    }

    // Shuffle the password to make it more random
    fisher_yates(senha, tamanho);

    // Print the generated password
    printf("Sua senha e: "); // "Your password is: "
    for (int i = 0; i < tamanho; i++) {
        printf("%c", senha[i]); // Print each character of the password
    }
    printf("\n");

    return 0; // Exit the program successfully
}