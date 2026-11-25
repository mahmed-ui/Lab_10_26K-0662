#include <stdio.h>

int main(){
    FILE *fp;
    char name[11];
    char cities[5][11];
    float temps[5];
    float temp;
    int i, n, hottest;

    fp = fopen("temperature.txt", "wb");
    for (i = 0; i < 5; i++)
    {
        printf("City %d name and temperature: ", i + 1);
        scanf("%s %f", name, &temp);
        fprintf(fp, "%-10s %5.1f\n", name, temp);
    }
    fclose(fp);

    fp = fopen("temperature.txt", "rb+");

    printf("City number: ");
    scanf("%d", &n);
    fseek(fp, (n - 1) * 17, SEEK_SET);
    fscanf(fp, "%s %f", name, &temp);
    printf("%s %.1f\n", name, temp);

    printf("City number to correct: ");
    scanf("%d", &n);
    fseek(fp, (n - 1) * 17, SEEK_SET);
    fscanf(fp, "%s %f", name, &temp);
    printf("New temperature: ");
    scanf("%f", &temp);
    fseek(fp, (n - 1) * 17, SEEK_SET);
    fprintf(fp, "%-10s %5.1f\n", name, temp);
    printf("%s updated to %.1f\n", name, temp);

    rewind(fp);
    for (i = 0; i < 5; i++)
        fscanf(fp, "%s %f", cities[i], &temps[i]);

    hottest = 0;
    for (i = 1; i < 5; i++){
        if (temps[i] > temps[hottest])
            hottest = i;
    }
    printf("Hottest city: %s (%.1f)\n", cities[hottest], temps[hottest]);

    fclose(fp);
    return 0;
}
