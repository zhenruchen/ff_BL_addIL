#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _ar_reg(void);
extern void _cad_reg(void);
extern void _ca_reg(void);
extern void _cat_reg(void);
extern void _catp_reg(void);
extern void _currentclamp_reg(void);
extern void _dipole_reg(void);
extern void _dpresyn_reg(void);
extern void _gnetstim_reg(void);
extern void _h_reg(void);
extern void _kca_reg(void);
extern void _kdr_reg(void);
extern void _km_reg(void);
extern void _na_reg(void);
extern void _pp_dipole_reg(void);
extern void _precall_reg(void);
extern void _tchannel_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," ar.mod");
    fprintf(stderr," cad.mod");
    fprintf(stderr," ca.mod");
    fprintf(stderr," cat.mod");
    fprintf(stderr," catp.mod");
    fprintf(stderr," currentclamp.mod");
    fprintf(stderr," dipole.mod");
    fprintf(stderr," dpresyn.mod");
    fprintf(stderr," gnetstim.mod");
    fprintf(stderr," h.mod");
    fprintf(stderr," kca.mod");
    fprintf(stderr," kdr.mod");
    fprintf(stderr," km.mod");
    fprintf(stderr," na.mod");
    fprintf(stderr," pp_dipole.mod");
    fprintf(stderr," precall.mod");
    fprintf(stderr," tchannel.mod");
    fprintf(stderr, "\n");
  }
  _ar_reg();
  _cad_reg();
  _ca_reg();
  _cat_reg();
  _catp_reg();
  _currentclamp_reg();
  _dipole_reg();
  _dpresyn_reg();
  _gnetstim_reg();
  _h_reg();
  _kca_reg();
  _kdr_reg();
  _km_reg();
  _na_reg();
  _pp_dipole_reg();
  _precall_reg();
  _tchannel_reg();
}
