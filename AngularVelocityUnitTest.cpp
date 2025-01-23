#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "angularvelocitycalculator.h"

namespace UnitTest
{
    TEST_CLASS(AngularVelocityTest)
    {
    public:
        TEST_METHOD(TestAngularVelocityOne)
        {
            // Datos de prueba
            struct point_t points[] = {
                {0.0, 1.0, 0.0},  // Tiempo, posición x, posición y
                {0.1, 0.9, 0.1},
                {0.2, 0.7, 0.2},
                {0.3, 0.4, 0.3},
                {0.4, 0.0, 0.4},
            };
            int numberOfPoints = 5;

            // Resultado esperado (calcula manualmente el valor correcto)
            float expectedMaxAngularVelocity = 5.0;

            // Llamar a la función a probar
            float actualMaxAngularVelocity = computeMaximumAngularVelocity(points, numberOfPoints);

            Assert::AreEqual(expectedMaxAngularVelocity, actualMaxAngularVelocity);
            Assert::IsTrue(expectedMaxAngularVelocity - actualMaxAngularVelocity < 1);
        }

        TEST_METHOD(TestAngularVelocityOne)
        {
            // Datos de prueba
            struct point_t points[] = {
                {0.0, 1.0, 0.0},  // Tiempo, posición x, posición y
                {0.1, 0.9, 0.1},
                {0.2, 0.7, 0.2},
                {0.3, 0.4, 0.3},
                {0.4, 0.0, 0.4},
            };
            int numberOfPoints = 5;

            // Resultado esperado (calcula manualmente el valor correcto)
            float expectedMaxAngularVelocity = 5.0;

            // Llamar a la función a probar
            float actualMaxAngularVelocity = computeMaximumAngularVelocity(points, numberOfPoints);

            Assert::AreEqual(expectedMaxAngularVelocity, actualMaxAngularVelocity);
            Assert::IsTrue(expectedMaxAngularVelocity - actualMaxAngularVelocity < 1);
        }
        
        /*
        Beste datu multzo batzuekin probatuko dugu:
        {0.0, 1.0, 0.0},  // Tiempo, posición x, posición y
                {0.1, 0.03565, -0.104},
                {0.2, 0.03208, -0.08556},
                {0.3, 0.04838, 0.109},
                {0.4, 0.0, 0.4},
        Kasu honetan, ExpectedMaxAngularVelocity 23.6 rad/s litzateke.

{0.0, 1.0, 0.0},  // Tiempo, posición x, posición y
                {0.1, 0.03565, -0.104},
                {0.2, 0.06434, 0.102},
                {0.3, 0.06603, 0.09438},
                {0.4, 0.0, 0.4},
        Kasu honetan, ExpectedMaxAngularVelocity 22.5 rad/s litzateke
        */

    };
}
