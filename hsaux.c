#include "postgres.h"

#include "funcapi.h"

#include "HsFFI.h"

PG_MODULE_MAGIC;

#define __GLASGOW_HASKELL__

Datum		pg_finestructure(PG_FUNCTION_ARGS);
Datum		pg_hs_init(PG_FUNCTION_ARGS)

PG_FUNCTION_INFO_V1(pg_finestructure);
PG_FUNCTION_INFO_V1(pg_hs_init);

Datum
pg_hs_init(PG_FUNCTION_ARGS)
{
	hs_init(NULL, NULL);

#ifdef __GLASGOW_HASKELL__
	hs_add_root(__stginit_HS42);
#endif

	PG_RETURN_NULL();
}

Datum
pg_finestructure(PG_FUNCTION_ARGS)
{
	PG_RETURN_INT16(137);
}
