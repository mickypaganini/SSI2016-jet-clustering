// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME IODict

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
#include "CalchepPartonTextInput.hh"
#include "HepMCInput.hh"
#include "HuskyInput.hh"
#include "InputMaker_Ntuple.hh"
#include "LheInput.hh"
#include "MultiInput.hh"
#include "StdTextInput.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *SpartyJetcLcLNtupleInputBase_Dictionary();
   static void SpartyJetcLcLNtupleInputBase_TClassManip(TClass*);
   static void *new_SpartyJetcLcLNtupleInputBase(void *p = 0);
   static void *newArray_SpartyJetcLcLNtupleInputBase(Long_t size, void *p);
   static void delete_SpartyJetcLcLNtupleInputBase(void *p);
   static void deleteArray_SpartyJetcLcLNtupleInputBase(void *p);
   static void destruct_SpartyJetcLcLNtupleInputBase(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::NtupleInputBase*)
   {
      ::SpartyJet::NtupleInputBase *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::NtupleInputBase),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::NtupleInputBase", "InputMaker_Ntuple.hh", 45,
                  typeid(::SpartyJet::NtupleInputBase), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLNtupleInputBase_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::NtupleInputBase) );
      instance.SetNew(&new_SpartyJetcLcLNtupleInputBase);
      instance.SetNewArray(&newArray_SpartyJetcLcLNtupleInputBase);
      instance.SetDelete(&delete_SpartyJetcLcLNtupleInputBase);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLNtupleInputBase);
      instance.SetDestructor(&destruct_SpartyJetcLcLNtupleInputBase);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::NtupleInputBase*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::NtupleInputBase*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::NtupleInputBase*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLNtupleInputBase_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::NtupleInputBase*)0x0)->GetClass();
      SpartyJetcLcLNtupleInputBase_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLNtupleInputBase_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLNtupleInputMaker_Dictionary();
   static void SpartyJetcLcLNtupleInputMaker_TClassManip(TClass*);
   static void *new_SpartyJetcLcLNtupleInputMaker(void *p = 0);
   static void *newArray_SpartyJetcLcLNtupleInputMaker(Long_t size, void *p);
   static void delete_SpartyJetcLcLNtupleInputMaker(void *p);
   static void deleteArray_SpartyJetcLcLNtupleInputMaker(void *p);
   static void destruct_SpartyJetcLcLNtupleInputMaker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::NtupleInputMaker*)
   {
      ::SpartyJet::NtupleInputMaker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::NtupleInputMaker),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::NtupleInputMaker", "InputMaker_Ntuple.hh", 102,
                  typeid(::SpartyJet::NtupleInputMaker), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLNtupleInputMaker_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::NtupleInputMaker) );
      instance.SetNew(&new_SpartyJetcLcLNtupleInputMaker);
      instance.SetNewArray(&newArray_SpartyJetcLcLNtupleInputMaker);
      instance.SetDelete(&delete_SpartyJetcLcLNtupleInputMaker);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLNtupleInputMaker);
      instance.SetDestructor(&destruct_SpartyJetcLcLNtupleInputMaker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::NtupleInputMaker*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::NtupleInputMaker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::NtupleInputMaker*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLNtupleInputMaker_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::NtupleInputMaker*)0x0)->GetClass();
      SpartyJetcLcLNtupleInputMaker_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLNtupleInputMaker_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLDelphesInputMaker_Dictionary();
   static void SpartyJetcLcLDelphesInputMaker_TClassManip(TClass*);
   static void delete_SpartyJetcLcLDelphesInputMaker(void *p);
   static void deleteArray_SpartyJetcLcLDelphesInputMaker(void *p);
   static void destruct_SpartyJetcLcLDelphesInputMaker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::DelphesInputMaker*)
   {
      ::SpartyJet::DelphesInputMaker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::DelphesInputMaker),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::DelphesInputMaker", "InputMaker_Ntuple.hh", 155,
                  typeid(::SpartyJet::DelphesInputMaker), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLDelphesInputMaker_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::DelphesInputMaker) );
      instance.SetDelete(&delete_SpartyJetcLcLDelphesInputMaker);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLDelphesInputMaker);
      instance.SetDestructor(&destruct_SpartyJetcLcLDelphesInputMaker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::DelphesInputMaker*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::DelphesInputMaker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::DelphesInputMaker*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLDelphesInputMaker_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::DelphesInputMaker*)0x0)->GetClass();
      SpartyJetcLcLDelphesInputMaker_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLDelphesInputMaker_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLTextInputMaker_Dictionary();
   static void SpartyJetcLcLTextInputMaker_TClassManip(TClass*);
   static void delete_SpartyJetcLcLTextInputMaker(void *p);
   static void deleteArray_SpartyJetcLcLTextInputMaker(void *p);
   static void destruct_SpartyJetcLcLTextInputMaker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::TextInputMaker*)
   {
      ::SpartyJet::TextInputMaker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::TextInputMaker),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::TextInputMaker", "JetCore/InputMaker.hh", 121,
                  typeid(::SpartyJet::TextInputMaker), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLTextInputMaker_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::TextInputMaker) );
      instance.SetDelete(&delete_SpartyJetcLcLTextInputMaker);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLTextInputMaker);
      instance.SetDestructor(&destruct_SpartyJetcLcLTextInputMaker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::TextInputMaker*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::TextInputMaker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::TextInputMaker*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLTextInputMaker_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::TextInputMaker*)0x0)->GetClass();
      SpartyJetcLcLTextInputMaker_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLTextInputMaker_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLStdTextInput_Dictionary();
   static void SpartyJetcLcLStdTextInput_TClassManip(TClass*);
   static void delete_SpartyJetcLcLStdTextInput(void *p);
   static void deleteArray_SpartyJetcLcLStdTextInput(void *p);
   static void destruct_SpartyJetcLcLStdTextInput(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::StdTextInput*)
   {
      ::SpartyJet::StdTextInput *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::StdTextInput),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::StdTextInput", "StdTextInput.hh", 30,
                  typeid(::SpartyJet::StdTextInput), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLStdTextInput_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::StdTextInput) );
      instance.SetDelete(&delete_SpartyJetcLcLStdTextInput);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLStdTextInput);
      instance.SetDestructor(&destruct_SpartyJetcLcLStdTextInput);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::StdTextInput*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::StdTextInput*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::StdTextInput*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLStdTextInput_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::StdTextInput*)0x0)->GetClass();
      SpartyJetcLcLStdTextInput_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLStdTextInput_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLHepMCInput_Dictionary();
   static void SpartyJetcLcLHepMCInput_TClassManip(TClass*);
   static void delete_SpartyJetcLcLHepMCInput(void *p);
   static void deleteArray_SpartyJetcLcLHepMCInput(void *p);
   static void destruct_SpartyJetcLcLHepMCInput(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::HepMCInput*)
   {
      ::SpartyJet::HepMCInput *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::HepMCInput),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::HepMCInput", "HepMCInput.hh", 39,
                  typeid(::SpartyJet::HepMCInput), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLHepMCInput_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::HepMCInput) );
      instance.SetDelete(&delete_SpartyJetcLcLHepMCInput);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLHepMCInput);
      instance.SetDestructor(&destruct_SpartyJetcLcLHepMCInput);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::HepMCInput*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::HepMCInput*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::HepMCInput*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLHepMCInput_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::HepMCInput*)0x0)->GetClass();
      SpartyJetcLcLHepMCInput_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLHepMCInput_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLLheInput_Dictionary();
   static void SpartyJetcLcLLheInput_TClassManip(TClass*);
   static void delete_SpartyJetcLcLLheInput(void *p);
   static void deleteArray_SpartyJetcLcLLheInput(void *p);
   static void destruct_SpartyJetcLcLLheInput(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::LheInput*)
   {
      ::SpartyJet::LheInput *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::LheInput),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::LheInput", "LheInput.hh", 30,
                  typeid(::SpartyJet::LheInput), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLLheInput_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::LheInput) );
      instance.SetDelete(&delete_SpartyJetcLcLLheInput);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLLheInput);
      instance.SetDestructor(&destruct_SpartyJetcLcLLheInput);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::LheInput*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::LheInput*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::LheInput*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLLheInput_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::LheInput*)0x0)->GetClass();
      SpartyJetcLcLLheInput_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLLheInput_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLCalchepPartonTextInput_Dictionary();
   static void SpartyJetcLcLCalchepPartonTextInput_TClassManip(TClass*);
   static void delete_SpartyJetcLcLCalchepPartonTextInput(void *p);
   static void deleteArray_SpartyJetcLcLCalchepPartonTextInput(void *p);
   static void destruct_SpartyJetcLcLCalchepPartonTextInput(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::CalchepPartonTextInput*)
   {
      ::SpartyJet::CalchepPartonTextInput *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::CalchepPartonTextInput),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::CalchepPartonTextInput", "CalchepPartonTextInput.hh", 30,
                  typeid(::SpartyJet::CalchepPartonTextInput), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLCalchepPartonTextInput_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::CalchepPartonTextInput) );
      instance.SetDelete(&delete_SpartyJetcLcLCalchepPartonTextInput);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLCalchepPartonTextInput);
      instance.SetDestructor(&destruct_SpartyJetcLcLCalchepPartonTextInput);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::CalchepPartonTextInput*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::CalchepPartonTextInput*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::CalchepPartonTextInput*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLCalchepPartonTextInput_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::CalchepPartonTextInput*)0x0)->GetClass();
      SpartyJetcLcLCalchepPartonTextInput_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLCalchepPartonTextInput_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLHuskyInput_Dictionary();
   static void SpartyJetcLcLHuskyInput_TClassManip(TClass*);
   static void delete_SpartyJetcLcLHuskyInput(void *p);
   static void deleteArray_SpartyJetcLcLHuskyInput(void *p);
   static void destruct_SpartyJetcLcLHuskyInput(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::HuskyInput*)
   {
      ::SpartyJet::HuskyInput *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::HuskyInput),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::HuskyInput", "HuskyInput.hh", 30,
                  typeid(::SpartyJet::HuskyInput), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLHuskyInput_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::HuskyInput) );
      instance.SetDelete(&delete_SpartyJetcLcLHuskyInput);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLHuskyInput);
      instance.SetDestructor(&destruct_SpartyJetcLcLHuskyInput);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::HuskyInput*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::HuskyInput*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::HuskyInput*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLHuskyInput_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::HuskyInput*)0x0)->GetClass();
      SpartyJetcLcLHuskyInput_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLHuskyInput_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLMultiInput_Dictionary();
   static void SpartyJetcLcLMultiInput_TClassManip(TClass*);
   static void *new_SpartyJetcLcLMultiInput(void *p = 0);
   static void *newArray_SpartyJetcLcLMultiInput(Long_t size, void *p);
   static void delete_SpartyJetcLcLMultiInput(void *p);
   static void deleteArray_SpartyJetcLcLMultiInput(void *p);
   static void destruct_SpartyJetcLcLMultiInput(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::MultiInput*)
   {
      ::SpartyJet::MultiInput *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::MultiInput),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::MultiInput", "MultiInput.hh", 33,
                  typeid(::SpartyJet::MultiInput), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLMultiInput_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::MultiInput) );
      instance.SetNew(&new_SpartyJetcLcLMultiInput);
      instance.SetNewArray(&newArray_SpartyJetcLcLMultiInput);
      instance.SetDelete(&delete_SpartyJetcLcLMultiInput);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLMultiInput);
      instance.SetDestructor(&destruct_SpartyJetcLcLMultiInput);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::MultiInput*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::MultiInput*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::MultiInput*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLMultiInput_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::MultiInput*)0x0)->GetClass();
      SpartyJetcLcLMultiInput_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLMultiInput_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLNtupleInputBase(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::NtupleInputBase : new ::SpartyJet::NtupleInputBase;
   }
   static void *newArray_SpartyJetcLcLNtupleInputBase(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::NtupleInputBase[nElements] : new ::SpartyJet::NtupleInputBase[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLNtupleInputBase(void *p) {
      delete ((::SpartyJet::NtupleInputBase*)p);
   }
   static void deleteArray_SpartyJetcLcLNtupleInputBase(void *p) {
      delete [] ((::SpartyJet::NtupleInputBase*)p);
   }
   static void destruct_SpartyJetcLcLNtupleInputBase(void *p) {
      typedef ::SpartyJet::NtupleInputBase current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::NtupleInputBase

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLNtupleInputMaker(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::NtupleInputMaker : new ::SpartyJet::NtupleInputMaker;
   }
   static void *newArray_SpartyJetcLcLNtupleInputMaker(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::NtupleInputMaker[nElements] : new ::SpartyJet::NtupleInputMaker[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLNtupleInputMaker(void *p) {
      delete ((::SpartyJet::NtupleInputMaker*)p);
   }
   static void deleteArray_SpartyJetcLcLNtupleInputMaker(void *p) {
      delete [] ((::SpartyJet::NtupleInputMaker*)p);
   }
   static void destruct_SpartyJetcLcLNtupleInputMaker(void *p) {
      typedef ::SpartyJet::NtupleInputMaker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::NtupleInputMaker

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLDelphesInputMaker(void *p) {
      delete ((::SpartyJet::DelphesInputMaker*)p);
   }
   static void deleteArray_SpartyJetcLcLDelphesInputMaker(void *p) {
      delete [] ((::SpartyJet::DelphesInputMaker*)p);
   }
   static void destruct_SpartyJetcLcLDelphesInputMaker(void *p) {
      typedef ::SpartyJet::DelphesInputMaker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::DelphesInputMaker

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLTextInputMaker(void *p) {
      delete ((::SpartyJet::TextInputMaker*)p);
   }
   static void deleteArray_SpartyJetcLcLTextInputMaker(void *p) {
      delete [] ((::SpartyJet::TextInputMaker*)p);
   }
   static void destruct_SpartyJetcLcLTextInputMaker(void *p) {
      typedef ::SpartyJet::TextInputMaker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::TextInputMaker

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLStdTextInput(void *p) {
      delete ((::SpartyJet::StdTextInput*)p);
   }
   static void deleteArray_SpartyJetcLcLStdTextInput(void *p) {
      delete [] ((::SpartyJet::StdTextInput*)p);
   }
   static void destruct_SpartyJetcLcLStdTextInput(void *p) {
      typedef ::SpartyJet::StdTextInput current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::StdTextInput

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLHepMCInput(void *p) {
      delete ((::SpartyJet::HepMCInput*)p);
   }
   static void deleteArray_SpartyJetcLcLHepMCInput(void *p) {
      delete [] ((::SpartyJet::HepMCInput*)p);
   }
   static void destruct_SpartyJetcLcLHepMCInput(void *p) {
      typedef ::SpartyJet::HepMCInput current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::HepMCInput

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLLheInput(void *p) {
      delete ((::SpartyJet::LheInput*)p);
   }
   static void deleteArray_SpartyJetcLcLLheInput(void *p) {
      delete [] ((::SpartyJet::LheInput*)p);
   }
   static void destruct_SpartyJetcLcLLheInput(void *p) {
      typedef ::SpartyJet::LheInput current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::LheInput

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLCalchepPartonTextInput(void *p) {
      delete ((::SpartyJet::CalchepPartonTextInput*)p);
   }
   static void deleteArray_SpartyJetcLcLCalchepPartonTextInput(void *p) {
      delete [] ((::SpartyJet::CalchepPartonTextInput*)p);
   }
   static void destruct_SpartyJetcLcLCalchepPartonTextInput(void *p) {
      typedef ::SpartyJet::CalchepPartonTextInput current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::CalchepPartonTextInput

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLHuskyInput(void *p) {
      delete ((::SpartyJet::HuskyInput*)p);
   }
   static void deleteArray_SpartyJetcLcLHuskyInput(void *p) {
      delete [] ((::SpartyJet::HuskyInput*)p);
   }
   static void destruct_SpartyJetcLcLHuskyInput(void *p) {
      typedef ::SpartyJet::HuskyInput current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::HuskyInput

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLMultiInput(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::MultiInput : new ::SpartyJet::MultiInput;
   }
   static void *newArray_SpartyJetcLcLMultiInput(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::MultiInput[nElements] : new ::SpartyJet::MultiInput[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLMultiInput(void *p) {
      delete ((::SpartyJet::MultiInput*)p);
   }
   static void deleteArray_SpartyJetcLcLMultiInput(void *p) {
      delete [] ((::SpartyJet::MultiInput*)p);
   }
   static void destruct_SpartyJetcLcLMultiInput(void *p) {
      typedef ::SpartyJet::MultiInput current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::MultiInput

namespace {
  void TriggerDictionaryInitialization_IODict_Impl() {
    static const char* headers[] = {
"CalchepPartonTextInput.hh",
"HepMCInput.hh",
"HuskyInput.hh",
"InputMaker_Ntuple.hh",
"LheInput.hh",
"MultiInput.hh",
"StdTextInput.hh",
0
    };
    static const char* includePaths[] = {
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2",
"/usr/local/include",
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2/IO/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$InputMaker_Ntuple.hh")))  NtupleInputBase;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$InputMaker_Ntuple.hh")))  NtupleInputMaker;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$InputMaker_Ntuple.hh")))  DelphesInputMaker;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$CalchepPartonTextInput.hh")))  TextInputMaker;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$StdTextInput.hh")))  StdTextInput;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$HepMCInput.hh")))  HepMCInput;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$LheInput.hh")))  LheInput;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$CalchepPartonTextInput.hh")))  CalchepPartonTextInput;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$HuskyInput.hh")))  HuskyInput;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$MultiInput.hh")))  MultiInput;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "CalchepPartonTextInput.hh"
#include "HepMCInput.hh"
#include "HuskyInput.hh"
#include "InputMaker_Ntuple.hh"
#include "LheInput.hh"
#include "MultiInput.hh"
#include "StdTextInput.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"SpartyJet::CalchepPartonTextInput", payloadCode, "@",
"SpartyJet::DelphesInputMaker", payloadCode, "@",
"SpartyJet::HepMCInput", payloadCode, "@",
"SpartyJet::HuskyInput", payloadCode, "@",
"SpartyJet::LheInput", payloadCode, "@",
"SpartyJet::MultiInput", payloadCode, "@",
"SpartyJet::NtupleInputBase", payloadCode, "@",
"SpartyJet::NtupleInputMaker", payloadCode, "@",
"SpartyJet::StdTextInput", payloadCode, "@",
"SpartyJet::TextInputMaker", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("IODict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_IODict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_IODict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_IODict() {
  TriggerDictionaryInitialization_IODict_Impl();
}
