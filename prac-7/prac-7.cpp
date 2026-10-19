#include <stdio.h>

int maxProfit(int prices[], int n)
{
    if(n <= 1)
        return 0;

    int minPrice = prices[0];
    int maxProfit = 0;
    int i;

    for(i = 1; i < n; i++)
    {
        if(prices[i] < minPrice)
            minPrice = prices[i];

        int currentProfit = prices[i] - minPrice;

        if(currentProfit > maxProfit)
            maxProfit = currentProfit;
    }

    return maxProfit;
}

int main()
{
    int n, i;

    printf("Enter number of days: ");
    scanf("%d", &n);

    int prices[n];

    printf("Enter stock prices:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &prices[i]);

    int profit = maxProfit(prices, n);

    printf("Maximum Profit: %d\n", profit);

    return 0;
}
