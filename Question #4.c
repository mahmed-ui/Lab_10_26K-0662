#include <stdio.h>
#include <string.h>

int main(){
    FILE *fp;
    int i, room, nights;
    int fileRoom, fileNights;
    char fileStatus, fileName[21];
    float fileRate;
    char name[21];
    char guests[10][21];
    int rooms[10];

    fp = fopen("hotel.txt", "wb");
    for (i = 101; i <= 110; i++)
        fprintf(fp, "%3d %c %-20s %2d %8.2f\n", i, 'F', "-", 0, 8000.00);
    fclose(fp);

    fp = fopen("hotel.txt", "rb+");

    for (i = 0; i < 2; i++){
        printf("Check-in room: ");
        scanf("%d", &room);
        printf("Name: ");
        scanf("%s", name);
        printf("Nights: ");
        scanf("%d", &nights);

        fseek(fp, (room - 101) * 39, SEEK_SET);
        fscanf(fp, "%d %c %s %d %f", &fileRoom, &fileStatus, fileName, &fileNights, &fileRate);

        if (fileStatus == 'F'){
            fseek(fp, (room - 101) * 39, SEEK_SET);
            fprintf(fp, "%3d %c %-20s %2d %8.2f\n", room, 'B', name, nights, 8000.00);
            printf("Room %d booked\n", room);
        }else{
            printf("Room already booked\n");
        }
    }

    rewind(fp);
    for (i = 0; i < 10; i++){
        fscanf(fp, "%d %c %s %d %f", &fileRoom, &fileStatus, guests[i], &fileNights, &fileRate);
        rooms[i] = fileRoom;
    }

    printf("Search name: ");
    scanf("%s", name);
    for (i = 0; i < 10; i++){
        if (strcmp(guests[i], name) == 0)
        {
            printf("%s is in room %d\n", name, rooms[i]);
            break;
        }
    }
    if (i == 10)
        printf("%s not found\n", name);

    printf("Check-out room: ");
    scanf("%d", &room);
    fseek(fp, (room - 101) * 39, SEEK_SET);
    fscanf(fp, "%d %c %s %d %f", &fileRoom, &fileStatus, fileName, &fileNights, &fileRate);
    printf("Bill: %d x %.2f = %.2f\n", fileNights, fileRate, fileNights * fileRate);

    fseek(fp, (room - 101) * 39, SEEK_SET);
    fprintf(fp, "%3d %c %-20s %2d %8.2f\n", room, 'F', "-", 0, 8000.00);

    fclose(fp);
    return 0;
}
