#include <stdio.h>

void strrev(char *string)
{
    int begin, end, count = 0;

    while (string[count] != '\0')
        count++;

    end = count - 1;

    char r[count + 1];

    for (begin = 0; begin < count; begin++)
    {
        r[begin] = string[end];
        end--;
    }

    r[begin] = '\0';

    for (int i = 0; i < count; i++)
    {
        string[i] = r[i];
    }
}

int QT_strrev()
{
    char str[4] = "abc";
    strrev(str);
    char result[4] = "cba";
    for (int i = 0; i < 3; i++)
    {
        if (str[i] != result[i])
        {
            printf("Test for strrev:  failed\n");
            return 1;
        }
    }
    printf("Test for strrev:  passed\n");
    return 0;
}

int strcmp(char *string_1, char *string_2)
{
    int total_1, total_2 = 0;
    while (string_1[total_1] != '\0')
    {
        total_1++;
    }
    while (string_2[total_2] != '\0')
    {
        total_2++;
    }
    int total_to_use = total_1;
    int total_to_not_use = total_2;
    int bigger_indicator = 2;
    if (total_2 < total_1)
    {
        total_to_use = total_2;
        total_to_not_use = total_1;
        bigger_indicator = 1;
    }
    int ascii_1;
    int ascii_2;
    int in;
    for (int j = 0; j < total_to_not_use; j++)
    {
        for (in = 0; in < total_to_use; in++)
        {
            if (string_1[in] != string_2[in])
            {
                ascii_1 = string_1[in];
                ascii_2 = string_2[in];
                return ascii_1 - ascii_2;
            }
        }
        if (j >= total_to_use && total_1 != total_2)
        {
            if (bigger_indicator == 1)
            {
                return string_1[j] - 0;
            }
            else if (bigger_indicator == 2)
            {
                return 0 - string_2[j];
            }
        }
    }
    return 0;
}

int QT_strcmp()
{
    char test11[] = "hellob";
    char test12[] = "helloa";
    char test21[] = "hellob";
    char test22[] = "helloa";
    char test31[] = "hello";
    char test32[] = "helloa";
    char test41[] = "hello";
    char test42[] = "helloa";
    char string_1_wierd[] = "hello";
    int result1 = strcmp(test11, test12);
    int result2 = strcmp(test22, test21);
    int result3 = strcmp(test32, test31);
    int result4 = strcmp(test41, test42);
    if (result1 == 1 && result2 == -1 && result3 == 97 && result4 == -97)
    {
        printf("Test for strcmp:  passed\n");
        return 0;
    }
    else
    {
        printf("Test for strcmp:  failed\n");
        return 1;
    }
}

int strcmpi(char *string_1, char *string_2)
{
    for (int i = 0; string_1[i] != '\0'; i++)
    {
        if (string_1[i] >= 'A' && string_1[i] <= 'Z')
        {
            string_1[i] = string_1[i] + 32;
        }
    }
    for (int i = 0; string_2[i] != '\0'; i++)
    {
        if (string_2[i] >= 'A' && string_2[i] <= 'Z')
        {
            string_2[i] = string_2[i] + 32;
        }
    }
    return strcmp(string_1, string_2);
}

int QT_strcmpi()
{
    char string_1[] = "HELLO";
    char string_2[] = "hello";
    int result = strcmpi(string_1, string_2);
    if (result == 0)
    {
        printf("Test strcmpi:  passed!\n");
        return 0;
    }
    else
    {
        printf("Test strcmpi:  failed!\n");
        return 1;
    }
}

int strncmp(char *string_1, char *string_2, int n)
{
    int total_1, total_2 = 0;
    while (string_1[total_1] != '\0')
    {
        total_1++;
    }
    while (string_2[total_2] != '\0')
    {
        total_2++;
    }
    for (int i = 0; i < n; i++)
    {
        if (string_1[i] != string_2[i])
        {
            int ascii1 = string_1[i];
            int ascii2 = string_2[i];
            return ascii1 - ascii2;
        }
    }

    return 0;
}

int QT_strncmp()
{
    char str1[] = "hello";
    char str2[] = "helloa";
    int result = strncmp(str1, str2, 3);
    if (result == 0)
    {
        printf("Test strncmp:  passed!\n");
        return 0;
    }
    else
    {
        printf("Test strncmp:  failed!\n");
        return 1;
    }
}

char *strlwr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
    return str;
}

char *strupr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
    return str;
}

int strlen(const char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}

char *strncpy(char *dest, char *src, int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = src[i];
    }
    return dest;
}

char *strchr(char *str, int c)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        int asciiValue = str[i];
        if (asciiValue == c)
        {
            return &str[i];
        }
    }
}

int main()
{
    char string[7] = "helloa";
    char string2[6] = "hello";

    //printf("%d", strncmp(string, string2, 7));

    //testing
    //printf("%d\n", QT_strrev());
    //printf("%d\n", QT_strcmp());
    //printf("%d\n", QT_strcmpi());
    printf("%d\n", QT_strncmp());

    return 0;
}