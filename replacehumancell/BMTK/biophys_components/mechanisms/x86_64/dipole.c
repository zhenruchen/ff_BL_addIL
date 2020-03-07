/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__dipole
#define _nrn_initial _nrn_initial__dipole
#define nrn_cur _nrn_cur__dipole
#define _nrn_current _nrn_current__dipole
#define nrn_jacob _nrn_jacob__dipole
#define nrn_state _nrn_state__dipole
#define _net_receive _net_receive__dipole 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define ia _p[0]
#define ri _p[1]
#define ztan _p[2]
#define Q _p[3]
#define pv	*_ppvar[0]._pval
#define _p_pv	_ppvar[0]._pval
#define Qsum	*_ppvar[1]._pval
#define _p_Qsum	_ppvar[1]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  0;
 /* external NEURON variables */
 /* declaration of user functions */
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_dipole", _hoc_setdata,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "ia_dipole", "nA",
 "ri_dipole", "Mohm",
 "ztan_dipole", "um",
 "Q_dipole", "fAm",
 "pv_dipole", "mV",
 "Qsum_dipole", "fAm",
 0,0
};
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void _ba1() , _ba2() ;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"dipole",
 0,
 "ia_dipole",
 "ri_dipole",
 "ztan_dipole",
 "Q_dipole",
 0,
 0,
 "pv_dipole",
 "Qsum_dipole",
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 4, _prop);
 	/*initialize range parameters*/
 	_prop->param = _p;
 	_prop->param_size = 4;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 2, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _dipole_reg() {
	int _vectorized = 0;
  _initlists();
 	register_mech(_mechanism, nrn_alloc,(void*)0, (void*)0, (void*)0, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 4, 2);
  hoc_register_dparam_semantics(_mechtype, 0, "pointer");
  hoc_register_dparam_semantics(_mechtype, 1, "pointer");
 	hoc_reg_ba(_mechtype, _ba1, 22);
 	hoc_reg_ba(_mechtype, _ba2, 23);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 dipole /home/mizzou/Desktop/ff_BL_addIL/replacehumancell/BMTK/biophys_components/mechanisms/modfiles/x86_64/dipole.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 /* AFTER SOLVE */
 static void _ba1(Node*_nd, double* _pp, Datum* _ppd, Datum* _thread, _NrnThread* _nt)  {
    _p = _pp; _ppvar = _ppd;
  v = NODEV(_nd);
 ia = ( pv - v ) / ri ;
   Q = ia * ztan ;
   Qsum = Qsum + Q ;
   }
 /* AFTER INITIAL */
 static void _ba2(Node*_nd, double* _pp, Datum* _ppd, Datum* _thread, _NrnThread* _nt)  {
    _p = _pp; _ppvar = _ppd;
  v = NODEV(_nd);
 ia = ( pv - v ) / ri ;
   Q = ia * ztan ;
   Qsum = Qsum + Q ;
   }

static void initmodel() {
  int _i; double _save;_ninits++;
{

}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel();
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{
} return _current;
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/home/mizzou/Desktop/ff_BL_addIL/replacehumancell/BMTK/biophys_components/mechanisms/modfiles/dipole.mod";
static const char* nmodl_file_text = 
  "NEURON {\n"
  "SUFFIX dipole\n"
  ": POINT_PROCESS Dipole\n"
  "RANGE ri, ia, Q, ztan\n"
  "POINTER pv\n"
  "\n"
  "POINTER Qsum : for density. sums into Dipole at section position 1\n"
  ": RANGE Qsum : for POINT_PROCESS. Gets additions from dipole\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(nA) = (nanoamp)\n"
  "	(mV) =(millivolt)\n"
  "	(Mohm) = (megaohm)\n"
  "	(um) = (micrometer)\n"
  "	(Am)= (amp meter)\n"
  "	(fAm) = (femto amp meter)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	ia (nA)\n"
  "	ri (Mohm)\n"
  "	pv (mV)\n"
  "	v (mV)\n"
  "	ztan (um)\n"
  "	Q  (fAm)\n"
  "	Qsum (fAm) :human dipole order of 10nAm\n"
  "}\n"
  "\n"
  "AFTER SOLVE {     	: solve for v's first then use them\n"
  "	ia=(pv-v)/ri\n"
  "	Q=ia*ztan\n"
  "	Qsum = Qsum + Q\n"
  "}\n"
  "	\n"
  "AFTER INITIAL {\n"
  "	ia=(pv-v)/ri\n"
  "	Q=ia*ztan\n"
  "	Qsum = Qsum + Q\n"
  "}\n"
  "\n"
  ": following needed for POINT_PROCESS only but will work if also in SUFFIX\n"
  ": BEFORE INITIAL {\n"
  ":	Qsum = 0\n"
  ": }\n"
  ": BEFORE BREAKPOINT {\n"
  ":	Qsum = 0\n"
  ": }\n"
  "\n"
  ;
#endif
