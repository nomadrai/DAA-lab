#include <stdio.h>
#include <string.h>

void reverseBruteForce(char s[], int n)
{
    char result[n + 1];
    int i, j = 0;

    for(i = n - 1; i >= 0; i--)
    {
        result[j] = s[i];
        j++;
    }
    result[j] = '\0';

    printf("Reversed string (Brute Force): %s\n", result);
}

void reverseTwoPointers(char s[], int n)
{
    int left = 0;
    int right = n - 1;
    char temp;

    while(left < right)
    {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }

    printf("Reversed string (Two Pointers): %s\n", s);
}

int main()
{
    char s[100];

    printf("Enter a string: ");
    scanf("%s", s);

    int n = strlen(s);

    reverseBruteForce(s, n);
    reverseTwoPointers(s, n);

    return 0;
}
