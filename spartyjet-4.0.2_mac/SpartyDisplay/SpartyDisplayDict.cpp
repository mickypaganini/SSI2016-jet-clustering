// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME SpartyDisplayDict

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
#include "EventView.hh"
#include "Jet2DView.hh"
#include "JetCollExtended.hh"
#include "JetCollReaderBase.hh"
#include "JetHistoryView.hh"
#include "JetInputCollection.hh"
#include "JetRetrieverFile.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *SpartyJetcLcLJetCollExtended_Dictionary();
   static void SpartyJetcLcLJetCollExtended_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetCollExtended(void *p = 0);
   static void *newArray_SpartyJetcLcLJetCollExtended(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetCollExtended(void *p);
   static void deleteArray_SpartyJetcLcLJetCollExtended(void *p);
   static void destruct_SpartyJetcLcLJetCollExtended(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetCollExtended*)
   {
      ::SpartyJet::JetCollExtended *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetCollExtended),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetCollExtended", "JetCollExtended.hh", 33,
                  typeid(::SpartyJet::JetCollExtended), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetCollExtended_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetCollExtended) );
      instance.SetNew(&new_SpartyJetcLcLJetCollExtended);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetCollExtended);
      instance.SetDelete(&delete_SpartyJetcLcLJetCollExtended);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetCollExtended);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetCollExtended);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetCollExtended*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetCollExtended*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetCollExtended*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetCollExtended_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetCollExtended*)0x0)->GetClass();
      SpartyJetcLcLJetCollExtended_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetCollExtended_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetInputCollection_Dictionary();
   static void SpartyJetcLcLJetInputCollection_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetInputCollection(void *p = 0);
   static void *newArray_SpartyJetcLcLJetInputCollection(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetInputCollection(void *p);
   static void deleteArray_SpartyJetcLcLJetInputCollection(void *p);
   static void destruct_SpartyJetcLcLJetInputCollection(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetInputCollection*)
   {
      ::SpartyJet::JetInputCollection *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetInputCollection),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetInputCollection", "JetInputCollection.hh", 32,
                  typeid(::SpartyJet::JetInputCollection), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetInputCollection_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetInputCollection) );
      instance.SetNew(&new_SpartyJetcLcLJetInputCollection);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetInputCollection);
      instance.SetDelete(&delete_SpartyJetcLcLJetInputCollection);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetInputCollection);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetInputCollection);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetInputCollection*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetInputCollection*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetInputCollection*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetInputCollection_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetInputCollection*)0x0)->GetClass();
      SpartyJetcLcLJetInputCollection_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetInputCollection_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetRetrieverFile_Dictionary();
   static void SpartyJetcLcLJetRetrieverFile_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetRetrieverFile(void *p = 0);
   static void *newArray_SpartyJetcLcLJetRetrieverFile(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetRetrieverFile(void *p);
   static void deleteArray_SpartyJetcLcLJetRetrieverFile(void *p);
   static void destruct_SpartyJetcLcLJetRetrieverFile(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetRetrieverFile*)
   {
      ::SpartyJet::JetRetrieverFile *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetRetrieverFile),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetRetrieverFile", "JetRetrieverFile.hh", 46,
                  typeid(::SpartyJet::JetRetrieverFile), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetRetrieverFile_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetRetrieverFile) );
      instance.SetNew(&new_SpartyJetcLcLJetRetrieverFile);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetRetrieverFile);
      instance.SetDelete(&delete_SpartyJetcLcLJetRetrieverFile);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetRetrieverFile);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetRetrieverFile);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetRetrieverFile*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetRetrieverFile*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetRetrieverFile*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetRetrieverFile_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetRetrieverFile*)0x0)->GetClass();
      SpartyJetcLcLJetRetrieverFile_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetRetrieverFile_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLIJetCollReader_Dictionary();
   static void SpartyJetcLcLIJetCollReader_TClassManip(TClass*);
   static void delete_SpartyJetcLcLIJetCollReader(void *p);
   static void deleteArray_SpartyJetcLcLIJetCollReader(void *p);
   static void destruct_SpartyJetcLcLIJetCollReader(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::IJetCollReader*)
   {
      ::SpartyJet::IJetCollReader *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::IJetCollReader),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::IJetCollReader", "JetCollReaderBase.hh", 39,
                  typeid(::SpartyJet::IJetCollReader), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLIJetCollReader_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::IJetCollReader) );
      instance.SetDelete(&delete_SpartyJetcLcLIJetCollReader);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLIJetCollReader);
      instance.SetDestructor(&destruct_SpartyJetcLcLIJetCollReader);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::IJetCollReader*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::IJetCollReader*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::IJetCollReader*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLIJetCollReader_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::IJetCollReader*)0x0)->GetClass();
      SpartyJetcLcLIJetCollReader_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLIJetCollReader_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLEventViewBase_Dictionary();
   static void SpartyJetcLcLEventViewBase_TClassManip(TClass*);
   static void *new_SpartyJetcLcLEventViewBase(void *p = 0);
   static void *newArray_SpartyJetcLcLEventViewBase(Long_t size, void *p);
   static void delete_SpartyJetcLcLEventViewBase(void *p);
   static void deleteArray_SpartyJetcLcLEventViewBase(void *p);
   static void destruct_SpartyJetcLcLEventViewBase(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::EventViewBase*)
   {
      ::SpartyJet::EventViewBase *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::EventViewBase),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::EventViewBase", "EventView.hh", 43,
                  typeid(::SpartyJet::EventViewBase), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLEventViewBase_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::EventViewBase) );
      instance.SetNew(&new_SpartyJetcLcLEventViewBase);
      instance.SetNewArray(&newArray_SpartyJetcLcLEventViewBase);
      instance.SetDelete(&delete_SpartyJetcLcLEventViewBase);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLEventViewBase);
      instance.SetDestructor(&destruct_SpartyJetcLcLEventViewBase);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::EventViewBase*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::EventViewBase*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::EventViewBase*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLEventViewBase_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::EventViewBase*)0x0)->GetClass();
      SpartyJetcLcLEventViewBase_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLEventViewBase_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLLegoView_Dictionary();
   static void SpartyJetcLcLLegoView_TClassManip(TClass*);
   static void *new_SpartyJetcLcLLegoView(void *p = 0);
   static void *newArray_SpartyJetcLcLLegoView(Long_t size, void *p);
   static void delete_SpartyJetcLcLLegoView(void *p);
   static void deleteArray_SpartyJetcLcLLegoView(void *p);
   static void destruct_SpartyJetcLcLLegoView(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::LegoView*)
   {
      ::SpartyJet::LegoView *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::LegoView),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::LegoView", "EventView.hh", 84,
                  typeid(::SpartyJet::LegoView), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLLegoView_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::LegoView) );
      instance.SetNew(&new_SpartyJetcLcLLegoView);
      instance.SetNewArray(&newArray_SpartyJetcLcLLegoView);
      instance.SetDelete(&delete_SpartyJetcLcLLegoView);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLLegoView);
      instance.SetDestructor(&destruct_SpartyJetcLcLLegoView);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::LegoView*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::LegoView*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::LegoView*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLLegoView_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::LegoView*)0x0)->GetClass();
      SpartyJetcLcLLegoView_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLLegoView_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLEvent2DView_Dictionary();
   static void SpartyJetcLcLEvent2DView_TClassManip(TClass*);
   static void *new_SpartyJetcLcLEvent2DView(void *p = 0);
   static void *newArray_SpartyJetcLcLEvent2DView(Long_t size, void *p);
   static void delete_SpartyJetcLcLEvent2DView(void *p);
   static void deleteArray_SpartyJetcLcLEvent2DView(void *p);
   static void destruct_SpartyJetcLcLEvent2DView(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::Event2DView*)
   {
      ::SpartyJet::Event2DView *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::Event2DView),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::Event2DView", "EventView.hh", 102,
                  typeid(::SpartyJet::Event2DView), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLEvent2DView_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::Event2DView) );
      instance.SetNew(&new_SpartyJetcLcLEvent2DView);
      instance.SetNewArray(&newArray_SpartyJetcLcLEvent2DView);
      instance.SetDelete(&delete_SpartyJetcLcLEvent2DView);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLEvent2DView);
      instance.SetDestructor(&destruct_SpartyJetcLcLEvent2DView);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::Event2DView*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::Event2DView*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::Event2DView*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLEvent2DView_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::Event2DView*)0x0)->GetClass();
      SpartyJetcLcLEvent2DView_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLEvent2DView_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLSnowMassView_Dictionary();
   static void SpartyJetcLcLSnowMassView_TClassManip(TClass*);
   static void *new_SpartyJetcLcLSnowMassView(void *p = 0);
   static void *newArray_SpartyJetcLcLSnowMassView(Long_t size, void *p);
   static void delete_SpartyJetcLcLSnowMassView(void *p);
   static void deleteArray_SpartyJetcLcLSnowMassView(void *p);
   static void destruct_SpartyJetcLcLSnowMassView(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::SnowMassView*)
   {
      ::SpartyJet::SnowMassView *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::SnowMassView),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::SnowMassView", "EventView.hh", 124,
                  typeid(::SpartyJet::SnowMassView), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLSnowMassView_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::SnowMassView) );
      instance.SetNew(&new_SpartyJetcLcLSnowMassView);
      instance.SetNewArray(&newArray_SpartyJetcLcLSnowMassView);
      instance.SetDelete(&delete_SpartyJetcLcLSnowMassView);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLSnowMassView);
      instance.SetDestructor(&destruct_SpartyJetcLcLSnowMassView);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::SnowMassView*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::SnowMassView*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::SnowMassView*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLSnowMassView_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::SnowMassView*)0x0)->GetClass();
      SpartyJetcLcLSnowMassView_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLSnowMassView_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLPrintEvent_Dictionary();
   static void SpartyJetcLcLPrintEvent_TClassManip(TClass*);
   static void *new_SpartyJetcLcLPrintEvent(void *p = 0);
   static void *newArray_SpartyJetcLcLPrintEvent(Long_t size, void *p);
   static void delete_SpartyJetcLcLPrintEvent(void *p);
   static void deleteArray_SpartyJetcLcLPrintEvent(void *p);
   static void destruct_SpartyJetcLcLPrintEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::PrintEvent*)
   {
      ::SpartyJet::PrintEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::PrintEvent),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::PrintEvent", "EventView.hh", 143,
                  typeid(::SpartyJet::PrintEvent), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLPrintEvent_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::PrintEvent) );
      instance.SetNew(&new_SpartyJetcLcLPrintEvent);
      instance.SetNewArray(&newArray_SpartyJetcLcLPrintEvent);
      instance.SetDelete(&delete_SpartyJetcLcLPrintEvent);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLPrintEvent);
      instance.SetDestructor(&destruct_SpartyJetcLcLPrintEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::PrintEvent*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::PrintEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::PrintEvent*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLPrintEvent_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::PrintEvent*)0x0)->GetClass();
      SpartyJetcLcLPrintEvent_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLPrintEvent_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLParamSpace_Dictionary();
   static void SpartyJetcLcLParamSpace_TClassManip(TClass*);
   static void *new_SpartyJetcLcLParamSpace(void *p = 0);
   static void *newArray_SpartyJetcLcLParamSpace(Long_t size, void *p);
   static void delete_SpartyJetcLcLParamSpace(void *p);
   static void deleteArray_SpartyJetcLcLParamSpace(void *p);
   static void destruct_SpartyJetcLcLParamSpace(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::ParamSpace*)
   {
      ::SpartyJet::ParamSpace *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::ParamSpace),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::ParamSpace", "EventView.hh", 154,
                  typeid(::SpartyJet::ParamSpace), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLParamSpace_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::ParamSpace) );
      instance.SetNew(&new_SpartyJetcLcLParamSpace);
      instance.SetNewArray(&newArray_SpartyJetcLcLParamSpace);
      instance.SetDelete(&delete_SpartyJetcLcLParamSpace);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLParamSpace);
      instance.SetDestructor(&destruct_SpartyJetcLcLParamSpace);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::ParamSpace*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::ParamSpace*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::ParamSpace*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLParamSpace_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::ParamSpace*)0x0)->GetClass();
      SpartyJetcLcLParamSpace_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLParamSpace_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLJetHistViewCollection_Dictionary();
   static void SpartyJetcLcLJetHistViewCollection_TClassManip(TClass*);
   static void *new_SpartyJetcLcLJetHistViewCollection(void *p = 0);
   static void *newArray_SpartyJetcLcLJetHistViewCollection(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetHistViewCollection(void *p);
   static void deleteArray_SpartyJetcLcLJetHistViewCollection(void *p);
   static void destruct_SpartyJetcLcLJetHistViewCollection(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetHistViewCollection*)
   {
      ::SpartyJet::JetHistViewCollection *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::JetHistViewCollection),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetHistViewCollection", "JetHistoryView.hh", 70,
                  typeid(::SpartyJet::JetHistViewCollection), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLJetHistViewCollection_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::JetHistViewCollection) );
      instance.SetNew(&new_SpartyJetcLcLJetHistViewCollection);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetHistViewCollection);
      instance.SetDelete(&delete_SpartyJetcLcLJetHistViewCollection);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetHistViewCollection);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetHistViewCollection);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetHistViewCollection*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetHistViewCollection*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetHistViewCollection*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLJetHistViewCollection_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetHistViewCollection*)0x0)->GetClass();
      SpartyJetcLcLJetHistViewCollection_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLJetHistViewCollection_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_SpartyJetcLcLPtMarker(void *p = 0);
   static void *newArray_SpartyJetcLcLPtMarker(Long_t size, void *p);
   static void delete_SpartyJetcLcLPtMarker(void *p);
   static void deleteArray_SpartyJetcLcLPtMarker(void *p);
   static void destruct_SpartyJetcLcLPtMarker(void *p);
   static void streamer_SpartyJetcLcLPtMarker(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::PtMarker*)
   {
      ::SpartyJet::PtMarker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SpartyJet::PtMarker >(0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::PtMarker", ::SpartyJet::PtMarker::Class_Version(), "Jet2DView.hh", 35,
                  typeid(::SpartyJet::PtMarker), DefineBehavior(ptr, ptr),
                  &::SpartyJet::PtMarker::Dictionary, isa_proxy, 16,
                  sizeof(::SpartyJet::PtMarker) );
      instance.SetNew(&new_SpartyJetcLcLPtMarker);
      instance.SetNewArray(&newArray_SpartyJetcLcLPtMarker);
      instance.SetDelete(&delete_SpartyJetcLcLPtMarker);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLPtMarker);
      instance.SetDestructor(&destruct_SpartyJetcLcLPtMarker);
      instance.SetStreamerFunc(&streamer_SpartyJetcLcLPtMarker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::PtMarker*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::PtMarker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::PtMarker*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_SpartyJetcLcLJetHistoryView(void *p = 0);
   static void *newArray_SpartyJetcLcLJetHistoryView(Long_t size, void *p);
   static void delete_SpartyJetcLcLJetHistoryView(void *p);
   static void deleteArray_SpartyJetcLcLJetHistoryView(void *p);
   static void destruct_SpartyJetcLcLJetHistoryView(void *p);
   static void streamer_SpartyJetcLcLJetHistoryView(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::JetHistoryView*)
   {
      ::SpartyJet::JetHistoryView *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SpartyJet::JetHistoryView >(0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::JetHistoryView", ::SpartyJet::JetHistoryView::Class_Version(), "JetHistoryView.hh", 33,
                  typeid(::SpartyJet::JetHistoryView), DefineBehavior(ptr, ptr),
                  &::SpartyJet::JetHistoryView::Dictionary, isa_proxy, 16,
                  sizeof(::SpartyJet::JetHistoryView) );
      instance.SetNew(&new_SpartyJetcLcLJetHistoryView);
      instance.SetNewArray(&newArray_SpartyJetcLcLJetHistoryView);
      instance.SetDelete(&delete_SpartyJetcLcLJetHistoryView);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLJetHistoryView);
      instance.SetDestructor(&destruct_SpartyJetcLcLJetHistoryView);
      instance.SetStreamerFunc(&streamer_SpartyJetcLcLJetHistoryView);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::JetHistoryView*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::JetHistoryView*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::JetHistoryView*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR_Dictionary();
   static void SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR_TClassManip(TClass*);
   static void delete_SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR(void *p);
   static void deleteArray_SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR(void *p);
   static void destruct_SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SpartyJet::HistoryProvider<SpartyJet::JetHistoryView>*)
   {
      ::SpartyJet::HistoryProvider<SpartyJet::JetHistoryView> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SpartyJet::HistoryProvider<SpartyJet::JetHistoryView>),0);
      static ::ROOT::TGenericClassInfo 
         instance("SpartyJet::HistoryProvider<SpartyJet::JetHistoryView>", "JetCore/JetHistory.hh", 108,
                  typeid(::SpartyJet::HistoryProvider<SpartyJet::JetHistoryView>), DefineBehavior(ptr, ptr),
                  &SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR_Dictionary, isa_proxy, 0,
                  sizeof(::SpartyJet::HistoryProvider<SpartyJet::JetHistoryView>) );
      instance.SetDelete(&delete_SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR);
      instance.SetDeleteArray(&deleteArray_SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR);
      instance.SetDestructor(&destruct_SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SpartyJet::HistoryProvider<SpartyJet::JetHistoryView>*)
   {
      return GenerateInitInstanceLocal((::SpartyJet::HistoryProvider<SpartyJet::JetHistoryView>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::SpartyJet::HistoryProvider<SpartyJet::JetHistoryView>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::HistoryProvider<SpartyJet::JetHistoryView>*)0x0)->GetClass();
      SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR_TClassManip(theClass);
   return theClass;
   }

   static void SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace SpartyJet {
//______________________________________________________________________________
atomic_TClass_ptr PtMarker::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *PtMarker::Class_Name()
{
   return "SpartyJet::PtMarker";
}

//______________________________________________________________________________
const char *PtMarker::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::PtMarker*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int PtMarker::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::PtMarker*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PtMarker::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::PtMarker*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PtMarker::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::PtMarker*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace SpartyJet
namespace SpartyJet {
//______________________________________________________________________________
atomic_TClass_ptr JetHistoryView::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *JetHistoryView::Class_Name()
{
   return "SpartyJet::JetHistoryView";
}

//______________________________________________________________________________
const char *JetHistoryView::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetHistoryView*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int JetHistoryView::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetHistoryView*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetHistoryView::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetHistoryView*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetHistoryView::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SpartyJet::JetHistoryView*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace SpartyJet
namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetCollExtended(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetCollExtended : new ::SpartyJet::JetCollExtended;
   }
   static void *newArray_SpartyJetcLcLJetCollExtended(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetCollExtended[nElements] : new ::SpartyJet::JetCollExtended[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetCollExtended(void *p) {
      delete ((::SpartyJet::JetCollExtended*)p);
   }
   static void deleteArray_SpartyJetcLcLJetCollExtended(void *p) {
      delete [] ((::SpartyJet::JetCollExtended*)p);
   }
   static void destruct_SpartyJetcLcLJetCollExtended(void *p) {
      typedef ::SpartyJet::JetCollExtended current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetCollExtended

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetInputCollection(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetInputCollection : new ::SpartyJet::JetInputCollection;
   }
   static void *newArray_SpartyJetcLcLJetInputCollection(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetInputCollection[nElements] : new ::SpartyJet::JetInputCollection[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetInputCollection(void *p) {
      delete ((::SpartyJet::JetInputCollection*)p);
   }
   static void deleteArray_SpartyJetcLcLJetInputCollection(void *p) {
      delete [] ((::SpartyJet::JetInputCollection*)p);
   }
   static void destruct_SpartyJetcLcLJetInputCollection(void *p) {
      typedef ::SpartyJet::JetInputCollection current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetInputCollection

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetRetrieverFile(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetRetrieverFile : new ::SpartyJet::JetRetrieverFile;
   }
   static void *newArray_SpartyJetcLcLJetRetrieverFile(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetRetrieverFile[nElements] : new ::SpartyJet::JetRetrieverFile[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetRetrieverFile(void *p) {
      delete ((::SpartyJet::JetRetrieverFile*)p);
   }
   static void deleteArray_SpartyJetcLcLJetRetrieverFile(void *p) {
      delete [] ((::SpartyJet::JetRetrieverFile*)p);
   }
   static void destruct_SpartyJetcLcLJetRetrieverFile(void *p) {
      typedef ::SpartyJet::JetRetrieverFile current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetRetrieverFile

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLIJetCollReader(void *p) {
      delete ((::SpartyJet::IJetCollReader*)p);
   }
   static void deleteArray_SpartyJetcLcLIJetCollReader(void *p) {
      delete [] ((::SpartyJet::IJetCollReader*)p);
   }
   static void destruct_SpartyJetcLcLIJetCollReader(void *p) {
      typedef ::SpartyJet::IJetCollReader current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::IJetCollReader

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLEventViewBase(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::EventViewBase : new ::SpartyJet::EventViewBase;
   }
   static void *newArray_SpartyJetcLcLEventViewBase(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::EventViewBase[nElements] : new ::SpartyJet::EventViewBase[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLEventViewBase(void *p) {
      delete ((::SpartyJet::EventViewBase*)p);
   }
   static void deleteArray_SpartyJetcLcLEventViewBase(void *p) {
      delete [] ((::SpartyJet::EventViewBase*)p);
   }
   static void destruct_SpartyJetcLcLEventViewBase(void *p) {
      typedef ::SpartyJet::EventViewBase current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::EventViewBase

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLLegoView(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::LegoView : new ::SpartyJet::LegoView;
   }
   static void *newArray_SpartyJetcLcLLegoView(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::LegoView[nElements] : new ::SpartyJet::LegoView[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLLegoView(void *p) {
      delete ((::SpartyJet::LegoView*)p);
   }
   static void deleteArray_SpartyJetcLcLLegoView(void *p) {
      delete [] ((::SpartyJet::LegoView*)p);
   }
   static void destruct_SpartyJetcLcLLegoView(void *p) {
      typedef ::SpartyJet::LegoView current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::LegoView

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLEvent2DView(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::Event2DView : new ::SpartyJet::Event2DView;
   }
   static void *newArray_SpartyJetcLcLEvent2DView(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::Event2DView[nElements] : new ::SpartyJet::Event2DView[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLEvent2DView(void *p) {
      delete ((::SpartyJet::Event2DView*)p);
   }
   static void deleteArray_SpartyJetcLcLEvent2DView(void *p) {
      delete [] ((::SpartyJet::Event2DView*)p);
   }
   static void destruct_SpartyJetcLcLEvent2DView(void *p) {
      typedef ::SpartyJet::Event2DView current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::Event2DView

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLSnowMassView(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::SnowMassView : new ::SpartyJet::SnowMassView;
   }
   static void *newArray_SpartyJetcLcLSnowMassView(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::SnowMassView[nElements] : new ::SpartyJet::SnowMassView[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLSnowMassView(void *p) {
      delete ((::SpartyJet::SnowMassView*)p);
   }
   static void deleteArray_SpartyJetcLcLSnowMassView(void *p) {
      delete [] ((::SpartyJet::SnowMassView*)p);
   }
   static void destruct_SpartyJetcLcLSnowMassView(void *p) {
      typedef ::SpartyJet::SnowMassView current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::SnowMassView

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLPrintEvent(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::PrintEvent : new ::SpartyJet::PrintEvent;
   }
   static void *newArray_SpartyJetcLcLPrintEvent(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::PrintEvent[nElements] : new ::SpartyJet::PrintEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLPrintEvent(void *p) {
      delete ((::SpartyJet::PrintEvent*)p);
   }
   static void deleteArray_SpartyJetcLcLPrintEvent(void *p) {
      delete [] ((::SpartyJet::PrintEvent*)p);
   }
   static void destruct_SpartyJetcLcLPrintEvent(void *p) {
      typedef ::SpartyJet::PrintEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::PrintEvent

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLParamSpace(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::ParamSpace : new ::SpartyJet::ParamSpace;
   }
   static void *newArray_SpartyJetcLcLParamSpace(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::ParamSpace[nElements] : new ::SpartyJet::ParamSpace[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLParamSpace(void *p) {
      delete ((::SpartyJet::ParamSpace*)p);
   }
   static void deleteArray_SpartyJetcLcLParamSpace(void *p) {
      delete [] ((::SpartyJet::ParamSpace*)p);
   }
   static void destruct_SpartyJetcLcLParamSpace(void *p) {
      typedef ::SpartyJet::ParamSpace current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::ParamSpace

namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetHistViewCollection(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetHistViewCollection : new ::SpartyJet::JetHistViewCollection;
   }
   static void *newArray_SpartyJetcLcLJetHistViewCollection(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::SpartyJet::JetHistViewCollection[nElements] : new ::SpartyJet::JetHistViewCollection[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetHistViewCollection(void *p) {
      delete ((::SpartyJet::JetHistViewCollection*)p);
   }
   static void deleteArray_SpartyJetcLcLJetHistViewCollection(void *p) {
      delete [] ((::SpartyJet::JetHistViewCollection*)p);
   }
   static void destruct_SpartyJetcLcLJetHistViewCollection(void *p) {
      typedef ::SpartyJet::JetHistViewCollection current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::JetHistViewCollection

namespace SpartyJet {
//______________________________________________________________________________
void PtMarker::Streamer(TBuffer &R__b)
{
   // Stream an object of class SpartyJet::PtMarker.

   TMarker::Streamer(R__b);
}

} // namespace SpartyJet
namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLPtMarker(void *p) {
      return  p ? new(p) ::SpartyJet::PtMarker : new ::SpartyJet::PtMarker;
   }
   static void *newArray_SpartyJetcLcLPtMarker(Long_t nElements, void *p) {
      return p ? new(p) ::SpartyJet::PtMarker[nElements] : new ::SpartyJet::PtMarker[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLPtMarker(void *p) {
      delete ((::SpartyJet::PtMarker*)p);
   }
   static void deleteArray_SpartyJetcLcLPtMarker(void *p) {
      delete [] ((::SpartyJet::PtMarker*)p);
   }
   static void destruct_SpartyJetcLcLPtMarker(void *p) {
      typedef ::SpartyJet::PtMarker current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_SpartyJetcLcLPtMarker(TBuffer &buf, void *obj) {
      ((::SpartyJet::PtMarker*)obj)->::SpartyJet::PtMarker::Streamer(buf);
   }
} // end of namespace ROOT for class ::SpartyJet::PtMarker

namespace SpartyJet {
//______________________________________________________________________________
void JetHistoryView::Streamer(TBuffer &R__b)
{
   // Stream an object of class SpartyJet::JetHistoryView.

   //This works around a msvc bug and should be harmless on other platforms
   typedef SpartyJet::PtMarker baseClass0;
   baseClass0::Streamer(R__b);
}

} // namespace SpartyJet
namespace ROOT {
   // Wrappers around operator new
   static void *new_SpartyJetcLcLJetHistoryView(void *p) {
      return  p ? new(p) ::SpartyJet::JetHistoryView : new ::SpartyJet::JetHistoryView;
   }
   static void *newArray_SpartyJetcLcLJetHistoryView(Long_t nElements, void *p) {
      return p ? new(p) ::SpartyJet::JetHistoryView[nElements] : new ::SpartyJet::JetHistoryView[nElements];
   }
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLJetHistoryView(void *p) {
      delete ((::SpartyJet::JetHistoryView*)p);
   }
   static void deleteArray_SpartyJetcLcLJetHistoryView(void *p) {
      delete [] ((::SpartyJet::JetHistoryView*)p);
   }
   static void destruct_SpartyJetcLcLJetHistoryView(void *p) {
      typedef ::SpartyJet::JetHistoryView current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_SpartyJetcLcLJetHistoryView(TBuffer &buf, void *obj) {
      ((::SpartyJet::JetHistoryView*)obj)->::SpartyJet::JetHistoryView::Streamer(buf);
   }
} // end of namespace ROOT for class ::SpartyJet::JetHistoryView

namespace ROOT {
   // Wrapper around operator delete
   static void delete_SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR(void *p) {
      delete ((::SpartyJet::HistoryProvider<SpartyJet::JetHistoryView>*)p);
   }
   static void deleteArray_SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR(void *p) {
      delete [] ((::SpartyJet::HistoryProvider<SpartyJet::JetHistoryView>*)p);
   }
   static void destruct_SpartyJetcLcLHistoryProviderlESpartyJetcLcLJetHistoryViewgR(void *p) {
      typedef ::SpartyJet::HistoryProvider<SpartyJet::JetHistoryView> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SpartyJet::HistoryProvider<SpartyJet::JetHistoryView>

namespace {
  void TriggerDictionaryInitialization_SpartyDisplayDict_Impl() {
    static const char* headers[] = {
"EventView.hh",
"Jet2DView.hh",
"JetCollExtended.hh",
"JetCollReaderBase.hh",
"JetHistoryView.hh",
"JetInputCollection.hh",
"JetRetrieverFile.hh",
0
    };
    static const char* includePaths[] = {
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2",
"/usr/local/include",
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2/SpartyDisplay/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$EventView.hh")))  JetCollExtended;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetCollReaderBase.hh")))  JetInputCollection;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetRetrieverFile.hh")))  JetRetrieverFile;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetCollReaderBase.hh")))  IJetCollReader;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$EventView.hh")))  EventViewBase;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$EventView.hh")))  LegoView;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$EventView.hh")))  Event2DView;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$EventView.hh")))  SnowMassView;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$EventView.hh")))  PrintEvent;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$EventView.hh")))  ParamSpace;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetHistoryView.hh")))  JetHistViewCollection;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$Jet2DView.hh")))  PtMarker;}
namespace SpartyJet{class __attribute__((annotate("$clingAutoload$JetHistoryView.hh")))  JetHistoryView;}
namespace SpartyJet{template <class T> class __attribute__((annotate("$clingAutoload$EventView.hh")))  HistoryProvider;
}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "EventView.hh"
#include "Jet2DView.hh"
#include "JetCollExtended.hh"
#include "JetCollReaderBase.hh"
#include "JetHistoryView.hh"
#include "JetInputCollection.hh"
#include "JetRetrieverFile.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"SpartyJet::Event2DView", payloadCode, "@",
"SpartyJet::EventViewBase", payloadCode, "@",
"SpartyJet::HistoryProvider<SpartyJet::JetHistoryView>", payloadCode, "@",
"SpartyJet::IJetCollReader", payloadCode, "@",
"SpartyJet::JetCollExtended", payloadCode, "@",
"SpartyJet::JetHistViewCollection", payloadCode, "@",
"SpartyJet::JetHistoryView", payloadCode, "@",
"SpartyJet::JetInputCollection", payloadCode, "@",
"SpartyJet::JetRetrieverFile", payloadCode, "@",
"SpartyJet::LegoView", payloadCode, "@",
"SpartyJet::ParamSpace", payloadCode, "@",
"SpartyJet::PrintEvent", payloadCode, "@",
"SpartyJet::PtMarker", payloadCode, "@",
"SpartyJet::SnowMassView", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("SpartyDisplayDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_SpartyDisplayDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_SpartyDisplayDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_SpartyDisplayDict() {
  TriggerDictionaryInitialization_SpartyDisplayDict_Impl();
}
