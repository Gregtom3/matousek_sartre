#pragma once
#if ROOT_VERSION_CODE >= ROOT_VERSION(6,00,0)
#include <g4main/PHG4Reco.h>
#include <phool/recoConsts.h>
R__LOAD_LIBRARY(libeicsmear.so)
#endif

float eta2theta( double eta )
{
  float theta = 2.0 * atan( exp( -1 * eta ) );
  return theta;
}

/** Build EIC detector
 */
Smear::Detector BuildEicSphenix() {

  gSystem->Load("libeicsmear");

  /* CALORIMETER
   *
   * Calorimeter resolution usually given as sigma_E/E = const% + stocastic%/Sqrt{E}
   * EIC Smear needs absolute sigma: sigma_E = Sqrt{const*const*E*E + stoc*stoc*E}
   *
   * Genre == 1 (third argument) means only photons and electrons are smeared
   *
   * Accept.Charge( kAll ) seems not to be working properly
   */

  /* Create "electron-going" (backward) electromagnetic calorimeter (PbWO4)*/
  Smear::Acceptance::Zone zone_eemc( eta2theta( -1.55 ), eta2theta( -4.00 ) );

  Smear::Device eemcE(Smear::kE,  "sqrt(0.01*0.01*E*E + 0.025*0.025*E)");
  eemcE.Accept.SetGenre(Smear::kElectromagnetic);
  eemcE.Accept.AddZone(zone_eemc);

  /* Create "central rapidity" electromagnetic calorimeter (W-SciFi) */
  Smear::Acceptance::Zone zone_cemc( eta2theta(  1.24 ), eta2theta( -1.55 ) );

  Smear::Device cemcE(Smear::kE,  "sqrt(0.05*0.05*E*E + 0.16*0.16*E)");
  cemcE.Accept.SetGenre(Smear::kElectromagnetic);
  cemcE.Accept.AddZone(zone_cemc);

  /* Create "hadron-going" (forward) electromagnetic calorimeter (PbScint) */
  Smear::Acceptance::Zone zone_femc( eta2theta(  4.00 ), eta2theta(  1.24 ) );

  Smear::Device femcE(Smear::kE,  "sqrt(0.02*0.02*E*E + 0.08*0.08*E)");
  femcE.Accept.SetGenre(Smear::kElectromagnetic);
  femcE.Accept.AddZone(zone_femc);

  /* Create "central rapidity" hadron calorimeter (inner+outer) (Fe Scint + Steel Scint) */
  Smear::Acceptance::Zone zone_chcal( eta2theta(  1.10 ), eta2theta( -1.10 ) );

  Smear::Device chcalE(Smear::kE,  "sqrt(0.12*0.12*E*E + 0.81*0.81*E)");
  chcalE.Accept.SetGenre(Smear::kHadronic);
  chcalE.Accept.AddZone(zone_chcal);

  /* Create "hadron-going" (forward) hadron calorimeter (Fe Scint) */
  Smear::Acceptance::Zone zone_fhcal( eta2theta(  4.00 ), eta2theta(  1.24 ) );

  Smear::Device fhcalE(Smear::kE,  "sqrt(0.0*0.0*E*E + 0.70*0.70*E)");
  fhcalE.Accept.SetGenre(Smear::kHadronic);
  fhcalE.Accept.AddZone(zone_fhcal);

  /* TRACKING SYSTEM */
  /* Create our tracking capabilities, by a combination of mometum, theta and phi Devices.
   * The momentum parametrization (a*p + b) gives sigma_P/P in percent.
   * So Multiply through by P and divide by 100 to get absolute sigma_P
   * Theta and Phi parametrizations give absolute sigma in miliradians
   *
   * Note: eic-smear only saves smeared parameters for 'smeared' particle, i.e. if you want to
   * save e.g. the 'true' energy for particles measured with the tracker, you need to smear the
   * energy with '0' smearing for those particles.
   */

  /* Create tracking system. */
  Smear::Acceptance::Zone zone_tracking( eta2theta( 4 ), eta2theta( -4.00 ) );

  /* Try parametrization based on sPHENIX Geant4 simulation. The fit to the simulations only covers pseudorapidity -2.5 to + 2.5, so be extra careful with the parametrization outside that range. */
  Smear::Device trackingMomentum(Smear::kP, "P * sqrt( (7.82e-3 + 4.39e-4*(-log(tan(theta/2.0)))**2 + 7.55e-4*(-log(tan(theta/2.0)))**4)**2 + ( (1.44e-3 + -5.35e-4*(-log(tan(theta/2.0)))**2 + -6.73e-5*(-log(tan(theta/2.0)))**3 + 1.37e-4*(-log(tan(theta/2.0)))**4) * P )**2 )");
  trackingMomentum.Accept.SetGenre(Smear::kAll);
  trackingMomentum.Accept.SetCharge(Smear::kCharged);
  trackingMomentum.Accept.AddZone(zone_tracking);

  Smear::Device trackingTheta(Smear::kTheta, "(P>10)*10");
  trackingTheta.Accept.SetGenre(Smear::kAll);
  trackingTheta.Accept.SetCharge(Smear::kCharged);
  trackingTheta.Accept.AddZone(zone_tracking);

  Smear::Device trackingPhi(Smear::kPhi, "0");
  trackingPhi.Accept.SetGenre(Smear::kAll);
  trackingPhi.Accept.SetCharge(Smear::kCharged);
  trackingPhi.Accept.AddZone(zone_tracking);

  /* @TODO Below numbers are for tracking with BeAST. We need to get the parametrization for EIC-sPHENIX!!! */
  //  Smear::Device trackingMomentum(Smear::kP, "(P*P*(0.0182031 + 0.00921047*pow((-log(tan(theta/2.0))), 2) - 0.00291243*pow((-log(tan(theta/2.0))), 4) + 0.000264353*pow((-log(tan(theta/2.0))), 6)) + P*(0.209681 + 0.275144*pow((-log(tan(theta/2.0))), 2) - 0.0436536*pow((-log(tan(theta/2.0))), 4) + 0.00367412*pow((-log(tan(theta/2.0))), 6)))*0.01");
  //  trackingMomentum.Accept.SetCharge(Smear::kCharged);
  //  trackingMomentum.Accept.AddZone(zone_tracking);

  //  Smear::Device trackingTheta(Smear::kTheta, "((1.0/(1.0*P))*(0.752935 + 0.280370*pow((-log(tan(theta/2.0))), 2) - 0.0359713*pow((-log(tan(theta/2.0))), 4) + 0.00200623*pow((-log(tan(theta/2.0))), 6)) + 0.0282315 - 0.00998623*pow((-log(tan(theta/2.0))), 2) + 0.00117487*pow((-log(tan(theta/2.0))), 4) - 0.0000443918*pow((-log(tan(theta/2.0))), 6))*0.001");
  //  trackingTheta.Accept.SetCharge(Smear::kCharged);
  //  trackingTheta.Accept.AddZone(zone_tracking);

  //  Smear::Device trackingPhi(Smear::kPhi, "((1.0/(1.0*P))*(0.743977 + 0.753393*pow((-log(tan(theta/2.0))), 2) + 0.0634184*pow((-log(tan(theta/2.0))), 4) + 0.0128001*pow((-log(tan(theta/2.0))), 6)) + 0.0308753 + 0.0480770*pow((-log(tan(theta/2.0))), 2) - 0.0129859*pow((-log(tan(theta/2.0))), 4) + 0.00109374*pow((-log(tan(theta/2.0))), 6))*0.001");
  //  trackingPhi.Accept.SetCharge(Smear::kCharged);
  //  trackingPhi.Accept.AddZone(zone_tracking);

  /* Create mRICH detector parameterization */

  Smear::Acceptance::Zone zone_dRICH( eta2theta( 3.95 ), eta2theta( 1.24 ));
  Smear::ParticleID dRICH_KPi("PIDMatrixFiles/dRICH_KPiPIDMatrix.dat");
  Smear::ParticleID dRICH_ePi("PIDMatrixFiles/dRICH_ePiPIDMatrix.dat");
  dRICH_KPi.Accept.AddZone(zone_dRICH);
  dRICH_ePi.Accept.AddZone(zone_dRICH);

  //only implement gas RICH for e/pi separation, since the dRICH already covers the momentum and pseudorapidity range for K/pi separation
  Smear::Acceptance::Zone zone_gasRICH( eta2theta( 3.95 ), eta2theta( 1.24 ));
  Smear::ParticleID gasRICH("PIDMatrixFiles/gasRICH_PIDMatrix.dat");
  gasRICH.Accept.AddZone(zone_gasRICH);

  Smear::Acceptance::Zone zone_hside_mRICH( eta2theta( 1.24 ), eta2theta( 1.10 ));
  Smear::ParticleID hside_mRICH_KPi("PIDMatrixFiles/hside_mRICH_KPiPIDMatrix.dat");
  Smear::ParticleID hside_mRICH_ePi("PIDMatrixFiles/mRICH_ePiPIDMatrix.dat");
  hside_mRICH_KPi.Accept.AddZone(zone_hside_mRICH);
  hside_mRICH_ePi.Accept.AddZone(zone_hside_mRICH);

  Smear::Acceptance::Zone zone_DIRC( eta2theta( 1.24 ), eta2theta( -1.24 ));
  Smear::ParticleID DIRC("PIDMatrixFiles/DIRCPIDMatrix.dat");
  DIRC.Accept.AddZone(zone_DIRC);

  Smear::Acceptance::Zone zone_eside_mRICH( eta2theta( -1.4 ), eta2theta( -3.9 ));
  Smear::ParticleID eside_mRICH_KPi("PIDMatrixFiles/eside_mRICH_PIDMatrix.dat");
  Smear::ParticleID eside_mRICH_ePi("PIDMatrixFiles/mRICH_ePiPIDMatrix.dat");
  eside_mRICH_KPi.Accept.AddZone(zone_eside_mRICH);
  eside_mRICH_ePi.Accept.AddZone(zone_eside_mRICH);

  /* Create a DETECTOR and add the devices
   */
  Smear::Detector det;

  det.AddDevice(eemcE);
  det.AddDevice(cemcE);
  det.AddDevice(femcE);

  det.AddDevice(chcalE);
  det.AddDevice(fhcalE);

  det.AddDevice(trackingMomentum);
  det.AddDevice(trackingTheta);
  det.AddDevice(trackingPhi);

  det.AddDevice(dRICH_KPi);
  det.AddDevice(dRICH_ePi);
  det.AddDevice(gasRICH);
  det.AddDevice(hside_mRICH_KPi);
  det.AddDevice(hside_mRICH_ePi);
  det.AddDevice(DIRC);
  det.AddDevice(eside_mRICH_KPi);
  det.AddDevice(eside_mRICH_ePi);

  det.SetEventKinematicsCalculator("NM JB DA"); // The detector will calculate event kinematics from smeared values

  return det;
}
