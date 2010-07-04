# Normal PGXS Section
MODULE_big = pg_freespacemap
OBJS = pg_freespacemap.o

DATA_built = pg_freespacemap.sql
DATA = uninstall_pg_freespacemap.sql

USE_PGXS=1

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/pg_freespacemap
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif

HS_INCLUDE=/nix/store/s30bjfrfcklyhgrbix5hn8pnfpmrvl6q-ghc-6.12.2/lib/ghc-6.12.2/include/


hsaux.o: hsaux.c
	gcc -g -O2 -g -Wall -O2 -fPIC -Wall -Wmissing-prototypes -Wpointer-arith \
	-Wdeclaration-after-statement -Wendif-labels -fno-strict-aliasing -fwrapv \
	-g -fpic \
	-I. \
	-I/usr/include/postgresql/8.4/server \
	-I/usr/include/postgresql/internal \
	-D_GNU_SOURCE \
	-I/usr/include/libxml2 \
	-I/usr/include/tcl8.5 \
	-I$(HS_INCLUDE) \
	-c $<

hs42: hsaux.o
	ghc --make -shared -fPIC -no-hs-main -dynamic HS42.hs \
	-o 42.so hsaux.o -lHSrts-ghc6.12.2

clean:
	rm -f *.hi *.o *.so

