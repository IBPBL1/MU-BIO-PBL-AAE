#include "pointreader.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest
{
    TEST_CLASS(PointReaderTest)
    {
    public:
        TEST_METHOD(TestReadingWorksWithValidInput)
        {
            char const* filename = "points.txt";
            struct point_t* points;
            
            int numberOfPoints = readPoints(filename, &points);
            Logger::WriteMessage("In TestReadingWorksWithValidInput");
            Assert::IsTrue(numberOfPoints > 0); //Fitxategia ondo irakurtzen bada, puntu kopuruak 0 baino handiagoa izan behar du

        }
		TEST_METHOD(TestReadingNotWorksWithInvalidInput)
		{

            point_t* points;
            int numberOfPoints = readPoints("invalidpoints.txt", &points);

			Logger::WriteMessage("In TestReadingNotWorksWithInvalidInput");
			Assert::AreEqual(numberOfPoints, -1);//Fitxategia behar bezala irakurtzen ez bada, funtzioak -1 itzuli behar du


		}
        TEST_METHOD(TestReadingNotWorksWithUnexsistentFile){

            point_t* points;
            int numberOfPoints = readPoints("points.txt", &points);
			Logger::WriteMessage("In TestReadingNotWorksWithUnexsistentFile");
			Assert::AreEqual(numberOfPoints, -2);//Fitxategia ez badago, funtzioak -2 itzuli behar du

        }
    };
}