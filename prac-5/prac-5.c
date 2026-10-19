#include <stdio.h>

struct Item {
    int weight;
    int value;
    float ratio;
};

void sortItems(struct Item items[], int n) {
    int i, j;
    struct Item temp;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;
    float totalValue = 0.0;

    printf("Enter number of packages: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and value of each package:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter truck capacity: ");
    scanf("%d", &capacity);

    sortItems(items, n);

    printf("\nSelected Packages:\n");

    for(int i = 0; i < n; i++) {
        if(capacity == 0)
            break;

        if(items[i].weight <= capacity) {
            printf("Take full package (Weight = %d, Value = %.2f)\n",
                   items[i].weight, (float)items[i].value);

            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else {
            float fraction = (float)capacity / items[i].weight;

            printf("Take %.2f fraction of package (Weight = %d, Value = %.2f)\n",
                   fraction, items[i].weight,
                   fraction * items[i].value);

            totalValue += fraction * items[i].value;
            capacity = 0;
        }
    }

    printf("\nMaximum Total Value = %.2f\n", totalValue);

    return 0;
}
