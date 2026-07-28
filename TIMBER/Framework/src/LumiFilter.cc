#include "../include/LumiFilter.h"

LumiFilter::LumiFilter(std::string filename) {
    boost::property_tree::read_json(filename, ptree);
}

LumiFilter::LumiFilter(int year){
    if (year == 16 or year == 2016) {
        boost::property_tree::read_json(std::getenv("TIMBERPATH")+std::string("TIMBER/data/LumiJSON/Cert_271036-284044_13TeV_Legacy2016_Collisions16_JSON.txt"), ptree);
    } else if (year == 17 or year == 2017) {
        boost::property_tree::read_json(std::getenv("TIMBERPATH")+std::string("TIMBER/data/LumiJSON/Cert_294927-306462_13TeV_UL2017_Collisions17_GoldenJSON.txt"), ptree);
    } else if (year == 18 or year == 2018) {
        boost::property_tree::read_json(std::getenv("TIMBERPATH")+std::string("TIMBER/data/LumiJSON/Cert_314472-325175_13TeV_Legacy2018_Collisions18_JSON.txt"), ptree);
    } else if (year == 22 or year == 2022) {
        boost::property_tree::read_json(std::getenv("TIMBERPATH")+std::string("TIMBER/data/LumiJSON/Cert_Collisions2022_355100_362760_Golden.json"), ptree);
    } else if (year == 23 or year == 2023) {
        boost::property_tree::read_json(std::getenv("TIMBERPATH")+std::string("TIMBER/data/LumiJSON/Cert_Collisions2023_366442_370790_Golden.json"), ptree);
    } else if (year == 24 or year == 2024) {
        boost::property_tree::read_json(std::getenv("TIMBERPATH")+std::string("TIMBER/data/LumiJSON/Cert_Collisions2024_378981_386951_Golden.json"), ptree);
    } else {
        std::cout << "Year " << year << " not supported by LumiFilter" << std::endl;
        throw;
    }
}

LumiFilter::~LumiFilter() {
}

bool LumiFilter::eval(unsigned int run, unsigned int lumi) {
    bool out = false;
    for ( const auto& runEntry : ptree ) {
        if (std::stoul(runEntry.first) == run) {
            for ( const auto& lrEntry : runEntry.second ) {
                const auto lrNd = lrEntry.second;
                lumStart = std::stoul(lrNd.begin()->second.data());
                lumEnd = std::stoul((++lrNd.begin())->second.data());
                if ((lumi < lumEnd) && (lumi > lumStart)) {
                    out = true;
                }
            }
        }
    }
    return out;
}
