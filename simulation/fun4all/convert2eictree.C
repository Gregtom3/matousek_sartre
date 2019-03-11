int convert2eictree()
{
  gSystem->Load("$OPT_SPHENIX/eic-smear_root-5.34.38/lib/libeicsmear.so");

  BuildTree("example.txt");

  return 0;
}
