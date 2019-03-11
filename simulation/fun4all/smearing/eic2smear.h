#ifndef __eic2smear_H__
#define __eic2smear_H__

/* Fun4All includes */
#include <fun4all/SubsysReco.h>

/* STL includes */
#include <math.h>
#include <map>

/*HepMC include */
#include <phhepmc/PHHepMCGenEvent.h>
#include <phhepmc/PHHepMCGenEventMap.h>
class TTree;
class TFile;

class PHCompositeNode;



class eic2smear : public SubsysReco
{

public:

  eic2smear(std::string filename);

  int
  Init(PHCompositeNode*);
  int
  InitRun(PHCompositeNode*);
  int
  process_event(PHCompositeNode*);
  int
  End(PHCompositeNode*);

  
  
  

private:
  
  bool _verbose;
  bool _save_towers;
  bool _save_tracks;
  bool _do_process_dvmp;

  int _ievent;
  int _total_pass;

  std::string _filename;
  TFile *_tfile;

  /** helper pointer to topNode */
  PHCompositeNode *_topNode;
};

#endif // __eic2smear_H__
