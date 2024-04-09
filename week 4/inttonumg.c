#include <stdio.h>
#include <string.h>

char *units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char *thousands[] = {"", "thousand", "million", "billion", "trillion"};

// Function to convert numbers less than 1000 to words
void convert_less_than_thousand(int num, char *result) {
    if (num == 0) {
        return;
    } else if (num < 10) {
        strcat(result, units[num]);
    } else if (num < 20) {
        strcat(result, teens[num - 10]);
    } else if (num < 100) {
        strcat(result, tens[num / 10]);
        strcat(result, " ");
        convert_less_than_thousand(num % 10, result);
    } else {
        strcat(result, units[num / 100]);
        strcat(result, " hundred ");
        convert_less_than_thousand(num % 100, result);
    }
}

// Function to convert number to words
void number_to_words(long long n, char *result) {
    if (n == 0) {
        strcpy(result, "zero");
        return;
    }

    int i = 0;
    while (n > 0) {
        if (n % 1000 != 0) {
            char temp[1000];
            temp[0] = '\0';
            convert_less_than_thousand(n % 1000, temp);
            strcat(temp, thousands[i]);
            strcat(temp, " ");
            strcat(temp, result);
            strcpy(result, temp);
        }
        n /= 1000;
        i++;
    }
}

int main() {
    long long n;
    printf("Enter a number: ");
    scanf("%lld", &n);
    
    char result[1000];
    result[0] = '\0';

    number_to_words(n, result);

    printf("Output: %s\n", result);

    return 0;
}
