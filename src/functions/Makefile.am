noinst_LTLIBRARIES = ppwexp.la
noinst_LTLIBRARIES += ddpwexp.la
noinst_LTLIBRARIES += qpwexp.la

ppwexp_la_CPPFLAGS = -I$(top_srcdir)/src \
												 -I$(includedir)/JAGS

ppwexp_la_LDFLAGS = -no-undefined -module -avoid-version

ppwexp_la_SOURCES = PPwexp.cc

ddpwexp_la_CPPFLAGS = -I$(top_srcdir)/src \
												 -I$(includedir)/JAGS

ddpwexp_la_LDFLAGS = -no-undefined -module -avoid-version

ddpwexp_la_SOURCES = DDPwexp.cc

qpwexp_la_CPPFLAGS = -I$(top_srcdir)/src \
												 -I$(includedir)/JAGS

qpwexp_la_LDFLAGS = -no-undefined -module -avoid-version

qpwexp_la_SOURCES = QPwexp.cc

noinst_HEADERS = PPwexp.h
noinst_HEADERS += DDPwexp.h
noinst_HEADERS += QPwexp.h
