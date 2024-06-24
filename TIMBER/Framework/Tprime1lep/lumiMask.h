#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <limits>

/**
 * Luminosity mask (constructed from a list of good lumi block ranges, as in the DQM JSON files)
 *
 * adopted from CMSSW code (EventSkipperByID and LuminosityBlockRange) for the minimal case needed here
 */
class lumiMask {
 public:
  using Run = unsigned int;
  using LumiBlock = unsigned int;

  /**
   * Luminosity block range - helper struct
   */
  class LumiBlockRange {
  public:
    LumiBlockRange(Run run, LumiBlock firstLumi, LumiBlock lastLumi)
      : m_run(run), m_firstLumi(firstLumi),
      m_lastLumi(lastLumi ? lastLumi : std::numeric_limits<LumiBlock>::max())
	{}
    Run run() const { return m_run; }
    LumiBlock firstLumi() const { return m_firstLumi; }
    LumiBlock lastLumi () const { return m_lastLumi ; }
  private:
    Run m_run;
    LumiBlock m_firstLumi;
    LumiBlock m_lastLumi;
  };

  explicit lumiMask(const std::vector<LumiBlockRange>& accept)
    : m_accept(accept)
  {
    std::sort(m_accept.begin(), m_accept.end());
  }

  bool accept(Run run, LumiBlock lumi) const
  { return std::binary_search(m_accept.begin(), m_accept.end(), LumiBlockRange(run, lumi, lumi)); }

  static lumiMask fromJSON(const std::string& fileName, lumiMask::Run firstRun=0, lumiMask::Run lastRun=0);

 private:
  std::vector<LumiBlockRange> m_accept;
};

bool operator< ( const lumiMask::LumiBlockRange& lh, const lumiMask::LumiBlockRange& rh )
{
  return ( lh.run() == rh.run() ) ? ( lh.lastLumi() < rh.firstLumi() ) : lh.run() < rh.run();
}
