#pragma once

class MobileAverageFilter{
public:
   MobileAverageFilter(int size_);
    ~MobileAverageFilter();
    float filter(float data);

private:
    float* vector;
    int size;
    int index;
};