## $Id: Makefile.am,v 1.6 2004/04/25 16:29:25 lirc Exp $

## Process this file with automake to produce Makefile.in

## this is so that Automake includes the C compiling definitions, and
## includes the source files in the distribution.
EXTRA_PROGRAMS = automake_dummy
automake_dummy_SOURCES = lirc_bt829.c

## there is no *just* object file support in automake.  This is close enough
module_DATA = lirc_bt829.o

include ../Makefile.common
