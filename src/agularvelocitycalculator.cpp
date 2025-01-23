#include "angularvelocitycalculator.h"
#include <math.h>
#include <stdlib.h>

#define M_PI 3.1416

// Balioak izendatu
struct Point {
    double x;
    double y;
    double time;
};


double calculate_angle(double x, double y) {
    return atan2(y, x);  // x eta y puntuak ditugu, eta atan2 funtzioak (arcotan), bi puntuak sortutako angelua kalkulatzen du.
}


float computeMaximumAngularVelocity(const point_t* points, int numberOfPoints) { 

   
    float maxVelocity = 0.0; // maximoa baino handiagoa bada abiadura angeluarra, maximotzat ezarriko da eta horregatik zenbaki txikienetik hasten da.

    for (int i = 1; i < numberOfPoints; i++) { // Puntu bakoitza analizatzen du.
        
        double angle1 = calculate_angle(points[i - 1].x, points[i - 1].y); // angelu bat kalkulatzen du, adibidez, A1={0.1, 0.2, 0.3}  arctan(0.1,0.2)
                                                                                                                 //A2={0.4, 0.5, 0.6}  
                                                                                                                  
        double angle2 = calculate_angle(points[i].x, points[i].y); // bere jarraian dagoen puntuaren angelua    arctan(0.4, 0.5)

        
        double deltaAngle = angle2 - angle1; //Angeluen arteko diferentzia

        
        if (deltaAngle > M_PI) { // (-pi, pi) tartean guztiak egoteko, hau da;
            deltaAngle -= 2 * M_PI; //angelua pi baino handiagoa bada, angeluari -2pi egin behar zaio.
        }
        else if (deltaAngle < -M_PI) { // Aldiz, angelua -pi baino txikiagoa bada;
            deltaAngle += 2 * M_PI; // angeluari 2pi gehitzen zaio.
        }

        
        float deltaTime = points[i].time - points[i - 1].time; //Puntu batetik bestera zenbat denbora pasa den. i= 1 denean hau egiten du (0.3 - 0.0)
                                                                                                                // i= 2 (0.6 - 0.3)

        
        if (deltaTime > 0) { //Denbora diferentzia 0 baino handiagoa den bitartean (beti gertatuko da, baina badaezpada):
            
            double angularVelocityRad = fabs(deltaAngle / deltaTime); // Abiadura angeluarra kalkulatzen du, hau da, angelua eta denboraren arteko zatiketa
                                                                      // Emaitza beti balio absolutuan (fabs)

           
            if (angularVelocityRad > maxVelocity) { // maximoa baino handiagoa bada abiadura angeluarra, maximotzat ezarriko da
                maxVelocity = angularVelocityRad;
            }
        }
    }

    return maxVelocity; 
}
