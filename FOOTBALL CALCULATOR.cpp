#include<iostream> 
#include<string>
#include<windows.h>
using namespace std; 

int N=3, k, C; //Dichiarazioni variabili globali.
float temp;
string temp2;


struct grmin { //Dichiarazioni degli struct.
	int min= 10000;
	string minn; } minimo;
		
struct grmax {
	int max= 0;
	string maxn; } massimo;	
		
struct grsommed {
	float somma;
	float media; } sommaMedia;
	
	
void riempimentoVett (string nome[], int punteggio[]); //Header o testata delle funzioni.
void stampaVett (string nome[], int punteggio[], int N);
struct grmin calcoloMin (string nome[], int punteggio[]);
struct grmax calcoloMax (string nome[], int punteggio[]);
struct grsommed calcoloSommaMedia (int punteggio[]);
void riempimentoVettR (string nome3[]);
void calcoloSommaR (int punteggio[], int punteggio2[], int somma3[], string nome3[]);
void calcoloDifferenzaR (int punteggio[], int punteggio2[], int differenza3[], string nome3[]);
void calcoloMediaR (int punteggio[], int punteggio2[], float s3omma[], float media3[], string nome3[]);
void bubblesortCrescente (string nome3[], float media3[]);
void bubblesortDecrescente (string nome3[], float media3[]);
void stampaMedia (string nome3[], float media3[]);
void bubblesortOttimizzato (string nome3[], float media3[]);
void setFontSize(int FontSize);


