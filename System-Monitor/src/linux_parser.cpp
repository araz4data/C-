#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, kernel;
  string line;
  string version ;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() {
  int totalMem ;
  int freeMem ;
  float mem ;
  string line ;
  string str ;
  std::ifstream filestream( kMeminfoFilename ) ;

  if ( filestream.is_open() ) {
    while (std::getline(filestream, line ) ) {
      std::istringstream linestream( line ) ;
      linestream >> str >> mem ;
      if ( str.find("memTotal") != string::npos) totalMem = mem ;  
      if (str.find("memFree") != string::npos) freeMem = mem ;  
      
    }
   }
 return (float) (totalMem - freeMem) ; 
}

// TODO: Read and return the system uptime
long LinuxParser::UpTime() { 
  std::ifstream filestream( kProcDirectory + kUptimeFilename ) ;
  string line ;
  float up ;
  float idle ;
  if ( filestream.is_open() ) {
    std::getline(filestream, line ) ;
    std::istringstream linestream( line ) ;
    linestream >> up >> idle ;
  }
  return (long) up ;
}


// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { 
  vector<long> cpuUtilVect = LinuxParser::CpuUtilization() ; 
  return cpuUtilVect[6] ;
}

// TODO: Read and return the number of active jiffies for a PID
vector<long> LinuxParser::ActiveJiffies(int pid) {
  std::ifstream filestream( LinuxParser::kProcDirectory + to_string(pid) + LinuxParser::kStatFilename ) ;
  std::string line ;
  std::string str ;
  int tmp ;
  int total = 0 ;

  vector<long> cpuUtilVect ;

  if ( filestream.is_open() ) {
    std::string str ;
    std::getline(filestream, line ) ;
    std::istringstream linestream( line ) ;
    for ( int i = 0 ; i < 22 ; i++ ) {
      if ( (i >= 13 && i <= 16) || i == 21 ) {   
        linestream >> tmp ;
	total += tmp ;
        cpuUtilVect.push_back(tmp);
      } else {
        linestream >> str ;
      }
    }
  }

  cpuUtilVect.push_back( LinuxParser::UpTime() ) ;

  return cpuUtilVect ;
}


// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { 
  vector<long> cpuUtilVect = LinuxParser::CpuUtilization() ; 
  return cpuUtilVect[5] ;

}

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { 
  vector<long> cpuUtilVect = LinuxParser::CpuUtilization() ; 
  return cpuUtilVect[2] ;
}


// TODO: Read and return CPU utilization
vector<long> LinuxParser::CpuUtilization() { 
  std::ifstream filestream( LinuxParser::kProcDirectory + LinuxParser::kStatFilename ) ;
  std::string line ;
  std::string str ;
  int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice ;
  int virtal, total, active ;
  vector<long> cpuUtilVect ;
  if ( filestream.is_open() ) {
    std::string str ;
    std::getline(filestream, line ) ;
    std::istringstream linestream( line ) ;
    linestream >> str >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice ;

    user = user - guest ;   
    cpuUtilVect.push_back(user);
    nice = nice - guest_nice ; 
    cpuUtilVect.push_back(nice);
    idle = idle + iowait ;
    cpuUtilVect.push_back(idle);
    system = system + irq + softirq ;
    cpuUtilVect.push_back(system);
    virtal = guest + guest_nice ;
    cpuUtilVect.push_back(virtal);
    active  = user + nice + system + steal + virtal ;
    cpuUtilVect.push_back(active);

    total  = user + nice + system + idle + steal + virtal ;
    cpuUtilVect.push_back(total);
  }

  return cpuUtilVect ; 
}



// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() { 
  std::ifstream filestream( kProcDirectory + kStatFilename ) ;
  string line ;
  string str ;
  int tmp, proc ;
  if ( filestream.is_open() ) {
    while (std::getline(filestream, line ) ) {
      std::istringstream linestream( line ) ;
      linestream >> str >> tmp ;
      if ( str.find("processes") != string::npos) proc = tmp ;  
    }
  }
  return proc ;
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() { 
  std::ifstream filestream( kProcDirectory + kStatFilename ) ;
  string line ;
  string str ;
  int tmp, proc ;
  if ( filestream.is_open() ) {
    while (std::getline(filestream, line ) ) {
      std::istringstream linestream( line ) ;
      linestream >> str >> tmp ;
      if ( str.find("procs_running") != string::npos) proc = tmp ;  
    }
  }
  return proc ;
}

// TODO: Read and return the command associated with a process
string LinuxParser::Command(int pid) { 
  std::ifstream filestream( LinuxParser::kProcDirectory + to_string(pid) + LinuxParser::kCmdlineFilename ) ;
  std::string line ;
  std::string str ;
  if ( filestream.is_open() ) {
    std::string str ;
    std::getline(filestream, line ) ;
  }
  return line ; 
}

// TODO: Read and return the memory used by a process
string LinuxParser::Ram(int pid[[maybe_unused]]) { 
  std::ifstream filestream( kProcDirectory + to_string(pid) + kStatusFilename ) ;
  string line ;
  string str ;
  int tmp, ram ;
  if ( filestream.is_open() ) {
    while (std::getline(filestream, line ) ) {
      std::istringstream linestream( line ) ;
      linestream >> str >> tmp ;
      //if ( str.find("VmSize") != string::npos) ram = tmp ;  
      if ( str.find("VmRSS") != string::npos) ram = tmp ;  
    }
  }
  ram /= 1024 ;
  return to_string( ram) ;
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) { 
  std::ifstream filestream( kProcDirectory + to_string(pid) + kStatusFilename ) ;
  string line ;
  string str1{}, str2{} ;
  if ( filestream.is_open() ) {
    while (std::getline(filestream, line ) ) {
      std::istringstream linestream( line ) ;
      linestream >> str1 >> str2 ;
      if ( str1.find("Uid") != string::npos) return str2 ;  
    }
  }
  return str2 ;
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) { 
  string uid = LinuxParser::Uid( pid ) ; 
  std::ifstream filestream( kPasswordPath ) ;
  std::size_t p ;
  string line ;
  vector<string> tokens ;
  string str1{}, str2{} ;
  if ( filestream.is_open() ) {
    while (std::getline(filestream, line ) ) {
      if ( line.find(uid) != string::npos) {
	      while(( p = line.find(":")) != string::npos ) return line.substr(0,p ) ;
      }
    }
  }
  return string() ;
}

// TODO: Read and return the uptime of a process
long LinuxParser::UpTime(int pid) { 
  vector<long> cpuUtilVect = LinuxParser::ActiveJiffies( pid ) ;
  long int Hertz = sysconf( _SC_CLK_TCK ) ;
  long seconds = cpuUtilVect[5] - cpuUtilVect[4] / Hertz ;
  return seconds ;
}
