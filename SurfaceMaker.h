#ifndef SURFACEMAKER_H
#define SURFACEMAKER_H

#include <string>

class cycleUtils;

class SurfaceMaker {
public:
    SurfaceMaker();
    ~SurfaceMaker();

    void OnOpenCurveFile(const std::string& filename);
    void OnSaveMesh();
    void ConstructSurface(const std::string& filename);

private:
    cycleUtils* m_cycleUtils;
};

#endif 