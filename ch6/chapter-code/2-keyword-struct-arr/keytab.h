#ifndef KEYTAB_H
#define KEYTAB_H

#include "keyword.h"
#define KEYTAB_NKEYS (sizeof keytab / sizeof keytab[0])

extern struct key keytab[];
extern int keytab_size;

#endif
