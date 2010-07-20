#include "postgres.h"

#include "funcapi.h"

#include "HsFFI.h"

PG_MODULE_MAGIC;

#define __GLASGOW_HASKELL__

Datum		pg_finestructure(PG_FUNCTION_ARGS);

PG_FUNCTION_INFO_V1(pg_finestructure);

extern void __stginit_HS42(void);
extern void _PG_init(void);

void
_PG_init(void)
{
	int argc = 1;
	char *name = "pghsxs";
	char *argv[1] = {name};
	char **argv_alias = argv;

	hs_init(&argc, &argv_alias);

#ifdef __GLASGOW_HASKELL__
	hs_add_root(__stginit_HS42);
#endif
}

Datum
pg_finestructure(PG_FUNCTION_ARGS)
{
	PG_RETURN_INT16(137);
}
