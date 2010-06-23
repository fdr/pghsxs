/*-------------------------------------------------------------------------
 *
 * pg_freespacemap.c
 *	  display contents of a free space map
 *
 *	  $PostgreSQL$
 *-------------------------------------------------------------------------
 */
#include "postgres.h"

/* I think only funcapi is necessary here */
#include "access/heapam.h"
#include "funcapi.h"
#include "storage/block.h"
#include "storage/freespace.h"


PG_MODULE_MAGIC;

Datum		pg_freespace(PG_FUNCTION_ARGS);

/*
 * Returns the amount of free space on a given page, according to the
 * free space map.
 *
 * HASKELL GENERATED:
 *
 * Mostly static (except synname):
 *
 * PG_FUNCTION_INFO_V1(symname);
 */
PG_FUNCTION_INFO_V1(pg_freespace);

/*
 * HASKELL GENERATED:
 *
 * (mostly static, except symname)
 *
 * Datum
 * symname(PG_FUNCTION_ARGS)
 */
Datum
pg_freespace(PG_FUNCTION_ARGS)
{
	/* 
	 * HASKELL GENERATED: 
	 *
	 * (May also have to generate the PG_GETARG_CTypeSym Macro)
	 *
	 * CTypeSym gensym = PG_GETARG_CTypeSym
	 */
	Oid			relid  = PG_GETARG_OID(0);
	int64		blkno  = PG_GETARG_INT64(1);

	Datum retval;
	
	/* 
	 * HASKELL GENERATED: 
	 *
	 * Prelude Args can be useful for passing additional interesting
	 * information or out-parameters like ErrData. Retval may be nonsensical
	 * should errdata be set. I think it's okay to have a fixed number of
	 * prelude args that every haskell function gets for free (ex: suppose
	 * haskell wants to know the current memory context).
	 *
	 * mangled_func_name(prelude_arg0, prelude_arg1, gensym_arg0, gensym_argn);
	 */
	retval = call_my_hs_function(&errdata, relid, blkno, ...);

	/* Static C boilerplate, assuming prelude arg0 is the error data structure */
	if (prelude_arg0 != NULL) {
		/*
		 * Stuff to raise the error from errdata structures via
		 * longjmp-wrapping PG Constructs
		 */
	}

	PG_RETURN_CTypeSym(retval);
}
