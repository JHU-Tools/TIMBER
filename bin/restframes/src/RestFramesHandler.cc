#include "../include/RestFramesHandler.hh"

using namespace ROOT::VecOps;

namespace RestFrames{

    void RestFramesHandler::initialize() {
        define_tree();

        if(LAB->InitializeTree())
            g_Log << LogInfo << "...Successfully initialized reconstruction trees" << LogEnd;
        else
            g_Log << LogError << "...Failed initializing reconstruction trees" << LogEnd;

        define_groups_jigsaws();

        if(LAB->InitializeAnalysis())
            g_Log << LogInfo << "...Successfully initialized analysis" << LogEnd;
        else
            g_Log << LogError << "...Failed initializing analysis" << LogEnd;
    }

    void RestFramesHandler::before_analysis() {
        rfh_lock.lock();
        LAB->ClearEvent();
    }

    void RestFramesHandler::after_analysis() {
        rfh_lock.unlock();
    }

    void RestFramesHandler::test() {
        g_Log << LogInfo << "Testing a rest frames handler object call, successful" << LogEnd;
    };

    RestFramesContainer::RestFramesContainer(int num_threads) {
        m_num_threads = num_threads;
    };

    void RestFramesContainer::initialize() {
        for (int i = 0; i < m_num_threads; ++i) {
            g_Log << LogInfo << "Instantiating RestFramesHandler of thread " << i << "..." << LogEnd;
            handler_slots.push_back(std::unique_ptr<RestFramesHandler>(create_handler()));
        }
    }



    RestFramesContainer::~RestFramesContainer() {
        for (auto i = handler_slots.begin(); i != handler_slots.end(); ++i) {
            i->reset();
        }
    }
    RestFramesHandler *RestFramesContainer::get_handler (int thread) {
        RestFramesHandler *rfh = (handler_slots[thread].get());
        return rfh;
    }

    void RestFramesContainer::test_all () {
        int iter_num = 1;
        for (auto i = handler_slots.begin(); i != handler_slots.end(); ++i) {
            g_Log << LogInfo << "--------------Now testing thread " << iter_num << "'s handler------------" << LogEnd;
            (*i)->test();
            iter_num++;
        }
        g_Log << LogInfo << "--------------All threads tested------------" << LogEnd;

    }
}