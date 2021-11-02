#pragma once
//#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class PCA {
                public:
                    /**
                    * Apply dimensionality reduction
                    * @warn Will override the source vector if no dest provided!
                    */
                    void transform(float *x, float *dest = NULL) {
                        static float u[2] = { 0 };
                        u[0] = dot(x,   -0.301845582617  , -0.497732724344  , 0.804500104239  , -0.118029494836 );
                        u[1] = dot(x,   0.175669677828  , -0.707964963301  , -0.280569029139  , 0.623864404273 );
                        memcpy(dest != NULL ? dest : x, u, sizeof(float) * 2);
                    }

                protected:
                    /**
                    * Compute dot product with varargs
                    */
                    float dot(float *x, ...) {
                        va_list w;
                        va_start(w, 4);
                        static float mean[] = {  0.699208484791 , 0.620595202843 , 0.235168362771 , 0.130499319672  };
                        float dot = 0.0;

                        for (uint16_t i = 0; i < 4; i++) {
                            dot += (x[i] - mean[i]) * va_arg(w, double);
                        }

                        return dot;
                    }
                };
            }
        }
    }
