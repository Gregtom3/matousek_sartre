//
// File generated by rootcint at Sun Feb 24 22:32:50 2019

// Do NOT change. Changes will be lost next time file is generated
//

#define R__DICTIONARY_FILENAME PHSartre_Dict
#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "PHSartre_Dict.h"

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
   void PHSartre_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void PHSartre_Dictionary();
   static void *new_PHSartre(void *p = 0);
   static void *newArray_PHSartre(Long_t size, void *p);
   static void delete_PHSartre(void *p);
   static void deleteArray_PHSartre(void *p);
   static void destruct_PHSartre(void *p);

   // Function generating the singleton type initializer
   static ROOT::TGenericClassInfo *GenerateInitInstanceLocal(const ::PHSartre*)
   {
      ::PHSartre *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PHSartre),0);
      static ::ROOT::TGenericClassInfo 
         instance("PHSartre", "./PHSartre.h", 33,
                  typeid(::PHSartre), ::ROOT::DefineBehavior(ptr, ptr),
                  0, &PHSartre_Dictionary, isa_proxy, 3,
                  sizeof(::PHSartre) );
      instance.SetNew(&new_PHSartre);
      instance.SetNewArray(&newArray_PHSartre);
      instance.SetDelete(&delete_PHSartre);
      instance.SetDeleteArray(&deleteArray_PHSartre);
      instance.SetDestructor(&destruct_PHSartre);
      return &instance;
   }
   ROOT::TGenericClassInfo *GenerateInitInstance(const ::PHSartre*)
   {
      return GenerateInitInstanceLocal((::PHSartre*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::PHSartre*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static void PHSartre_Dictionary() {
      ::ROOTDict::GenerateInitInstanceLocal((const ::PHSartre*)0x0)->GetClass();
   }

} // end of namespace ROOTDict

namespace ROOTDict {
   // Wrappers around operator new
   static void *new_PHSartre(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::PHSartre : new ::PHSartre;
   }
   static void *newArray_PHSartre(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::PHSartre[nElements] : new ::PHSartre[nElements];
   }
   // Wrapper around operator delete
   static void delete_PHSartre(void *p) {
      delete ((::PHSartre*)p);
   }
   static void deleteArray_PHSartre(void *p) {
      delete [] ((::PHSartre*)p);
   }
   static void destruct_PHSartre(void *p) {
      typedef ::PHSartre current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOTDict for class ::PHSartre

/********************************************************
* PHSartre_Dict.cc
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

extern "C" void G__cpp_reset_tagtablePHSartre_Dict();

extern "C" void G__set_cpp_environmentPHSartre_Dict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("PHSartre.h");
  G__cpp_reset_tagtablePHSartre_Dict();
}
#include <new>
extern "C" int G__cpp_dllrevPHSartre_Dict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* PHSartre */
static int G__PHSartre_Dict_537_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   PHSartre* p = NULL;
   char* gvp = (char*) G__getgvp();
   switch (libp->paran) {
   case 1:
     //m: 1
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new PHSartre(*(string*) libp->para[0].ref);
     } else {
       p = new((void*) gvp) PHSartre(*(string*) libp->para[0].ref);
     }
     break;
   case 0:
     int n = G__getaryconstruct();
     if (n) {
       if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
         p = new PHSartre[n];
       } else {
         p = new((void*) gvp) PHSartre[n];
       }
     } else {
       if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
         p = new PHSartre;
       } else {
         p = new((void*) gvp) PHSartre;
       }
     }
     break;
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__PHSartre_DictLN_PHSartre));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartre_Dict_537_0_6(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartre*) G__getstructoffset())->set_config_file((const char*) G__int(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartre_Dict_537_0_7(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((const PHSartre*) G__getstructoffset())->print_config();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartre_Dict_537_0_8(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartre*) G__getstructoffset())->register_trigger((PHSartreGenTrigger*) G__int(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartre_Dict_537_0_9(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartre*) G__getstructoffset())->set_trigger_OR();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartre_Dict_537_0_10(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartre*) G__getstructoffset())->set_trigger_AND();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartre_Dict_537_0_11(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartre*) G__getstructoffset())->process_string(*((string*) G__int(libp->para[0])));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartre_Dict_537_0_12(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartre*) G__getstructoffset())->beam_vertex_parameters((double) G__double(libp->para[0]), (double) G__double(libp->para[1])
, (double) G__double(libp->para[2]), (double) G__double(libp->para[3])
, (double) G__double(libp->para[4]), (double) G__double(libp->para[5]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartre_Dict_537_0_13(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartre*) G__getstructoffset())->set_vertex_distribution_function((PHHepMCGenHelper::VTXFUNC) G__int(libp->para[0]), (PHHepMCGenHelper::VTXFUNC) G__int(libp->para[1])
, (PHHepMCGenHelper::VTXFUNC) G__int(libp->para[2]), (PHHepMCGenHelper::VTXFUNC) G__int(libp->para[3]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartre_Dict_537_0_14(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartre*) G__getstructoffset())->set_vertex_distribution_mean((const double) G__double(libp->para[0]), (const double) G__double(libp->para[1])
, (const double) G__double(libp->para[2]), (const double) G__double(libp->para[3]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartre_Dict_537_0_15(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartre*) G__getstructoffset())->set_vertex_distribution_width((const double) G__double(libp->para[0]), (const double) G__double(libp->para[1])
, (const double) G__double(libp->para[2]), (const double) G__double(libp->para[3]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartre_Dict_537_0_16(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartre*) G__getstructoffset())->set_reuse_vertex((int) G__int(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartre_Dict_537_0_17(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) ((const PHSartre*) G__getstructoffset())->get_embedding_id());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__PHSartre_Dict_537_0_18(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((PHSartre*) G__getstructoffset())->set_embedding_id((int) G__int(libp->para[0]));
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic copy constructor
static int G__PHSartre_Dict_537_0_23(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)

{
   PHSartre* p;
   void* tmp = (void*) G__int(libp->para[0]);
   p = new PHSartre(*(PHSartre*) tmp);
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__PHSartre_DictLN_PHSartre));
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef PHSartre G__TPHSartre;
static int G__PHSartre_Dict_537_0_24(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
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
       delete[] (PHSartre*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((PHSartre*) (soff+(sizeof(PHSartre)*i)))->~G__TPHSartre();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (PHSartre*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((PHSartre*) (soff))->~G__TPHSartre();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic assignment operator
static int G__PHSartre_Dict_537_0_25(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   PHSartre* dest = (PHSartre*) G__getstructoffset();
   *dest = *(PHSartre*) libp->para[0].ref;
   const PHSartre& obj = *dest;
   result7->ref = (long) (&obj);
   result7->obj.i = (long) (&obj);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* PHSartre */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncPHSartre_Dict {
 public:
  G__Sizep2memfuncPHSartre_Dict(): p(&G__Sizep2memfuncPHSartre_Dict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncPHSartre_Dict::*p)();
};

size_t G__get_sizep2memfuncPHSartre_Dict()
{
  G__Sizep2memfuncPHSartre_Dict a;
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
extern "C" void G__cpp_setup_inheritancePHSartre_Dict() {

   /* Setting up class inheritance */
   if(0==G__getnumbaseclass(G__get_linked_tagnum(&G__PHSartre_DictLN_PHSartre))) {
     PHSartre *G__Lderived;
     G__Lderived=(PHSartre*)0x1000;
     {
       SubsysReco *G__Lpbase=(SubsysReco*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__PHSartre_DictLN_PHSartre),G__get_linked_tagnum(&G__PHSartre_DictLN_SubsysReco),(long)G__Lpbase-(long)G__Lderived,1,1);
     }
     {
       Fun4AllBase *G__Lpbase=(Fun4AllBase*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__PHSartre_DictLN_PHSartre),G__get_linked_tagnum(&G__PHSartre_DictLN_Fun4AllBase),(long)G__Lpbase-(long)G__Lderived,1,0);
     }
   }
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetablePHSartre_Dict() {

   /* Setting up typedef entry */
   G__search_typename2("vector<ROOT::TSchemaHelper>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<TVirtualArray*>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<std::bidirectional_iterator_tag,TObject*,std::ptrdiff_t,const TObject**,const TObject*&>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*,std::ptrdiff_t,const TObject**,const TObject*&>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*,long>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("iterator<bidirectional_iterator_tag,TObject*,long,const TObject**>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("map<std::string,TObjArray*>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_maplEstringcOTObjArraymUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOTObjArraymUgRsPgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("map<string,TObjArray*>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_maplEstringcOTObjArraymUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOTObjArraymUgRsPgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("map<string,TObjArray*>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_maplEstringcOTObjArraymUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOTObjArraymUgRsPgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("map<string,TObjArray*,less<string> >",117,G__get_linked_tagnum(&G__PHSartre_DictLN_maplEstringcOTObjArraymUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOTObjArraymUgRsPgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<PHSartreGenTrigger*>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlEPHSartreGenTriggermUcOallocatorlEPHSartreGenTriggermUgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_reverse_iteratorlEvectorlEPHSartreGenTriggermUcOallocatorlEPHSartreGenTriggermUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlEPHSartreGenTriggermUcOallocatorlEPHSartreGenTriggermUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_reverse_iteratorlEvectorlEPHSartreGenTriggermUcOallocatorlEPHSartreGenTriggermUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlEPHSartreGenTriggermUcOallocatorlEPHSartreGenTriggermUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<std::string>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlEstringcOallocatorlEstringgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<string>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlEstringcOallocatorlEstringgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_reverse_iteratorlEvectorlEstringcOallocatorlEstringgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlEstringcOallocatorlEstringgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_reverse_iteratorlEvectorlEstringcOallocatorlEstringgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlEstringcOallocatorlEstringgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<string>",117,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlEstringcOallocatorlEstringgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* PHSartre */
static void G__setup_memvarPHSartre(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__PHSartre_DictLN_PHSartre));
   { PHSartre *p; p=(PHSartre*)0x1000; if (p) { }
   G__memvar_setup((void*)0,105,0,0,-1,-1,-1,4,"_eventcount=",0,(char*)NULL);
   G__memvar_setup((void*)0,105,0,0,-1,-1,-1,4,"_gencount=",0,(char*)NULL);
   G__memvar_setup((void*)0,117,0,0,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlEPHSartreGenTriggermUcOallocatorlEPHSartreGenTriggermUgRsPgR),G__defined_typename("vector<PHSartreGenTrigger*>"),-1,4,"_registeredTriggers=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_triggersOR=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"_triggersAND=",0,(char*)NULL);
   G__memvar_setup((void*)0,117,0,0,G__get_linked_tagnum(&G__PHSartre_DictLN_string),-1,-1,4,"_configFile=",0,(char*)NULL);
   G__memvar_setup((void*)0,117,0,0,G__get_linked_tagnum(&G__PHSartre_DictLN_vectorlEstringcOallocatorlEstringgRsPgR),G__defined_typename("vector<std::string>"),-1,4,"_commands=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__PHSartre_DictLN_Sartre),-1,-1,4,"_sartre=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__PHSartre_DictLN_EventGeneratorSettings),-1,-1,4,"settings=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__PHSartre_DictLN_TGenPhaseSpace),-1,-1,4,"decay=",0,(char*)NULL);
   G__memvar_setup((void*)0,105,0,0,-1,-1,-1,4,"daughterID=",0,(char*)NULL);
   G__memvar_setup((void*)0,100,0,0,-1,-1,-1,4,"daughterMasses[2]=",0,(char*)NULL);
   G__memvar_setup((void*)0,103,0,0,-1,-1,-1,4,"doPerformDecay=",0,(char*)NULL);
   G__memvar_setup((void*)0,117,0,0,G__get_linked_tagnum(&G__PHSartre_DictLN_PHHepMCGenHelper),-1,-1,4,"hepmc_helper=",0,(char*)NULL);
   G__memvar_setup((void*)0,117,0,0,G__get_linked_tagnum(&G__PHSartre_DictLN_string),-1,-1,4,"_filename=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__PHSartre_DictLN_TFile),-1,-1,4,"_tfile=",0,(char*)NULL);
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__PHSartre_DictLN_TTree),-1,-1,4,"_outTree=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarPHSartre_Dict() {
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
static void G__setup_memfuncPHSartre(void) {
   /* PHSartre */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__PHSartre_DictLN_PHSartre));
   G__memfunc_setup("PHSartre",777,G__PHSartre_Dict_537_0_1, 105, G__get_linked_tagnum(&G__PHSartre_DictLN_PHSartre), -1, 0, 1, 1, 1, 0, "u 'string' - 11 '\"PHSartre\"' name", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Init",404,(G__InterfaceMethod) NULL,105, -1, -1, 0, 1, 1, 1, 0, "U 'PHCompositeNode' - 0 - topNode", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("process_event",1408,(G__InterfaceMethod) NULL,105, -1, -1, 0, 1, 1, 1, 0, "U 'PHCompositeNode' - 0 - topNode", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("ResetEvent",1029,(G__InterfaceMethod) NULL,105, -1, -1, 0, 1, 1, 1, 0, "U 'PHCompositeNode' - 0 - topNode", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("End",279,(G__InterfaceMethod) NULL,105, -1, -1, 0, 1, 1, 1, 0, "U 'PHCompositeNode' - 0 - topNode", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("set_config_file",1568,G__PHSartre_Dict_537_0_6, 121, -1, -1, 0, 1, 1, 1, 0, "C - - 10 - cfg_file", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("print_config",1282,G__PHSartre_Dict_537_0_7, 121, -1, -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("register_trigger",1720,G__PHSartre_Dict_537_0_8, 121, -1, -1, 0, 1, 1, 1, 0, "U 'PHSartreGenTrigger' - 0 - theTrigger", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("set_trigger_OR",1439,G__PHSartre_Dict_537_0_9, 121, -1, -1, 0, 0, 1, 1, 0, "", "default true", (void*) NULL, 0);
   G__memfunc_setup("set_trigger_AND",1489,G__PHSartre_Dict_537_0_10, 121, -1, -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("process_string",1525,G__PHSartre_Dict_537_0_11, 121, -1, -1, 0, 1, 1, 1, 0, "u 'string' - 0 - s", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("beam_vertex_parameters",2341,G__PHSartre_Dict_537_0_12, 121, -1, -1, 0, 6, 1, 1, 0, 
"d - - 0 - beamX d - - 0 - beamY "
"d - - 0 - beamZ d - - 0 - beamXsigma "
"d - - 0 - beamYsigma d - - 0 - beamZsigma", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("set_vertex_distribution_function",3469,G__PHSartre_Dict_537_0_13, 121, -1, -1, 0, 4, 1, 1, 0, 
"i 'PHHepMCGenHelper::VTXFUNC' - 0 - x i 'PHHepMCGenHelper::VTXFUNC' - 0 - y "
"i 'PHHepMCGenHelper::VTXFUNC' - 0 - z i 'PHHepMCGenHelper::VTXFUNC' - 0 - t", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("set_vertex_distribution_mean",3016,G__PHSartre_Dict_537_0_14, 121, -1, -1, 0, 4, 1, 1, 0, 
"d - - 10 - x d - - 10 - y "
"d - - 10 - z d - - 10 - t", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("set_vertex_distribution_width",3143,G__PHSartre_Dict_537_0_15, 121, -1, -1, 0, 4, 1, 1, 0, 
"d - - 10 - x d - - 10 - y "
"d - - 10 - z d - - 10 - t", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("set_reuse_vertex",1740,G__PHSartre_Dict_537_0_16, 121, -1, -1, 0, 1, 1, 1, 0, "i - - 0 - src_embedding_id", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("get_embedding_id",1642,G__PHSartre_Dict_537_0_17, 105, -1, -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("set_embedding_id",1654,G__PHSartre_Dict_537_0_18, 121, -1, -1, 0, 1, 1, 1, 0, "i - - 0 - id", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("create_node_tree",1672,(G__InterfaceMethod) NULL, 105, -1, -1, 0, 1, 1, 4, 0, "U 'PHCompositeNode' - 0 - topNode", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("percent_diff",1257,(G__InterfaceMethod) NULL, 100, -1, -1, 0, 2, 1, 4, 0, 
"d - - 10 - a d - - 10 - b", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("randomlyReverseBeams",2090,(G__InterfaceMethod) NULL, 121, -1, -1, 0, 1, 1, 4, 0, "U 'Event' - 0 - myEvent", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("ReverseBeams",1220,(G__InterfaceMethod) NULL, 121, -1, -1, 0, 1, 1, 4, 0, "U 'Event' - 0 - myEvent", (char*)NULL, (void*) NULL, 0);
   // automatic copy constructor
   G__memfunc_setup("PHSartre", 777, G__PHSartre_Dict_537_0_23, (int) ('i'), G__get_linked_tagnum(&G__PHSartre_DictLN_PHSartre), -1, 0, 1, 1, 1, 0, "u 'PHSartre' - 11 - -", (char*) NULL, (void*) NULL, 0);
   // automatic destructor
   G__memfunc_setup("~PHSartre", 903, G__PHSartre_Dict_537_0_24, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 1);
   // automatic assignment operator
   G__memfunc_setup("operator=", 937, G__PHSartre_Dict_537_0_25, (int) ('u'), G__get_linked_tagnum(&G__PHSartre_DictLN_PHSartre), -1, 1, 1, 1, 1, 0, "u 'PHSartre' - 11 - -", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncPHSartre_Dict() {
}

/*********************************************************
* Global variable information setup for each class
*********************************************************/
static void G__cpp_setup_global0() {

   /* Setting up global variables */
   G__resetplocal();

}

static void G__cpp_setup_global1() {
}

static void G__cpp_setup_global2() {
}

static void G__cpp_setup_global3() {

   G__resetglobalenv();
}
extern "C" void G__cpp_setup_globalPHSartre_Dict() {
  G__cpp_setup_global0();
  G__cpp_setup_global1();
  G__cpp_setup_global2();
  G__cpp_setup_global3();
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
}

static void G__cpp_setup_func23() {
}

static void G__cpp_setup_func24() {
}

static void G__cpp_setup_func25() {
}

static void G__cpp_setup_func26() {
}

static void G__cpp_setup_func27() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcPHSartre_Dict() {
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
  G__cpp_setup_func23();
  G__cpp_setup_func24();
  G__cpp_setup_func25();
  G__cpp_setup_func26();
  G__cpp_setup_func27();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__PHSartre_DictLN_string = { "string" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR = { "vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR = { "reverse_iterator<vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >::iterator>" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR = { "vector<TVirtualArray*,allocator<TVirtualArray*> >" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<TVirtualArray*,allocator<TVirtualArray*> >::iterator>" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_Fun4AllBase = { "Fun4AllBase" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_PHCompositeNode = { "PHCompositeNode" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_SubsysReco = { "SubsysReco" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_PHHepMCGenHelper = { "PHHepMCGenHelper" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_PHHepMCGenHelpercLcLVTXFUNC = { "PHHepMCGenHelper::VTXFUNC" , 101 , -1 };
G__linked_taginfo G__PHSartre_DictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR = { "iterator<bidirectional_iterator_tag,TObject*,long,const TObject**,const TObject*&>" , 115 , -1 };
G__linked_taginfo G__PHSartre_DictLN_TFile = { "TFile" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_TTree = { "TTree" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_maplEstringcOTObjArraymUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOTObjArraymUgRsPgRsPgR = { "map<string,TObjArray*,less<string>,allocator<pair<const string,TObjArray*> > >" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_Sartre = { "Sartre" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_Event = { "Event" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_EventGeneratorSettings = { "EventGeneratorSettings" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_PHSartreGenTrigger = { "PHSartreGenTrigger" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_TGenPhaseSpace = { "TGenPhaseSpace" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_PHSartre = { "PHSartre" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_vectorlEPHSartreGenTriggermUcOallocatorlEPHSartreGenTriggermUgRsPgR = { "vector<PHSartreGenTrigger*,allocator<PHSartreGenTrigger*> >" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_reverse_iteratorlEvectorlEPHSartreGenTriggermUcOallocatorlEPHSartreGenTriggermUgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<PHSartreGenTrigger*,allocator<PHSartreGenTrigger*> >::iterator>" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_vectorlEstringcOallocatorlEstringgRsPgR = { "vector<string,allocator<string> >" , 99 , -1 };
G__linked_taginfo G__PHSartre_DictLN_reverse_iteratorlEvectorlEstringcOallocatorlEstringgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<string,allocator<string> >::iterator>" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtablePHSartre_Dict() {
  G__PHSartre_DictLN_string.tagnum = -1 ;
  G__PHSartre_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR.tagnum = -1 ;
  G__PHSartre_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__PHSartre_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR.tagnum = -1 ;
  G__PHSartre_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__PHSartre_DictLN_Fun4AllBase.tagnum = -1 ;
  G__PHSartre_DictLN_PHCompositeNode.tagnum = -1 ;
  G__PHSartre_DictLN_SubsysReco.tagnum = -1 ;
  G__PHSartre_DictLN_PHHepMCGenHelper.tagnum = -1 ;
  G__PHSartre_DictLN_PHHepMCGenHelpercLcLVTXFUNC.tagnum = -1 ;
  G__PHSartre_DictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR.tagnum = -1 ;
  G__PHSartre_DictLN_TFile.tagnum = -1 ;
  G__PHSartre_DictLN_TTree.tagnum = -1 ;
  G__PHSartre_DictLN_maplEstringcOTObjArraymUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOTObjArraymUgRsPgRsPgR.tagnum = -1 ;
  G__PHSartre_DictLN_Sartre.tagnum = -1 ;
  G__PHSartre_DictLN_Event.tagnum = -1 ;
  G__PHSartre_DictLN_EventGeneratorSettings.tagnum = -1 ;
  G__PHSartre_DictLN_PHSartreGenTrigger.tagnum = -1 ;
  G__PHSartre_DictLN_TGenPhaseSpace.tagnum = -1 ;
  G__PHSartre_DictLN_PHSartre.tagnum = -1 ;
  G__PHSartre_DictLN_vectorlEPHSartreGenTriggermUcOallocatorlEPHSartreGenTriggermUgRsPgR.tagnum = -1 ;
  G__PHSartre_DictLN_reverse_iteratorlEvectorlEPHSartreGenTriggermUcOallocatorlEPHSartreGenTriggermUgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__PHSartre_DictLN_vectorlEstringcOallocatorlEstringgRsPgR.tagnum = -1 ;
  G__PHSartre_DictLN_reverse_iteratorlEvectorlEstringcOallocatorlEstringgRsPgRcLcLiteratorgR.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtablePHSartre_Dict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_string);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_Fun4AllBase);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_PHCompositeNode);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_SubsysReco);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_PHHepMCGenHelper);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_PHHepMCGenHelpercLcLVTXFUNC);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_TFile);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_TTree);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_maplEstringcOTObjArraymUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOTObjArraymUgRsPgRsPgR);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_Sartre);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_Event);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_EventGeneratorSettings);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_PHSartreGenTrigger);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_TGenPhaseSpace);
   G__tagtable_setup(G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_PHSartre),sizeof(PHSartre),-1,197888,(char*)NULL,G__setup_memvarPHSartre,G__setup_memfuncPHSartre);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_vectorlEPHSartreGenTriggermUcOallocatorlEPHSartreGenTriggermUgRsPgR);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_reverse_iteratorlEvectorlEPHSartreGenTriggermUcOallocatorlEPHSartreGenTriggermUgRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_vectorlEstringcOallocatorlEstringgRsPgR);
   G__get_linked_tagnum_fwd(&G__PHSartre_DictLN_reverse_iteratorlEvectorlEstringcOallocatorlEstringgRsPgRcLcLiteratorgR);
}
extern "C" void G__cpp_setupPHSartre_Dict(void) {
  G__check_setup_version(30051515,"G__cpp_setupPHSartre_Dict()");
  G__set_cpp_environmentPHSartre_Dict();
  G__cpp_setup_tagtablePHSartre_Dict();

  G__cpp_setup_inheritancePHSartre_Dict();

  G__cpp_setup_typetablePHSartre_Dict();

  G__cpp_setup_memvarPHSartre_Dict();

  G__cpp_setup_memfuncPHSartre_Dict();
  G__cpp_setup_globalPHSartre_Dict();
  G__cpp_setup_funcPHSartre_Dict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncPHSartre_Dict();
  return;
}
class G__cpp_setup_initPHSartre_Dict {
  public:
    G__cpp_setup_initPHSartre_Dict() { G__add_setup_func("PHSartre_Dict",(G__incsetup)(&G__cpp_setupPHSartre_Dict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initPHSartre_Dict() { G__remove_setup_func("PHSartre_Dict"); }
};
G__cpp_setup_initPHSartre_Dict G__cpp_setup_initializerPHSartre_Dict;
