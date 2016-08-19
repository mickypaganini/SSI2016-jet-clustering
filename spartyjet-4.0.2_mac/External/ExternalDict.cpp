// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME ExternalDict

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
#include "tmp_include/fastjet/PseudoJet.hh"
#include "FJWrapper.hh"
#include "/usr/local/include/fastjet/internal/BasicRandom.hh"
#include "/usr/local/include/fastjet/AreaDefinition.hh"
#include "/usr/local/include/fastjet/CDFJetCluPlugin.hh"
#include "/usr/local/include/fastjet/CDFMidPointPlugin.hh"
#include "/usr/local/include/fastjet/ClusterSequence.hh"
#include "/usr/local/include/fastjet/ClusterSequence1GhostPassiveArea.hh"
#include "/usr/local/include/fastjet/ClusterSequenceActiveArea.hh"
#include "/usr/local/include/fastjet/ClusterSequenceActiveAreaExplicitGhosts.hh"
#include "/usr/local/include/fastjet/ClusterSequenceArea.hh"
#include "/usr/local/include/fastjet/ClusterSequenceAreaBase.hh"
#include "/usr/local/include/fastjet/ClusterSequencePassiveArea.hh"
#include "/usr/local/include/fastjet/ClusterSequenceStructure.hh"
#include "/usr/local/include/fastjet/ClusterSequenceVoronoiArea.hh"
#include "/usr/local/include/fastjet/CompositeJetStructure.hh"
#include "/usr/local/include/fastjet/EECambridgePlugin.hh"
#include "/usr/local/include/fastjet/Error.hh"
#include "/usr/local/include/fastjet/FunctionOfPseudoJet.hh"
#include "/usr/local/include/fastjet/GhostedAreaSpec.hh"
#include "/usr/local/include/fastjet/GridJetPlugin.hh"
#include "/usr/local/include/fastjet/JadePlugin.hh"
#include "/usr/local/include/fastjet/JetDefinition.hh"
#include "/usr/local/include/fastjet/LimitedWarning.hh"
#include "/usr/local/include/fastjet/NNH.hh"
#include "/usr/local/include/fastjet/NestedDefsPlugin.hh"
#include "/usr/local/include/fastjet/PseudoJetStructureBase.hh"
#include "/usr/local/include/fastjet/SISConeBasePlugin.hh"
#include "/usr/local/include/fastjet/SISConePlugin.hh"
#include "/usr/local/include/fastjet/SISConeSphericalPlugin.hh"
#include "/usr/local/include/fastjet/Selector.hh"
#include "/usr/local/include/fastjet/SharedPtr.hh"
#include "/usr/local/include/fastjet/WrappedStructure.hh"
#include "/usr/local/include/fastjet/version.hh"
#include "/usr/local/include/fastjet/tools/BackgroundEstimatorBase.hh"
#include "/usr/local/include/fastjet/tools/Boost.hh"
#include "/usr/local/include/fastjet/tools/CASubJetTagger.hh"
#include "/usr/local/include/fastjet/tools/Filter.hh"
#include "/usr/local/include/fastjet/tools/GridMedianBackgroundEstimator.hh"
#include "/usr/local/include/fastjet/tools/JHTopTagger.hh"
#include "/usr/local/include/fastjet/tools/JetMedianBackgroundEstimator.hh"
#include "/usr/local/include/fastjet/tools/MassDropTagger.hh"
#include "/usr/local/include/fastjet/tools/Pruner.hh"
#include "/usr/local/include/fastjet/tools/RestFrameNSubjettinessTagger.hh"
#include "/usr/local/include/fastjet/tools/Subtractor.hh"
#include "/usr/local/include/fastjet/tools/TopTaggerBase.hh"
#include "/usr/local/include/fastjet/tools/Transformer.hh"
#include "/usr/local/include/fastjet/CDFJetCluPlugin.hh"
#include "/usr/local/include/fastjet/CDFMidPointPlugin.hh"
#include "/usr/local/include/fastjet/EECambridgePlugin.hh"
#include "/usr/local/include/fastjet/GridJetPlugin.hh"
#include "/usr/local/include/fastjet/JadePlugin.hh"
#include "/usr/local/include/fastjet/NestedDefsPlugin.hh"
#include "/usr/local/include/fastjet/SISConeBasePlugin.hh"
#include "/usr/local/include/fastjet/SISConePlugin.hh"
#include "/usr/local/include/fastjet/SISConeSphericalPlugin.hh"

// Header files passed via #pragma extra_include

