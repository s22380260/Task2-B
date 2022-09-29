#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctype.h>

int enum_words(const char* str)
{
    int cnt = 0;
    int cur = 0;

    size_t sz = strlen(str);

    for (size_t i = 0; i < sz; i++)
    {
        if (isspace(str[i]) || ispunct(str[i]))
        {
            cnt += !!cur;
            cur = 0;
        }
        else
        {
            cur++;
        }
    }

    return cnt + !!cur;
}

void test(const char* input)
{
    printf("'%s' => %d", input, enum_words(input));
}

int main()
{
    test("My best friend name is Natalia. She is 27 years old");

    char cs[256];
    printf("\nEnter custom string to test: ");
    scanf_s("%[^\n]", &cs, sizeof(cs));
    test(cs);

    return 0;
}