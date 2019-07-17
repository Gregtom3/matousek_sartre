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
  /* Tracking Momentum in CEMC */
  Smear::Device trackingMomentum_CEMC(Smear::kP, "-0.00617024+sqrt((0.00772158+-0.00307934*(-log(tan(theta/2.0)))+0.0103485*(-log(tan(theta/2.0)))^2+0.00121678*(-log(tan(theta/2.0)))^3+-0.00934239*(-log(tan(theta/2.0)))^4)^2+(-0.00934239*P+-0.00533642*P*(-log(tan(theta/2.0)))+0.0153259*P*(-log(tan(theta/2.0)))^2+-0.00406926*P*(-log(tan(theta/2.0)))^3+-0.00628814*P*(-log(tan(theta/2.0)))^4)^2+(0.00180757*P^2+-7.69322e-05*P^2*(-log(tan(theta/2.0)))+-0.000694712*P^2*(-log(tan(theta/2.0)))^2+3.46393e-05*P^2*(-log(tan(theta/2.0)))^3+0.000178284*P^2*(-log(tan(theta/2.0)))^4)^2)");
  trackingMomentum_CEMC.Accept.SetGenre(Smear::kAll);
  trackingMomentum_CEMC.Accept.SetCharge(Smear::kCharged);
  trackingMomentum_CEMC.Accept.AddZone(zone_cemc);

  /* Smear::Device trackingTheta(Smear::kTheta, "0");
  trackingTheta.Accept.SetGenre(Smear::kAll);
  trackingTheta.Accept.SetCharge(Smear::kCharged);
  trackingTheta.Accept.AddZone(zone_cemc);

  Smear::Device trackingPhi(Smear::kPhi, "0");
  trackingPhi.Accept.SetGenre(Smear::kAll);
  trackingPhi.Accept.SetCharge(Smear::kCharged);
  trackingPhi.Accept.AddZone(zone_cemc);*/

  /* Tracking Momentum in EEMC */
   Smear::Device trackingMomentum_EEMC(Smear::kP, "-0.0772304+sqrt((-1.23794+-2.2575*(-log(tan(theta/2.0)))+-1.39895*(-log(tan(theta/2.0)))^2+-0.374941*(-log(tan(theta/2.0)))^3+-0.0368343*(-log(tan(theta/2.0)))^4)^2+(-0.0368343*P+-0.181595*P*(-log(tan(theta/2.0)))+-0.207071*P*(-log(tan(theta/2.0)))^2+-0.0766112*P*(-log(tan(theta/2.0)))^3+-0.00962969*P*(-log(tan(theta/2.0)))^4)^2+(0.104853*P^2+0.181946*P^2*(-log(tan(theta/2.0)))+0.114157*P^2*(-log(tan(theta/2.0)))^2+0.0305872*P^2*(-log(tan(theta/2.0)))^3+0.00309452*P^2*(-log(tan(theta/2.0)))^4)^2)");
  trackingMomentum_EEMC.Accept.SetGenre(Smear::kAll);
  trackingMomentum_EEMC.Accept.SetCharge(Smear::kCharged);
  trackingMomentum_EEMC.Accept.AddZone(zone_eemc);

  /* Smear::Device trackingTheta(Smear::kTheta, "0");
  trackingTheta.Accept.SetGenre(Smear::kAll);
  trackingTheta.Accept.SetCharge(Smear::kCharged);
  trackingTheta.Accept.AddZone(zone_tracking);

  Smear::Device trackingPhi(Smear::kPhi, "0");
  trackingPhi.Accept.SetGenre(Smear::kAll);
  trackingPhi.Accept.SetCharge(Smear::kCharged);
  trackingPhi.Accept.AddZone(zone_tracking);*/

  /* Tracking Momentum in FEMC */
   Smear::Device trackingMomentum_FEMC(Smear::kP, "-0.0126778+sqrt((0.650439+-1.30173*(-log(tan(theta/2.0)))+0.951292*(-log(tan(theta/2.0)))^2+-0.290433*(-log(tan(theta/2.0)))^3+0.0311389*(-log(tan(theta/2.0)))^4)^2+(0.0311389*P+-0.0984525*P*(-log(tan(theta/2.0)))+0.103116*P*(-log(tan(theta/2.0)))^2+-0.0368756*P*(-log(tan(theta/2.0)))^3+0.0046492*P*(-log(tan(theta/2.0)))^4)^2+(0.00936494*P^2+-0.0186277*P^2*(-log(tan(theta/2.0)))+0.0133764*P^2*(-log(tan(theta/2.0)))^2+-0.00392038*P^2*(-log(tan(theta/2.0)))^3+0.000429569*P^2*(-log(tan(theta/2.0)))^4)^2)");
  trackingMomentum_FEMC.Accept.SetGenre(Smear::kAll);
  trackingMomentum_FEMC.Accept.SetCharge(Smear::kCharged);
  trackingMomentum_FEMC.Accept.AddZone(zone_femc);

  /* Smear::Device trackingTheta(Smear::kTheta, "0");
  trackingTheta.Accept.SetGenre(Smear::kAll);
  trackingTheta.Accept.SetCharge(Smear::kCharged);
  trackingTheta.Accept.AddZone(zone_tracking);

  Smear::Device trackingPhi(Smear::kPhi, "0");
  trackingPhi.Accept.SetGenre(Smear::kAll);
  trackingPhi.Accept.SetCharge(Smear::kCharged);
  trackingPhi.Accept.AddZone(zone_tracking);*/

  /* Tracking Theta in MAPS */
  Smear::Acceptance::Zone zone_maps( eta2theta(  2.34 ), eta2theta( -2.34 ) );
  Smear::Device trackingTheta_maps(Smear::kTheta, "9.7753e-05+-3.46961e-05*(-log(tan(theta/2.0)))^2+4.84101e-06*(-log(tan(theta/2.0)))^4");
  trackingTheta_maps.Accept.SetGenre(Smear::kAll);
  trackingTheta_maps.Accept.SetCharge(Smear::kCharged);
  trackingTheta_maps.Accept.AddZone(zone_maps);

  /* Tracking Theta in EGEMS */
  Smear::Acceptance::Zone zone_egems( eta2theta(  -2.34 ), eta2theta( -4.00 ) );
  Smear::Device trackingTheta_egems(Smear::kTheta, "0.00169807+8.87515e-05*(-log(tan(theta/2.0)))^2+-3.35042e-06*(-log(tan(theta/2.0)))^4");
  trackingTheta_egems.Accept.SetGenre(Smear::kAll);
  trackingTheta_egems.Accept.SetCharge(Smear::kCharged);
  trackingTheta_egems.Accept.AddZone(zone_egems);

  /* Tracking Theta in FGEMS */
  Smear::Acceptance::Zone zone_fgems( eta2theta(  4.00 ), eta2theta( 2.34 ) );
  Smear::Device trackingTheta_fgems(Smear::kTheta, "0.000341547+0.000150987*(-log(tan(theta/2.0)))^2+-6.51146e-06*(-log(tan(theta/2.0)))^4");
  trackingTheta_fgems.Accept.SetGenre(Smear::kAll);
  trackingTheta_fgems.Accept.SetCharge(Smear::kCharged);
  trackingTheta_fgems.Accept.AddZone(zone_fgems);

  /* Tracking Phi */
  Smear::Acceptance::Zone zone_all( eta2theta(  4.00 ), eta2theta( -4.00 ) );
  Smear::Device trackingPhi(Smear::kPhi, "0.0552268");
  trackingPhi.Accept.SetGenre(Smear::kAll);
  trackingPhi.Accept.SetCharge(Smear::kCharged);
  trackingPhi.Accept.AddZone(zone_all);

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

  det.AddDevice(trackingMomentum_CEMC);
  det.AddDevice(trackingMomentum_EEMC);
  det.AddDevice(trackingMomentum_FEMC);
  det.AddDevice(trackingTheta_egems);
  det.AddDevice(trackingTheta_fgems);
  det.AddDevice(trackingTheta_maps);
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
