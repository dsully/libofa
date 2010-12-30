# ------------------------------------------------------------------
#
#   libofa -- the Open Fingerprint Architecture library
#
#   Copyright (C) 2006 MusicIP Corporation
#   All rights reserved.
#
#-------------------------------------------------------------------
AUTOMAKE_OPTIONS = foreign

SUBDIRS = include lib @EXAMPLES_SUBDIR@
DIST_SUBDIRS = include lib examples

cvsclean: distclean
	@echo "additonal cleanup for cvs commits"
	rm -f *~ *.exe
	rm -f $(PACKAGE)-$(VERSION).tar.gz

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libofa.pc

EXTRA_DIST = autogen.sh config_win32.h connected_by_musicip.gif \
	connected_by_musicip.png COPYING Doxyfile.in libofa.pc.in README \
	README.win32 win32/example.vcproj win32/libofa.def win32/libofa.sln
	win32/libofa.vcproj

CLEANFILES = stamp-h