main() 
	{
		
    /* PROGRAMMA CHE: 1- USO DELLA SELEZIONE E ITERAZIONE AVANZATO.
					  2- ESEGUE CALCOLI DI: RICERCA DEL MASSIMO E DEL MINIMO, SOMMA E MEDIA ALL'INTERNO DI UN VETTORE E DEL SUO VETTORE PARALLELO;
					  3- ESEGUE CALCOLI DI: SOMMA, DIFFERENZA E MEDIA TRA 2 VETTORI DANDO UN VETTORE RISULTANTE;
					  4- ORDINAMENTO DI UN VETTORE TRAMITE BUBBLE SORT E BUBBLE SORT OTTIMIZZATO CON BOOLEANI.
					  5- USO DEI RECORD (STRUCT).
					  6- USO DELLE STRINGHE DI CARATTERE (STRING).
					  7- USO DELLE FUNZIONI.
					  8- STILE DI INDENTAZIONE TRAMITE STILE LISP. */	
			
					 
	int N=3, punteggio[N], punteggio2[N], somma3[N], differenza3[N]; //Dichiarazione delle varie variabili.
	char x;
	string nome[N], nome2[N], nome3[N];
	
	
	do{ //Inizio di un ciclo di iterazione post-condizionata per la possibilità di ripetere il programma rispondendo a una domanda.
	
		float media3[k], s3omma[k];

	
		setFontSize(20); //Funzione per grandezza font.                                                                                                                                                 //COLORI: A=verde limone B=azzurro C=rosso D=fucsia E=giallo F=bianco 0=nero  1=blu scuro  2=verde  3=verde acqua   4=bordeaux  5=viola  6=verde oliva  7=grigio chiaro   8=grigio  9=blu.
		system("color F0"); //Funzione per cambiare colore sfondo e carattere.             
		
		
		cout<<"PER GODERE DI UN'ESPERIENZA MIGLIORE USARE SQUADRE CHE HANNO MILITATO NEL CAMPIONATO DI SERIE A NEGLI ULTIMI 5 ANNI."<<endl<<endl;
		riempimentoVett (nome,punteggio); //Riempimento di un primo vettore e del suo vettore parallelo. 
	
		cout<<endl<<"NEL SECONDO VETTORE INSERISCI SQUADRE DELLA STESSA REGIONE DELLE CORRISPONDENTI DEL PRIMO VETTORE."<<endl<<endl;
		riempimentoVett (nome2,punteggio2); //Riempimento di un secondo vettore e del suo vettore parallelo.
		
		
		system("color F0"); //Reinserisco il colore standard scelto prima di continuare con il programma.
		
			
		cout<<endl<<"Il PRIMO VETTORE inserito \212: ";
		stampaVett (nome, punteggio, N); //Stampa del primo vettore.
		
		cout<<endl<<"Il SECONDO VETTORE inserito \212: ";
		stampaVett (nome2, punteggio2, N); //Stampa del secondo vettore.
		
			
		minimo= calcoloMin (nome, punteggio); //Calcolo del minimo del primo vettore.
		cout<<endl<<endl<<"Il MINIMO del PUNTEGGIO tra le squadre del PRIMO VETTORE \212: "<<minimo.minn<<" "<<minimo.min; //Stampa del minimo del primo vettore.
		massimo= calcoloMax (nome, punteggio);
		cout<<endl<<"Il MASSIMO del PUNTEGGIO tra le squadre del PRIMO VETTORE \212: "<<massimo.maxn<<" "<<massimo.max;;	 //Stampa del massimo del primo vettore.
		
		minimo= calcoloMin (nome2, punteggio2); //Calcolo del minimo del secondo vettore.
		cout<<endl<<endl<<"Il MINIMO del PUNTEGGIO tra le squadre del SECONDO VETTORE \212: "<<minimo.minn<<" "<<minimo.min; //Stampa del minimo del secondo vettore.
		massimo= calcoloMax (nome2, punteggio2); //Calcolo del massimo del secondo vettore.
		cout<<endl<<"Il MASSIMO del PUNTEGGIO tra le squadre del SECONDO VETTORE \212: "<<massimo.maxn<<" "<<massimo.max; //Stampa del massimo del secondo vettore.
			
		
		sommaMedia= calcoloSommaMedia (punteggio); //Calcolo della somma e della media del primo vettore.
		cout<<endl<<endl<<"La SOMMA del PUNTEGGIO delle squadre del PRIMO VETTORE \212: "<<sommaMedia.somma; //Stampa della somma del primo vettore.
		cout<<endl<<"La MEDIA del PUNTEGGIO tra le squadre del PRIMO VETTORE \212: "<<sommaMedia.media; //Stampa della media del primo vettore.
				
		sommaMedia= calcoloSommaMedia (punteggio2); //Calcolo della somma e della media del secondo vettore.
		cout<<endl<<endl<<"La SOMMA del PUNTEGGIO delle squadre del SECONDO VETTORE \212: "<<sommaMedia.somma; //Stampa della somma del secondo vettore.
		cout<<endl<<"La MEDIA del PUNTEGGIO tra le squadre del SECONDO VETTORE \212: "<<sommaMedia.media; //Stampa della media del secondo vettore.
		
		
		cout<<endl<<endl;
		riempimentoVettR (nome3); //Riempimento di un terzo vettore per i calcoli tra vettori.	
		
		cout<<endl<<"La SOMMA dei PUNTEGGI delle squadre della stessa REGIONE \212: "; 
		calcoloSommaR (punteggio, punteggio2, somma3, nome3); //Calcolo della somma degli elementi corrispettivi dei due precedenti vettori.
		
		cout<<endl<<"La DIFFERENZA dei PUNTEGGI delle squadre della stessa REGIONE \212: "; 
		calcoloDifferenzaR (punteggio, punteggio2, differenza3, nome3); //Calcolo della differenza degli elementi corrispettivi dei due precedenti vettori.
		
		cout<<endl<<"La MEDIA dei PUNTEGGI delle squadre della stessa REGIONE \212: "; 
		calcoloMediaR (punteggio, punteggio2, s3omma, media3, nome3); //Calcolo della media degli elementi corrispettivi dei due precedenti vettori.
		
		
		bubblesortCrescente (nome3, media3); //Bubble Sort crescente.
		
		cout<<endl<<endl<<"La MEDIA dei PUNTEGGI delle squadre delle REGIONI ORDINATE in ordine crescente \212: "; 
		stampaMedia (nome3, media3); //Stampa del vettore media ordinato e del suo vettore parallelo.
		
		
		bubblesortDecrescente (nome3, media3); //Bubble Sort decrescente.
		
		cout<<endl<<"La MEDIA dei PUNTEGGI delle squadre delle REGIONI ORDINATE in ordine decrescente \212: "; 
		stampaMedia (nome3, media3); //Stampa del vettore media ordinato e del suo vettore parallelo.
		
		
		bubblesortOttimizzato (nome3, media3); //Bubble Sort crescente ottimizzato con i booleani.
		
		cout<<endl<<"La MEDIA dei PUNTEGGI delle squadre delle REGIONI ri-ORDINATE in ordine crescente \212: ";
		stampaMedia (nome3, media3); //Stampa del vettore media ordinato e del suo vettore parallelo.
		
		
		cout<<endl;
		do {
			cout<<endl<<endl<<"VUOI RIPETERE IL PROGRAMMA? DIGITA S/N: ";
			cin>>x; }
		while(x!='S'&&x!='s'&&x!='N'&&x!='n');
		cout<<endl; }
	while(x=='S'||x=='s'); //Condizione dell'iterazione post-condizionata	   
	cout<<endl<<endl;
	return 0; }
		    
		
