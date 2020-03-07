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
 
#define nrn_init _nrn_init__DPRESYN
#define _nrn_initial _nrn_initial__DPRESYN
#define nrn_cur _nrn_cur__DPRESYN
#define _nrn_current _nrn_current__DPRESYN
#define nrn_jacob _nrn_jacob__DPRESYN
#define nrn_state _nrn_state__DPRESYN
#define _net_receive _net_receive__DPRESYN 
#define clean clean__DPRESYN 
#define newspike newspike__DPRESYN 
#define pp pp__DPRESYN 
#define prq prq__DPRESYN 
#define preinit preinit__DPRESYN 
 
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
#define in _p[0]
#define x _p[1]
#define nsyn _p[2]
#define link _p[3]
#define times (_p + 4)
#define maxsyn _p[104]
#define _g _p[105]
#define _nd_area  *_ppvar[0]._pval
 
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
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_code();
 static double _hoc_check();
 static double _hoc_clean();
 static double _hoc_delay();
 static double _hoc_newspike();
 static double _hoc_pp();
 static double _hoc_prq();
 static double _hoc_post();
 static double _hoc_pre();
 static double _hoc_preinit();
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

 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "code", _hoc_code,
 "check", _hoc_check,
 "clean", _hoc_clean,
 "delay", _hoc_delay,
 "newspike", _hoc_newspike,
 "pp", _hoc_pp,
 "prq", _hoc_prq,
 "post", _hoc_post,
 "pre", _hoc_pre,
 "preinit", _hoc_preinit,
 0, 0
};
#define code code_DPRESYN
#define check check_DPRESYN
#define delay delay_DPRESYN
#define post post_DPRESYN
#define pre pre_DPRESYN
 extern double code( );
 extern double check( );
 extern double delay( );
 extern double post( );
 extern double pre( );
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 0,0
};
 static double delta_t = 1;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
 static void _destructor(Prop*);
 static void _constructor(Prop*);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"DPRESYN",
 "in",
 "x",
 "nsyn",
 "link",
 0,
 "times[100]",
 "maxsyn",
 0,
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 106, _prop);
 	/*initialize range parameters*/
 	in = 0;
 	x = 0;
 	nsyn = 0;
 	link = 0;
  }
 	_prop->param = _p;
 	_prop->param_size = 106;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 2, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 if (!nrn_point_prop_) {_constructor(_prop);}
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _dpresyn_reg() {
	int _vectorized = 0;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 0,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 	register_destructor(_destructor);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 106, 2);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
 	hoc_register_cvode(_mechtype, _ode_count, 0, 0, 0);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 DPRESYN /home/mizzou/Desktop/ff_BL_addIL/replacehumancell/BMTK/biophys_components/mechanisms/modfiles/x86_64/dpresyn.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int clean();
static int newspike();
static int pp();
static int prq(double);
static int preinit();
 
/*VERBATIM*/

#define PSTCAST ((SynS *)((unsigned long) lpst))
#define QUECAST ((QueU *)((unsigned long) queu))
#define PRECAST ((PreL *)((unsigned long) link))
#define QPRCAST ((QptR *)((unsigned long) qptr))

#define PREINC  50.  /* size increment for growing the presyn array */
#define POSTINC 5.   /* size increment for growing the postsyn array */

typedef struct QueU { /* postsynaptic queue */
  double time;  /* records spike time + delay */
  short index;  /* records index of associated SynS struct */
} QueU;

/* holds all the info for accessing the queu and its tail */
typedef struct QptR {
  struct QueU *qq;     /* will point to the queu */
  double *nspk; /* will point to newspk */
  double *head; /* will point to begsyn */
  double *qln;  /* points to qlen */
  double dead;  /* Cdur + Deadtime */
  double qterm;  /* the last time put on this queue */
  int cpost;  /* user code for info about postsyn cell */
} QptR;

typedef struct SynS { /* postsynaptic structure */
  /* this stuff used presynaptically */
  short index;  /* index of this item */
  double del;   /* param: individualized delay set by user */
  double spkt;  /* state: time when next spike can begin */
  struct QptR *qpt;   /* indirection to get at the queu */

  /* for allowing mult spikes to add up */
  short chainlen;
  short chainptr;

  /* user codes */
  int ucode;  /* user code for user convenience, an arbitrary index */
  /* this stuff used postsynaptically */
  double pgm;   /* percent of gmax - set by user */
  double Rcurr; /* holds current value of R (release status), internal */
  double last;  /* time last syn will end, internal */
  int *pcpre;   /* pointer to access the presyn code */
  struct SynS **back;  /* pointer to presyn pointer to this entry */
} SynS;

