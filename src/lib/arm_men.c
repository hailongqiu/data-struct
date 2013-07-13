/* 內存相關函數.
 */

#include "arm_men.h"

apointer a_malloc(auint n_bytes)
{
    apointer mem = (apointer)malloc(n_bytes);
    
    if (mem)
        return mem;
    return NULL;
}
