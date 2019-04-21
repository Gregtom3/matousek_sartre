#include <stdio.h>
#pragma once
#if ROOT_VERSION_CODE >= ROOT_VERSION(6,00,0)
#include <eicsmear/functions.h>
#include "eic_sphenix.C"
R__LOAD_LIBRARY(libeicsmear.so)
#endif
int run_eic_sphenix()
{
  gSystem->Load("libeicsmear");

  gROOT->LoadMacro("eic_sphenix.C");

  SmearTree(BuildEicSphenix(), "/sphenix/user/gregtom3/matousek_sartre/data/eictree_output/100_sample.root");

  return 0;
}
