#include <stdio.h>

int main(){
    FILE *fp;
    char category[13];
    float amount, total = 0;
    int entry, i;

    fp = fopen("expenses.txt", "wb");
    fprintf(fp, "%-12s %9.2f\n", "Food", 1200.00);
    fprintf(fp, "%-12s %9.2f\n", "Transport", 500.00);
    fprintf(fp, "%-12s %9.2f\n", "Books", 850.00);
    fprintf(fp, "%-12s %9.2f\n", "Mobile", 300.00);
    fclose(fp);

    printf("Category: ");
    scanf("%s", category);
    printf("Amount: ");
    scanf("%f", &amount);
    fp = fopen("expenses.txt", "ab");
    fprintf(fp, "%-12s %9.2f\n", category, amount);
    fclose(fp);

    fp = fopen("expenses.txt", "rb+");
    fseek(fp, -2 * 23, SEEK_END);
    printf("Latest two: ");
    for (i = 0; i < 2; i++){
        fscanf(fp, "%s %f", category, &amount);
        printf("%s %.2f", category, amount);
        if (i == 0)
            printf(", ");
    }
    printf("\n");

    printf("Entry to fix: ");
    scanf("%d", &entry);
    printf("Correct amount: ");
    scanf("%f", &amount);
    fseek(fp, (entry - 1) * 23, SEEK_SET);
    fscanf(fp, "%s %f", category, &total);
    fseek(fp, (entry - 1) * 23, SEEK_SET);
    fprintf(fp, "%-12s %9.2f\n", category, amount);

    total = 0;
    rewind(fp);
    for (i = 0; i < 5; i++){
        fscanf(fp, "%s %f", category, &amount);
        printf("%s %.2f\n", category, amount);
        total = total + amount;
    }
    printf("Total: %.2f\n", total);

    fclose(fp);
    return 0;
}
