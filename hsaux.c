#include "postgres.h"

#include "funcapi.h"

PG_MODULE_MAGIC;

Datum		pg_finestructure(PG_FUNCTION_ARGS);

PG_FUNCTION_INFO_V1(pg_finestructure);

Datum
pg_finestructure(PG_FUNCTION_ARGS)
{
	PG_RETURN_INT16(137);
}
