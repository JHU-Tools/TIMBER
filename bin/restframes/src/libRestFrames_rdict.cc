// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME libRestFrames_rdict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
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

// Header files passed as explicit arguments
#include "../include/RFKey.hh"
#include "../include/RFCharge.hh"
#include "../include/RFPlot.hh"
#include "../include/RFBase.hh"
#include "../include/RFLog.hh"
#include "../include/RestFrame.hh"
#include "../include/ReconstructionFrame.hh"
#include "../include/GeneratorFrame.hh"
#include "../include/LabFrame.hh"
#include "../include/DecayFrame.hh"
#include "../include/VisibleFrame.hh"
#include "../include/InvisibleFrame.hh"
#include "../include/LabRecoFrame.hh"
#include "../include/DecayRecoFrame.hh"
#include "../include/VisibleRecoFrame.hh"
#include "../include/InvisibleRecoFrame.hh"
#include "../include/SelfAssemblingRecoFrame.hh"
#include "../include/LabGenFrame.hh"
#include "../include/DecayGenFrame.hh"
#include "../include/VisibleGenFrame.hh"
#include "../include/InvisibleGenFrame.hh"
#include "../include/ResonanceGenFrame.hh"
#include "../include/ppLabGenFrame.hh"
#include "../include/State.hh"
#include "../include/VisibleState.hh"
#include "../include/InvisibleState.hh"
#include "../include/CombinatoricState.hh"
#include "../include/Group.hh"
#include "../include/InvisibleGroup.hh"
#include "../include/CombinatoricGroup.hh"
#include "../include/Jigsaw.hh"
#include "../include/InvisibleJigsaw.hh"
#include "../include/CombinatoricJigsaw.hh"
#include "../include/SetMassInvJigsaw.hh"
#include "../include/SetRapidityInvJigsaw.hh"
#include "../include/ContraBoostInvJigsaw.hh"
#include "../include/CombinedCBInvJigsaw.hh"
#include "../include/MinMassDiffInvJigsaw.hh"
#include "../include/MinMassesSqInvJigsaw.hh"
#include "../include/MaxProbBreitWignerInvJigsaw.hh"
#include "../include/MinMassesCombJigsaw.hh"
#include "../include/MinMassChi2CombJigsaw.hh"
#include "../include/MaxProbBreitWignerCombJigsaw.hh"
#include "../include/MinMassDiffCombJigsaw.hh"
#include "../include/MinMassesSqCombJigsaw.hh"
#include "../include/TreePlot.hh"
#include "../include/TreePlotNode.hh"
#include "../include/TreePlotLink.hh"
#include "../include/HistPlotVar.hh"
#include "../include/HistPlotCategory.hh"
#include "../include/HistPlot.hh"
#include "../include/RFList.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace RestFrames {
   namespace ROOTDict {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *RestFrames_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("RestFrames", 0 /*version*/, "../include/RFKey.hh", 33,
                     ::ROOT::Internal::DefineBehavior((void*)0,(void*)0),
                     &RestFrames_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_DICT_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_DICT_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *RestFrames_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace ROOT {
   static TClass *RestFramescLcLRFKey_Dictionary();
   static void RestFramescLcLRFKey_TClassManip(TClass*);
   static void delete_RestFramescLcLRFKey(void *p);
   static void deleteArray_RestFramescLcLRFKey(void *p);
   static void destruct_RestFramescLcLRFKey(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RFKey*)
   {
      ::RestFrames::RFKey *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RFKey));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RFKey", "../include/RFKey.hh", 38,
                  typeid(::RestFrames::RFKey), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRFKey_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RFKey) );
      instance.SetDelete(&delete_RestFramescLcLRFKey);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRFKey);
      instance.SetDestructor(&destruct_RestFramescLcLRFKey);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RFKey*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RFKey*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RFKey*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRFKey_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RFKey*)0x0)->GetClass();
      RestFramescLcLRFKey_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRFKey_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLRFCharge_Dictionary();
   static void RestFramescLcLRFCharge_TClassManip(TClass*);
   static void *new_RestFramescLcLRFCharge(void *p = 0);
   static void *newArray_RestFramescLcLRFCharge(Long_t size, void *p);
   static void delete_RestFramescLcLRFCharge(void *p);
   static void deleteArray_RestFramescLcLRFCharge(void *p);
   static void destruct_RestFramescLcLRFCharge(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RFCharge*)
   {
      ::RestFrames::RFCharge *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RFCharge));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RFCharge", "../include/RFCharge.hh", 40,
                  typeid(::RestFrames::RFCharge), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRFCharge_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RFCharge) );
      instance.SetNew(&new_RestFramescLcLRFCharge);
      instance.SetNewArray(&newArray_RestFramescLcLRFCharge);
      instance.SetDelete(&delete_RestFramescLcLRFCharge);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRFCharge);
      instance.SetDestructor(&destruct_RestFramescLcLRFCharge);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RFCharge*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RFCharge*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RFCharge*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRFCharge_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RFCharge*)0x0)->GetClass();
      RestFramescLcLRFCharge_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRFCharge_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR_Dictionary();
   static void RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR_TClassManip(TClass*);
   static void *new_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR(void *p = 0);
   static void *newArray_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR(Long_t size, void *p);
   static void delete_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR(void *p);
   static void deleteArray_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR(void *p);
   static void destruct_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RFList<const RestFrames::RestFrame>*)
   {
      ::RestFrames::RFList<const RestFrames::RestFrame> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RFList<const RestFrames::RestFrame>));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RFList<const RestFrames::RestFrame>", "../include/RFList.hh", 209,
                  typeid(::RestFrames::RFList<const RestFrames::RestFrame>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RFList<const RestFrames::RestFrame>) );
      instance.SetNew(&new_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR);
      instance.SetNewArray(&newArray_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR);
      instance.SetDelete(&delete_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR);
      instance.SetDestructor(&destruct_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR);

      ::ROOT::AddClassAlternate("RestFrames::RFList<const RestFrames::RestFrame>","RestFrames::RFList<RestFrames::RestFrame const>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RFList<const RestFrames::RestFrame>*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RFList<const RestFrames::RestFrame>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RFList<const RestFrames::RestFrame>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RFList<const RestFrames::RestFrame>*)0x0)->GetClass();
      RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLRFListlERestFramescLcLGroupgR_Dictionary();
   static void RestFramescLcLRFListlERestFramescLcLGroupgR_TClassManip(TClass*);
   static void *new_RestFramescLcLRFListlERestFramescLcLGroupgR(void *p = 0);
   static void *newArray_RestFramescLcLRFListlERestFramescLcLGroupgR(Long_t size, void *p);
   static void delete_RestFramescLcLRFListlERestFramescLcLGroupgR(void *p);
   static void deleteArray_RestFramescLcLRFListlERestFramescLcLGroupgR(void *p);
   static void destruct_RestFramescLcLRFListlERestFramescLcLGroupgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RFList<RestFrames::Group>*)
   {
      ::RestFrames::RFList<RestFrames::Group> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RFList<RestFrames::Group>));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RFList<RestFrames::Group>", "../include/RFList.hh", 209,
                  typeid(::RestFrames::RFList<RestFrames::Group>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRFListlERestFramescLcLGroupgR_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RFList<RestFrames::Group>) );
      instance.SetNew(&new_RestFramescLcLRFListlERestFramescLcLGroupgR);
      instance.SetNewArray(&newArray_RestFramescLcLRFListlERestFramescLcLGroupgR);
      instance.SetDelete(&delete_RestFramescLcLRFListlERestFramescLcLGroupgR);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRFListlERestFramescLcLGroupgR);
      instance.SetDestructor(&destruct_RestFramescLcLRFListlERestFramescLcLGroupgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RFList<RestFrames::Group>*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RFList<RestFrames::Group>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RFList<RestFrames::Group>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRFListlERestFramescLcLGroupgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RFList<RestFrames::Group>*)0x0)->GetClass();
      RestFramescLcLRFListlERestFramescLcLGroupgR_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRFListlERestFramescLcLGroupgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR_Dictionary();
   static void RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR_TClassManip(TClass*);
   static void *new_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR(void *p = 0);
   static void *newArray_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR(Long_t size, void *p);
   static void delete_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR(void *p);
   static void deleteArray_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR(void *p);
   static void destruct_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RFList<const RestFrames::Group>*)
   {
      ::RestFrames::RFList<const RestFrames::Group> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RFList<const RestFrames::Group>));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RFList<const RestFrames::Group>", "../include/RFList.hh", 209,
                  typeid(::RestFrames::RFList<const RestFrames::Group>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RFList<const RestFrames::Group>) );
      instance.SetNew(&new_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR);
      instance.SetNewArray(&newArray_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR);
      instance.SetDelete(&delete_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR);
      instance.SetDestructor(&destruct_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR);

      ::ROOT::AddClassAlternate("RestFrames::RFList<const RestFrames::Group>","RestFrames::RFList<RestFrames::Group const>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RFList<const RestFrames::Group>*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RFList<const RestFrames::Group>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RFList<const RestFrames::Group>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RFList<const RestFrames::Group>*)0x0)->GetClass();
      RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLRFListlERestFramescLcLJigsawgR_Dictionary();
   static void RestFramescLcLRFListlERestFramescLcLJigsawgR_TClassManip(TClass*);
   static void *new_RestFramescLcLRFListlERestFramescLcLJigsawgR(void *p = 0);
   static void *newArray_RestFramescLcLRFListlERestFramescLcLJigsawgR(Long_t size, void *p);
   static void delete_RestFramescLcLRFListlERestFramescLcLJigsawgR(void *p);
   static void deleteArray_RestFramescLcLRFListlERestFramescLcLJigsawgR(void *p);
   static void destruct_RestFramescLcLRFListlERestFramescLcLJigsawgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RFList<RestFrames::Jigsaw>*)
   {
      ::RestFrames::RFList<RestFrames::Jigsaw> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RFList<RestFrames::Jigsaw>));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RFList<RestFrames::Jigsaw>", "../include/RFList.hh", 209,
                  typeid(::RestFrames::RFList<RestFrames::Jigsaw>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRFListlERestFramescLcLJigsawgR_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RFList<RestFrames::Jigsaw>) );
      instance.SetNew(&new_RestFramescLcLRFListlERestFramescLcLJigsawgR);
      instance.SetNewArray(&newArray_RestFramescLcLRFListlERestFramescLcLJigsawgR);
      instance.SetDelete(&delete_RestFramescLcLRFListlERestFramescLcLJigsawgR);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRFListlERestFramescLcLJigsawgR);
      instance.SetDestructor(&destruct_RestFramescLcLRFListlERestFramescLcLJigsawgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RFList<RestFrames::Jigsaw>*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RFList<RestFrames::Jigsaw>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RFList<RestFrames::Jigsaw>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRFListlERestFramescLcLJigsawgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RFList<RestFrames::Jigsaw>*)0x0)->GetClass();
      RestFramescLcLRFListlERestFramescLcLJigsawgR_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRFListlERestFramescLcLJigsawgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR_Dictionary();
   static void RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR_TClassManip(TClass*);
   static void *new_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR(void *p = 0);
   static void *newArray_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR(Long_t size, void *p);
   static void delete_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR(void *p);
   static void deleteArray_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR(void *p);
   static void destruct_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RFList<const RestFrames::Jigsaw>*)
   {
      ::RestFrames::RFList<const RestFrames::Jigsaw> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RFList<const RestFrames::Jigsaw>));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RFList<const RestFrames::Jigsaw>", "../include/RFList.hh", 209,
                  typeid(::RestFrames::RFList<const RestFrames::Jigsaw>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RFList<const RestFrames::Jigsaw>) );
      instance.SetNew(&new_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR);
      instance.SetNewArray(&newArray_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR);
      instance.SetDelete(&delete_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR);
      instance.SetDestructor(&destruct_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR);

      ::ROOT::AddClassAlternate("RestFrames::RFList<const RestFrames::Jigsaw>","RestFrames::RFList<RestFrames::Jigsaw const>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RFList<const RestFrames::Jigsaw>*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RFList<const RestFrames::Jigsaw>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RFList<const RestFrames::Jigsaw>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RFList<const RestFrames::Jigsaw>*)0x0)->GetClass();
      RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLRFListlERestFramescLcLHistPlotVargR_Dictionary();
   static void RestFramescLcLRFListlERestFramescLcLHistPlotVargR_TClassManip(TClass*);
   static void *new_RestFramescLcLRFListlERestFramescLcLHistPlotVargR(void *p = 0);
   static void *newArray_RestFramescLcLRFListlERestFramescLcLHistPlotVargR(Long_t size, void *p);
   static void delete_RestFramescLcLRFListlERestFramescLcLHistPlotVargR(void *p);
   static void deleteArray_RestFramescLcLRFListlERestFramescLcLHistPlotVargR(void *p);
   static void destruct_RestFramescLcLRFListlERestFramescLcLHistPlotVargR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RFList<RestFrames::HistPlotVar>*)
   {
      ::RestFrames::RFList<RestFrames::HistPlotVar> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RFList<RestFrames::HistPlotVar>));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RFList<RestFrames::HistPlotVar>", "../include/RFList.hh", 209,
                  typeid(::RestFrames::RFList<RestFrames::HistPlotVar>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRFListlERestFramescLcLHistPlotVargR_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RFList<RestFrames::HistPlotVar>) );
      instance.SetNew(&new_RestFramescLcLRFListlERestFramescLcLHistPlotVargR);
      instance.SetNewArray(&newArray_RestFramescLcLRFListlERestFramescLcLHistPlotVargR);
      instance.SetDelete(&delete_RestFramescLcLRFListlERestFramescLcLHistPlotVargR);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRFListlERestFramescLcLHistPlotVargR);
      instance.SetDestructor(&destruct_RestFramescLcLRFListlERestFramescLcLHistPlotVargR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RFList<RestFrames::HistPlotVar>*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RFList<RestFrames::HistPlotVar>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RFList<RestFrames::HistPlotVar>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRFListlERestFramescLcLHistPlotVargR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RFList<RestFrames::HistPlotVar>*)0x0)->GetClass();
      RestFramescLcLRFListlERestFramescLcLHistPlotVargR_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRFListlERestFramescLcLHistPlotVargR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR_Dictionary();
   static void RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR_TClassManip(TClass*);
   static void *new_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR(void *p = 0);
   static void *newArray_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR(Long_t size, void *p);
   static void delete_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR(void *p);
   static void deleteArray_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR(void *p);
   static void destruct_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RFList<RestFrames::HistPlotCategory>*)
   {
      ::RestFrames::RFList<RestFrames::HistPlotCategory> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RFList<RestFrames::HistPlotCategory>));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RFList<RestFrames::HistPlotCategory>", "../include/RFList.hh", 209,
                  typeid(::RestFrames::RFList<RestFrames::HistPlotCategory>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RFList<RestFrames::HistPlotCategory>) );
      instance.SetNew(&new_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR);
      instance.SetNewArray(&newArray_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR);
      instance.SetDelete(&delete_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR);
      instance.SetDestructor(&destruct_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RFList<RestFrames::HistPlotCategory>*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RFList<RestFrames::HistPlotCategory>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RFList<RestFrames::HistPlotCategory>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RFList<RestFrames::HistPlotCategory>*)0x0)->GetClass();
      RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR_Dictionary();
   static void RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR_TClassManip(TClass*);
   static void *new_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR(void *p = 0);
   static void *newArray_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR(Long_t size, void *p);
   static void delete_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR(void *p);
   static void deleteArray_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR(void *p);
   static void destruct_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RFList<const RestFrames::HistPlotCategory>*)
   {
      ::RestFrames::RFList<const RestFrames::HistPlotCategory> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RFList<const RestFrames::HistPlotCategory>));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RFList<const RestFrames::HistPlotCategory>", "../include/RFList.hh", 209,
                  typeid(::RestFrames::RFList<const RestFrames::HistPlotCategory>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RFList<const RestFrames::HistPlotCategory>) );
      instance.SetNew(&new_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR);
      instance.SetNewArray(&newArray_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR);
      instance.SetDelete(&delete_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR);
      instance.SetDestructor(&destruct_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR);

      ::ROOT::AddClassAlternate("RestFrames::RFList<const RestFrames::HistPlotCategory>","RestFrames::RFList<RestFrames::HistPlotCategory const>");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RFList<const RestFrames::HistPlotCategory>*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RFList<const RestFrames::HistPlotCategory>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RFList<const RestFrames::HistPlotCategory>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RFList<const RestFrames::HistPlotCategory>*)0x0)->GetClass();
      RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLRFListlERestFramescLcLRestFramegR_Dictionary();
   static void RestFramescLcLRFListlERestFramescLcLRestFramegR_TClassManip(TClass*);
   static void *new_RestFramescLcLRFListlERestFramescLcLRestFramegR(void *p = 0);
   static void *newArray_RestFramescLcLRFListlERestFramescLcLRestFramegR(Long_t size, void *p);
   static void delete_RestFramescLcLRFListlERestFramescLcLRestFramegR(void *p);
   static void deleteArray_RestFramescLcLRFListlERestFramescLcLRestFramegR(void *p);
   static void destruct_RestFramescLcLRFListlERestFramescLcLRestFramegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RFList<RestFrames::RestFrame>*)
   {
      ::RestFrames::RFList<RestFrames::RestFrame> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RFList<RestFrames::RestFrame>));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RFList<RestFrames::RestFrame>", "../include/RFList.hh", 241,
                  typeid(::RestFrames::RFList<RestFrames::RestFrame>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRFListlERestFramescLcLRestFramegR_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RFList<RestFrames::RestFrame>) );
      instance.SetNew(&new_RestFramescLcLRFListlERestFramescLcLRestFramegR);
      instance.SetNewArray(&newArray_RestFramescLcLRFListlERestFramescLcLRestFramegR);
      instance.SetDelete(&delete_RestFramescLcLRFListlERestFramescLcLRestFramegR);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRFListlERestFramescLcLRestFramegR);
      instance.SetDestructor(&destruct_RestFramescLcLRFListlERestFramescLcLRestFramegR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RFList<RestFrames::RestFrame>*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RFList<RestFrames::RestFrame>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RFList<RestFrames::RestFrame>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRFListlERestFramescLcLRestFramegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RFList<RestFrames::RestFrame>*)0x0)->GetClass();
      RestFramescLcLRFListlERestFramescLcLRestFramegR_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRFListlERestFramescLcLRestFramegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLRFLog_Dictionary();
   static void RestFramescLcLRFLog_TClassManip(TClass*);
   static void *new_RestFramescLcLRFLog(void *p = 0);
   static void *newArray_RestFramescLcLRFLog(Long_t size, void *p);
   static void delete_RestFramescLcLRFLog(void *p);
   static void deleteArray_RestFramescLcLRFLog(void *p);
   static void destruct_RestFramescLcLRFLog(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RFLog*)
   {
      ::RestFrames::RFLog *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RFLog));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RFLog", "../include/RFLog.hh", 51,
                  typeid(::RestFrames::RFLog), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRFLog_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RFLog) );
      instance.SetNew(&new_RestFramescLcLRFLog);
      instance.SetNewArray(&newArray_RestFramescLcLRFLog);
      instance.SetDelete(&delete_RestFramescLcLRFLog);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRFLog);
      instance.SetDestructor(&destruct_RestFramescLcLRFLog);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RFLog*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RFLog*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RFLog*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRFLog_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RFLog*)0x0)->GetClass();
      RestFramescLcLRFLog_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRFLog_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLRFBase_Dictionary();
   static void RestFramescLcLRFBase_TClassManip(TClass*);
   static void *new_RestFramescLcLRFBase(void *p = 0);
   static void *newArray_RestFramescLcLRFBase(Long_t size, void *p);
   static void delete_RestFramescLcLRFBase(void *p);
   static void deleteArray_RestFramescLcLRFBase(void *p);
   static void destruct_RestFramescLcLRFBase(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RFBase*)
   {
      ::RestFrames::RFBase *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RFBase));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RFBase", "../include/RFBase.hh", 53,
                  typeid(::RestFrames::RFBase), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRFBase_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RFBase) );
      instance.SetNew(&new_RestFramescLcLRFBase);
      instance.SetNewArray(&newArray_RestFramescLcLRFBase);
      instance.SetDelete(&delete_RestFramescLcLRFBase);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRFBase);
      instance.SetDestructor(&destruct_RestFramescLcLRFBase);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RFBase*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RFBase*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RFBase*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRFBase_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RFBase*)0x0)->GetClass();
      RestFramescLcLRFBase_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRFBase_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLRFPlot_Dictionary();
   static void RestFramescLcLRFPlot_TClassManip(TClass*);
   static void delete_RestFramescLcLRFPlot(void *p);
   static void deleteArray_RestFramescLcLRFPlot(void *p);
   static void destruct_RestFramescLcLRFPlot(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RFPlot*)
   {
      ::RestFrames::RFPlot *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RFPlot));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RFPlot", "../include/RFPlot.hh", 41,
                  typeid(::RestFrames::RFPlot), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRFPlot_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RFPlot) );
      instance.SetDelete(&delete_RestFramescLcLRFPlot);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRFPlot);
      instance.SetDestructor(&destruct_RestFramescLcLRFPlot);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RFPlot*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RFPlot*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RFPlot*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRFPlot_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RFPlot*)0x0)->GetClass();
      RestFramescLcLRFPlot_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRFPlot_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLRestFrame_Dictionary();
   static void RestFramescLcLRestFrame_TClassManip(TClass*);
   static void delete_RestFramescLcLRestFrame(void *p);
   static void deleteArray_RestFramescLcLRestFrame(void *p);
   static void destruct_RestFramescLcLRestFrame(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::RestFrame*)
   {
      ::RestFrames::RestFrame *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::RestFrame));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::RestFrame", "../include/RestFrame.hh", 45,
                  typeid(::RestFrames::RestFrame), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLRestFrame_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::RestFrame) );
      instance.SetDelete(&delete_RestFramescLcLRestFrame);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLRestFrame);
      instance.SetDestructor(&destruct_RestFramescLcLRestFrame);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::RestFrame*)
   {
      return GenerateInitInstanceLocal((::RestFrames::RestFrame*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::RestFrame*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLRestFrame_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::RestFrame*)0x0)->GetClass();
      RestFramescLcLRestFrame_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLRestFrame_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLGroup_Dictionary();
   static void RestFramescLcLGroup_TClassManip(TClass*);
   static void delete_RestFramescLcLGroup(void *p);
   static void deleteArray_RestFramescLcLGroup(void *p);
   static void destruct_RestFramescLcLGroup(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::Group*)
   {
      ::RestFrames::Group *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::Group));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::Group", "../include/Group.hh", 46,
                  typeid(::RestFrames::Group), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLGroup_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::Group) );
      instance.SetDelete(&delete_RestFramescLcLGroup);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLGroup);
      instance.SetDestructor(&destruct_RestFramescLcLGroup);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::Group*)
   {
      return GenerateInitInstanceLocal((::RestFrames::Group*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::Group*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLGroup_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::Group*)0x0)->GetClass();
      RestFramescLcLGroup_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLGroup_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLLabRecoFrame_Dictionary();
   static void RestFramescLcLLabRecoFrame_TClassManip(TClass*);
   static void *new_RestFramescLcLLabRecoFrame(void *p = 0);
   static void *newArray_RestFramescLcLLabRecoFrame(Long_t size, void *p);
   static void delete_RestFramescLcLLabRecoFrame(void *p);
   static void deleteArray_RestFramescLcLLabRecoFrame(void *p);
   static void destruct_RestFramescLcLLabRecoFrame(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::LabRecoFrame*)
   {
      ::RestFrames::LabRecoFrame *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::LabRecoFrame));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::LabRecoFrame", "../include/LabRecoFrame.hh", 44,
                  typeid(::RestFrames::LabRecoFrame), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLLabRecoFrame_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::LabRecoFrame) );
      instance.SetNew(&new_RestFramescLcLLabRecoFrame);
      instance.SetNewArray(&newArray_RestFramescLcLLabRecoFrame);
      instance.SetDelete(&delete_RestFramescLcLLabRecoFrame);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLLabRecoFrame);
      instance.SetDestructor(&destruct_RestFramescLcLLabRecoFrame);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::LabRecoFrame*)
   {
      return GenerateInitInstanceLocal((::RestFrames::LabRecoFrame*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::LabRecoFrame*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLLabRecoFrame_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::LabRecoFrame*)0x0)->GetClass();
      RestFramescLcLLabRecoFrame_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLLabRecoFrame_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLDecayRecoFrame_Dictionary();
   static void RestFramescLcLDecayRecoFrame_TClassManip(TClass*);
   static void *new_RestFramescLcLDecayRecoFrame(void *p = 0);
   static void *newArray_RestFramescLcLDecayRecoFrame(Long_t size, void *p);
   static void delete_RestFramescLcLDecayRecoFrame(void *p);
   static void deleteArray_RestFramescLcLDecayRecoFrame(void *p);
   static void destruct_RestFramescLcLDecayRecoFrame(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::DecayRecoFrame*)
   {
      ::RestFrames::DecayRecoFrame *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::DecayRecoFrame));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::DecayRecoFrame", "../include/DecayRecoFrame.hh", 43,
                  typeid(::RestFrames::DecayRecoFrame), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLDecayRecoFrame_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::DecayRecoFrame) );
      instance.SetNew(&new_RestFramescLcLDecayRecoFrame);
      instance.SetNewArray(&newArray_RestFramescLcLDecayRecoFrame);
      instance.SetDelete(&delete_RestFramescLcLDecayRecoFrame);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLDecayRecoFrame);
      instance.SetDestructor(&destruct_RestFramescLcLDecayRecoFrame);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::DecayRecoFrame*)
   {
      return GenerateInitInstanceLocal((::RestFrames::DecayRecoFrame*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::DecayRecoFrame*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLDecayRecoFrame_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::DecayRecoFrame*)0x0)->GetClass();
      RestFramescLcLDecayRecoFrame_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLDecayRecoFrame_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLVisibleRecoFrame_Dictionary();
   static void RestFramescLcLVisibleRecoFrame_TClassManip(TClass*);
   static void *new_RestFramescLcLVisibleRecoFrame(void *p = 0);
   static void *newArray_RestFramescLcLVisibleRecoFrame(Long_t size, void *p);
   static void delete_RestFramescLcLVisibleRecoFrame(void *p);
   static void deleteArray_RestFramescLcLVisibleRecoFrame(void *p);
   static void destruct_RestFramescLcLVisibleRecoFrame(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::VisibleRecoFrame*)
   {
      ::RestFrames::VisibleRecoFrame *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::VisibleRecoFrame));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::VisibleRecoFrame", "../include/VisibleRecoFrame.hh", 41,
                  typeid(::RestFrames::VisibleRecoFrame), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLVisibleRecoFrame_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::VisibleRecoFrame) );
      instance.SetNew(&new_RestFramescLcLVisibleRecoFrame);
      instance.SetNewArray(&newArray_RestFramescLcLVisibleRecoFrame);
      instance.SetDelete(&delete_RestFramescLcLVisibleRecoFrame);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLVisibleRecoFrame);
      instance.SetDestructor(&destruct_RestFramescLcLVisibleRecoFrame);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::VisibleRecoFrame*)
   {
      return GenerateInitInstanceLocal((::RestFrames::VisibleRecoFrame*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::VisibleRecoFrame*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLVisibleRecoFrame_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::VisibleRecoFrame*)0x0)->GetClass();
      RestFramescLcLVisibleRecoFrame_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLVisibleRecoFrame_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLInvisibleRecoFrame_Dictionary();
   static void RestFramescLcLInvisibleRecoFrame_TClassManip(TClass*);
   static void delete_RestFramescLcLInvisibleRecoFrame(void *p);
   static void deleteArray_RestFramescLcLInvisibleRecoFrame(void *p);
   static void destruct_RestFramescLcLInvisibleRecoFrame(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::InvisibleRecoFrame*)
   {
      ::RestFrames::InvisibleRecoFrame *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::InvisibleRecoFrame));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::InvisibleRecoFrame", "../include/InvisibleRecoFrame.hh", 41,
                  typeid(::RestFrames::InvisibleRecoFrame), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLInvisibleRecoFrame_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::InvisibleRecoFrame) );
      instance.SetDelete(&delete_RestFramescLcLInvisibleRecoFrame);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLInvisibleRecoFrame);
      instance.SetDestructor(&destruct_RestFramescLcLInvisibleRecoFrame);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::InvisibleRecoFrame*)
   {
      return GenerateInitInstanceLocal((::RestFrames::InvisibleRecoFrame*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::InvisibleRecoFrame*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLInvisibleRecoFrame_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::InvisibleRecoFrame*)0x0)->GetClass();
      RestFramescLcLInvisibleRecoFrame_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLInvisibleRecoFrame_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLJigsaw_Dictionary();
   static void RestFramescLcLJigsaw_TClassManip(TClass*);
   static void delete_RestFramescLcLJigsaw(void *p);
   static void deleteArray_RestFramescLcLJigsaw(void *p);
   static void destruct_RestFramescLcLJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::Jigsaw*)
   {
      ::RestFrames::Jigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::Jigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::Jigsaw", "../include/Jigsaw.hh", 44,
                  typeid(::RestFrames::Jigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::Jigsaw) );
      instance.SetDelete(&delete_RestFramescLcLJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::Jigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::Jigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::Jigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::Jigsaw*)0x0)->GetClass();
      RestFramescLcLJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLSelfAssemblingRecoFrame_Dictionary();
   static void RestFramescLcLSelfAssemblingRecoFrame_TClassManip(TClass*);
   static void delete_RestFramescLcLSelfAssemblingRecoFrame(void *p);
   static void deleteArray_RestFramescLcLSelfAssemblingRecoFrame(void *p);
   static void destruct_RestFramescLcLSelfAssemblingRecoFrame(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::SelfAssemblingRecoFrame*)
   {
      ::RestFrames::SelfAssemblingRecoFrame *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::SelfAssemblingRecoFrame));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::SelfAssemblingRecoFrame", "../include/SelfAssemblingRecoFrame.hh", 43,
                  typeid(::RestFrames::SelfAssemblingRecoFrame), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLSelfAssemblingRecoFrame_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::SelfAssemblingRecoFrame) );
      instance.SetDelete(&delete_RestFramescLcLSelfAssemblingRecoFrame);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLSelfAssemblingRecoFrame);
      instance.SetDestructor(&destruct_RestFramescLcLSelfAssemblingRecoFrame);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::SelfAssemblingRecoFrame*)
   {
      return GenerateInitInstanceLocal((::RestFrames::SelfAssemblingRecoFrame*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::SelfAssemblingRecoFrame*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLSelfAssemblingRecoFrame_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::SelfAssemblingRecoFrame*)0x0)->GetClass();
      RestFramescLcLSelfAssemblingRecoFrame_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLSelfAssemblingRecoFrame_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLLabGenFrame_Dictionary();
   static void RestFramescLcLLabGenFrame_TClassManip(TClass*);
   static void delete_RestFramescLcLLabGenFrame(void *p);
   static void deleteArray_RestFramescLcLLabGenFrame(void *p);
   static void destruct_RestFramescLcLLabGenFrame(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::LabGenFrame*)
   {
      ::RestFrames::LabGenFrame *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::LabGenFrame));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::LabGenFrame", "../include/LabGenFrame.hh", 41,
                  typeid(::RestFrames::LabGenFrame), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLLabGenFrame_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::LabGenFrame) );
      instance.SetDelete(&delete_RestFramescLcLLabGenFrame);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLLabGenFrame);
      instance.SetDestructor(&destruct_RestFramescLcLLabGenFrame);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::LabGenFrame*)
   {
      return GenerateInitInstanceLocal((::RestFrames::LabGenFrame*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::LabGenFrame*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLLabGenFrame_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::LabGenFrame*)0x0)->GetClass();
      RestFramescLcLLabGenFrame_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLLabGenFrame_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLDecayGenFrame_Dictionary();
   static void RestFramescLcLDecayGenFrame_TClassManip(TClass*);
   static void *new_RestFramescLcLDecayGenFrame(void *p = 0);
   static void *newArray_RestFramescLcLDecayGenFrame(Long_t size, void *p);
   static void delete_RestFramescLcLDecayGenFrame(void *p);
   static void deleteArray_RestFramescLcLDecayGenFrame(void *p);
   static void destruct_RestFramescLcLDecayGenFrame(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::DecayGenFrame*)
   {
      ::RestFrames::DecayGenFrame *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::DecayGenFrame));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::DecayGenFrame", "../include/DecayGenFrame.hh", 43,
                  typeid(::RestFrames::DecayGenFrame), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLDecayGenFrame_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::DecayGenFrame) );
      instance.SetNew(&new_RestFramescLcLDecayGenFrame);
      instance.SetNewArray(&newArray_RestFramescLcLDecayGenFrame);
      instance.SetDelete(&delete_RestFramescLcLDecayGenFrame);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLDecayGenFrame);
      instance.SetDestructor(&destruct_RestFramescLcLDecayGenFrame);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::DecayGenFrame*)
   {
      return GenerateInitInstanceLocal((::RestFrames::DecayGenFrame*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::DecayGenFrame*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLDecayGenFrame_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::DecayGenFrame*)0x0)->GetClass();
      RestFramescLcLDecayGenFrame_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLDecayGenFrame_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLVisibleGenFrame_Dictionary();
   static void RestFramescLcLVisibleGenFrame_TClassManip(TClass*);
   static void *new_RestFramescLcLVisibleGenFrame(void *p = 0);
   static void *newArray_RestFramescLcLVisibleGenFrame(Long_t size, void *p);
   static void delete_RestFramescLcLVisibleGenFrame(void *p);
   static void deleteArray_RestFramescLcLVisibleGenFrame(void *p);
   static void destruct_RestFramescLcLVisibleGenFrame(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::VisibleGenFrame*)
   {
      ::RestFrames::VisibleGenFrame *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::VisibleGenFrame));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::VisibleGenFrame", "../include/VisibleGenFrame.hh", 41,
                  typeid(::RestFrames::VisibleGenFrame), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLVisibleGenFrame_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::VisibleGenFrame) );
      instance.SetNew(&new_RestFramescLcLVisibleGenFrame);
      instance.SetNewArray(&newArray_RestFramescLcLVisibleGenFrame);
      instance.SetDelete(&delete_RestFramescLcLVisibleGenFrame);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLVisibleGenFrame);
      instance.SetDestructor(&destruct_RestFramescLcLVisibleGenFrame);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::VisibleGenFrame*)
   {
      return GenerateInitInstanceLocal((::RestFrames::VisibleGenFrame*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::VisibleGenFrame*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLVisibleGenFrame_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::VisibleGenFrame*)0x0)->GetClass();
      RestFramescLcLVisibleGenFrame_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLVisibleGenFrame_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLInvisibleGenFrame_Dictionary();
   static void RestFramescLcLInvisibleGenFrame_TClassManip(TClass*);
   static void delete_RestFramescLcLInvisibleGenFrame(void *p);
   static void deleteArray_RestFramescLcLInvisibleGenFrame(void *p);
   static void destruct_RestFramescLcLInvisibleGenFrame(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::InvisibleGenFrame*)
   {
      ::RestFrames::InvisibleGenFrame *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::InvisibleGenFrame));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::InvisibleGenFrame", "../include/InvisibleGenFrame.hh", 41,
                  typeid(::RestFrames::InvisibleGenFrame), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLInvisibleGenFrame_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::InvisibleGenFrame) );
      instance.SetDelete(&delete_RestFramescLcLInvisibleGenFrame);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLInvisibleGenFrame);
      instance.SetDestructor(&destruct_RestFramescLcLInvisibleGenFrame);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::InvisibleGenFrame*)
   {
      return GenerateInitInstanceLocal((::RestFrames::InvisibleGenFrame*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::InvisibleGenFrame*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLInvisibleGenFrame_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::InvisibleGenFrame*)0x0)->GetClass();
      RestFramescLcLInvisibleGenFrame_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLInvisibleGenFrame_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLResonanceGenFrame_Dictionary();
   static void RestFramescLcLResonanceGenFrame_TClassManip(TClass*);
   static void *new_RestFramescLcLResonanceGenFrame(void *p = 0);
   static void *newArray_RestFramescLcLResonanceGenFrame(Long_t size, void *p);
   static void delete_RestFramescLcLResonanceGenFrame(void *p);
   static void deleteArray_RestFramescLcLResonanceGenFrame(void *p);
   static void destruct_RestFramescLcLResonanceGenFrame(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::ResonanceGenFrame*)
   {
      ::RestFrames::ResonanceGenFrame *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::ResonanceGenFrame));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::ResonanceGenFrame", "../include/ResonanceGenFrame.hh", 40,
                  typeid(::RestFrames::ResonanceGenFrame), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLResonanceGenFrame_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::ResonanceGenFrame) );
      instance.SetNew(&new_RestFramescLcLResonanceGenFrame);
      instance.SetNewArray(&newArray_RestFramescLcLResonanceGenFrame);
      instance.SetDelete(&delete_RestFramescLcLResonanceGenFrame);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLResonanceGenFrame);
      instance.SetDestructor(&destruct_RestFramescLcLResonanceGenFrame);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::ResonanceGenFrame*)
   {
      return GenerateInitInstanceLocal((::RestFrames::ResonanceGenFrame*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::ResonanceGenFrame*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLResonanceGenFrame_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::ResonanceGenFrame*)0x0)->GetClass();
      RestFramescLcLResonanceGenFrame_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLResonanceGenFrame_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLppLabGenFrame_Dictionary();
   static void RestFramescLcLppLabGenFrame_TClassManip(TClass*);
   static void delete_RestFramescLcLppLabGenFrame(void *p);
   static void deleteArray_RestFramescLcLppLabGenFrame(void *p);
   static void destruct_RestFramescLcLppLabGenFrame(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::ppLabGenFrame*)
   {
      ::RestFrames::ppLabGenFrame *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::ppLabGenFrame));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::ppLabGenFrame", "../include/ppLabGenFrame.hh", 40,
                  typeid(::RestFrames::ppLabGenFrame), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLppLabGenFrame_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::ppLabGenFrame) );
      instance.SetDelete(&delete_RestFramescLcLppLabGenFrame);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLppLabGenFrame);
      instance.SetDestructor(&destruct_RestFramescLcLppLabGenFrame);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::ppLabGenFrame*)
   {
      return GenerateInitInstanceLocal((::RestFrames::ppLabGenFrame*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::ppLabGenFrame*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLppLabGenFrame_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::ppLabGenFrame*)0x0)->GetClass();
      RestFramescLcLppLabGenFrame_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLppLabGenFrame_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLInvisibleGroup_Dictionary();
   static void RestFramescLcLInvisibleGroup_TClassManip(TClass*);
   static void *new_RestFramescLcLInvisibleGroup(void *p = 0);
   static void *newArray_RestFramescLcLInvisibleGroup(Long_t size, void *p);
   static void delete_RestFramescLcLInvisibleGroup(void *p);
   static void deleteArray_RestFramescLcLInvisibleGroup(void *p);
   static void destruct_RestFramescLcLInvisibleGroup(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::InvisibleGroup*)
   {
      ::RestFrames::InvisibleGroup *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::InvisibleGroup));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::InvisibleGroup", "../include/InvisibleGroup.hh", 40,
                  typeid(::RestFrames::InvisibleGroup), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLInvisibleGroup_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::InvisibleGroup) );
      instance.SetNew(&new_RestFramescLcLInvisibleGroup);
      instance.SetNewArray(&newArray_RestFramescLcLInvisibleGroup);
      instance.SetDelete(&delete_RestFramescLcLInvisibleGroup);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLInvisibleGroup);
      instance.SetDestructor(&destruct_RestFramescLcLInvisibleGroup);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::InvisibleGroup*)
   {
      return GenerateInitInstanceLocal((::RestFrames::InvisibleGroup*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::InvisibleGroup*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLInvisibleGroup_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::InvisibleGroup*)0x0)->GetClass();
      RestFramescLcLInvisibleGroup_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLInvisibleGroup_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLCombinatoricGroup_Dictionary();
   static void RestFramescLcLCombinatoricGroup_TClassManip(TClass*);
   static void *new_RestFramescLcLCombinatoricGroup(void *p = 0);
   static void *newArray_RestFramescLcLCombinatoricGroup(Long_t size, void *p);
   static void delete_RestFramescLcLCombinatoricGroup(void *p);
   static void deleteArray_RestFramescLcLCombinatoricGroup(void *p);
   static void destruct_RestFramescLcLCombinatoricGroup(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::CombinatoricGroup*)
   {
      ::RestFrames::CombinatoricGroup *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::CombinatoricGroup));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::CombinatoricGroup", "../include/CombinatoricGroup.hh", 39,
                  typeid(::RestFrames::CombinatoricGroup), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLCombinatoricGroup_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::CombinatoricGroup) );
      instance.SetNew(&new_RestFramescLcLCombinatoricGroup);
      instance.SetNewArray(&newArray_RestFramescLcLCombinatoricGroup);
      instance.SetDelete(&delete_RestFramescLcLCombinatoricGroup);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLCombinatoricGroup);
      instance.SetDestructor(&destruct_RestFramescLcLCombinatoricGroup);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::CombinatoricGroup*)
   {
      return GenerateInitInstanceLocal((::RestFrames::CombinatoricGroup*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::CombinatoricGroup*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLCombinatoricGroup_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::CombinatoricGroup*)0x0)->GetClass();
      RestFramescLcLCombinatoricGroup_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLCombinatoricGroup_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLInvisibleJigsaw_Dictionary();
   static void RestFramescLcLInvisibleJigsaw_TClassManip(TClass*);
   static void delete_RestFramescLcLInvisibleJigsaw(void *p);
   static void deleteArray_RestFramescLcLInvisibleJigsaw(void *p);
   static void destruct_RestFramescLcLInvisibleJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::InvisibleJigsaw*)
   {
      ::RestFrames::InvisibleJigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::InvisibleJigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::InvisibleJigsaw", "../include/InvisibleJigsaw.hh", 39,
                  typeid(::RestFrames::InvisibleJigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLInvisibleJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::InvisibleJigsaw) );
      instance.SetDelete(&delete_RestFramescLcLInvisibleJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLInvisibleJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLInvisibleJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::InvisibleJigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::InvisibleJigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::InvisibleJigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLInvisibleJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::InvisibleJigsaw*)0x0)->GetClass();
      RestFramescLcLInvisibleJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLInvisibleJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLCombinatoricJigsaw_Dictionary();
   static void RestFramescLcLCombinatoricJigsaw_TClassManip(TClass*);
   static void delete_RestFramescLcLCombinatoricJigsaw(void *p);
   static void deleteArray_RestFramescLcLCombinatoricJigsaw(void *p);
   static void destruct_RestFramescLcLCombinatoricJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::CombinatoricJigsaw*)
   {
      ::RestFrames::CombinatoricJigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::CombinatoricJigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::CombinatoricJigsaw", "../include/CombinatoricJigsaw.hh", 40,
                  typeid(::RestFrames::CombinatoricJigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLCombinatoricJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::CombinatoricJigsaw) );
      instance.SetDelete(&delete_RestFramescLcLCombinatoricJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLCombinatoricJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLCombinatoricJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::CombinatoricJigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::CombinatoricJigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::CombinatoricJigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLCombinatoricJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::CombinatoricJigsaw*)0x0)->GetClass();
      RestFramescLcLCombinatoricJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLCombinatoricJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLSetMassInvJigsaw_Dictionary();
   static void RestFramescLcLSetMassInvJigsaw_TClassManip(TClass*);
   static void *new_RestFramescLcLSetMassInvJigsaw(void *p = 0);
   static void *newArray_RestFramescLcLSetMassInvJigsaw(Long_t size, void *p);
   static void delete_RestFramescLcLSetMassInvJigsaw(void *p);
   static void deleteArray_RestFramescLcLSetMassInvJigsaw(void *p);
   static void destruct_RestFramescLcLSetMassInvJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::SetMassInvJigsaw*)
   {
      ::RestFrames::SetMassInvJigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::SetMassInvJigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::SetMassInvJigsaw", "../include/SetMassInvJigsaw.hh", 37,
                  typeid(::RestFrames::SetMassInvJigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLSetMassInvJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::SetMassInvJigsaw) );
      instance.SetNew(&new_RestFramescLcLSetMassInvJigsaw);
      instance.SetNewArray(&newArray_RestFramescLcLSetMassInvJigsaw);
      instance.SetDelete(&delete_RestFramescLcLSetMassInvJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLSetMassInvJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLSetMassInvJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::SetMassInvJigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::SetMassInvJigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::SetMassInvJigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLSetMassInvJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::SetMassInvJigsaw*)0x0)->GetClass();
      RestFramescLcLSetMassInvJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLSetMassInvJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLSetRapidityInvJigsaw_Dictionary();
   static void RestFramescLcLSetRapidityInvJigsaw_TClassManip(TClass*);
   static void *new_RestFramescLcLSetRapidityInvJigsaw(void *p = 0);
   static void *newArray_RestFramescLcLSetRapidityInvJigsaw(Long_t size, void *p);
   static void delete_RestFramescLcLSetRapidityInvJigsaw(void *p);
   static void deleteArray_RestFramescLcLSetRapidityInvJigsaw(void *p);
   static void destruct_RestFramescLcLSetRapidityInvJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::SetRapidityInvJigsaw*)
   {
      ::RestFrames::SetRapidityInvJigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::SetRapidityInvJigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::SetRapidityInvJigsaw", "../include/SetRapidityInvJigsaw.hh", 37,
                  typeid(::RestFrames::SetRapidityInvJigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLSetRapidityInvJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::SetRapidityInvJigsaw) );
      instance.SetNew(&new_RestFramescLcLSetRapidityInvJigsaw);
      instance.SetNewArray(&newArray_RestFramescLcLSetRapidityInvJigsaw);
      instance.SetDelete(&delete_RestFramescLcLSetRapidityInvJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLSetRapidityInvJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLSetRapidityInvJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::SetRapidityInvJigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::SetRapidityInvJigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::SetRapidityInvJigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLSetRapidityInvJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::SetRapidityInvJigsaw*)0x0)->GetClass();
      RestFramescLcLSetRapidityInvJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLSetRapidityInvJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLContraBoostInvJigsaw_Dictionary();
   static void RestFramescLcLContraBoostInvJigsaw_TClassManip(TClass*);
   static void *new_RestFramescLcLContraBoostInvJigsaw(void *p = 0);
   static void *newArray_RestFramescLcLContraBoostInvJigsaw(Long_t size, void *p);
   static void delete_RestFramescLcLContraBoostInvJigsaw(void *p);
   static void deleteArray_RestFramescLcLContraBoostInvJigsaw(void *p);
   static void destruct_RestFramescLcLContraBoostInvJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::ContraBoostInvJigsaw*)
   {
      ::RestFrames::ContraBoostInvJigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::ContraBoostInvJigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::ContraBoostInvJigsaw", "../include/ContraBoostInvJigsaw.hh", 37,
                  typeid(::RestFrames::ContraBoostInvJigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLContraBoostInvJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::ContraBoostInvJigsaw) );
      instance.SetNew(&new_RestFramescLcLContraBoostInvJigsaw);
      instance.SetNewArray(&newArray_RestFramescLcLContraBoostInvJigsaw);
      instance.SetDelete(&delete_RestFramescLcLContraBoostInvJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLContraBoostInvJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLContraBoostInvJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::ContraBoostInvJigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::ContraBoostInvJigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::ContraBoostInvJigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLContraBoostInvJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::ContraBoostInvJigsaw*)0x0)->GetClass();
      RestFramescLcLContraBoostInvJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLContraBoostInvJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLCombinedCBInvJigsaw_Dictionary();
   static void RestFramescLcLCombinedCBInvJigsaw_TClassManip(TClass*);
   static void delete_RestFramescLcLCombinedCBInvJigsaw(void *p);
   static void deleteArray_RestFramescLcLCombinedCBInvJigsaw(void *p);
   static void destruct_RestFramescLcLCombinedCBInvJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::CombinedCBInvJigsaw*)
   {
      ::RestFrames::CombinedCBInvJigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::CombinedCBInvJigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::CombinedCBInvJigsaw", "../include/CombinedCBInvJigsaw.hh", 39,
                  typeid(::RestFrames::CombinedCBInvJigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLCombinedCBInvJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::CombinedCBInvJigsaw) );
      instance.SetDelete(&delete_RestFramescLcLCombinedCBInvJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLCombinedCBInvJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLCombinedCBInvJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::CombinedCBInvJigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::CombinedCBInvJigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::CombinedCBInvJigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLCombinedCBInvJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::CombinedCBInvJigsaw*)0x0)->GetClass();
      RestFramescLcLCombinedCBInvJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLCombinedCBInvJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLMinMassDiffInvJigsaw_Dictionary();
   static void RestFramescLcLMinMassDiffInvJigsaw_TClassManip(TClass*);
   static void delete_RestFramescLcLMinMassDiffInvJigsaw(void *p);
   static void deleteArray_RestFramescLcLMinMassDiffInvJigsaw(void *p);
   static void destruct_RestFramescLcLMinMassDiffInvJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::MinMassDiffInvJigsaw*)
   {
      ::RestFrames::MinMassDiffInvJigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::MinMassDiffInvJigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::MinMassDiffInvJigsaw", "../include/MinMassDiffInvJigsaw.hh", 40,
                  typeid(::RestFrames::MinMassDiffInvJigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLMinMassDiffInvJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::MinMassDiffInvJigsaw) );
      instance.SetDelete(&delete_RestFramescLcLMinMassDiffInvJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLMinMassDiffInvJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLMinMassDiffInvJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::MinMassDiffInvJigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::MinMassDiffInvJigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::MinMassDiffInvJigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLMinMassDiffInvJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::MinMassDiffInvJigsaw*)0x0)->GetClass();
      RestFramescLcLMinMassDiffInvJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLMinMassDiffInvJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLMinMassesSqInvJigsaw_Dictionary();
   static void RestFramescLcLMinMassesSqInvJigsaw_TClassManip(TClass*);
   static void *new_RestFramescLcLMinMassesSqInvJigsaw(void *p = 0);
   static void *newArray_RestFramescLcLMinMassesSqInvJigsaw(Long_t size, void *p);
   static void delete_RestFramescLcLMinMassesSqInvJigsaw(void *p);
   static void deleteArray_RestFramescLcLMinMassesSqInvJigsaw(void *p);
   static void destruct_RestFramescLcLMinMassesSqInvJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::MinMassesSqInvJigsaw*)
   {
      ::RestFrames::MinMassesSqInvJigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::MinMassesSqInvJigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::MinMassesSqInvJigsaw", "../include/MinMassesSqInvJigsaw.hh", 37,
                  typeid(::RestFrames::MinMassesSqInvJigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLMinMassesSqInvJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::MinMassesSqInvJigsaw) );
      instance.SetNew(&new_RestFramescLcLMinMassesSqInvJigsaw);
      instance.SetNewArray(&newArray_RestFramescLcLMinMassesSqInvJigsaw);
      instance.SetDelete(&delete_RestFramescLcLMinMassesSqInvJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLMinMassesSqInvJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLMinMassesSqInvJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::MinMassesSqInvJigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::MinMassesSqInvJigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::MinMassesSqInvJigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLMinMassesSqInvJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::MinMassesSqInvJigsaw*)0x0)->GetClass();
      RestFramescLcLMinMassesSqInvJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLMinMassesSqInvJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLMaxProbBreitWignerInvJigsaw_Dictionary();
   static void RestFramescLcLMaxProbBreitWignerInvJigsaw_TClassManip(TClass*);
   static void delete_RestFramescLcLMaxProbBreitWignerInvJigsaw(void *p);
   static void deleteArray_RestFramescLcLMaxProbBreitWignerInvJigsaw(void *p);
   static void destruct_RestFramescLcLMaxProbBreitWignerInvJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::MaxProbBreitWignerInvJigsaw*)
   {
      ::RestFrames::MaxProbBreitWignerInvJigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::MaxProbBreitWignerInvJigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::MaxProbBreitWignerInvJigsaw", "../include/MaxProbBreitWignerInvJigsaw.hh", 40,
                  typeid(::RestFrames::MaxProbBreitWignerInvJigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLMaxProbBreitWignerInvJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::MaxProbBreitWignerInvJigsaw) );
      instance.SetDelete(&delete_RestFramescLcLMaxProbBreitWignerInvJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLMaxProbBreitWignerInvJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLMaxProbBreitWignerInvJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::MaxProbBreitWignerInvJigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::MaxProbBreitWignerInvJigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::MaxProbBreitWignerInvJigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLMaxProbBreitWignerInvJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::MaxProbBreitWignerInvJigsaw*)0x0)->GetClass();
      RestFramescLcLMaxProbBreitWignerInvJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLMaxProbBreitWignerInvJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLMinMassesCombJigsaw_Dictionary();
   static void RestFramescLcLMinMassesCombJigsaw_TClassManip(TClass*);
   static void *new_RestFramescLcLMinMassesCombJigsaw(void *p = 0);
   static void *newArray_RestFramescLcLMinMassesCombJigsaw(Long_t size, void *p);
   static void delete_RestFramescLcLMinMassesCombJigsaw(void *p);
   static void deleteArray_RestFramescLcLMinMassesCombJigsaw(void *p);
   static void destruct_RestFramescLcLMinMassesCombJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::MinMassesCombJigsaw*)
   {
      ::RestFrames::MinMassesCombJigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::MinMassesCombJigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::MinMassesCombJigsaw", "../include/MinMassesCombJigsaw.hh", 40,
                  typeid(::RestFrames::MinMassesCombJigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLMinMassesCombJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::MinMassesCombJigsaw) );
      instance.SetNew(&new_RestFramescLcLMinMassesCombJigsaw);
      instance.SetNewArray(&newArray_RestFramescLcLMinMassesCombJigsaw);
      instance.SetDelete(&delete_RestFramescLcLMinMassesCombJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLMinMassesCombJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLMinMassesCombJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::MinMassesCombJigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::MinMassesCombJigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::MinMassesCombJigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLMinMassesCombJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::MinMassesCombJigsaw*)0x0)->GetClass();
      RestFramescLcLMinMassesCombJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLMinMassesCombJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLMinMassChi2CombJigsaw_Dictionary();
   static void RestFramescLcLMinMassChi2CombJigsaw_TClassManip(TClass*);
   static void delete_RestFramescLcLMinMassChi2CombJigsaw(void *p);
   static void deleteArray_RestFramescLcLMinMassChi2CombJigsaw(void *p);
   static void destruct_RestFramescLcLMinMassChi2CombJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::MinMassChi2CombJigsaw*)
   {
      ::RestFrames::MinMassChi2CombJigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::MinMassChi2CombJigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::MinMassChi2CombJigsaw", "../include/MinMassChi2CombJigsaw.hh", 37,
                  typeid(::RestFrames::MinMassChi2CombJigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLMinMassChi2CombJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::MinMassChi2CombJigsaw) );
      instance.SetDelete(&delete_RestFramescLcLMinMassChi2CombJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLMinMassChi2CombJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLMinMassChi2CombJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::MinMassChi2CombJigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::MinMassChi2CombJigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::MinMassChi2CombJigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLMinMassChi2CombJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::MinMassChi2CombJigsaw*)0x0)->GetClass();
      RestFramescLcLMinMassChi2CombJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLMinMassChi2CombJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLMaxProbBreitWignerCombJigsaw_Dictionary();
   static void RestFramescLcLMaxProbBreitWignerCombJigsaw_TClassManip(TClass*);
   static void delete_RestFramescLcLMaxProbBreitWignerCombJigsaw(void *p);
   static void deleteArray_RestFramescLcLMaxProbBreitWignerCombJigsaw(void *p);
   static void destruct_RestFramescLcLMaxProbBreitWignerCombJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::MaxProbBreitWignerCombJigsaw*)
   {
      ::RestFrames::MaxProbBreitWignerCombJigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::MaxProbBreitWignerCombJigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::MaxProbBreitWignerCombJigsaw", "../include/MaxProbBreitWignerCombJigsaw.hh", 37,
                  typeid(::RestFrames::MaxProbBreitWignerCombJigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLMaxProbBreitWignerCombJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::MaxProbBreitWignerCombJigsaw) );
      instance.SetDelete(&delete_RestFramescLcLMaxProbBreitWignerCombJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLMaxProbBreitWignerCombJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLMaxProbBreitWignerCombJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::MaxProbBreitWignerCombJigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::MaxProbBreitWignerCombJigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::MaxProbBreitWignerCombJigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLMaxProbBreitWignerCombJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::MaxProbBreitWignerCombJigsaw*)0x0)->GetClass();
      RestFramescLcLMaxProbBreitWignerCombJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLMaxProbBreitWignerCombJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLMinMassDiffCombJigsaw_Dictionary();
   static void RestFramescLcLMinMassDiffCombJigsaw_TClassManip(TClass*);
   static void delete_RestFramescLcLMinMassDiffCombJigsaw(void *p);
   static void deleteArray_RestFramescLcLMinMassDiffCombJigsaw(void *p);
   static void destruct_RestFramescLcLMinMassDiffCombJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::MinMassDiffCombJigsaw*)
   {
      ::RestFrames::MinMassDiffCombJigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::MinMassDiffCombJigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::MinMassDiffCombJigsaw", "../include/MinMassDiffCombJigsaw.hh", 37,
                  typeid(::RestFrames::MinMassDiffCombJigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLMinMassDiffCombJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::MinMassDiffCombJigsaw) );
      instance.SetDelete(&delete_RestFramescLcLMinMassDiffCombJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLMinMassDiffCombJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLMinMassDiffCombJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::MinMassDiffCombJigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::MinMassDiffCombJigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::MinMassDiffCombJigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLMinMassDiffCombJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::MinMassDiffCombJigsaw*)0x0)->GetClass();
      RestFramescLcLMinMassDiffCombJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLMinMassDiffCombJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLMinMassesSqCombJigsaw_Dictionary();
   static void RestFramescLcLMinMassesSqCombJigsaw_TClassManip(TClass*);
   static void delete_RestFramescLcLMinMassesSqCombJigsaw(void *p);
   static void deleteArray_RestFramescLcLMinMassesSqCombJigsaw(void *p);
   static void destruct_RestFramescLcLMinMassesSqCombJigsaw(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::MinMassesSqCombJigsaw*)
   {
      ::RestFrames::MinMassesSqCombJigsaw *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::MinMassesSqCombJigsaw));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::MinMassesSqCombJigsaw", "../include/MinMassesSqCombJigsaw.hh", 37,
                  typeid(::RestFrames::MinMassesSqCombJigsaw), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLMinMassesSqCombJigsaw_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::MinMassesSqCombJigsaw) );
      instance.SetDelete(&delete_RestFramescLcLMinMassesSqCombJigsaw);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLMinMassesSqCombJigsaw);
      instance.SetDestructor(&destruct_RestFramescLcLMinMassesSqCombJigsaw);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::MinMassesSqCombJigsaw*)
   {
      return GenerateInitInstanceLocal((::RestFrames::MinMassesSqCombJigsaw*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::MinMassesSqCombJigsaw*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLMinMassesSqCombJigsaw_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::MinMassesSqCombJigsaw*)0x0)->GetClass();
      RestFramescLcLMinMassesSqCombJigsaw_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLMinMassesSqCombJigsaw_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLTreePlot_Dictionary();
   static void RestFramescLcLTreePlot_TClassManip(TClass*);
   static void delete_RestFramescLcLTreePlot(void *p);
   static void deleteArray_RestFramescLcLTreePlot(void *p);
   static void destruct_RestFramescLcLTreePlot(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::TreePlot*)
   {
      ::RestFrames::TreePlot *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::TreePlot));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::TreePlot", "../include/TreePlot.hh", 50,
                  typeid(::RestFrames::TreePlot), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLTreePlot_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::TreePlot) );
      instance.SetDelete(&delete_RestFramescLcLTreePlot);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLTreePlot);
      instance.SetDestructor(&destruct_RestFramescLcLTreePlot);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::TreePlot*)
   {
      return GenerateInitInstanceLocal((::RestFrames::TreePlot*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::TreePlot*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLTreePlot_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::TreePlot*)0x0)->GetClass();
      RestFramescLcLTreePlot_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLTreePlot_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLTreePlotNode_Dictionary();
   static void RestFramescLcLTreePlotNode_TClassManip(TClass*);
   static void *new_RestFramescLcLTreePlotNode(void *p = 0);
   static void *newArray_RestFramescLcLTreePlotNode(Long_t size, void *p);
   static void delete_RestFramescLcLTreePlotNode(void *p);
   static void deleteArray_RestFramescLcLTreePlotNode(void *p);
   static void destruct_RestFramescLcLTreePlotNode(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::TreePlotNode*)
   {
      ::RestFrames::TreePlotNode *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::TreePlotNode));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::TreePlotNode", "../include/TreePlotNode.hh", 42,
                  typeid(::RestFrames::TreePlotNode), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLTreePlotNode_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::TreePlotNode) );
      instance.SetNew(&new_RestFramescLcLTreePlotNode);
      instance.SetNewArray(&newArray_RestFramescLcLTreePlotNode);
      instance.SetDelete(&delete_RestFramescLcLTreePlotNode);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLTreePlotNode);
      instance.SetDestructor(&destruct_RestFramescLcLTreePlotNode);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::TreePlotNode*)
   {
      return GenerateInitInstanceLocal((::RestFrames::TreePlotNode*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::TreePlotNode*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLTreePlotNode_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::TreePlotNode*)0x0)->GetClass();
      RestFramescLcLTreePlotNode_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLTreePlotNode_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLTreePlotLink_Dictionary();
   static void RestFramescLcLTreePlotLink_TClassManip(TClass*);
   static void delete_RestFramescLcLTreePlotLink(void *p);
   static void deleteArray_RestFramescLcLTreePlotLink(void *p);
   static void destruct_RestFramescLcLTreePlotLink(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::TreePlotLink*)
   {
      ::RestFrames::TreePlotLink *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::TreePlotLink));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::TreePlotLink", "../include/TreePlotLink.hh", 40,
                  typeid(::RestFrames::TreePlotLink), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLTreePlotLink_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::TreePlotLink) );
      instance.SetDelete(&delete_RestFramescLcLTreePlotLink);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLTreePlotLink);
      instance.SetDestructor(&destruct_RestFramescLcLTreePlotLink);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::TreePlotLink*)
   {
      return GenerateInitInstanceLocal((::RestFrames::TreePlotLink*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::TreePlotLink*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLTreePlotLink_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::TreePlotLink*)0x0)->GetClass();
      RestFramescLcLTreePlotLink_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLTreePlotLink_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLHistPlotVar_Dictionary();
   static void RestFramescLcLHistPlotVar_TClassManip(TClass*);
   static void *new_RestFramescLcLHistPlotVar(void *p = 0);
   static void *newArray_RestFramescLcLHistPlotVar(Long_t size, void *p);
   static void delete_RestFramescLcLHistPlotVar(void *p);
   static void deleteArray_RestFramescLcLHistPlotVar(void *p);
   static void destruct_RestFramescLcLHistPlotVar(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::HistPlotVar*)
   {
      ::RestFrames::HistPlotVar *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::HistPlotVar));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::HistPlotVar", "../include/HistPlotVar.hh", 40,
                  typeid(::RestFrames::HistPlotVar), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLHistPlotVar_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::HistPlotVar) );
      instance.SetNew(&new_RestFramescLcLHistPlotVar);
      instance.SetNewArray(&newArray_RestFramescLcLHistPlotVar);
      instance.SetDelete(&delete_RestFramescLcLHistPlotVar);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLHistPlotVar);
      instance.SetDestructor(&destruct_RestFramescLcLHistPlotVar);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::HistPlotVar*)
   {
      return GenerateInitInstanceLocal((::RestFrames::HistPlotVar*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::HistPlotVar*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLHistPlotVar_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::HistPlotVar*)0x0)->GetClass();
      RestFramescLcLHistPlotVar_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLHistPlotVar_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLHistPlotCategory_Dictionary();
   static void RestFramescLcLHistPlotCategory_TClassManip(TClass*);
   static void *new_RestFramescLcLHistPlotCategory(void *p = 0);
   static void *newArray_RestFramescLcLHistPlotCategory(Long_t size, void *p);
   static void delete_RestFramescLcLHistPlotCategory(void *p);
   static void deleteArray_RestFramescLcLHistPlotCategory(void *p);
   static void destruct_RestFramescLcLHistPlotCategory(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::HistPlotCategory*)
   {
      ::RestFrames::HistPlotCategory *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::HistPlotCategory));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::HistPlotCategory", "../include/HistPlotCategory.hh", 40,
                  typeid(::RestFrames::HistPlotCategory), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLHistPlotCategory_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::HistPlotCategory) );
      instance.SetNew(&new_RestFramescLcLHistPlotCategory);
      instance.SetNewArray(&newArray_RestFramescLcLHistPlotCategory);
      instance.SetDelete(&delete_RestFramescLcLHistPlotCategory);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLHistPlotCategory);
      instance.SetDestructor(&destruct_RestFramescLcLHistPlotCategory);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::HistPlotCategory*)
   {
      return GenerateInitInstanceLocal((::RestFrames::HistPlotCategory*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::HistPlotCategory*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLHistPlotCategory_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::HistPlotCategory*)0x0)->GetClass();
      RestFramescLcLHistPlotCategory_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLHistPlotCategory_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RestFramescLcLHistPlot_Dictionary();
   static void RestFramescLcLHistPlot_TClassManip(TClass*);
   static void delete_RestFramescLcLHistPlot(void *p);
   static void deleteArray_RestFramescLcLHistPlot(void *p);
   static void destruct_RestFramescLcLHistPlot(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RestFrames::HistPlot*)
   {
      ::RestFrames::HistPlot *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RestFrames::HistPlot));
      static ::ROOT::TGenericClassInfo 
         instance("RestFrames::HistPlot", "../include/HistPlot.hh", 44,
                  typeid(::RestFrames::HistPlot), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RestFramescLcLHistPlot_Dictionary, isa_proxy, 4,
                  sizeof(::RestFrames::HistPlot) );
      instance.SetDelete(&delete_RestFramescLcLHistPlot);
      instance.SetDeleteArray(&deleteArray_RestFramescLcLHistPlot);
      instance.SetDestructor(&destruct_RestFramescLcLHistPlot);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RestFrames::HistPlot*)
   {
      return GenerateInitInstanceLocal((::RestFrames::HistPlot*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RestFrames::HistPlot*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RestFramescLcLHistPlot_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RestFrames::HistPlot*)0x0)->GetClass();
      RestFramescLcLHistPlot_TClassManip(theClass);
   return theClass;
   }

   static void RestFramescLcLHistPlot_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLRFKey(void *p) {
      delete ((::RestFrames::RFKey*)p);
   }
   static void deleteArray_RestFramescLcLRFKey(void *p) {
      delete [] ((::RestFrames::RFKey*)p);
   }
   static void destruct_RestFramescLcLRFKey(void *p) {
      typedef ::RestFrames::RFKey current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RFKey

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLRFCharge(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFCharge : new ::RestFrames::RFCharge;
   }
   static void *newArray_RestFramescLcLRFCharge(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFCharge[nElements] : new ::RestFrames::RFCharge[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLRFCharge(void *p) {
      delete ((::RestFrames::RFCharge*)p);
   }
   static void deleteArray_RestFramescLcLRFCharge(void *p) {
      delete [] ((::RestFrames::RFCharge*)p);
   }
   static void destruct_RestFramescLcLRFCharge(void *p) {
      typedef ::RestFrames::RFCharge current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RFCharge

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<const RestFrames::RestFrame> : new ::RestFrames::RFList<const RestFrames::RestFrame>;
   }
   static void *newArray_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<const RestFrames::RestFrame>[nElements] : new ::RestFrames::RFList<const RestFrames::RestFrame>[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR(void *p) {
      delete ((::RestFrames::RFList<const RestFrames::RestFrame>*)p);
   }
   static void deleteArray_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR(void *p) {
      delete [] ((::RestFrames::RFList<const RestFrames::RestFrame>*)p);
   }
   static void destruct_RestFramescLcLRFListlEconstsPRestFramescLcLRestFramegR(void *p) {
      typedef ::RestFrames::RFList<const RestFrames::RestFrame> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RFList<const RestFrames::RestFrame>

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLRFListlERestFramescLcLGroupgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<RestFrames::Group> : new ::RestFrames::RFList<RestFrames::Group>;
   }
   static void *newArray_RestFramescLcLRFListlERestFramescLcLGroupgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<RestFrames::Group>[nElements] : new ::RestFrames::RFList<RestFrames::Group>[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLRFListlERestFramescLcLGroupgR(void *p) {
      delete ((::RestFrames::RFList<RestFrames::Group>*)p);
   }
   static void deleteArray_RestFramescLcLRFListlERestFramescLcLGroupgR(void *p) {
      delete [] ((::RestFrames::RFList<RestFrames::Group>*)p);
   }
   static void destruct_RestFramescLcLRFListlERestFramescLcLGroupgR(void *p) {
      typedef ::RestFrames::RFList<RestFrames::Group> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RFList<RestFrames::Group>

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<const RestFrames::Group> : new ::RestFrames::RFList<const RestFrames::Group>;
   }
   static void *newArray_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<const RestFrames::Group>[nElements] : new ::RestFrames::RFList<const RestFrames::Group>[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR(void *p) {
      delete ((::RestFrames::RFList<const RestFrames::Group>*)p);
   }
   static void deleteArray_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR(void *p) {
      delete [] ((::RestFrames::RFList<const RestFrames::Group>*)p);
   }
   static void destruct_RestFramescLcLRFListlEconstsPRestFramescLcLGroupgR(void *p) {
      typedef ::RestFrames::RFList<const RestFrames::Group> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RFList<const RestFrames::Group>

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLRFListlERestFramescLcLJigsawgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<RestFrames::Jigsaw> : new ::RestFrames::RFList<RestFrames::Jigsaw>;
   }
   static void *newArray_RestFramescLcLRFListlERestFramescLcLJigsawgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<RestFrames::Jigsaw>[nElements] : new ::RestFrames::RFList<RestFrames::Jigsaw>[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLRFListlERestFramescLcLJigsawgR(void *p) {
      delete ((::RestFrames::RFList<RestFrames::Jigsaw>*)p);
   }
   static void deleteArray_RestFramescLcLRFListlERestFramescLcLJigsawgR(void *p) {
      delete [] ((::RestFrames::RFList<RestFrames::Jigsaw>*)p);
   }
   static void destruct_RestFramescLcLRFListlERestFramescLcLJigsawgR(void *p) {
      typedef ::RestFrames::RFList<RestFrames::Jigsaw> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RFList<RestFrames::Jigsaw>

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<const RestFrames::Jigsaw> : new ::RestFrames::RFList<const RestFrames::Jigsaw>;
   }
   static void *newArray_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<const RestFrames::Jigsaw>[nElements] : new ::RestFrames::RFList<const RestFrames::Jigsaw>[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR(void *p) {
      delete ((::RestFrames::RFList<const RestFrames::Jigsaw>*)p);
   }
   static void deleteArray_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR(void *p) {
      delete [] ((::RestFrames::RFList<const RestFrames::Jigsaw>*)p);
   }
   static void destruct_RestFramescLcLRFListlEconstsPRestFramescLcLJigsawgR(void *p) {
      typedef ::RestFrames::RFList<const RestFrames::Jigsaw> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RFList<const RestFrames::Jigsaw>

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLRFListlERestFramescLcLHistPlotVargR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<RestFrames::HistPlotVar> : new ::RestFrames::RFList<RestFrames::HistPlotVar>;
   }
   static void *newArray_RestFramescLcLRFListlERestFramescLcLHistPlotVargR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<RestFrames::HistPlotVar>[nElements] : new ::RestFrames::RFList<RestFrames::HistPlotVar>[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLRFListlERestFramescLcLHistPlotVargR(void *p) {
      delete ((::RestFrames::RFList<RestFrames::HistPlotVar>*)p);
   }
   static void deleteArray_RestFramescLcLRFListlERestFramescLcLHistPlotVargR(void *p) {
      delete [] ((::RestFrames::RFList<RestFrames::HistPlotVar>*)p);
   }
   static void destruct_RestFramescLcLRFListlERestFramescLcLHistPlotVargR(void *p) {
      typedef ::RestFrames::RFList<RestFrames::HistPlotVar> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RFList<RestFrames::HistPlotVar>

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<RestFrames::HistPlotCategory> : new ::RestFrames::RFList<RestFrames::HistPlotCategory>;
   }
   static void *newArray_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<RestFrames::HistPlotCategory>[nElements] : new ::RestFrames::RFList<RestFrames::HistPlotCategory>[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR(void *p) {
      delete ((::RestFrames::RFList<RestFrames::HistPlotCategory>*)p);
   }
   static void deleteArray_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR(void *p) {
      delete [] ((::RestFrames::RFList<RestFrames::HistPlotCategory>*)p);
   }
   static void destruct_RestFramescLcLRFListlERestFramescLcLHistPlotCategorygR(void *p) {
      typedef ::RestFrames::RFList<RestFrames::HistPlotCategory> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RFList<RestFrames::HistPlotCategory>

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<const RestFrames::HistPlotCategory> : new ::RestFrames::RFList<const RestFrames::HistPlotCategory>;
   }
   static void *newArray_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<const RestFrames::HistPlotCategory>[nElements] : new ::RestFrames::RFList<const RestFrames::HistPlotCategory>[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR(void *p) {
      delete ((::RestFrames::RFList<const RestFrames::HistPlotCategory>*)p);
   }
   static void deleteArray_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR(void *p) {
      delete [] ((::RestFrames::RFList<const RestFrames::HistPlotCategory>*)p);
   }
   static void destruct_RestFramescLcLRFListlEconstsPRestFramescLcLHistPlotCategorygR(void *p) {
      typedef ::RestFrames::RFList<const RestFrames::HistPlotCategory> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RFList<const RestFrames::HistPlotCategory>

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLRFListlERestFramescLcLRestFramegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<RestFrames::RestFrame> : new ::RestFrames::RFList<RestFrames::RestFrame>;
   }
   static void *newArray_RestFramescLcLRFListlERestFramescLcLRestFramegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFList<RestFrames::RestFrame>[nElements] : new ::RestFrames::RFList<RestFrames::RestFrame>[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLRFListlERestFramescLcLRestFramegR(void *p) {
      delete ((::RestFrames::RFList<RestFrames::RestFrame>*)p);
   }
   static void deleteArray_RestFramescLcLRFListlERestFramescLcLRestFramegR(void *p) {
      delete [] ((::RestFrames::RFList<RestFrames::RestFrame>*)p);
   }
   static void destruct_RestFramescLcLRFListlERestFramescLcLRestFramegR(void *p) {
      typedef ::RestFrames::RFList<RestFrames::RestFrame> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RFList<RestFrames::RestFrame>

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLRFLog(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFLog : new ::RestFrames::RFLog;
   }
   static void *newArray_RestFramescLcLRFLog(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFLog[nElements] : new ::RestFrames::RFLog[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLRFLog(void *p) {
      delete ((::RestFrames::RFLog*)p);
   }
   static void deleteArray_RestFramescLcLRFLog(void *p) {
      delete [] ((::RestFrames::RFLog*)p);
   }
   static void destruct_RestFramescLcLRFLog(void *p) {
      typedef ::RestFrames::RFLog current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RFLog

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLRFBase(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFBase : new ::RestFrames::RFBase;
   }
   static void *newArray_RestFramescLcLRFBase(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::RFBase[nElements] : new ::RestFrames::RFBase[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLRFBase(void *p) {
      delete ((::RestFrames::RFBase*)p);
   }
   static void deleteArray_RestFramescLcLRFBase(void *p) {
      delete [] ((::RestFrames::RFBase*)p);
   }
   static void destruct_RestFramescLcLRFBase(void *p) {
      typedef ::RestFrames::RFBase current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RFBase

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLRFPlot(void *p) {
      delete ((::RestFrames::RFPlot*)p);
   }
   static void deleteArray_RestFramescLcLRFPlot(void *p) {
      delete [] ((::RestFrames::RFPlot*)p);
   }
   static void destruct_RestFramescLcLRFPlot(void *p) {
      typedef ::RestFrames::RFPlot current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RFPlot

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLRestFrame(void *p) {
      delete ((::RestFrames::RestFrame*)p);
   }
   static void deleteArray_RestFramescLcLRestFrame(void *p) {
      delete [] ((::RestFrames::RestFrame*)p);
   }
   static void destruct_RestFramescLcLRestFrame(void *p) {
      typedef ::RestFrames::RestFrame current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::RestFrame

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLGroup(void *p) {
      delete ((::RestFrames::Group*)p);
   }
   static void deleteArray_RestFramescLcLGroup(void *p) {
      delete [] ((::RestFrames::Group*)p);
   }
   static void destruct_RestFramescLcLGroup(void *p) {
      typedef ::RestFrames::Group current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::Group

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLLabRecoFrame(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::LabRecoFrame : new ::RestFrames::LabRecoFrame;
   }
   static void *newArray_RestFramescLcLLabRecoFrame(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::LabRecoFrame[nElements] : new ::RestFrames::LabRecoFrame[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLLabRecoFrame(void *p) {
      delete ((::RestFrames::LabRecoFrame*)p);
   }
   static void deleteArray_RestFramescLcLLabRecoFrame(void *p) {
      delete [] ((::RestFrames::LabRecoFrame*)p);
   }
   static void destruct_RestFramescLcLLabRecoFrame(void *p) {
      typedef ::RestFrames::LabRecoFrame current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::LabRecoFrame

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLDecayRecoFrame(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::DecayRecoFrame : new ::RestFrames::DecayRecoFrame;
   }
   static void *newArray_RestFramescLcLDecayRecoFrame(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::DecayRecoFrame[nElements] : new ::RestFrames::DecayRecoFrame[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLDecayRecoFrame(void *p) {
      delete ((::RestFrames::DecayRecoFrame*)p);
   }
   static void deleteArray_RestFramescLcLDecayRecoFrame(void *p) {
      delete [] ((::RestFrames::DecayRecoFrame*)p);
   }
   static void destruct_RestFramescLcLDecayRecoFrame(void *p) {
      typedef ::RestFrames::DecayRecoFrame current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::DecayRecoFrame

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLVisibleRecoFrame(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::VisibleRecoFrame : new ::RestFrames::VisibleRecoFrame;
   }
   static void *newArray_RestFramescLcLVisibleRecoFrame(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::VisibleRecoFrame[nElements] : new ::RestFrames::VisibleRecoFrame[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLVisibleRecoFrame(void *p) {
      delete ((::RestFrames::VisibleRecoFrame*)p);
   }
   static void deleteArray_RestFramescLcLVisibleRecoFrame(void *p) {
      delete [] ((::RestFrames::VisibleRecoFrame*)p);
   }
   static void destruct_RestFramescLcLVisibleRecoFrame(void *p) {
      typedef ::RestFrames::VisibleRecoFrame current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::VisibleRecoFrame

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLInvisibleRecoFrame(void *p) {
      delete ((::RestFrames::InvisibleRecoFrame*)p);
   }
   static void deleteArray_RestFramescLcLInvisibleRecoFrame(void *p) {
      delete [] ((::RestFrames::InvisibleRecoFrame*)p);
   }
   static void destruct_RestFramescLcLInvisibleRecoFrame(void *p) {
      typedef ::RestFrames::InvisibleRecoFrame current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::InvisibleRecoFrame

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLJigsaw(void *p) {
      delete ((::RestFrames::Jigsaw*)p);
   }
   static void deleteArray_RestFramescLcLJigsaw(void *p) {
      delete [] ((::RestFrames::Jigsaw*)p);
   }
   static void destruct_RestFramescLcLJigsaw(void *p) {
      typedef ::RestFrames::Jigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::Jigsaw

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLSelfAssemblingRecoFrame(void *p) {
      delete ((::RestFrames::SelfAssemblingRecoFrame*)p);
   }
   static void deleteArray_RestFramescLcLSelfAssemblingRecoFrame(void *p) {
      delete [] ((::RestFrames::SelfAssemblingRecoFrame*)p);
   }
   static void destruct_RestFramescLcLSelfAssemblingRecoFrame(void *p) {
      typedef ::RestFrames::SelfAssemblingRecoFrame current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::SelfAssemblingRecoFrame

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLLabGenFrame(void *p) {
      delete ((::RestFrames::LabGenFrame*)p);
   }
   static void deleteArray_RestFramescLcLLabGenFrame(void *p) {
      delete [] ((::RestFrames::LabGenFrame*)p);
   }
   static void destruct_RestFramescLcLLabGenFrame(void *p) {
      typedef ::RestFrames::LabGenFrame current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::LabGenFrame

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLDecayGenFrame(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::DecayGenFrame : new ::RestFrames::DecayGenFrame;
   }
   static void *newArray_RestFramescLcLDecayGenFrame(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::DecayGenFrame[nElements] : new ::RestFrames::DecayGenFrame[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLDecayGenFrame(void *p) {
      delete ((::RestFrames::DecayGenFrame*)p);
   }
   static void deleteArray_RestFramescLcLDecayGenFrame(void *p) {
      delete [] ((::RestFrames::DecayGenFrame*)p);
   }
   static void destruct_RestFramescLcLDecayGenFrame(void *p) {
      typedef ::RestFrames::DecayGenFrame current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::DecayGenFrame

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLVisibleGenFrame(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::VisibleGenFrame : new ::RestFrames::VisibleGenFrame;
   }
   static void *newArray_RestFramescLcLVisibleGenFrame(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::VisibleGenFrame[nElements] : new ::RestFrames::VisibleGenFrame[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLVisibleGenFrame(void *p) {
      delete ((::RestFrames::VisibleGenFrame*)p);
   }
   static void deleteArray_RestFramescLcLVisibleGenFrame(void *p) {
      delete [] ((::RestFrames::VisibleGenFrame*)p);
   }
   static void destruct_RestFramescLcLVisibleGenFrame(void *p) {
      typedef ::RestFrames::VisibleGenFrame current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::VisibleGenFrame

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLInvisibleGenFrame(void *p) {
      delete ((::RestFrames::InvisibleGenFrame*)p);
   }
   static void deleteArray_RestFramescLcLInvisibleGenFrame(void *p) {
      delete [] ((::RestFrames::InvisibleGenFrame*)p);
   }
   static void destruct_RestFramescLcLInvisibleGenFrame(void *p) {
      typedef ::RestFrames::InvisibleGenFrame current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::InvisibleGenFrame

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLResonanceGenFrame(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::ResonanceGenFrame : new ::RestFrames::ResonanceGenFrame;
   }
   static void *newArray_RestFramescLcLResonanceGenFrame(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::ResonanceGenFrame[nElements] : new ::RestFrames::ResonanceGenFrame[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLResonanceGenFrame(void *p) {
      delete ((::RestFrames::ResonanceGenFrame*)p);
   }
   static void deleteArray_RestFramescLcLResonanceGenFrame(void *p) {
      delete [] ((::RestFrames::ResonanceGenFrame*)p);
   }
   static void destruct_RestFramescLcLResonanceGenFrame(void *p) {
      typedef ::RestFrames::ResonanceGenFrame current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::ResonanceGenFrame

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLppLabGenFrame(void *p) {
      delete ((::RestFrames::ppLabGenFrame*)p);
   }
   static void deleteArray_RestFramescLcLppLabGenFrame(void *p) {
      delete [] ((::RestFrames::ppLabGenFrame*)p);
   }
   static void destruct_RestFramescLcLppLabGenFrame(void *p) {
      typedef ::RestFrames::ppLabGenFrame current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::ppLabGenFrame

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLInvisibleGroup(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::InvisibleGroup : new ::RestFrames::InvisibleGroup;
   }
   static void *newArray_RestFramescLcLInvisibleGroup(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::InvisibleGroup[nElements] : new ::RestFrames::InvisibleGroup[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLInvisibleGroup(void *p) {
      delete ((::RestFrames::InvisibleGroup*)p);
   }
   static void deleteArray_RestFramescLcLInvisibleGroup(void *p) {
      delete [] ((::RestFrames::InvisibleGroup*)p);
   }
   static void destruct_RestFramescLcLInvisibleGroup(void *p) {
      typedef ::RestFrames::InvisibleGroup current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::InvisibleGroup

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLCombinatoricGroup(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::CombinatoricGroup : new ::RestFrames::CombinatoricGroup;
   }
   static void *newArray_RestFramescLcLCombinatoricGroup(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::CombinatoricGroup[nElements] : new ::RestFrames::CombinatoricGroup[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLCombinatoricGroup(void *p) {
      delete ((::RestFrames::CombinatoricGroup*)p);
   }
   static void deleteArray_RestFramescLcLCombinatoricGroup(void *p) {
      delete [] ((::RestFrames::CombinatoricGroup*)p);
   }
   static void destruct_RestFramescLcLCombinatoricGroup(void *p) {
      typedef ::RestFrames::CombinatoricGroup current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::CombinatoricGroup

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLInvisibleJigsaw(void *p) {
      delete ((::RestFrames::InvisibleJigsaw*)p);
   }
   static void deleteArray_RestFramescLcLInvisibleJigsaw(void *p) {
      delete [] ((::RestFrames::InvisibleJigsaw*)p);
   }
   static void destruct_RestFramescLcLInvisibleJigsaw(void *p) {
      typedef ::RestFrames::InvisibleJigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::InvisibleJigsaw

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLCombinatoricJigsaw(void *p) {
      delete ((::RestFrames::CombinatoricJigsaw*)p);
   }
   static void deleteArray_RestFramescLcLCombinatoricJigsaw(void *p) {
      delete [] ((::RestFrames::CombinatoricJigsaw*)p);
   }
   static void destruct_RestFramescLcLCombinatoricJigsaw(void *p) {
      typedef ::RestFrames::CombinatoricJigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::CombinatoricJigsaw

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLSetMassInvJigsaw(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::SetMassInvJigsaw : new ::RestFrames::SetMassInvJigsaw;
   }
   static void *newArray_RestFramescLcLSetMassInvJigsaw(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::SetMassInvJigsaw[nElements] : new ::RestFrames::SetMassInvJigsaw[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLSetMassInvJigsaw(void *p) {
      delete ((::RestFrames::SetMassInvJigsaw*)p);
   }
   static void deleteArray_RestFramescLcLSetMassInvJigsaw(void *p) {
      delete [] ((::RestFrames::SetMassInvJigsaw*)p);
   }
   static void destruct_RestFramescLcLSetMassInvJigsaw(void *p) {
      typedef ::RestFrames::SetMassInvJigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::SetMassInvJigsaw

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLSetRapidityInvJigsaw(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::SetRapidityInvJigsaw : new ::RestFrames::SetRapidityInvJigsaw;
   }
   static void *newArray_RestFramescLcLSetRapidityInvJigsaw(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::SetRapidityInvJigsaw[nElements] : new ::RestFrames::SetRapidityInvJigsaw[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLSetRapidityInvJigsaw(void *p) {
      delete ((::RestFrames::SetRapidityInvJigsaw*)p);
   }
   static void deleteArray_RestFramescLcLSetRapidityInvJigsaw(void *p) {
      delete [] ((::RestFrames::SetRapidityInvJigsaw*)p);
   }
   static void destruct_RestFramescLcLSetRapidityInvJigsaw(void *p) {
      typedef ::RestFrames::SetRapidityInvJigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::SetRapidityInvJigsaw

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLContraBoostInvJigsaw(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::ContraBoostInvJigsaw : new ::RestFrames::ContraBoostInvJigsaw;
   }
   static void *newArray_RestFramescLcLContraBoostInvJigsaw(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::ContraBoostInvJigsaw[nElements] : new ::RestFrames::ContraBoostInvJigsaw[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLContraBoostInvJigsaw(void *p) {
      delete ((::RestFrames::ContraBoostInvJigsaw*)p);
   }
   static void deleteArray_RestFramescLcLContraBoostInvJigsaw(void *p) {
      delete [] ((::RestFrames::ContraBoostInvJigsaw*)p);
   }
   static void destruct_RestFramescLcLContraBoostInvJigsaw(void *p) {
      typedef ::RestFrames::ContraBoostInvJigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::ContraBoostInvJigsaw

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLCombinedCBInvJigsaw(void *p) {
      delete ((::RestFrames::CombinedCBInvJigsaw*)p);
   }
   static void deleteArray_RestFramescLcLCombinedCBInvJigsaw(void *p) {
      delete [] ((::RestFrames::CombinedCBInvJigsaw*)p);
   }
   static void destruct_RestFramescLcLCombinedCBInvJigsaw(void *p) {
      typedef ::RestFrames::CombinedCBInvJigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::CombinedCBInvJigsaw

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLMinMassDiffInvJigsaw(void *p) {
      delete ((::RestFrames::MinMassDiffInvJigsaw*)p);
   }
   static void deleteArray_RestFramescLcLMinMassDiffInvJigsaw(void *p) {
      delete [] ((::RestFrames::MinMassDiffInvJigsaw*)p);
   }
   static void destruct_RestFramescLcLMinMassDiffInvJigsaw(void *p) {
      typedef ::RestFrames::MinMassDiffInvJigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::MinMassDiffInvJigsaw

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLMinMassesSqInvJigsaw(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::MinMassesSqInvJigsaw : new ::RestFrames::MinMassesSqInvJigsaw;
   }
   static void *newArray_RestFramescLcLMinMassesSqInvJigsaw(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::MinMassesSqInvJigsaw[nElements] : new ::RestFrames::MinMassesSqInvJigsaw[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLMinMassesSqInvJigsaw(void *p) {
      delete ((::RestFrames::MinMassesSqInvJigsaw*)p);
   }
   static void deleteArray_RestFramescLcLMinMassesSqInvJigsaw(void *p) {
      delete [] ((::RestFrames::MinMassesSqInvJigsaw*)p);
   }
   static void destruct_RestFramescLcLMinMassesSqInvJigsaw(void *p) {
      typedef ::RestFrames::MinMassesSqInvJigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::MinMassesSqInvJigsaw

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLMaxProbBreitWignerInvJigsaw(void *p) {
      delete ((::RestFrames::MaxProbBreitWignerInvJigsaw*)p);
   }
   static void deleteArray_RestFramescLcLMaxProbBreitWignerInvJigsaw(void *p) {
      delete [] ((::RestFrames::MaxProbBreitWignerInvJigsaw*)p);
   }
   static void destruct_RestFramescLcLMaxProbBreitWignerInvJigsaw(void *p) {
      typedef ::RestFrames::MaxProbBreitWignerInvJigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::MaxProbBreitWignerInvJigsaw

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLMinMassesCombJigsaw(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::MinMassesCombJigsaw : new ::RestFrames::MinMassesCombJigsaw;
   }
   static void *newArray_RestFramescLcLMinMassesCombJigsaw(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::MinMassesCombJigsaw[nElements] : new ::RestFrames::MinMassesCombJigsaw[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLMinMassesCombJigsaw(void *p) {
      delete ((::RestFrames::MinMassesCombJigsaw*)p);
   }
   static void deleteArray_RestFramescLcLMinMassesCombJigsaw(void *p) {
      delete [] ((::RestFrames::MinMassesCombJigsaw*)p);
   }
   static void destruct_RestFramescLcLMinMassesCombJigsaw(void *p) {
      typedef ::RestFrames::MinMassesCombJigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::MinMassesCombJigsaw

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLMinMassChi2CombJigsaw(void *p) {
      delete ((::RestFrames::MinMassChi2CombJigsaw*)p);
   }
   static void deleteArray_RestFramescLcLMinMassChi2CombJigsaw(void *p) {
      delete [] ((::RestFrames::MinMassChi2CombJigsaw*)p);
   }
   static void destruct_RestFramescLcLMinMassChi2CombJigsaw(void *p) {
      typedef ::RestFrames::MinMassChi2CombJigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::MinMassChi2CombJigsaw

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLMaxProbBreitWignerCombJigsaw(void *p) {
      delete ((::RestFrames::MaxProbBreitWignerCombJigsaw*)p);
   }
   static void deleteArray_RestFramescLcLMaxProbBreitWignerCombJigsaw(void *p) {
      delete [] ((::RestFrames::MaxProbBreitWignerCombJigsaw*)p);
   }
   static void destruct_RestFramescLcLMaxProbBreitWignerCombJigsaw(void *p) {
      typedef ::RestFrames::MaxProbBreitWignerCombJigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::MaxProbBreitWignerCombJigsaw

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLMinMassDiffCombJigsaw(void *p) {
      delete ((::RestFrames::MinMassDiffCombJigsaw*)p);
   }
   static void deleteArray_RestFramescLcLMinMassDiffCombJigsaw(void *p) {
      delete [] ((::RestFrames::MinMassDiffCombJigsaw*)p);
   }
   static void destruct_RestFramescLcLMinMassDiffCombJigsaw(void *p) {
      typedef ::RestFrames::MinMassDiffCombJigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::MinMassDiffCombJigsaw

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLMinMassesSqCombJigsaw(void *p) {
      delete ((::RestFrames::MinMassesSqCombJigsaw*)p);
   }
   static void deleteArray_RestFramescLcLMinMassesSqCombJigsaw(void *p) {
      delete [] ((::RestFrames::MinMassesSqCombJigsaw*)p);
   }
   static void destruct_RestFramescLcLMinMassesSqCombJigsaw(void *p) {
      typedef ::RestFrames::MinMassesSqCombJigsaw current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::MinMassesSqCombJigsaw

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLTreePlot(void *p) {
      delete ((::RestFrames::TreePlot*)p);
   }
   static void deleteArray_RestFramescLcLTreePlot(void *p) {
      delete [] ((::RestFrames::TreePlot*)p);
   }
   static void destruct_RestFramescLcLTreePlot(void *p) {
      typedef ::RestFrames::TreePlot current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::TreePlot

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLTreePlotNode(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::TreePlotNode : new ::RestFrames::TreePlotNode;
   }
   static void *newArray_RestFramescLcLTreePlotNode(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::TreePlotNode[nElements] : new ::RestFrames::TreePlotNode[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLTreePlotNode(void *p) {
      delete ((::RestFrames::TreePlotNode*)p);
   }
   static void deleteArray_RestFramescLcLTreePlotNode(void *p) {
      delete [] ((::RestFrames::TreePlotNode*)p);
   }
   static void destruct_RestFramescLcLTreePlotNode(void *p) {
      typedef ::RestFrames::TreePlotNode current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::TreePlotNode

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLTreePlotLink(void *p) {
      delete ((::RestFrames::TreePlotLink*)p);
   }
   static void deleteArray_RestFramescLcLTreePlotLink(void *p) {
      delete [] ((::RestFrames::TreePlotLink*)p);
   }
   static void destruct_RestFramescLcLTreePlotLink(void *p) {
      typedef ::RestFrames::TreePlotLink current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::TreePlotLink

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLHistPlotVar(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::HistPlotVar : new ::RestFrames::HistPlotVar;
   }
   static void *newArray_RestFramescLcLHistPlotVar(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::HistPlotVar[nElements] : new ::RestFrames::HistPlotVar[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLHistPlotVar(void *p) {
      delete ((::RestFrames::HistPlotVar*)p);
   }
   static void deleteArray_RestFramescLcLHistPlotVar(void *p) {
      delete [] ((::RestFrames::HistPlotVar*)p);
   }
   static void destruct_RestFramescLcLHistPlotVar(void *p) {
      typedef ::RestFrames::HistPlotVar current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::HistPlotVar

namespace ROOT {
   // Wrappers around operator new
   static void *new_RestFramescLcLHistPlotCategory(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::HistPlotCategory : new ::RestFrames::HistPlotCategory;
   }
   static void *newArray_RestFramescLcLHistPlotCategory(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::RestFrames::HistPlotCategory[nElements] : new ::RestFrames::HistPlotCategory[nElements];
   }
   // Wrapper around operator delete
   static void delete_RestFramescLcLHistPlotCategory(void *p) {
      delete ((::RestFrames::HistPlotCategory*)p);
   }
   static void deleteArray_RestFramescLcLHistPlotCategory(void *p) {
      delete [] ((::RestFrames::HistPlotCategory*)p);
   }
   static void destruct_RestFramescLcLHistPlotCategory(void *p) {
      typedef ::RestFrames::HistPlotCategory current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::HistPlotCategory

namespace ROOT {
   // Wrapper around operator delete
   static void delete_RestFramescLcLHistPlot(void *p) {
      delete ((::RestFrames::HistPlot*)p);
   }
   static void deleteArray_RestFramescLcLHistPlot(void *p) {
      delete [] ((::RestFrames::HistPlot*)p);
   }
   static void destruct_RestFramescLcLHistPlot(void *p) {
      typedef ::RestFrames::HistPlot current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RestFrames::HistPlot

namespace ROOT {
   static TClass *vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR_Dictionary();
   static void vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p = 0);
   static void *newArray_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(Long_t size, void *p);
   static void delete_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p);
   static void deleteArray_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p);
   static void destruct_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >*)
   {
      vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >", -2, "vector", 210,
                  typeid(vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >) );
      instance.SetNew(&new_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR);
      instance.SetNewArray(&newArray_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR);
      instance.SetDelete(&delete_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR);
      instance.SetDestructor(&destruct_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> > >()));

      ::ROOT::AddClassAlternate("vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >","std::vector<std::pair<RestFrames::HistPlotVar const*, RestFrames::HistPlotVar const*>, std::allocator<std::pair<RestFrames::HistPlotVar const*, RestFrames::HistPlotVar const*> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >*)0x0)->GetClass();
      vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> > : new vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >;
   }
   static void *newArray_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >[nElements] : new vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p) {
      delete ((vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >*)p);
   }
   static void deleteArray_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p) {
      delete [] ((vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >*)p);
   }
   static void destruct_vectorlEpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p) {
      typedef vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >

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
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 210,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));

      ::ROOT::AddClassAlternate("vector<int>","std::vector<int, std::allocator<int> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

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
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
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
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 210,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));

      ::ROOT::AddClassAlternate("vector<double>","std::vector<double, std::allocator<double> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<double>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

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
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
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

namespace ROOT {
   static TClass *vectorlEconstsPRestFramescLcLHistPlotVarmUgR_Dictionary();
   static void vectorlEconstsPRestFramescLcLHistPlotVarmUgR_TClassManip(TClass*);
   static void *new_vectorlEconstsPRestFramescLcLHistPlotVarmUgR(void *p = 0);
   static void *newArray_vectorlEconstsPRestFramescLcLHistPlotVarmUgR(Long_t size, void *p);
   static void delete_vectorlEconstsPRestFramescLcLHistPlotVarmUgR(void *p);
   static void deleteArray_vectorlEconstsPRestFramescLcLHistPlotVarmUgR(void *p);
   static void destruct_vectorlEconstsPRestFramescLcLHistPlotVarmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<const RestFrames::HistPlotVar*>*)
   {
      vector<const RestFrames::HistPlotVar*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<const RestFrames::HistPlotVar*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<const RestFrames::HistPlotVar*>", -2, "vector", 210,
                  typeid(vector<const RestFrames::HistPlotVar*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEconstsPRestFramescLcLHistPlotVarmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<const RestFrames::HistPlotVar*>) );
      instance.SetNew(&new_vectorlEconstsPRestFramescLcLHistPlotVarmUgR);
      instance.SetNewArray(&newArray_vectorlEconstsPRestFramescLcLHistPlotVarmUgR);
      instance.SetDelete(&delete_vectorlEconstsPRestFramescLcLHistPlotVarmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEconstsPRestFramescLcLHistPlotVarmUgR);
      instance.SetDestructor(&destruct_vectorlEconstsPRestFramescLcLHistPlotVarmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<const RestFrames::HistPlotVar*> >()));

      ::ROOT::AddClassAlternate("vector<const RestFrames::HistPlotVar*>","std::vector<RestFrames::HistPlotVar const*, std::allocator<RestFrames::HistPlotVar const*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<const RestFrames::HistPlotVar*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEconstsPRestFramescLcLHistPlotVarmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<const RestFrames::HistPlotVar*>*)0x0)->GetClass();
      vectorlEconstsPRestFramescLcLHistPlotVarmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEconstsPRestFramescLcLHistPlotVarmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEconstsPRestFramescLcLHistPlotVarmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<const RestFrames::HistPlotVar*> : new vector<const RestFrames::HistPlotVar*>;
   }
   static void *newArray_vectorlEconstsPRestFramescLcLHistPlotVarmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<const RestFrames::HistPlotVar*>[nElements] : new vector<const RestFrames::HistPlotVar*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEconstsPRestFramescLcLHistPlotVarmUgR(void *p) {
      delete ((vector<const RestFrames::HistPlotVar*>*)p);
   }
   static void deleteArray_vectorlEconstsPRestFramescLcLHistPlotVarmUgR(void *p) {
      delete [] ((vector<const RestFrames::HistPlotVar*>*)p);
   }
   static void destruct_vectorlEconstsPRestFramescLcLHistPlotVarmUgR(void *p) {
      typedef vector<const RestFrames::HistPlotVar*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<const RestFrames::HistPlotVar*>

namespace ROOT {
   static TClass *vectorlEconstsPRestFramescLcLHistPlotCategorymUgR_Dictionary();
   static void vectorlEconstsPRestFramescLcLHistPlotCategorymUgR_TClassManip(TClass*);
   static void *new_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR(void *p = 0);
   static void *newArray_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR(Long_t size, void *p);
   static void delete_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR(void *p);
   static void deleteArray_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR(void *p);
   static void destruct_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<const RestFrames::HistPlotCategory*>*)
   {
      vector<const RestFrames::HistPlotCategory*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<const RestFrames::HistPlotCategory*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<const RestFrames::HistPlotCategory*>", -2, "vector", 210,
                  typeid(vector<const RestFrames::HistPlotCategory*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEconstsPRestFramescLcLHistPlotCategorymUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<const RestFrames::HistPlotCategory*>) );
      instance.SetNew(&new_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR);
      instance.SetNewArray(&newArray_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR);
      instance.SetDelete(&delete_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR);
      instance.SetDestructor(&destruct_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<const RestFrames::HistPlotCategory*> >()));

      ::ROOT::AddClassAlternate("vector<const RestFrames::HistPlotCategory*>","std::vector<RestFrames::HistPlotCategory const*, std::allocator<RestFrames::HistPlotCategory const*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<const RestFrames::HistPlotCategory*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEconstsPRestFramescLcLHistPlotCategorymUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<const RestFrames::HistPlotCategory*>*)0x0)->GetClass();
      vectorlEconstsPRestFramescLcLHistPlotCategorymUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEconstsPRestFramescLcLHistPlotCategorymUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<const RestFrames::HistPlotCategory*> : new vector<const RestFrames::HistPlotCategory*>;
   }
   static void *newArray_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<const RestFrames::HistPlotCategory*>[nElements] : new vector<const RestFrames::HistPlotCategory*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR(void *p) {
      delete ((vector<const RestFrames::HistPlotCategory*>*)p);
   }
   static void deleteArray_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR(void *p) {
      delete [] ((vector<const RestFrames::HistPlotCategory*>*)p);
   }
   static void destruct_vectorlEconstsPRestFramescLcLHistPlotCategorymUgR(void *p) {
      typedef vector<const RestFrames::HistPlotCategory*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<const RestFrames::HistPlotCategory*>

namespace ROOT {
   static TClass *vectorlEboolgR_Dictionary();
   static void vectorlEboolgR_TClassManip(TClass*);
   static void *new_vectorlEboolgR(void *p = 0);
   static void *newArray_vectorlEboolgR(Long_t size, void *p);
   static void delete_vectorlEboolgR(void *p);
   static void deleteArray_vectorlEboolgR(void *p);
   static void destruct_vectorlEboolgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<bool>*)
   {
      vector<bool> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<bool>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<bool>", -2, "vector", 518,
                  typeid(vector<bool>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEboolgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<bool>) );
      instance.SetNew(&new_vectorlEboolgR);
      instance.SetNewArray(&newArray_vectorlEboolgR);
      instance.SetDelete(&delete_vectorlEboolgR);
      instance.SetDeleteArray(&deleteArray_vectorlEboolgR);
      instance.SetDestructor(&destruct_vectorlEboolgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<bool> >()));

      ::ROOT::AddClassAlternate("vector<bool>","std::vector<bool, std::allocator<bool> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<bool>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEboolgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<bool>*)0x0)->GetClass();
      vectorlEboolgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEboolgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEboolgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<bool> : new vector<bool>;
   }
   static void *newArray_vectorlEboolgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<bool>[nElements] : new vector<bool>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEboolgR(void *p) {
      delete ((vector<bool>*)p);
   }
   static void deleteArray_vectorlEboolgR(void *p) {
      delete [] ((vector<bool>*)p);
   }
   static void destruct_vectorlEboolgR(void *p) {
      typedef vector<bool> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<bool>

namespace ROOT {
   static TClass *vectorlETObjectmUgR_Dictionary();
   static void vectorlETObjectmUgR_TClassManip(TClass*);
   static void *new_vectorlETObjectmUgR(void *p = 0);
   static void *newArray_vectorlETObjectmUgR(Long_t size, void *p);
   static void delete_vectorlETObjectmUgR(void *p);
   static void deleteArray_vectorlETObjectmUgR(void *p);
   static void destruct_vectorlETObjectmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TObject*>*)
   {
      vector<TObject*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TObject*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TObject*>", -2, "vector", 210,
                  typeid(vector<TObject*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETObjectmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TObject*>) );
      instance.SetNew(&new_vectorlETObjectmUgR);
      instance.SetNewArray(&newArray_vectorlETObjectmUgR);
      instance.SetDelete(&delete_vectorlETObjectmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETObjectmUgR);
      instance.SetDestructor(&destruct_vectorlETObjectmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TObject*> >()));

      ::ROOT::AddClassAlternate("vector<TObject*>","std::vector<TObject*, std::allocator<TObject*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TObject*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETObjectmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TObject*>*)0x0)->GetClass();
      vectorlETObjectmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETObjectmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETObjectmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TObject*> : new vector<TObject*>;
   }
   static void *newArray_vectorlETObjectmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TObject*>[nElements] : new vector<TObject*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETObjectmUgR(void *p) {
      delete ((vector<TObject*>*)p);
   }
   static void deleteArray_vectorlETObjectmUgR(void *p) {
      delete [] ((vector<TObject*>*)p);
   }
   static void destruct_vectorlETObjectmUgR(void *p) {
      typedef vector<TObject*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TObject*>

namespace ROOT {
   static TClass *vectorlETLorentzVectorgR_Dictionary();
   static void vectorlETLorentzVectorgR_TClassManip(TClass*);
   static void *new_vectorlETLorentzVectorgR(void *p = 0);
   static void *newArray_vectorlETLorentzVectorgR(Long_t size, void *p);
   static void delete_vectorlETLorentzVectorgR(void *p);
   static void deleteArray_vectorlETLorentzVectorgR(void *p);
   static void destruct_vectorlETLorentzVectorgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TLorentzVector>*)
   {
      vector<TLorentzVector> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TLorentzVector>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TLorentzVector>", -2, "vector", 210,
                  typeid(vector<TLorentzVector>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETLorentzVectorgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TLorentzVector>) );
      instance.SetNew(&new_vectorlETLorentzVectorgR);
      instance.SetNewArray(&newArray_vectorlETLorentzVectorgR);
      instance.SetDelete(&delete_vectorlETLorentzVectorgR);
      instance.SetDeleteArray(&deleteArray_vectorlETLorentzVectorgR);
      instance.SetDestructor(&destruct_vectorlETLorentzVectorgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TLorentzVector> >()));

      ::ROOT::AddClassAlternate("vector<TLorentzVector>","std::vector<TLorentzVector, std::allocator<TLorentzVector> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TLorentzVector>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETLorentzVectorgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TLorentzVector>*)0x0)->GetClass();
      vectorlETLorentzVectorgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETLorentzVectorgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETLorentzVectorgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TLorentzVector> : new vector<TLorentzVector>;
   }
   static void *newArray_vectorlETLorentzVectorgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TLorentzVector>[nElements] : new vector<TLorentzVector>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETLorentzVectorgR(void *p) {
      delete ((vector<TLorentzVector>*)p);
   }
   static void deleteArray_vectorlETLorentzVectorgR(void *p) {
      delete [] ((vector<TLorentzVector>*)p);
   }
   static void destruct_vectorlETLorentzVectorgR(void *p) {
      typedef vector<TLorentzVector> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TLorentzVector>

namespace ROOT {
   static TClass *vectorlETH2DmUgR_Dictionary();
   static void vectorlETH2DmUgR_TClassManip(TClass*);
   static void *new_vectorlETH2DmUgR(void *p = 0);
   static void *newArray_vectorlETH2DmUgR(Long_t size, void *p);
   static void delete_vectorlETH2DmUgR(void *p);
   static void deleteArray_vectorlETH2DmUgR(void *p);
   static void destruct_vectorlETH2DmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TH2D*>*)
   {
      vector<TH2D*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TH2D*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TH2D*>", -2, "vector", 210,
                  typeid(vector<TH2D*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETH2DmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TH2D*>) );
      instance.SetNew(&new_vectorlETH2DmUgR);
      instance.SetNewArray(&newArray_vectorlETH2DmUgR);
      instance.SetDelete(&delete_vectorlETH2DmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETH2DmUgR);
      instance.SetDestructor(&destruct_vectorlETH2DmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TH2D*> >()));

      ::ROOT::AddClassAlternate("vector<TH2D*>","std::vector<TH2D*, std::allocator<TH2D*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TH2D*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETH2DmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TH2D*>*)0x0)->GetClass();
      vectorlETH2DmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETH2DmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETH2DmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TH2D*> : new vector<TH2D*>;
   }
   static void *newArray_vectorlETH2DmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TH2D*>[nElements] : new vector<TH2D*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETH2DmUgR(void *p) {
      delete ((vector<TH2D*>*)p);
   }
   static void deleteArray_vectorlETH2DmUgR(void *p) {
      delete [] ((vector<TH2D*>*)p);
   }
   static void destruct_vectorlETH2DmUgR(void *p) {
      typedef vector<TH2D*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TH2D*>

namespace ROOT {
   static TClass *vectorlETH1DmUgR_Dictionary();
   static void vectorlETH1DmUgR_TClassManip(TClass*);
   static void *new_vectorlETH1DmUgR(void *p = 0);
   static void *newArray_vectorlETH1DmUgR(Long_t size, void *p);
   static void delete_vectorlETH1DmUgR(void *p);
   static void deleteArray_vectorlETH1DmUgR(void *p);
   static void destruct_vectorlETH1DmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TH1D*>*)
   {
      vector<TH1D*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TH1D*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TH1D*>", -2, "vector", 210,
                  typeid(vector<TH1D*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETH1DmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TH1D*>) );
      instance.SetNew(&new_vectorlETH1DmUgR);
      instance.SetNewArray(&newArray_vectorlETH1DmUgR);
      instance.SetDelete(&delete_vectorlETH1DmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETH1DmUgR);
      instance.SetDestructor(&destruct_vectorlETH1DmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TH1D*> >()));

      ::ROOT::AddClassAlternate("vector<TH1D*>","std::vector<TH1D*, std::allocator<TH1D*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TH1D*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETH1DmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TH1D*>*)0x0)->GetClass();
      vectorlETH1DmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETH1DmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETH1DmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TH1D*> : new vector<TH1D*>;
   }
   static void *newArray_vectorlETH1DmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TH1D*>[nElements] : new vector<TH1D*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETH1DmUgR(void *p) {
      delete ((vector<TH1D*>*)p);
   }
   static void deleteArray_vectorlETH1DmUgR(void *p) {
      delete [] ((vector<TH1D*>*)p);
   }
   static void destruct_vectorlETH1DmUgR(void *p) {
      typedef vector<TH1D*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TH1D*>

namespace ROOT {
   static TClass *vectorlETCanvasmUgR_Dictionary();
   static void vectorlETCanvasmUgR_TClassManip(TClass*);
   static void *new_vectorlETCanvasmUgR(void *p = 0);
   static void *newArray_vectorlETCanvasmUgR(Long_t size, void *p);
   static void delete_vectorlETCanvasmUgR(void *p);
   static void deleteArray_vectorlETCanvasmUgR(void *p);
   static void destruct_vectorlETCanvasmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TCanvas*>*)
   {
      vector<TCanvas*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TCanvas*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TCanvas*>", -2, "vector", 210,
                  typeid(vector<TCanvas*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETCanvasmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TCanvas*>) );
      instance.SetNew(&new_vectorlETCanvasmUgR);
      instance.SetNewArray(&newArray_vectorlETCanvasmUgR);
      instance.SetDelete(&delete_vectorlETCanvasmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETCanvasmUgR);
      instance.SetDestructor(&destruct_vectorlETCanvasmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TCanvas*> >()));

      ::ROOT::AddClassAlternate("vector<TCanvas*>","std::vector<TCanvas*, std::allocator<TCanvas*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<TCanvas*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETCanvasmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TCanvas*>*)0x0)->GetClass();
      vectorlETCanvasmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETCanvasmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETCanvasmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TCanvas*> : new vector<TCanvas*>;
   }
   static void *newArray_vectorlETCanvasmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TCanvas*>[nElements] : new vector<TCanvas*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETCanvasmUgR(void *p) {
      delete ((vector<TCanvas*>*)p);
   }
   static void deleteArray_vectorlETCanvasmUgR(void *p) {
      delete [] ((vector<TCanvas*>*)p);
   }
   static void destruct_vectorlETCanvasmUgR(void *p) {
      typedef vector<TCanvas*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TCanvas*>

namespace ROOT {
   static TClass *vectorlERestFramescLcLTreePlotNodemUgR_Dictionary();
   static void vectorlERestFramescLcLTreePlotNodemUgR_TClassManip(TClass*);
   static void *new_vectorlERestFramescLcLTreePlotNodemUgR(void *p = 0);
   static void *newArray_vectorlERestFramescLcLTreePlotNodemUgR(Long_t size, void *p);
   static void delete_vectorlERestFramescLcLTreePlotNodemUgR(void *p);
   static void deleteArray_vectorlERestFramescLcLTreePlotNodemUgR(void *p);
   static void destruct_vectorlERestFramescLcLTreePlotNodemUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<RestFrames::TreePlotNode*>*)
   {
      vector<RestFrames::TreePlotNode*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<RestFrames::TreePlotNode*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<RestFrames::TreePlotNode*>", -2, "vector", 210,
                  typeid(vector<RestFrames::TreePlotNode*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlERestFramescLcLTreePlotNodemUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<RestFrames::TreePlotNode*>) );
      instance.SetNew(&new_vectorlERestFramescLcLTreePlotNodemUgR);
      instance.SetNewArray(&newArray_vectorlERestFramescLcLTreePlotNodemUgR);
      instance.SetDelete(&delete_vectorlERestFramescLcLTreePlotNodemUgR);
      instance.SetDeleteArray(&deleteArray_vectorlERestFramescLcLTreePlotNodemUgR);
      instance.SetDestructor(&destruct_vectorlERestFramescLcLTreePlotNodemUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<RestFrames::TreePlotNode*> >()));

      ::ROOT::AddClassAlternate("vector<RestFrames::TreePlotNode*>","std::vector<RestFrames::TreePlotNode*, std::allocator<RestFrames::TreePlotNode*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<RestFrames::TreePlotNode*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlERestFramescLcLTreePlotNodemUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<RestFrames::TreePlotNode*>*)0x0)->GetClass();
      vectorlERestFramescLcLTreePlotNodemUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlERestFramescLcLTreePlotNodemUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlERestFramescLcLTreePlotNodemUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RestFrames::TreePlotNode*> : new vector<RestFrames::TreePlotNode*>;
   }
   static void *newArray_vectorlERestFramescLcLTreePlotNodemUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RestFrames::TreePlotNode*>[nElements] : new vector<RestFrames::TreePlotNode*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlERestFramescLcLTreePlotNodemUgR(void *p) {
      delete ((vector<RestFrames::TreePlotNode*>*)p);
   }
   static void deleteArray_vectorlERestFramescLcLTreePlotNodemUgR(void *p) {
      delete [] ((vector<RestFrames::TreePlotNode*>*)p);
   }
   static void destruct_vectorlERestFramescLcLTreePlotNodemUgR(void *p) {
      typedef vector<RestFrames::TreePlotNode*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<RestFrames::TreePlotNode*>

namespace ROOT {
   static TClass *vectorlERestFramescLcLTreePlotLinkmUgR_Dictionary();
   static void vectorlERestFramescLcLTreePlotLinkmUgR_TClassManip(TClass*);
   static void *new_vectorlERestFramescLcLTreePlotLinkmUgR(void *p = 0);
   static void *newArray_vectorlERestFramescLcLTreePlotLinkmUgR(Long_t size, void *p);
   static void delete_vectorlERestFramescLcLTreePlotLinkmUgR(void *p);
   static void deleteArray_vectorlERestFramescLcLTreePlotLinkmUgR(void *p);
   static void destruct_vectorlERestFramescLcLTreePlotLinkmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<RestFrames::TreePlotLink*>*)
   {
      vector<RestFrames::TreePlotLink*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<RestFrames::TreePlotLink*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<RestFrames::TreePlotLink*>", -2, "vector", 210,
                  typeid(vector<RestFrames::TreePlotLink*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlERestFramescLcLTreePlotLinkmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<RestFrames::TreePlotLink*>) );
      instance.SetNew(&new_vectorlERestFramescLcLTreePlotLinkmUgR);
      instance.SetNewArray(&newArray_vectorlERestFramescLcLTreePlotLinkmUgR);
      instance.SetDelete(&delete_vectorlERestFramescLcLTreePlotLinkmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlERestFramescLcLTreePlotLinkmUgR);
      instance.SetDestructor(&destruct_vectorlERestFramescLcLTreePlotLinkmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<RestFrames::TreePlotLink*> >()));

      ::ROOT::AddClassAlternate("vector<RestFrames::TreePlotLink*>","std::vector<RestFrames::TreePlotLink*, std::allocator<RestFrames::TreePlotLink*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<RestFrames::TreePlotLink*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlERestFramescLcLTreePlotLinkmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<RestFrames::TreePlotLink*>*)0x0)->GetClass();
      vectorlERestFramescLcLTreePlotLinkmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlERestFramescLcLTreePlotLinkmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlERestFramescLcLTreePlotLinkmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RestFrames::TreePlotLink*> : new vector<RestFrames::TreePlotLink*>;
   }
   static void *newArray_vectorlERestFramescLcLTreePlotLinkmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RestFrames::TreePlotLink*>[nElements] : new vector<RestFrames::TreePlotLink*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlERestFramescLcLTreePlotLinkmUgR(void *p) {
      delete ((vector<RestFrames::TreePlotLink*>*)p);
   }
   static void deleteArray_vectorlERestFramescLcLTreePlotLinkmUgR(void *p) {
      delete [] ((vector<RestFrames::TreePlotLink*>*)p);
   }
   static void destruct_vectorlERestFramescLcLTreePlotLinkmUgR(void *p) {
      typedef vector<RestFrames::TreePlotLink*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<RestFrames::TreePlotLink*>

namespace ROOT {
   static TClass *vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR_Dictionary();
   static void vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR_TClassManip(TClass*);
   static void *new_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR(void *p = 0);
   static void *newArray_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR(Long_t size, void *p);
   static void delete_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR(void *p);
   static void deleteArray_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR(void *p);
   static void destruct_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<RestFrames::RFList<const RestFrames::RestFrame> >*)
   {
      vector<RestFrames::RFList<const RestFrames::RestFrame> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<RestFrames::RFList<const RestFrames::RestFrame> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<RestFrames::RFList<const RestFrames::RestFrame> >", -2, "vector", 210,
                  typeid(vector<RestFrames::RFList<const RestFrames::RestFrame> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<RestFrames::RFList<const RestFrames::RestFrame> >) );
      instance.SetNew(&new_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR);
      instance.SetNewArray(&newArray_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR);
      instance.SetDelete(&delete_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR);
      instance.SetDestructor(&destruct_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<RestFrames::RFList<const RestFrames::RestFrame> > >()));

      ::ROOT::AddClassAlternate("vector<RestFrames::RFList<const RestFrames::RestFrame> >","std::vector<RestFrames::RFList<RestFrames::RestFrame const>, std::allocator<RestFrames::RFList<RestFrames::RestFrame const> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<RestFrames::RFList<const RestFrames::RestFrame> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<RestFrames::RFList<const RestFrames::RestFrame> >*)0x0)->GetClass();
      vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RestFrames::RFList<const RestFrames::RestFrame> > : new vector<RestFrames::RFList<const RestFrames::RestFrame> >;
   }
   static void *newArray_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RestFrames::RFList<const RestFrames::RestFrame> >[nElements] : new vector<RestFrames::RFList<const RestFrames::RestFrame> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR(void *p) {
      delete ((vector<RestFrames::RFList<const RestFrames::RestFrame> >*)p);
   }
   static void deleteArray_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR(void *p) {
      delete [] ((vector<RestFrames::RFList<const RestFrames::RestFrame> >*)p);
   }
   static void destruct_vectorlERestFramescLcLRFListlEconstsPRestFramescLcLRestFramegRsPgR(void *p) {
      typedef vector<RestFrames::RFList<const RestFrames::RestFrame> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<RestFrames::RFList<const RestFrames::RestFrame> >

namespace ROOT {
   static TClass *vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR_Dictionary();
   static void vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR_TClassManip(TClass*);
   static void *new_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR(void *p = 0);
   static void *newArray_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR(Long_t size, void *p);
   static void delete_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR(void *p);
   static void deleteArray_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR(void *p);
   static void destruct_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<RestFrames::RFList<RestFrames::State> >*)
   {
      vector<RestFrames::RFList<RestFrames::State> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<RestFrames::RFList<RestFrames::State> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<RestFrames::RFList<RestFrames::State> >", -2, "vector", 210,
                  typeid(vector<RestFrames::RFList<RestFrames::State> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<RestFrames::RFList<RestFrames::State> >) );
      instance.SetNew(&new_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR);
      instance.SetNewArray(&newArray_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR);
      instance.SetDelete(&delete_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR);
      instance.SetDestructor(&destruct_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<RestFrames::RFList<RestFrames::State> > >()));

      ::ROOT::AddClassAlternate("vector<RestFrames::RFList<RestFrames::State> >","std::vector<RestFrames::RFList<RestFrames::State>, std::allocator<RestFrames::RFList<RestFrames::State> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<RestFrames::RFList<RestFrames::State> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<RestFrames::RFList<RestFrames::State> >*)0x0)->GetClass();
      vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RestFrames::RFList<RestFrames::State> > : new vector<RestFrames::RFList<RestFrames::State> >;
   }
   static void *newArray_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RestFrames::RFList<RestFrames::State> >[nElements] : new vector<RestFrames::RFList<RestFrames::State> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR(void *p) {
      delete ((vector<RestFrames::RFList<RestFrames::State> >*)p);
   }
   static void deleteArray_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR(void *p) {
      delete [] ((vector<RestFrames::RFList<RestFrames::State> >*)p);
   }
   static void destruct_vectorlERestFramescLcLRFListlERestFramescLcLStategRsPgR(void *p) {
      typedef vector<RestFrames::RFList<RestFrames::State> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<RestFrames::RFList<RestFrames::State> >

namespace ROOT {
   static TClass *vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR_Dictionary();
   static void vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR_TClassManip(TClass*);
   static void *new_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR(void *p = 0);
   static void *newArray_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR(Long_t size, void *p);
   static void delete_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR(void *p);
   static void deleteArray_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR(void *p);
   static void destruct_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<RestFrames::RFList<RestFrames::HistPlotCategory> >*)
   {
      vector<RestFrames::RFList<RestFrames::HistPlotCategory> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<RestFrames::RFList<RestFrames::HistPlotCategory> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<RestFrames::RFList<RestFrames::HistPlotCategory> >", -2, "vector", 210,
                  typeid(vector<RestFrames::RFList<RestFrames::HistPlotCategory> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<RestFrames::RFList<RestFrames::HistPlotCategory> >) );
      instance.SetNew(&new_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR);
      instance.SetNewArray(&newArray_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR);
      instance.SetDelete(&delete_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR);
      instance.SetDestructor(&destruct_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<RestFrames::RFList<RestFrames::HistPlotCategory> > >()));

      ::ROOT::AddClassAlternate("vector<RestFrames::RFList<RestFrames::HistPlotCategory> >","std::vector<RestFrames::RFList<RestFrames::HistPlotCategory>, std::allocator<RestFrames::RFList<RestFrames::HistPlotCategory> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<RestFrames::RFList<RestFrames::HistPlotCategory> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<RestFrames::RFList<RestFrames::HistPlotCategory> >*)0x0)->GetClass();
      vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RestFrames::RFList<RestFrames::HistPlotCategory> > : new vector<RestFrames::RFList<RestFrames::HistPlotCategory> >;
   }
   static void *newArray_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RestFrames::RFList<RestFrames::HistPlotCategory> >[nElements] : new vector<RestFrames::RFList<RestFrames::HistPlotCategory> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR(void *p) {
      delete ((vector<RestFrames::RFList<RestFrames::HistPlotCategory> >*)p);
   }
   static void deleteArray_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR(void *p) {
      delete [] ((vector<RestFrames::RFList<RestFrames::HistPlotCategory> >*)p);
   }
   static void destruct_vectorlERestFramescLcLRFListlERestFramescLcLHistPlotCategorygRsPgR(void *p) {
      typedef vector<RestFrames::RFList<RestFrames::HistPlotCategory> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<RestFrames::RFList<RestFrames::HistPlotCategory> >

namespace ROOT {
   static TClass *vectorlERestFramescLcLRFBasemUgR_Dictionary();
   static void vectorlERestFramescLcLRFBasemUgR_TClassManip(TClass*);
   static void *new_vectorlERestFramescLcLRFBasemUgR(void *p = 0);
   static void *newArray_vectorlERestFramescLcLRFBasemUgR(Long_t size, void *p);
   static void delete_vectorlERestFramescLcLRFBasemUgR(void *p);
   static void deleteArray_vectorlERestFramescLcLRFBasemUgR(void *p);
   static void destruct_vectorlERestFramescLcLRFBasemUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<RestFrames::RFBase*>*)
   {
      vector<RestFrames::RFBase*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<RestFrames::RFBase*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<RestFrames::RFBase*>", -2, "vector", 210,
                  typeid(vector<RestFrames::RFBase*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlERestFramescLcLRFBasemUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<RestFrames::RFBase*>) );
      instance.SetNew(&new_vectorlERestFramescLcLRFBasemUgR);
      instance.SetNewArray(&newArray_vectorlERestFramescLcLRFBasemUgR);
      instance.SetDelete(&delete_vectorlERestFramescLcLRFBasemUgR);
      instance.SetDeleteArray(&deleteArray_vectorlERestFramescLcLRFBasemUgR);
      instance.SetDestructor(&destruct_vectorlERestFramescLcLRFBasemUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<RestFrames::RFBase*> >()));

      ::ROOT::AddClassAlternate("vector<RestFrames::RFBase*>","std::vector<RestFrames::RFBase*, std::allocator<RestFrames::RFBase*> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<RestFrames::RFBase*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlERestFramescLcLRFBasemUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<RestFrames::RFBase*>*)0x0)->GetClass();
      vectorlERestFramescLcLRFBasemUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlERestFramescLcLRFBasemUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlERestFramescLcLRFBasemUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RestFrames::RFBase*> : new vector<RestFrames::RFBase*>;
   }
   static void *newArray_vectorlERestFramescLcLRFBasemUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<RestFrames::RFBase*>[nElements] : new vector<RestFrames::RFBase*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlERestFramescLcLRFBasemUgR(void *p) {
      delete ((vector<RestFrames::RFBase*>*)p);
   }
   static void deleteArray_vectorlERestFramescLcLRFBasemUgR(void *p) {
      delete [] ((vector<RestFrames::RFBase*>*)p);
   }
   static void destruct_vectorlERestFramescLcLRFBasemUgR(void *p) {
      typedef vector<RestFrames::RFBase*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<RestFrames::RFBase*>

namespace ROOT {
   static TClass *maplEintcORestFramescLcLRFChargegR_Dictionary();
   static void maplEintcORestFramescLcLRFChargegR_TClassManip(TClass*);
   static void *new_maplEintcORestFramescLcLRFChargegR(void *p = 0);
   static void *newArray_maplEintcORestFramescLcLRFChargegR(Long_t size, void *p);
   static void delete_maplEintcORestFramescLcLRFChargegR(void *p);
   static void deleteArray_maplEintcORestFramescLcLRFChargegR(void *p);
   static void destruct_maplEintcORestFramescLcLRFChargegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,RestFrames::RFCharge>*)
   {
      map<int,RestFrames::RFCharge> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,RestFrames::RFCharge>));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,RestFrames::RFCharge>", -2, "map", 96,
                  typeid(map<int,RestFrames::RFCharge>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEintcORestFramescLcLRFChargegR_Dictionary, isa_proxy, 0,
                  sizeof(map<int,RestFrames::RFCharge>) );
      instance.SetNew(&new_maplEintcORestFramescLcLRFChargegR);
      instance.SetNewArray(&newArray_maplEintcORestFramescLcLRFChargegR);
      instance.SetDelete(&delete_maplEintcORestFramescLcLRFChargegR);
      instance.SetDeleteArray(&deleteArray_maplEintcORestFramescLcLRFChargegR);
      instance.SetDestructor(&destruct_maplEintcORestFramescLcLRFChargegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,RestFrames::RFCharge> >()));

      ::ROOT::AddClassAlternate("map<int,RestFrames::RFCharge>","std::map<int, RestFrames::RFCharge, std::less<int>, std::allocator<std::pair<int const, RestFrames::RFCharge> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<int,RestFrames::RFCharge>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcORestFramescLcLRFChargegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<int,RestFrames::RFCharge>*)0x0)->GetClass();
      maplEintcORestFramescLcLRFChargegR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcORestFramescLcLRFChargegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcORestFramescLcLRFChargegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<int,RestFrames::RFCharge> : new map<int,RestFrames::RFCharge>;
   }
   static void *newArray_maplEintcORestFramescLcLRFChargegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<int,RestFrames::RFCharge>[nElements] : new map<int,RestFrames::RFCharge>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcORestFramescLcLRFChargegR(void *p) {
      delete ((map<int,RestFrames::RFCharge>*)p);
   }
   static void deleteArray_maplEintcORestFramescLcLRFChargegR(void *p) {
      delete [] ((map<int,RestFrames::RFCharge>*)p);
   }
   static void destruct_maplEintcORestFramescLcLRFChargegR(void *p) {
      typedef map<int,RestFrames::RFCharge> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<int,RestFrames::RFCharge>

namespace ROOT {
   static TClass *maplEconstsPRestFramescLcLRestFramemUcOintgR_Dictionary();
   static void maplEconstsPRestFramescLcLRestFramemUcOintgR_TClassManip(TClass*);
   static void *new_maplEconstsPRestFramescLcLRestFramemUcOintgR(void *p = 0);
   static void *newArray_maplEconstsPRestFramescLcLRestFramemUcOintgR(Long_t size, void *p);
   static void delete_maplEconstsPRestFramescLcLRestFramemUcOintgR(void *p);
   static void deleteArray_maplEconstsPRestFramescLcLRestFramemUcOintgR(void *p);
   static void destruct_maplEconstsPRestFramescLcLRestFramemUcOintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<const RestFrames::RestFrame*,int>*)
   {
      map<const RestFrames::RestFrame*,int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<const RestFrames::RestFrame*,int>));
      static ::ROOT::TGenericClassInfo 
         instance("map<const RestFrames::RestFrame*,int>", -2, "map", 96,
                  typeid(map<const RestFrames::RestFrame*,int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEconstsPRestFramescLcLRestFramemUcOintgR_Dictionary, isa_proxy, 0,
                  sizeof(map<const RestFrames::RestFrame*,int>) );
      instance.SetNew(&new_maplEconstsPRestFramescLcLRestFramemUcOintgR);
      instance.SetNewArray(&newArray_maplEconstsPRestFramescLcLRestFramemUcOintgR);
      instance.SetDelete(&delete_maplEconstsPRestFramescLcLRestFramemUcOintgR);
      instance.SetDeleteArray(&deleteArray_maplEconstsPRestFramescLcLRestFramemUcOintgR);
      instance.SetDestructor(&destruct_maplEconstsPRestFramescLcLRestFramemUcOintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<const RestFrames::RestFrame*,int> >()));

      ::ROOT::AddClassAlternate("map<const RestFrames::RestFrame*,int>","std::map<RestFrames::RestFrame const*, int, std::less<RestFrames::RestFrame const*>, std::allocator<std::pair<RestFrames::RestFrame const* const, int> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<const RestFrames::RestFrame*,int>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEconstsPRestFramescLcLRestFramemUcOintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<const RestFrames::RestFrame*,int>*)0x0)->GetClass();
      maplEconstsPRestFramescLcLRestFramemUcOintgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEconstsPRestFramescLcLRestFramemUcOintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEconstsPRestFramescLcLRestFramemUcOintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<const RestFrames::RestFrame*,int> : new map<const RestFrames::RestFrame*,int>;
   }
   static void *newArray_maplEconstsPRestFramescLcLRestFramemUcOintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<const RestFrames::RestFrame*,int>[nElements] : new map<const RestFrames::RestFrame*,int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEconstsPRestFramescLcLRestFramemUcOintgR(void *p) {
      delete ((map<const RestFrames::RestFrame*,int>*)p);
   }
   static void deleteArray_maplEconstsPRestFramescLcLRestFramemUcOintgR(void *p) {
      delete [] ((map<const RestFrames::RestFrame*,int>*)p);
   }
   static void destruct_maplEconstsPRestFramescLcLRestFramemUcOintgR(void *p) {
      typedef map<const RestFrames::RestFrame*,int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<const RestFrames::RestFrame*,int>

namespace ROOT {
   static TClass *maplEconstsPRestFramescLcLRestFramemUcOboolgR_Dictionary();
   static void maplEconstsPRestFramescLcLRestFramemUcOboolgR_TClassManip(TClass*);
   static void *new_maplEconstsPRestFramescLcLRestFramemUcOboolgR(void *p = 0);
   static void *newArray_maplEconstsPRestFramescLcLRestFramemUcOboolgR(Long_t size, void *p);
   static void delete_maplEconstsPRestFramescLcLRestFramemUcOboolgR(void *p);
   static void deleteArray_maplEconstsPRestFramescLcLRestFramemUcOboolgR(void *p);
   static void destruct_maplEconstsPRestFramescLcLRestFramemUcOboolgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<const RestFrames::RestFrame*,bool>*)
   {
      map<const RestFrames::RestFrame*,bool> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<const RestFrames::RestFrame*,bool>));
      static ::ROOT::TGenericClassInfo 
         instance("map<const RestFrames::RestFrame*,bool>", -2, "map", 96,
                  typeid(map<const RestFrames::RestFrame*,bool>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEconstsPRestFramescLcLRestFramemUcOboolgR_Dictionary, isa_proxy, 0,
                  sizeof(map<const RestFrames::RestFrame*,bool>) );
      instance.SetNew(&new_maplEconstsPRestFramescLcLRestFramemUcOboolgR);
      instance.SetNewArray(&newArray_maplEconstsPRestFramescLcLRestFramemUcOboolgR);
      instance.SetDelete(&delete_maplEconstsPRestFramescLcLRestFramemUcOboolgR);
      instance.SetDeleteArray(&deleteArray_maplEconstsPRestFramescLcLRestFramemUcOboolgR);
      instance.SetDestructor(&destruct_maplEconstsPRestFramescLcLRestFramemUcOboolgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<const RestFrames::RestFrame*,bool> >()));

      ::ROOT::AddClassAlternate("map<const RestFrames::RestFrame*,bool>","std::map<RestFrames::RestFrame const*, bool, std::less<RestFrames::RestFrame const*>, std::allocator<std::pair<RestFrames::RestFrame const* const, bool> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<const RestFrames::RestFrame*,bool>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEconstsPRestFramescLcLRestFramemUcOboolgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<const RestFrames::RestFrame*,bool>*)0x0)->GetClass();
      maplEconstsPRestFramescLcLRestFramemUcOboolgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEconstsPRestFramescLcLRestFramemUcOboolgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEconstsPRestFramescLcLRestFramemUcOboolgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<const RestFrames::RestFrame*,bool> : new map<const RestFrames::RestFrame*,bool>;
   }
   static void *newArray_maplEconstsPRestFramescLcLRestFramemUcOboolgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<const RestFrames::RestFrame*,bool>[nElements] : new map<const RestFrames::RestFrame*,bool>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEconstsPRestFramescLcLRestFramemUcOboolgR(void *p) {
      delete ((map<const RestFrames::RestFrame*,bool>*)p);
   }
   static void deleteArray_maplEconstsPRestFramescLcLRestFramemUcOboolgR(void *p) {
      delete [] ((map<const RestFrames::RestFrame*,bool>*)p);
   }
   static void destruct_maplEconstsPRestFramescLcLRestFramemUcOboolgR(void *p) {
      typedef map<const RestFrames::RestFrame*,bool> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<const RestFrames::RestFrame*,bool>

namespace ROOT {
   static TClass *maplEconstsPRestFramescLcLRestFramemUcOTVector3gR_Dictionary();
   static void maplEconstsPRestFramescLcLRestFramemUcOTVector3gR_TClassManip(TClass*);
   static void *new_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR(void *p = 0);
   static void *newArray_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR(Long_t size, void *p);
   static void delete_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR(void *p);
   static void deleteArray_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR(void *p);
   static void destruct_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<const RestFrames::RestFrame*,TVector3>*)
   {
      map<const RestFrames::RestFrame*,TVector3> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<const RestFrames::RestFrame*,TVector3>));
      static ::ROOT::TGenericClassInfo 
         instance("map<const RestFrames::RestFrame*,TVector3>", -2, "map", 96,
                  typeid(map<const RestFrames::RestFrame*,TVector3>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEconstsPRestFramescLcLRestFramemUcOTVector3gR_Dictionary, isa_proxy, 0,
                  sizeof(map<const RestFrames::RestFrame*,TVector3>) );
      instance.SetNew(&new_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR);
      instance.SetNewArray(&newArray_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR);
      instance.SetDelete(&delete_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR);
      instance.SetDeleteArray(&deleteArray_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR);
      instance.SetDestructor(&destruct_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<const RestFrames::RestFrame*,TVector3> >()));

      ::ROOT::AddClassAlternate("map<const RestFrames::RestFrame*,TVector3>","std::map<RestFrames::RestFrame const*, TVector3, std::less<RestFrames::RestFrame const*>, std::allocator<std::pair<RestFrames::RestFrame const* const, TVector3> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<const RestFrames::RestFrame*,TVector3>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEconstsPRestFramescLcLRestFramemUcOTVector3gR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<const RestFrames::RestFrame*,TVector3>*)0x0)->GetClass();
      maplEconstsPRestFramescLcLRestFramemUcOTVector3gR_TClassManip(theClass);
   return theClass;
   }

   static void maplEconstsPRestFramescLcLRestFramemUcOTVector3gR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<const RestFrames::RestFrame*,TVector3> : new map<const RestFrames::RestFrame*,TVector3>;
   }
   static void *newArray_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<const RestFrames::RestFrame*,TVector3>[nElements] : new map<const RestFrames::RestFrame*,TVector3>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR(void *p) {
      delete ((map<const RestFrames::RestFrame*,TVector3>*)p);
   }
   static void deleteArray_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR(void *p) {
      delete [] ((map<const RestFrames::RestFrame*,TVector3>*)p);
   }
   static void destruct_maplEconstsPRestFramescLcLRestFramemUcOTVector3gR(void *p) {
      typedef map<const RestFrames::RestFrame*,TVector3> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<const RestFrames::RestFrame*,TVector3>

namespace ROOT {
   static TClass *maplEconstsPRestFramescLcLJigsawmUcOintgR_Dictionary();
   static void maplEconstsPRestFramescLcLJigsawmUcOintgR_TClassManip(TClass*);
   static void *new_maplEconstsPRestFramescLcLJigsawmUcOintgR(void *p = 0);
   static void *newArray_maplEconstsPRestFramescLcLJigsawmUcOintgR(Long_t size, void *p);
   static void delete_maplEconstsPRestFramescLcLJigsawmUcOintgR(void *p);
   static void deleteArray_maplEconstsPRestFramescLcLJigsawmUcOintgR(void *p);
   static void destruct_maplEconstsPRestFramescLcLJigsawmUcOintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<const RestFrames::Jigsaw*,int>*)
   {
      map<const RestFrames::Jigsaw*,int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<const RestFrames::Jigsaw*,int>));
      static ::ROOT::TGenericClassInfo 
         instance("map<const RestFrames::Jigsaw*,int>", -2, "map", 96,
                  typeid(map<const RestFrames::Jigsaw*,int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEconstsPRestFramescLcLJigsawmUcOintgR_Dictionary, isa_proxy, 0,
                  sizeof(map<const RestFrames::Jigsaw*,int>) );
      instance.SetNew(&new_maplEconstsPRestFramescLcLJigsawmUcOintgR);
      instance.SetNewArray(&newArray_maplEconstsPRestFramescLcLJigsawmUcOintgR);
      instance.SetDelete(&delete_maplEconstsPRestFramescLcLJigsawmUcOintgR);
      instance.SetDeleteArray(&deleteArray_maplEconstsPRestFramescLcLJigsawmUcOintgR);
      instance.SetDestructor(&destruct_maplEconstsPRestFramescLcLJigsawmUcOintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<const RestFrames::Jigsaw*,int> >()));

      ::ROOT::AddClassAlternate("map<const RestFrames::Jigsaw*,int>","std::map<RestFrames::Jigsaw const*, int, std::less<RestFrames::Jigsaw const*>, std::allocator<std::pair<RestFrames::Jigsaw const* const, int> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<const RestFrames::Jigsaw*,int>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEconstsPRestFramescLcLJigsawmUcOintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<const RestFrames::Jigsaw*,int>*)0x0)->GetClass();
      maplEconstsPRestFramescLcLJigsawmUcOintgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEconstsPRestFramescLcLJigsawmUcOintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEconstsPRestFramescLcLJigsawmUcOintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<const RestFrames::Jigsaw*,int> : new map<const RestFrames::Jigsaw*,int>;
   }
   static void *newArray_maplEconstsPRestFramescLcLJigsawmUcOintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<const RestFrames::Jigsaw*,int>[nElements] : new map<const RestFrames::Jigsaw*,int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEconstsPRestFramescLcLJigsawmUcOintgR(void *p) {
      delete ((map<const RestFrames::Jigsaw*,int>*)p);
   }
   static void deleteArray_maplEconstsPRestFramescLcLJigsawmUcOintgR(void *p) {
      delete [] ((map<const RestFrames::Jigsaw*,int>*)p);
   }
   static void destruct_maplEconstsPRestFramescLcLJigsawmUcOintgR(void *p) {
      typedef map<const RestFrames::Jigsaw*,int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<const RestFrames::Jigsaw*,int>

namespace ROOT {
   static TClass *maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR_Dictionary();
   static void maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR_TClassManip(TClass*);
   static void *new_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR(void *p = 0);
   static void *newArray_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR(Long_t size, void *p);
   static void delete_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR(void *p);
   static void deleteArray_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR(void *p);
   static void destruct_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<const RestFrames::HistPlotCategory*,vector<TH2D*> >*)
   {
      map<const RestFrames::HistPlotCategory*,vector<TH2D*> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<const RestFrames::HistPlotCategory*,vector<TH2D*> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<const RestFrames::HistPlotCategory*,vector<TH2D*> >", -2, "map", 96,
                  typeid(map<const RestFrames::HistPlotCategory*,vector<TH2D*> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<const RestFrames::HistPlotCategory*,vector<TH2D*> >) );
      instance.SetNew(&new_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR);
      instance.SetNewArray(&newArray_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR);
      instance.SetDelete(&delete_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR);
      instance.SetDestructor(&destruct_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<const RestFrames::HistPlotCategory*,vector<TH2D*> > >()));

      ::ROOT::AddClassAlternate("map<const RestFrames::HistPlotCategory*,vector<TH2D*> >","std::map<RestFrames::HistPlotCategory const*, std::vector<TH2D*, std::allocator<TH2D*> >, std::less<RestFrames::HistPlotCategory const*>, std::allocator<std::pair<RestFrames::HistPlotCategory const* const, std::vector<TH2D*, std::allocator<TH2D*> > > > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<const RestFrames::HistPlotCategory*,vector<TH2D*> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<const RestFrames::HistPlotCategory*,vector<TH2D*> >*)0x0)->GetClass();
      maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<const RestFrames::HistPlotCategory*,vector<TH2D*> > : new map<const RestFrames::HistPlotCategory*,vector<TH2D*> >;
   }
   static void *newArray_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<const RestFrames::HistPlotCategory*,vector<TH2D*> >[nElements] : new map<const RestFrames::HistPlotCategory*,vector<TH2D*> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR(void *p) {
      delete ((map<const RestFrames::HistPlotCategory*,vector<TH2D*> >*)p);
   }
   static void deleteArray_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR(void *p) {
      delete [] ((map<const RestFrames::HistPlotCategory*,vector<TH2D*> >*)p);
   }
   static void destruct_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH2DmUgRsPgR(void *p) {
      typedef map<const RestFrames::HistPlotCategory*,vector<TH2D*> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<const RestFrames::HistPlotCategory*,vector<TH2D*> >

namespace ROOT {
   static TClass *maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR_Dictionary();
   static void maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR_TClassManip(TClass*);
   static void *new_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR(void *p = 0);
   static void *newArray_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR(Long_t size, void *p);
   static void delete_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR(void *p);
   static void deleteArray_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR(void *p);
   static void destruct_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<const RestFrames::HistPlotCategory*,vector<TH1D*> >*)
   {
      map<const RestFrames::HistPlotCategory*,vector<TH1D*> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<const RestFrames::HistPlotCategory*,vector<TH1D*> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<const RestFrames::HistPlotCategory*,vector<TH1D*> >", -2, "map", 96,
                  typeid(map<const RestFrames::HistPlotCategory*,vector<TH1D*> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<const RestFrames::HistPlotCategory*,vector<TH1D*> >) );
      instance.SetNew(&new_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR);
      instance.SetNewArray(&newArray_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR);
      instance.SetDelete(&delete_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR);
      instance.SetDestructor(&destruct_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<const RestFrames::HistPlotCategory*,vector<TH1D*> > >()));

      ::ROOT::AddClassAlternate("map<const RestFrames::HistPlotCategory*,vector<TH1D*> >","std::map<RestFrames::HistPlotCategory const*, std::vector<TH1D*, std::allocator<TH1D*> >, std::less<RestFrames::HistPlotCategory const*>, std::allocator<std::pair<RestFrames::HistPlotCategory const* const, std::vector<TH1D*, std::allocator<TH1D*> > > > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<const RestFrames::HistPlotCategory*,vector<TH1D*> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<const RestFrames::HistPlotCategory*,vector<TH1D*> >*)0x0)->GetClass();
      maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<const RestFrames::HistPlotCategory*,vector<TH1D*> > : new map<const RestFrames::HistPlotCategory*,vector<TH1D*> >;
   }
   static void *newArray_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<const RestFrames::HistPlotCategory*,vector<TH1D*> >[nElements] : new map<const RestFrames::HistPlotCategory*,vector<TH1D*> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR(void *p) {
      delete ((map<const RestFrames::HistPlotCategory*,vector<TH1D*> >*)p);
   }
   static void deleteArray_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR(void *p) {
      delete [] ((map<const RestFrames::HistPlotCategory*,vector<TH1D*> >*)p);
   }
   static void destruct_maplEconstsPRestFramescLcLHistPlotCategorymUcOvectorlETH1DmUgRsPgR(void *p) {
      typedef map<const RestFrames::HistPlotCategory*,vector<TH1D*> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<const RestFrames::HistPlotCategory*,vector<TH1D*> >

namespace ROOT {
   static TClass *maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR_Dictionary();
   static void maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR_TClassManip(TClass*);
   static void *new_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p = 0);
   static void *newArray_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(Long_t size, void *p);
   static void delete_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p);
   static void deleteArray_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p);
   static void destruct_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >*)
   {
      map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >", -2, "map", 96,
                  typeid(map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >) );
      instance.SetNew(&new_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR);
      instance.SetNewArray(&newArray_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR);
      instance.SetDelete(&delete_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR);
      instance.SetDestructor(&destruct_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> > >()));

      ::ROOT::AddClassAlternate("map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >","std::map<TH2D*, std::pair<RestFrames::HistPlotVar const*, RestFrames::HistPlotVar const*>, std::less<TH2D*>, std::allocator<std::pair<TH2D* const, std::pair<RestFrames::HistPlotVar const*, RestFrames::HistPlotVar const*> > > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >*)0x0)->GetClass();
      maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> > : new map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >;
   }
   static void *newArray_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >[nElements] : new map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p) {
      delete ((map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >*)p);
   }
   static void deleteArray_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p) {
      delete [] ((map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >*)p);
   }
   static void destruct_maplETH2DmUcOpairlEconstsPRestFramescLcLHistPlotVarmUcOconstsPRestFramescLcLHistPlotVarmUgRsPgR(void *p) {
      typedef map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<TH2D*,pair<const RestFrames::HistPlotVar*,const RestFrames::HistPlotVar*> >

namespace ROOT {
   static TClass *maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR_Dictionary();
   static void maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR_TClassManip(TClass*);
   static void *new_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR(void *p = 0);
   static void *newArray_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR(Long_t size, void *p);
   static void delete_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR(void *p);
   static void deleteArray_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR(void *p);
   static void destruct_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<TH1D*,const RestFrames::HistPlotVar*>*)
   {
      map<TH1D*,const RestFrames::HistPlotVar*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<TH1D*,const RestFrames::HistPlotVar*>));
      static ::ROOT::TGenericClassInfo 
         instance("map<TH1D*,const RestFrames::HistPlotVar*>", -2, "map", 96,
                  typeid(map<TH1D*,const RestFrames::HistPlotVar*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR_Dictionary, isa_proxy, 0,
                  sizeof(map<TH1D*,const RestFrames::HistPlotVar*>) );
      instance.SetNew(&new_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR);
      instance.SetNewArray(&newArray_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR);
      instance.SetDelete(&delete_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR);
      instance.SetDeleteArray(&deleteArray_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR);
      instance.SetDestructor(&destruct_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<TH1D*,const RestFrames::HistPlotVar*> >()));

      ::ROOT::AddClassAlternate("map<TH1D*,const RestFrames::HistPlotVar*>","std::map<TH1D*, RestFrames::HistPlotVar const*, std::less<TH1D*>, std::allocator<std::pair<TH1D* const, RestFrames::HistPlotVar const*> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<TH1D*,const RestFrames::HistPlotVar*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<TH1D*,const RestFrames::HistPlotVar*>*)0x0)->GetClass();
      maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR_TClassManip(theClass);
   return theClass;
   }

   static void maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<TH1D*,const RestFrames::HistPlotVar*> : new map<TH1D*,const RestFrames::HistPlotVar*>;
   }
   static void *newArray_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<TH1D*,const RestFrames::HistPlotVar*>[nElements] : new map<TH1D*,const RestFrames::HistPlotVar*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR(void *p) {
      delete ((map<TH1D*,const RestFrames::HistPlotVar*>*)p);
   }
   static void deleteArray_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR(void *p) {
      delete [] ((map<TH1D*,const RestFrames::HistPlotVar*>*)p);
   }
   static void destruct_maplETH1DmUcOconstsPRestFramescLcLHistPlotVarmUgR(void *p) {
      typedef map<TH1D*,const RestFrames::HistPlotVar*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<TH1D*,const RestFrames::HistPlotVar*>

namespace ROOT {
   static TClass *maplERestFramescLcLLogTypecOstringgR_Dictionary();
   static void maplERestFramescLcLLogTypecOstringgR_TClassManip(TClass*);
   static void *new_maplERestFramescLcLLogTypecOstringgR(void *p = 0);
   static void *newArray_maplERestFramescLcLLogTypecOstringgR(Long_t size, void *p);
   static void delete_maplERestFramescLcLLogTypecOstringgR(void *p);
   static void deleteArray_maplERestFramescLcLLogTypecOstringgR(void *p);
   static void destruct_maplERestFramescLcLLogTypecOstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<RestFrames::LogType,string>*)
   {
      map<RestFrames::LogType,string> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<RestFrames::LogType,string>));
      static ::ROOT::TGenericClassInfo 
         instance("map<RestFrames::LogType,string>", -2, "map", 96,
                  typeid(map<RestFrames::LogType,string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplERestFramescLcLLogTypecOstringgR_Dictionary, isa_proxy, 0,
                  sizeof(map<RestFrames::LogType,string>) );
      instance.SetNew(&new_maplERestFramescLcLLogTypecOstringgR);
      instance.SetNewArray(&newArray_maplERestFramescLcLLogTypecOstringgR);
      instance.SetDelete(&delete_maplERestFramescLcLLogTypecOstringgR);
      instance.SetDeleteArray(&deleteArray_maplERestFramescLcLLogTypecOstringgR);
      instance.SetDestructor(&destruct_maplERestFramescLcLLogTypecOstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<RestFrames::LogType,string> >()));

      ::ROOT::AddClassAlternate("map<RestFrames::LogType,string>","std::map<RestFrames::LogType, std::string, std::less<RestFrames::LogType>, std::allocator<std::pair<RestFrames::LogType const, std::string> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<RestFrames::LogType,string>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplERestFramescLcLLogTypecOstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<RestFrames::LogType,string>*)0x0)->GetClass();
      maplERestFramescLcLLogTypecOstringgR_TClassManip(theClass);
   return theClass;
   }

   static void maplERestFramescLcLLogTypecOstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplERestFramescLcLLogTypecOstringgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<RestFrames::LogType,string> : new map<RestFrames::LogType,string>;
   }
   static void *newArray_maplERestFramescLcLLogTypecOstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<RestFrames::LogType,string>[nElements] : new map<RestFrames::LogType,string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplERestFramescLcLLogTypecOstringgR(void *p) {
      delete ((map<RestFrames::LogType,string>*)p);
   }
   static void deleteArray_maplERestFramescLcLLogTypecOstringgR(void *p) {
      delete [] ((map<RestFrames::LogType,string>*)p);
   }
   static void destruct_maplERestFramescLcLLogTypecOstringgR(void *p) {
      typedef map<RestFrames::LogType,string> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<RestFrames::LogType,string>

namespace ROOT {
   static TClass *maplERestFramescLcLFrameTypecOintgR_Dictionary();
   static void maplERestFramescLcLFrameTypecOintgR_TClassManip(TClass*);
   static void *new_maplERestFramescLcLFrameTypecOintgR(void *p = 0);
   static void *newArray_maplERestFramescLcLFrameTypecOintgR(Long_t size, void *p);
   static void delete_maplERestFramescLcLFrameTypecOintgR(void *p);
   static void deleteArray_maplERestFramescLcLFrameTypecOintgR(void *p);
   static void destruct_maplERestFramescLcLFrameTypecOintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<RestFrames::FrameType,int>*)
   {
      map<RestFrames::FrameType,int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<RestFrames::FrameType,int>));
      static ::ROOT::TGenericClassInfo 
         instance("map<RestFrames::FrameType,int>", -2, "map", 96,
                  typeid(map<RestFrames::FrameType,int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplERestFramescLcLFrameTypecOintgR_Dictionary, isa_proxy, 0,
                  sizeof(map<RestFrames::FrameType,int>) );
      instance.SetNew(&new_maplERestFramescLcLFrameTypecOintgR);
      instance.SetNewArray(&newArray_maplERestFramescLcLFrameTypecOintgR);
      instance.SetDelete(&delete_maplERestFramescLcLFrameTypecOintgR);
      instance.SetDeleteArray(&deleteArray_maplERestFramescLcLFrameTypecOintgR);
      instance.SetDestructor(&destruct_maplERestFramescLcLFrameTypecOintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<RestFrames::FrameType,int> >()));

      ::ROOT::AddClassAlternate("map<RestFrames::FrameType,int>","std::map<RestFrames::FrameType, int, std::less<RestFrames::FrameType>, std::allocator<std::pair<RestFrames::FrameType const, int> > >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<RestFrames::FrameType,int>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplERestFramescLcLFrameTypecOintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<RestFrames::FrameType,int>*)0x0)->GetClass();
      maplERestFramescLcLFrameTypecOintgR_TClassManip(theClass);
   return theClass;
   }

   static void maplERestFramescLcLFrameTypecOintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplERestFramescLcLFrameTypecOintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<RestFrames::FrameType,int> : new map<RestFrames::FrameType,int>;
   }
   static void *newArray_maplERestFramescLcLFrameTypecOintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<RestFrames::FrameType,int>[nElements] : new map<RestFrames::FrameType,int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplERestFramescLcLFrameTypecOintgR(void *p) {
      delete ((map<RestFrames::FrameType,int>*)p);
   }
   static void deleteArray_maplERestFramescLcLFrameTypecOintgR(void *p) {
      delete [] ((map<RestFrames::FrameType,int>*)p);
   }
   static void destruct_maplERestFramescLcLFrameTypecOintgR(void *p) {
      typedef map<RestFrames::FrameType,int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<RestFrames::FrameType,int>

namespace {
  void TriggerDictionaryInitialization_libRestFrames_Impl() {
    static const char* headers[] = {
"../include/RFKey.hh",
"../include/RFCharge.hh",
"../include/RFPlot.hh",
"../include/RFBase.hh",
"../include/RFLog.hh",
"../include/RestFrame.hh",
"../include/ReconstructionFrame.hh",
"../include/GeneratorFrame.hh",
"../include/LabFrame.hh",
"../include/DecayFrame.hh",
"../include/VisibleFrame.hh",
"../include/InvisibleFrame.hh",
"../include/LabRecoFrame.hh",
"../include/DecayRecoFrame.hh",
"../include/VisibleRecoFrame.hh",
"../include/InvisibleRecoFrame.hh",
"../include/SelfAssemblingRecoFrame.hh",
"../include/LabGenFrame.hh",
"../include/DecayGenFrame.hh",
"../include/VisibleGenFrame.hh",
"../include/InvisibleGenFrame.hh",
"../include/ResonanceGenFrame.hh",
"../include/ppLabGenFrame.hh",
"../include/State.hh",
"../include/VisibleState.hh",
"../include/InvisibleState.hh",
"../include/CombinatoricState.hh",
"../include/Group.hh",
"../include/InvisibleGroup.hh",
"../include/CombinatoricGroup.hh",
"../include/Jigsaw.hh",
"../include/InvisibleJigsaw.hh",
"../include/CombinatoricJigsaw.hh",
"../include/SetMassInvJigsaw.hh",
"../include/SetRapidityInvJigsaw.hh",
"../include/ContraBoostInvJigsaw.hh",
"../include/CombinedCBInvJigsaw.hh",
"../include/MinMassDiffInvJigsaw.hh",
"../include/MinMassesSqInvJigsaw.hh",
"../include/MaxProbBreitWignerInvJigsaw.hh",
"../include/MinMassesCombJigsaw.hh",
"../include/MinMassChi2CombJigsaw.hh",
"../include/MaxProbBreitWignerCombJigsaw.hh",
"../include/MinMassDiffCombJigsaw.hh",
"../include/MinMassesSqCombJigsaw.hh",
"../include/TreePlot.hh",
"../include/TreePlotNode.hh",
"../include/TreePlotLink.hh",
"../include/HistPlotVar.hh",
"../include/HistPlotCategory.hh",
"../include/HistPlot.hh",
"../include/RFList.hh",
0
    };
    static const char* includePaths[] = {
"../inc",
"/usr/../include/root",
"/usr/../include/root",
"/eos/home-d/dplotnik/../include/../include/src/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libRestFrames dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/RFKey.hh")))  RFKey;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/RFCharge.hh")))  RFCharge;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/RestFrame.hh")))  RestFrame;}
namespace RestFrames{template <class T> class __attribute__((annotate("$clingAutoload$../include/RFList.hh")))  __attribute__((annotate("$clingAutoload$../include/RFPlot.hh")))  RFList;
}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/Group.hh")))  __attribute__((annotate("$clingAutoload$../include/ReconstructionFrame.hh")))  Group;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/Jigsaw.hh")))  __attribute__((annotate("$clingAutoload$../include/SelfAssemblingRecoFrame.hh")))  Jigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/HistPlotVar.hh")))  HistPlotVar;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/HistPlotCategory.hh")))  HistPlotCategory;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/RFLog.hh")))  __attribute__((annotate("$clingAutoload$../include/RFPlot.hh")))  RFLog;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/RFBase.hh")))  __attribute__((annotate("$clingAutoload$../include/RFPlot.hh")))  RFBase;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/RFPlot.hh")))  RFPlot;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/LabRecoFrame.hh")))  LabRecoFrame;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/DecayRecoFrame.hh")))  DecayRecoFrame;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/VisibleRecoFrame.hh")))  VisibleRecoFrame;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/InvisibleRecoFrame.hh")))  InvisibleRecoFrame;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/SelfAssemblingRecoFrame.hh")))  SelfAssemblingRecoFrame;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/LabGenFrame.hh")))  LabGenFrame;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/DecayGenFrame.hh")))  DecayGenFrame;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/VisibleGenFrame.hh")))  VisibleGenFrame;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/InvisibleGenFrame.hh")))  InvisibleGenFrame;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/ResonanceGenFrame.hh")))  ResonanceGenFrame;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/ppLabGenFrame.hh")))  ppLabGenFrame;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/InvisibleGroup.hh")))  InvisibleGroup;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/CombinatoricGroup.hh")))  CombinatoricGroup;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/InvisibleJigsaw.hh")))  InvisibleJigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/CombinatoricJigsaw.hh")))  CombinatoricJigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/SetMassInvJigsaw.hh")))  SetMassInvJigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/SetRapidityInvJigsaw.hh")))  SetRapidityInvJigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/ContraBoostInvJigsaw.hh")))  ContraBoostInvJigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/CombinedCBInvJigsaw.hh")))  CombinedCBInvJigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/MinMassDiffInvJigsaw.hh")))  MinMassDiffInvJigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/MinMassesSqInvJigsaw.hh")))  MinMassesSqInvJigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/MaxProbBreitWignerInvJigsaw.hh")))  MaxProbBreitWignerInvJigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/MinMassesCombJigsaw.hh")))  MinMassesCombJigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/MinMassChi2CombJigsaw.hh")))  MinMassChi2CombJigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/MaxProbBreitWignerCombJigsaw.hh")))  MaxProbBreitWignerCombJigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/MinMassDiffCombJigsaw.hh")))  MinMassDiffCombJigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/MinMassesSqCombJigsaw.hh")))  MinMassesSqCombJigsaw;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/TreePlot.hh")))  TreePlot;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/TreePlotNode.hh")))  TreePlotNode;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/TreePlotLink.hh")))  TreePlotLink;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/HistPlot.hh")))  HistPlot;}
namespace RestFrames{typedef RestFrames::RFList<RFBase> RFBaseList __attribute__((annotate("$clingAutoload$../include/RFList.hh")))  __attribute__((annotate("$clingAutoload$../include/RFPlot.hh"))) ;}
namespace RestFrames{typedef RestFrames::RFList<RestFrame> RestFrameList __attribute__((annotate("$clingAutoload$../include/RFList.hh")))  __attribute__((annotate("$clingAutoload$../include/RFPlot.hh"))) ;}
namespace RestFrames{typedef RestFrames::RFList<const RestFrame> ConstRestFrameList __attribute__((annotate("$clingAutoload$../include/RFList.hh")))  __attribute__((annotate("$clingAutoload$../include/RFPlot.hh"))) ;}
namespace RestFrames{typedef RestFrames::RFList<Group> GroupList __attribute__((annotate("$clingAutoload$../include/RFList.hh")))  __attribute__((annotate("$clingAutoload$../include/RFPlot.hh"))) ;}
namespace RestFrames{typedef RestFrames::RFList<const Group> ConstGroupList __attribute__((annotate("$clingAutoload$../include/RFList.hh")))  __attribute__((annotate("$clingAutoload$../include/RFPlot.hh"))) ;}
namespace RestFrames{typedef RestFrames::RFList<Jigsaw> JigsawList __attribute__((annotate("$clingAutoload$../include/RFList.hh")))  __attribute__((annotate("$clingAutoload$../include/RFPlot.hh"))) ;}
namespace RestFrames{typedef RestFrames::RFList<const Jigsaw> ConstJigsawList __attribute__((annotate("$clingAutoload$../include/RFList.hh")))  __attribute__((annotate("$clingAutoload$../include/RFPlot.hh"))) ;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/State.hh")))  __attribute__((annotate("$clingAutoload$../include/SelfAssemblingRecoFrame.hh")))  State;}
namespace RestFrames{typedef RestFrames::RFList<State> StateList __attribute__((annotate("$clingAutoload$../include/RFList.hh")))  __attribute__((annotate("$clingAutoload$../include/RFPlot.hh"))) ;}
namespace RestFrames{class __attribute__((annotate("$clingAutoload$../include/VisibleState.hh")))  VisibleState;}
namespace RestFrames{typedef RestFrames::RFList<VisibleState> VisibleStateList __attribute__((annotate("$clingAutoload$../include/RFList.hh")))  __attribute__((annotate("$clingAutoload$../include/RFPlot.hh"))) ;}
namespace RestFrames{typedef RestFrames::RFList<HistPlotVar> HistPlotVarList __attribute__((annotate("$clingAutoload$../include/RFList.hh")))  __attribute__((annotate("$clingAutoload$../include/RFPlot.hh"))) ;}
namespace RestFrames{typedef RestFrames::RFList<HistPlotCategory> HistPlotCatList __attribute__((annotate("$clingAutoload$../include/RFList.hh")))  __attribute__((annotate("$clingAutoload$../include/RFPlot.hh"))) ;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libRestFrames dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "../include/RFKey.hh"
#include "../include/RFCharge.hh"
#include "../include/RFPlot.hh"
#include "../include/RFBase.hh"
#include "../include/RFLog.hh"
#include "../include/RestFrame.hh"
#include "../include/ReconstructionFrame.hh"
#include "../include/GeneratorFrame.hh"
#include "../include/LabFrame.hh"
#include "../include/DecayFrame.hh"
#include "../include/VisibleFrame.hh"
#include "../include/InvisibleFrame.hh"
#include "../include/LabRecoFrame.hh"
#include "../include/DecayRecoFrame.hh"
#include "../include/VisibleRecoFrame.hh"
#include "../include/InvisibleRecoFrame.hh"
#include "../include/SelfAssemblingRecoFrame.hh"
#include "../include/LabGenFrame.hh"
#include "../include/DecayGenFrame.hh"
#include "../include/VisibleGenFrame.hh"
#include "../include/InvisibleGenFrame.hh"
#include "../include/ResonanceGenFrame.hh"
#include "../include/ppLabGenFrame.hh"
#include "../include/State.hh"
#include "../include/VisibleState.hh"
#include "../include/InvisibleState.hh"
#include "../include/CombinatoricState.hh"
#include "../include/Group.hh"
#include "../include/InvisibleGroup.hh"
#include "../include/CombinatoricGroup.hh"
#include "../include/Jigsaw.hh"
#include "../include/InvisibleJigsaw.hh"
#include "../include/CombinatoricJigsaw.hh"
#include "../include/SetMassInvJigsaw.hh"
#include "../include/SetRapidityInvJigsaw.hh"
#include "../include/ContraBoostInvJigsaw.hh"
#include "../include/CombinedCBInvJigsaw.hh"
#include "../include/MinMassDiffInvJigsaw.hh"
#include "../include/MinMassesSqInvJigsaw.hh"
#include "../include/MaxProbBreitWignerInvJigsaw.hh"
#include "../include/MinMassesCombJigsaw.hh"
#include "../include/MinMassChi2CombJigsaw.hh"
#include "../include/MaxProbBreitWignerCombJigsaw.hh"
#include "../include/MinMassDiffCombJigsaw.hh"
#include "../include/MinMassesSqCombJigsaw.hh"
#include "../include/TreePlot.hh"
#include "../include/TreePlotNode.hh"
#include "../include/TreePlotLink.hh"
#include "../include/HistPlotVar.hh"
#include "../include/HistPlotCategory.hh"
#include "../include/HistPlot.hh"
#include "../include/RFList.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"RestFrames::CombinatoricGroup", payloadCode, "@",
"RestFrames::CombinatoricJigsaw", payloadCode, "@",
"RestFrames::CombinedCBInvJigsaw", payloadCode, "@",
"RestFrames::ConstGroupList", payloadCode, "@",
"RestFrames::ConstJigsawList", payloadCode, "@",
"RestFrames::ConstRestFrameList", payloadCode, "@",
"RestFrames::ContraBoostInvJigsaw", payloadCode, "@",
"RestFrames::DecayGenFrame", payloadCode, "@",
"RestFrames::DecayRecoFrame", payloadCode, "@",
"RestFrames::Group", payloadCode, "@",
"RestFrames::GroupList", payloadCode, "@",
"RestFrames::HistPlot", payloadCode, "@",
"RestFrames::HistPlotCatList", payloadCode, "@",
"RestFrames::HistPlotCategory", payloadCode, "@",
"RestFrames::HistPlotVar", payloadCode, "@",
"RestFrames::HistPlotVarList", payloadCode, "@",
"RestFrames::InvisibleGenFrame", payloadCode, "@",
"RestFrames::InvisibleGroup", payloadCode, "@",
"RestFrames::InvisibleJigsaw", payloadCode, "@",
"RestFrames::InvisibleRecoFrame", payloadCode, "@",
"RestFrames::Jigsaw", payloadCode, "@",
"RestFrames::JigsawList", payloadCode, "@",
"RestFrames::LabGenFrame", payloadCode, "@",
"RestFrames::LabRecoFrame", payloadCode, "@",
"RestFrames::LogType", payloadCode, "@",
"RestFrames::MaxProbBreitWignerCombJigsaw", payloadCode, "@",
"RestFrames::MaxProbBreitWignerInvJigsaw", payloadCode, "@",
"RestFrames::MinMassChi2CombJigsaw", payloadCode, "@",
"RestFrames::MinMassDiffCombJigsaw", payloadCode, "@",
"RestFrames::MinMassDiffInvJigsaw", payloadCode, "@",
"RestFrames::MinMassesCombJigsaw", payloadCode, "@",
"RestFrames::MinMassesSqCombJigsaw", payloadCode, "@",
"RestFrames::MinMassesSqInvJigsaw", payloadCode, "@",
"RestFrames::RFBase", payloadCode, "@",
"RestFrames::RFBaseList", payloadCode, "@",
"RestFrames::RFCharge", payloadCode, "@",
"RestFrames::RFKey", payloadCode, "@",
"RestFrames::RFList<RestFrames::Group>", payloadCode, "@",
"RestFrames::RFList<RestFrames::HistPlotCategory>", payloadCode, "@",
"RestFrames::RFList<RestFrames::HistPlotVar>", payloadCode, "@",
"RestFrames::RFList<RestFrames::Jigsaw>", payloadCode, "@",
"RestFrames::RFList<RestFrames::RestFrame>", payloadCode, "@",
"RestFrames::RFList<const RestFrames::Group>", payloadCode, "@",
"RestFrames::RFList<const RestFrames::HistPlotCategory>", payloadCode, "@",
"RestFrames::RFList<const RestFrames::Jigsaw>", payloadCode, "@",
"RestFrames::RFList<const RestFrames::RestFrame>", payloadCode, "@",
"RestFrames::RFLog", payloadCode, "@",
"RestFrames::RFPlot", payloadCode, "@",
"RestFrames::ResonanceGenFrame", payloadCode, "@",
"RestFrames::RestFrame", payloadCode, "@",
"RestFrames::RestFrameList", payloadCode, "@",
"RestFrames::RestFrameListList", payloadCode, "@",
"RestFrames::SelfAssemblingRecoFrame", payloadCode, "@",
"RestFrames::SetLogColor", payloadCode, "@",
"RestFrames::SetLogMaxWidth", payloadCode, "@",
"RestFrames::SetLogPrint", payloadCode, "@",
"RestFrames::SetMassInvJigsaw", payloadCode, "@",
"RestFrames::SetRapidityInvJigsaw", payloadCode, "@",
"RestFrames::SetStyle", payloadCode, "@",
"RestFrames::SetZPalette", payloadCode, "@",
"RestFrames::StateList", payloadCode, "@",
"RestFrames::StateListList", payloadCode, "@",
"RestFrames::TreePlot", payloadCode, "@",
"RestFrames::TreePlotLink", payloadCode, "@",
"RestFrames::TreePlotNode", payloadCode, "@",
"RestFrames::VisibleGenFrame", payloadCode, "@",
"RestFrames::VisibleRecoFrame", payloadCode, "@",
"RestFrames::VisibleStateList", payloadCode, "@",
"RestFrames::ppLabGenFrame", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libRestFrames",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libRestFrames_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libRestFrames_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libRestFrames() {
  TriggerDictionaryInitialization_libRestFrames_Impl();
}
