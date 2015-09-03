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

library(msm)

# necessary libs
library(rjags)
load.module("pwexponential")

# model
mf <- textConnection("
model {
  for (i in 1:N) 
  {
    x[i] ~ dpwexp(rate[], grids[])
  }
  for (j in 1:M) {
    rate[j] ~ dgamma(1, 2)
  }
}")

# parameters to observe
params <- c("rate")

# fixed parameters
# a     <- 0
# theta <- 2
# beta  <- 1

# data
# RT <- abs(rnorm(500, 5))
# x <- RT
# dat <- list(x=x, N=N, a=a, theta=theta, beta=beta)

f <- c(0.3, 0.6, 0.8, 1.3)
t <- c(0.0, 2.0, 3.0, 5.0)

x <- rpexp(1000, f, t)
N <- length(x)
grids <- t
M <- length(grids)
dat <- list(x=x, N=N, grids=grids, M=M)

# inits
inits1 <- list(rate=c(0.1, 0.5, 1, 2))
inits2 <- list(rate=c(1.0, 2, 5, 8))
inits <- list(inits1,inits2)

# sample
j.model <- jags.model(mf, dat, inits, n.chains=2)

j.samples <- coda.samples(j.model, params, n.iter=1000, thin=3)

# plot
plot(j.samples)
