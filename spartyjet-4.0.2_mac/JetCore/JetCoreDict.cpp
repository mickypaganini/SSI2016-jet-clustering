// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME JetCoreDict

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
#include "BranchWrap.hh"
#include "CommonUtils.hh"
#include "CustomMessage.hh"
#include "FourVecCollection.hh"
#include "GetJets.hh"
#include "GhostBuilder.hh"
#include "InputMaker.hh"
#include "Jet.hh"
#include "JetAnalysis.hh"
#include "JetBuilder.hh"
#include "JetCollection.hh"
#include "JetDistances.hh"
#include "JetHistory.hh"
#include "JetMoment.hh"
#include "JetMomentMap.hh"
#include "JetNegEnergyTool.hh"
#include "JetStructure.hh"
#include "JetTool.hh"
#include "NtupleMaker.hh"
#include "OutputVarUtils.hh"

// Header files passed via #pragma extra_include

namespace SpartyJet {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *SpartyJet_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("SpartyJet", 0 /*version*/, "CommonUtils.hh", 30,
                     ::ROOT::DefineBehavior((void*)0,(void*)0),
                     &SpartyJet_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *SpartyJet_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace ROOT {
   static TClass *SpartyJetcLcLJet_Dictionary();
   static void SpartyJetcLcLJet_TClassManip(TClass*);
   static void delete_SpartyJetcLcLJet(void *p);
   static void deleteArray_SpartyJetcLcLJet(void *p);
   static void destruct_SpartyJetcLcLJet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::Jet*)
   {
      ::SpartyJet::Jet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::Jet),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::Jet", "Jet.hh", 50,
                  typeid(::SpartyJet::Jet), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJet_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::Jet) );
      instance.SetDelete(&delete_SpartyJetcLcLJet);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJet);
      instance.SetDestructor(&destruct_SpartyJetcLcLJet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::Jet*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::Jet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::Jet*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJet_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::Jet*)0x0)->GetClass();
      SpartyJetcLcLJet_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJet_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetCollection_Dictionary();
   static void SpartyJetcLcLJetCollection_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetCollection(void *p = 0);
   static void *newArray_SpartyJetcLcLJetCollection(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetCollection(void *p);
   static void deleteArray_SpartyJetcLcLJetCollection(void *p);
   static void destruct_SpartyJetcLcLJetCollection(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetCollection*)
   {
      ::SpartyJet::JetCollection *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetCollection),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetCollection", "JetCollection.hh", 63,
                  typeid(::SpartyJet::JetCollection), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetCollection_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetCollection) );
      instance.SetNew(&new_SpartyJetcLcLJetCollection);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetCollection);
      instance.SetDelete(&delete_SpartyJetcLcLJetCollection);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetCollection);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetCollection);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetCollection*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetCollection*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetCollection*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetCollection_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetCollection*)0x0)->GetClass();
      SpartyJetcLcLJetCollection_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetCollection_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetAnalysis_Dictionary();
   static void SpartyJetcLcLJetAnalysis_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetAnalysis(void *p = 0);
   static void *newArray_SpartyJetcLcLJetAnalysis(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetAnalysis(void *p);
   static void deleteArray_SpartyJetcLcLJetAnalysis(void *p);
   static void destruct_SpartyJetcLcLJetAnalysis(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetAnalysis*)
   {
      ::SpartyJet::JetAnalysis *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetAnalysis),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetAnalysis", "JetAnalysis.hh", 54,
                  typeid(::SpartyJet::JetAnalysis), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetAnalysis_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetAnalysis) );
      instance.SetNew(&new_SpartyJetcLcLJetAnalysis);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetAnalysis);
      instance.SetDelete(&delete_SpartyJetcLcLJetAnalysis);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetAnalysis);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetAnalysis);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetAnalysis*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetAnalysis*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetAnalysis*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetAnalysis_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetAnalysis*)0x0)->GetClass();
      SpartyJetcLcLJetAnalysis_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetAnalysis_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetTool_Dictionary();
   static void SpartyJetcLcLJetTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetTool(void *p = 0);
   static void *newArray_SpartyJetcLcLJetTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetTool(void *p);
   static void deleteArray_SpartyJetcLcLJetTool(void *p);
   static void destruct_SpartyJetcLcLJetTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetTool*)
   {
      ::SpartyJet::JetTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetTool", "JetTool.hh", 46,
                  typeid(::SpartyJet::JetTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetTool) );
      instance.SetNew(&new_SpartyJetcLcLJetTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetTool);
      instance.SetDelete(&delete_SpartyJetcLcLJetTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetTool*)0x0)->GetClass();
      SpartyJetcLcLJetTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetNegEnergyTool_Dictionary();
   static void SpartyJetcLcLJetNegEnergyTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLJetNegEnergyTool(void *p);
   static void deleteArray_SpartyJetcLcLJetNegEnergyTool(void *p);
   static void destruct_SpartyJetcLcLJetNegEnergyTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetNegEnergyTool*)
   {
      ::SpartyJet::JetNegEnergyTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetNegEnergyTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetNegEnergyTool", "JetNegEnergyTool.hh", 36,
                  typeid(::SpartyJet::JetNegEnergyTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetNegEnergyTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetNegEnergyTool) );
      instance.SetDelete(&delete_SpartyJetcLcLJetNegEnergyTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetNegEnergyTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetNegEnergyTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetNegEnergyTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetNegEnergyTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetNegEnergyTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetNegEnergyTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetNegEnergyTool*)0x0)->GetClass();
      SpartyJetcLcLJetNegEnergyTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetNegEnergyTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetBuilder_Dictionary();
   static void SpartyJetcLcLJetBuilder_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetBuilder(void *p = 0);
   static void *newArray_SpartyJetcLcLJetBuilder(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetBuilder(void *p);
   static void deleteArray_SpartyJetcLcLJetBuilder(void *p);
   static void destruct_SpartyJetcLcLJetBuilder(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetBuilder*)
   {
      ::SpartyJet::JetBuilder *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetBuilder),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetBuilder", "JetBuilder.hh", 49,
                  typeid(::SpartyJet::JetBuilder), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetBuilder_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetBuilder) );
      instance.SetNew(&new_SpartyJetcLcLJetBuilder);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetBuilder);
      instance.SetDelete(&delete_SpartyJetcLcLJetBuilder);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetBuilder);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetBuilder);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetBuilder*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetBuilder*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetBuilder*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetBuilder_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetBuilder*)0x0)->GetClass();
      SpartyJetcLcLJetBuilder_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetBuilder_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLInputMaker_Dictionary();
   static void SpartyJetcLcLInputMaker_TClassManip(TClass*);
   static void delete_SpartyJetcLcLInputMaker(void *p);
   static void deleteArray_SpartyJetcLcLInputMaker(void *p);
   static void destruct_SpartyJetcLcLInputMaker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::InputMaker*)
   {
      ::SpartyJet::InputMaker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::InputMaker),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::InputMaker", "InputMaker.hh", 51,
                  typeid(::SpartyJet::InputMaker), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLInputMaker_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::InputMaker) );
      instance.SetDelete(&delete_SpartyJetcLcLInputMaker);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLInputMaker);
      instance.SetDestructor(&destruct_SpartyJetcLcLInputMaker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::InputMaker*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::InputMaker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::InputMaker*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLInputMaker_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::InputMaker*)0x0)->GetClass();
      SpartyJetcLcLInputMaker_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLInputMaker_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJet(void *p) {
      delete ((::SpartyJet::Jet*)p);
   }
   static void deleteArray_SpartyJetcLcLJet(void *p) {
      delete [] ((::SpartyJet::Jet*)p);
   }
   static void destruct_SpartyJetcLcLJet(void *p) {
      typedef ::SpartyJet::Jet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::Jet

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetCollection(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetCollection : new ::SpartyJet::JetCollection;
   }
   static void *newArray_SpartyJetcLcLJetCollection(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetCollection[nElements] : new ::SpartyJet::JetCollection[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetCollection(void *p) {
      delete ((::SpartyJet::JetCollection*)p);
   }
   static void deleteArray_SpartyJetcLcLJetCollection(void *p) {
      delete [] ((::SpartyJet::JetCollection*)p);
   }
   static void destruct_SpartyJetcLcLJetCollection(void *p) {
      typedef ::SpartyJet::JetCollection current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetCollection

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetAnalysis(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetAnalysis : new ::SpartyJet::JetAnalysis;
   }
   static void *newArray_SpartyJetcLcLJetAnalysis(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetAnalysis[nElements] : new ::SpartyJet::JetAnalysis[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetAnalysis(void *p) {
      delete ((::SpartyJet::JetAnalysis*)p);
   }
   static void deleteArray_SpartyJetcLcLJetAnalysis(void *p) {
      delete [] ((::SpartyJet::JetAnalysis*)p);
   }
   static void destruct_SpartyJetcLcLJetAnalysis(void *p) {
      typedef ::SpartyJet::JetAnalysis current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetAnalysis

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetTool : new ::SpartyJet::JetTool;
   }
   static void *newArray_SpartyJetcLcLJetTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetTool[nElements] : new ::SpartyJet::JetTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetTool(void *p) {
      delete ((::SpartyJet::JetTool*)p);
   }
   static void deleteArray_SpartyJetcLcLJetTool(void *p) {
      delete [] ((::SpartyJet::JetTool*)p);
   }
   static void destruct_SpartyJetcLcLJetTool(void *p) {
      typedef ::SpartyJet::JetTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetNegEnergyTool(void *p) {
      delete ((::SpartyJet::JetNegEnergyTool*)p);
   }
   static void deleteArray_SpartyJetcLcLJetNegEnergyTool(void *p) {
      delete [] ((::SpartyJet::JetNegEnergyTool*)p);
   }
   static void destruct_SpartyJetcLcLJetNegEnergyTool(void *p) {
      typedef ::SpartyJet::JetNegEnergyTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetNegEnergyTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetBuilder(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetBuilder : new ::SpartyJet::JetBuilder;
   }
   static void *newArray_SpartyJetcLcLJetBuilder(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetBuilder[nElements] : new ::SpartyJet::JetBuilder[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetBuilder(void *p) {
      delete ((::SpartyJet::JetBuilder*)p);
   }
   static void deleteArray_SpartyJetcLcLJetBuilder(void *p) {
      delete [] ((::SpartyJet::JetBuilder*)p);
   }
   static void destruct_SpartyJetcLcLJetBuilder(void *p) {
      typedef ::SpartyJet::JetBuilder current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetBuilder

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLInputMaker(void *p) {
      delete ((::SpartyJet::InputMaker*)p);
   }
   static void deleteArray_SpartyJetcLcLInputMaker(void *p) {
      delete [] ((::SpartyJet::InputMaker*)p);
   }
   static void destruct_SpartyJetcLcLInputMaker(void *p) {
      typedef ::SpartyJet::InputMaker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::InputMaker

namespace ROOT {
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary();
   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p);
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<float> >*)
   {
      vector<vector<float> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<float> >),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<float> >", -2, "vector", 481,
                  typeid(vector<vector<float> >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEfloatgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<float> >) );
      instance.SetNew(&new_vectorlEvectorlEfloatgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<float> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<float> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<float> >*)0x0)->GetClass();
      vectorlEvectorlEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<float> > : new vector<vector<float> >;
   }
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<float> >[nElements] : new vector<vector<float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete ((vector<vector<float> >*)p);
   }
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete [] ((vector<vector<float> >*)p);
   }
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p) {
      typedef vector<vector<float> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<float> >

namespace ROOT {
   static TClass *vectorlEvectorlEdoublegRsPgR_Dictionary();
   static void vectorlEvectorlEdoublegRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEdoublegRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEdoublegRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEdoublegRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEdoublegRsPgR(void *p);
   static void destruct_vectorlEvectorlEdoublegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<double> >*)
   {
      vector<vector<double> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<double> >),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<double> >", -2, "vector", 481,
                  typeid(vector<vector<double> >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEdoublegRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<double> >) );
      instance.SetNew(&new_vectorlEvectorlEdoublegRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEdoublegRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEdoublegRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEdoublegRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEdoublegRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<double> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<double> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEdoublegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<double> >*)0x0)->GetClass();
      vectorlEvectorlEdoublegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEdoublegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEdoublegRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<double> > : new vector<vector<double> >;
   }
   static void *newArray_vectorlEvectorlEdoublegRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<double> >[nElements] : new vector<vector<double> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEdoublegRsPgR(void *p) {
      delete ((vector<vector<double> >*)p);
   }
   static void deleteArray_vectorlEvectorlEdoublegRsPgR(void *p) {
      delete [] ((vector<vector<double> >*)p);
   }
   static void destruct_vectorlEvectorlEdoublegRsPgR(void *p) {
      typedef vector<vector<double> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<double> >

namespace ROOT {
   static TClass *vectorlEstringgR_Dictionary();
   static void vectorlEstringgR_TClassManip(TClass*);
   static void *new_vectorlEstringgR(void *p = 0);
   static void *newArray_vectorlEstringgR(Long_t size, void *p);
   static void delete_vectorlEstringgR(void *p);
   static void deleteArray_vectorlEstringgR(void *p);
   static void destruct_vectorlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<string>*)
   {
      vector<string> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<string>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<string>", -2, "vector", 481,
                  typeid(vector<string>), DefineBehavior(ptr, ptr),
                  &vectorlEstringgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<string>) );
      instance.SetNew(&new_vectorlEstringgR);
      instance.SetNewArray(&newArray_vectorlEstringgR);
      instance.SetDelete(&delete_vectorlEstringgR);
      instance.SetDeleteArray(&deleteArray_vectorlEstringgR);
      instance.SetDestructor(&destruct_vectorlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<string> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<string>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<string>*)0x0)->GetClass();
      vectorlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEstringgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<string> : new vector<string>;
   }
   static void *newArray_vectorlEstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<string>[nElements] : new vector<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEstringgR(void *p) {
      delete ((vector<string>*)p);
   }
   static void deleteArray_vectorlEstringgR(void *p) {
      delete [] ((vector<string>*)p);
   }
   static void destruct_vectorlEstringgR(void *p) {
      typedef vector<string> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<string>

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 481,
                  typeid(vector<int>), DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = 0);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 481,
                  typeid(vector<float>), DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<float>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<float>*)0x0)->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete ((vector<float>*)p);
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] ((vector<float>*)p);
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<float>

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
                  &vectorlEdoublegR_Dictionary, isa_proxy, 4,
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
  void TriggerDictionaryInitialization_JetCoreDict_Impl() {
    static const char* headers[] = {
"BranchWrap.hh",
"CommonUtils.hh",
"CustomMessage.hh",
"FourVecCollection.hh",
"GetJets.hh",
"GhostBuilder.hh",
"InputMaker.hh",
"Jet.hh",
"JetAnalysis.hh",
"JetBuilder.hh",
"JetCollection.hh",
"JetDistances.hh",
"JetHistory.hh",
"JetMoment.hh",
"JetMomentMap.hh",
"JetNegEnergyTool.hh",
"JetStructure.hh",
"JetTool.hh",
"NtupleMaker.hh",
"OutputVarUtils.hh",
0
    };
    static const char* includePaths[] = {
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2",
"/usr/local/include",
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2/JetCore/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace std{inline namespace __1{template <class _Tp> class __attribute__((annotate("$clingAutoload$string")))  allocator;
}}
namespace std{inline namespace __1{template <class _CharT> struct __attribute__((annotate("$clingAutoload$string")))  char_traits;
}}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$FourVecCollection.hh")))  Jet;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$GetJets.hh")))  JetCollection;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$GetJets.hh")))  JetAnalysis;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$GetJets.hh")))  JetTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetNegEnergyTool.hh")))  JetNegEnergyTool;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetBuilder.hh")))  JetBuilder;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$InputMaker.hh")))  InputMaker;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "BranchWrap.hh"
#include "CommonUtils.hh"
#include "CustomMessage.hh"
#include "FourVecCollection.hh"
#include "GetJets.hh"
#include "GhostBuilder.hh"
#include "InputMaker.hh"
#include "Jet.hh"
#include "JetAnalysis.hh"
#include "JetBuilder.hh"
#include "JetCollection.hh"
#include "JetDistances.hh"
#include "JetHistory.hh"
#include "JetMoment.hh"
#include "JetMomentMap.hh"
#include "JetNegEnergyTool.hh"
#include "JetStructure.hh"
#include "JetTool.hh"
#include "NtupleMaker.hh"
#include "OutputVarUtils.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"SpartyJet::ArrayType", payloadCode, "@",
"SpartyJet::BaseType", payloadCode, "@",
"SpartyJet::InputMaker", payloadCode, "@",
"SpartyJet::Jet", payloadCode, "@",
"SpartyJet::JetAnalysis", payloadCode, "@",
"SpartyJet::JetBuilder", payloadCode, "@",
"SpartyJet::JetCollection", payloadCode, "@",
"SpartyJet::JetNegEnergyTool", payloadCode, "@",
"SpartyJet::JetTool", payloadCode, "@",
"SpartyJet::MessageLevel", payloadCode, "@",
"vector<double>", payloadCode, "@",
"vector<float>", payloadCode, "@",
"vector<int>", payloadCode, "@",
"vector<std::string>", payloadCode, "@",
"vector<std::vector<double> >", payloadCode, "@",
"vector<std::vector<float> >", payloadCode, "@",
"vector<string>", payloadCode, "@",
"vector<vector<double> >", payloadCode, "@",
"vector<vector<float> >", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("JetCoreDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_JetCoreDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_JetCoreDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_JetCoreDict() {
  TriggerDictionaryInitialization_JetCoreDict_Impl();
}
