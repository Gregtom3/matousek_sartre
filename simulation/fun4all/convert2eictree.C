int convert2eictree(TString filename="test.out")
{
  gSystem->Load("$OPT_SPHENIX/eic-smear_root-5.34.38/lib/libeicsmear.so");

  BuildTree(filename);

  return 0;
}
