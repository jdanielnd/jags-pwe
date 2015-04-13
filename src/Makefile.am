SUBDIRS = distributions

jagsmod_LTLIBRARIES = exponential.la

exponential_la_SOURCES = exponential.cc

exponential_la_CPPFLAGS = -I$(includedir)/JAGS

exponential_la_LIBADD = distributions/expdist.la

if WINDOWS
exponential_la_LIBADD += -ljags-$(JAGS_MAJOR) -ljrmath-0
else
exponential_la_LIBADD += -ljags -ljrmath
endif

exponential_la_LDFLAGS = -module -avoid-version
if WINDOWS
exponential_la_LDFLAGS += -no-undefined
endif
