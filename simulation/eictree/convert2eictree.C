#pragma once
#if ROOT_VERSION_CODE >= ROOT_VERSION(6,00,0)
#include <eicsmear/functions.h>
R__LOAD_LIBRARY(libeicsmear.so)
#endif
int convert2eictree(TString filename="/sphenix/user/gregtom3/matousek_sartre/data/fun4all_output/100_sample.txt")
{
  // gSystem->Load("libeicsmear.so");
  gSystem->Load("$OPT_SPHENIX/eic-smear_root-5.34.38/lib/libeicsmear.so");

  BuildTree(filename);

  return 0;
}
