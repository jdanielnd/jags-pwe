#!/usr/bin/R --silent -f
# -*- encoding: utf-8 -*-
# amoroso.R
#
# (c) 2015 Dominik Wabersich <dominik.wabersich [aet] gmail.com>
# GPL 3.0+ or (cc) by-sa (http://creativecommons.org/licenses/by-sa/3.0/)
#
# created 2015-01-06
# last mod 2015-01-06 17:03 DW
#

rm(list=ls())

# necessary libs
library(rjags)
load.module("exponential")

# model
mf <- textConnection("model {
  for (i in 1:N) 
  {
    x[i] ~ dexp2(alpha)
  }
  alpha ~ dgamma(0.5,0.5)
}")

# parameters to observe
params <- c("alpha")

# fixed parameters
# a     <- 0
# theta <- 2
# beta  <- 1

# data
# RT <- abs(rnorm(500, 5))
# x <- RT
# dat <- list(x=x, N=N, a=a, theta=theta, beta=beta)
x <- rexp(100, 10)
N <- length(x)
dat <- list(x=x, N=N)

# inits
inits1 <- list(alpha=0.1)
inits2 <- list(alpha=0.9)
inits <- list(inits1,inits2)

# sample
j.model <- jags.model(mf, dat, inits, n.chains=2, n.adapt=100)
j.samples <- coda.samples(j.model, params, n.iter=400, thin=3)

# plot
plot(j.samples)
