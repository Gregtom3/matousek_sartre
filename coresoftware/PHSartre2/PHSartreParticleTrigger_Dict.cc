//
// File generated by rootcint at Sun Feb 24 22:12:34 2019

// Do NOT change. Changes will be lost next time file is generated
//

#define R__DICTIONARY_FILENAME PHSartreParticleTrigger_Dict
#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "PHSartreParticleTrigger_Dict.h"

#include "TClass.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"

// Direct notice to TROOT of the dictionary's loading.
namespace {
   static struct DictInit {
      DictInit() {
         ROOT::RegisterModule();
      }
   } __TheDictionaryInitializer;
}

// START OF SHADOWS

namespace ROOTShadow {
   namespace Shadow {
   } // of namespace Shadow
} // of namespace ROOTShadow
// END OF SHADOWS

namespace ROOTDict {
   void PHSartreParticleTrigger_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void PHSartreParticleTrigger_Dictionary();
   static void *new_PHSartreParticleTrigger(void *p = 0);
   static void *newArray_PHSartreParticleTrigger(Long_t size, void *p);
   static void delete_PHSartreParticleTrigger(void *p);
   static void deleteArray_PHSartreParticleTrigger(void *p);
   static void destruct_PHSartreParticleTrigger(void *p);

   // Function generating the singleton type initializer
   static ROOT::TGenericClassInfo *GenerateInitInstanceLocal(const ::PHSartreParticleTrigger*)
   {
      ::PHSartreParticleTrigger *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PHSartreParticleTrigger),0);
      static ::ROOT::TGenericClassInfo 
         instance("PHSartreParticleTrigger", "./PHSartreParticleTrigger.h", 11,
                  typeid(::PHSartreParticleTrigger), ::ROOT::DefineBehavior(ptr, ptr),
                  0, &PHSartreParticleTrigger_Dictionary, isa_proxy, 3,
                  sizeof(::PHSartreParticleTrigger) );
      instance.SetNew(&new_PHSartreParticleTrigger);
      instance.SetNewArray(&newArray_PHSartreParticleTrigger);
      instance.SetDelete(&delete_PHSartreParticleTrigger);
      instance.SetDeleteArray(&deleteArray_PHSartreParticleTrigger);
      instance.SetDestructor(&destruct_PHSartreParticleTrigger);
      return &instance;
   }
   ROOT::TGenericClassInfo *GenerateInitInstance(const ::PHSartreParticleTrigger*)
   {
      return GenerateInitInstanceLocal((::PHSartreParticleTrigger*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::PHSartreParticleTrigger*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void PHSartreParticleTrigger_Dictionary() {
      ::ROOTDict::GenerateInitInstanceLocal((const ::PHSartreParticleTrigger*)0x0)->GetClass();
   }

} // end of namespace ROOTDict

namespace ROOTDict {
   // Wrappers around operator new
   static void *new_PHSartreParticleTrigger(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::PHSartreParticleTrigger : new ::PHSartreParticleTrigger;
   }
   static void *newArray_PHSartreParticleTrigger(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::PHSartreParticleTrigger[nElements] : new ::PHSartreParticleTrigger[nElements];
   }
   // Wrapper around operator delete
   static void delete_PHSartreParticleTrigger(void *p) {
      delete ((::PHSartreParticleTrigger*)p);
   }
   static void deleteArray_PHSartreParticleTrigger(void *p) {
      delete [] ((::PHSartreParticleTrigger*)p);
   }
   static void destruct_PHSartreParticleTrigger(void *p) {
      typedef ::PHSartreParticleTrigger current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOTDict for class ::PHSartreParticleTrigger

/********************************************************
* PHSartreParticleTrigger_Dict.cc
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************/

#ifdef G__MEMTEST
#undef malloc
#undef free
#endif

#if defined(__GNUC__) && __GNUC__ >= 4 && ((__GNUC_MINOR__ == 2 && __GNUC_PATCHLEVEL__ >= 1) || (__GNUC_MINOR__ >= 3))
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif

extern "C" void G__cpp_reset_tagtablePHSartreParticleTrigger_Dict();

extern "C" void G__set_cpp_environmentPHSartreParticleTrigger_Dict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("PHSartreParticleTrigger.h");
  G__cpp_reset_tagtablePHSartreParticleTrigger_Dict();
}
#include <new>
extern "C" int G__cpp_dllrevPHSartreParticleTrigger_Dict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* PHSartreParticleTrigger */
static int G__PHSartreParticleTrigger_Dict_174_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   PHSartreParticleTrigger* p = NULL;
   char* gvp = (char*) G__getgvp();
   switch (libp->paran) {
   case 1:
     //m: 1
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new PHSartreParticleTrigger(*(string*) libp->para[0].ref);
     } else {
       p = new((void*) gvp) PHSartreParticleTrigger(*(string*) libp->para[0].ref);
     }
     break;
   case 0:
     int n = G__getaryconstruct();
     if (n) {
       if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
         p = new PHSartreParticleTrigger[n];
       } else {
         p = new((void*) gvp) PHSartreParticleTrigger[n];
       }
     } else {
       if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
         p = new PHSartreParticleTrigger;
       } else {
         p = new((void*) gvp) PHSartreParticleTrigger;
       }
     }
     break;
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_PHSartreParticleTrigger));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_3(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->AddParticles(*(string*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_4(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->AddParticles((int) G__int(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_5(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->AddParticles(*((vector<int>*) G__int(libp->para[0])));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_6(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetPtHigh((double) G__double(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_7(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetPtLow((double) G__double(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_8(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetPtHighLow((double) G__double(libp->para[0]), (double) G__double(libp->para[1]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_9(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetPHigh((double) G__double(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_10(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetPLow((double) G__double(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_11(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetPHighLow((double) G__double(libp->para[0]), (double) G__double(libp->para[1]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_12(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetEtaHigh((double) G__double(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_13(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetEtaLow((double) G__double(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_14(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetEtaHighLow((double) G__double(libp->para[0]), (double) G__double(libp->para[1]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_15(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetAbsEtaHigh((double) G__double(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_16(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetAbsEtaLow((double) G__double(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_17(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetAbsEtaHighLow((double) G__double(libp->para[0]), (double) G__double(libp->para[1]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_18(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetPzHigh((double) G__double(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_19(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetPzLow((double) G__double(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_20(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->SetPzHighLow((double) G__double(libp->para[0]), (double) G__double(libp->para[1]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartreParticleTrigger_Dict_174_0_21(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartreParticleTrigger*) G__getstructoffset())->PrintConfig();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic copy constructor
static int G__PHSartreParticleTrigger_Dict_174_0_22(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)

{
   PHSartreParticleTrigger* p;
   void* tmp = (void*) G__int(libp->para[0]);
   p = new PHSartreParticleTrigger(*(PHSartreParticleTrigger*) tmp);
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_PHSartreParticleTrigger));
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef PHSartreParticleTrigger G__TPHSartreParticleTrigger;
static int G__PHSartreParticleTrigger_Dict_174_0_23(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   char* gvp = (char*) G__getgvp();
   long soff = G__getstructoffset();
   int n = G__getaryconstruct();
   //
   //has_a_delete: 0
   //has_own_delete1arg: 0
   //has_own_delete2arg: 0
   //
   if (!soff) {
     return(1);
   }
   if (n) {
     if (gvp == (char*)G__PVOID) {
       delete[] (PHSartreParticleTrigger*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((PHSartreParticleTrigger*) (soff+(sizeof(PHSartreParticleTrigger)*i)))->~G__TPHSartreParticleTrigger();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (PHSartreParticleTrigger*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((PHSartreParticleTrigger*) (soff))->~G__TPHSartreParticleTrigger();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic assignment operator
static int G__PHSartreParticleTrigger_Dict_174_0_24(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   PHSartreParticleTrigger* dest = (PHSartreParticleTrigger*) G__getstructoffset();
   *dest = *(PHSartreParticleTrigger*) libp->para[0].ref;
   const PHSartreParticleTrigger& obj = *dest;
   result7->ref = (long) (&obj);
   result7->obj.i = (long) (&obj);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* PHSartreParticleTrigger */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncPHSartreParticleTrigger_Dict {
 public:
  G__Sizep2memfuncPHSartreParticleTrigger_Dict(): p(&G__Sizep2memfuncPHSartreParticleTrigger_Dict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncPHSartreParticleTrigger_Dict::*p)();
};

size_t G__get_sizep2memfuncPHSartreParticleTrigger_Dict()
{
  G__Sizep2memfuncPHSartreParticleTrigger_Dict a;
  G__setsizep2memfunc((int)a.sizep2memfunc());
  return((size_t)a.sizep2memfunc());
}


/*********************************************************
* virtual base class offset calculation interface
*********************************************************/

   /* Setting up class inheritance */

/*********************************************************
* Inheritance information setup/
*********************************************************/
extern "C" void G__cpp_setup_inheritancePHSartreParticleTrigger_Dict() {

   /* Setting up class inheritance */
   if(0==G__getnumbaseclass(G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_PHSartreParticleTrigger))) {
     PHSartreParticleTrigger *G__Lderived;
     G__Lderived=(PHSartreParticleTrigger*)0x1000;
     {
       PHSartreGenTrigger *G__Lpbase=(PHSartreGenTrigger*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_PHSartreParticleTrigger),G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_PHSartreGenTrigger),(long)G__Lpbase-(long)G__Lderived,1,1);
     }
   }
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetablePHSartreParticleTrigger_Dict() {

   /* Setting up typedef entry */
   G__search_typename2("vector<ROOT::TSchemaHelper>",117,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<TVirtualArray*>",117,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<int>",117,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_vectorlEintcOallocatorlEintgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_vectorlEintcOallocatorlEintgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_vectorlEintcOallocatorlEintgRsPgR));
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* PHSartreParticleTrigger */
static void G__setup_memvarPHSartreParticleTrigger(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_PHSartreParticleTrigger));
   { PHSartreParticleTrigger *p; p=(PHSartreParticleTrigger*)0x1000; if (p) { }
   G__memvar_setup((void*)0,117,0,0,G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_vectorlEintcOallocatorlEintgRsPgR),G__defined_typename("vector<int>"),-1,4,"_theParticles=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"_theEtaHigh=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"_theEtaLow=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"_thePtHigh=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"_thePtLow=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"_thePHigh=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"_thePLow=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"_thePzHigh=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"_thePzLow=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doEtaHighCut=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doEtaLowCut=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doBothEtaCut=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doAbsEtaHighCut=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doAbsEtaLowCut=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doBothAbsEtaCut=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doPtHighCut=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doPtLowCut=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doBothPtCut=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doPHighCut=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doPLowCut=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doBothPCut=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doPzHighCut=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doPzLowCut=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_doBothPzCut=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarPHSartreParticleTrigger_Dict() {
}
/***********************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
***********************************************************/

/*********************************************************
* Member function information setup for each class
*********************************************************/
static void G__setup_memfuncPHSartreParticleTrigger(void) {
   /* PHSartreParticleTrigger */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_PHSartreParticleTrigger));
   G__memfunc_setup("PHSartreParticleTrigger",2321,G__PHSartreParticleTrigger_Dict_174_0_1, 105, G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_PHSartreParticleTrigger), -1, 0, 1, 1, 1, 0, "u 'string' - 11 '\"PHSartreParticleTrigger\"' name", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Apply",518,(G__InterfaceMethod) NULL,103, -1, -1, 0, 1, 1, 1, 0, "U 'Event' - 0 - event", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("AddParticles",1200,G__PHSartreParticleTrigger_Dict_174_0_3, 121, -1, -1, 0, 1, 1, 1, 0, "u 'string' - 11 - particles", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("AddParticles",1200,G__PHSartreParticleTrigger_Dict_174_0_4, 121, -1, -1, 0, 1, 1, 1, 0, "i - - 0 - particle", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("AddParticles",1200,G__PHSartreParticleTrigger_Dict_174_0_5, 121, -1, -1, 0, 1, 1, 1, 0, "u 'vector<int,allocator<int> >' 'vector<int>' 0 - particles", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetPtHigh",880,G__PHSartreParticleTrigger_Dict_174_0_6, 121, -1, -1, 0, 1, 1, 1, 0, "d - - 0 - pt", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetPtLow",802,G__PHSartreParticleTrigger_Dict_174_0_7, 121, -1, -1, 0, 1, 1, 1, 0, "d - - 0 - pt", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetPtHighLow",1186,G__PHSartreParticleTrigger_Dict_174_0_8, 121, -1, -1, 0, 2, 1, 1, 0, 
"d - - 0 - ptHigh d - - 0 - ptLow", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetPHigh",764,G__PHSartreParticleTrigger_Dict_174_0_9, 121, -1, -1, 0, 1, 1, 1, 0, "d - - 0 - p", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetPLow",686,G__PHSartreParticleTrigger_Dict_174_0_10, 121, -1, -1, 0, 1, 1, 1, 0, "d - - 0 - p", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetPHighLow",1070,G__PHSartreParticleTrigger_Dict_174_0_11, 121, -1, -1, 0, 2, 1, 1, 0, 
"d - - 0 - pHigh d - - 0 - pLow", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetEtaHigh",966,G__PHSartreParticleTrigger_Dict_174_0_12, 121, -1, -1, 0, 1, 1, 1, 0, "d - - 0 - eta", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetEtaLow",888,G__PHSartreParticleTrigger_Dict_174_0_13, 121, -1, -1, 0, 1, 1, 1, 0, "d - - 0 - eta", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetEtaHighLow",1272,G__PHSartreParticleTrigger_Dict_174_0_14, 121, -1, -1, 0, 2, 1, 1, 0, 
"d - - 0 - etaHigh d - - 0 - etaLow", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetAbsEtaHigh",1244,G__PHSartreParticleTrigger_Dict_174_0_15, 121, -1, -1, 0, 1, 1, 1, 0, "d - - 0 - eta", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetAbsEtaLow",1166,G__PHSartreParticleTrigger_Dict_174_0_16, 121, -1, -1, 0, 1, 1, 1, 0, "d - - 0 - eta", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetAbsEtaHighLow",1550,G__PHSartreParticleTrigger_Dict_174_0_17, 121, -1, -1, 0, 2, 1, 1, 0, 
"d - - 0 - etaHigh d - - 0 - etaLow", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetPzHigh",886,G__PHSartreParticleTrigger_Dict_174_0_18, 121, -1, -1, 0, 1, 1, 1, 0, "d - - 0 - pz", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetPzLow",808,G__PHSartreParticleTrigger_Dict_174_0_19, 121, -1, -1, 0, 1, 1, 1, 0, "d - - 0 - pz", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("SetPzHighLow",1192,G__PHSartreParticleTrigger_Dict_174_0_20, 121, -1, -1, 0, 2, 1, 1, 0, 
"d - - 0 - pzHigh d - - 0 - pzLow", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("PrintConfig",1123,G__PHSartreParticleTrigger_Dict_174_0_21, 121, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   // automatic copy constructor
   G__memfunc_setup("PHSartreParticleTrigger", 2321, G__PHSartreParticleTrigger_Dict_174_0_22, (int) ('i'), 
G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_PHSartreParticleTrigger), -1, 0, 1, 1, 1, 0, "u 'PHSartreParticleTrigger' - 11 - -", (char*) NULL, (void*) NULL, 0);
   // automatic destructor
   G__memfunc_setup("~PHSartreParticleTrigger", 2447, G__PHSartreParticleTrigger_Dict_174_0_23, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 1);
   // automatic assignment operator
   G__memfunc_setup("operator=", 937, G__PHSartreParticleTrigger_Dict_174_0_24, (int) ('u'), G__get_linked_tagnum(&G__PHSartreParticleTrigger_DictLN_PHSartreParticleTrigger), -1, 1, 1, 1, 1, 0, "u 'PHSartreParticleTrigger' - 11 - -", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncPHSartreParticleTrigger_Dict() {
}

/*********************************************************
* Global variable information setup for each class
*********************************************************/
static void G__cpp_setup_global0() {

   /* Setting up global variables */
   G__resetplocal();

}

static void G__cpp_setup_global1() {

   G__resetglobalenv();
}
extern "C" void G__cpp_setup_globalPHSartreParticleTrigger_Dict() {
  G__cpp_setup_global0();
  G__cpp_setup_global1();
}

/*********************************************************
* Global function information setup for each class
*********************************************************/
static void G__cpp_setup_func0() {
   G__lastifuncposition();

}

static void G__cpp_setup_func1() {
}

static void G__cpp_setup_func2() {
}

static void G__cpp_setup_func3() {
}

static void G__cpp_setup_func4() {
}

static void G__cpp_setup_func5() {
}

static void G__cpp_setup_func6() {
}

static void G__cpp_setup_func7() {
}

static void G__cpp_setup_func8() {
}

static void G__cpp_setup_func9() {
}

static void G__cpp_setup_func10() {
}

static void G__cpp_setup_func11() {
}

static void G__cpp_setup_func12() {
}

static void G__cpp_setup_func13() {
}

static void G__cpp_setup_func14() {
}

static void G__cpp_setup_func15() {
}

static void G__cpp_setup_func16() {
}

static void G__cpp_setup_func17() {
}

static void G__cpp_setup_func18() {
}

static void G__cpp_setup_func19() {
}

static void G__cpp_setup_func20() {
}

static void G__cpp_setup_func21() {
}

static void G__cpp_setup_func22() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcPHSartreParticleTrigger_Dict() {
  G__cpp_setup_func0();
  G__cpp_setup_func1();
  G__cpp_setup_func2();
  G__cpp_setup_func3();
  G__cpp_setup_func4();
  G__cpp_setup_func5();
  G__cpp_setup_func6();
  G__cpp_setup_func7();
  G__cpp_setup_func8();
  G__cpp_setup_func9();
  G__cpp_setup_func10();
  G__cpp_setup_func11();
  G__cpp_setup_func12();
  G__cpp_setup_func13();
  G__cpp_setup_func14();
  G__cpp_setup_func15();
  G__cpp_setup_func16();
  G__cpp_setup_func17();
  G__cpp_setup_func18();
  G__cpp_setup_func19();
  G__cpp_setup_func20();
  G__cpp_setup_func21();
  G__cpp_setup_func22();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__PHSartreParticleTrigger_DictLN_string = { "string" , 99 , -1 };
G__linked_taginfo G__PHSartreParticleTrigger_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR = { "vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >" , 99 , -1 };
G__linked_taginfo G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR = { "reverse_iterator<vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >::iterator>" , 99 , -1 };
G__linked_taginfo G__PHSartreParticleTrigger_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR = { "vector<TVirtualArray*,allocator<TVirtualArray*> >" , 99 , -1 };
G__linked_taginfo G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<TVirtualArray*,allocator<TVirtualArray*> >::iterator>" , 99 , -1 };
G__linked_taginfo G__PHSartreParticleTrigger_DictLN_Event = { "Event" , 99 , -1 };
G__linked_taginfo G__PHSartreParticleTrigger_DictLN_PHSartreGenTrigger = { "PHSartreGenTrigger" , 99 , -1 };
G__linked_taginfo G__PHSartreParticleTrigger_DictLN_vectorlEintcOallocatorlEintgRsPgR = { "vector<int,allocator<int> >" , 99 , -1 };
G__linked_taginfo G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<int,allocator<int> >::iterator>" , 99 , -1 };
G__linked_taginfo G__PHSartreParticleTrigger_DictLN_PHSartreParticleTrigger = { "PHSartreParticleTrigger" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtablePHSartreParticleTrigger_Dict() {
  G__PHSartreParticleTrigger_DictLN_string.tagnum = -1 ;
  G__PHSartreParticleTrigger_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR.tagnum = -1 ;
  G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__PHSartreParticleTrigger_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR.tagnum = -1 ;
  G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__PHSartreParticleTrigger_DictLN_Event.tagnum = -1 ;
  G__PHSartreParticleTrigger_DictLN_PHSartreGenTrigger.tagnum = -1 ;
  G__PHSartreParticleTrigger_DictLN_vectorlEintcOallocatorlEintgRsPgR.tagnum = -1 ;
  G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__PHSartreParticleTrigger_DictLN_PHSartreParticleTrigger.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtablePHSartreParticleTrigger_Dict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__PHSartreParticleTrigger_DictLN_string);
   G__get_linked_tagnum_fwd(&G__PHSartreParticleTrigger_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR);
   G__get_linked_tagnum_fwd(&G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__PHSartreParticleTrigger_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR);
   G__get_linked_tagnum_fwd(&G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__PHSartreParticleTrigger_DictLN_Event);
   G__get_linked_tagnum_fwd(&G__PHSartreParticleTrigger_DictLN_PHSartreGenTrigger);
   G__get_linked_tagnum_fwd(&G__PHSartreParticleTrigger_DictLN_vectorlEintcOallocatorlEintgRsPgR);
   G__get_linked_tagnum_fwd(&G__PHSartreParticleTrigger_DictLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR);
   G__tagtable_setup(G__get_linked_tagnum_fwd(&G__PHSartreParticleTrigger_DictLN_PHSartreParticleTrigger),sizeof(PHSartreParticleTrigger),-1,197888,(char*)NULL,G__setup_memvarPHSartreParticleTrigger,G__setup_memfuncPHSartreParticleTrigger);
}
extern "C" void G__cpp_setupPHSartreParticleTrigger_Dict(void) {
  G__check_setup_version(30051515,"G__cpp_setupPHSartreParticleTrigger_Dict()");
  G__set_cpp_environmentPHSartreParticleTrigger_Dict();
  G__cpp_setup_tagtablePHSartreParticleTrigger_Dict();

  G__cpp_setup_inheritancePHSartreParticleTrigger_Dict();

  G__cpp_setup_typetablePHSartreParticleTrigger_Dict();

  G__cpp_setup_memvarPHSartreParticleTrigger_Dict();

  G__cpp_setup_memfuncPHSartreParticleTrigger_Dict();
  G__cpp_setup_globalPHSartreParticleTrigger_Dict();
  G__cpp_setup_funcPHSartreParticleTrigger_Dict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncPHSartreParticleTrigger_Dict();
  return;
}
class G__cpp_setup_initPHSartreParticleTrigger_Dict {
  public:
    G__cpp_setup_initPHSartreParticleTrigger_Dict() { G__add_setup_func("PHSartreParticleTrigger_Dict",(G__incsetup)(&G__cpp_setupPHSartreParticleTrigger_Dict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initPHSartreParticleTrigger_Dict() { G__remove_setup_func("PHSartreParticleTrigger_Dict"); }
};
G__cpp_setup_initPHSartreParticleTrigger_Dict G__cpp_setup_initializerPHSartreParticleTrigger_Dict;

