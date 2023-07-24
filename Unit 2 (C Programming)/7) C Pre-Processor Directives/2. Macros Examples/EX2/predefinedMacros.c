#include <stdio.h>

int main()
{
    printf("__STDC__ = %hhd\n",__STDC__);
    switch(__STDC_VERSION__)
    {
        case 199409L:
        printf("Version: %s\n","C95");
        break;
        case 199901L:
        printf("Version: %s\n","C99");
        break;
        case 201112L:
        printf("Version: %s\n","C11");
        break;
        case 201710L:
        printf("Version: %s\n","C17");
        break;
    }
    /* 1 -> OS 
       0 -> No OS */
    printf("__STDC_HOSTED__ = %hhd\n",__STDC_HOSTED__);

    printf("__FILE__ = %s\n",__FILE__);
    printf("__LINE__ = %d\n",__LINE__);
    printf("__DATE__ = %s\n", __DATE__);
    printf("__TIME__ = %s\n", __TIME__);
    printf("__func__ = %s\n",__func__);

    return 0;
}