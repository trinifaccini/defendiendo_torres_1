#include <stdio.h>
#include <stdbool.h>

const int PRIM_DIA_RANGO_1 = 1;
const int ULT_DIA_RANGO_1 = 10;
const int PRIM_DIA_RANGO_2 = 11;
const int ULT_DIA_RANGO_2 = 20;
const int PRIM_DIA_RANGO_3 = 21;
const int ULT_DIA_RANGO_3 = 30;
const char MANIANA = 'M';
const char TARDE = 'T';
const char NOCHE = 'N';
const char PIE_DERECHO = 'D';
const char PIE_IZQUIERDO = 'I';
const char ENSALADA = 'E';
const char HAMBURGUESA = 'H';
const char PIZZA = 'P';
const char GUISO = 'G';
const int MIN_HORAS_RANGO_1 = 0;
const int MAX_HORAS_RANGO_1 = 4;
const int MIN_HORAS_RANGO_2 = 5;
const int MAX_HORAS_RANGO_2 = 8;
const int MIN_HORAS_RANGO_3 = 9;
const int MAX_HORAS_RANGO_3 = 12;
const char MAL_ANIMO = 'M';
const char REGULAR_ANIMO = 'R';
const char BUEN_ANIMO = 'B';
const int MIN_PUNTOS_MAL = 5;
const int MAX_PUNTOS_MAL = 20;
const int MIN_PUNTOS_REGU = 21;
const int MAX_PUNTOS_REGU = 35;
const int MIN_PUNTOS_BIEN = 36;
const int MAX_PUNTOS_BIEN = 50;

/* 
// post: devuelve true cuando el valor sea un numero dentro de los dias del mes.
*/
bool es_dia_valido (int dia_del_mes){
		return ((dia_del_mes >= PRIM_DIA_RANGO_1) && (dia_del_mes <= ULT_DIA_RANGO_3));
}

/* pre: el dato debe ser valido.
// post: sale el dia del mes en el que se encuentra.
*/
void preguntar_dia_del_mes (int *dia_del_mes){
		printf("¿En que dia del mes se encuentra? ");
		scanf (" %i", dia_del_mes);
		while(!es_dia_valido(*dia_del_mes)){
			printf("Por favor, ingrese un dia del mes valido! ");
			scanf(" %i", dia_del_mes);
		}
}

/*
// pre: es el dia de el mes en el que se encuentra.
// post: devuelve la velociad del viento respectivo al rango al que pertenezca el dia del mes.
*/
int velocidad_viento_segun_dia (int *dia_del_mes){
		int velocidad;
		if ((*dia_del_mes >= PRIM_DIA_RANGO_1) && (*dia_del_mes <= ULT_DIA_RANGO_1)){	
			velocidad = 75;
		}else if ((*dia_del_mes >= PRIM_DIA_RANGO_2) && (*dia_del_mes <= ULT_DIA_RANGO_2)){
			velocidad = 50;
		}else if ((*dia_del_mes >= PRIM_DIA_RANGO_3) && (*dia_del_mes <= ULT_DIA_RANGO_3)){
			velocidad = 25;
		}

		return velocidad;
}

/*
// post: devuelve true cuando el valor concuerde con un momento del dia.
*/
bool es_hora_valida (char hora_del_dia){
		if ((hora_del_dia == MANIANA) || (hora_del_dia == TARDE) || (hora_del_dia == NOCHE)){
			return true;
		}else
			return false;
}

/*
//pre: es dato valido.
// post: sale la inicial del momento del dia en la que se encuentra.
*/
void preguntar_hora_del_dia (char* hora_del_dia){
		printf("¿Cual es la hora actual? Maniana: M - Tarde: T - Noche: N : ");
		scanf(" %c", hora_del_dia);
		while(!es_hora_valida(*hora_del_dia)){
			printf("Por favor, ingrese una hora valida! Maniana: M - Tarde: T - Noche: N : ");
			scanf(" %c", hora_del_dia);
		}
}

