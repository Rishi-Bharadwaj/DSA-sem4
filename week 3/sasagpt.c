#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int charIndex[256]; // Assuming ASCII characters, use a larger array if using extended character set
    memset(charIndex, -1, sizeof(charIndex)); // Initialize array with -1

    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < n; end++) {
        if (charIndex[s[end]] != -1 && charIndex[s[end]] >= start) {
            // If the character is repeated and its last occurrence is within the current substring
            start = charIndex[s[end]] + 1; // Move the start index to the next position after the repeated character
        }

        charIndex[s[end]] = end; // Update the index of the current character
        int currentLength = end - start + 1; // Length of the current substring

        maxLength = (currentLength > maxLength) ? currentLength : maxLength; // Update the maximum length
    }

    return maxLength;
}

int main() {
    char inputString[] = "nomlikespeanutbutter";
    int result = lengthOfLongestSubstring(inputString);
    printf("Maximal substring length without repeating characters: %d\n", result);

    return 0;
}
