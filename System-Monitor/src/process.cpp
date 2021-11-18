#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { return Process::pid ; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { 
  vector<long> cpuUtilVect = LinuxParser::ActiveJiffies( Process::Pid() ) ;
  long int Hertz = sysconf( _SC_CLK_TCK ) ;
  long total = cpuUtilVect[0] + cpuUtilVect[1] + cpuUtilVect[2] + cpuUtilVect[3] ;
  long seconds = cpuUtilVect[5] - cpuUtilVect[4] / Hertz ;

  return  ( ( (float)total / (float)Hertz ) / (float) seconds ) ;
}

// TODO: Return the command that generated this process
string Process::Command() { return LinuxParser::Command(Process::Pid()) ; }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(Process::Pid()) ; }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(Process::Pid()) ; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(Process::Pid()) ; }

// TODO: Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const { 
//  if ( Process::CpuUtilization() < a.Process::CpuUtilization() ) return true ;
//  if ( this->pid < a.pid ) return true ;
  if ( this->cpuUtil < a.cpuUtil ) return true ;
  return false ;
}

void Process::SetPid( int pid_) { pid = pid_ ;  }
void Process::SetCpuUtil( float cpuUtil_) { cpuUtil = cpuUtil_ ;  }

