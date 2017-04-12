# Author: Kevin Cai (kcai2@ucsc.edu)

GCC      = gcc -g -O0 -Wall -Wextra -std=gnu99 mstat.c -o mstat
CSOURCES = mstat.c
SOURCES  = ${CSOURCES} Makefile
EXECBINS = mstat
LISTING  = Listing.ps
SUBMIT   = submit cmps012b-wm.w15 lab8

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

