// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME ExternalToolsDict

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
#include "AngularCorrelation.hh"
#include "AngularCorrelationTool.hh"
#include "BoostVariables.hh"
#include "CMSTopTagger.hh"
#include "DetectorModel.hh"
#include "HEPTopTaggerWrapper.hh"
#include "QjetsTool.hh"
#include "RadialSmearingTool.hh"
#include "TopTaggerDipolarityTool.hh"
#include "TransformerMomentHandler.hh"
#include "TransformerTool.hh"
#include "WTagger.hh"
#include "Njettiness/Njettiness.hh"
#include "Njettiness/NjettinessPlugin.hh"
#include "Njettiness/Nsubjettiness.hh"
#include "Qjets/Qjets.hh"
#include "Qjets/QjetsPlugin.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *fastjetcLcLMinMassFunction_Dictionary();
   static void fastjetcLcLMinMassFunction_TClassManip(TClass*);
   static void *new_fastjetcLcLMinMassFunction(void *p = 0);
   static void *newArray_fastjetcLcLMinMassFunction(Long_t size, void *p);
   static void delete_fastjetcLcLMinMassFunction(void *p);
   static void deleteArray_fastjetcLcLMinMassFunction(void *p);
   static void destruct_fastjetcLcLMinMassFunction(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::MinMassFunction*)
   {
      ::fastjet::MinMassFunction *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::MinMassFunction),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::MinMassFunction", "BoostVariables.hh", 39,
                  typeid(::fastjet::MinMassFunction), DefineBehavior(ptr, ptr),
                  &fastjetcLcLMinMassFunction_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::MinMassFunction) );
      instance.SetNew(&new_fastjetcLcLMinMassFunction);
      instance.SetNewArray(&newArray_fastjetcLcLMinMassFunction);
      instance.SetDelete(&delete_fastjetcLcLMinMassFunction);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLMinMassFunction);
      instance.SetDestructor(&destruct_fastjetcLcLMinMassFunction);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::MinMassFunction*)
   {
      return GenerateInitInstanceLocal((::fastjet::MinMassFunction*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::MinMassFunction*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLMinMassFunction_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::MinMassFunction*)0x0)->GetClass();
      fastjetcLcLMinMassFunction_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLMinMassFunction_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLzCellFunction_Dictionary();
   static void fastjetcLcLzCellFunction_TClassManip(TClass*);
   static void *new_fastjetcLcLzCellFunction(void *p = 0);
   static void *newArray_fastjetcLcLzCellFunction(Long_t size, void *p);
   static void delete_fastjetcLcLzCellFunction(void *p);
   static void deleteArray_fastjetcLcLzCellFunction(void *p);
   static void destruct_fastjetcLcLzCellFunction(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::zCellFunction*)
   {
      ::fastjet::zCellFunction *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::zCellFunction),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::zCellFunction", "BoostVariables.hh", 75,
                  typeid(::fastjet::zCellFunction), DefineBehavior(ptr, ptr),
                  &fastjetcLcLzCellFunction_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::zCellFunction) );
      instance.SetNew(&new_fastjetcLcLzCellFunction);
      instance.SetNewArray(&newArray_fastjetcLcLzCellFunction);
      instance.SetDelete(&delete_fastjetcLcLzCellFunction);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLzCellFunction);
      instance.SetDestructor(&destruct_fastjetcLcLzCellFunction);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::zCellFunction*)
   {
      return GenerateInitInstanceLocal((::fastjet::zCellFunction*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::zCellFunction*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLzCellFunction_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::zCellFunction*)0x0)->GetClass();
      fastjetcLcLzCellFunction_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLzCellFunction_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLzCutFunction_Dictionary();
   static void fastjetcLcLzCutFunction_TClassManip(TClass*);
   static void delete_fastjetcLcLzCutFunction(void *p);
   static void deleteArray_fastjetcLcLzCutFunction(void *p);
   static void destruct_fastjetcLcLzCutFunction(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::zCutFunction*)
   {
      ::fastjet::zCutFunction *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::zCutFunction),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::zCutFunction", "BoostVariables.hh", 93,
                  typeid(::fastjet::zCutFunction), DefineBehavior(ptr, ptr),
                  &fastjetcLcLzCutFunction_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::zCutFunction) );
      instance.SetDelete(&delete_fastjetcLcLzCutFunction);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLzCutFunction);
      instance.SetDestructor(&destruct_fastjetcLcLzCutFunction);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::zCutFunction*)
   {
      return GenerateInitInstanceLocal((::fastjet::zCutFunction*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::zCutFunction*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLzCutFunction_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::zCutFunction*)0x0)->GetClass();
      fastjetcLcLzCutFunction_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLzCutFunction_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLAngularCorrelationTool_Dictionary();
   static void SpartyJetcLcLFastJetcLcLAngularCorrelationTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLFastJetcLcLAngularCorrelationTool(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLAngularCorrelationTool(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLAngularCorrelationTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::AngularCorrelationTool*)
   {
      ::SpartyJet::FastJet::AngularCorrelationTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::AngularCorrelationTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::AngularCorrelationTool", "AngularCorrelationTool.hh", 37,
                  typeid(::SpartyJet::FastJet::AngularCorrelationTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLAngularCorrelationTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::AngularCorrelationTool) );
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLAngularCorrelationTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLAngularCorrelationTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLAngularCorrelationTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FastJet::AngularCorrelationTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FastJet::AngularCorrelationTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::AngularCorrelationTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLAngularCorrelationTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::AngularCorrelationTool*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLAngularCorrelationTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLAngularCorrelationTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLTransformerTool_Dictionary();
   static void SpartyJetcLcLFastJetcLcLTransformerTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLFastJetcLcLTransformerTool(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLTransformerTool(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLTransformerTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::TransformerTool*)
   {
      ::SpartyJet::FastJet::TransformerTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::TransformerTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::TransformerTool", "TransformerTool.hh", 38,
                  typeid(::SpartyJet::FastJet::TransformerTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLTransformerTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::TransformerTool) );
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLTransformerTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLTransformerTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLTransformerTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FastJet::TransformerTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FastJet::TransformerTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::TransformerTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLTransformerTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::TransformerTool*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLTransformerTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLTransformerTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLCMSTopTagger_Dictionary();
   static void fastjetcLcLCMSTopTagger_TClassManip(TClass*);
   static void *new_fastjetcLcLCMSTopTagger(void *p = 0);
   static void *newArray_fastjetcLcLCMSTopTagger(Long_t size, void *p);
   static void delete_fastjetcLcLCMSTopTagger(void *p);
   static void deleteArray_fastjetcLcLCMSTopTagger(void *p);
   static void destruct_fastjetcLcLCMSTopTagger(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::CMSTopTagger*)
   {
      ::fastjet::CMSTopTagger *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::CMSTopTagger),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::CMSTopTagger", "CMSTopTagger.hh", 54,
                  typeid(::fastjet::CMSTopTagger), DefineBehavior(ptr, ptr),
                  &fastjetcLcLCMSTopTagger_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::CMSTopTagger) );
      instance.SetNew(&new_fastjetcLcLCMSTopTagger);
      instance.SetNewArray(&newArray_fastjetcLcLCMSTopTagger);
      instance.SetDelete(&delete_fastjetcLcLCMSTopTagger);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLCMSTopTagger);
      instance.SetDestructor(&destruct_fastjetcLcLCMSTopTagger);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::CMSTopTagger*)
   {
      return GenerateInitInstanceLocal((::fastjet::CMSTopTagger*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::CMSTopTagger*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLCMSTopTagger_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::CMSTopTagger*)0x0)->GetClass();
      fastjetcLcLCMSTopTagger_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLCMSTopTagger_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLHEPTopTagger_Dictionary();
   static void fastjetcLcLHEPTopTagger_TClassManip(TClass*);
   static void *new_fastjetcLcLHEPTopTagger(void *p = 0);
   static void *newArray_fastjetcLcLHEPTopTagger(Long_t size, void *p);
   static void delete_fastjetcLcLHEPTopTagger(void *p);
   static void deleteArray_fastjetcLcLHEPTopTagger(void *p);
   static void destruct_fastjetcLcLHEPTopTagger(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::HEPTopTagger*)
   {
      ::fastjet::HEPTopTagger *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::HEPTopTagger),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::HEPTopTagger", "HEPTopTaggerWrapper.hh", 44,
                  typeid(::fastjet::HEPTopTagger), DefineBehavior(ptr, ptr),
                  &fastjetcLcLHEPTopTagger_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::HEPTopTagger) );
      instance.SetNew(&new_fastjetcLcLHEPTopTagger);
      instance.SetNewArray(&newArray_fastjetcLcLHEPTopTagger);
      instance.SetDelete(&delete_fastjetcLcLHEPTopTagger);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLHEPTopTagger);
      instance.SetDestructor(&destruct_fastjetcLcLHEPTopTagger);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::HEPTopTagger*)
   {
      return GenerateInitInstanceLocal((::fastjet::HEPTopTagger*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::HEPTopTagger*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLHEPTopTagger_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::HEPTopTagger*)0x0)->GetClass();
      fastjetcLcLHEPTopTagger_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLHEPTopTagger_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLWTagger_Dictionary();
   static void fastjetcLcLWTagger_TClassManip(TClass*);
   static void *new_fastjetcLcLWTagger(void *p = 0);
   static void *newArray_fastjetcLcLWTagger(Long_t size, void *p);
   static void delete_fastjetcLcLWTagger(void *p);
   static void deleteArray_fastjetcLcLWTagger(void *p);
   static void destruct_fastjetcLcLWTagger(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::WTagger*)
   {
      ::fastjet::WTagger *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::WTagger),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::WTagger", "WTagger.hh", 41,
                  typeid(::fastjet::WTagger), DefineBehavior(ptr, ptr),
                  &fastjetcLcLWTagger_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::WTagger) );
      instance.SetNew(&new_fastjetcLcLWTagger);
      instance.SetNewArray(&newArray_fastjetcLcLWTagger);
      instance.SetDelete(&delete_fastjetcLcLWTagger);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLWTagger);
      instance.SetDestructor(&destruct_fastjetcLcLWTagger);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::WTagger*)
   {
      return GenerateInitInstanceLocal((::fastjet::WTagger*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::WTagger*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLWTagger_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::WTagger*)0x0)->GetClass();
      fastjetcLcLWTagger_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLWTagger_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool_Dictionary();
   static void SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::TopTaggerDipolarityTool*)
   {
      ::SpartyJet::FastJet::TopTaggerDipolarityTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::TopTaggerDipolarityTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::TopTaggerDipolarityTool", "TopTaggerDipolarityTool.hh", 46,
                  typeid(::SpartyJet::FastJet::TopTaggerDipolarityTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::TopTaggerDipolarityTool) );
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FastJet::TopTaggerDipolarityTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FastJet::TopTaggerDipolarityTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::TopTaggerDipolarityTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::TopTaggerDipolarityTool*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLRadialSmearingTool_Dictionary();
   static void SpartyJetcLcLRadialSmearingTool_TClassManip(TClass*);
   static void *new_SpartyJetcLcLRadialSmearingTool(void *p = 0);
   static void *newArray_SpartyJetcLcLRadialSmearingTool(Long_t size, void *p);
   static void delete_SpartyJetcLcLRadialSmearingTool(void *p);
   static void deleteArray_SpartyJetcLcLRadialSmearingTool(void *p);
   static void destruct_SpartyJetcLcLRadialSmearingTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::RadialSmearingTool*)
   {
      ::SpartyJet::RadialSmearingTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::RadialSmearingTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::RadialSmearingTool", "RadialSmearingTool.hh", 40,
                  typeid(::SpartyJet::RadialSmearingTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLRadialSmearingTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::RadialSmearingTool) );
      instance.SetNew(&new_SpartyJetcLcLRadialSmearingTool);
      instance.SetNewArray(&newArray_SpartyJetcLcLRadialSmearingTool);
      instance.SetDelete(&delete_SpartyJetcLcLRadialSmearingTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLRadialSmearingTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLRadialSmearingTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::RadialSmearingTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::RadialSmearingTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::RadialSmearingTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLRadialSmearingTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::RadialSmearingTool*)0x0)->GetClass();
      SpartyJetcLcLRadialSmearingTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLRadialSmearingTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLNjettinessPlugin_Dictionary();
   static void fastjetcLcLNjettinessPlugin_TClassManip(TClass*);
   static void delete_fastjetcLcLNjettinessPlugin(void *p);
   static void deleteArray_fastjetcLcLNjettinessPlugin(void *p);
   static void destruct_fastjetcLcLNjettinessPlugin(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::NjettinessPlugin*)
   {
      ::fastjet::NjettinessPlugin *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::NjettinessPlugin),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::NjettinessPlugin", "Njettiness/NjettinessPlugin.hh", 71,
                  typeid(::fastjet::NjettinessPlugin), DefineBehavior(ptr, ptr),
                  &fastjetcLcLNjettinessPlugin_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::NjettinessPlugin) );
      instance.SetDelete(&delete_fastjetcLcLNjettinessPlugin);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLNjettinessPlugin);
      instance.SetDestructor(&destruct_fastjetcLcLNjettinessPlugin);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::NjettinessPlugin*)
   {
      return GenerateInitInstanceLocal((::fastjet::NjettinessPlugin*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::NjettinessPlugin*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLNjettinessPlugin_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::NjettinessPlugin*)0x0)->GetClass();
      fastjetcLcLNjettinessPlugin_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLNjettinessPlugin_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLNsubjettiness_Dictionary();
   static void fastjetcLcLNsubjettiness_TClassManip(TClass*);
   static void delete_fastjetcLcLNsubjettiness(void *p);
   static void deleteArray_fastjetcLcLNsubjettiness(void *p);
   static void destruct_fastjetcLcLNsubjettiness(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::Nsubjettiness*)
   {
      ::fastjet::Nsubjettiness *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::Nsubjettiness),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::Nsubjettiness", "Njettiness/Nsubjettiness.hh", 51,
                  typeid(::fastjet::Nsubjettiness), DefineBehavior(ptr, ptr),
                  &fastjetcLcLNsubjettiness_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::Nsubjettiness) );
      instance.SetDelete(&delete_fastjetcLcLNsubjettiness);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLNsubjettiness);
      instance.SetDestructor(&destruct_fastjetcLcLNsubjettiness);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::Nsubjettiness*)
   {
      return GenerateInitInstanceLocal((::fastjet::Nsubjettiness*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::Nsubjettiness*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLNsubjettiness_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::Nsubjettiness*)0x0)->GetClass();
      fastjetcLcLNsubjettiness_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLNsubjettiness_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *Njettiness_Dictionary();
   static void Njettiness_TClassManip(TClass*);
   static void delete_Njettiness(void *p);
   static void deleteArray_Njettiness(void *p);
   static void destruct_Njettiness(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Njettiness*)
   {
      ::Njettiness *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Njettiness),0);
      static ::ROOT::TGenericClassInfo 
         instance("Njettiness", "Njettiness/Njettiness.hh", 375,
                  typeid(::Njettiness), DefineBehavior(ptr, ptr),
                  &Njettiness_Dictionary, isa_proxy, 0,
                  sizeof(::Njettiness) );
      instance.SetDelete(&delete_Njettiness);
      instance.SetDeleteArray(&deleteArray_Njettiness);
      instance.SetDestructor(&destruct_Njettiness);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Njettiness*)
   {
      return GenerateInitInstanceLocal((::Njettiness*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Njettiness*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Njettiness_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Njettiness*)0x0)->GetClass();
      Njettiness_TClassManip(theClass);
   return theClass;
   }

   static void Njettiness_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *QjetsPlugin_Dictionary();
   static void QjetsPlugin_TClassManip(TClass*);
   static void delete_QjetsPlugin(void *p);
   static void deleteArray_QjetsPlugin(void *p);
   static void destruct_QjetsPlugin(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::QjetsPlugin*)
   {
      ::QjetsPlugin *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::QjetsPlugin),0);
      static ::ROOT::TGenericClassInfo 
         instance("QjetsPlugin", "Qjets/QjetsPlugin.hh", 8,
                  typeid(::QjetsPlugin), DefineBehavior(ptr, ptr),
                  &QjetsPlugin_Dictionary, isa_proxy, 0,
                  sizeof(::QjetsPlugin) );
      instance.SetDelete(&delete_QjetsPlugin);
      instance.SetDeleteArray(&deleteArray_QjetsPlugin);
      instance.SetDestructor(&destruct_QjetsPlugin);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::QjetsPlugin*)
   {
      return GenerateInitInstanceLocal((::QjetsPlugin*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::QjetsPlugin*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *QjetsPlugin_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::QjetsPlugin*)0x0)->GetClass();
      QjetsPlugin_TClassManip(theClass);
   return theClass;
   }

   static void QjetsPlugin_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLFastJetcLcLQjetsTool_Dictionary();
   static void SpartyJetcLcLFastJetcLcLQjetsTool_TClassManip(TClass*);
   static void delete_SpartyJetcLcLFastJetcLcLQjetsTool(void *p);
   static void deleteArray_SpartyJetcLcLFastJetcLcLQjetsTool(void *p);
   static void destruct_SpartyJetcLcLFastJetcLcLQjetsTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::FastJet::QjetsTool*)
   {
      ::SpartyJet::FastJet::QjetsTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::FastJet::QjetsTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::FastJet::QjetsTool", "QjetsTool.hh", 43,
                  typeid(::SpartyJet::FastJet::QjetsTool), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLFastJetcLcLQjetsTool_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::FastJet::QjetsTool) );
      instance.SetDelete(&delete_SpartyJetcLcLFastJetcLcLQjetsTool);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLFastJetcLcLQjetsTool);
      instance.SetDestructor(&destruct_SpartyJetcLcLFastJetcLcLQjetsTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::FastJet::QjetsTool*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::FastJet::QjetsTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::FastJet::QjetsTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLFastJetcLcLQjetsTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::FastJet::QjetsTool*)0x0)->GetClass();
      SpartyJetcLcLFastJetcLcLQjetsTool_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLFastJetcLcLQjetsTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLMinMassFunction(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::MinMassFunction : new ::fastjet::MinMassFunction;
   }
   static void *newArray_fastjetcLcLMinMassFunction(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::MinMassFunction[nElements] : new ::fastjet::MinMassFunction[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLMinMassFunction(void *p) {
      delete ((::fastjet::MinMassFunction*)p);
   }
   static void deleteArray_fastjetcLcLMinMassFunction(void *p) {
      delete [] ((::fastjet::MinMassFunction*)p);
   }
   static void destruct_fastjetcLcLMinMassFunction(void *p) {
      typedef ::fastjet::MinMassFunction current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::MinMassFunction

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLzCellFunction(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::zCellFunction : new ::fastjet::zCellFunction;
   }
   static void *newArray_fastjetcLcLzCellFunction(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::zCellFunction[nElements] : new ::fastjet::zCellFunction[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLzCellFunction(void *p) {
      delete ((::fastjet::zCellFunction*)p);
   }
   static void deleteArray_fastjetcLcLzCellFunction(void *p) {
      delete [] ((::fastjet::zCellFunction*)p);
   }
   static void destruct_fastjetcLcLzCellFunction(void *p) {
      typedef ::fastjet::zCellFunction current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::zCellFunction

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLzCutFunction(void *p) {
      delete ((::fastjet::zCutFunction*)p);
   }
   static void deleteArray_fastjetcLcLzCutFunction(void *p) {
      delete [] ((::fastjet::zCutFunction*)p);
   }
   static void destruct_fastjetcLcLzCutFunction(void *p) {
      typedef ::fastjet::zCutFunction current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::zCutFunction

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLAngularCorrelationTool(void *p) {
      delete ((::SpartyJet::FastJet::AngularCorrelationTool*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLAngularCorrelationTool(void *p) {
      delete [] ((::SpartyJet::FastJet::AngularCorrelationTool*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLAngularCorrelationTool(void *p) {
      typedef ::SpartyJet::FastJet::AngularCorrelationTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::AngularCorrelationTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLTransformerTool(void *p) {
      delete ((::SpartyJet::FastJet::TransformerTool*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLTransformerTool(void *p) {
      delete [] ((::SpartyJet::FastJet::TransformerTool*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLTransformerTool(void *p) {
      typedef ::SpartyJet::FastJet::TransformerTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::TransformerTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLCMSTopTagger(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::CMSTopTagger : new ::fastjet::CMSTopTagger;
   }
   static void *newArray_fastjetcLcLCMSTopTagger(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::CMSTopTagger[nElements] : new ::fastjet::CMSTopTagger[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLCMSTopTagger(void *p) {
      delete ((::fastjet::CMSTopTagger*)p);
   }
   static void deleteArray_fastjetcLcLCMSTopTagger(void *p) {
      delete [] ((::fastjet::CMSTopTagger*)p);
   }
   static void destruct_fastjetcLcLCMSTopTagger(void *p) {
      typedef ::fastjet::CMSTopTagger current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::CMSTopTagger

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLHEPTopTagger(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::HEPTopTagger : new ::fastjet::HEPTopTagger;
   }
   static void *newArray_fastjetcLcLHEPTopTagger(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::HEPTopTagger[nElements] : new ::fastjet::HEPTopTagger[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLHEPTopTagger(void *p) {
      delete ((::fastjet::HEPTopTagger*)p);
   }
   static void deleteArray_fastjetcLcLHEPTopTagger(void *p) {
      delete [] ((::fastjet::HEPTopTagger*)p);
   }
   static void destruct_fastjetcLcLHEPTopTagger(void *p) {
      typedef ::fastjet::HEPTopTagger current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::HEPTopTagger

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLWTagger(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::WTagger : new ::fastjet::WTagger;
   }
   static void *newArray_fastjetcLcLWTagger(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::WTagger[nElements] : new ::fastjet::WTagger[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLWTagger(void *p) {
      delete ((::fastjet::WTagger*)p);
   }
   static void deleteArray_fastjetcLcLWTagger(void *p) {
      delete [] ((::fastjet::WTagger*)p);
   }
   static void destruct_fastjetcLcLWTagger(void *p) {
      typedef ::fastjet::WTagger current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::WTagger

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool(void *p) {
      delete ((::SpartyJet::FastJet::TopTaggerDipolarityTool*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool(void *p) {
      delete [] ((::SpartyJet::FastJet::TopTaggerDipolarityTool*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLTopTaggerDipolarityTool(void *p) {
      typedef ::SpartyJet::FastJet::TopTaggerDipolarityTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::TopTaggerDipolarityTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLRadialSmearingTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::RadialSmearingTool : new ::SpartyJet::RadialSmearingTool;
   }
   static void *newArray_SpartyJetcLcLRadialSmearingTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::RadialSmearingTool[nElements] : new ::SpartyJet::RadialSmearingTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLRadialSmearingTool(void *p) {
      delete ((::SpartyJet::RadialSmearingTool*)p);
   }
   static void deleteArray_SpartyJetcLcLRadialSmearingTool(void *p) {
      delete [] ((::SpartyJet::RadialSmearingTool*)p);
   }
   static void destruct_SpartyJetcLcLRadialSmearingTool(void *p) {
      typedef ::SpartyJet::RadialSmearingTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::RadialSmearingTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLNjettinessPlugin(void *p) {
      delete ((::fastjet::NjettinessPlugin*)p);
   }
   static void deleteArray_fastjetcLcLNjettinessPlugin(void *p) {
      delete [] ((::fastjet::NjettinessPlugin*)p);
   }
   static void destruct_fastjetcLcLNjettinessPlugin(void *p) {
      typedef ::fastjet::NjettinessPlugin current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::NjettinessPlugin

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLNsubjettiness(void *p) {
      delete ((::fastjet::Nsubjettiness*)p);
   }
   static void deleteArray_fastjetcLcLNsubjettiness(void *p) {
      delete [] ((::fastjet::Nsubjettiness*)p);
   }
   static void destruct_fastjetcLcLNsubjettiness(void *p) {
      typedef ::fastjet::Nsubjettiness current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::Nsubjettiness

namespace ROOT {
   // Wrapper around operator delete
   static void delete_Njettiness(void *p) {
      delete ((::Njettiness*)p);
   }
   static void deleteArray_Njettiness(void *p) {
      delete [] ((::Njettiness*)p);
   }
   static void destruct_Njettiness(void *p) {
      typedef ::Njettiness current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Njettiness

namespace ROOT {
   // Wrapper around operator delete
   static void delete_QjetsPlugin(void *p) {
      delete ((::QjetsPlugin*)p);
   }
   static void deleteArray_QjetsPlugin(void *p) {
      delete [] ((::QjetsPlugin*)p);
   }
   static void destruct_QjetsPlugin(void *p) {
      typedef ::QjetsPlugin current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::QjetsPlugin

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLFastJetcLcLQjetsTool(void *p) {
      delete ((::SpartyJet::FastJet::QjetsTool*)p);
   }
   static void deleteArray_SpartyJetcLcLFastJetcLcLQjetsTool(void *p) {
      delete [] ((::SpartyJet::FastJet::QjetsTool*)p);
   }
   static void destruct_SpartyJetcLcLFastJetcLcLQjetsTool(void *p) {
      typedef ::SpartyJet::FastJet::QjetsTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::FastJet::QjetsTool

namespace {
  void TriggerDictionaryInitialization_ExternalToolsDict_Impl() {
    static const char* headers[] = {
"AngularCorrelation.hh",
"AngularCorrelationTool.hh",
"BoostVariables.hh",
"CMSTopTagger.hh",
"DetectorModel.hh",
"HEPTopTaggerWrapper.hh",
"QjetsTool.hh",
"RadialSmearingTool.hh",
"TopTaggerDipolarityTool.hh",
"TransformerMomentHandler.hh",
"TransformerTool.hh",
"WTagger.hh",
"Njettiness/Njettiness.hh",
"Njettiness/NjettinessPlugin.hh",
"Njettiness/Nsubjettiness.hh",
"Qjets/Qjets.hh",
"Qjets/QjetsPlugin.hh",
0
    };
    static const char* includePaths[] = {
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2",
"/usr/local/include",
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2/ExternalTools/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace fastjet{class __attribute__((annotate("$clingAutoload$BoostVariables.hh")))  MinMassFunction;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$BoostVariables.hh")))  zCellFunction;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$BoostVariables.hh")))  zCutFunction;}
namespace SpartyJet{namespace FastJet{class __attribute__((annotate("$clingAutoload$AngularCorrelationTool.hh")))  AngularCorrelationTool;}}
namespace SpartyJet{namespace FastJet{class __attribute__((annotate("$clingAutoload$TopTaggerDipolarityTool.hh")))  TransformerTool;}}
namespace fastjet{class __attribute__((annotate("$clingAutoload$CMSTopTagger.hh")))  CMSTopTagger;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$HEPTopTaggerWrapper.hh")))  HEPTopTagger;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$WTagger.hh")))  WTagger;}
namespace SpartyJet{namespace FastJet{class __attribute__((annotate("$clingAutoload$TopTaggerDipolarityTool.hh")))  TopTaggerDipolarityTool;}}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$RadialSmearingTool.hh")))  RadialSmearingTool;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$Njettiness/NjettinessPlugin.hh")))  NjettinessPlugin;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$Njettiness/Nsubjettiness.hh")))  Nsubjettiness;}
class __attribute__((annotate("$clingAutoload$Njettiness/Njettiness.hh")))  Njettiness;
class __attribute__((annotate("$clingAutoload$QjetsTool.hh")))  QjetsPlugin;
namespace SpartyJet{namespace FastJet{class __attribute__((annotate("$clingAutoload$QjetsTool.hh")))  QjetsTool;}}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "AngularCorrelation.hh"
#include "AngularCorrelationTool.hh"
#include "BoostVariables.hh"
#include "CMSTopTagger.hh"
#include "DetectorModel.hh"
#include "HEPTopTaggerWrapper.hh"
#include "QjetsTool.hh"
#include "RadialSmearingTool.hh"
#include "TopTaggerDipolarityTool.hh"
#include "TransformerMomentHandler.hh"
#include "TransformerTool.hh"
#include "WTagger.hh"
#include "Njettiness/Njettiness.hh"
#include "Njettiness/NjettinessPlugin.hh"
#include "Njettiness/Nsubjettiness.hh"
#include "Qjets/Qjets.hh"
#include "Qjets/QjetsPlugin.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Njettiness", payloadCode, "@",
"Njettiness::AxesMode", payloadCode, "@",
"QjetsPlugin", payloadCode, "@",
"SpartyJet::FastJet::AngularCorrelationTool", payloadCode, "@",
"SpartyJet::FastJet::QjetsTool", payloadCode, "@",
"SpartyJet::FastJet::TopTaggerDipolarityTool", payloadCode, "@",
"SpartyJet::FastJet::TransformerTool", payloadCode, "@",
"SpartyJet::RadialSmearingTool", payloadCode, "@",
"fastjet::CMSTopTagger", payloadCode, "@",
"fastjet::HEPTopTagger", payloadCode, "@",
"fastjet::MinMassFunction", payloadCode, "@",
"fastjet::NjettinessPlugin", payloadCode, "@",
"fastjet::Nsubjettiness", payloadCode, "@",
"fastjet::WTagger", payloadCode, "@",
"fastjet::zCellFunction", payloadCode, "@",
"fastjet::zCutFunction", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ExternalToolsDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ExternalToolsDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ExternalToolsDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ExternalToolsDict() {
  TriggerDictionaryInitialization_ExternalToolsDict_Impl();
}
