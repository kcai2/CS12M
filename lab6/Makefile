# Author: Kevin Cai (kcai2@ucsc.edu)

GCC      = gcc -g -O0 -Wall -Wextra -std=gnu99 lsort.c -o lsort nsort.c -o nsort
CSOURCES = nsort.c lsort.c
SOURCES  = ${CSOURCES} Makefile
EXECBINS = nsort   lsort
LISTING  = Listing.ps
SUBMIT   = submit cmps012b-wm.w15 lab6

all : ${EXECBINS}

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