/*
// pre: es la inicial del momento del dia en la que se encuentra.
// post: devuelve el porcentaje de humedad que hay en ese momento del dia.
*/
int porcentaje_humedad_segun_hora(char* hora_del_dia){
		int porcentaje;
		if (*hora_del_dia == MANIANA){
			porcentaje = 75;
		}else if (*hora_del_dia == TARDE){
			porcentaje = 25;
		}else if (*hora_del_dia == NOCHE){
			porcentaje = 50;
		}

		return porcentaje;

}

/* 
// post: devuelve true cuando el valor concuerde con la inicial de uno de sus pies.
*/
bool es_pie_valido (char pie_usado){
		return ((pie_usado == PIE_DERECHO) || (pie_usado == PIE_IZQUIERDO));
}

/*
//pre. es dato valido.
// post: sale la inicial del pie que primero uso al levantarse.
*/
void preguntar_pie_levanto (char* pie_usado){
		printf("Indique el pie con el que se levanto: Pie derecho: D - Pie izquierdo: I : ");
		scanf(" %c", pie_usado);
		while (!es_pie_valido(*pie_usado)){
			printf("Por favor, ingrese un pie valido! Pie derecho: D - Pie izquierdo: I : ");
			scanf(" %c", pie_usado);
	}
}

/*
// pre: es la incial del pie que uso.
// post: devuelve la cantidad de puntos respectivos al pie que haya usado.
*/
int puntaje_segun_pie (char* pie_usado){
		preguntar_pie_levanto (pie_usado);
		int puntos_pie;
		if (*pie_usado == PIE_DERECHO){
			puntos_pie = 10;
		}else if (*pie_usado == PIE_IZQUIERDO){
			puntos_pie = 0;
		}

		return puntos_pie;

}

/*
// post: devuelve true cuando el valor concuerde con alguna de las inciales de las comidas que pudo haber comido la noche anterior.
*/
bool es_cena_valida (char cena_dia_anterior){
		return ((cena_dia_anterior == ENSALADA) || (cena_dia_anterior == HAMBURGUESA) || (cena_dia_anterior == PIZZA) || (cena_dia_anterior == GUISO));
}

/*
// pre: es dato valido.
// post: sale la inicial de la comida que ceno la noche anterior.
*/
void preguntar_cena_dia_anterior (char* cena_dia_anterior){
		printf("Ingrese la comida que ceno el dia anterior Ensalada: E - Hamburguesa: H - Pizza: P - Guiso: G : ");
		scanf(" %c", cena_dia_anterior);
		while (!es_cena_valida(*cena_dia_anterior)){
			printf("Por favor, ingrese bien lo que ceno anoche Ensalada: E - Hamburguesa: H - Pizza: P - Guiso: G : ");
			scanf(" %c", cena_dia_anterior);
	}
}

/*
// pre: es la inicial de la comida que ceno la noche anterior.		
// post: devuelve la cantidad de puntos respectivos a lo que haya cenado.
*/
int puntaje_segun_comida_cena (char* cena_dia_anterior){
		preguntar_cena_dia_anterior (cena_dia_anterior);
		int puntos_cena;
		if (*cena_dia_anterior == ENSALADA){
			puntos_cena = 20;
		}else if (*cena_dia_anterior == HAMBURGUESA){
			puntos_cena = 15;
		}else if (*cena_dia_anterior == PIZZA){
			puntos_cena = 10;
		}else if (*cena_dia_anterior == GUISO){
			puntos_cena = 5;
		}

		return puntos_cena;

}

/*
// post: devuelve true cuando el valor este dentro del rango valido de las horas que podrian haber dormido.
*/
bool son_horas_validas (int horas_dormidas){
		return ((horas_dormidas >= MIN_HORAS_RANGO_1) && (horas_dormidas <= MAX_HORAS_RANGO_3));
}

/*
// pre: Es dato valido.
// post: sale la cantidad de horas que durmio la noche anterior.
*/
void preguntar_cuanto_durmio (int* horas_dormidas){
		printf("¿Cuantas horas durmio anoche? (entre 1 y 12): ");
		scanf(" %i", horas_dormidas);
		while(!son_horas_validas(*horas_dormidas)){
			printf("Por favor, indique correctamente cuantas horas durmio (entre 1 y 12): ");
			scanf( " %i", horas_dormidas);
	}
}

