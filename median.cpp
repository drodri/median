#include "median.h"


MobileAverageFilter::MobileAverageFilter(int size_): size(size_), index(0){
  vector = new float[size_];
}
MobileAverageFilter::~MobileAverageFilter(){
  delete [] vector;
}
float MobileAverageFilter::filter(float data){
  vector[index++] = data;
  if(index>=size)
    index = 0;
  float m = 0.0f;
  for (int i =0;i<size;i++)
    m+=vector[i];
  return m/size;
}