namespace fastjet {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *fastjet_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("fastjet", 0 /*version*/, "fastjet/internal/numconsts.hh", 36,
                     ::ROOT::DefineBehavior((void*)0,(void*)0),
                     &fastjet_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *fastjet_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace ROOT {
   static TClass *fastjetcLcLJetDefinition_Dictionary();
   static void fastjetcLcLJetDefinition_TClassManip(TClass*);
   static void *new_fastjetcLcLJetDefinition(void *p = 0);
   static void *newArray_fastjetcLcLJetDefinition(Long_t size, void *p);
   static void delete_fastjetcLcLJetDefinition(void *p);
   static void deleteArray_fastjetcLcLJetDefinition(void *p);
   static void destruct_fastjetcLcLJetDefinition(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::JetDefinition*)
   {
      ::fastjet::JetDefinition *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::JetDefinition),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::JetDefinition", "fastjet/ClusterSequence.hh", 173,
                  typeid(::fastjet::JetDefinition), DefineBehavior(ptr, ptr),
                  &fastjetcLcLJetDefinition_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::JetDefinition) );
      instance.SetNew(&new_fastjetcLcLJetDefinition);
      instance.SetNewArray(&newArray_fastjetcLcLJetDefinition);
      instance.SetDelete(&delete_fastjetcLcLJetDefinition);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLJetDefinition);
      instance.SetDestructor(&destruct_fastjetcLcLJetDefinition);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::JetDefinition*)
   {
      return GenerateInitInstanceLocal((::fastjet::JetDefinition*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::JetDefinition*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLJetDefinition_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::JetDefinition*)0x0)->GetClass();
      fastjetcLcLJetDefinition_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLJetDefinition_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLJetDefinitioncLcLPlugin_Dictionary();
   static void fastjetcLcLJetDefinitioncLcLPlugin_TClassManip(TClass*);
   static void delete_fastjetcLcLJetDefinitioncLcLPlugin(void *p);
   static void deleteArray_fastjetcLcLJetDefinitioncLcLPlugin(void *p);
   static void destruct_fastjetcLcLJetDefinitioncLcLPlugin(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::JetDefinition::Plugin*)
   {
      ::fastjet::JetDefinition::Plugin *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::JetDefinition::Plugin),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::JetDefinition::Plugin", "fastjet/ClusterSequence.hh", 443,
                  typeid(::fastjet::JetDefinition::Plugin), DefineBehavior(ptr, ptr),
                  &fastjetcLcLJetDefinitioncLcLPlugin_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::JetDefinition::Plugin) );
      instance.SetDelete(&delete_fastjetcLcLJetDefinitioncLcLPlugin);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLJetDefinitioncLcLPlugin);
      instance.SetDestructor(&destruct_fastjetcLcLJetDefinitioncLcLPlugin);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::JetDefinition::Plugin*)
   {
      return GenerateInitInstanceLocal((::fastjet::JetDefinition::Plugin*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::JetDefinition::Plugin*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLJetDefinitioncLcLPlugin_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::JetDefinition::Plugin*)0x0)->GetClass();
      fastjetcLcLJetDefinitioncLcLPlugin_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLJetDefinitioncLcLPlugin_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLBasicRandomlEintgR_Dictionary();
   static void fastjetcLcLBasicRandomlEintgR_TClassManip(TClass*);
   static void *new_fastjetcLcLBasicRandomlEintgR(void *p = 0);
   static void *newArray_fastjetcLcLBasicRandomlEintgR(Long_t size, void *p);
   static void delete_fastjetcLcLBasicRandomlEintgR(void *p);
   static void deleteArray_fastjetcLcLBasicRandomlEintgR(void *p);
   static void destruct_fastjetcLcLBasicRandomlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::BasicRandom<int>*)
   {
      ::fastjet::BasicRandom<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::BasicRandom<int>),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::BasicRandom<int>", "fastjet/internal/BasicRandom.hh", 68,
                  typeid(::fastjet::BasicRandom<int>), DefineBehavior(ptr, ptr),
                  &fastjetcLcLBasicRandomlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::BasicRandom<int>) );
      instance.SetNew(&new_fastjetcLcLBasicRandomlEintgR);
      instance.SetNewArray(&newArray_fastjetcLcLBasicRandomlEintgR);
      instance.SetDelete(&delete_fastjetcLcLBasicRandomlEintgR);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLBasicRandomlEintgR);
      instance.SetDestructor(&destruct_fastjetcLcLBasicRandomlEintgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::BasicRandom<int>*)
   {
      return GenerateInitInstanceLocal((::fastjet::BasicRandom<int>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::BasicRandom<int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLBasicRandomlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::BasicRandom<int>*)0x0)->GetClass();
      fastjetcLcLBasicRandomlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLBasicRandomlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLBasicRandomlEdoublegR_Dictionary();
   static void fastjetcLcLBasicRandomlEdoublegR_TClassManip(TClass*);
   static void *new_fastjetcLcLBasicRandomlEdoublegR(void *p = 0);
   static void *newArray_fastjetcLcLBasicRandomlEdoublegR(Long_t size, void *p);
   static void delete_fastjetcLcLBasicRandomlEdoublegR(void *p);
   static void deleteArray_fastjetcLcLBasicRandomlEdoublegR(void *p);
   static void destruct_fastjetcLcLBasicRandomlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::BasicRandom<double>*)
   {
      ::fastjet::BasicRandom<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::BasicRandom<double>),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::BasicRandom<double>", "fastjet/internal/BasicRandom.hh", 128,
                  typeid(::fastjet::BasicRandom<double>), DefineBehavior(ptr, ptr),
                  &fastjetcLcLBasicRandomlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::BasicRandom<double>) );
      instance.SetNew(&new_fastjetcLcLBasicRandomlEdoublegR);
      instance.SetNewArray(&newArray_fastjetcLcLBasicRandomlEdoublegR);
      instance.SetDelete(&delete_fastjetcLcLBasicRandomlEdoublegR);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLBasicRandomlEdoublegR);
      instance.SetDestructor(&destruct_fastjetcLcLBasicRandomlEdoublegR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::BasicRandom<double>*)
   {
      return GenerateInitInstanceLocal((::fastjet::BasicRandom<double>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::BasicRandom<double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLBasicRandomlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::BasicRandom<double>*)0x0)->GetClass();
      fastjetcLcLBasicRandomlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLBasicRandomlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLAreaDefinition_Dictionary();
   static void fastjetcLcLAreaDefinition_TClassManip(TClass*);
   static void *new_fastjetcLcLAreaDefinition(void *p = 0);
   static void *newArray_fastjetcLcLAreaDefinition(Long_t size, void *p);
   static void delete_fastjetcLcLAreaDefinition(void *p);
   static void deleteArray_fastjetcLcLAreaDefinition(void *p);
   static void destruct_fastjetcLcLAreaDefinition(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::AreaDefinition*)
   {
      ::fastjet::AreaDefinition *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::AreaDefinition),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::AreaDefinition", "fastjet/AreaDefinition.hh", 80,
                  typeid(::fastjet::AreaDefinition), DefineBehavior(ptr, ptr),
                  &fastjetcLcLAreaDefinition_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::AreaDefinition) );
      instance.SetNew(&new_fastjetcLcLAreaDefinition);
      instance.SetNewArray(&newArray_fastjetcLcLAreaDefinition);
      instance.SetDelete(&delete_fastjetcLcLAreaDefinition);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLAreaDefinition);
      instance.SetDestructor(&destruct_fastjetcLcLAreaDefinition);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::AreaDefinition*)
   {
      return GenerateInitInstanceLocal((::fastjet::AreaDefinition*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::AreaDefinition*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLAreaDefinition_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::AreaDefinition*)0x0)->GetClass();
      fastjetcLcLAreaDefinition_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLAreaDefinition_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLPseudoJet_Dictionary();
   static void fastjetcLcLPseudoJet_TClassManip(TClass*);
   static void *new_fastjetcLcLPseudoJet(void *p = 0);
   static void *newArray_fastjetcLcLPseudoJet(Long_t size, void *p);
   static void delete_fastjetcLcLPseudoJet(void *p);
   static void deleteArray_fastjetcLcLPseudoJet(void *p);
   static void destruct_fastjetcLcLPseudoJet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::PseudoJet*)
   {
      ::fastjet::PseudoJet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::PseudoJet),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::PseudoJet", "tmp_include/fastjet/PseudoJet.hh", 62,
                  typeid(::fastjet::PseudoJet), DefineBehavior(ptr, ptr),
                  &fastjetcLcLPseudoJet_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::PseudoJet) );
      instance.SetNew(&new_fastjetcLcLPseudoJet);
      instance.SetNewArray(&newArray_fastjetcLcLPseudoJet);
      instance.SetDelete(&delete_fastjetcLcLPseudoJet);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLPseudoJet);
      instance.SetDestructor(&destruct_fastjetcLcLPseudoJet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::PseudoJet*)
   {
      return GenerateInitInstanceLocal((::fastjet::PseudoJet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::PseudoJet*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLPseudoJet_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::PseudoJet*)0x0)->GetClass();
      fastjetcLcLPseudoJet_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLPseudoJet_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLClusterSequence_Dictionary();
   static void fastjetcLcLClusterSequence_TClassManip(TClass*);
   static void *new_fastjetcLcLClusterSequence(void *p = 0);
   static void *newArray_fastjetcLcLClusterSequence(Long_t size, void *p);
   static void delete_fastjetcLcLClusterSequence(void *p);
   static void deleteArray_fastjetcLcLClusterSequence(void *p);
   static void destruct_fastjetcLcLClusterSequence(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::ClusterSequence*)
   {
      ::fastjet::ClusterSequence *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::ClusterSequence),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::ClusterSequence", "fastjet/ClusterSequence.hh", 120,
                  typeid(::fastjet::ClusterSequence), DefineBehavior(ptr, ptr),
                  &fastjetcLcLClusterSequence_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::ClusterSequence) );
      instance.SetNew(&new_fastjetcLcLClusterSequence);
      instance.SetNewArray(&newArray_fastjetcLcLClusterSequence);
      instance.SetDelete(&delete_fastjetcLcLClusterSequence);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLClusterSequence);
      instance.SetDestructor(&destruct_fastjetcLcLClusterSequence);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::ClusterSequence*)
   {
      return GenerateInitInstanceLocal((::fastjet::ClusterSequence*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::ClusterSequence*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLClusterSequence_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::ClusterSequence*)0x0)->GetClass();
      fastjetcLcLClusterSequence_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLClusterSequence_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLSelector_Dictionary();
   static void fastjetcLcLSelector_TClassManip(TClass*);
   static void *new_fastjetcLcLSelector(void *p = 0);
   static void *newArray_fastjetcLcLSelector(Long_t size, void *p);
   static void delete_fastjetcLcLSelector(void *p);
   static void deleteArray_fastjetcLcLSelector(void *p);
   static void destruct_fastjetcLcLSelector(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::Selector*)
   {
      ::fastjet::Selector *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::Selector),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::Selector", "fastjet/ClusterSequence.hh", 138,
                  typeid(::fastjet::Selector), DefineBehavior(ptr, ptr),
                  &fastjetcLcLSelector_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::Selector) );
      instance.SetNew(&new_fastjetcLcLSelector);
      instance.SetNewArray(&newArray_fastjetcLcLSelector);
      instance.SetDelete(&delete_fastjetcLcLSelector);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLSelector);
      instance.SetDestructor(&destruct_fastjetcLcLSelector);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::Selector*)
   {
      return GenerateInitInstanceLocal((::fastjet::Selector*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::Selector*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLSelector_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::Selector*)0x0)->GetClass();
      fastjetcLcLSelector_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLSelector_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLPseudoJetStructureBase_Dictionary();
   static void fastjetcLcLPseudoJetStructureBase_TClassManip(TClass*);
   static void *new_fastjetcLcLPseudoJetStructureBase(void *p = 0);
   static void *newArray_fastjetcLcLPseudoJetStructureBase(Long_t size, void *p);
   static void delete_fastjetcLcLPseudoJetStructureBase(void *p);
   static void deleteArray_fastjetcLcLPseudoJetStructureBase(void *p);
   static void destruct_fastjetcLcLPseudoJetStructureBase(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::PseudoJetStructureBase*)
   {
      ::fastjet::PseudoJetStructureBase *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::PseudoJetStructureBase),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::PseudoJetStructureBase", "fastjet/PseudoJetStructureBase.hh", 55,
                  typeid(::fastjet::PseudoJetStructureBase), DefineBehavior(ptr, ptr),
                  &fastjetcLcLPseudoJetStructureBase_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::PseudoJetStructureBase) );
      instance.SetNew(&new_fastjetcLcLPseudoJetStructureBase);
      instance.SetNewArray(&newArray_fastjetcLcLPseudoJetStructureBase);
      instance.SetDelete(&delete_fastjetcLcLPseudoJetStructureBase);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLPseudoJetStructureBase);
      instance.SetDestructor(&destruct_fastjetcLcLPseudoJetStructureBase);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::PseudoJetStructureBase*)
   {
      return GenerateInitInstanceLocal((::fastjet::PseudoJetStructureBase*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::PseudoJetStructureBase*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLPseudoJetStructureBase_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::PseudoJetStructureBase*)0x0)->GetClass();
      fastjetcLcLPseudoJetStructureBase_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLPseudoJetStructureBase_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLWrappedStructure_Dictionary();
   static void fastjetcLcLWrappedStructure_TClassManip(TClass*);
   static void delete_fastjetcLcLWrappedStructure(void *p);
   static void deleteArray_fastjetcLcLWrappedStructure(void *p);
   static void destruct_fastjetcLcLWrappedStructure(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::WrappedStructure*)
   {
      ::fastjet::WrappedStructure *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::WrappedStructure),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::WrappedStructure", "fastjet/WrappedStructure.hh", 51,
                  typeid(::fastjet::WrappedStructure), DefineBehavior(ptr, ptr),
                  &fastjetcLcLWrappedStructure_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::WrappedStructure) );
      instance.SetDelete(&delete_fastjetcLcLWrappedStructure);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLWrappedStructure);
      instance.SetDestructor(&destruct_fastjetcLcLWrappedStructure);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::WrappedStructure*)
   {
      return GenerateInitInstanceLocal((::fastjet::WrappedStructure*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::WrappedStructure*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLWrappedStructure_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::WrappedStructure*)0x0)->GetClass();
      fastjetcLcLWrappedStructure_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLWrappedStructure_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLTopTaggerBase_Dictionary();
   static void fastjetcLcLTopTaggerBase_TClassManip(TClass*);
   static void delete_fastjetcLcLTopTaggerBase(void *p);
   static void deleteArray_fastjetcLcLTopTaggerBase(void *p);
   static void destruct_fastjetcLcLTopTaggerBase(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::TopTaggerBase*)
   {
      ::fastjet::TopTaggerBase *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::TopTaggerBase),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::TopTaggerBase", "fastjet/tools/TopTaggerBase.hh", 53,
                  typeid(::fastjet::TopTaggerBase), DefineBehavior(ptr, ptr),
                  &fastjetcLcLTopTaggerBase_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::TopTaggerBase) );
      instance.SetDelete(&delete_fastjetcLcLTopTaggerBase);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLTopTaggerBase);
      instance.SetDestructor(&destruct_fastjetcLcLTopTaggerBase);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::TopTaggerBase*)
   {
      return GenerateInitInstanceLocal((::fastjet::TopTaggerBase*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::TopTaggerBase*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLTopTaggerBase_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::TopTaggerBase*)0x0)->GetClass();
      fastjetcLcLTopTaggerBase_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLTopTaggerBase_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLTopTaggerBaseStructure_Dictionary();
   static void fastjetcLcLTopTaggerBaseStructure_TClassManip(TClass*);
   static void delete_fastjetcLcLTopTaggerBaseStructure(void *p);
   static void deleteArray_fastjetcLcLTopTaggerBaseStructure(void *p);
   static void destruct_fastjetcLcLTopTaggerBaseStructure(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::TopTaggerBaseStructure*)
   {
      ::fastjet::TopTaggerBaseStructure *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::TopTaggerBaseStructure),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::TopTaggerBaseStructure", "fastjet/tools/TopTaggerBase.hh", 94,
                  typeid(::fastjet::TopTaggerBaseStructure), DefineBehavior(ptr, ptr),
                  &fastjetcLcLTopTaggerBaseStructure_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::TopTaggerBaseStructure) );
      instance.SetDelete(&delete_fastjetcLcLTopTaggerBaseStructure);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLTopTaggerBaseStructure);
      instance.SetDestructor(&destruct_fastjetcLcLTopTaggerBaseStructure);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::TopTaggerBaseStructure*)
   {
      return GenerateInitInstanceLocal((::fastjet::TopTaggerBaseStructure*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::TopTaggerBaseStructure*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLTopTaggerBaseStructure_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::TopTaggerBaseStructure*)0x0)->GetClass();
      fastjetcLcLTopTaggerBaseStructure_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLTopTaggerBaseStructure_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR_Dictionary();
   static void fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR_TClassManip(TClass*);
   static void delete_fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR(void *p);
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR(void *p);
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::FunctionOfPseudoJet<Double32_t>*)
   {
      ::fastjet::FunctionOfPseudoJet<Double32_t> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::FunctionOfPseudoJet<Double32_t>),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::FunctionOfPseudoJet<Double32_t>", "fastjet/ClusterSequence.hh", 46,
                  typeid(::fastjet::FunctionOfPseudoJet<Double32_t>), DefineBehavior(ptr, ptr),
                  &fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::FunctionOfPseudoJet<Double32_t>) );
      instance.SetDelete(&delete_fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR);
      instance.SetDestructor(&destruct_fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<Double32_t>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<Double32_t>*)0x0)->GetClass();
      fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLFunctionOfPseudoJetlEfloatgR_Dictionary();
   static void fastjetcLcLFunctionOfPseudoJetlEfloatgR_TClassManip(TClass*);
   static void delete_fastjetcLcLFunctionOfPseudoJetlEfloatgR(void *p);
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEfloatgR(void *p);
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::FunctionOfPseudoJet<float>*)
   {
      ::fastjet::FunctionOfPseudoJet<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::FunctionOfPseudoJet<float>),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::FunctionOfPseudoJet<float>", "fastjet/ClusterSequence.hh", 46,
                  typeid(::fastjet::FunctionOfPseudoJet<float>), DefineBehavior(ptr, ptr),
                  &fastjetcLcLFunctionOfPseudoJetlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::FunctionOfPseudoJet<float>) );
      instance.SetDelete(&delete_fastjetcLcLFunctionOfPseudoJetlEfloatgR);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLFunctionOfPseudoJetlEfloatgR);
      instance.SetDestructor(&destruct_fastjetcLcLFunctionOfPseudoJetlEfloatgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::FunctionOfPseudoJet<float>*)
   {
      return GenerateInitInstanceLocal((::fastjet::FunctionOfPseudoJet<float>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<float>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLFunctionOfPseudoJetlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<float>*)0x0)->GetClass();
      fastjetcLcLFunctionOfPseudoJetlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLFunctionOfPseudoJetlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLFunctionOfPseudoJetlEintgR_Dictionary();
   static void fastjetcLcLFunctionOfPseudoJetlEintgR_TClassManip(TClass*);
   static void delete_fastjetcLcLFunctionOfPseudoJetlEintgR(void *p);
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEintgR(void *p);
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::FunctionOfPseudoJet<int>*)
   {
      ::fastjet::FunctionOfPseudoJet<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::FunctionOfPseudoJet<int>),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::FunctionOfPseudoJet<int>", "fastjet/ClusterSequence.hh", 46,
                  typeid(::fastjet::FunctionOfPseudoJet<int>), DefineBehavior(ptr, ptr),
                  &fastjetcLcLFunctionOfPseudoJetlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::FunctionOfPseudoJet<int>) );
      instance.SetDelete(&delete_fastjetcLcLFunctionOfPseudoJetlEintgR);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLFunctionOfPseudoJetlEintgR);
      instance.SetDestructor(&destruct_fastjetcLcLFunctionOfPseudoJetlEintgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::FunctionOfPseudoJet<int>*)
   {
      return GenerateInitInstanceLocal((::fastjet::FunctionOfPseudoJet<int>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLFunctionOfPseudoJetlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<int>*)0x0)->GetClass();
      fastjetcLcLFunctionOfPseudoJetlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLFunctionOfPseudoJetlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLFunctionOfPseudoJetlEboolgR_Dictionary();
   static void fastjetcLcLFunctionOfPseudoJetlEboolgR_TClassManip(TClass*);
   static void delete_fastjetcLcLFunctionOfPseudoJetlEboolgR(void *p);
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEboolgR(void *p);
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEboolgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::FunctionOfPseudoJet<bool>*)
   {
      ::fastjet::FunctionOfPseudoJet<bool> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::FunctionOfPseudoJet<bool>),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::FunctionOfPseudoJet<bool>", "fastjet/ClusterSequence.hh", 46,
                  typeid(::fastjet::FunctionOfPseudoJet<bool>), DefineBehavior(ptr, ptr),
                  &fastjetcLcLFunctionOfPseudoJetlEboolgR_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::FunctionOfPseudoJet<bool>) );
      instance.SetDelete(&delete_fastjetcLcLFunctionOfPseudoJetlEboolgR);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLFunctionOfPseudoJetlEboolgR);
      instance.SetDestructor(&destruct_fastjetcLcLFunctionOfPseudoJetlEboolgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::FunctionOfPseudoJet<bool>*)
   {
      return GenerateInitInstanceLocal((::fastjet::FunctionOfPseudoJet<bool>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<bool>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLFunctionOfPseudoJetlEboolgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<bool>*)0x0)->GetClass();
      fastjetcLcLFunctionOfPseudoJetlEboolgR_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLFunctionOfPseudoJetlEboolgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR_Dictionary();
   static void fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR_TClassManip(TClass*);
   static void delete_fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR(void *p);
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR(void *p);
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::FunctionOfPseudoJet<vector<Double32_t> >*)
   {
      ::fastjet::FunctionOfPseudoJet<vector<Double32_t> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::FunctionOfPseudoJet<vector<Double32_t> >),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::FunctionOfPseudoJet<vector<Double32_t> >", "fastjet/ClusterSequence.hh", 46,
                  typeid(::fastjet::FunctionOfPseudoJet<vector<Double32_t> >), DefineBehavior(ptr, ptr),
                  &fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::FunctionOfPseudoJet<vector<Double32_t> >) );
      instance.SetDelete(&delete_fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR);
      instance.SetDestructor(&destruct_fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR);

      AddClassAlternate("fastjet::FunctionOfPseudoJet<vector<Double32_t> >","fastjet::FunctionOfPseudoJet<std::vector<Double32_t> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<vector<Double32_t> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<vector<Double32_t> >*)0x0)->GetClass();
      fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR_Dictionary();
   static void fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR_TClassManip(TClass*);
   static void delete_fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR(void *p);
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR(void *p);
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::FunctionOfPseudoJet<vector<float> >*)
   {
      ::fastjet::FunctionOfPseudoJet<vector<float> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::FunctionOfPseudoJet<vector<float> >),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::FunctionOfPseudoJet<vector<float> >", "fastjet/ClusterSequence.hh", 46,
                  typeid(::fastjet::FunctionOfPseudoJet<vector<float> >), DefineBehavior(ptr, ptr),
                  &fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::FunctionOfPseudoJet<vector<float> >) );
      instance.SetDelete(&delete_fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR);
      instance.SetDestructor(&destruct_fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR);

      AddClassAlternate("fastjet::FunctionOfPseudoJet<vector<float> >","fastjet::FunctionOfPseudoJet<std::vector<float> >");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::FunctionOfPseudoJet<vector<float> >*)
   {
      return GenerateInitInstanceLocal((::fastjet::FunctionOfPseudoJet<vector<float> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<vector<float> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<vector<float> >*)0x0)->GetClass();
      fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR_Dictionary();
   static void fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR_TClassManip(TClass*);
   static void delete_fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR(void *p);
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR(void *p);
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::FunctionOfPseudoJet<vector<int> >*)
   {
      ::fastjet::FunctionOfPseudoJet<vector<int> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::FunctionOfPseudoJet<vector<int> >),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::FunctionOfPseudoJet<vector<int> >", "fastjet/ClusterSequence.hh", 46,
                  typeid(::fastjet::FunctionOfPseudoJet<vector<int> >), DefineBehavior(ptr, ptr),
                  &fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::FunctionOfPseudoJet<vector<int> >) );
      instance.SetDelete(&delete_fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR);
      instance.SetDestructor(&destruct_fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR);

      AddClassAlternate("fastjet::FunctionOfPseudoJet<vector<int> >","fastjet::FunctionOfPseudoJet<std::vector<int> >");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::FunctionOfPseudoJet<vector<int> >*)
   {
      return GenerateInitInstanceLocal((::fastjet::FunctionOfPseudoJet<vector<int> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<vector<int> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<vector<int> >*)0x0)->GetClass();
      fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR_Dictionary();
   static void fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR_TClassManip(TClass*);
   static void delete_fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR(void *p);
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR(void *p);
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::FunctionOfPseudoJet<vector<bool> >*)
   {
      ::fastjet::FunctionOfPseudoJet<vector<bool> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::FunctionOfPseudoJet<vector<bool> >),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::FunctionOfPseudoJet<vector<bool> >", "fastjet/ClusterSequence.hh", 46,
                  typeid(::fastjet::FunctionOfPseudoJet<vector<bool> >), DefineBehavior(ptr, ptr),
                  &fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::FunctionOfPseudoJet<vector<bool> >) );
      instance.SetDelete(&delete_fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR);
      instance.SetDestructor(&destruct_fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR);

      AddClassAlternate("fastjet::FunctionOfPseudoJet<vector<bool> >","fastjet::FunctionOfPseudoJet<std::vector<bool> >");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::FunctionOfPseudoJet<vector<bool> >*)
   {
      return GenerateInitInstanceLocal((::fastjet::FunctionOfPseudoJet<vector<bool> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<vector<bool> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<vector<bool> >*)0x0)->GetClass();
      fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR_Dictionary();
   static void fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR_TClassManip(TClass*);
   static void delete_fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR(void *p);
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR(void *p);
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>*)
   {
      ::fastjet::FunctionOfPseudoJet<fastjet::PseudoJet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>", "fastjet/ClusterSequence.hh", 46,
                  typeid(::fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>), DefineBehavior(ptr, ptr),
                  &fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>) );
      instance.SetDelete(&delete_fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR);
      instance.SetDestructor(&destruct_fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>*)
   {
      return GenerateInitInstanceLocal((::fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>*)0x0)->GetClass();
      fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLTransformer_Dictionary();
   static void fastjetcLcLTransformer_TClassManip(TClass*);
   static void delete_fastjetcLcLTransformer(void *p);
   static void deleteArray_fastjetcLcLTransformer(void *p);
   static void destruct_fastjetcLcLTransformer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::Transformer*)
   {
      ::fastjet::Transformer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::Transformer),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::Transformer", "fastjet/tools/Transformer.hh", 69,
                  typeid(::fastjet::Transformer), DefineBehavior(ptr, ptr),
                  &fastjetcLcLTransformer_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::Transformer) );
      instance.SetDelete(&delete_fastjetcLcLTransformer);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLTransformer);
      instance.SetDestructor(&destruct_fastjetcLcLTransformer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::Transformer*)
   {
      return GenerateInitInstanceLocal((::fastjet::Transformer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::Transformer*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLTransformer_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::Transformer*)0x0)->GetClass();
      fastjetcLcLTransformer_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLTransformer_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLBoost_Dictionary();
   static void fastjetcLcLBoost_TClassManip(TClass*);
   static void delete_fastjetcLcLBoost(void *p);
   static void deleteArray_fastjetcLcLBoost(void *p);
   static void destruct_fastjetcLcLBoost(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::Boost*)
   {
      ::fastjet::Boost *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::Boost),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::Boost", "fastjet/tools/Boost.hh", 45,
                  typeid(::fastjet::Boost), DefineBehavior(ptr, ptr),
                  &fastjetcLcLBoost_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::Boost) );
      instance.SetDelete(&delete_fastjetcLcLBoost);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLBoost);
      instance.SetDestructor(&destruct_fastjetcLcLBoost);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::Boost*)
   {
      return GenerateInitInstanceLocal((::fastjet::Boost*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::Boost*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLBoost_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::Boost*)0x0)->GetClass();
      fastjetcLcLBoost_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLBoost_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLCASubJetTagger_Dictionary();
   static void fastjetcLcLCASubJetTagger_TClassManip(TClass*);
   static void *new_fastjetcLcLCASubJetTagger(void *p = 0);
   static void *newArray_fastjetcLcLCASubJetTagger(Long_t size, void *p);
   static void delete_fastjetcLcLCASubJetTagger(void *p);
   static void deleteArray_fastjetcLcLCASubJetTagger(void *p);
   static void destruct_fastjetcLcLCASubJetTagger(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::CASubJetTagger*)
   {
      ::fastjet::CASubJetTagger *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::CASubJetTagger),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::CASubJetTagger", "fastjet/tools/CASubJetTagger.hh", 104,
                  typeid(::fastjet::CASubJetTagger), DefineBehavior(ptr, ptr),
                  &fastjetcLcLCASubJetTagger_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::CASubJetTagger) );
      instance.SetNew(&new_fastjetcLcLCASubJetTagger);
      instance.SetNewArray(&newArray_fastjetcLcLCASubJetTagger);
      instance.SetDelete(&delete_fastjetcLcLCASubJetTagger);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLCASubJetTagger);
      instance.SetDestructor(&destruct_fastjetcLcLCASubJetTagger);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::CASubJetTagger*)
   {
      return GenerateInitInstanceLocal((::fastjet::CASubJetTagger*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::CASubJetTagger*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLCASubJetTagger_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::CASubJetTagger*)0x0)->GetClass();
      fastjetcLcLCASubJetTagger_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLCASubJetTagger_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLFilter_Dictionary();
   static void fastjetcLcLFilter_TClassManip(TClass*);
   static void *new_fastjetcLcLFilter(void *p = 0);
   static void *newArray_fastjetcLcLFilter(Long_t size, void *p);
   static void delete_fastjetcLcLFilter(void *p);
   static void deleteArray_fastjetcLcLFilter(void *p);
   static void destruct_fastjetcLcLFilter(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::Filter*)
   {
      ::fastjet::Filter *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::Filter),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::Filter", "fastjet/tools/Filter.hh", 91,
                  typeid(::fastjet::Filter), DefineBehavior(ptr, ptr),
                  &fastjetcLcLFilter_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::Filter) );
      instance.SetNew(&new_fastjetcLcLFilter);
      instance.SetNewArray(&newArray_fastjetcLcLFilter);
      instance.SetDelete(&delete_fastjetcLcLFilter);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLFilter);
      instance.SetDestructor(&destruct_fastjetcLcLFilter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::Filter*)
   {
      return GenerateInitInstanceLocal((::fastjet::Filter*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::Filter*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLFilter_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::Filter*)0x0)->GetClass();
      fastjetcLcLFilter_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLFilter_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLGridMedianBackgroundEstimator_Dictionary();
   static void fastjetcLcLGridMedianBackgroundEstimator_TClassManip(TClass*);
   static void delete_fastjetcLcLGridMedianBackgroundEstimator(void *p);
   static void deleteArray_fastjetcLcLGridMedianBackgroundEstimator(void *p);
   static void destruct_fastjetcLcLGridMedianBackgroundEstimator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::GridMedianBackgroundEstimator*)
   {
      ::fastjet::GridMedianBackgroundEstimator *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::GridMedianBackgroundEstimator),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::GridMedianBackgroundEstimator", "fastjet/tools/GridMedianBackgroundEstimator.hh", 63,
                  typeid(::fastjet::GridMedianBackgroundEstimator), DefineBehavior(ptr, ptr),
                  &fastjetcLcLGridMedianBackgroundEstimator_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::GridMedianBackgroundEstimator) );
      instance.SetDelete(&delete_fastjetcLcLGridMedianBackgroundEstimator);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLGridMedianBackgroundEstimator);
      instance.SetDestructor(&destruct_fastjetcLcLGridMedianBackgroundEstimator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::GridMedianBackgroundEstimator*)
   {
      return GenerateInitInstanceLocal((::fastjet::GridMedianBackgroundEstimator*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::GridMedianBackgroundEstimator*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLGridMedianBackgroundEstimator_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::GridMedianBackgroundEstimator*)0x0)->GetClass();
      fastjetcLcLGridMedianBackgroundEstimator_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLGridMedianBackgroundEstimator_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLJetMedianBackgroundEstimator_Dictionary();
   static void fastjetcLcLJetMedianBackgroundEstimator_TClassManip(TClass*);
   static void *new_fastjetcLcLJetMedianBackgroundEstimator(void *p = 0);
   static void *newArray_fastjetcLcLJetMedianBackgroundEstimator(Long_t size, void *p);
   static void delete_fastjetcLcLJetMedianBackgroundEstimator(void *p);
   static void deleteArray_fastjetcLcLJetMedianBackgroundEstimator(void *p);
   static void destruct_fastjetcLcLJetMedianBackgroundEstimator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::JetMedianBackgroundEstimator*)
   {
      ::fastjet::JetMedianBackgroundEstimator *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::JetMedianBackgroundEstimator),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::JetMedianBackgroundEstimator", "fastjet/tools/JetMedianBackgroundEstimator.hh", 78,
                  typeid(::fastjet::JetMedianBackgroundEstimator), DefineBehavior(ptr, ptr),
                  &fastjetcLcLJetMedianBackgroundEstimator_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::JetMedianBackgroundEstimator) );
      instance.SetNew(&new_fastjetcLcLJetMedianBackgroundEstimator);
      instance.SetNewArray(&newArray_fastjetcLcLJetMedianBackgroundEstimator);
      instance.SetDelete(&delete_fastjetcLcLJetMedianBackgroundEstimator);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLJetMedianBackgroundEstimator);
      instance.SetDestructor(&destruct_fastjetcLcLJetMedianBackgroundEstimator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::JetMedianBackgroundEstimator*)
   {
      return GenerateInitInstanceLocal((::fastjet::JetMedianBackgroundEstimator*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::JetMedianBackgroundEstimator*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLJetMedianBackgroundEstimator_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::JetMedianBackgroundEstimator*)0x0)->GetClass();
      fastjetcLcLJetMedianBackgroundEstimator_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLJetMedianBackgroundEstimator_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLMassDropTagger_Dictionary();
   static void fastjetcLcLMassDropTagger_TClassManip(TClass*);
   static void *new_fastjetcLcLMassDropTagger(void *p = 0);
   static void *newArray_fastjetcLcLMassDropTagger(Long_t size, void *p);
   static void delete_fastjetcLcLMassDropTagger(void *p);
   static void deleteArray_fastjetcLcLMassDropTagger(void *p);
   static void destruct_fastjetcLcLMassDropTagger(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::MassDropTagger*)
   {
      ::fastjet::MassDropTagger *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::MassDropTagger),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::MassDropTagger", "fastjet/tools/MassDropTagger.hh", 90,
                  typeid(::fastjet::MassDropTagger), DefineBehavior(ptr, ptr),
                  &fastjetcLcLMassDropTagger_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::MassDropTagger) );
      instance.SetNew(&new_fastjetcLcLMassDropTagger);
      instance.SetNewArray(&newArray_fastjetcLcLMassDropTagger);
      instance.SetDelete(&delete_fastjetcLcLMassDropTagger);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLMassDropTagger);
      instance.SetDestructor(&destruct_fastjetcLcLMassDropTagger);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::MassDropTagger*)
   {
      return GenerateInitInstanceLocal((::fastjet::MassDropTagger*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::MassDropTagger*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLMassDropTagger_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::MassDropTagger*)0x0)->GetClass();
      fastjetcLcLMassDropTagger_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLMassDropTagger_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLRestFrameNSubjettinessTagger_Dictionary();
   static void fastjetcLcLRestFrameNSubjettinessTagger_TClassManip(TClass*);
   static void delete_fastjetcLcLRestFrameNSubjettinessTagger(void *p);
   static void deleteArray_fastjetcLcLRestFrameNSubjettinessTagger(void *p);
   static void destruct_fastjetcLcLRestFrameNSubjettinessTagger(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::RestFrameNSubjettinessTagger*)
   {
      ::fastjet::RestFrameNSubjettinessTagger *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::RestFrameNSubjettinessTagger),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::RestFrameNSubjettinessTagger", "fastjet/tools/RestFrameNSubjettinessTagger.hh", 99,
                  typeid(::fastjet::RestFrameNSubjettinessTagger), DefineBehavior(ptr, ptr),
                  &fastjetcLcLRestFrameNSubjettinessTagger_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::RestFrameNSubjettinessTagger) );
      instance.SetDelete(&delete_fastjetcLcLRestFrameNSubjettinessTagger);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLRestFrameNSubjettinessTagger);
      instance.SetDestructor(&destruct_fastjetcLcLRestFrameNSubjettinessTagger);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::RestFrameNSubjettinessTagger*)
   {
      return GenerateInitInstanceLocal((::fastjet::RestFrameNSubjettinessTagger*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::RestFrameNSubjettinessTagger*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLRestFrameNSubjettinessTagger_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::RestFrameNSubjettinessTagger*)0x0)->GetClass();
      fastjetcLcLRestFrameNSubjettinessTagger_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLRestFrameNSubjettinessTagger_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLRestFrameNSubjettinessTaggerStructure_Dictionary();
   static void fastjetcLcLRestFrameNSubjettinessTaggerStructure_TClassManip(TClass*);
   static void delete_fastjetcLcLRestFrameNSubjettinessTaggerStructure(void *p);
   static void deleteArray_fastjetcLcLRestFrameNSubjettinessTaggerStructure(void *p);
   static void destruct_fastjetcLcLRestFrameNSubjettinessTaggerStructure(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::RestFrameNSubjettinessTaggerStructure*)
   {
      ::fastjet::RestFrameNSubjettinessTaggerStructure *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::RestFrameNSubjettinessTaggerStructure),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::RestFrameNSubjettinessTaggerStructure", "fastjet/tools/RestFrameNSubjettinessTagger.hh", 135,
                  typeid(::fastjet::RestFrameNSubjettinessTaggerStructure), DefineBehavior(ptr, ptr),
                  &fastjetcLcLRestFrameNSubjettinessTaggerStructure_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::RestFrameNSubjettinessTaggerStructure) );
      instance.SetDelete(&delete_fastjetcLcLRestFrameNSubjettinessTaggerStructure);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLRestFrameNSubjettinessTaggerStructure);
      instance.SetDestructor(&destruct_fastjetcLcLRestFrameNSubjettinessTaggerStructure);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::RestFrameNSubjettinessTaggerStructure*)
   {
      return GenerateInitInstanceLocal((::fastjet::RestFrameNSubjettinessTaggerStructure*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::RestFrameNSubjettinessTaggerStructure*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLRestFrameNSubjettinessTaggerStructure_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::RestFrameNSubjettinessTaggerStructure*)0x0)->GetClass();
      fastjetcLcLRestFrameNSubjettinessTaggerStructure_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLRestFrameNSubjettinessTaggerStructure_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLSubtractor_Dictionary();
   static void fastjetcLcLSubtractor_TClassManip(TClass*);
   static void *new_fastjetcLcLSubtractor(void *p = 0);
   static void *newArray_fastjetcLcLSubtractor(Long_t size, void *p);
   static void delete_fastjetcLcLSubtractor(void *p);
   static void deleteArray_fastjetcLcLSubtractor(void *p);
   static void destruct_fastjetcLcLSubtractor(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::Subtractor*)
   {
      ::fastjet::Subtractor *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::Subtractor),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::Subtractor", "fastjet/tools/Subtractor.hh", 59,
                  typeid(::fastjet::Subtractor), DefineBehavior(ptr, ptr),
                  &fastjetcLcLSubtractor_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::Subtractor) );
      instance.SetNew(&new_fastjetcLcLSubtractor);
      instance.SetNewArray(&newArray_fastjetcLcLSubtractor);
      instance.SetDelete(&delete_fastjetcLcLSubtractor);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLSubtractor);
      instance.SetDestructor(&destruct_fastjetcLcLSubtractor);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::Subtractor*)
   {
      return GenerateInitInstanceLocal((::fastjet::Subtractor*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::Subtractor*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLSubtractor_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::Subtractor*)0x0)->GetClass();
      fastjetcLcLSubtractor_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLSubtractor_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLJHTopTagger_Dictionary();
   static void fastjetcLcLJHTopTagger_TClassManip(TClass*);
   static void *new_fastjetcLcLJHTopTagger(void *p = 0);
   static void *newArray_fastjetcLcLJHTopTagger(Long_t size, void *p);
   static void delete_fastjetcLcLJHTopTagger(void *p);
   static void deleteArray_fastjetcLcLJHTopTagger(void *p);
   static void destruct_fastjetcLcLJHTopTagger(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::JHTopTagger*)
   {
      ::fastjet::JHTopTagger *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::JHTopTagger),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::JHTopTagger", "fastjet/tools/JHTopTagger.hh", 118,
                  typeid(::fastjet::JHTopTagger), DefineBehavior(ptr, ptr),
                  &fastjetcLcLJHTopTagger_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::JHTopTagger) );
      instance.SetNew(&new_fastjetcLcLJHTopTagger);
      instance.SetNewArray(&newArray_fastjetcLcLJHTopTagger);
      instance.SetDelete(&delete_fastjetcLcLJHTopTagger);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLJHTopTagger);
      instance.SetDestructor(&destruct_fastjetcLcLJHTopTagger);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::JHTopTagger*)
   {
      return GenerateInitInstanceLocal((::fastjet::JHTopTagger*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::JHTopTagger*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLJHTopTagger_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::JHTopTagger*)0x0)->GetClass();
      fastjetcLcLJHTopTagger_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLJHTopTagger_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLJHTopTaggerStructure_Dictionary();
   static void fastjetcLcLJHTopTaggerStructure_TClassManip(TClass*);
   static void delete_fastjetcLcLJHTopTaggerStructure(void *p);
   static void deleteArray_fastjetcLcLJHTopTaggerStructure(void *p);
   static void destruct_fastjetcLcLJHTopTaggerStructure(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::JHTopTaggerStructure*)
   {
      ::fastjet::JHTopTaggerStructure *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::JHTopTaggerStructure),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::JHTopTaggerStructure", "fastjet/tools/JHTopTagger.hh", 167,
                  typeid(::fastjet::JHTopTaggerStructure), DefineBehavior(ptr, ptr),
                  &fastjetcLcLJHTopTaggerStructure_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::JHTopTaggerStructure) );
      instance.SetDelete(&delete_fastjetcLcLJHTopTaggerStructure);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLJHTopTaggerStructure);
      instance.SetDestructor(&destruct_fastjetcLcLJHTopTaggerStructure);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::JHTopTaggerStructure*)
   {
      return GenerateInitInstanceLocal((::fastjet::JHTopTaggerStructure*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::JHTopTaggerStructure*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLJHTopTaggerStructure_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::JHTopTaggerStructure*)0x0)->GetClass();
      fastjetcLcLJHTopTaggerStructure_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLJHTopTaggerStructure_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLUnboost_Dictionary();
   static void fastjetcLcLUnboost_TClassManip(TClass*);
   static void delete_fastjetcLcLUnboost(void *p);
   static void deleteArray_fastjetcLcLUnboost(void *p);
   static void destruct_fastjetcLcLUnboost(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::Unboost*)
   {
      ::fastjet::Unboost *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::Unboost),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::Unboost", "fastjet/tools/Boost.hh", 68,
                  typeid(::fastjet::Unboost), DefineBehavior(ptr, ptr),
                  &fastjetcLcLUnboost_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::Unboost) );
      instance.SetDelete(&delete_fastjetcLcLUnboost);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLUnboost);
      instance.SetDestructor(&destruct_fastjetcLcLUnboost);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::Unboost*)
   {
      return GenerateInitInstanceLocal((::fastjet::Unboost*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::Unboost*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLUnboost_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::Unboost*)0x0)->GetClass();
      fastjetcLcLUnboost_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLUnboost_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLPruner_Dictionary();
   static void fastjetcLcLPruner_TClassManip(TClass*);
   static void delete_fastjetcLcLPruner(void *p);
   static void deleteArray_fastjetcLcLPruner(void *p);
   static void destruct_fastjetcLcLPruner(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::Pruner*)
   {
      ::fastjet::Pruner *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::Pruner),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::Pruner", "fastjet/tools/Pruner.hh", 100,
                  typeid(::fastjet::Pruner), DefineBehavior(ptr, ptr),
                  &fastjetcLcLPruner_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::Pruner) );
      instance.SetDelete(&delete_fastjetcLcLPruner);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLPruner);
      instance.SetDestructor(&destruct_fastjetcLcLPruner);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::Pruner*)
   {
      return GenerateInitInstanceLocal((::fastjet::Pruner*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::Pruner*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLPruner_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::Pruner*)0x0)->GetClass();
      fastjetcLcLPruner_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLPruner_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *fastjetcLcLPrunerStructure_Dictionary();
   static void fastjetcLcLPrunerStructure_TClassManip(TClass*);
   static void delete_fastjetcLcLPrunerStructure(void *p);
   static void deleteArray_fastjetcLcLPrunerStructure(void *p);
   static void destruct_fastjetcLcLPrunerStructure(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::fastjet::PrunerStructure*)
   {
      ::fastjet::PrunerStructure *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::fastjet::PrunerStructure),0);
      static ::ROOT::TGenericClassInfo 
         instance("fastjet::PrunerStructure", "fastjet/tools/Pruner.hh", 176,
                  typeid(::fastjet::PrunerStructure), DefineBehavior(ptr, ptr),
                  &fastjetcLcLPrunerStructure_Dictionary, isa_proxy, 0,
                  sizeof(::fastjet::PrunerStructure) );
      instance.SetDelete(&delete_fastjetcLcLPrunerStructure);
      instance.SetDeleteArray(&deleteArray_fastjetcLcLPrunerStructure);
      instance.SetDestructor(&destruct_fastjetcLcLPrunerStructure);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::fastjet::PrunerStructure*)
   {
      return GenerateInitInstanceLocal((::fastjet::PrunerStructure*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::fastjet::PrunerStructure*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *fastjetcLcLPrunerStructure_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::fastjet::PrunerStructure*)0x0)->GetClass();
      fastjetcLcLPrunerStructure_TClassManip(theClass);
   return theClass;
   }

   static void fastjetcLcLPrunerStructure_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLJetDefinition(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::JetDefinition : new ::fastjet::JetDefinition;
   }
   static void *newArray_fastjetcLcLJetDefinition(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::JetDefinition[nElements] : new ::fastjet::JetDefinition[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLJetDefinition(void *p) {
      delete ((::fastjet::JetDefinition*)p);
   }
   static void deleteArray_fastjetcLcLJetDefinition(void *p) {
      delete [] ((::fastjet::JetDefinition*)p);
   }
   static void destruct_fastjetcLcLJetDefinition(void *p) {
      typedef ::fastjet::JetDefinition current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::JetDefinition

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLJetDefinitioncLcLPlugin(void *p) {
      delete ((::fastjet::JetDefinition::Plugin*)p);
   }
   static void deleteArray_fastjetcLcLJetDefinitioncLcLPlugin(void *p) {
      delete [] ((::fastjet::JetDefinition::Plugin*)p);
   }
   static void destruct_fastjetcLcLJetDefinitioncLcLPlugin(void *p) {
      typedef ::fastjet::JetDefinition::Plugin current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::JetDefinition::Plugin

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLBasicRandomlEintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::BasicRandom<int> : new ::fastjet::BasicRandom<int>;
   }
   static void *newArray_fastjetcLcLBasicRandomlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::BasicRandom<int>[nElements] : new ::fastjet::BasicRandom<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLBasicRandomlEintgR(void *p) {
      delete ((::fastjet::BasicRandom<int>*)p);
   }
   static void deleteArray_fastjetcLcLBasicRandomlEintgR(void *p) {
      delete [] ((::fastjet::BasicRandom<int>*)p);
   }
   static void destruct_fastjetcLcLBasicRandomlEintgR(void *p) {
      typedef ::fastjet::BasicRandom<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::BasicRandom<int>

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLBasicRandomlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::BasicRandom<double> : new ::fastjet::BasicRandom<double>;
   }
   static void *newArray_fastjetcLcLBasicRandomlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::BasicRandom<double>[nElements] : new ::fastjet::BasicRandom<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLBasicRandomlEdoublegR(void *p) {
      delete ((::fastjet::BasicRandom<double>*)p);
   }
   static void deleteArray_fastjetcLcLBasicRandomlEdoublegR(void *p) {
      delete [] ((::fastjet::BasicRandom<double>*)p);
   }
   static void destruct_fastjetcLcLBasicRandomlEdoublegR(void *p) {
      typedef ::fastjet::BasicRandom<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::BasicRandom<double>

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLAreaDefinition(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::AreaDefinition : new ::fastjet::AreaDefinition;
   }
   static void *newArray_fastjetcLcLAreaDefinition(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::AreaDefinition[nElements] : new ::fastjet::AreaDefinition[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLAreaDefinition(void *p) {
      delete ((::fastjet::AreaDefinition*)p);
   }
   static void deleteArray_fastjetcLcLAreaDefinition(void *p) {
      delete [] ((::fastjet::AreaDefinition*)p);
   }
   static void destruct_fastjetcLcLAreaDefinition(void *p) {
      typedef ::fastjet::AreaDefinition current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::AreaDefinition

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLPseudoJet(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::PseudoJet : new ::fastjet::PseudoJet;
   }
   static void *newArray_fastjetcLcLPseudoJet(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::PseudoJet[nElements] : new ::fastjet::PseudoJet[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLPseudoJet(void *p) {
      delete ((::fastjet::PseudoJet*)p);
   }
   static void deleteArray_fastjetcLcLPseudoJet(void *p) {
      delete [] ((::fastjet::PseudoJet*)p);
   }
   static void destruct_fastjetcLcLPseudoJet(void *p) {
      typedef ::fastjet::PseudoJet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::PseudoJet

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLClusterSequence(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::ClusterSequence : new ::fastjet::ClusterSequence;
   }
   static void *newArray_fastjetcLcLClusterSequence(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::ClusterSequence[nElements] : new ::fastjet::ClusterSequence[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLClusterSequence(void *p) {
      delete ((::fastjet::ClusterSequence*)p);
   }
   static void deleteArray_fastjetcLcLClusterSequence(void *p) {
      delete [] ((::fastjet::ClusterSequence*)p);
   }
   static void destruct_fastjetcLcLClusterSequence(void *p) {
      typedef ::fastjet::ClusterSequence current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::ClusterSequence

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLSelector(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::Selector : new ::fastjet::Selector;
   }
   static void *newArray_fastjetcLcLSelector(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::Selector[nElements] : new ::fastjet::Selector[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLSelector(void *p) {
      delete ((::fastjet::Selector*)p);
   }
   static void deleteArray_fastjetcLcLSelector(void *p) {
      delete [] ((::fastjet::Selector*)p);
   }
   static void destruct_fastjetcLcLSelector(void *p) {
      typedef ::fastjet::Selector current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::Selector

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLPseudoJetStructureBase(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::PseudoJetStructureBase : new ::fastjet::PseudoJetStructureBase;
   }
   static void *newArray_fastjetcLcLPseudoJetStructureBase(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::PseudoJetStructureBase[nElements] : new ::fastjet::PseudoJetStructureBase[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLPseudoJetStructureBase(void *p) {
      delete ((::fastjet::PseudoJetStructureBase*)p);
   }
   static void deleteArray_fastjetcLcLPseudoJetStructureBase(void *p) {
      delete [] ((::fastjet::PseudoJetStructureBase*)p);
   }
   static void destruct_fastjetcLcLPseudoJetStructureBase(void *p) {
      typedef ::fastjet::PseudoJetStructureBase current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::PseudoJetStructureBase

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLWrappedStructure(void *p) {
      delete ((::fastjet::WrappedStructure*)p);
   }
   static void deleteArray_fastjetcLcLWrappedStructure(void *p) {
      delete [] ((::fastjet::WrappedStructure*)p);
   }
   static void destruct_fastjetcLcLWrappedStructure(void *p) {
      typedef ::fastjet::WrappedStructure current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::WrappedStructure

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLTopTaggerBase(void *p) {
      delete ((::fastjet::TopTaggerBase*)p);
   }
   static void deleteArray_fastjetcLcLTopTaggerBase(void *p) {
      delete [] ((::fastjet::TopTaggerBase*)p);
   }
   static void destruct_fastjetcLcLTopTaggerBase(void *p) {
      typedef ::fastjet::TopTaggerBase current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::TopTaggerBase

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLTopTaggerBaseStructure(void *p) {
      delete ((::fastjet::TopTaggerBaseStructure*)p);
   }
   static void deleteArray_fastjetcLcLTopTaggerBaseStructure(void *p) {
      delete [] ((::fastjet::TopTaggerBaseStructure*)p);
   }
   static void destruct_fastjetcLcLTopTaggerBaseStructure(void *p) {
      typedef ::fastjet::TopTaggerBaseStructure current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::TopTaggerBaseStructure

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR(void *p) {
      delete ((::fastjet::FunctionOfPseudoJet<Double32_t>*)p);
   }
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR(void *p) {
      delete [] ((::fastjet::FunctionOfPseudoJet<Double32_t>*)p);
   }
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEDouble32_tgR(void *p) {
      typedef ::fastjet::FunctionOfPseudoJet<Double32_t> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::FunctionOfPseudoJet<Double32_t>

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLFunctionOfPseudoJetlEfloatgR(void *p) {
      delete ((::fastjet::FunctionOfPseudoJet<float>*)p);
   }
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEfloatgR(void *p) {
      delete [] ((::fastjet::FunctionOfPseudoJet<float>*)p);
   }
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEfloatgR(void *p) {
      typedef ::fastjet::FunctionOfPseudoJet<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::FunctionOfPseudoJet<float>

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLFunctionOfPseudoJetlEintgR(void *p) {
      delete ((::fastjet::FunctionOfPseudoJet<int>*)p);
   }
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEintgR(void *p) {
      delete [] ((::fastjet::FunctionOfPseudoJet<int>*)p);
   }
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEintgR(void *p) {
      typedef ::fastjet::FunctionOfPseudoJet<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::FunctionOfPseudoJet<int>

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLFunctionOfPseudoJetlEboolgR(void *p) {
      delete ((::fastjet::FunctionOfPseudoJet<bool>*)p);
   }
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEboolgR(void *p) {
      delete [] ((::fastjet::FunctionOfPseudoJet<bool>*)p);
   }
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEboolgR(void *p) {
      typedef ::fastjet::FunctionOfPseudoJet<bool> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::FunctionOfPseudoJet<bool>

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR(void *p) {
      delete ((::fastjet::FunctionOfPseudoJet<vector<Double32_t> >*)p);
   }
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR(void *p) {
      delete [] ((::fastjet::FunctionOfPseudoJet<vector<Double32_t> >*)p);
   }
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEvectorlEDouble32_tgRsPgR(void *p) {
      typedef ::fastjet::FunctionOfPseudoJet<vector<Double32_t> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::FunctionOfPseudoJet<vector<Double32_t> >

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR(void *p) {
      delete ((::fastjet::FunctionOfPseudoJet<vector<float> >*)p);
   }
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR(void *p) {
      delete [] ((::fastjet::FunctionOfPseudoJet<vector<float> >*)p);
   }
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEvectorlEfloatgRsPgR(void *p) {
      typedef ::fastjet::FunctionOfPseudoJet<vector<float> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::FunctionOfPseudoJet<vector<float> >

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR(void *p) {
      delete ((::fastjet::FunctionOfPseudoJet<vector<int> >*)p);
   }
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR(void *p) {
      delete [] ((::fastjet::FunctionOfPseudoJet<vector<int> >*)p);
   }
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEvectorlEintgRsPgR(void *p) {
      typedef ::fastjet::FunctionOfPseudoJet<vector<int> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::FunctionOfPseudoJet<vector<int> >

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR(void *p) {
      delete ((::fastjet::FunctionOfPseudoJet<vector<bool> >*)p);
   }
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR(void *p) {
      delete [] ((::fastjet::FunctionOfPseudoJet<vector<bool> >*)p);
   }
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEvectorlEboolgRsPgR(void *p) {
      typedef ::fastjet::FunctionOfPseudoJet<vector<bool> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::FunctionOfPseudoJet<vector<bool> >

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR(void *p) {
      delete ((::fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>*)p);
   }
   static void deleteArray_fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR(void *p) {
      delete [] ((::fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>*)p);
   }
   static void destruct_fastjetcLcLFunctionOfPseudoJetlEfastjetcLcLPseudoJetgR(void *p) {
      typedef ::fastjet::FunctionOfPseudoJet<fastjet::PseudoJet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLTransformer(void *p) {
      delete ((::fastjet::Transformer*)p);
   }
   static void deleteArray_fastjetcLcLTransformer(void *p) {
      delete [] ((::fastjet::Transformer*)p);
   }
   static void destruct_fastjetcLcLTransformer(void *p) {
      typedef ::fastjet::Transformer current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::Transformer

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLBoost(void *p) {
      delete ((::fastjet::Boost*)p);
   }
   static void deleteArray_fastjetcLcLBoost(void *p) {
      delete [] ((::fastjet::Boost*)p);
   }
   static void destruct_fastjetcLcLBoost(void *p) {
      typedef ::fastjet::Boost current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::Boost

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLCASubJetTagger(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::CASubJetTagger : new ::fastjet::CASubJetTagger;
   }
   static void *newArray_fastjetcLcLCASubJetTagger(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::CASubJetTagger[nElements] : new ::fastjet::CASubJetTagger[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLCASubJetTagger(void *p) {
      delete ((::fastjet::CASubJetTagger*)p);
   }
   static void deleteArray_fastjetcLcLCASubJetTagger(void *p) {
      delete [] ((::fastjet::CASubJetTagger*)p);
   }
   static void destruct_fastjetcLcLCASubJetTagger(void *p) {
      typedef ::fastjet::CASubJetTagger current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::CASubJetTagger

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLFilter(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::Filter : new ::fastjet::Filter;
   }
   static void *newArray_fastjetcLcLFilter(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::Filter[nElements] : new ::fastjet::Filter[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLFilter(void *p) {
      delete ((::fastjet::Filter*)p);
   }
   static void deleteArray_fastjetcLcLFilter(void *p) {
      delete [] ((::fastjet::Filter*)p);
   }
   static void destruct_fastjetcLcLFilter(void *p) {
      typedef ::fastjet::Filter current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::Filter

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLGridMedianBackgroundEstimator(void *p) {
      delete ((::fastjet::GridMedianBackgroundEstimator*)p);
   }
   static void deleteArray_fastjetcLcLGridMedianBackgroundEstimator(void *p) {
      delete [] ((::fastjet::GridMedianBackgroundEstimator*)p);
   }
   static void destruct_fastjetcLcLGridMedianBackgroundEstimator(void *p) {
      typedef ::fastjet::GridMedianBackgroundEstimator current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::GridMedianBackgroundEstimator

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLJetMedianBackgroundEstimator(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::JetMedianBackgroundEstimator : new ::fastjet::JetMedianBackgroundEstimator;
   }
   static void *newArray_fastjetcLcLJetMedianBackgroundEstimator(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::JetMedianBackgroundEstimator[nElements] : new ::fastjet::JetMedianBackgroundEstimator[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLJetMedianBackgroundEstimator(void *p) {
      delete ((::fastjet::JetMedianBackgroundEstimator*)p);
   }
   static void deleteArray_fastjetcLcLJetMedianBackgroundEstimator(void *p) {
      delete [] ((::fastjet::JetMedianBackgroundEstimator*)p);
   }
   static void destruct_fastjetcLcLJetMedianBackgroundEstimator(void *p) {
      typedef ::fastjet::JetMedianBackgroundEstimator current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::JetMedianBackgroundEstimator

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLMassDropTagger(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::MassDropTagger : new ::fastjet::MassDropTagger;
   }
   static void *newArray_fastjetcLcLMassDropTagger(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::MassDropTagger[nElements] : new ::fastjet::MassDropTagger[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLMassDropTagger(void *p) {
      delete ((::fastjet::MassDropTagger*)p);
   }
   static void deleteArray_fastjetcLcLMassDropTagger(void *p) {
      delete [] ((::fastjet::MassDropTagger*)p);
   }
   static void destruct_fastjetcLcLMassDropTagger(void *p) {
      typedef ::fastjet::MassDropTagger current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::MassDropTagger

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLRestFrameNSubjettinessTagger(void *p) {
      delete ((::fastjet::RestFrameNSubjettinessTagger*)p);
   }
   static void deleteArray_fastjetcLcLRestFrameNSubjettinessTagger(void *p) {
      delete [] ((::fastjet::RestFrameNSubjettinessTagger*)p);
   }
   static void destruct_fastjetcLcLRestFrameNSubjettinessTagger(void *p) {
      typedef ::fastjet::RestFrameNSubjettinessTagger current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::RestFrameNSubjettinessTagger

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLRestFrameNSubjettinessTaggerStructure(void *p) {
      delete ((::fastjet::RestFrameNSubjettinessTaggerStructure*)p);
   }
   static void deleteArray_fastjetcLcLRestFrameNSubjettinessTaggerStructure(void *p) {
      delete [] ((::fastjet::RestFrameNSubjettinessTaggerStructure*)p);
   }
   static void destruct_fastjetcLcLRestFrameNSubjettinessTaggerStructure(void *p) {
      typedef ::fastjet::RestFrameNSubjettinessTaggerStructure current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::RestFrameNSubjettinessTaggerStructure

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLSubtractor(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::Subtractor : new ::fastjet::Subtractor;
   }
   static void *newArray_fastjetcLcLSubtractor(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::Subtractor[nElements] : new ::fastjet::Subtractor[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLSubtractor(void *p) {
      delete ((::fastjet::Subtractor*)p);
   }
   static void deleteArray_fastjetcLcLSubtractor(void *p) {
      delete [] ((::fastjet::Subtractor*)p);
   }
   static void destruct_fastjetcLcLSubtractor(void *p) {
      typedef ::fastjet::Subtractor current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::Subtractor

namespace ROOT {
   // Wrappers around operator new
   static void *new_fastjetcLcLJHTopTagger(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::JHTopTagger : new ::fastjet::JHTopTagger;
   }
   static void *newArray_fastjetcLcLJHTopTagger(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::fastjet::JHTopTagger[nElements] : new ::fastjet::JHTopTagger[nElements];
   }
   // Wrapper around operator delete
   static void delete_fastjetcLcLJHTopTagger(void *p) {
      delete ((::fastjet::JHTopTagger*)p);
   }
   static void deleteArray_fastjetcLcLJHTopTagger(void *p) {
      delete [] ((::fastjet::JHTopTagger*)p);
   }
   static void destruct_fastjetcLcLJHTopTagger(void *p) {
      typedef ::fastjet::JHTopTagger current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::JHTopTagger

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLJHTopTaggerStructure(void *p) {
      delete ((::fastjet::JHTopTaggerStructure*)p);
   }
   static void deleteArray_fastjetcLcLJHTopTaggerStructure(void *p) {
      delete [] ((::fastjet::JHTopTaggerStructure*)p);
   }
   static void destruct_fastjetcLcLJHTopTaggerStructure(void *p) {
      typedef ::fastjet::JHTopTaggerStructure current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::JHTopTaggerStructure

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLUnboost(void *p) {
      delete ((::fastjet::Unboost*)p);
   }
   static void deleteArray_fastjetcLcLUnboost(void *p) {
      delete [] ((::fastjet::Unboost*)p);
   }
   static void destruct_fastjetcLcLUnboost(void *p) {
      typedef ::fastjet::Unboost current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::Unboost

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLPruner(void *p) {
      delete ((::fastjet::Pruner*)p);
   }
   static void deleteArray_fastjetcLcLPruner(void *p) {
      delete [] ((::fastjet::Pruner*)p);
   }
   static void destruct_fastjetcLcLPruner(void *p) {
      typedef ::fastjet::Pruner current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::Pruner

namespace ROOT {
   // Wrapper around operator delete
   static void delete_fastjetcLcLPrunerStructure(void *p) {
      delete ((::fastjet::PrunerStructure*)p);
   }
   static void deleteArray_fastjetcLcLPrunerStructure(void *p) {
      delete [] ((::fastjet::PrunerStructure*)p);
   }
   static void destruct_fastjetcLcLPrunerStructure(void *p) {
      typedef ::fastjet::PrunerStructure current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::fastjet::PrunerStructure

namespace ROOT {
   static TClass *vectorlEfastjetcLcLPseudoJetgR_Dictionary();
   static void vectorlEfastjetcLcLPseudoJetgR_TClassManip(TClass*);
   static void *new_vectorlEfastjetcLcLPseudoJetgR(void *p = 0);
   static void *newArray_vectorlEfastjetcLcLPseudoJetgR(Long_t size, void *p);
   static void delete_vectorlEfastjetcLcLPseudoJetgR(void *p);
   static void deleteArray_vectorlEfastjetcLcLPseudoJetgR(void *p);
   static void destruct_vectorlEfastjetcLcLPseudoJetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<fastjet::PseudoJet>*)
   {
      vector<fastjet::PseudoJet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<fastjet::PseudoJet>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<fastjet::PseudoJet>", -2, "vector", 481,
                  typeid(vector<fastjet::PseudoJet>), DefineBehavior(ptr, ptr),
                  &vectorlEfastjetcLcLPseudoJetgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<fastjet::PseudoJet>) );
      instance.SetNew(&new_vectorlEfastjetcLcLPseudoJetgR);
      instance.SetNewArray(&newArray_vectorlEfastjetcLcLPseudoJetgR);
      instance.SetDelete(&delete_vectorlEfastjetcLcLPseudoJetgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfastjetcLcLPseudoJetgR);
      instance.SetDestructor(&destruct_vectorlEfastjetcLcLPseudoJetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<fastjet::PseudoJet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<fastjet::PseudoJet>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfastjetcLcLPseudoJetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<fastjet::PseudoJet>*)0x0)->GetClass();
      vectorlEfastjetcLcLPseudoJetgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfastjetcLcLPseudoJetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfastjetcLcLPseudoJetgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<fastjet::PseudoJet> : new vector<fastjet::PseudoJet>;
   }
   static void *newArray_vectorlEfastjetcLcLPseudoJetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<fastjet::PseudoJet>[nElements] : new vector<fastjet::PseudoJet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfastjetcLcLPseudoJetgR(void *p) {
      delete ((vector<fastjet::PseudoJet>*)p);
   }
   static void deleteArray_vectorlEfastjetcLcLPseudoJetgR(void *p) {
      delete [] ((vector<fastjet::PseudoJet>*)p);
   }
   static void destruct_vectorlEfastjetcLcLPseudoJetgR(void *p) {
      typedef vector<fastjet::PseudoJet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<fastjet::PseudoJet>

namespace {
  void TriggerDictionaryInitialization_ExternalDict_Impl() {
    static const char* headers[] = {
"tmp_include/fastjet/PseudoJet.hh",
"FJWrapper.hh",
"/usr/local/include/fastjet/internal/BasicRandom.hh",
"/usr/local/include/fastjet/AreaDefinition.hh",
"/usr/local/include/fastjet/CDFJetCluPlugin.hh",
"/usr/local/include/fastjet/CDFMidPointPlugin.hh",
"/usr/local/include/fastjet/ClusterSequence.hh",
"/usr/local/include/fastjet/ClusterSequence1GhostPassiveArea.hh",
"/usr/local/include/fastjet/ClusterSequenceActiveArea.hh",
"/usr/local/include/fastjet/ClusterSequenceActiveAreaExplicitGhosts.hh",
"/usr/local/include/fastjet/ClusterSequenceArea.hh",
"/usr/local/include/fastjet/ClusterSequenceAreaBase.hh",
"/usr/local/include/fastjet/ClusterSequencePassiveArea.hh",
"/usr/local/include/fastjet/ClusterSequenceStructure.hh",
"/usr/local/include/fastjet/ClusterSequenceVoronoiArea.hh",
"/usr/local/include/fastjet/CompositeJetStructure.hh",
"/usr/local/include/fastjet/EECambridgePlugin.hh",
"/usr/local/include/fastjet/Error.hh",
"/usr/local/include/fastjet/FunctionOfPseudoJet.hh",
"/usr/local/include/fastjet/GhostedAreaSpec.hh",
"/usr/local/include/fastjet/GridJetPlugin.hh",
"/usr/local/include/fastjet/JadePlugin.hh",
"/usr/local/include/fastjet/JetDefinition.hh",
"/usr/local/include/fastjet/LimitedWarning.hh",
"/usr/local/include/fastjet/NNH.hh",
"/usr/local/include/fastjet/NestedDefsPlugin.hh",
"/usr/local/include/fastjet/PseudoJetStructureBase.hh",
"/usr/local/include/fastjet/SISConeBasePlugin.hh",
"/usr/local/include/fastjet/SISConePlugin.hh",
"/usr/local/include/fastjet/SISConeSphericalPlugin.hh",
"/usr/local/include/fastjet/Selector.hh",
"/usr/local/include/fastjet/SharedPtr.hh",
"/usr/local/include/fastjet/WrappedStructure.hh",
"/usr/local/include/fastjet/version.hh",
"/usr/local/include/fastjet/tools/BackgroundEstimatorBase.hh",
"/usr/local/include/fastjet/tools/Boost.hh",
"/usr/local/include/fastjet/tools/CASubJetTagger.hh",
"/usr/local/include/fastjet/tools/Filter.hh",
"/usr/local/include/fastjet/tools/GridMedianBackgroundEstimator.hh",
"/usr/local/include/fastjet/tools/JHTopTagger.hh",
"/usr/local/include/fastjet/tools/JetMedianBackgroundEstimator.hh",
"/usr/local/include/fastjet/tools/MassDropTagger.hh",
"/usr/local/include/fastjet/tools/Pruner.hh",
"/usr/local/include/fastjet/tools/RestFrameNSubjettinessTagger.hh",
"/usr/local/include/fastjet/tools/Subtractor.hh",
"/usr/local/include/fastjet/tools/TopTaggerBase.hh",
"/usr/local/include/fastjet/tools/Transformer.hh",
"/usr/local/include/fastjet/CDFJetCluPlugin.hh",
"/usr/local/include/fastjet/CDFMidPointPlugin.hh",
"/usr/local/include/fastjet/EECambridgePlugin.hh",
"/usr/local/include/fastjet/GridJetPlugin.hh",
"/usr/local/include/fastjet/JadePlugin.hh",
"/usr/local/include/fastjet/NestedDefsPlugin.hh",
"/usr/local/include/fastjet/SISConeBasePlugin.hh",
"/usr/local/include/fastjet/SISConePlugin.hh",
"/usr/local/include/fastjet/SISConeSphericalPlugin.hh",
0
    };
    static const char* includePaths[] = {
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2",
"/usr/local/include",
"wtag-1.00/include",
"/Users/hrussell/Applications/root/include",
"/Users/hrussell/Work/SSI2016/spartyjet-4.0.2/External/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace fastjet{class __attribute__((annotate("$clingAutoload$FJWrapper.hh")))  JetDefinition;}
namespace fastjet{template <typename _Tp> class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/internal/BasicRandom.hh")))  BasicRandom;
}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/AreaDefinition.hh")))  AreaDefinition;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$tmp_include/fastjet/PseudoJet.hh")))  PseudoJet;}
namespace std{inline namespace __1{template <class _Tp> class __attribute__((annotate("$clingAutoload$string")))  allocator;
}}
namespace fastjet{class __attribute__((annotate("$clingAutoload$FJWrapper.hh")))  ClusterSequence;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$FJWrapper.hh")))  Selector;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$tmp_include/fastjet/PseudoJet.hh")))  PseudoJetStructureBase;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/WrappedStructure.hh")))  WrappedStructure;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/JHTopTagger.hh")))  TopTaggerBase;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/JHTopTagger.hh")))  TopTaggerBaseStructure;}
namespace fastjet{template <typename TOut> class __attribute__((annotate("$clingAutoload$FJWrapper.hh")))  FunctionOfPseudoJet;
}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/CASubJetTagger.hh")))  Transformer;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/Boost.hh")))  Boost;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/CASubJetTagger.hh")))  CASubJetTagger;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/Filter.hh")))  Filter;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/GridMedianBackgroundEstimator.hh")))  GridMedianBackgroundEstimator;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/JetMedianBackgroundEstimator.hh")))  JetMedianBackgroundEstimator;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/MassDropTagger.hh")))  MassDropTagger;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/RestFrameNSubjettinessTagger.hh")))  RestFrameNSubjettinessTagger;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/RestFrameNSubjettinessTagger.hh")))  RestFrameNSubjettinessTaggerStructure;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/Subtractor.hh")))  Subtractor;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/JHTopTagger.hh")))  JHTopTagger;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/JHTopTagger.hh")))  JHTopTaggerStructure;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/Boost.hh")))  Unboost;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/Pruner.hh")))  Pruner;}
namespace fastjet{class __attribute__((annotate("$clingAutoload$/usr/local/include/fastjet/tools/Pruner.hh")))  PrunerStructure;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "tmp_include/fastjet/PseudoJet.hh"
#include "FJWrapper.hh"
#include "/usr/local/include/fastjet/internal/BasicRandom.hh"
#include "/usr/local/include/fastjet/AreaDefinition.hh"
#include "/usr/local/include/fastjet/CDFJetCluPlugin.hh"
#include "/usr/local/include/fastjet/CDFMidPointPlugin.hh"
#include "/usr/local/include/fastjet/ClusterSequence.hh"
#include "/usr/local/include/fastjet/ClusterSequence1GhostPassiveArea.hh"
#include "/usr/local/include/fastjet/ClusterSequenceActiveArea.hh"
#include "/usr/local/include/fastjet/ClusterSequenceActiveAreaExplicitGhosts.hh"
#include "/usr/local/include/fastjet/ClusterSequenceArea.hh"
#include "/usr/local/include/fastjet/ClusterSequenceAreaBase.hh"
#include "/usr/local/include/fastjet/ClusterSequencePassiveArea.hh"
#include "/usr/local/include/fastjet/ClusterSequenceStructure.hh"
#include "/usr/local/include/fastjet/ClusterSequenceVoronoiArea.hh"
#include "/usr/local/include/fastjet/CompositeJetStructure.hh"
#include "/usr/local/include/fastjet/EECambridgePlugin.hh"
#include "/usr/local/include/fastjet/Error.hh"
#include "/usr/local/include/fastjet/FunctionOfPseudoJet.hh"
#include "/usr/local/include/fastjet/GhostedAreaSpec.hh"
#include "/usr/local/include/fastjet/GridJetPlugin.hh"
#include "/usr/local/include/fastjet/JadePlugin.hh"
#include "/usr/local/include/fastjet/JetDefinition.hh"
#include "/usr/local/include/fastjet/LimitedWarning.hh"
#include "/usr/local/include/fastjet/NNH.hh"
#include "/usr/local/include/fastjet/NestedDefsPlugin.hh"
#include "/usr/local/include/fastjet/PseudoJetStructureBase.hh"
#include "/usr/local/include/fastjet/SISConeBasePlugin.hh"
#include "/usr/local/include/fastjet/SISConePlugin.hh"
#include "/usr/local/include/fastjet/SISConeSphericalPlugin.hh"
#include "/usr/local/include/fastjet/Selector.hh"
#include "/usr/local/include/fastjet/SharedPtr.hh"
#include "/usr/local/include/fastjet/WrappedStructure.hh"
#include "/usr/local/include/fastjet/version.hh"
#include "/usr/local/include/fastjet/tools/BackgroundEstimatorBase.hh"
#include "/usr/local/include/fastjet/tools/Boost.hh"
#include "/usr/local/include/fastjet/tools/CASubJetTagger.hh"
#include "/usr/local/include/fastjet/tools/Filter.hh"
#include "/usr/local/include/fastjet/tools/GridMedianBackgroundEstimator.hh"
#include "/usr/local/include/fastjet/tools/JHTopTagger.hh"
#include "/usr/local/include/fastjet/tools/JetMedianBackgroundEstimator.hh"
#include "/usr/local/include/fastjet/tools/MassDropTagger.hh"
#include "/usr/local/include/fastjet/tools/Pruner.hh"
#include "/usr/local/include/fastjet/tools/RestFrameNSubjettinessTagger.hh"
#include "/usr/local/include/fastjet/tools/Subtractor.hh"
#include "/usr/local/include/fastjet/tools/TopTaggerBase.hh"
#include "/usr/local/include/fastjet/tools/Transformer.hh"
#include "/usr/local/include/fastjet/CDFJetCluPlugin.hh"
#include "/usr/local/include/fastjet/CDFMidPointPlugin.hh"
#include "/usr/local/include/fastjet/EECambridgePlugin.hh"
#include "/usr/local/include/fastjet/GridJetPlugin.hh"
#include "/usr/local/include/fastjet/JadePlugin.hh"
#include "/usr/local/include/fastjet/NestedDefsPlugin.hh"
#include "/usr/local/include/fastjet/SISConeBasePlugin.hh"
#include "/usr/local/include/fastjet/SISConePlugin.hh"
#include "/usr/local/include/fastjet/SISConeSphericalPlugin.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"fastjet::AreaDefinition", payloadCode, "@",
"fastjet::BasicRandom<double>", payloadCode, "@",
"fastjet::BasicRandom<int>", payloadCode, "@",
"fastjet::Boost", payloadCode, "@",
"fastjet::CASubJetTagger", payloadCode, "@",
"fastjet::ClusterSequence", payloadCode, "@",
"fastjet::Filter", payloadCode, "@",
"fastjet::FunctionOfPseudoJet<Double32_t>", payloadCode, "@",
"fastjet::FunctionOfPseudoJet<bool>", payloadCode, "@",
"fastjet::FunctionOfPseudoJet<fastjet::PseudoJet>", payloadCode, "@",
"fastjet::FunctionOfPseudoJet<float>", payloadCode, "@",
"fastjet::FunctionOfPseudoJet<int>", payloadCode, "@",
"fastjet::FunctionOfPseudoJet<std::vector<Double32_t> >", payloadCode, "@",
"fastjet::FunctionOfPseudoJet<std::vector<bool> >", payloadCode, "@",
"fastjet::FunctionOfPseudoJet<std::vector<float> >", payloadCode, "@",
"fastjet::FunctionOfPseudoJet<std::vector<int> >", payloadCode, "@",
"fastjet::FunctionOfPseudoJet<vector<Double32_t> >", payloadCode, "@",
"fastjet::FunctionOfPseudoJet<vector<bool> >", payloadCode, "@",
"fastjet::FunctionOfPseudoJet<vector<float> >", payloadCode, "@",
"fastjet::FunctionOfPseudoJet<vector<int> >", payloadCode, "@",
"fastjet::GridMedianBackgroundEstimator", payloadCode, "@",
"fastjet::JHTopTagger", payloadCode, "@",
"fastjet::JHTopTaggerStructure", payloadCode, "@",
"fastjet::JetDefinition", payloadCode, "@",
"fastjet::JetDefinition::Plugin", payloadCode, "@",
"fastjet::JetMedianBackgroundEstimator", payloadCode, "@",
"fastjet::MassDropTagger", payloadCode, "@",
"fastjet::Pruner", payloadCode, "@",
"fastjet::PrunerStructure", payloadCode, "@",
"fastjet::PseudoJet", payloadCode, "@",
"fastjet::PseudoJetStructureBase", payloadCode, "@",
"fastjet::RestFrameNSubjettinessTagger", payloadCode, "@",
"fastjet::RestFrameNSubjettinessTaggerStructure", payloadCode, "@",
"fastjet::Selector", payloadCode, "@",
"fastjet::Subtractor", payloadCode, "@",
"fastjet::TopTaggerBase", payloadCode, "@",
"fastjet::TopTaggerBaseStructure", payloadCode, "@",
"fastjet::Transformer", payloadCode, "@",
"fastjet::Unboost", payloadCode, "@",
"fastjet::WrappedStructure", payloadCode, "@",
"vector<fastjet::PseudoJet>", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ExternalDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ExternalDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ExternalDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ExternalDict() {
  TriggerDictionaryInitialization_ExternalDict_Impl();
}