void riempimentoVett (string nome[], int punteggio[]) { //Funzione di riempimento del vettore int e del suo parallelo in string.
	for(int i=0;i<N;i++) {
		cout<<"Inserisci il NOME della SQUADRA " <<i+1<< " da inserire nel vettore: ";
		cin>>nome[i];
		string c1= nome[i];
		if (c1== "ROMA")
			system("color E4");
		else {
			if (c1== "JUVENTUS")
				system("color F0");
			if (c1== "CHIEVO") 
			   	system("color E1"); 
			if (c1== "FROSINONE")
				system("color EB");
			if (c1== "TORINO") 
			   	system("color 4F"); 
			if (c1== "HELLAS") 
			   	system("color E9"); 
			if (c1== "LAZIO") 
			   	system("color FB"); 
			if (c1== "NAPOLI") 
			   	system("color BF"); 
			if (c1== "BENEVENTO") 
			   	system("color E4"); 
			if (c1== "MILAN") 
			   	system("color C0");
			if (c1== "INTER") 
			   	system("color 09"); 
			if (c1== "GENOA") 
			   	system("color C9"); 
			if (c1== "SAMPDORIA") 
			   	system("color 9F");  
			if (c1== "FIORENTINA") 
			   	system("color 5F");
			if (c1== "ATALANTA") 
			   	system("color 09"); 
			if (c1== "UDINESE") 
			   	system("color F0");  
			if (c1== "CAGLIARI") 
			   	system("color C9");
			if (c1== "BOLOGNA") 
			   	system("color C9"); 
			if (c1== "SASSUOLO") 
			   	system("color 02"); 
			if (c1== "CROTONE") 
			   	system("color C9"); 
			if (c1== "PALERMO") 
			   	system("color 0D");  
			if (c1== "EMPOLI") 
			   	system("color BF"); 
			if (c1== "PARMA") 
			   	system("color E9");
			if (c1== "CATANIA") 
			   	system("color CB");
			if (c1== "CESENA") 
			   	system("color F0"); 
			if (c1== "LIVORNO") 
			   	system("color 4F"); 
			if (c1== "SPAL") 
			   	system("color FB");  
			if (c1== "PESCARA") 
			   	system("color FB"); 
			if (c1== "CARPI") 
			   	system("color FC"); }
		cout<<"Inserisci il PUNTEGIO della SQUADRA nella scorsa stagione ";
		cin>>punteggio[i]; } }

void stampaVett (string nome[], int punteggio[], int N) { //Funzione di stampa del vettore int e del suo parallelo in string.
	for(int i=0;i<N;i++) {
		cout<<nome[i]<<" ";
		cout<<punteggio[i];
		if(i<N-1)
			cout<<" - "; } }
			
struct grmin calcoloMin (string nome[], int punteggio[]) { //Funzione per calcolare il minimo all'interno di un vettore.
	grmin minimo;
	for(int i=0;i<N;i++) {
		if(punteggio[i]<minimo.min) {
			minimo.min=punteggio[i];
			minimo.minn=nome[i]; } }
			return minimo; }

struct grmax calcoloMax (string nome[], int punteggio[]) { //Funzione per calcolare il massimo all'interno di un vettore.
	grmax massimo;
	for(int i=0;i<N;i++) {
		if(punteggio[i]>massimo.max) {
			massimo.max=punteggio[i];
			massimo.maxn=nome[i]; } }
			return massimo; }
			
