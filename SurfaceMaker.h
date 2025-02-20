#ifndef SURFACEMAKER_H
#define SURFACEMAKER_H

#include <string>

#include <vector>
#include "amlVec.h"

class cycleUtils;

class SurfaceMaker {
public:
    SurfaceMaker();
    ~SurfaceMaker();

    void OnOpenCurveFile(const std::string& filename);
    void OnOpenCurveNetwork(const std::vector<std::vector<AML::double3>>& curveNetwork);
    void OnSaveMesh();
    void ConstructSurface(const std::string& filename);

private:
    cycleUtils* m_cycleUtils;
};

#endif 