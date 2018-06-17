#ifndef FRACTAL_IMAGE_H
#define FRACTAL_IMAGE_H

#include <array>
#include <vector>
#include <complex>
#include <random>
#include <iomanip>
#include <sstream>
#include <iostream>

#include <Eigen/Geometry>
#include <Magick++.h>

#include "Constants.hpp"

using namespace std;
using namespace Eigen;
using namespace Magick;

class FractalInstance
{  
  void build();

  Vector2d to_screen_coords(complex<double> c);

  default_random_engine generator;

  unsigned iterations;
  double escape_radius;

  vector<double> coefficients;
  vector<double> exponents; 

public:
  FractalInstance(
    vector<double> coefficients = {1, 1, 1}, 
    vector<double> exponents = {3, 2, 1},
    unsigned iterations = default_iterations, 
    double escape_radius = default_radius
  );

  vector< vector<unsigned> > counters;

  const double get_max_count();

  void setCoefficients(vector<double> coefficients);
  void setExponents(vector<double> exponents);

  static double default_radius;
  static double complex_range;

  static unsigned num_points;
  static unsigned default_iterations;
};

#endif // FRACTAL_IMAGE_H
