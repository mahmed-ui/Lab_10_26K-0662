#include <stdio.h>
#include <string.h>

int countRepeat(char s[], int i){
    if (s[i + 1] == s[i])
        return 1 + countRepeat(s, i + 1);
    return 1;
}

void compress(char s[], int i, char out[], int j){
    int count;
    if (s[i] == '\0')
    {
        out[j] = '\0';
        return;
    }
    count = countRepeat(s, i);
    out[j] = s[i];
    out[j + 1] = '0' + count;
    compress(s, i + count, out, j + 2);
}

void expand(char in[], int i, char out[], int j){
    int count, k;
    if (in[i] == '\0')
    {
        out[j] = '\0';
        return;
    }
    count = in[i + 1] - '0';
    for (k = 0; k < count; k++)
        out[j + k] = in[i];
    expand(in, i + 2, out, j + count);
}

int main(){
    char original[100], compressed[200], expanded[100];

    printf("Original: ");
    scanf("%s", original);

    compress(original, 0, compressed, 0);
    printf("Compressed: %s\n", compressed);

    expand(compressed, 0, expanded, 0);
    printf("Expanded: %s\n", expanded);

    if (strcmp(original, expanded) == 0)
        printf("Match: Yes\n");
    else
        printf("Match: No\n");
    return 0;
}