/* holds all the info for accessing presyn list */
typedef struct PreL {
  struct SynS **plst;        /* will point to post for postsyn nrn*/
  double *nnpre;     /* number of pointers currently there */
  double *mxpre;     /* number permitted before realloc required */
  double link2;       /* a copy of the link information to confirm correct hook up */
  int cpre;   /* user code for info about presyn cell */
} PreL;

 
static int  preinit (  ) {
    return 0; }
 
static double _hoc_preinit(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 preinit (  );
 return(_r);
}
 
static int  newspike (  ) {
   
/*VERBATIM*/
{ 
  int ii, jj, nspk, qend, head, ind, swapi;
  double time, swapt;
  SynS *psyn;		/* pointer to the presynaptic structure */
  QptR *qpr;
  QueU *qp;		/* pointer to the head position in postsyn queu */

  for (ii=0; ii<nsyn;ii++) { 

    /* psyn is the pointer back to the postsyn info array (struct SynS) */
    if ((psyn = PRECAST->plst[ii])==(SynS *)NULL ||     /* skip empties */
	(t < psyn->spkt && psyn->chainlen == 1)) {   /* skip if still on last one */
      continue; }
    /* are we chaining synapses? : this means that we will treat additional spks as */
    /* if they were coming from another synapse */
    if (psyn->chainlen > 1) {
      psyn->chainptr++;  /* augment the pointer */
      if (psyn->chainptr >= psyn->chainlen) { /* have run out of room */
	if (t < psyn->spkt) {  /* can't reset yet so just drop this spk */
	  continue;
	} else {               /* the whole chain is completely done so can reset */
	  psyn->chainptr = 0; }
      }
      ind = psyn->index + psyn->chainptr; /* add index of next one on chain */
    } else {
      ind = psyn->index;
    }

    /* qpr = the post-syn queu pointer */
    qpr = psyn->qpt;  
    /* qp = pointer to postsyn queu */
    qp = qpr->qq;
    nspk = (int)(*(qpr->nspk));
    time = t + psyn->del;
    psyn->spkt = t + qpr->dead; /* when it will all end */

    /* basic queu code taken from queu.inc (viz.) but now must make sure */
    /* that we don't go backwards in time (different delays) */
    /* should have been cleared if we are to write here */
    if (qp[nspk].time != 1e20) { //  -- REMOVED THIS ERROR!!
      printf("WARNING: QUEUE ANOMALY: %x %g %g ",qpr->qq,*(qpr->nspk),*(qpr->qln));
      // hoc_execerror("Error: queue full.\n",0);
    }
    if (qpr->qterm < time) {	/* queu marching forward in time: AOK */
	/* push the two queu items: a time and an index */
	(qp[nspk]).time = time; /* delay */
	(qp[nspk]).index = ind; /* tell postsyn which presyn spiked */
	qpr->qterm = time;	/* keep track of largest time put on */
    } else {			/* move backward to insert in right place */
	/* actually a heap rather than a queue since maintains order */
	qend = (int)(*(qpr->qln)) - 1; /* max ind for queu */
	head = (int)(*(qpr->head)) - 1; /* one in front of the head */
	if (head == -1) { head = qend; } /* wrap around */
	/* search backward */
	for (jj=((nspk==0)?qend:nspk-1);
	     time < qp[jj].time && jj != head;
	     jj=((jj==0)?qend:jj-1)); /* skip over from end */
	if (jj==nspk) { 
	  printf("%g %d %d ",qpr->qterm,ii,jj);
	  hoc_execerror("ERROR: newspike search failed.\n",0); }
	/* move things forward */
	for (jj=((jj==qend)?0:jj+1); /* start one up */
	     jj != nspk;	/* till back where we were */
	     jj=((jj==qend)?0:jj+1)) {
	  swapt = qp[jj].time;	/* store temporarily */
	  swapi = qp[jj].index;
	  qp[jj].time = time;	/* put in the new one */
	  qp[jj].index = ind;
	  time = swapt;		/* swap them */
	  ind = swapi;
	}
	qp[jj].time = time;
	qp[jj].index = ind;
      }

      /* move the tail forward and reset if reached the end */
      (*(qpr->nspk))++;
      if ((*(qpr->nspk)) == *(qpr->qln)) { (*(qpr->nspk)) = 0.; 
        printf("Cycling around for %x\n",qpr->qq);}

  }
  }
  return 0; }
 
static double _hoc_newspike(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 newspike (  );
 return(_r);
}
 
