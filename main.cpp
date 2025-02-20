#include "SurfaceMaker.h"


std::vector<std::vector<AML::double3>> createCylinderCurveNetwork(double radius, double height, int numSegments) {
    std::vector<std::vector<AML::double3>> curveNetwork;

    // Create the top and bottom circles split into two arcs
    std::vector<AML::double3> topCircleArc1;
    std::vector<AML::double3> topCircleArc2;
    std::vector<AML::double3> bottomCircleArc1;
    std::vector<AML::double3> bottomCircleArc2;

    for (int i = 0; i < numSegments; ++i) {
        double angle = 2.0 * M_PI * i / numSegments;
        double x = radius * cos(angle);
        double y = radius * sin(angle);
        if (i < numSegments / 2) {
            topCircleArc1.push_back(AML::double3(x, y, height));
            bottomCircleArc1.push_back(AML::double3(x, y, 0.0));
        } else {
            topCircleArc2.push_back(AML::double3(x, y, height));
            bottomCircleArc2.push_back(AML::double3(x, y, 0.0));
        }
    }

    // Close the arcs
    topCircleArc1.push_back(topCircleArc2[0]);
    topCircleArc2.push_back(topCircleArc1[0]);
    bottomCircleArc1.push_back(bottomCircleArc2[0]);
    bottomCircleArc2.push_back(bottomCircleArc1[0]);

    // Add the arcs to the curve network
    curveNetwork.push_back(topCircleArc1);
    curveNetwork.push_back(topCircleArc2);
    curveNetwork.push_back(bottomCircleArc1);
    curveNetwork.push_back(bottomCircleArc2);

    // Create two vertical edges to connect corresponding points on the top and bottom arcs
    std::vector<AML::double3> verticalEdge1 = {bottomCircleArc1[0], topCircleArc1[0]};
    std::vector<AML::double3> verticalEdge2 = {bottomCircleArc2[0], topCircleArc2[0]};
    curveNetwork.push_back(verticalEdge1);
    curveNetwork.push_back(verticalEdge2);


    return curveNetwork;
}

// Example usage
int main(){

    std::vector<std::vector<AML::double3>> curveNetwork;
    double radius = 1.0;
    double height = 2.0;
    int numSegments = 20;
    curveNetwork = createCylinderCurveNetwork(radius, height, numSegments);

    SurfaceMaker surfaceMaker = SurfaceMaker();
    // surfaceMaker.ConstructSurface("../exampleCurves/block.curve");
    surfaceMaker.OnOpenCurveNetwork(curveNetwork);
    // surfaceMaker.OnSaveMesh();

    return 0;
}