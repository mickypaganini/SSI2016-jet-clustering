// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME FastJetToolsDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
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
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "FastJetFinder.hh"
#include "FastJetTool.hh"
#include "FastJetUtils.hh"
#include "PseudoJetMoment.hh"
#include "PtDensityTool.hh"
#include "SelectorTool.hh"
#include "YSplitterTool.hh"

// Header files passed via #pragma extra_include

namespace SpartyJet {
namespace FastJet {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *SpartyJetcLcLFastJet_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("SpartyJet::FastJet", 0 /*version*/, "FastJetFinder.hh", 39,
                     ::ROOT::DefineBehavior((void*)0,(void*)0),
                     &SpartyJetcLcLFastJet_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *SpartyJetcLcLFastJet_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}
}

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLFastJetFinder_Dictionary();
   static void SpartyJetcLcLFastJetcLcLFastJetFinder_TClassManip(TClass*);
   static void *new_SpartyJetcLcLFastJetcLcLFastJetFinder(void *p = 0);
   static void *newArray_SpartyJetcLcLFastJetcLcLFastJetFinder(Long_t size, void *p);
   static void delete_SpartyJetcLcLFastJetcLcLFastJetFinder(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLFastJetFinder(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLFastJetFinder(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::FastJetFinder*)
   {
      ::SpartyJet::FastJet::FastJetFinder *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::FastJetFinder),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::FastJetFinder", "FastJetFinder.hh", 44,
                  typeid(::SpartyJet::FastJet::FastJetFinder), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLFastJetFinder_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::FastJetFinder) );
      instance.SetNew(&new_SpartyJetcLcLFastJetcLcLFastJetFinder);
      instance.SetNewArray(&newArray_SpartyJetcLcLFastJetcLcLFastJetFinder);
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLFastJetFinder);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLFastJetFinder);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLFastJetFinder);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FastJet::FastJetFinder*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FastJet::FastJetFinder*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::FastJetFinder*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLFastJetFinder_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::FastJetFinder*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLFastJetFinder_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLFastJetFinder_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLFastJetRecluster_Dictionary();
   static void SpartyJetcLcLFastJetcLcLFastJetRecluster_TClassManip(TClass*);
   static void *new_SpartyJetcLcLFastJetcLcLFastJetRecluster(void *p = 0);
   static void *newArray_SpartyJetcLcLFastJetcLcLFastJetRecluster(Long_t size, void *p);
   static void delete_SpartyJetcLcLFastJetcLcLFastJetRecluster(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLFastJetRecluster(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLFastJetRecluster(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::FastJetRecluster*)
   {
      ::SpartyJet::FastJet::FastJetRecluster *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::FastJetRecluster),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::FastJetRecluster", "FastJetFinder.hh", 104,
                  typeid(::SpartyJet::FastJet::FastJetRecluster), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLFastJetRecluster_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::FastJetRecluster) );
      instance.SetNew(&new_SpartyJetcLcLFastJetcLcLFastJetRecluster);
      instance.SetNewArray(&newArray_SpartyJetcLcLFastJetcLcLFastJetRecluster);
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLFastJetRecluster);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLFastJetRecluster);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLFastJetRecluster);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FastJet::FastJetRecluster*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FastJet::FastJetRecluster*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::FastJetRecluster*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLFastJetRecluster_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::FastJetRecluster*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLFastJetRecluster_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLFastJetRecluster_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLYSplitterTool_Dictionary();
   static void SpartyJetcLcLFastJetcLcLYSplitterTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLFastJetcLcLYSplitterTool(void *p = 0);
   static void *newArray_SpartyJetcLcLFastJetcLcLYSplitterTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLFastJetcLcLYSplitterTool(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLYSplitterTool(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLYSplitterTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::YSplitterTool*)
   {
      ::SpartyJet::FastJet::YSplitterTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::YSplitterTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::YSplitterTool", "YSplitterTool.hh", 33,
                  typeid(::SpartyJet::FastJet::YSplitterTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLYSplitterTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::YSplitterTool) );
      instance.SetNew(&new_SpartyJetcLcLFastJetcLcLYSplitterTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLFastJetcLcLYSplitterTool);
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLYSplitterTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLYSplitterTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLYSplitterTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FastJet::YSplitterTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FastJet::YSplitterTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::YSplitterTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLYSplitterTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::YSplitterTool*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLYSplitterTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLYSplitterTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLPtDensityTool_Dictionary();
   static void SpartyJetcLcLFastJetcLcLPtDensityTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLFastJetcLcLPtDensityTool(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLPtDensityTool(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLPtDensityTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::PtDensityTool*)
   {
      ::SpartyJet::FastJet::PtDensityTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::PtDensityTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::PtDensityTool", "PtDensityTool.hh", 38,
                  typeid(::SpartyJet::FastJet::PtDensityTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLPtDensityTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::PtDensityTool) );
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLPtDensityTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLPtDensityTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLPtDensityTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FastJet::PtDensityTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FastJet::PtDensityTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::PtDensityTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLPtDensityTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::PtDensityTool*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLPtDensityTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLPtDensityTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLFastJetTool_Dictionary();
   static void SpartyJetcLcLFastJetcLcLFastJetTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLFastJetcLcLFastJetTool(void *p = 0);
   static void *newArray_SpartyJetcLcLFastJetcLcLFastJetTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLFastJetcLcLFastJetTool(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLFastJetTool(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLFastJetTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::FastJetTool*)
   {
      ::SpartyJet::FastJet::FastJetTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::FastJetTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::FastJetTool", "FastJetTool.hh", 36,
                  typeid(::SpartyJet::FastJet::FastJetTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLFastJetTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::FastJetTool) );
      instance.SetNew(&new_SpartyJetcLcLFastJetcLcLFastJetTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLFastJetcLcLFastJetTool);
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLFastJetTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLFastJetTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLFastJetTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FastJet::FastJetTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FastJet::FastJetTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::FastJetTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLFastJetTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::FastJetTool*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLFastJetTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLFastJetTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLPseudoJetTool_Dictionary();
   static void SpartyJetcLcLFastJetcLcLPseudoJetTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLFastJetcLcLPseudoJetTool(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetTool(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLPseudoJetTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::PseudoJetTool*)
   {
      ::SpartyJet::FastJet::PseudoJetTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::PseudoJetTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::PseudoJetTool", "FastJetTool.hh", 50,
                  typeid(::SpartyJet::FastJet::PseudoJetTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLPseudoJetTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::PseudoJetTool) );
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLPseudoJetTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLPseudoJetTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FastJet::PseudoJetTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FastJet::PseudoJetTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::PseudoJetTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLPseudoJetTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::PseudoJetTool*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLPseudoJetTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLPseudoJetTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLSelectorTool_Dictionary();
   static void SpartyJetcLcLFastJetcLcLSelectorTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLFastJetcLcLSelectorTool(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLSelectorTool(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLSelectorTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::SelectorTool*)
   {
      ::SpartyJet::FastJet::SelectorTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::SelectorTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::SelectorTool", "SelectorTool.hh", 37,
                  typeid(::SpartyJet::FastJet::SelectorTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLSelectorTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::SelectorTool) );
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLSelectorTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLSelectorTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLSelectorTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FastJet::SelectorTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FastJet::SelectorTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::SelectorTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLSelectorTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::SelectorTool*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLSelectorTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLSelectorTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR_Dictionary();
   static void SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR_TClassManip(TClass*);
   static void delete_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::PseudoJetMoment<float>*)
   {
      ::SpartyJet::FastJet::PseudoJetMoment<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::PseudoJetMoment<float>),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::PseudoJetMoment<float>", "PseudoJetMoment.hh", 56,
                  typeid(::SpartyJet::FastJet::PseudoJetMoment<float>), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::PseudoJetMoment<float>) );
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FastJet::PseudoJetMoment<float>*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FastJet::PseudoJetMoment<float>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::PseudoJetMoment<float>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::PseudoJetMoment<float>*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR_Dictionary();
   static void SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR_TClassManip(TClass*);
   static void delete_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::PseudoJetMoment<Double32_t>*)
   {
      ::SpartyJet::FastJet::PseudoJetMoment<Double32_t> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::PseudoJetMoment<Double32_t>),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::PseudoJetMoment<Double32_t>", "PseudoJetMoment.hh", 56,
                  typeid(::SpartyJet::FastJet::PseudoJetMoment<Double32_t>), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::PseudoJetMoment<Double32_t>) );
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::PseudoJetMoment<Double32_t>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::PseudoJetMoment<Double32_t>*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR_Dictionary();
   static void SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR_TClassManip(TClass*);
   static void delete_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::PseudoJetMomentTool<float>*)
   {
      ::SpartyJet::FastJet::PseudoJetMomentTool<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::PseudoJetMomentTool<float>),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::PseudoJetMomentTool<float>", "PseudoJetMoment.hh", 70,
                  typeid(::SpartyJet::FastJet::PseudoJetMomentTool<float>), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::PseudoJetMomentTool<float>) );
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FastJet::PseudoJetMomentTool<float>*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FastJet::PseudoJetMomentTool<float>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::PseudoJetMomentTool<float>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::PseudoJetMomentTool<float>*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR_Dictionary();
   static void SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR_TClassManip(TClass*);
   static void delete_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::PseudoJetMomentTool<Double32_t>*)
   {
      ::SpartyJet::FastJet::PseudoJetMomentTool<Double32_t> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::PseudoJetMomentTool<Double32_t>),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::PseudoJetMomentTool<Double32_t>", "PseudoJetMoment.hh", 70,
                  typeid(::SpartyJet::FastJet::PseudoJetMomentTool<Double32_t>), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::PseudoJetMomentTool<Double32_t>) );
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::PseudoJetMomentTool<Double32_t>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::PseudoJetMomentTool<Double32_t>*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLMassFunction_Dictionary();
   static void SpartyJetcLcLFastJetcLcLMassFunction_TClassManip(TClass*);
   static void *new_SpartyJetcLcLFastJetcLcLMassFunction(void *p = 0);
   static void *newArray_SpartyJetcLcLFastJetcLcLMassFunction(Long_t size, void *p);
   static void delete_SpartyJetcLcLFastJetcLcLMassFunction(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLMassFunction(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLMassFunction(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::MassFunction*)
   {
      ::SpartyJet::FastJet::MassFunction *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::MassFunction),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::MassFunction", "PseudoJetMoment.hh", 78,
                  typeid(::SpartyJet::FastJet::MassFunction), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLMassFunction_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::MassFunction) );
      instance.SetNew(&new_SpartyJetcLcLFastJetcLcLMassFunction);
      instance.SetNewArray(&newArray_SpartyJetcLcLFastJetcLcLMassFunction);
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLMassFunction);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLMassFunction);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLMassFunction);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FastJet::MassFunction*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FastJet::MassFunction*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::MassFunction*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLMassFunction_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::MassFunction*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLMassFunction_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLMassFunction_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLFastJetcLcLFastJetFinder(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::FastJet::FastJetFinder : new ::SpartyJet::FastJet::FastJetFinder;
   }
   static void *newArray_SpartyJetcLcLFastJetcLcLFastJetFinder(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::FastJet::FastJetFinder[nElements] : new ::SpartyJet::FastJet::FastJetFinder[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLFastJetFinder(void *p) {
      delete ((::SpartyJet::FastJet::FastJetFinder*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLFastJetFinder(void *p) {
      delete [] ((::SpartyJet::FastJet::FastJetFinder*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLFastJetFinder(void *p) {
      typedef ::SpartyJet::FastJet::FastJetFinder current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::FastJetFinder

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLFastJetcLcLFastJetRecluster(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::FastJet::FastJetRecluster : new ::SpartyJet::FastJet::FastJetRecluster;
   }
   static void *newArray_SpartyJetcLcLFastJetcLcLFastJetRecluster(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::FastJet::FastJetRecluster[nElements] : new ::SpartyJet::FastJet::FastJetRecluster[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLFastJetRecluster(void *p) {
      delete ((::SpartyJet::FastJet::FastJetRecluster*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLFastJetRecluster(void *p) {
      delete [] ((::SpartyJet::FastJet::FastJetRecluster*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLFastJetRecluster(void *p) {
      typedef ::SpartyJet::FastJet::FastJetRecluster current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::FastJetRecluster

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLFastJetcLcLYSplitterTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::FastJet::YSplitterTool : new ::SpartyJet::FastJet::YSplitterTool;
   }
   static void *newArray_SpartyJetcLcLFastJetcLcLYSplitterTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::FastJet::YSplitterTool[nElements] : new ::SpartyJet::FastJet::YSplitterTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLYSplitterTool(void *p) {
      delete ((::SpartyJet::FastJet::YSplitterTool*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLYSplitterTool(void *p) {
      delete [] ((::SpartyJet::FastJet::YSplitterTool*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLYSplitterTool(void *p) {
      typedef ::SpartyJet::FastJet::YSplitterTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::YSplitterTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLPtDensityTool(void *p) {
      delete ((::SpartyJet::FastJet::PtDensityTool*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLPtDensityTool(void *p) {
      delete [] ((::SpartyJet::FastJet::PtDensityTool*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLPtDensityTool(void *p) {
      typedef ::SpartyJet::FastJet::PtDensityTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::PtDensityTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLFastJetcLcLFastJetTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::FastJet::FastJetTool : new ::SpartyJet::FastJet::FastJetTool;
   }
   static void *newArray_SpartyJetcLcLFastJetcLcLFastJetTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::FastJet::FastJetTool[nElements] : new ::SpartyJet::FastJet::FastJetTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLFastJetTool(void *p) {
      delete ((::SpartyJet::FastJet::FastJetTool*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLFastJetTool(void *p) {
      delete [] ((::SpartyJet::FastJet::FastJetTool*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLFastJetTool(void *p) {
      typedef ::SpartyJet::FastJet::FastJetTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::FastJetTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLPseudoJetTool(void *p) {
      delete ((::SpartyJet::FastJet::PseudoJetTool*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetTool(void *p) {
      delete [] ((::SpartyJet::FastJet::PseudoJetTool*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLPseudoJetTool(void *p) {
      typedef ::SpartyJet::FastJet::PseudoJetTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::PseudoJetTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLSelectorTool(void *p) {
      delete ((::SpartyJet::FastJet::SelectorTool*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLSelectorTool(void *p) {
      delete [] ((::SpartyJet::FastJet::SelectorTool*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLSelectorTool(void *p) {
      typedef ::SpartyJet::FastJet::SelectorTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::SelectorTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR(void *p) {
      delete ((::SpartyJet::FastJet::PseudoJetMoment<float>*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR(void *p) {
      delete [] ((::SpartyJet::FastJet::PseudoJetMoment<float>*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEfloatgR(void *p) {
      typedef ::SpartyJet::FastJet::PseudoJetMoment<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::PseudoJetMoment<float>

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR(void *p) {
      delete ((::SpartyJet::FastJet::PseudoJetMoment<Double32_t>*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR(void *p) {
      delete [] ((::SpartyJet::FastJet::PseudoJetMoment<Double32_t>*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLPseudoJetMomentlEDouble32_tgR(void *p) {
      typedef ::SpartyJet::FastJet::PseudoJetMoment<Double32_t> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::PseudoJetMoment<Double32_t>

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR(void *p) {
      delete ((::SpartyJet::FastJet::PseudoJetMomentTool<float>*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR(void *p) {
      delete [] ((::SpartyJet::FastJet::PseudoJetMomentTool<float>*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEfloatgR(void *p) {
      typedef ::SpartyJet::FastJet::PseudoJetMomentTool<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::PseudoJetMomentTool<float>

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR(void *p) {
      delete ((::SpartyJet::FastJet::PseudoJetMomentTool<Double32_t>*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR(void *p) {
      delete [] ((::SpartyJet::FastJet::PseudoJetMomentTool<Double32_t>*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLPseudoJetMomentToollEDouble32_tgR(void *p) {
      typedef ::SpartyJet::FastJet::PseudoJetMomentTool<Double32_t> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::PseudoJetMomentTool<Double32_t>

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLFastJetcLcLMassFunction(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::FastJet::MassFunction : new ::SpartyJet::FastJet::MassFunction;
   }
   static void *newArray_SpartyJetcLcLFastJetcLcLMassFunction(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::FastJet::MassFunction[nElements] : new ::SpartyJet::FastJet::MassFunction[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLMassFunction(void *p) {
      delete ((::SpartyJet::FastJet::MassFunction*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLMassFunction(void *p) {
      delete [] ((::SpartyJet::FastJet::MassFunction*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLMassFunction(void *p) {
      typedef ::SpartyJet::FastJet::MassFunction current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::MassFunction

namespace {
  void TriggerDictionaryInitialization_FastJetToolsDict_Impl() {
    static const char* headers[] = {
"FastJetFinder.hh",
"FastJetTool.hh",
"FastJetUtils.hh",
"PseudoJetMoment.hh",
"PtDensityTool.hh",
"SelectorTool.hh",
"YSplitterTool.hh",
0
    };
    static const char* includePaths[] = {
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2",
"/usr/local/include",
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2/FastJetTools/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace SpartyJet{namespace FastJet{class __attribute__((annotate("$clingAutoload$FastJetFinder.hh")))  FastJetFinder;}}
namespace SpartyJet{namespace FastJet{class __attribute__((annotate("$clingAutoload$FastJetFinder.hh")))  FastJetRecluster;}}
namespace SpartyJet{namespace FastJet{class __attribute__((annotate("$clingAutoload$YSplitterTool.hh")))  YSplitterTool;}}
namespace SpartyJet{namespace FastJet{class __attribute__((annotate("$clingAutoload$PtDensityTool.hh")))  PtDensityTool;}}
namespace SpartyJet{namespace FastJet{class __attribute__((annotate("$clingAutoload$FastJetTool.hh")))  FastJetTool;}}
namespace SpartyJet{namespace FastJet{class __attribute__((annotate("$clingAutoload$FastJetTool.hh")))  PseudoJetTool;}}
namespace SpartyJet{namespace FastJet{class __attribute__((annotate("$clingAutoload$SelectorTool.hh")))  SelectorTool;}}
namespace SpartyJet{namespace FastJet{template <class T = float> class __attribute__((annotate("$clingAutoload$PseudoJetMoment.hh")))  PseudoJetMoment;
}}
typedef double Double32_t __attribute__((annotate("$clingAutoload$RtypesCore.h"))) ;
namespace SpartyJet{namespace FastJet{template <class T = Double32_t> class __attribute__((annotate("$clingAutoload$PseudoJetMoment.hh")))  PseudoJetMomentTool;
}}
namespace SpartyJet{namespace FastJet{class __attribute__((annotate("$clingAutoload$PseudoJetMoment.hh")))  MassFunction;}}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "FastJetFinder.hh"
#include "FastJetTool.hh"
#include "FastJetUtils.hh"
#include "PseudoJetMoment.hh"
#include "PtDensityTool.hh"
#include "SelectorTool.hh"
#include "YSplitterTool.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"SpartyJet::FastJet::FastJetFinder", payloadCode, "@",
"SpartyJet::FastJet::FastJetRecluster", payloadCode, "@",
"SpartyJet::FastJet::FastJetTool", payloadCode, "@",
"SpartyJet::FastJet::MassFunction", payloadCode, "@",
"SpartyJet::FastJet::PseudoJetMoment<Double32_t>", payloadCode, "@",
"SpartyJet::FastJet::PseudoJetMoment<float>", payloadCode, "@",
"SpartyJet::FastJet::PseudoJetMomentTool<Double32_t>", payloadCode, "@",
"SpartyJet::FastJet::PseudoJetMomentTool<float>", payloadCode, "@",
"SpartyJet::FastJet::PseudoJetTool", payloadCode, "@",
"SpartyJet::FastJet::PtDensityTool", payloadCode, "@",
"SpartyJet::FastJet::SelectorTool", payloadCode, "@",
"SpartyJet::FastJet::YSplitterTool", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("FastJetToolsDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_FastJetToolsDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_FastJetToolsDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_FastJetToolsDict() {
  TriggerDictionaryInitialization_FastJetToolsDict_Impl();
}
