
#ifndef __ARM_MEM_H__
#define __ARM_MEM_H__

#include <stdio.h>
#include <stdlib.h>
#include "arm_types.h"


apointer a_malloc        (auint n_bytes);

#define a_new_size(struct_type, size) _A_NEW_SIZE(struct_type, malloc, size)
#define _A_NEW_SIZE(struct_type, func, size)   \
    (struct_type*)a_##func(size)
#define a_new0(struct_type) _A_NEW(struct_type, malloc)
#define _A_NEW(struct_type, func)                \
    (struct_type*)a_##func(sizeof(struct_type)); 


#endif
