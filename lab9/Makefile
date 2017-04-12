# $Id: Makefile,v 1.1 2015-03-09 16:50:48-07 - - $
# Authors: Kevin Cai (kcai2@ucsc.edu) & Ahmadullah Tokhi (atokhi)

GCC      = gcc -g -O0 -Wall -Wextra -std=gnu11
CSOURCES = numsort.c linesort.c inssort.c
CHEADER  = inssort.h
SOURCES  = ${CSOURCES} Makefile
EXECBINS = numsort linesort
LISTING  = Listing.ps
SUBMIT   = submit cmps012b-wm.w15 lab9

all : ${EXECBINS}

numsort : numsort.o inssort.o
	${GCC} numsort.o inssort.o -o numsort

linesort : linesort.o inssort.o
	${GCC} linesort.o inssort.o -o linesort

% : %.c
	${GCC} $< -o $@

ci : 
	cid + ${SOURCES}
	- checksource $<

clean : 
	- rm -vf core

spotless : clean
	- rm -vf ${EXECBINS}

lis : ${CSOURCES} Makefile
	mkpspdf ${LISTING} ${SOURCES}

submit : ${SOURCES}
	${SUBMIT} ${SOURCES}

again : ${SOURCES}
	gmake --no-print-directory spotless ci all lis