struct grsommed calcoloSommaMedia (int punteggio[]) { //Funzione per calcolare somma e media all'interno di un vettore.
	grsommed sommaMedia;
	for(int i=0;i<N;i++) {  
		sommaMedia.somma+=punteggio[i];
		sommaMedia.media=sommaMedia.somma/N; }
		return sommaMedia; }
			
void riempimentoVettR (string nome3[]) { //Funzione di riempimento di un terzo vettore.
	for(int k=0;k<N;k++)  {
		cout<<"Inserisci il NOME della REGIONE delle squadre " <<k+1<< " dei due vettori: ";
		cin>>nome3[k]; } }
		
void calcoloSommaR (int punteggio[], int punteggio2[], int somma3[], string nome3[]) { //Funzione di riempimento di un vettore con la somma dei corrispettivi dei due precedentu vettori.
	int k=0;
	for(int i=0;i<N;i++) {
		somma3[k]=punteggio[i]+ punteggio2[i];
		cout<<nome3[k]<<" ";
		cout<<somma3[k];
		if(k<N-1)
			cout<<" - ";
			k++; } }
			
void calcoloDifferenzaR (int punteggio[], int punteggio2[], int differenza3[], string nome3[]) { //Funzione di riempimento di un vettore con la differenza dei corrispettivi dei due precedentu vettori.
	k=0;
	for(int i=0;i<N;i++ ) {
		differenza3[k]=punteggio[i]- punteggio2[i];
		cout<<nome3[k]<<" ";
		cout<<differenza3[k];
		if(k<N-1)
			cout<<" - ";
			k++; } } 
			
void calcoloMediaR (int punteggio[], int punteggio2[], float s3omma[], float media3[], string nome3[]) { //Funzione di riempimento di un vettore con la media dei corrispettivi dei due precedentu vettori.
	k=0;
	for(int i=0;i<N;i++) {
		s3omma[k]=punteggio[i]+punteggio2[i];
		media3[k]=s3omma[k]/2;
		cout<<nome3[k]<<" ";
		cout<<media3[k];
		k++;
		if(k<N)
			cout<<" - "; } }
		
void bubblesortCrescente (string nome3[], float media3[]) { //Funzione con Bubble Sort crescente per ordinare il vettore media.
	for (C=0;C<N;C++) { 
		for (k=1; k<N-C; k++) {
			if (media3[k-1]>media3[k]) {
				temp=media3[k];
				temp2=nome3[k]; 
				media3[k]=media3[k-1];
				nome3[k]=nome3[k-1]; 
				media3[k-1]=temp;
				nome3[k-1]=temp2; } } } }	

void bubblesortDecrescente (string nome3[], float media3[]) { //Funzione con Bubble Sort decrescente per ordinare il vettore media.
	for (C=0;C<N;C++) {  
		for (k=1; k<N-C; k++) {
			if (media3[k-1]<media3[k]) {
				temp=media3[k];
				temp2=nome3[k]; 
				media3[k]=media3[k-1];
				nome3[k]=nome3[k-1]; 
				media3[k-1]=temp;
				nome3[k-1]=temp2; } } } }	
		
void stampaMedia (string nome3[], float media3[]) { //Funzione di stampa del vettore media.
	for(k=0; k<N; k++) {
		cout<<nome3[k]<<" ";
		cout<<media3[k];
		if(k<N-1)
			cout<<" - "; } }
			
void bubblesortOttimizzato (string nome3[], float media3[]) { //Funzione con Bubble Sort crescente ottimizzato con booleani per ordinare il vettore media.
	C=0;
	bool scambioAvvenuto=true;
	while (C<N && scambioAvvenuto) { 
		for (k=1; k<N-C; k++) { 
			scambioAvvenuto=false;		
			if (media3[k-1]>media3[k]) {
					scambioAvvenuto=true;
					temp=media3[k];
					temp2=nome3[k]; 
					media3[k]=media3[k-1];
					nome3[k]=nome3[k-1]; 
					media3[k-1]=temp;
					nome3[k-1]=temp2; } } 
		C++; } }
		
void setFontSize(int FontSize) { //Funzione per modificare la grandezza del font.
    CONSOLE_FONT_INFOEX info = {0};
    info.cbSize= sizeof(info);
    info.dwFontSize.Y= FontSize;
    info.FontWeight= FW_NORMAL;
    wcscpy(info.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info); }
