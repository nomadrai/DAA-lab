#include <stdio.h>

void twoSumBruteForce(int numbers[], int n, int target)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(numbers[i] + numbers[j] == target)
            {
                printf("Brute Force Output: [%d, %d]\n", i + 1, j + 1);
                return;
            }
        }
    }

    printf("Brute Force Output: No pair found\n");
}

void twoSumTwoPointers(int numbers[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while(left < right)
    {
        int sum = numbers[left] + numbers[right];

        if(sum == target)
        {
            printf("Two Pointers Output: [%d, %d]\n", left + 1, right + 1);
            return;
        }
        else if(sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    printf("Two Pointers Output: No pair found\n");
}

int main()
{
    int n, i, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter sorted elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    twoSumBruteForce(numbers, n, target);
    twoSumTwoPointers(numbers, n, target);

    return 0;
}