static int  clean (  ) {
   
/*VERBATIM*/
{ 
    int ii,jj,newn;
    SynS** pl;
    pl = PRECAST->plst;

    for(ii=0,jj=0,newn=nsyn; ii<nsyn; ii++,jj++) {
      while (pl[ii] == (SynS *)NULL && ii<nsyn) {
	ii++; newn--; 
      }
      if (ii != jj && ii<nsyn) {
	pl[jj] = pl[ii];
	pl[jj]->back = &(pl[jj]);
      }
    }
    nsyn = newn;
  }
  return 0; }
 
static double _hoc_clean(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 clean (  );
 return(_r);
}
 
double check (  ) {
   double _lcheck;
 
/*VERBATIM*/
{ 
    int ii;
    for (ii=0,_lcheck=0; ii<nsyn && _lcheck!=-1.; ii++) {
      if (PRECAST->plst[ii] != (SynS *)NULL) {
	_lcheck++;  /* count the active pointers */
	if ((&(PRECAST->plst[ii])) != (PRECAST->plst[ii]->back)) {
	  printf("****************************************************************\n");
	  printf("ERROR:: %2d: Index:%3d,C%09d,Pr%09d,Po%09d, Delay:%6g (%x->%x->%x)\n",
		 ii,
		 PRECAST->plst[(int)ii]->index,
		 PRECAST->plst[(int)ii]->ucode,
		 PRECAST->cpre,
		 PRECAST->plst[(int)ii]->qpt->cpost,
		 PRECAST->plst[(int)ii]->del,
		 &(PRECAST->plst[(int)ii]),
		 PRECAST->plst[(int)ii],
		 (PRECAST->plst[(int)ii]->back));
	  printf("****************************************************************\n");
	  _lcheck = -1.0;
	}
      }
    } 
  }
 
return _lcheck;
 }
 
static double _hoc_check(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  check (  );
 return(_r);
}
 
double code (  ) {
   double _lcode;
 
/*VERBATIM*/
{ int ii;
    if (ifarg(1)) {
      ii = (int)*getarg(1);
      if (ii < 0) { ii = nsyn+ii; }
      if (ii >= nsyn || ii < 0) {hoc_execerror("array index out of bounds", 0);}
      _lcode = ((PRECAST->plst[ii] == (SynS *)NULL)?-2:PRECAST->plst[ii]->ucode);
    } else {
      for (ii=0;ii<nsyn;ii++) {
	if (PRECAST->plst[ii] == (SynS *)NULL) {
	  printf("%d EMPTY.\n",ii);
	} else { 
	  printf("%d,%09d  ",ii,PRECAST->plst[ii]->ucode);
        }
      }
      _lcode = 1.0;
    }
  } 
 
return _lcode;
 }
 
static double _hoc_code(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  code (  );
 return(_r);
}
 
double delay (  ) {
   double _ldelay;
 
/*VERBATIM*/
{ int ii;
    if (ifarg(1)) {
      ii = (int)*getarg(1);
      if (ii < 0) { ii = nsyn+ii; }
      if (ii >= nsyn || ii < 0) {hoc_execerror("array index out of bounds", 0);}
      _ldelay = ((PRECAST->plst[ii] == (SynS *)NULL)?-2:PRECAST->plst[ii]->del);
    } else {
      for (ii=0;ii<nsyn;ii++) {
	if (PRECAST->plst[ii] == (SynS *)NULL) {
	  printf("%d EMPTY.\n",ii);
	} else { 
	  printf("%d,%g  ",ii,PRECAST->plst[ii]->del);
        }
      }
      _ldelay = 1.0;
    }
  } 
 
return _ldelay;
 }
 
static double _hoc_delay(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  delay (  );
 return(_r);
}
 
double pre (  ) {
   double _lpre;
 
/*VERBATIM*/
{
    if (ifarg(2)) { PRECAST->cpre = (int)*getarg(2); }
    _lpre = PRECAST->cpre;
  } 
 
return _lpre;
 }
 
static double _hoc_pre(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  pre (  );
 return(_r);
}
 
