# include <regex.h>
# include <stdio.h>

int main() {
    regex_t reg1;

    int result;

    char user_input[200];

    result = regcomp(&reg1, "^([a-zA-Z0-9_\.-]+)@([a-zA-Z0-9_\.-]+)\.([a-zA-Z]{2,5})$", REG_EXTENDED);

    if (result == 0) {
        printf("Regex compiled successfully.\n");
    } else {
        printf("Could not compile Regex!\n");
        return 0;
    }

    scanf("%s", user_input);

    result = regexec(&reg1, user_input, 0, NULL, 0);

    if (result != 0) {
        printf("Failed to find match.\n");
    }
    else {
        printf("Valid email found!\n");
    }
}