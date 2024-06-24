#include "../TIMBER/Framework/Tprime1lep/lumiMask.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <iostream>

lumiMask lumiMask::fromJSON(const std::string& file, lumiMask::Run firstRun, lumiMask::Run lastRun)
{
  const bool noRunFilter = ( firstRun == 0 ) && ( lastRun == 0 );
  boost::property_tree::ptree ptree;
  boost::property_tree::read_json(file, ptree);

  std::vector<lumiMask::LumiBlockRange> accept;
  for ( const auto& runEntry : ptree ) {
    const lumiMask::Run run = std::stoul(runEntry.first);
    if ( noRunFilter || ( ( firstRun <= run ) && ( run <= lastRun ) ) ) {
      for ( const auto& lrEntry : runEntry.second ) {
        const auto lrNd = lrEntry.second;
        if ( lrNd.size() != 2 ) {
	  std::cout << "ERROR: format should be run : list-of-lists, where each sublist has exactly two entries" << std::endl;
        } else {
          const lumiMask::LumiBlock firstLumi = std::stoul(lrNd.begin()->second.data());
          const lumiMask::LumiBlock lastLumi  = std::stoul((++lrNd.begin())->second.data());
          // std::cout << run << " : "<< firstLumi << "-" << lastLumi << std::endl;
          accept.emplace_back(run, firstLumi, lastLumi);
        }
      }
      // } else {
      //   std::cout << "Excluding run " << run << " (out of range " << firstRun << "-" << lastRun << ")" << std::endl;
    }
  }
  return lumiMask(accept);
}