double post (  ) {
   double _lpost;
 
/*VERBATIM*/
{ int xx,ii;
    xx = -2;
    if (ifarg(1)) { xx = (int)*getarg(1); }
    if (xx >= 0) {
      if (xx >= nsyn) {hoc_execerror("array index out of bounds", 0);}
      _lpost = ((PRECAST->plst[xx] == (SynS *)NULL)?-2:PRECAST->plst[xx]->qpt->cpost);
    } else {
      for (ii=0;ii<nsyn;ii++) {
	if (PRECAST->plst[ii] == (SynS *)NULL) {
	  printf("%2d EMPTY.\n",ii);
	} else { 
	  printf("%1d (%1d) Del:%-4g Cd:%09d Pre:%09d Post:%09d\n",
		 ii,
		 PRECAST->plst[ii]->index,
		 PRECAST->plst[ii]->del,
		 PRECAST->plst[ii]->ucode,
		 PRECAST->cpre,
		 PRECAST->plst[ii]->qpt->cpost);
	  if (xx == -1 || (&(PRECAST->plst[ii])) != (PRECAST->plst[ii]->back)) {
	    printf("\t\t%s: %x -> %x\n",
		   (((&(PRECAST->plst[ii]))==(PRECAST->plst[ii]->back))?
		    "OK":"POINTER MISMATCH"),
		   &(PRECAST->plst[ii]),
		   PRECAST->plst[ii]);
	  }
	}
      }
      _lpost = 1.0;
    }
  } 
 
return _lpost;
 }
 
static double _hoc_post(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r =  post (  );
 return(_r);
}
 
static int  prq (  double _lx ) {
   
/*VERBATIM*/
{ int ii;
    SynS *psyn;		
    QptR *qpr;
    psyn = PRECAST->plst[(int)_lx];
    qpr = psyn->qpt;  
    printf("%x %g %g\n",qpr->qq,*(qpr->nspk),*(qpr->qln));
    for (ii=0;ii<*(qpr->qln);ii++) {
      printf("%8g%8d\n",
	     ((qpr->qq)[ii]).time,
	     ((qpr->qq)[ii]).index);
   }
  } 
  return 0; }
 
static double _hoc_prq(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 prq (  *getarg(1) );
 return(_r);
}
 
static int  pp (  ) {
   
/*VERBATIM*/
  x = fabs(times[(int)in]-t);
 if ( x < 0.05 ) {
     newspike ( _threadargs_ ) ;
     in = in + 1.0 ;
     }
    return 0; }
 
static double _hoc_pp(void* _vptr) {
 double _r;
    _hoc_setdata(_vptr);
 _r = 1.;
 pp (  );
 return(_r);
}
 
static int _ode_count(int _type){ hoc_execerror("DPRESYN", "cannot be used with CVODE"); return 0;}
 
static void _constructor(Prop* _prop) {
	_p = _prop->param; _ppvar = _prop->dparam;
{
 {
   
/*VERBATIM*/
{
    /* link allows postsyn cell to manipulate presyn list */
    link = (double)((unsigned long)hoc_Ecalloc(1, sizeof(PreL))); hoc_malchk();
    PRECAST->link2  = link;  /* this can be queried to protect against error */
    PRECAST->nnpre = &nsyn;
    PRECAST->mxpre = &maxsyn;
    nsyn = 0.;
    maxsyn = 0.;
    if (ifarg(2)) { 
      PRECAST->cpre = (int)*getarg(2);
    } else { PRECAST->cpre = -1; }
 } 
 }
 
}
}
 
