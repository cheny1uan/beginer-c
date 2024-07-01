/* 2351892 陈奕炫 信11 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int lenth=0;
    if (str == NULL) {
        return 0;
    }
    for (; *str != 0; str++)
        lenth++;

    return lenth;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    if (s1 == NULL)
        return NULL;
    if (s2 == NULL)
        return s1;
    while (*s1 != 0) {
        s1++;
    }
    while (*s2 != 0) {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = *s2;
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p1 = s1;
    const char* p2 = s2;
    if (s1 == NULL)
        return NULL;
    if (s2 == NULL)
        return s1;
    for (; *p1 != 0; p1++)
        ;
    for (; *p2 != 0 && (p2 - s2 < len); p1++, p2++)
        *p1 = *p2;
    *p1 = 0;

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p1 = s1;
   

    if (s1 == NULL) 
        return NULL;
    if (s2 == NULL) {
        *s1 = 0;
        return p1;
    }
    while (*s2 != 0) {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = 0;
    return p1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    char* p1 = s1;
    const char* p2 = s2;

    if (s1 == NULL)
        return NULL;
    if (s2 == NULL) {        
        return s1;
    }
    for(;*p2!=0&&(p2-s2<len);p1++,p2++)
        *p1 = *p2;
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    while (*s1 == *s2 && *s1 != 0 && *s2 != 0) {
        s1++;
        s2++;
    }
    if (*s1 == 0 && *s2 == 0)
        return 0;
    else
        return *s1 - *s2;
 
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    char ch1, ch2;
    while (*s1 != 0 && *s2 != 0) {

        if (*s1 >= 'A' && *s1 <= 'Z') {
            ch1 = *s1 + 32;
        }
        else
            ch1 = *s1;

        if (*s2 >= 'A' && *s2 <= 'Z') {
            ch2 = *s2 + 32;
        }
        else
            ch2 = *s2;

        if (ch1 != ch2) {
            return ch1 - ch2;
        }
        s1++;
        s2++;
    }
    if (*s1 == 0 && *s2 == 0) {
        return 0;
    }
    else
        return *s1 - *s2;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    
    const char* s2_start = s2;
    for (; *s1 != 0 && *s2 != 0 && (s2 - s2_start < len); s1++, s2++)
        if (*s1 != *s2)
            return *s1 - *s2;
    if (s2 - s2_start == len)
        return 0;
    else
        return *s1 - *s2;
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    char ch1, ch2;
    const char* s2_start = s2;
    for (; *s1 != 0 && *s2 !=0&& (s2 - s2_start < len); s1++, s2++)
    {
        if (*s1 >= 'A' && *s1 <= 'Z') {
            ch1 = *s1 + 32;
        }
        else
            ch1 = *s1;

        if (*s2 >= 'A' && *s2 <= 'Z') {
            ch2 = *s2 + 32;
        }
        else
            ch2 = *s2;
        if (ch1 != ch2) {
            return ch1 - ch2;
        }
       
    }
    if (s2 - s2_start == len)
        return 0;
    else
    {
        if (*s1 >= 'A' && *s1 <= 'Z') {
            ch1 = *s1 + 32;
        }
        else
            ch1 = *s1;

        if (*s2 >= 'A' && *s2 <= 'Z') {
            ch2 = *s2 + 32;
        }
        else
            ch2 = *s2;

        return ch1 - ch2;
    }


    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strupr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    char* p = str;
    for (; *p != 0; p++){
        if (*p >= 'a' && *p <= 'z')
            *p -= 32;
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    char* p = str;
    for (; *p != 0; p++) {
        if (*p >= 'A' && *p <= 'Z')
            *p += 32;
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    const char* p = str;
    for (; *p != 0; p++){
        if (*p == ch)
            return p - str + 1;
    }
        return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || substr == NULL)
        return NULL;
    const char* str_start = str;
    
        for (; *str != 0; str++)
        {
            if (*str == *substr)
            {
                const char* p1 = str;
                const char* p2 = substr;
                for (; *p2 != 0; p1++, p2++) {
                    if (*p1 != *p2)
                        break;
                }
                if (*p2 == 0)
                    break;
            }
        }
        if (*str == '\0')
            return 0;
        else
            return str - str_start + 1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    const char* p=str;
    const char* str_last=str;
    for (; *p != 0; p++) {
        str_last = p;
    }

    for (; str_last >= str;str_last--) {
        if (*str_last == ch)
            return str_last - str + 1;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL||substr==NULL)
        return NULL;
    const char* p = str;
    const char* str_last=str;
    for (; *p != 0; p++) {
        str_last = p;
    }
    for (; str_last>=str; str_last--)
    {
        if (*str_last == *substr)
        {
            const char* p1 = str_last;
            const char* p2 = substr;
            for (; *p2 != 0; p1++, p2++) {
                if (*p1 != *p2)
                    break;
            }
            if (*p2 == 0)
                break;
        }
    }
    if (str_last<str)
        return 0;
    else
        return str_last - str + 1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strrev(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */

    if (str == NULL)
        return NULL;
    char* str_last = str, *str_start = str;
    for (; *str_last != 0; str_last++)
        ;
    str_last--;
    for (; str_start < str_last; str_start++, str_last--) {
        char ch;
        ch = *str_start;
        *str_start = *str_last;
        *str_last = ch;
    }
        
    return str;
}
