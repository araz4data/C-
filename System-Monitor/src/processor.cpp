#include "processor.h"
#include <string>
#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
  total = LinuxParser::Jiffies() ;
  idle  = LinuxParser::IdleJiffies() ;
  agg = (float) ( total - idle ) ;
  agg /= total ;
  return agg ;
}
