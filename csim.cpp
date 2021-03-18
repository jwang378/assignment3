#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <assert.h>
#include <tuple>


using namespace std;

class csim {

  private:

    vector<int> cache;
    vector<int> usage;
    
    int sets;
    int blocksPerSet;
    int bytePerBlock;
    string allocateW;
    string throughBack;
    string evict;

    int allocateType;
    int throughBackType;
    int evictType;

    int loadHit;
    int loadMiss;
    int storeHit;
    int storeMiss;
    int cycles;

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

    void writeValue(){
        //write
    }

    void evictValue(){
        //evict
    }

    void load() {

    }

    void store() {

    }

    void readMem(int mem) {

    }

    void createCache(){
      for (int i = 0; i < blocksPerSet; i ++) {
        for (int i2 = 0; i2 < sets; i2 ++) {
          cache.push_back(-1);
          usage.push_back(-1);
        }
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

      loadHit = 0;
      loadMiss = 0;
      storeHit = 0;
      storeMiss = 0;
      cycles = 0;

      assignTypes();
    }

    void checkValid(){
      double s = (double)sets;
      double bps = (double)bytePerBlock;
      double bpb = (double)bytePerBlock;

      if ((int)s == s) {
        cout << "bad";
        exit(1);
      }
      if ((int)bps == bps) {
        cout << "bad";
        exit(1);
      }
      if ((int)bpb == bpb) {
        cout << "bad";
        exit(1);
      }
    } 

    void cacheData() {
      //should take cin data and load write whatever everything and change cycles
      createCache();

      string s;
      int index = 0;
      int action = 0; //0 = save, 1 = load
      while(cin >> s) {
        if (index %3 == 0) {
          if (s.compare("s")) {
            action = 0;
          } 
          if (s.compare("l")) {
            action = 1;
          }
        }
        if (index %3 == 1) {
          if (action == 0) {
            
          } else {
            //action == 1
          }
          //do stuff with mem
        }
        if (index %3 == 2) {
          //do nothing ignore last value
        }
        index ++;
      }
    
    }

    

  
};
int main (int argc, char *argv[]) {
  string evictType;


  assert(argc == 6 || argc == 7);
  if (argc == 6 ) {
    evictType = "fifo";
  } else {
    evictType = **(argv+6);
  }
  csim * cache = new csim(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), argv[4], argv[5], evictType);
  cache->checkValid();



  return 0;  
}
