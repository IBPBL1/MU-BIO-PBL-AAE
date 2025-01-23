#include <csv.h>
#include <stdio.h>
#include "point.h"
#include "pointreader.h"
#include "angularvelocitycalculator.h"

int main(int argc, char ** argv) {// argc (programaria sartzen dizkiogun fitxategi kopurua da) eta argv (sartutako fitxategiaren balioak "array" modura gordetzen du)
	if (argc != 2) { // 2-ren berdina izan behar da, 2 baino gutxiago baldin bada programak ez ditu beharrezko dato kopurua jasotzen, eta bi baino gehiago baldin bada datu gehiegi dauzka programa aurrera eramateko.
		printf("Abiadura angeluar maximoa kalkulatzeko programa, Tracker-ek sortutako koma-balio bereizien txt fitxategi batetik abiatuta\n");
		printf("Usage: %s <datuak>\n", argv[0]); //argv[0]-ren esanahia honako hau da: Exekutagarriaren izena edo ibilbidea.

		return -1; // Ez du ezer ere bueltatzen programak.
	}
	struct point_t* points; // Points izeneko puntero bat deklaratzen du, era horretan punteroaren memoriaren helbidea gordetzen du, hau da memoria dinamikoa.

	int numberOfPoints = readPoints(argv[1], &points); // readPoints funtziotik puntuak irakurtzen ditu, era honetan zenbat puntu daudezen gordetzen du.

	if (numberOfPoints < 0) { //Irakurritako puntuak 0 baino txikiagoa baldin bada errore bat itzultzen du.
		printf("Error reading file\n");
		return -1;
	}
	float maximumAngularVelocity = computeMaximumAngularVelocity(points, numberOfPoints); //maximumAngularVelocity-k abiadura angeluar altueta hartzen du eta zenbaki hamartarretan itzultzen du.
	
	printf("Maximum angular velocity: %f\n", maximumAngularVelocity);

	freePoints(&points); //Memoria dinamikoa askatzen du
	return 0;
}