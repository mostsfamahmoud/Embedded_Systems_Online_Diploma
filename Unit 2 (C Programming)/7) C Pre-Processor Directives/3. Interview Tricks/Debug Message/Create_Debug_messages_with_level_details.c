/*
Think how to write a code can be Removed or added to the Embedded C Program and
Responsible on print Debug with Details
*/

#include <stdio.h>

#define DEBUG_ENABLE

#define DPRINTF(debug_level,...) if (debug_level) {\
                                    printf("@ Func = %s, File = %s, Line = %d >> ",__func__,__FILE__,__LINE__);\
                                    printf(__VA_ARGS__);\
                                }


void CAN_SEND()
{
    #ifdef DEBUG_ENABLE
    DPRINTF(3,"Inside CAN_SEND\n")
    #endif
}

void CAN_INIT()
{
    #ifdef DEBUG_ENABLE
    DPRINTF(3,"Inside CAN_INIT\n")
    #endif
}

int main()
{
    #ifdef DEBUG_ENABLE
    DPRINTF(2,"Enter main\n")
    #endif

    CAN_INIT();
    CAN_SEND();

    #ifdef DEBUG_ENABLE
    DPRINTF(2,"Exit main\n")
    #endif

    return 0;
}