// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME JetToolsDict

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
#include "CalorimeterSimTool.hh"
#include "EConversionTool.hh"
#include "EtaPhiMomentTool.hh"
#include "HardProcessMatchTool.hh"
#include "HullMomentTool.hh"
#include "JetAreaCorrectionTool.hh"
#include "JetForkTool.hh"
#include "JetMomentTool.hh"
#include "JetSelectorTool.hh"
#include "TopDownPruneTool.hh"
#include "cyl_geom.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *SpartyJetcLcLForkToolParent_Dictionary();
   static void SpartyJetcLcLForkToolParent_TClassManip(TClass*);
   static void *new_SpartyJetcLcLForkToolParent(void *p = 0);
   static void *newArray_SpartyJetcLcLForkToolParent(Long_t size, void *p);
   static void delete_SpartyJetcLcLForkToolParent(void *p);
   static void deleteArray_SpartyJetcLcLForkToolParent(void *p);
   static void destruct_SpartyJetcLcLForkToolParent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::ForkToolParent*)
   {
      ::SpartyJet::ForkToolParent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::ForkToolParent),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::ForkToolParent", "JetForkTool.hh", 39,
                  typeid(::SpartyJet::ForkToolParent), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLForkToolParent_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::ForkToolParent) );
      instance.SetNew(&new_SpartyJetcLcLForkToolParent);
      instance.SetNewArray(&newArray_SpartyJetcLcLForkToolParent);
      instance.SetDelete(&delete_SpartyJetcLcLForkToolParent);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLForkToolParent);
      instance.SetDestructor(&destruct_SpartyJetcLcLForkToolParent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::ForkToolParent*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::ForkToolParent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::ForkToolParent*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLForkToolParent_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::ForkToolParent*)0x0)->GetClass();
      SpartyJetcLcLForkToolParent_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLForkToolParent_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLForkToolChild_Dictionary();
   static void SpartyJetcLcLForkToolChild_TClassManip(TClass*);
   static void delete_SpartyJetcLcLForkToolChild(void *p);
   static void deleteArray_SpartyJetcLcLForkToolChild(void *p);
   static void destruct_SpartyJetcLcLForkToolChild(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::ForkToolChild*)
   {
      ::SpartyJet::ForkToolChild *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::ForkToolChild),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::ForkToolChild", "JetForkTool.hh", 56,
                  typeid(::SpartyJet::ForkToolChild), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLForkToolChild_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::ForkToolChild) );
      instance.SetDelete(&delete_SpartyJetcLcLForkToolChild);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLForkToolChild);
      instance.SetDestructor(&destruct_SpartyJetcLcLForkToolChild);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::ForkToolChild*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::ForkToolChild*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::ForkToolChild*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLForkToolChild_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::ForkToolChild*)0x0)->GetClass();
      SpartyJetcLcLForkToolChild_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLForkToolChild_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetSelectorTool_Dictionary();
   static void SpartyJetcLcLJetSelectorTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLJetSelectorTool(void *p);
   static void deleteArray_SpartyJetcLcLJetSelectorTool(void *p);
   static void destruct_SpartyJetcLcLJetSelectorTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetSelectorTool*)
   {
      ::SpartyJet::JetSelectorTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetSelectorTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetSelectorTool", "JetSelectorTool.hh", 32,
                  typeid(::SpartyJet::JetSelectorTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetSelectorTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetSelectorTool) );
      instance.SetDelete(&delete_SpartyJetcLcLJetSelectorTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetSelectorTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetSelectorTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetSelectorTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetSelectorTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetSelectorTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetSelectorTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetSelectorTool*)0x0)->GetClass();
      SpartyJetcLcLJetSelectorTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetSelectorTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetPtSelectorTool_Dictionary();
   static void SpartyJetcLcLJetPtSelectorTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetPtSelectorTool(void *p = 0);
   static void *newArray_SpartyJetcLcLJetPtSelectorTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetPtSelectorTool(void *p);
   static void deleteArray_SpartyJetcLcLJetPtSelectorTool(void *p);
   static void destruct_SpartyJetcLcLJetPtSelectorTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetPtSelectorTool*)
   {
      ::SpartyJet::JetPtSelectorTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetPtSelectorTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetPtSelectorTool", "JetSelectorTool.hh", 55,
                  typeid(::SpartyJet::JetPtSelectorTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetPtSelectorTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetPtSelectorTool) );
      instance.SetNew(&new_SpartyJetcLcLJetPtSelectorTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetPtSelectorTool);
      instance.SetDelete(&delete_SpartyJetcLcLJetPtSelectorTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetPtSelectorTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetPtSelectorTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetPtSelectorTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetPtSelectorTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetPtSelectorTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetPtSelectorTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetPtSelectorTool*)0x0)->GetClass();
      SpartyJetcLcLJetPtSelectorTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetPtSelectorTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetEtaCentralSelectorTool_Dictionary();
   static void SpartyJetcLcLJetEtaCentralSelectorTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetEtaCentralSelectorTool(void *p = 0);
   static void *newArray_SpartyJetcLcLJetEtaCentralSelectorTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetEtaCentralSelectorTool(void *p);
   static void deleteArray_SpartyJetcLcLJetEtaCentralSelectorTool(void *p);
   static void destruct_SpartyJetcLcLJetEtaCentralSelectorTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetEtaCentralSelectorTool*)
   {
      ::SpartyJet::JetEtaCentralSelectorTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetEtaCentralSelectorTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetEtaCentralSelectorTool", "JetSelectorTool.hh", 76,
                  typeid(::SpartyJet::JetEtaCentralSelectorTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetEtaCentralSelectorTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetEtaCentralSelectorTool) );
      instance.SetNew(&new_SpartyJetcLcLJetEtaCentralSelectorTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetEtaCentralSelectorTool);
      instance.SetDelete(&delete_SpartyJetcLcLJetEtaCentralSelectorTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetEtaCentralSelectorTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetEtaCentralSelectorTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetEtaCentralSelectorTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetEtaCentralSelectorTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetEtaCentralSelectorTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetEtaCentralSelectorTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetEtaCentralSelectorTool*)0x0)->GetClass();
      SpartyJetcLcLJetEtaCentralSelectorTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetEtaCentralSelectorTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetEtaForwardSelectorTool_Dictionary();
   static void SpartyJetcLcLJetEtaForwardSelectorTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetEtaForwardSelectorTool(void *p = 0);
   static void *newArray_SpartyJetcLcLJetEtaForwardSelectorTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetEtaForwardSelectorTool(void *p);
   static void deleteArray_SpartyJetcLcLJetEtaForwardSelectorTool(void *p);
   static void destruct_SpartyJetcLcLJetEtaForwardSelectorTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetEtaForwardSelectorTool*)
   {
      ::SpartyJet::JetEtaForwardSelectorTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetEtaForwardSelectorTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetEtaForwardSelectorTool", "JetSelectorTool.hh", 84,
                  typeid(::SpartyJet::JetEtaForwardSelectorTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetEtaForwardSelectorTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetEtaForwardSelectorTool) );
      instance.SetNew(&new_SpartyJetcLcLJetEtaForwardSelectorTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetEtaForwardSelectorTool);
      instance.SetDelete(&delete_SpartyJetcLcLJetEtaForwardSelectorTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetEtaForwardSelectorTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetEtaForwardSelectorTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetEtaForwardSelectorTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetEtaForwardSelectorTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetEtaForwardSelectorTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetEtaForwardSelectorTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetEtaForwardSelectorTool*)0x0)->GetClass();
      SpartyJetcLcLJetEtaForwardSelectorTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetEtaForwardSelectorTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetMassSelectorTool_Dictionary();
   static void SpartyJetcLcLJetMassSelectorTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetMassSelectorTool(void *p = 0);
   static void *newArray_SpartyJetcLcLJetMassSelectorTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetMassSelectorTool(void *p);
   static void deleteArray_SpartyJetcLcLJetMassSelectorTool(void *p);
   static void destruct_SpartyJetcLcLJetMassSelectorTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetMassSelectorTool*)
   {
      ::SpartyJet::JetMassSelectorTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetMassSelectorTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetMassSelectorTool", "JetSelectorTool.hh", 102,
                  typeid(::SpartyJet::JetMassSelectorTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetMassSelectorTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetMassSelectorTool) );
      instance.SetNew(&new_SpartyJetcLcLJetMassSelectorTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetMassSelectorTool);
      instance.SetDelete(&delete_SpartyJetcLcLJetMassSelectorTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetMassSelectorTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetMassSelectorTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetMassSelectorTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetMassSelectorTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetMassSelectorTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetMassSelectorTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetMassSelectorTool*)0x0)->GetClass();
      SpartyJetcLcLJetMassSelectorTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetMassSelectorTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetInputPdgIdSelectorTool_Dictionary();
   static void SpartyJetcLcLJetInputPdgIdSelectorTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetInputPdgIdSelectorTool(void *p = 0);
   static void *newArray_SpartyJetcLcLJetInputPdgIdSelectorTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetInputPdgIdSelectorTool(void *p);
   static void deleteArray_SpartyJetcLcLJetInputPdgIdSelectorTool(void *p);
   static void destruct_SpartyJetcLcLJetInputPdgIdSelectorTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetInputPdgIdSelectorTool*)
   {
      ::SpartyJet::JetInputPdgIdSelectorTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetInputPdgIdSelectorTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetInputPdgIdSelectorTool", "JetSelectorTool.hh", 111,
                  typeid(::SpartyJet::JetInputPdgIdSelectorTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetInputPdgIdSelectorTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetInputPdgIdSelectorTool) );
      instance.SetNew(&new_SpartyJetcLcLJetInputPdgIdSelectorTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetInputPdgIdSelectorTool);
      instance.SetDelete(&delete_SpartyJetcLcLJetInputPdgIdSelectorTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetInputPdgIdSelectorTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetInputPdgIdSelectorTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetInputPdgIdSelectorTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetInputPdgIdSelectorTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetInputPdgIdSelectorTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetInputPdgIdSelectorTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetInputPdgIdSelectorTool*)0x0)->GetClass();
      SpartyJetcLcLJetInputPdgIdSelectorTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetInputPdgIdSelectorTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetPtORESelectorTool_Dictionary();
   static void SpartyJetcLcLJetPtORESelectorTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetPtORESelectorTool(void *p = 0);
   static void *newArray_SpartyJetcLcLJetPtORESelectorTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetPtORESelectorTool(void *p);
   static void deleteArray_SpartyJetcLcLJetPtORESelectorTool(void *p);
   static void destruct_SpartyJetcLcLJetPtORESelectorTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetPtORESelectorTool*)
   {
      ::SpartyJet::JetPtORESelectorTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetPtORESelectorTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetPtORESelectorTool", "JetSelectorTool.hh", 67,
                  typeid(::SpartyJet::JetPtORESelectorTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetPtORESelectorTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetPtORESelectorTool) );
      instance.SetNew(&new_SpartyJetcLcLJetPtORESelectorTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetPtORESelectorTool);
      instance.SetDelete(&delete_SpartyJetcLcLJetPtORESelectorTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetPtORESelectorTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetPtORESelectorTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetPtORESelectorTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetPtORESelectorTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetPtORESelectorTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetPtORESelectorTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetPtORESelectorTool*)0x0)->GetClass();
      SpartyJetcLcLJetPtORESelectorTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetPtORESelectorTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetMomentSelectorToollEfloatgR_Dictionary();
   static void SpartyJetcLcLJetMomentSelectorToollEfloatgR_TClassManip(TClass*);
   static void delete_SpartyJetcLcLJetMomentSelectorToollEfloatgR(void *p);
   static void deleteArray_SpartyJetcLcLJetMomentSelectorToollEfloatgR(void *p);
   static void destruct_SpartyJetcLcLJetMomentSelectorToollEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetMomentSelectorTool<float>*)
   {
      ::SpartyJet::JetMomentSelectorTool<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetMomentSelectorTool<float>),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetMomentSelectorTool<float>", "JetSelectorTool.hh", 124,
                  typeid(::SpartyJet::JetMomentSelectorTool<float>), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetMomentSelectorToollEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetMomentSelectorTool<float>) );
      instance.SetDelete(&delete_SpartyJetcLcLJetMomentSelectorToollEfloatgR);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetMomentSelectorToollEfloatgR);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetMomentSelectorToollEfloatgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetMomentSelectorTool<float>*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetMomentSelectorTool<float>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetMomentSelectorTool<float>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetMomentSelectorToollEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetMomentSelectorTool<float>*)0x0)->GetClass();
      SpartyJetcLcLJetMomentSelectorToollEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetMomentSelectorToollEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetMomentSelectorToollEintgR_Dictionary();
   static void SpartyJetcLcLJetMomentSelectorToollEintgR_TClassManip(TClass*);
   static void delete_SpartyJetcLcLJetMomentSelectorToollEintgR(void *p);
   static void deleteArray_SpartyJetcLcLJetMomentSelectorToollEintgR(void *p);
   static void destruct_SpartyJetcLcLJetMomentSelectorToollEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetMomentSelectorTool<int>*)
   {
      ::SpartyJet::JetMomentSelectorTool<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetMomentSelectorTool<int>),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetMomentSelectorTool<int>", "JetSelectorTool.hh", 124,
                  typeid(::SpartyJet::JetMomentSelectorTool<int>), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetMomentSelectorToollEintgR_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetMomentSelectorTool<int>) );
      instance.SetDelete(&delete_SpartyJetcLcLJetMomentSelectorToollEintgR);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetMomentSelectorToollEintgR);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetMomentSelectorToollEintgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetMomentSelectorTool<int>*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetMomentSelectorTool<int>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetMomentSelectorTool<int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetMomentSelectorToollEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetMomentSelectorTool<int>*)0x0)->GetClass();
      SpartyJetcLcLJetMomentSelectorToollEintgR_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetMomentSelectorToollEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLEtaPhiMomentTool_Dictionary();
   static void SpartyJetcLcLEtaPhiMomentTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLEtaPhiMomentTool(void *p = 0);
   static void *newArray_SpartyJetcLcLEtaPhiMomentTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLEtaPhiMomentTool(void *p);
   static void deleteArray_SpartyJetcLcLEtaPhiMomentTool(void *p);
   static void destruct_SpartyJetcLcLEtaPhiMomentTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::EtaPhiMomentTool*)
   {
      ::SpartyJet::EtaPhiMomentTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::EtaPhiMomentTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::EtaPhiMomentTool", "EtaPhiMomentTool.hh", 31,
                  typeid(::SpartyJet::EtaPhiMomentTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLEtaPhiMomentTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::EtaPhiMomentTool) );
      instance.SetNew(&new_SpartyJetcLcLEtaPhiMomentTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLEtaPhiMomentTool);
      instance.SetDelete(&delete_SpartyJetcLcLEtaPhiMomentTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLEtaPhiMomentTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLEtaPhiMomentTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::EtaPhiMomentTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::EtaPhiMomentTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::EtaPhiMomentTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLEtaPhiMomentTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::EtaPhiMomentTool*)0x0)->GetClass();
      SpartyJetcLcLEtaPhiMomentTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLEtaPhiMomentTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLEConversionTool_Dictionary();
   static void SpartyJetcLcLEConversionTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLEConversionTool(void *p);
   static void deleteArray_SpartyJetcLcLEConversionTool(void *p);
   static void destruct_SpartyJetcLcLEConversionTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::EConversionTool*)
   {
      ::SpartyJet::EConversionTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::EConversionTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::EConversionTool", "EConversionTool.hh", 32,
                  typeid(::SpartyJet::EConversionTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLEConversionTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::EConversionTool) );
      instance.SetDelete(&delete_SpartyJetcLcLEConversionTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLEConversionTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLEConversionTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::EConversionTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::EConversionTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::EConversionTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLEConversionTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::EConversionTool*)0x0)->GetClass();
      SpartyJetcLcLEConversionTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLEConversionTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLMomentArrayTestTool_Dictionary();
   static void SpartyJetcLcLMomentArrayTestTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLMomentArrayTestTool(void *p = 0);
   static void *newArray_SpartyJetcLcLMomentArrayTestTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLMomentArrayTestTool(void *p);
   static void deleteArray_SpartyJetcLcLMomentArrayTestTool(void *p);
   static void destruct_SpartyJetcLcLMomentArrayTestTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::MomentArrayTestTool*)
   {
      ::SpartyJet::MomentArrayTestTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::MomentArrayTestTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::MomentArrayTestTool", "EtaPhiMomentTool.hh", 39,
                  typeid(::SpartyJet::MomentArrayTestTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLMomentArrayTestTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::MomentArrayTestTool) );
      instance.SetNew(&new_SpartyJetcLcLMomentArrayTestTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLMomentArrayTestTool);
      instance.SetDelete(&delete_SpartyJetcLcLMomentArrayTestTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLMomentArrayTestTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLMomentArrayTestTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::MomentArrayTestTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::MomentArrayTestTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::MomentArrayTestTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLMomentArrayTestTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::MomentArrayTestTool*)0x0)->GetClass();
      SpartyJetcLcLMomentArrayTestTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLMomentArrayTestTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLHullMomentTool_Dictionary();
   static void SpartyJetcLcLHullMomentTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLHullMomentTool(void *p);
   static void deleteArray_SpartyJetcLcLHullMomentTool(void *p);
   static void destruct_SpartyJetcLcLHullMomentTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::HullMomentTool*)
   {
      ::SpartyJet::HullMomentTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::HullMomentTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::HullMomentTool", "HullMomentTool.hh", 31,
                  typeid(::SpartyJet::HullMomentTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLHullMomentTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::HullMomentTool) );
      instance.SetDelete(&delete_SpartyJetcLcLHullMomentTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLHullMomentTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLHullMomentTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::HullMomentTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::HullMomentTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::HullMomentTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLHullMomentTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::HullMomentTool*)0x0)->GetClass();
      SpartyJetcLcLHullMomentTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLHullMomentTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetAreaCorrectionTool_Dictionary();
   static void SpartyJetcLcLJetAreaCorrectionTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLJetAreaCorrectionTool(void *p);
   static void deleteArray_SpartyJetcLcLJetAreaCorrectionTool(void *p);
   static void destruct_SpartyJetcLcLJetAreaCorrectionTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetAreaCorrectionTool*)
   {
      ::SpartyJet::JetAreaCorrectionTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetAreaCorrectionTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetAreaCorrectionTool", "JetAreaCorrectionTool.hh", 32,
                  typeid(::SpartyJet::JetAreaCorrectionTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetAreaCorrectionTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetAreaCorrectionTool) );
      instance.SetDelete(&delete_SpartyJetcLcLJetAreaCorrectionTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetAreaCorrectionTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetAreaCorrectionTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetAreaCorrectionTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetAreaCorrectionTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetAreaCorrectionTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetAreaCorrectionTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetAreaCorrectionTool*)0x0)->GetClass();
      SpartyJetcLcLJetAreaCorrectionTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetAreaCorrectionTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLCalorimeterSimTool_Dictionary();
   static void SpartyJetcLcLCalorimeterSimTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLCalorimeterSimTool(void *p);
   static void deleteArray_SpartyJetcLcLCalorimeterSimTool(void *p);
   static void destruct_SpartyJetcLcLCalorimeterSimTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::CalorimeterSimTool*)
   {
      ::SpartyJet::CalorimeterSimTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::CalorimeterSimTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::CalorimeterSimTool", "CalorimeterSimTool.hh", 32,
                  typeid(::SpartyJet::CalorimeterSimTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLCalorimeterSimTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::CalorimeterSimTool) );
      instance.SetDelete(&delete_SpartyJetcLcLCalorimeterSimTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLCalorimeterSimTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLCalorimeterSimTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::CalorimeterSimTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::CalorimeterSimTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::CalorimeterSimTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLCalorimeterSimTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::CalorimeterSimTool*)0x0)->GetClass();
      SpartyJetcLcLCalorimeterSimTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLCalorimeterSimTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLHardProcessMatchTool_Dictionary();
   static void SpartyJetcLcLHardProcessMatchTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLHardProcessMatchTool(void *p = 0);
   static void *newArray_SpartyJetcLcLHardProcessMatchTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLHardProcessMatchTool(void *p);
   static void deleteArray_SpartyJetcLcLHardProcessMatchTool(void *p);
   static void destruct_SpartyJetcLcLHardProcessMatchTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::HardProcessMatchTool*)
   {
      ::SpartyJet::HardProcessMatchTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::HardProcessMatchTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::HardProcessMatchTool", "HardProcessMatchTool.hh", 31,
                  typeid(::SpartyJet::HardProcessMatchTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLHardProcessMatchTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::HardProcessMatchTool) );
      instance.SetNew(&new_SpartyJetcLcLHardProcessMatchTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLHardProcessMatchTool);
      instance.SetDelete(&delete_SpartyJetcLcLHardProcessMatchTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLHardProcessMatchTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLHardProcessMatchTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::HardProcessMatchTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::HardProcessMatchTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::HardProcessMatchTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLHardProcessMatchTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::HardProcessMatchTool*)0x0)->GetClass();
      SpartyJetcLcLHardProcessMatchTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLHardProcessMatchTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLTopDownPruneTool_Dictionary();
   static void SpartyJetcLcLTopDownPruneTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLTopDownPruneTool(void *p);
   static void deleteArray_SpartyJetcLcLTopDownPruneTool(void *p);
   static void destruct_SpartyJetcLcLTopDownPruneTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::TopDownPruneTool*)
   {
      ::SpartyJet::TopDownPruneTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::TopDownPruneTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::TopDownPruneTool", "TopDownPruneTool.hh", 41,
                  typeid(::SpartyJet::TopDownPruneTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLTopDownPruneTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::TopDownPruneTool) );
      instance.SetDelete(&delete_SpartyJetcLcLTopDownPruneTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLTopDownPruneTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLTopDownPruneTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::TopDownPruneTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::TopDownPruneTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::TopDownPruneTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLTopDownPruneTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::TopDownPruneTool*)0x0)->GetClass();
      SpartyJetcLcLTopDownPruneTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLTopDownPruneTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLMassDropTool_Dictionary();
   static void SpartyJetcLcLMassDropTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLMassDropTool(void *p = 0);
   static void *newArray_SpartyJetcLcLMassDropTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLMassDropTool(void *p);
   static void deleteArray_SpartyJetcLcLMassDropTool(void *p);
   static void destruct_SpartyJetcLcLMassDropTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::MassDropTool*)
   {
      ::SpartyJet::MassDropTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::MassDropTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::MassDropTool", "TopDownPruneTool.hh", 100,
                  typeid(::SpartyJet::MassDropTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLMassDropTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::MassDropTool) );
      instance.SetNew(&new_SpartyJetcLcLMassDropTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLMassDropTool);
      instance.SetDelete(&delete_SpartyJetcLcLMassDropTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLMassDropTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLMassDropTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::MassDropTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::MassDropTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::MassDropTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLMassDropTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::MassDropTool*)0x0)->GetClass();
      SpartyJetcLcLMassDropTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLMassDropTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJHPruneTool_Dictionary();
   static void SpartyJetcLcLJHPruneTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJHPruneTool(void *p = 0);
   static void *newArray_SpartyJetcLcLJHPruneTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLJHPruneTool(void *p);
   static void deleteArray_SpartyJetcLcLJHPruneTool(void *p);
   static void destruct_SpartyJetcLcLJHPruneTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JHPruneTool*)
   {
      ::SpartyJet::JHPruneTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JHPruneTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JHPruneTool", "TopDownPruneTool.hh", 113,
                  typeid(::SpartyJet::JHPruneTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJHPruneTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JHPruneTool) );
      instance.SetNew(&new_SpartyJetcLcLJHPruneTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLJHPruneTool);
      instance.SetDelete(&delete_SpartyJetcLcLJHPruneTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJHPruneTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLJHPruneTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JHPruneTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JHPruneTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JHPruneTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJHPruneTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JHPruneTool*)0x0)->GetClass();
      SpartyJetcLcLJHPruneTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJHPruneTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLSubjetCutTool_Dictionary();
   static void SpartyJetcLcLSubjetCutTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLSubjetCutTool(void *p);
   static void deleteArray_SpartyJetcLcLSubjetCutTool(void *p);
   static void destruct_SpartyJetcLcLSubjetCutTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::SubjetCutTool*)
   {
      ::SpartyJet::SubjetCutTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::SubjetCutTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::SubjetCutTool", "TopDownPruneTool.hh", 84,
                  typeid(::SpartyJet::SubjetCutTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLSubjetCutTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::SubjetCutTool) );
      instance.SetDelete(&delete_SpartyJetcLcLSubjetCutTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLSubjetCutTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLSubjetCutTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::SubjetCutTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::SubjetCutTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::SubjetCutTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLSubjetCutTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::SubjetCutTool*)0x0)->GetClass();
      SpartyJetcLcLSubjetCutTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLSubjetCutTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLSubjetMergeTool_Dictionary();
   static void SpartyJetcLcLSubjetMergeTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLSubjetMergeTool(void *p);
   static void deleteArray_SpartyJetcLcLSubjetMergeTool(void *p);
   static void destruct_SpartyJetcLcLSubjetMergeTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::SubjetMergeTool*)
   {
      ::SpartyJet::SubjetMergeTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::SubjetMergeTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::SubjetMergeTool", "TopDownPruneTool.hh", 128,
                  typeid(::SpartyJet::SubjetMergeTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLSubjetMergeTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::SubjetMergeTool) );
      instance.SetDelete(&delete_SpartyJetcLcLSubjetMergeTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLSubjetMergeTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLSubjetMergeTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::SubjetMergeTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::SubjetMergeTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::SubjetMergeTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLSubjetMergeTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::SubjetMergeTool*)0x0)->GetClass();
      SpartyJetcLcLSubjetMergeTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLSubjetMergeTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLMinMassTool_Dictionary();
   static void SpartyJetcLcLMinMassTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLMinMassTool(void *p = 0);
   static void *newArray_SpartyJetcLcLMinMassTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLMinMassTool(void *p);
   static void deleteArray_SpartyJetcLcLMinMassTool(void *p);
   static void destruct_SpartyJetcLcLMinMassTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::MinMassTool*)
   {
      ::SpartyJet::MinMassTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::MinMassTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::MinMassTool", "TopDownPruneTool.hh", 139,
                  typeid(::SpartyJet::MinMassTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLMinMassTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::MinMassTool) );
      instance.SetNew(&new_SpartyJetcLcLMinMassTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLMinMassTool);
      instance.SetDelete(&delete_SpartyJetcLcLMinMassTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLMinMassTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLMinMassTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::MinMassTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::MinMassTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::MinMassTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLMinMassTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::MinMassTool*)0x0)->GetClass();
      SpartyJetcLcLMinMassTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLMinMassTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLUnclusterTool_Dictionary();
   static void SpartyJetcLcLUnclusterTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLUnclusterTool(void *p);
   static void deleteArray_SpartyJetcLcLUnclusterTool(void *p);
   static void destruct_SpartyJetcLcLUnclusterTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::UnclusterTool*)
   {
      ::SpartyJet::UnclusterTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::UnclusterTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::UnclusterTool", "TopDownPruneTool.hh", 149,
                  typeid(::SpartyJet::UnclusterTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLUnclusterTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::UnclusterTool) );
      instance.SetDelete(&delete_SpartyJetcLcLUnclusterTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLUnclusterTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLUnclusterTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::UnclusterTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::UnclusterTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::UnclusterTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLUnclusterTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::UnclusterTool*)0x0)->GetClass();
      SpartyJetcLcLUnclusterTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLUnclusterTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetMomentTool_Dictionary();
   static void SpartyJetcLcLJetMomentTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLJetMomentTool(void *p);
   static void deleteArray_SpartyJetcLcLJetMomentTool(void *p);
   static void destruct_SpartyJetcLcLJetMomentTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetMomentTool*)
   {
      ::SpartyJet::JetMomentTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetMomentTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetMomentTool", "JetMomentTool.hh", 41,
                  typeid(::SpartyJet::JetMomentTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetMomentTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetMomentTool) );
      instance.SetDelete(&delete_SpartyJetcLcLJetMomentTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetMomentTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetMomentTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetMomentTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetMomentTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetMomentTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetMomentTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetMomentTool*)0x0)->GetClass();
      SpartyJetcLcLJetMomentTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetMomentTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLEventMomentTool_Dictionary();
   static void SpartyJetcLcLEventMomentTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLEventMomentTool(void *p);
   static void deleteArray_SpartyJetcLcLEventMomentTool(void *p);
   static void destruct_SpartyJetcLcLEventMomentTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::EventMomentTool*)
   {
      ::SpartyJet::EventMomentTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::EventMomentTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::EventMomentTool", "JetMomentTool.hh", 53,
                  typeid(::SpartyJet::EventMomentTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLEventMomentTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::EventMomentTool) );
      instance.SetDelete(&delete_SpartyJetcLcLEventMomentTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLEventMomentTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLEventMomentTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::EventMomentTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::EventMomentTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::EventMomentTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLEventMomentTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::EventMomentTool*)0x0)->GetClass();
      SpartyJetcLcLEventMomentTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLEventMomentTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetMomentlEDouble32_tgR_Dictionary();
   static void SpartyJetcLcLJetMomentlEDouble32_tgR_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetMomentlEDouble32_tgR(void *p = 0);
   static void *newArray_SpartyJetcLcLJetMomentlEDouble32_tgR(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetMomentlEDouble32_tgR(void *p);
   static void deleteArray_SpartyJetcLcLJetMomentlEDouble32_tgR(void *p);
   static void destruct_SpartyJetcLcLJetMomentlEDouble32_tgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetMoment<Double32_t>*)
   {
      ::SpartyJet::JetMoment<Double32_t> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetMoment<Double32_t>),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetMoment<Double32_t>", "JetCore/JetMoment.hh", 66,
                  typeid(::SpartyJet::JetMoment<Double32_t>), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetMomentlEDouble32_tgR_Dictionary, isa_proxy, 4,
                  sizeof(::SpartyJet::JetMoment<Double32_t>) );
      instance.SetNew(&new_SpartyJetcLcLJetMomentlEDouble32_tgR);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetMomentlEDouble32_tgR);
      instance.SetDelete(&delete_SpartyJetcLcLJetMomentlEDouble32_tgR);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetMomentlEDouble32_tgR);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetMomentlEDouble32_tgR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetMoment<Double32_t>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetMomentlEDouble32_tgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetMoment<Double32_t>*)0x0)->GetClass();
      SpartyJetcLcLJetMomentlEDouble32_tgR_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetMomentlEDouble32_tgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLHeavierSubjetMass_Dictionary();
   static void SpartyJetcLcLHeavierSubjetMass_TClassManip(TClass*);
   static void *new_SpartyJetcLcLHeavierSubjetMass(void *p = 0);
   static void *newArray_SpartyJetcLcLHeavierSubjetMass(Long_t size, void *p);
   static void delete_SpartyJetcLcLHeavierSubjetMass(void *p);
   static void deleteArray_SpartyJetcLcLHeavierSubjetMass(void *p);
   static void destruct_SpartyJetcLcLHeavierSubjetMass(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::HeavierSubjetMass*)
   {
      ::SpartyJet::HeavierSubjetMass *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::HeavierSubjetMass),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::HeavierSubjetMass", "JetMomentTool.hh", 66,
                  typeid(::SpartyJet::HeavierSubjetMass), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLHeavierSubjetMass_Dictionary, isa_proxy, 4,
                  sizeof(::SpartyJet::HeavierSubjetMass) );
      instance.SetNew(&new_SpartyJetcLcLHeavierSubjetMass);
      instance.SetNewArray(&newArray_SpartyJetcLcLHeavierSubjetMass);
      instance.SetDelete(&delete_SpartyJetcLcLHeavierSubjetMass);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLHeavierSubjetMass);
      instance.SetDestructor(&destruct_SpartyJetcLcLHeavierSubjetMass);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::HeavierSubjetMass*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::HeavierSubjetMass*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::HeavierSubjetMass*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLHeavierSubjetMass_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::HeavierSubjetMass*)0x0)->GetClass();
      SpartyJetcLcLHeavierSubjetMass_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLHeavierSubjetMass_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLMassMoment_Dictionary();
   static void SpartyJetcLcLMassMoment_TClassManip(TClass*);
   static void *new_SpartyJetcLcLMassMoment(void *p = 0);
   static void *newArray_SpartyJetcLcLMassMoment(Long_t size, void *p);
   static void delete_SpartyJetcLcLMassMoment(void *p);
   static void deleteArray_SpartyJetcLcLMassMoment(void *p);
   static void destruct_SpartyJetcLcLMassMoment(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::MassMoment*)
   {
      ::SpartyJet::MassMoment *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::MassMoment),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::MassMoment", "JetMomentTool.hh", 98,
                  typeid(::SpartyJet::MassMoment), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLMassMoment_Dictionary, isa_proxy, 4,
                  sizeof(::SpartyJet::MassMoment) );
      instance.SetNew(&new_SpartyJetcLcLMassMoment);
      instance.SetNewArray(&newArray_SpartyJetcLcLMassMoment);
      instance.SetDelete(&delete_SpartyJetcLcLMassMoment);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLMassMoment);
      instance.SetDestructor(&destruct_SpartyJetcLcLMassMoment);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::MassMoment*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::MassMoment*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::MassMoment*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLMassMoment_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::MassMoment*)0x0)->GetClass();
      SpartyJetcLcLMassMoment_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLMassMoment_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLPtMoment_Dictionary();
   static void SpartyJetcLcLPtMoment_TClassManip(TClass*);
   static void *new_SpartyJetcLcLPtMoment(void *p = 0);
   static void *newArray_SpartyJetcLcLPtMoment(Long_t size, void *p);
   static void delete_SpartyJetcLcLPtMoment(void *p);
   static void deleteArray_SpartyJetcLcLPtMoment(void *p);
   static void destruct_SpartyJetcLcLPtMoment(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::PtMoment*)
   {
      ::SpartyJet::PtMoment *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::PtMoment),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::PtMoment", "JetMomentTool.hh", 106,
                  typeid(::SpartyJet::PtMoment), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLPtMoment_Dictionary, isa_proxy, 4,
                  sizeof(::SpartyJet::PtMoment) );
      instance.SetNew(&new_SpartyJetcLcLPtMoment);
      instance.SetNewArray(&newArray_SpartyJetcLcLPtMoment);
      instance.SetDelete(&delete_SpartyJetcLcLPtMoment);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLPtMoment);
      instance.SetDestructor(&destruct_SpartyJetcLcLPtMoment);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::PtMoment*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::PtMoment*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::PtMoment*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLPtMoment_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::PtMoment*)0x0)->GetClass();
      SpartyJetcLcLPtMoment_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLPtMoment_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFinalDij_Dictionary();
   static void SpartyJetcLcLFinalDij_TClassManip(TClass*);
   static void *new_SpartyJetcLcLFinalDij(void *p = 0);
   static void *newArray_SpartyJetcLcLFinalDij(Long_t size, void *p);
   static void delete_SpartyJetcLcLFinalDij(void *p);
   static void deleteArray_SpartyJetcLcLFinalDij(void *p);
   static void destruct_SpartyJetcLcLFinalDij(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FinalDij*)
   {
      ::SpartyJet::FinalDij *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FinalDij),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FinalDij", "JetMomentTool.hh", 89,
                  typeid(::SpartyJet::FinalDij), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFinalDij_Dictionary, isa_proxy, 4,
                  sizeof(::SpartyJet::FinalDij) );
      instance.SetNew(&new_SpartyJetcLcLFinalDij);
      instance.SetNewArray(&newArray_SpartyJetcLcLFinalDij);
      instance.SetDelete(&delete_SpartyJetcLcLFinalDij);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFinalDij);
      instance.SetDestructor(&destruct_SpartyJetcLcLFinalDij);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FinalDij*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FinalDij*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FinalDij*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFinalDij_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FinalDij*)0x0)->GetClass();
      SpartyJetcLcLFinalDij_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFinalDij_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLzMoment_Dictionary();
   static void SpartyJetcLcLzMoment_TClassManip(TClass*);
   static void *new_SpartyJetcLcLzMoment(void *p = 0);
   static void *newArray_SpartyJetcLcLzMoment(Long_t size, void *p);
   static void delete_SpartyJetcLcLzMoment(void *p);
   static void deleteArray_SpartyJetcLcLzMoment(void *p);
   static void destruct_SpartyJetcLcLzMoment(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::zMoment*)
   {
      ::SpartyJet::zMoment *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::zMoment),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::zMoment", "JetMomentTool.hh", 114,
                  typeid(::SpartyJet::zMoment), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLzMoment_Dictionary, isa_proxy, 4,
                  sizeof(::SpartyJet::zMoment) );
      instance.SetNew(&new_SpartyJetcLcLzMoment);
      instance.SetNewArray(&newArray_SpartyJetcLcLzMoment);
      instance.SetDelete(&delete_SpartyJetcLcLzMoment);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLzMoment);
      instance.SetDestructor(&destruct_SpartyJetcLcLzMoment);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::zMoment*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::zMoment*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::zMoment*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLzMoment_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::zMoment*)0x0)->GetClass();
      SpartyJetcLcLzMoment_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLzMoment_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLDeltaRMoment_Dictionary();
   static void SpartyJetcLcLDeltaRMoment_TClassManip(TClass*);
   static void *new_SpartyJetcLcLDeltaRMoment(void *p = 0);
   static void *newArray_SpartyJetcLcLDeltaRMoment(Long_t size, void *p);
   static void delete_SpartyJetcLcLDeltaRMoment(void *p);
   static void deleteArray_SpartyJetcLcLDeltaRMoment(void *p);
   static void destruct_SpartyJetcLcLDeltaRMoment(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::DeltaRMoment*)
   {
      ::SpartyJet::DeltaRMoment *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::DeltaRMoment),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::DeltaRMoment", "JetMomentTool.hh", 131,
                  typeid(::SpartyJet::DeltaRMoment), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLDeltaRMoment_Dictionary, isa_proxy, 4,
                  sizeof(::SpartyJet::DeltaRMoment) );
      instance.SetNew(&new_SpartyJetcLcLDeltaRMoment);
      instance.SetNewArray(&newArray_SpartyJetcLcLDeltaRMoment);
      instance.SetDelete(&delete_SpartyJetcLcLDeltaRMoment);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLDeltaRMoment);
      instance.SetDestructor(&destruct_SpartyJetcLcLDeltaRMoment);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::DeltaRMoment*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::DeltaRMoment*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::DeltaRMoment*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLDeltaRMoment_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::DeltaRMoment*)0x0)->GetClass();
      SpartyJetcLcLDeltaRMoment_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLDeltaRMoment_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR_Dictionary();
   static void SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR(void *p = 0);
   static void *newArray_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR(void *p);
   static void deleteArray_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR(void *p);
   static void destruct_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetMoment<vector<Double32_t> >*)
   {
      ::SpartyJet::JetMoment<vector<Double32_t> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetMoment<vector<Double32_t> >),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetMoment<vector<Double32_t> >", "JetCore/JetMoment.hh", 66,
                  typeid(::SpartyJet::JetMoment<vector<Double32_t> >), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(::SpartyJet::JetMoment<vector<Double32_t> >) );
      instance.SetNew(&new_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR);
      instance.SetDelete(&delete_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetMoment<vector<Double32_t> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetMoment<vector<Double32_t> >*)0x0)->GetClass();
      SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLEventMomentlEDouble32_tgR_Dictionary();
   static void SpartyJetcLcLEventMomentlEDouble32_tgR_TClassManip(TClass*);
   static void *new_SpartyJetcLcLEventMomentlEDouble32_tgR(void *p = 0);
   static void *newArray_SpartyJetcLcLEventMomentlEDouble32_tgR(Long_t size, void *p);
   static void delete_SpartyJetcLcLEventMomentlEDouble32_tgR(void *p);
   static void deleteArray_SpartyJetcLcLEventMomentlEDouble32_tgR(void *p);
   static void destruct_SpartyJetcLcLEventMomentlEDouble32_tgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::EventMoment<Double32_t>*)
   {
      ::SpartyJet::EventMoment<Double32_t> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::EventMoment<Double32_t>),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::EventMoment<Double32_t>", "JetCore/JetMoment.hh", 103,
                  typeid(::SpartyJet::EventMoment<Double32_t>), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLEventMomentlEDouble32_tgR_Dictionary, isa_proxy, 4,
                  sizeof(::SpartyJet::EventMoment<Double32_t>) );
      instance.SetNew(&new_SpartyJetcLcLEventMomentlEDouble32_tgR);
      instance.SetNewArray(&newArray_SpartyJetcLcLEventMomentlEDouble32_tgR);
      instance.SetDelete(&delete_SpartyJetcLcLEventMomentlEDouble32_tgR);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLEventMomentlEDouble32_tgR);
      instance.SetDestructor(&destruct_SpartyJetcLcLEventMomentlEDouble32_tgR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::EventMoment<Double32_t>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLEventMomentlEDouble32_tgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::EventMoment<Double32_t>*)0x0)->GetClass();
      SpartyJetcLcLEventMomentlEDouble32_tgR_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLEventMomentlEDouble32_tgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR_Dictionary();
   static void SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR_TClassManip(TClass*);
   static void *new_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR(void *p = 0);
   static void *newArray_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR(Long_t size, void *p);
   static void delete_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR(void *p);
   static void deleteArray_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR(void *p);
   static void destruct_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::EventMoment<vector<Double32_t> >*)
   {
      ::SpartyJet::EventMoment<vector<Double32_t> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::EventMoment<vector<Double32_t> >),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::EventMoment<vector<Double32_t> >", "JetCore/JetMoment.hh", 103,
                  typeid(::SpartyJet::EventMoment<vector<Double32_t> >), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(::SpartyJet::EventMoment<vector<Double32_t> >) );
      instance.SetNew(&new_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR);
      instance.SetNewArray(&newArray_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR);
      instance.SetDelete(&delete_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR);
      instance.SetDestructor(&destruct_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::EventMoment<vector<Double32_t> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::EventMoment<vector<Double32_t> >*)0x0)->GetClass();
      SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLDijetMassMoment_Dictionary();
   static void SpartyJetcLcLDijetMassMoment_TClassManip(TClass*);
   static void *new_SpartyJetcLcLDijetMassMoment(void *p = 0);
   static void *newArray_SpartyJetcLcLDijetMassMoment(Long_t size, void *p);
   static void delete_SpartyJetcLcLDijetMassMoment(void *p);
   static void deleteArray_SpartyJetcLcLDijetMassMoment(void *p);
   static void destruct_SpartyJetcLcLDijetMassMoment(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::DijetMassMoment*)
   {
      ::SpartyJet::DijetMassMoment *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::DijetMassMoment),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::DijetMassMoment", "JetMomentTool.hh", 153,
                  typeid(::SpartyJet::DijetMassMoment), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLDijetMassMoment_Dictionary, isa_proxy, 4,
                  sizeof(::SpartyJet::DijetMassMoment) );
      instance.SetNew(&new_SpartyJetcLcLDijetMassMoment);
      instance.SetNewArray(&newArray_SpartyJetcLcLDijetMassMoment);
      instance.SetDelete(&delete_SpartyJetcLcLDijetMassMoment);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLDijetMassMoment);
      instance.SetDestructor(&destruct_SpartyJetcLcLDijetMassMoment);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::DijetMassMoment*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::DijetMassMoment*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::DijetMassMoment*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLDijetMassMoment_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::DijetMassMoment*)0x0)->GetClass();
      SpartyJetcLcLDijetMassMoment_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLDijetMassMoment_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLTrijetMassMoment_Dictionary();
   static void SpartyJetcLcLTrijetMassMoment_TClassManip(TClass*);
   static void *new_SpartyJetcLcLTrijetMassMoment(void *p = 0);
   static void *newArray_SpartyJetcLcLTrijetMassMoment(Long_t size, void *p);
   static void delete_SpartyJetcLcLTrijetMassMoment(void *p);
   static void deleteArray_SpartyJetcLcLTrijetMassMoment(void *p);
   static void destruct_SpartyJetcLcLTrijetMassMoment(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::TrijetMassMoment*)
   {
      ::SpartyJet::TrijetMassMoment *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::TrijetMassMoment),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::TrijetMassMoment", "JetMomentTool.hh", 169,
                  typeid(::SpartyJet::TrijetMassMoment), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLTrijetMassMoment_Dictionary, isa_proxy, 4,
                  sizeof(::SpartyJet::TrijetMassMoment) );
      instance.SetNew(&new_SpartyJetcLcLTrijetMassMoment);
      instance.SetNewArray(&newArray_SpartyJetcLcLTrijetMassMoment);
      instance.SetDelete(&delete_SpartyJetcLcLTrijetMassMoment);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLTrijetMassMoment);
      instance.SetDestructor(&destruct_SpartyJetcLcLTrijetMassMoment);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::TrijetMassMoment*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::TrijetMassMoment*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::TrijetMassMoment*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLTrijetMassMoment_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::TrijetMassMoment*)0x0)->GetClass();
      SpartyJetcLcLTrijetMassMoment_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLTrijetMassMoment_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLTrijetPtMoment_Dictionary();
   static void SpartyJetcLcLTrijetPtMoment_TClassManip(TClass*);
   static void *new_SpartyJetcLcLTrijetPtMoment(void *p = 0);
   static void *newArray_SpartyJetcLcLTrijetPtMoment(Long_t size, void *p);
   static void delete_SpartyJetcLcLTrijetPtMoment(void *p);
   static void deleteArray_SpartyJetcLcLTrijetPtMoment(void *p);
   static void destruct_SpartyJetcLcLTrijetPtMoment(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::TrijetPtMoment*)
   {
      ::SpartyJet::TrijetPtMoment *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::TrijetPtMoment),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::TrijetPtMoment", "JetMomentTool.hh", 192,
                  typeid(::SpartyJet::TrijetPtMoment), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLTrijetPtMoment_Dictionary, isa_proxy, 4,
                  sizeof(::SpartyJet::TrijetPtMoment) );
      instance.SetNew(&new_SpartyJetcLcLTrijetPtMoment);
      instance.SetNewArray(&newArray_SpartyJetcLcLTrijetPtMoment);
      instance.SetDelete(&delete_SpartyJetcLcLTrijetPtMoment);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLTrijetPtMoment);
      instance.SetDestructor(&destruct_SpartyJetcLcLTrijetPtMoment);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::TrijetPtMoment*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::TrijetPtMoment*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::TrijetPtMoment*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLTrijetPtMoment_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::TrijetPtMoment*)0x0)->GetClass();
      SpartyJetcLcLTrijetPtMoment_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLTrijetPtMoment_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLForkToolParent(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::ForkToolParent : new ::SpartyJet::ForkToolParent;
   }
   static void *newArray_SpartyJetcLcLForkToolParent(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::ForkToolParent[nElements] : new ::SpartyJet::ForkToolParent[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLForkToolParent(void *p) {
      delete ((::SpartyJet::ForkToolParent*)p);
   }
   static void deleteArray_SpartyJetcLcLForkToolParent(void *p) {
      delete [] ((::SpartyJet::ForkToolParent*)p);
   }
   static void destruct_SpartyJetcLcLForkToolParent(void *p) {
      typedef ::SpartyJet::ForkToolParent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::ForkToolParent

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLForkToolChild(void *p) {
      delete ((::SpartyJet::ForkToolChild*)p);
   }
   static void deleteArray_SpartyJetcLcLForkToolChild(void *p) {
      delete [] ((::SpartyJet::ForkToolChild*)p);
   }
   static void destruct_SpartyJetcLcLForkToolChild(void *p) {
      typedef ::SpartyJet::ForkToolChild current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::ForkToolChild

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetSelectorTool(void *p) {
      delete ((::SpartyJet::JetSelectorTool*)p);
   }
   static void deleteArray_SpartyJetcLcLJetSelectorTool(void *p) {
      delete [] ((::SpartyJet::JetSelectorTool*)p);
   }
   static void destruct_SpartyJetcLcLJetSelectorTool(void *p) {
      typedef ::SpartyJet::JetSelectorTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetSelectorTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetPtSelectorTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetPtSelectorTool : new ::SpartyJet::JetPtSelectorTool;
   }
   static void *newArray_SpartyJetcLcLJetPtSelectorTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetPtSelectorTool[nElements] : new ::SpartyJet::JetPtSelectorTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetPtSelectorTool(void *p) {
      delete ((::SpartyJet::JetPtSelectorTool*)p);
   }
   static void deleteArray_SpartyJetcLcLJetPtSelectorTool(void *p) {
      delete [] ((::SpartyJet::JetPtSelectorTool*)p);
   }
   static void destruct_SpartyJetcLcLJetPtSelectorTool(void *p) {
      typedef ::SpartyJet::JetPtSelectorTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetPtSelectorTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetEtaCentralSelectorTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetEtaCentralSelectorTool : new ::SpartyJet::JetEtaCentralSelectorTool;
   }
   static void *newArray_SpartyJetcLcLJetEtaCentralSelectorTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetEtaCentralSelectorTool[nElements] : new ::SpartyJet::JetEtaCentralSelectorTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetEtaCentralSelectorTool(void *p) {
      delete ((::SpartyJet::JetEtaCentralSelectorTool*)p);
   }
   static void deleteArray_SpartyJetcLcLJetEtaCentralSelectorTool(void *p) {
      delete [] ((::SpartyJet::JetEtaCentralSelectorTool*)p);
   }
   static void destruct_SpartyJetcLcLJetEtaCentralSelectorTool(void *p) {
      typedef ::SpartyJet::JetEtaCentralSelectorTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetEtaCentralSelectorTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetEtaForwardSelectorTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetEtaForwardSelectorTool : new ::SpartyJet::JetEtaForwardSelectorTool;
   }
   static void *newArray_SpartyJetcLcLJetEtaForwardSelectorTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetEtaForwardSelectorTool[nElements] : new ::SpartyJet::JetEtaForwardSelectorTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetEtaForwardSelectorTool(void *p) {
      delete ((::SpartyJet::JetEtaForwardSelectorTool*)p);
   }
   static void deleteArray_SpartyJetcLcLJetEtaForwardSelectorTool(void *p) {
      delete [] ((::SpartyJet::JetEtaForwardSelectorTool*)p);
   }
   static void destruct_SpartyJetcLcLJetEtaForwardSelectorTool(void *p) {
      typedef ::SpartyJet::JetEtaForwardSelectorTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetEtaForwardSelectorTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetMassSelectorTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetMassSelectorTool : new ::SpartyJet::JetMassSelectorTool;
   }
   static void *newArray_SpartyJetcLcLJetMassSelectorTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetMassSelectorTool[nElements] : new ::SpartyJet::JetMassSelectorTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetMassSelectorTool(void *p) {
      delete ((::SpartyJet::JetMassSelectorTool*)p);
   }
   static void deleteArray_SpartyJetcLcLJetMassSelectorTool(void *p) {
      delete [] ((::SpartyJet::JetMassSelectorTool*)p);
   }
   static void destruct_SpartyJetcLcLJetMassSelectorTool(void *p) {
      typedef ::SpartyJet::JetMassSelectorTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetMassSelectorTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetInputPdgIdSelectorTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetInputPdgIdSelectorTool : new ::SpartyJet::JetInputPdgIdSelectorTool;
   }
   static void *newArray_SpartyJetcLcLJetInputPdgIdSelectorTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetInputPdgIdSelectorTool[nElements] : new ::SpartyJet::JetInputPdgIdSelectorTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetInputPdgIdSelectorTool(void *p) {
      delete ((::SpartyJet::JetInputPdgIdSelectorTool*)p);
   }
   static void deleteArray_SpartyJetcLcLJetInputPdgIdSelectorTool(void *p) {
      delete [] ((::SpartyJet::JetInputPdgIdSelectorTool*)p);
   }
   static void destruct_SpartyJetcLcLJetInputPdgIdSelectorTool(void *p) {
      typedef ::SpartyJet::JetInputPdgIdSelectorTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetInputPdgIdSelectorTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetPtORESelectorTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetPtORESelectorTool : new ::SpartyJet::JetPtORESelectorTool;
   }
   static void *newArray_SpartyJetcLcLJetPtORESelectorTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetPtORESelectorTool[nElements] : new ::SpartyJet::JetPtORESelectorTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetPtORESelectorTool(void *p) {
      delete ((::SpartyJet::JetPtORESelectorTool*)p);
   }
   static void deleteArray_SpartyJetcLcLJetPtORESelectorTool(void *p) {
      delete [] ((::SpartyJet::JetPtORESelectorTool*)p);
   }
   static void destruct_SpartyJetcLcLJetPtORESelectorTool(void *p) {
      typedef ::SpartyJet::JetPtORESelectorTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetPtORESelectorTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetMomentSelectorToollEfloatgR(void *p) {
      delete ((::SpartyJet::JetMomentSelectorTool<float>*)p);
   }
   static void deleteArray_SpartyJetcLcLJetMomentSelectorToollEfloatgR(void *p) {
      delete [] ((::SpartyJet::JetMomentSelectorTool<float>*)p);
   }
   static void destruct_SpartyJetcLcLJetMomentSelectorToollEfloatgR(void *p) {
      typedef ::SpartyJet::JetMomentSelectorTool<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetMomentSelectorTool<float>

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetMomentSelectorToollEintgR(void *p) {
      delete ((::SpartyJet::JetMomentSelectorTool<int>*)p);
   }
   static void deleteArray_SpartyJetcLcLJetMomentSelectorToollEintgR(void *p) {
      delete [] ((::SpartyJet::JetMomentSelectorTool<int>*)p);
   }
   static void destruct_SpartyJetcLcLJetMomentSelectorToollEintgR(void *p) {
      typedef ::SpartyJet::JetMomentSelectorTool<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetMomentSelectorTool<int>

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLEtaPhiMomentTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::EtaPhiMomentTool : new ::SpartyJet::EtaPhiMomentTool;
   }
   static void *newArray_SpartyJetcLcLEtaPhiMomentTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::EtaPhiMomentTool[nElements] : new ::SpartyJet::EtaPhiMomentTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLEtaPhiMomentTool(void *p) {
      delete ((::SpartyJet::EtaPhiMomentTool*)p);
   }
   static void deleteArray_SpartyJetcLcLEtaPhiMomentTool(void *p) {
      delete [] ((::SpartyJet::EtaPhiMomentTool*)p);
   }
   static void destruct_SpartyJetcLcLEtaPhiMomentTool(void *p) {
      typedef ::SpartyJet::EtaPhiMomentTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::EtaPhiMomentTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLEConversionTool(void *p) {
      delete ((::SpartyJet::EConversionTool*)p);
   }
   static void deleteArray_SpartyJetcLcLEConversionTool(void *p) {
      delete [] ((::SpartyJet::EConversionTool*)p);
   }
   static void destruct_SpartyJetcLcLEConversionTool(void *p) {
      typedef ::SpartyJet::EConversionTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::EConversionTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLMomentArrayTestTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::MomentArrayTestTool : new ::SpartyJet::MomentArrayTestTool;
   }
   static void *newArray_SpartyJetcLcLMomentArrayTestTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::MomentArrayTestTool[nElements] : new ::SpartyJet::MomentArrayTestTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLMomentArrayTestTool(void *p) {
      delete ((::SpartyJet::MomentArrayTestTool*)p);
   }
   static void deleteArray_SpartyJetcLcLMomentArrayTestTool(void *p) {
      delete [] ((::SpartyJet::MomentArrayTestTool*)p);
   }
   static void destruct_SpartyJetcLcLMomentArrayTestTool(void *p) {
      typedef ::SpartyJet::MomentArrayTestTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::MomentArrayTestTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLHullMomentTool(void *p) {
      delete ((::SpartyJet::HullMomentTool*)p);
   }
   static void deleteArray_SpartyJetcLcLHullMomentTool(void *p) {
      delete [] ((::SpartyJet::HullMomentTool*)p);
   }
   static void destruct_SpartyJetcLcLHullMomentTool(void *p) {
      typedef ::SpartyJet::HullMomentTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::HullMomentTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetAreaCorrectionTool(void *p) {
      delete ((::SpartyJet::JetAreaCorrectionTool*)p);
   }
   static void deleteArray_SpartyJetcLcLJetAreaCorrectionTool(void *p) {
      delete [] ((::SpartyJet::JetAreaCorrectionTool*)p);
   }
   static void destruct_SpartyJetcLcLJetAreaCorrectionTool(void *p) {
      typedef ::SpartyJet::JetAreaCorrectionTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetAreaCorrectionTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLCalorimeterSimTool(void *p) {
      delete ((::SpartyJet::CalorimeterSimTool*)p);
   }
   static void deleteArray_SpartyJetcLcLCalorimeterSimTool(void *p) {
      delete [] ((::SpartyJet::CalorimeterSimTool*)p);
   }
   static void destruct_SpartyJetcLcLCalorimeterSimTool(void *p) {
      typedef ::SpartyJet::CalorimeterSimTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::CalorimeterSimTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLHardProcessMatchTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::HardProcessMatchTool : new ::SpartyJet::HardProcessMatchTool;
   }
   static void *newArray_SpartyJetcLcLHardProcessMatchTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::HardProcessMatchTool[nElements] : new ::SpartyJet::HardProcessMatchTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLHardProcessMatchTool(void *p) {
      delete ((::SpartyJet::HardProcessMatchTool*)p);
   }
   static void deleteArray_SpartyJetcLcLHardProcessMatchTool(void *p) {
      delete [] ((::SpartyJet::HardProcessMatchTool*)p);
   }
   static void destruct_SpartyJetcLcLHardProcessMatchTool(void *p) {
      typedef ::SpartyJet::HardProcessMatchTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::HardProcessMatchTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLTopDownPruneTool(void *p) {
      delete ((::SpartyJet::TopDownPruneTool*)p);
   }
   static void deleteArray_SpartyJetcLcLTopDownPruneTool(void *p) {
      delete [] ((::SpartyJet::TopDownPruneTool*)p);
   }
   static void destruct_SpartyJetcLcLTopDownPruneTool(void *p) {
      typedef ::SpartyJet::TopDownPruneTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::TopDownPruneTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLMassDropTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::MassDropTool : new ::SpartyJet::MassDropTool;
   }
   static void *newArray_SpartyJetcLcLMassDropTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::MassDropTool[nElements] : new ::SpartyJet::MassDropTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLMassDropTool(void *p) {
      delete ((::SpartyJet::MassDropTool*)p);
   }
   static void deleteArray_SpartyJetcLcLMassDropTool(void *p) {
      delete [] ((::SpartyJet::MassDropTool*)p);
   }
   static void destruct_SpartyJetcLcLMassDropTool(void *p) {
      typedef ::SpartyJet::MassDropTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::MassDropTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJHPruneTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JHPruneTool : new ::SpartyJet::JHPruneTool;
   }
   static void *newArray_SpartyJetcLcLJHPruneTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JHPruneTool[nElements] : new ::SpartyJet::JHPruneTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJHPruneTool(void *p) {
      delete ((::SpartyJet::JHPruneTool*)p);
   }
   static void deleteArray_SpartyJetcLcLJHPruneTool(void *p) {
      delete [] ((::SpartyJet::JHPruneTool*)p);
   }
   static void destruct_SpartyJetcLcLJHPruneTool(void *p) {
      typedef ::SpartyJet::JHPruneTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JHPruneTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLSubjetCutTool(void *p) {
      delete ((::SpartyJet::SubjetCutTool*)p);
   }
   static void deleteArray_SpartyJetcLcLSubjetCutTool(void *p) {
      delete [] ((::SpartyJet::SubjetCutTool*)p);
   }
   static void destruct_SpartyJetcLcLSubjetCutTool(void *p) {
      typedef ::SpartyJet::SubjetCutTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::SubjetCutTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLSubjetMergeTool(void *p) {
      delete ((::SpartyJet::SubjetMergeTool*)p);
   }
   static void deleteArray_SpartyJetcLcLSubjetMergeTool(void *p) {
      delete [] ((::SpartyJet::SubjetMergeTool*)p);
   }
   static void destruct_SpartyJetcLcLSubjetMergeTool(void *p) {
      typedef ::SpartyJet::SubjetMergeTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::SubjetMergeTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLMinMassTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::MinMassTool : new ::SpartyJet::MinMassTool;
   }
   static void *newArray_SpartyJetcLcLMinMassTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::MinMassTool[nElements] : new ::SpartyJet::MinMassTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLMinMassTool(void *p) {
      delete ((::SpartyJet::MinMassTool*)p);
   }
   static void deleteArray_SpartyJetcLcLMinMassTool(void *p) {
      delete [] ((::SpartyJet::MinMassTool*)p);
   }
   static void destruct_SpartyJetcLcLMinMassTool(void *p) {
      typedef ::SpartyJet::MinMassTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::MinMassTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLUnclusterTool(void *p) {
      delete ((::SpartyJet::UnclusterTool*)p);
   }
   static void deleteArray_SpartyJetcLcLUnclusterTool(void *p) {
      delete [] ((::SpartyJet::UnclusterTool*)p);
   }
   static void destruct_SpartyJetcLcLUnclusterTool(void *p) {
      typedef ::SpartyJet::UnclusterTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::UnclusterTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetMomentTool(void *p) {
      delete ((::SpartyJet::JetMomentTool*)p);
   }
   static void deleteArray_SpartyJetcLcLJetMomentTool(void *p) {
      delete [] ((::SpartyJet::JetMomentTool*)p);
   }
   static void destruct_SpartyJetcLcLJetMomentTool(void *p) {
      typedef ::SpartyJet::JetMomentTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetMomentTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLEventMomentTool(void *p) {
      delete ((::SpartyJet::EventMomentTool*)p);
   }
   static void deleteArray_SpartyJetcLcLEventMomentTool(void *p) {
      delete [] ((::SpartyJet::EventMomentTool*)p);
   }
   static void destruct_SpartyJetcLcLEventMomentTool(void *p) {
      typedef ::SpartyJet::EventMomentTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::EventMomentTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetMomentlEDouble32_tgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetMoment<Double32_t> : new ::SpartyJet::JetMoment<Double32_t>;
   }
   static void *newArray_SpartyJetcLcLJetMomentlEDouble32_tgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetMoment<Double32_t>[nElements] : new ::SpartyJet::JetMoment<Double32_t>[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetMomentlEDouble32_tgR(void *p) {
      delete ((::SpartyJet::JetMoment<Double32_t>*)p);
   }
   static void deleteArray_SpartyJetcLcLJetMomentlEDouble32_tgR(void *p) {
      delete [] ((::SpartyJet::JetMoment<Double32_t>*)p);
   }
   static void destruct_SpartyJetcLcLJetMomentlEDouble32_tgR(void *p) {
      typedef ::SpartyJet::JetMoment<Double32_t> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetMoment<Double32_t>

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLHeavierSubjetMass(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::HeavierSubjetMass : new ::SpartyJet::HeavierSubjetMass;
   }
   static void *newArray_SpartyJetcLcLHeavierSubjetMass(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::HeavierSubjetMass[nElements] : new ::SpartyJet::HeavierSubjetMass[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLHeavierSubjetMass(void *p) {
      delete ((::SpartyJet::HeavierSubjetMass*)p);
   }
   static void deleteArray_SpartyJetcLcLHeavierSubjetMass(void *p) {
      delete [] ((::SpartyJet::HeavierSubjetMass*)p);
   }
   static void destruct_SpartyJetcLcLHeavierSubjetMass(void *p) {
      typedef ::SpartyJet::HeavierSubjetMass current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::HeavierSubjetMass

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLMassMoment(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::MassMoment : new ::SpartyJet::MassMoment;
   }
   static void *newArray_SpartyJetcLcLMassMoment(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::MassMoment[nElements] : new ::SpartyJet::MassMoment[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLMassMoment(void *p) {
      delete ((::SpartyJet::MassMoment*)p);
   }
   static void deleteArray_SpartyJetcLcLMassMoment(void *p) {
      delete [] ((::SpartyJet::MassMoment*)p);
   }
   static void destruct_SpartyJetcLcLMassMoment(void *p) {
      typedef ::SpartyJet::MassMoment current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::MassMoment

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLPtMoment(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::PtMoment : new ::SpartyJet::PtMoment;
   }
   static void *newArray_SpartyJetcLcLPtMoment(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::PtMoment[nElements] : new ::SpartyJet::PtMoment[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLPtMoment(void *p) {
      delete ((::SpartyJet::PtMoment*)p);
   }
   static void deleteArray_SpartyJetcLcLPtMoment(void *p) {
      delete [] ((::SpartyJet::PtMoment*)p);
   }
   static void destruct_SpartyJetcLcLPtMoment(void *p) {
      typedef ::SpartyJet::PtMoment current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::PtMoment

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLFinalDij(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::FinalDij : new ::SpartyJet::FinalDij;
   }
   static void *newArray_SpartyJetcLcLFinalDij(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::FinalDij[nElements] : new ::SpartyJet::FinalDij[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFinalDij(void *p) {
      delete ((::SpartyJet::FinalDij*)p);
   }
   static void deleteArray_SpartyJetcLcLFinalDij(void *p) {
      delete [] ((::SpartyJet::FinalDij*)p);
   }
   static void destruct_SpartyJetcLcLFinalDij(void *p) {
      typedef ::SpartyJet::FinalDij current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FinalDij

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLzMoment(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::zMoment : new ::SpartyJet::zMoment;
   }
   static void *newArray_SpartyJetcLcLzMoment(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::zMoment[nElements] : new ::SpartyJet::zMoment[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLzMoment(void *p) {
      delete ((::SpartyJet::zMoment*)p);
   }
   static void deleteArray_SpartyJetcLcLzMoment(void *p) {
      delete [] ((::SpartyJet::zMoment*)p);
   }
   static void destruct_SpartyJetcLcLzMoment(void *p) {
      typedef ::SpartyJet::zMoment current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::zMoment

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLDeltaRMoment(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::DeltaRMoment : new ::SpartyJet::DeltaRMoment;
   }
   static void *newArray_SpartyJetcLcLDeltaRMoment(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::DeltaRMoment[nElements] : new ::SpartyJet::DeltaRMoment[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLDeltaRMoment(void *p) {
      delete ((::SpartyJet::DeltaRMoment*)p);
   }
   static void deleteArray_SpartyJetcLcLDeltaRMoment(void *p) {
      delete [] ((::SpartyJet::DeltaRMoment*)p);
   }
   static void destruct_SpartyJetcLcLDeltaRMoment(void *p) {
      typedef ::SpartyJet::DeltaRMoment current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::DeltaRMoment

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetMoment<vector<Double32_t> > : new ::SpartyJet::JetMoment<vector<Double32_t> >;
   }
   static void *newArray_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetMoment<vector<Double32_t> >[nElements] : new ::SpartyJet::JetMoment<vector<Double32_t> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR(void *p) {
      delete ((::SpartyJet::JetMoment<vector<Double32_t> >*)p);
   }
   static void deleteArray_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR(void *p) {
      delete [] ((::SpartyJet::JetMoment<vector<Double32_t> >*)p);
   }
   static void destruct_SpartyJetcLcLJetMomentlEvectorlEDouble32_tgRsPgR(void *p) {
      typedef ::SpartyJet::JetMoment<vector<Double32_t> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetMoment<vector<Double32_t> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLEventMomentlEDouble32_tgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::EventMoment<Double32_t> : new ::SpartyJet::EventMoment<Double32_t>;
   }
   static void *newArray_SpartyJetcLcLEventMomentlEDouble32_tgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::EventMoment<Double32_t>[nElements] : new ::SpartyJet::EventMoment<Double32_t>[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLEventMomentlEDouble32_tgR(void *p) {
      delete ((::SpartyJet::EventMoment<Double32_t>*)p);
   }
   static void deleteArray_SpartyJetcLcLEventMomentlEDouble32_tgR(void *p) {
      delete [] ((::SpartyJet::EventMoment<Double32_t>*)p);
   }
   static void destruct_SpartyJetcLcLEventMomentlEDouble32_tgR(void *p) {
      typedef ::SpartyJet::EventMoment<Double32_t> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::EventMoment<Double32_t>

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::EventMoment<vector<Double32_t> > : new ::SpartyJet::EventMoment<vector<Double32_t> >;
   }
   static void *newArray_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::EventMoment<vector<Double32_t> >[nElements] : new ::SpartyJet::EventMoment<vector<Double32_t> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR(void *p) {
      delete ((::SpartyJet::EventMoment<vector<Double32_t> >*)p);
   }
   static void deleteArray_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR(void *p) {
      delete [] ((::SpartyJet::EventMoment<vector<Double32_t> >*)p);
   }
   static void destruct_SpartyJetcLcLEventMomentlEvectorlEDouble32_tgRsPgR(void *p) {
      typedef ::SpartyJet::EventMoment<vector<Double32_t> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::EventMoment<vector<Double32_t> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLDijetMassMoment(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::DijetMassMoment : new ::SpartyJet::DijetMassMoment;
   }
   static void *newArray_SpartyJetcLcLDijetMassMoment(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::DijetMassMoment[nElements] : new ::SpartyJet::DijetMassMoment[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLDijetMassMoment(void *p) {
      delete ((::SpartyJet::DijetMassMoment*)p);
   }
   static void deleteArray_SpartyJetcLcLDijetMassMoment(void *p) {
      delete [] ((::SpartyJet::DijetMassMoment*)p);
   }
   static void destruct_SpartyJetcLcLDijetMassMoment(void *p) {
      typedef ::SpartyJet::DijetMassMoment current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::DijetMassMoment

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLTrijetMassMoment(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::TrijetMassMoment : new ::SpartyJet::TrijetMassMoment;
   }
   static void *newArray_SpartyJetcLcLTrijetMassMoment(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::TrijetMassMoment[nElements] : new ::SpartyJet::TrijetMassMoment[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLTrijetMassMoment(void *p) {
      delete ((::SpartyJet::TrijetMassMoment*)p);
   }
   static void deleteArray_SpartyJetcLcLTrijetMassMoment(void *p) {
      delete [] ((::SpartyJet::TrijetMassMoment*)p);
   }
   static void destruct_SpartyJetcLcLTrijetMassMoment(void *p) {
      typedef ::SpartyJet::TrijetMassMoment current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::TrijetMassMoment

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLTrijetPtMoment(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::TrijetPtMoment : new ::SpartyJet::TrijetPtMoment;
   }
   static void *newArray_SpartyJetcLcLTrijetPtMoment(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::TrijetPtMoment[nElements] : new ::SpartyJet::TrijetPtMoment[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLTrijetPtMoment(void *p) {
      delete ((::SpartyJet::TrijetPtMoment*)p);
   }
   static void deleteArray_SpartyJetcLcLTrijetPtMoment(void *p) {
      delete [] ((::SpartyJet::TrijetPtMoment*)p);
   }
   static void destruct_SpartyJetcLcLTrijetPtMoment(void *p) {
      typedef ::SpartyJet::TrijetPtMoment current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::TrijetPtMoment

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = 0);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 481,
                  typeid(vector<double>), DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<double>*)0x0)->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete ((vector<double>*)p);
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] ((vector<double>*)p);
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace {
  void TriggerDictionaryInitialization_JetToolsDict_Impl() {
    static const char* headers[] = {
"CalorimeterSimTool.hh",
"EConversionTool.hh",
"EtaPhiMomentTool.hh",
"HardProcessMatchTool.hh",
"HullMomentTool.hh",
"JetAreaCorrectionTool.hh",
"JetForkTool.hh",
"JetMomentTool.hh",
"JetSelectorTool.hh",
"TopDownPruneTool.hh",
"cyl_geom.hh",
0
    };
    static const char* includePaths[] = {
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2",
"/usr/local/include",
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2/JetTools/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetForkTool.hh")))  ForkToolParent;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetForkTool.hh")))  ForkToolChild;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetSelectorTool.hh")))  JetSelectorTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetSelectorTool.hh")))  JetPtSelectorTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetSelectorTool.hh")))  JetEtaCentralSelectorTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetSelectorTool.hh")))  JetEtaForwardSelectorTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetSelectorTool.hh")))  JetMassSelectorTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetSelectorTool.hh")))  JetInputPdgIdSelectorTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetSelectorTool.hh")))  JetPtORESelectorTool;}
namespace SpartyJet{template <class T = float> class __attribute__((annotate("$clingAutoload$JetSelectorTool.hh")))  JetMomentSelectorTool;
}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$EtaPhiMomentTool.hh")))  EtaPhiMomentTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$EConversionTool.hh")))  EConversionTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$EtaPhiMomentTool.hh")))  MomentArrayTestTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$HullMomentTool.hh")))  HullMomentTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetAreaCorrectionTool.hh")))  JetAreaCorrectionTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$CalorimeterSimTool.hh")))  CalorimeterSimTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$HardProcessMatchTool.hh")))  HardProcessMatchTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$TopDownPruneTool.hh")))  TopDownPruneTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$TopDownPruneTool.hh")))  MassDropTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$TopDownPruneTool.hh")))  JHPruneTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$TopDownPruneTool.hh")))  SubjetCutTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$TopDownPruneTool.hh")))  SubjetMergeTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$TopDownPruneTool.hh")))  MinMassTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$TopDownPruneTool.hh")))  UnclusterTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetMomentTool.hh")))  JetMomentTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetMomentTool.hh")))  EventMomentTool;}
namespace SpartyJet{template <class T> class __attribute__((annotate("$clingAutoload$JetForkTool.hh")))  JetMoment;
}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetMomentTool.hh")))  HeavierSubjetMass;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetMomentTool.hh")))  MassMoment;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetMomentTool.hh")))  PtMoment;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetMomentTool.hh")))  FinalDij;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetMomentTool.hh")))  zMoment;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetMomentTool.hh")))  DeltaRMoment;}
namespace std{inline namespace __1{template <class _Tp> class __attribute__((annotate("$clingAutoload$string")))  allocator;
}}
namespace SpartyJet{template <class T> class __attribute__((annotate("$clingAutoload$JetForkTool.hh")))  EventMoment;
}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetMomentTool.hh")))  DijetMassMoment;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetMomentTool.hh")))  TrijetMassMoment;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetMomentTool.hh")))  TrijetPtMoment;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "CalorimeterSimTool.hh"
#include "EConversionTool.hh"
#include "EtaPhiMomentTool.hh"
#include "HardProcessMatchTool.hh"
#include "HullMomentTool.hh"
#include "JetAreaCorrectionTool.hh"
#include "JetForkTool.hh"
#include "JetMomentTool.hh"
#include "JetSelectorTool.hh"
#include "TopDownPruneTool.hh"
#include "cyl_geom.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"SpartyJet::CalorimeterSimTool", payloadCode, "@",
"SpartyJet::DeltaRMoment", payloadCode, "@",
"SpartyJet::DijetMassMoment", payloadCode, "@",
"SpartyJet::EConversionTool", payloadCode, "@",
"SpartyJet::EtaPhiMomentTool", payloadCode, "@",
"SpartyJet::EventMoment<Double32_t>", payloadCode, "@",
"SpartyJet::EventMoment<vector<Double32_t> >", payloadCode, "@",
"SpartyJet::EventMomentTool", payloadCode, "@",
"SpartyJet::FinalDij", payloadCode, "@",
"SpartyJet::ForkToolChild", payloadCode, "@",
"SpartyJet::ForkToolParent", payloadCode, "@",
"SpartyJet::HardProcessMatchTool", payloadCode, "@",
"SpartyJet::HeavierSubjetMass", payloadCode, "@",
"SpartyJet::HullMomentTool", payloadCode, "@",
"SpartyJet::JHPruneTool", payloadCode, "@",
"SpartyJet::JetAreaCorrectionTool", payloadCode, "@",
"SpartyJet::JetEtaCentralSelectorTool", payloadCode, "@",
"SpartyJet::JetEtaForwardSelectorTool", payloadCode, "@",
"SpartyJet::JetInputPdgIdSelectorTool", payloadCode, "@",
"SpartyJet::JetMassSelectorTool", payloadCode, "@",
"SpartyJet::JetMoment<Double32_t>", payloadCode, "@",
"SpartyJet::JetMoment<vector<Double32_t> >", payloadCode, "@",
"SpartyJet::JetMomentSelectorTool<float>", payloadCode, "@",
"SpartyJet::JetMomentSelectorTool<int>", payloadCode, "@",
"SpartyJet::JetMomentTool", payloadCode, "@",
"SpartyJet::JetPtORESelectorTool", payloadCode, "@",
"SpartyJet::JetPtSelectorTool", payloadCode, "@",
"SpartyJet::JetSelectorTool", payloadCode, "@",
"SpartyJet::MassDropTool", payloadCode, "@",
"SpartyJet::MassMoment", payloadCode, "@",
"SpartyJet::MinMassTool", payloadCode, "@",
"SpartyJet::MomentArrayTestTool", payloadCode, "@",
"SpartyJet::PtMoment", payloadCode, "@",
"SpartyJet::SubjetCutTool", payloadCode, "@",
"SpartyJet::SubjetMergeTool", payloadCode, "@",
"SpartyJet::TopDownPruneTool", payloadCode, "@",
"SpartyJet::TrijetMassMoment", payloadCode, "@",
"SpartyJet::TrijetPtMoment", payloadCode, "@",
"SpartyJet::UnclusterTool", payloadCode, "@",
"SpartyJet::zMoment", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("JetToolsDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_JetToolsDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_JetToolsDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_JetToolsDict() {
  TriggerDictionaryInitialization_JetToolsDict_Impl();
}