static void _destructor(Prop* _prop) {
	_p = _prop->param; _ppvar = _prop->dparam;
{
 {
   
/*VERBATIM*/
{ 
      nsyn = maxsyn = 0;
      free(PRECAST);
      link = 0;
  }
 }
 
}
}

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
 {
   in = 0.0 ;
   x = 0.0 ;
   }
  _sav_indep = t; t = _save;

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

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
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
 
}}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

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
 { error =  pp();
 if(error){fprintf(stderr,"at line 31 in file dpresyn.mod:\n  SOLVE pp\n"); nrn_complain(_p); abort_run(error);}
 } {
   }
}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/home/mizzou/Desktop/ff_BL_addIL/replacehumancell/BMTK/biophys_components/mechanisms/modfiles/dpresyn.mod";
static const char* nmodl_file_text = 
  ": Modified from presyn.mod for dummy lgn cell\n"
  "\n"
  "COMMENT\n"
  "calls newspike() if spike occurs\n"
  "ENDCOMMENT\n"
  "\n"
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "NEURON {\n"
  "  POINT_PROCESS DPRESYN\n"
  "  RANGE in, times, x\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "  times[100]\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "  in = 0\n"
  "  x = 0\n"
  "}\n"
  "\n"
  ":::INCLUDE \"presyn.inc\"\n"
  ":::realpath /home/mizzou/Desktop/ff_BL_addIL/replacehumancell/BMTK/biophys_components/mechanisms/modfiles/presyn.inc\n"
  ": $Id: presyn.inc,v 1.4 2005/04/12 05:32:04 billl Exp $\n"
  "\n"
  "NEURON {\n"
  "  RANGE maxsyn, nsyn                         : scalars\n"
  "  RANGE link                              : PreL structure\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "  nsyn = 0\n"
  "  link = 0       : presyn struct points to list of pointers to postsyn cells\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "  maxsyn        : max and counter for the list of pointers\n"
  "}\n"
  "\n"
  ":::INCLUDE \"snshead.inc\"\n"
  ":::realpath /home/mizzou/Desktop/ff_BL_addIL/replacehumancell/BMTK/biophys_components/mechanisms/modfiles/snshead.inc\n"
  ": $Id: snshead.inc,v 1.21 1995/10/25 20:19:52 billl Exp $\n"
  "\n"
  "VERBATIM\n"
  "\n"
  "#define PSTCAST ((SynS *)((unsigned long) lpst))\n"
  "#define QUECAST ((QueU *)((unsigned long) queu))\n"
  "#define PRECAST ((PreL *)((unsigned long) link))\n"
  "#define QPRCAST ((QptR *)((unsigned long) qptr))\n"
  "\n"
  "#define PREINC  50.  /* size increment for growing the presyn array */\n"
  "#define POSTINC 5.   /* size increment for growing the postsyn array */\n"
  "\n"
  "typedef struct QueU { /* postsynaptic queue */\n"
  "  double time;  /* records spike time + delay */\n"
  "  short index;  /* records index of associated SynS struct */\n"
  "} QueU;\n"
  "\n"
  "/* holds all the info for accessing the queu and its tail */\n"
  "typedef struct QptR {\n"
  "  struct QueU *qq;     /* will point to the queu */\n"
  "  double *nspk; /* will point to newspk */\n"
  "  double *head; /* will point to begsyn */\n"
  "  double *qln;  /* points to qlen */\n"
  "  double dead;  /* Cdur + Deadtime */\n"
  "  double qterm;  /* the last time put on this queue */\n"
  "  int cpost;  /* user code for info about postsyn cell */\n"
  "} QptR;\n"
  "\n"
  "typedef struct SynS { /* postsynaptic structure */\n"
  "  /* this stuff used presynaptically */\n"
  "  short index;  /* index of this item */\n"
  "  double del;   /* param: individualized delay set by user */\n"
  "  double spkt;  /* state: time when next spike can begin */\n"
  "  struct QptR *qpt;   /* indirection to get at the queu */\n"
  "\n"
  "  /* for allowing mult spikes to add up */\n"
  "  short chainlen;\n"
  "  short chainptr;\n"
  "\n"
  "  /* user codes */\n"
  "  int ucode;  /* user code for user convenience, an arbitrary index */\n"
  "  /* this stuff used postsynaptically */\n"
  "  double pgm;   /* percent of gmax - set by user */\n"
  "  double Rcurr; /* holds current value of R (release status), internal */\n"
  "  double last;  /* time last syn will end, internal */\n"
  "  int *pcpre;   /* pointer to access the presyn code */\n"
  "  struct SynS **back;  /* pointer to presyn pointer to this entry */\n"
  "} SynS;\n"
  "\n"
  "/* holds all the info for accessing presyn list */\n"
  "typedef struct PreL {\n"
  "  struct SynS **plst;        /* will point to post for postsyn nrn*/\n"
  "  double *nnpre;     /* number of pointers currently there */\n"
  "  double *mxpre;     /* number permitted before realloc required */\n"
  "  double link2;       /* a copy of the link information to confirm correct hook up */\n"
  "  int cpre;   /* user code for info about presyn cell */\n"
  "} PreL;\n"
  "\n"
  "ENDVERBATIM\n"
  ":::end INCLUDE snshead.inc\n"
  "\n"
  "CONSTRUCTOR {\n"
  "  VERBATIM {\n"
  "    /* link allows postsyn cell to manipulate presyn list */\n"
  "    link = (double)((unsigned long)hoc_Ecalloc(1, sizeof(PreL))); hoc_malchk();\n"
  "    PRECAST->link2  = link;  /* this can be queried to protect against error */\n"
  "    PRECAST->nnpre = &nsyn;\n"
  "    PRECAST->mxpre = &maxsyn;\n"
  "    nsyn = 0.;\n"
  "    maxsyn = 0.;\n"
  "    if (ifarg(2)) { \n"
  "      PRECAST->cpre = (int)*getarg(2);\n"
  "    } else { PRECAST->cpre = -1; }\n"
  " } \n"
  " ENDVERBATIM\n"
  "}\n"
  "\n"
  "DESTRUCTOR {\n"
  "  VERBATIM { \n"
  "      nsyn = maxsyn = 0;\n"
  "      free(PRECAST);\n"
  "      link = 0;\n"
  "  }\n"
  "  ENDVERBATIM\n"
  "}\n"
  "\n"
  "PROCEDURE preinit () {}\n"
  "\n"
  ": globally used presynaptically to add to queue (was called pushqueu())\n"
  "PROCEDURE newspike() {\n"
  "VERBATIM { \n"
  "  int ii, jj, nspk, qend, head, ind, swapi;\n"
  "  double time, swapt;\n"
  "  SynS *psyn;		/* pointer to the presynaptic structure */\n"
  "  QptR *qpr;\n"
  "  QueU *qp;		/* pointer to the head position in postsyn queu */\n"
  "\n"
  "  for (ii=0; ii<nsyn;ii++) { \n"
  "\n"
  "    /* psyn is the pointer back to the postsyn info array (struct SynS) */\n"
  "    if ((psyn = PRECAST->plst[ii])==(SynS *)NULL ||     /* skip empties */\n"
  "	(t < psyn->spkt && psyn->chainlen == 1)) {   /* skip if still on last one */\n"
  "      continue; }\n"
  "    /* are we chaining synapses? : this means that we will treat additional spks as */\n"
  "    /* if they were coming from another synapse */\n"
  "    if (psyn->chainlen > 1) {\n"
  "      psyn->chainptr++;  /* augment the pointer */\n"
  "      if (psyn->chainptr >= psyn->chainlen) { /* have run out of room */\n"
  "	if (t < psyn->spkt) {  /* can't reset yet so just drop this spk */\n"
  "	  continue;\n"
  "	} else {               /* the whole chain is completely done so can reset */\n"
  "	  psyn->chainptr = 0; }\n"
  "      }\n"
  "      ind = psyn->index + psyn->chainptr; /* add index of next one on chain */\n"
  "    } else {\n"
  "      ind = psyn->index;\n"
  "    }\n"
  "\n"
  "    /* qpr = the post-syn queu pointer */\n"
  "    qpr = psyn->qpt;  \n"
  "    /* qp = pointer to postsyn queu */\n"
  "    qp = qpr->qq;\n"
  "    nspk = (int)(*(qpr->nspk));\n"
  "    time = t + psyn->del;\n"
  "    psyn->spkt = t + qpr->dead; /* when it will all end */\n"
  "\n"
  "    /* basic queu code taken from queu.inc (viz.) but now must make sure */\n"
  "    /* that we don't go backwards in time (different delays) */\n"
  "    /* should have been cleared if we are to write here */\n"
  "    if (qp[nspk].time != 1e20) { //  -- REMOVED THIS ERROR!!\n"
  "      printf(\"WARNING: QUEUE ANOMALY: %x %g %g \",qpr->qq,*(qpr->nspk),*(qpr->qln));\n"
  "      // hoc_execerror(\"Error: queue full.\\n\",0);\n"
  "    }\n"
  "    if (qpr->qterm < time) {	/* queu marching forward in time: AOK */\n"
  "	/* push the two queu items: a time and an index */\n"
  "	(qp[nspk]).time = time; /* delay */\n"
  "	(qp[nspk]).index = ind; /* tell postsyn which presyn spiked */\n"
  "	qpr->qterm = time;	/* keep track of largest time put on */\n"
  "    } else {			/* move backward to insert in right place */\n"
  "	/* actually a heap rather than a queue since maintains order */\n"
  "	qend = (int)(*(qpr->qln)) - 1; /* max ind for queu */\n"
  "	head = (int)(*(qpr->head)) - 1; /* one in front of the head */\n"
  "	if (head == -1) { head = qend; } /* wrap around */\n"
  "	/* search backward */\n"
  "	for (jj=((nspk==0)?qend:nspk-1);\n"
  "	     time < qp[jj].time && jj != head;\n"
  "	     jj=((jj==0)?qend:jj-1)); /* skip over from end */\n"
  "	if (jj==nspk) { \n"
  "	  printf(\"%g %d %d \",qpr->qterm,ii,jj);\n"
  "	  hoc_execerror(\"ERROR: newspike search failed.\\n\",0); }\n"
  "	/* move things forward */\n"
  "	for (jj=((jj==qend)?0:jj+1); /* start one up */\n"
  "	     jj != nspk;	/* till back where we were */\n"
  "	     jj=((jj==qend)?0:jj+1)) {\n"
  "	  swapt = qp[jj].time;	/* store temporarily */\n"
  "	  swapi = qp[jj].index;\n"
  "	  qp[jj].time = time;	/* put in the new one */\n"
  "	  qp[jj].index = ind;\n"
  "	  time = swapt;		/* swap them */\n"
  "	  ind = swapi;\n"
  "	}\n"
  "	qp[jj].time = time;\n"
  "	qp[jj].index = ind;\n"
  "      }\n"
  "\n"
  "      /* move the tail forward and reset if reached the end */\n"
  "      (*(qpr->nspk))++;\n"
  "      if ((*(qpr->nspk)) == *(qpr->qln)) { (*(qpr->nspk)) = 0.; \n"
  "        printf(\"Cycling around for %x\\n\",qpr->qq);}\n"
  "\n"
  "  }\n"
  "  }\n"
  "ENDVERBATIM\n"
  "}\n"
  "\n"
  ": eliminates empty pointers in presyn array, moving everything else down\n"
  "PROCEDURE clean() {\n"
  "  VERBATIM { \n"
  "    int ii,jj,newn;\n"
  "    SynS** pl;\n"
  "    pl = PRECAST->plst;\n"
  "\n"
  "    for(ii=0,jj=0,newn=nsyn; ii<nsyn; ii++,jj++) {\n"
  "      while (pl[ii] == (SynS *)NULL && ii<nsyn) {\n"
  "	ii++; newn--; \n"
  "      }\n"
  "      if (ii != jj && ii<nsyn) {\n"
  "	pl[jj] = pl[ii];\n"
  "	pl[jj]->back = &(pl[jj]);\n"
  "      }\n"
  "    }\n"
  "    nsyn = newn;\n"
  "  }\n"
  "  ENDVERBATIM\n"
  "}\n"
  "\n"
  ": prints out some selected information from the presyn structure, synlist\n"
  "FUNCTION check() {\n"
  "  VERBATIM { \n"
  "    int ii;\n"
  "    for (ii=0,_lcheck=0; ii<nsyn && _lcheck!=-1.; ii++) {\n"
  "      if (PRECAST->plst[ii] != (SynS *)NULL) {\n"
  "	_lcheck++;  /* count the active pointers */\n"
  "	if ((&(PRECAST->plst[ii])) != (PRECAST->plst[ii]->back)) {\n"
  "	  printf(\"****************************************************************\\n\");\n"
  "	  printf(\"ERROR:: %2d: Index:%3d,C%09d,Pr%09d,Po%09d, Delay:%6g (%x->%x->%x)\\n\",\n"
  "		 ii,\n"
  "		 PRECAST->plst[(int)ii]->index,\n"
  "		 PRECAST->plst[(int)ii]->ucode,\n"
  "		 PRECAST->cpre,\n"
  "		 PRECAST->plst[(int)ii]->qpt->cpost,\n"
  "		 PRECAST->plst[(int)ii]->del,\n"
  "		 &(PRECAST->plst[(int)ii]),\n"
  "		 PRECAST->plst[(int)ii],\n"
  "		 (PRECAST->plst[(int)ii]->back));\n"
  "	  printf(\"****************************************************************\\n\");\n"
  "	  _lcheck = -1.0;\n"
  "	}\n"
  "      }\n"
  "    } \n"
  "  }\n"
  "  ENDVERBATIM\n"
  "}\n"
  "\n"
  ": return ucode\n"
  "FUNCTION code() {\n"
  "  VERBATIM { int ii;\n"
  "    if (ifarg(1)) {\n"
  "      ii = (int)*getarg(1);\n"
  "      if (ii < 0) { ii = nsyn+ii; }\n"
  "      if (ii >= nsyn || ii < 0) {hoc_execerror(\"array index out of bounds\", 0);}\n"
  "      _lcode = ((PRECAST->plst[ii] == (SynS *)NULL)?-2:PRECAST->plst[ii]->ucode);\n"
  "    } else {\n"
  "      for (ii=0;ii<nsyn;ii++) {\n"
  "	if (PRECAST->plst[ii] == (SynS *)NULL) {\n"
  "	  printf(\"%d EMPTY.\\n\",ii);\n"
  "	} else { \n"
  "	  printf(\"%d,%09d  \",ii,PRECAST->plst[ii]->ucode);\n"
  "        }\n"
  "      }\n"
  "      _lcode = 1.0;\n"
  "    }\n"
  "  } \n"
  "  ENDVERBATIM\n"
  "}\n"
  "\n"
  ": return delay\n"
  "FUNCTION delay() {\n"
  "  VERBATIM { int ii;\n"
  "    if (ifarg(1)) {\n"
  "      ii = (int)*getarg(1);\n"
  "      if (ii < 0) { ii = nsyn+ii; }\n"
  "      if (ii >= nsyn || ii < 0) {hoc_execerror(\"array index out of bounds\", 0);}\n"
  "      _ldelay = ((PRECAST->plst[ii] == (SynS *)NULL)?-2:PRECAST->plst[ii]->del);\n"
  "    } else {\n"
  "      for (ii=0;ii<nsyn;ii++) {\n"
  "	if (PRECAST->plst[ii] == (SynS *)NULL) {\n"
  "	  printf(\"%d EMPTY.\\n\",ii);\n"
  "	} else { \n"
  "	  printf(\"%d,%g  \",ii,PRECAST->plst[ii]->del);\n"
  "        }\n"
  "      }\n"
  "      _ldelay = 1.0;\n"
  "    }\n"
  "  } \n"
  "  ENDVERBATIM\n"
  "}\n"
  "\n"
  ": return or set cpre code\n"
  "FUNCTION pre() {\n"
  "  VERBATIM {\n"
  "    if (ifarg(2)) { PRECAST->cpre = (int)*getarg(2); }\n"
  "    _lpre = PRECAST->cpre;\n"
  "  } \n"
  "  ENDVERBATIM\n"
  "}\n"
  "\n"
  ": return cpost code\n"
  ": 0 arg: prints out information from the postsyn structure\n"
  ": 1 arg = -1 print out the pointer structure\n"
  ": plst[i] remains only indication of eliminated pointer\n"
  "FUNCTION post() {\n"
  "  VERBATIM { int xx,ii;\n"
  "    xx = -2;\n"
  "    if (ifarg(1)) { xx = (int)*getarg(1); }\n"
  "    if (xx >= 0) {\n"
  "      if (xx >= nsyn) {hoc_execerror(\"array index out of bounds\", 0);}\n"
  "      _lpost = ((PRECAST->plst[xx] == (SynS *)NULL)?-2:PRECAST->plst[xx]->qpt->cpost);\n"
  "    } else {\n"
  "      for (ii=0;ii<nsyn;ii++) {\n"
  "	if (PRECAST->plst[ii] == (SynS *)NULL) {\n"
  "	  printf(\"%2d EMPTY.\\n\",ii);\n"
  "	} else { \n"
  "	  printf(\"%1d (%1d) Del:%-4g Cd:%09d Pre:%09d Post:%09d\\n\",\n"
  "		 ii,\n"
  "		 PRECAST->plst[ii]->index,\n"
  "		 PRECAST->plst[ii]->del,\n"
  "		 PRECAST->plst[ii]->ucode,\n"
  "		 PRECAST->cpre,\n"
  "		 PRECAST->plst[ii]->qpt->cpost);\n"
  "	  if (xx == -1 || (&(PRECAST->plst[ii])) != (PRECAST->plst[ii]->back)) {\n"
  "	    printf(\"\\t\\t%s: %x -> %x\\n\",\n"
  "		   (((&(PRECAST->plst[ii]))==(PRECAST->plst[ii]->back))?\n"
  "		    \"OK\":\"POINTER MISMATCH\"),\n"
  "		   &(PRECAST->plst[ii]),\n"
  "		   PRECAST->plst[ii]);\n"
  "	  }\n"
  "	}\n"
  "      }\n"
  "      _lpost = 1.0;\n"
  "    }\n"
  "  } \n"
  "  ENDVERBATIM\n"
  "}\n"
  "\n"
  ": for debugging - prints out queu info from the pre side\n"
  "PROCEDURE prq(x) {\n"
  "  VERBATIM { int ii;\n"
  "    SynS *psyn;		\n"
  "    QptR *qpr;\n"
  "    psyn = PRECAST->plst[(int)_lx];\n"
  "    qpr = psyn->qpt;  \n"
  "    printf(\"%x %g %g\\n\",qpr->qq,*(qpr->nspk),*(qpr->qln));\n"
  "    for (ii=0;ii<*(qpr->qln);ii++) {\n"
  "      printf(\"%8g%8d\\n\",\n"
  "	     ((qpr->qq)[ii]).time,\n"
  "	     ((qpr->qq)[ii]).index);\n"
  "   }\n"
  "  } \n"
  "  ENDVERBATIM\n"
  "}\n"
  "\n"
  ":::end INCLUDE presyn.inc\n"
  "\n"
  "INITIAL {\n"
  "  in = 0\n"
  "  x = 0\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "  SOLVE pp\n"
  "}\n"
  "\n"
  "PROCEDURE pp() {\n"
  "VERBATIM\n"
  "  x = fabs(times[(int)in]-t);\n"
  "ENDVERBATIM\n"
  "  if (x < 0.05) {\n"
  "      newspike()\n"
  "      in = in + 1\n"
  "    }\n"
  "}\n"
  ;
#endif
