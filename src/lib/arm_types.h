
#ifndef __ARM_TYPES_H__
#define __ARM_TYPES_H__

typedef unsigned char auchar;
typedef char achar;

typedef int aint;
typedef unsigned int auint;

typedef aint aboolean;

typedef short ashort;
typedef unsigned short aushort;

typedef long along;
typedef unsigned long aulong;

typedef float afloat;
typedef double adouble;

typedef void*  apointer;
typedef const void* aconstpointer;

typedef signed char gint8;
typedef unsigned char guint8;

typedef signed short gint16;
typedef unsigned char guint16;

typedef signed int gint32;
typedef unsigned int guint32;

//typedef signed long long gint64;
//typedef 

typedef aint (*ACompareFunc)      (aconstpointer a, aconstpointer b);
typedef aint (*ACompareDataFunc)  (aconstpointer a,
                                   aconstpointer b,
                                   apointer user_data);
typedef void (*ADestroyNotify)    (apointer data);

#define FALSE   (0)
#define TRUE    (!FALSE)
//#define A_BEGIN_DECLS  extern "C" {
//#define A_END_DECLS    }

#endif