/*
// pre: es la cantidad de horas que durmio.
// post: devuelve los puntos respectivos a las horas que haya dormido.
*/
int puntaje_segun_horas_dormidas (int* horas_dormidas){
		preguntar_cuanto_durmio (horas_dormidas);
		int puntos_suenio;
		if ((*horas_dormidas >= MIN_HORAS_RANGO_1) && (*horas_dormidas <= MAX_HORAS_RANGO_1)){
			puntos_suenio = 0;
		}else if ((*horas_dormidas >= MIN_HORAS_RANGO_2) && (*horas_dormidas <= MAX_HORAS_RANGO_2)){
			puntos_suenio = 10;
		}else if ((*horas_dormidas >= MIN_HORAS_RANGO_3) && (*horas_dormidas <= MAX_HORAS_RANGO_3)){
			puntos_suenio = 20;
		}

		return puntos_suenio;

}

/*
// post: devuelve la cantidad de puntos que obtuvo correspondientes a los datos ingresados.
*/
int puntaje_total_segun_datos (char *pie_usado, char* cena_dia_anterior, int* horas_dormidas){
		int puntos_pie = puntaje_segun_pie(pie_usado);
		int puntos_cena = puntaje_segun_comida_cena (cena_dia_anterior);
		int puntos_suenio = puntaje_segun_horas_dormidas (horas_dormidas);

		return puntos_pie + puntos_cena + puntos_suenio; 
}

/*
// pre: son los puntos que obtuvo cada uno.
// post: devuelve el animo que tiene en el momento, el cual es respectivo a la cantidad de puntos que haya obtenido. 
*/
char animo_segun_puntaje_total (char *pie_usado, char* cena_dia_anterior, int* horas_dormidas){
		int puntos_totales = puntaje_total_segun_datos(pie_usado, cena_dia_anterior, horas_dormidas);
		char animo;
		if ((puntos_totales >= MIN_PUNTOS_MAL) && (puntos_totales <= MAX_PUNTOS_MAL)){
			animo = MAL_ANIMO;
		}else if ((puntos_totales >= MIN_PUNTOS_REGU) && (puntos_totales <= MAX_PUNTOS_REGU)){
			animo = REGULAR_ANIMO;
		}else if ((puntos_totales >= MIN_PUNTOS_BIEN) && (puntos_totales <= MAX_PUNTOS_BIEN)){
			animo = BUEN_ANIMO;
		}

		return animo;

}

int main(){
	int dia_del_mes;
	char hora_del_dia;
	char pie_usado;
	char cena_dia_anterior;
	int horas_dormidas;

	preguntar_dia_del_mes(&dia_del_mes);
	int velocidad_viento = velocidad_viento_segun_dia(&dia_del_mes);
	preguntar_hora_del_dia(&hora_del_dia);
	int porcentaje_humedad = porcentaje_humedad_segun_hora(&hora_del_dia);
	printf ("A PARTIR DE AQUI INGRESE LOS DATOS DE LEGOLAS \n" );
	char animo_legolas = animo_segun_puntaje_total (&pie_usado, &cena_dia_anterior, &horas_dormidas);
	printf ("AHORA, INGRESE LOS DATOS DE GIMLI POR FAVOR \n" );
	char animo_gimli = animo_segun_puntaje_total(&pie_usado, &cena_dia_anterior, &horas_dormidas);
	
	printf("La velocidad viento en el dia de hoy es de %i km/h con una humedad del %i porciento. El animo de Legolas es %c mientras que el de Gimli es %c. Esperemos que la batalla del dia de hoy sea tan epica como esperamos.\n", velocidad_viento, porcentaje_humedad, animo_legolas, animo_gimli);

	printf("Resumen: %i %i %c %c \n", velocidad_viento, porcentaje_humedad, animo_legolas, animo_gimli);

	return 0;

}
