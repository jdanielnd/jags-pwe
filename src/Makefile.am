SUBDIRS = distributions
SUBDIRS += functions

jagsmod_LTLIBRARIES = pwexponential.la

pwexponential_la_SOURCES = pwexponential.cc

pwexponential_la_CPPFLAGS = -I$(includedir)/JAGS

pwexponential_la_LIBADD = distributions/pwexpdist.la
pwexponential_la_LIBADD += functions/ppwexp.la


if WINDOWS
pwexponential_la_LIBADD += -ljags-$(JAGS_MAJOR) -ljrmath-0
else
pwexponential_la_LIBADD += -ljags -ljrmath
endif

pwexponential_la_LDFLAGS = -module -avoid-version
if WINDOWS
pwexponential_la_LDFLAGS += -no-undefined
endif
