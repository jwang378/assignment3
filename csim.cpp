#include <string>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

using std::string;
class csim {

  private:
    int sets;
    int blocksPerSet;
    int bytePerBlock;
    string allocateW;
    string throughBack;
    string evict;

    int allocateType;
    int throughBackType;
    int evictType;

    void assignTypes(){
      if (allocateW == "write-allocate") {
        allocateType = 0;
      } else {
        if (allocateW == "no-write-allocate") {
          allocateType = 1;
        } else {
          exit(1);
        }
      }

      if (throughBack == "write-through") {
        throughBackType = 0;
      } else {
        if (throughBack == "write-back") {
          throughBackType = 1;
        } else {
          exit(1);
        }
      }

      if (evict == "lru") {
        evictType = 0;
      } else {
        if (evict == "fifo") {
          evictType = 1;
        } else {
          exit(1);
        }
      }

      if (allocateType == 1 && throughBackType == 1) {
        exit(1);
      }

    }   

  public:

    csim(int s, int bps, int bpb, string all, string tb, string ev){
      sets = s;
      blocksPerSet = bps;
      bytePerBlock = bpb;
      allocateW = all;
      throughBack = tb;
      evict = ev;

      assignTypes();
    }

    void checkValid(){
      double s = (double)sets;
      double bps = (double)bytePerBlock;
      double bpb = (double)bytePerBlock;

      if ((int)s == s) {
        exit(1);
      }
      if ((int)bps == bps) {
        exit(1);
      }
      if ((int)bpb == bpb) {
        exit(1);
      }
    }    

  
};
int main (int argc, char *argv[]) {
  string evictType;
  assert(argc == 5 || argc == 6);
  if (argc == 5 ) {
    evictType = "fifo";
  } else {
    evictType = argv[5];
  }
  csim * cache = new csim(atoi(argv[0]), atoi(argv[1]), atoi(argv[2]), argv[3], argv[4], evictType);
  cache->checkValid();



  return 0;  
}
