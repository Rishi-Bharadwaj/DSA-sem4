#include <stdio.h>
#include <string.h>

int expandAroundCenter(char *s, int left, int right) {
    int n = strlen(s);

    // Expand around the center while the characters at left and right are equal
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }

    // Return the length of the palindrome substring
    return right - left - 1;
}

void longestPalindromeSubstring(char *s) {
    int n = strlen(s);
    int start = 0; // Starting index of the longest palindromic substring
    int maxLength = 1; // Length of the longest palindromic substring

    for (int i = 0; i < n; i++) {
        // Check for odd length palindromes
        int len1 = expandAroundCenter(s, i, i);
        // Check for even length palindromes
        int len2 = expandAroundCenter(s, i, i + 1);

        // Choose the longer palindrome length
        int len = len1 > len2 ? len1 : len2;

        // Update start index and maxLength if a longer palindrome is found
        if (len > maxLength) {
            start = i - (len - 1) / 2;
            maxLength = len;
        }
    }

    // Print the longest palindromic substring
    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLength; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

int main() {
    char input[100]; // Assuming a maximum length for the input string
    printf("Enter a string: ");
    scanf("%s", input);

    longestPalindromeSubstring(input);

    return 0;
}
