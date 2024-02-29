#ifndef RestFramesHandler_HH
#define RestFramesHandler_HH

#include "RestFrames.hh"

#include <TLorentzVector.h>
#include <TVector3.h>
#include <ROOT/RVec.hxx>
#include <algorithm>
#include <iostream>
#include <memory>
#include <mutex>
#include <random>

using namespace RestFrames;
using namespace ROOT::VecOps;

namespace RestFrames {
    class RestFramesHandler {

        private:
            std::mutex rfh_lock;

        protected:
            std::unique_ptr<LabRecoFrame> LAB;

            void before_analysis();
            void after_analysis();
            void initialize();

            virtual void define_tree() = 0;
            virtual void define_groups_jigsaws() = 0;

        public:
            // for testing
            void test();
    };


    class RestFramesContainer {
        private:
            int m_num_threads;
            std::vector<std::unique_ptr<RestFramesHandler>> handler_slots;
        
        protected:
            RestFramesHandler *get_handler(int thread);
            virtual RestFramesHandler *create_handler() = 0;

        public:
            RestFramesContainer(int num_threads);
            ~RestFramesContainer();
            void initialize();
            void test_all();
    };

}
#endif