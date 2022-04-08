#include <stdlib.h>
#include "main.h"

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    unsigned int i, j, s1_len, s2_len;
    char *str;

    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    s1_len = 0;/* length of s1 */
    while (*(s1 + s1_len) != '\0')
        s1_len++;
    s2_len = 0;/* length of s2 */
    while (*(s2 + s2_len) != '\0')
        s2_len++;

    if (n >= s2_len)
        str = malloc((s1_len + s2_len + 1) * sizeof(char));
    else
        str = malloc((s1_len + n + 1) * sizeof(char));

    if (str == NULL)
        return (NULL);

    i = 0;
    while (i < s1_len)
    {
        *(str + i) = *(s1 + i);
        i++;
    }

    j = 0;
    while (j < s2_len)
    {
        *(str + s1_len) = *(s2 + j);
        s1_len++;
        j++;
    }
    
    *(str + (s1_len + 1)) = '\0';
    return (str);
}
