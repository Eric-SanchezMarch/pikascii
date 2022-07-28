
/*

PICASCII ES UN TAMAGOCHI, LA IDEA ES GENERAR UN SER DIGITALITZAT AUTOMATA,

	EL MOVIMENT ES GENERARA ALEATORIAMENT
	
	
BETA 2.0
	-> REEDICIO DE MENU PER ALGO MES LOGIC
	
	MENU ->USAREM EL MENU PER ENTRAR A LES FUNCIONS DEL TAMAGOCHI.
			1- CREAR 3 MINIJOCS els cuals donaran objectes o recompenses per a usar.
				Black Jac
				numero alt o mes baix
				desxifra contrasenya
				
				
			2- ESTADISTIQUES
				-> Mostrarem alimentacio, dies de vida, estat especial "febril, euforic, cansat..."
				-> Total monedes logrades
				-> insignies
				-> Registre aventura.  // generar events a partir del moviment aleatori amb textos predefinits, que seran guardats en una llista.
				
			3- MOTXILA
				-> mostrarem els consumibles, aquestos cobriran la necesitat de alimentacio, jocs desbloquejats, cures, energetics...
			
			5- Sortir.

	Mode historia:
		El joc al iniciar et donara un OU, Set demanara que li dones un nom. Seguidament naixera la criatura
		Et sortira un text on texplique que aquest pet es passiu i que anira generan la seva historia i permetra

*/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


void intro();
void imgPortada();
void estat1();
void rundown(int a);
void runleft(int a);
void runright(int a);
void runup(int a);
void botomenu();
void fps();
void menu();
void Pokedex();
void Equipo();
void Inventario();
void Mapa();
void Guardar();
void Medalles();
void Credits();
void Exit();
void textos(int a);


int main() {
	
	system("mode con: cols=31 lines=24");
	system("COLOR 06");	
	system("cls");	
	
	intro();
	estat1();
	
	
	return 0;
}


void intro(){
	
char play;	

	imgPortada();
	printf(" -----------------------------\n");
	printf("             STAR!           \n");
	printf(" -----------------------------\n");	
	
	play = getch();
	
	
	system("cls");
	system("COLOR 70");
	imgPortada();
	botomenu(0);
	usleep(224000); //fps
	
	
	system("cls");
	system("COLOR 06");
	imgPortada();
	botomenu(0);
	usleep(124000); //fps
	
	
	system("cls");
	system("COLOR 70");
	imgPortada();
	botomenu(0);
	usleep(224000); //fps
	
	system("cls");
	system("COLOR 46");
	imgPortada();
	botomenu(0);
	usleep(150000); //fps
	
	system("cls");
	system("COLOR 70");
	imgPortada();
	botomenu(0);
	usleep(404000); //fps
	
	system("cls");
	system("COLOR 06");
	imgPortada();
	botomenu(0);
	usleep(124000); //fps
	
	system("cls");
	system("COLOR 76");	
	imgPortada();
	botomenu(0);
	usleep(224000); //fps
	
	system("cls");
	system("COLOR 06");	
	imgPortada();
	botomenu(0);
	usleep(704000); //fps	
		system("cls");
}



void fps(int a){
	if (a == 1){
		usleep(166666);//246000      //156000
}else if(a == 2){
		usleep(365000);	
}
}
void estat1(){
	
	/*
		Estat1 generara aleatoriament la actitut de la rata, aquesta pot estar en moviment o quieta,
		 ames podra canviar la direccio de moviment
	*/
	
	/*
		Variables
	*/
int aux, aux2,x,y,a;
int memdir;
char opcions;

	/*
		Inicialitzacio de les Variables
	*/
aux = 1;	// direccio
aux2 = 2;
memdir = 1;//memdir =	0:down 	1:up 	2:left 		3:right
srand (time(NULL));	
	fflush(stdin);
	
	
	/*
		Bucle, aqui es on s'origina la magia
	*/
	do{
		
		aux = rand()%2;	// Tirem un dau per saver si es mou o no?
		
		//realment cal?
		if (aux < 0 ){			// 0 es igual a estar parada
			aux = 0;
		}		
		if (aux > 1 ){			// 1 es igual a estar en moviment
			aux = 1;
		}	//

		if (aux == 0){	//si la rata esta parada	
			switch(memdir){ // recordant la direccio actualitzarem el fps
				
				case 0:								// mira cap a tu
					a = rand()%12;
					for(x = 0; x < a; x++) {
						rundown(1);
						botomenu(1);
						fps(2);
						system("cls");
						rundown(3);
						botomenu(1);
						fps(2); 
						system("cls");
						}
					break;				
				case 1:								// et dona la esquena
					a = rand()%6;
					for(x = 0; x < a; x++) {
						runup(1);
						botomenu(1);
						fps(2); 
						system("cls");
						runup(3);
						botomenu(1);
						fps(2);
						system("cls");
						}
					break;
				
				case 2:								// mira a la dreta
					a = rand()%6;
					for(x = 0; x < a; x++) {
						runleft(1);
						botomenu(1);
						fps(2);
						system("cls");
						runleft(3);
						botomenu(1);
						fps(2); 
						system("cls");
					}		
					break;
				
				case 3:								// mira a la esquerra

					a = rand()%6;
					for(x = 0; x < a; x++) {
						runright(1);
						botomenu(1);
						fps(2);
						system("cls");
						runright(3);
						botomenu(1);
						fps(2);
						system("cls");
					}		
					break;											
			}	
		}	else if (aux == 1){// si la rata es mou
				srand (time(NULL));

			
			/*
				En este condicional estic
				
			*/
			
				aux2 = rand()%5; // cap a quina direccio es moura?			
					if (aux2 == 0){
						aux2 = 1;
					}
				
					if (aux2 == 5){
						aux2 =4;
					}
					
			switch(aux2){
				case 1:				//down
					memdir = 0;
					a = rand()%12;
					for(x = 0; x < a; x++) {
						for(y = 1; y <=4;y++ ){
							rundown(y);
							botomenu(1);
							fps(1);
							system("cls");						
						}
					}
					break;
				
				case 2:				//up
					memdir = 1;
					a = rand()%4;
					for(x = 0; x < a; x++) {
						for(y = 1; y <=4;y++ ){
							runup(y);
							botomenu(1);
							fps(1);
							system("cls");							
						}
					}
					break;
				
				case 3:				//Left
					memdir = 2;
					a = rand()%4;
					for(x = 0; x < a; x++) {
						for(y = 1; y <=4;y++ ){
							runleft(y);
							botomenu(1);
							fps(1);
							system("cls");							
						}
					}
					break;
				
				case 4:				//right
					memdir =3;
					a = rand()%4;
					for(x = 0; x < a; x++) {
						for(y = 1; y <=4;y++ ){
							runright(y);
							botomenu(1);
							fps(1);
							system("cls");							
						}
					}
					break;						
			}
		}else{
		}

	}while (!kbhit() );		// si pulsem una tecla trencarem el bucle i pasarem al menu
	
	menu();
	
}

void menu(){
	
	/*
		Realment que volem que face el ninot? 
	*/
char mmenu;
int nmm,maux;
int pass,a;
a = 0;
pass = 0;
nmm = 0;
mmenu = 0;
maux = 0;
do{
	
	system("cls");
	printf(" =============================\n");
	printf(" ||       ~  MENU  ~        ||\n");
	printf(" ||=========================||\n");
	printf(" ||                         ||\n");

	if((mmenu == 49) || (maux == 49)){
	printf(" ||  ->  Pokedex            ||\n");
	nmm = 1;
	pass = 1;
	maux = 49;
	}else{
	printf(" || 1. Pokedex              ||\n");	
	}
	if((mmenu == 50)|| (maux == 50)){
	printf(" ||  ->  Equipo             ||\n");
	nmm = 2;
	pass = 1;
	maux = 50;
	}else{
	printf(" || 2. Equipo               ||\n");	
	}
	if((mmenu == 51) || (maux == 51)){
	printf(" ||  ->  inventario         ||\n");
	nmm = 3;
	pass = 1;
	maux = 51;
	}else{
	printf(" || 3. Inventario           ||\n");
	}
	if((mmenu == 52)|| (maux == 52)){
	printf(" ||  ->  Mapa               ||\n");
	nmm = 4;
	pass = 1;
	maux = 52;
	}else{
	printf(" || 4. Mapa                 ||\n");	
	}
	if((mmenu == 53)|| (maux == 53)){
	printf(" ||  ->  guardar            ||\n");
	nmm = 5;
	pass = 1;
	maux = 53;
	}else{
	printf(" || 5. Guardar              ||\n");
	}
	if((mmenu == 54)|| (maux == 54)){
	printf(" ||  ->  Medalles           ||\n");
	nmm = 6;
	pass = 1;
	maux = 54;
	}else{
	printf(" || 6. Medalles             ||\n");	
	}
	printf(" ||                         ||\n");	
	if((mmenu == 55)|| (maux == 55)){
	printf(" ||  ->  Atras              ||\n");
	nmm = 7;
	pass = 1;
	maux = 55;
	}else{
	printf(" || 7. Atras                ||\n");
	}
	if((mmenu == 56)||(maux == 56) ){
	printf(" ||  ->  Exit               ||\n");
	nmm = 8;
	pass = 1;
	maux = 56;
	}else{
	printf(" || 8. Exit                 ||\n");	
	}

	textos(nmm);
	if ((pass == 2)&&(mmenu == 13))  {
		botomenu(2);
		a = 1;
	}

	if (pass == 1){
		botomenu(2);
	}else {
		botomenu(4);
	}

	if ((maux != 0)&&(pass == 1)){
		pass == 2;
	}
	
	mmenu= getch();		// un cop impres el menu demanem una entrada
	if (mmenu == 27){ 	// 27 es ESC 
		estat1();
	}
}while(a!=1);


	switch(maux){
		case 49:
			Pokedex();

		case 50:
			Equipo();

		case 51:
			Inventario();

		case 52:
			Mapa();

		case 53:
			Guardar();

		case 54:
			Medalles();

		case 55:
			Credits();

		case 56:
			Exit(); 

		case 27:
			estat1();
		default:
			menu();
			break;
	}


}
void textos(int a){
	switch(a){
		case 0:
			printf(" ||=========================||\n");
			printf(" ||                         ||\n");
			printf(" ||  selecciona una opcio:  ||\n");
			printf(" ||                         ||\n");
			printf(" ||                         ||\n");
			printf(" ||                         ||\n");
		

			break;
		case 1:
			printf(" ||=========================||\n");
			printf(" ||  Pokedex                ||\n");
			printf(" ||                         ||\n");
			printf(" ||  Registre de tots els   ||\n");
			printf(" ||  Poquemons trobats.     ||\n");
			printf(" ||                         ||\n");
			break;
		case 2:
			printf(" ||=========================||\n");
			printf(" ||  Equipo                 ||\n");
			printf(" ||                         ||\n");
			printf(" ||  Observa els teus       ||\n");
			printf(" ||  Digimonsters.          ||\n");
			printf(" ||                         ||\n");
			break;
		case 3:
			printf(" ||=========================||\n");
			printf(" ||  Inventario             ||\n");
			printf(" ||                         ||\n");
			printf(" ||  Utilitza els diferents ||\n");
			printf(" ||  Objectes del teu       ||\n");
			printf(" ||  Inventari.             ||\n");			
			break;
		case 4:
			printf(" ||=========================||\n");
			printf(" ||  Mapa                   ||\n");
			printf(" ||                         ||\n");
			printf(" ||  Observa el mapa        ||\n");
			printf(" ||  de aventura i indica   ||\n");
			printf(" ||  el cami.               ||\n");			
			break;
		case 5:
			printf(" ||=========================||\n");
			printf(" ||  Guardar                ||\n");
			printf(" ||                         ||\n");
			printf(" ||  Guarda el avanç de la  ||\n");
			printf(" ||  Partida.               ||\n");
			printf(" ||                         ||\n");			
			break;
		case 6:
			printf(" ||=========================||\n");
			printf(" ||  Medalles               ||\n");
			printf(" ||                         ||\n");
			printf(" ||  Trofeus, medalles i    ||\n");
			printf(" ||  estadistiques.         ||\n");
			printf(" ||                         ||\n");			
			break;
		case 7:
			printf(" ||=========================||\n");
			printf(" ||  Atras                  ||\n");
			printf(" ||                         ||\n");
			printf(" ||  Torna a la pantalla    ||\n");
			printf(" ||  Principal.             ||\n");
			printf(" ||                         ||\n");			
			break;
		case 8:
			printf(" ||=========================||\n");
			printf(" ||  Exit                   ||\n");
			printf(" ||                         ||\n");
			printf(" ||  Tanca el joc.          ||\n");
			printf(" ||                         ||\n");
			printf(" ||                         ||\n");	
			break;

			
		
		default :
		break;	
			
			
	}
}

void botomenu(int a){
	switch(a) {
		case 0:
			printf(" =============================\n");
			printf(" || Pi~Kaa Pika~Pii.. BYTE! ||\n");
			printf(" =============================\n");	
			break;
			
		case 1:
			printf(" =============================\n");
			printf(" ||                         ||\n");
			printf(" ||                         ||\n");
			printf(" =============================\n");	
			break;
		case 2:								    
			printf(" ||=========================||\n");
		    printf(" ||   [OK]         Atras    ||\n");
			printf(" =============================\n");		
			break;	
		case 3:
			printf(" ||=========================||\n");
		    printf(" ||    OK        [Atras]    ||\n");
			printf(" =============================\n");		
			break;	
		case 4:
			printf(" ||=========================||\n");
		    printf(" || PULSA UN NUMERO...      ||\n");
			printf(" =============================\n");		
			break;	
		case 5:
			printf(" ||=========================||\n");
		    printf(" ||    OK        Atras      ||\n");
			printf(" =============================\n");		
			break;	
			
		default:
			break;
		}
}


void Pokedex(){
	system("cls");
	printf("Pokedex");
	system("PAUSE");
	estat1();
	
}
void Equipo(){
	system("cls");
	printf("Equipo");
	system("PAUSE");
	estat1();
	
}
void Inventario(){
	system("cls");
	printf("Inventario");
	system("PAUSE");
	estat1();
	
}
void Mapa(){
	system("cls");
	printf("Mapa");
	system("PAUSE");
	estat1();
	
}
void Guardar(){
	system("cls");
	printf("Guardar");
	system("PAUSE");
	estat1();
	
}
void Medalles(){
	system("cls");
	printf("Medalles");
	system("PAUSE");
	estat1();
	
}
void Credits(){
	system("cls");
	printf("Credits");
	system("PAUSE");
	estat1();
	
}
void Exit(){
	system("cls");
	printf("Pokedex");
	system("PAUSE");
	estat1();
}


void imgPortada(){
	
	printf("Virtual Monster ASCII - C\n\n\n\n");
	printf("05                           \n");
	printf("102                        78\n");
	printf(" 40  77                 77 80\n");
	printf("  777 777             777 787\n");
	printf("     7  77    77    77  777  \n");
	printf("        7 777 7 7777 7       \n");
	printf("        7            77      \n");
	printf("          7         7 7      \n");
	printf("         801      1887       \n");
	printf("       77791   7  747 7      \n");
	printf("       801   77777  7501     \n");
	printf("       7807         5087     \n");
	printf("        777         727      \n");
	printf("                             \n\n");
}






void rundown(int a){					// la variable a ens indicara quina imatge imprimir de runfront 
	
	printf("\n");
	switch(a) {
	  case 1:							//**1 usada per a animacio stop	
		printf("\n\n    BBBBBi           vBQBBB  \n");		
		printf("    QBBBBLBB       .BuEBBBB  \n");		
		printf("     .BE  .IBP7vL7MB7   BB   \n");
		printf("      Bd    BBirriBP    BB   \n");
		printf("       BB            .PBS    \n");
		printf("       SU             iBr    \n");
		printf("      Bs                gQ   \n");
		printf("  iBBBBi    i.    :i    BB   \n");
		printf("  vBM7BPvJ2IR: :. rgIu1uv    \n");
		printf("  YBgrBBBBBR  :7i.  BBBBu    \n");
		printf("   UEBB2 JJYv5bvSgU7uv: BB   \n");
		printf("       B7   Udr7rrZY  .BZ    \n");
		printf("       BB1qKr.    .rSKBBj    \n");
		printf("       BBSr:::....:::ZBBX    \n");
		printf("        7Bq:iMBBBBd:7B2      \n");
		printf("          .ER.    .BL        \n");
		break;	  	

	  case 2:
		printf("\n     QBBBBi           2BBBBB \n");
		printf("     BBBQgLBB       :BLQBBBB \n");
		printf("      :B2  :PBX7Lv7QBi   BB  \n");
		printf("       B7    BgirriBJ    BB  \n");
		printf("        BB            :DBr   \n");
		printf("        DL             rB:   \n");
		printf("       Br                BQ  \n");
		printf("  BBQBBB.    r.    ::    BB  \n");
		printf("  BB7rsBXv11Xg. i  7M2UJur   \n");
		printf("  BB::iBgBBBd  iri. .BBBQY   \n");
		printf("  iBBQBB: uYJ7PKLXgJvsv. BB  \n");
		printf("    :gBBB.   dXr77rQr  :BP   \n");
		printf("       dBQJK5i...   iqBBB.   \n");
		printf("        BBjr:....   iBQQ     \n");
		printf("         LBBM   :BBQBg       \n");
		printf("           :gq7BBBQ          \n");
		printf("             SBBR            \n");
	 	break;
	 	
	 case 3:										//**1 usada per a animacio stop
	 	printf("\n     rr7               :i7i \n");
		printf("    BQBBBB.          BBQBBB \n");
		printf("    BBBBB5BB        BPQBBBB \n");
		printf("     :BM  :XB2iiriKBL   BB. \n");
		printf("      Qg    UI.:..KL    BZ  \n");
		printf("       BB            .QBJ   \n");
		printf("       Kd             rBr   \n");
		printf("      Bv                gQ  \n");
		printf("  LBBBBi :::d7    LP::  QB  \n");
		printf("  7QbiBK7u2IB: :  7BI1JLv   \n");
		printf("  LBRvBBMBQg  .7:. .RBBQj   \n");
		printf("   .vQBX .::uRg2EQRL:.  BB  \n");
		printf("       BQ   j2.:..Kv  :B5   \n");
		printf("       BBr257.    .7UYBBX   \n");
		printf("       qBBv. iJusj: :BBB7   \n");
		printf("         MKYubQRQMZLIP.     \n");
	 	printf("          .BB.    :BS       \n");
	 	break;
	 	
	case 4:
	 	printf("    irr.               rri   \n");
		printf("    QBQBBB          .BBBBBB  \n");
		printf("    BBBBBqB        BBUBBBBB  \n");
		printf("    .BB   vBXirri5BP.  QB:   \n");
		printf("     bB    vP.::.2I    DB    \n");
		printf("      YBQ:            BB     \n");
		printf("      rBr             DS     \n");
		printf("     Bq                1B    \n");
		printf("    BBU  .:qY    rZ::: YB    \n");
		printf("    BBK7YU2Br  : iBS12Yv.    \n");
		printf("    BBQPBBQ  .i7:  DBBBI.    \n");
		printf("     BQ  .:sgQbSZQJi:. BB    \n");
		printf("      qQi  7P.:::22   BQ     \n");
		printf("      SBBdvi   ..:r2s7BB     \n");
		printf("        KBBKi:. ...:2BBK     \n");
		printf("          7gQBBr  .BBB       \n");
		printf("             BBQgrbB.        \n");
		printf("              :BBBU          \n");
	 	break;
	 	
	default : 	
		printf("  ERROR 404- rundown \n");
		system("PAUSE");
	 	break;

	}
}

void runleft(int a){
	printf("\n");
	switch(a){
		
		case 1:
			printf("\n\n");
			printf("                 rBBBBBg      \n");
			printf("         i:...XBBBBBBBZ       \n");
			printf("     .J2PgBBBBr .gBBBBrvb.    \n");
			printf("    SSgD.   . rQBQ5QBBBQBB    \n");
			printf("   .X.        uBg.  iBBBg     \n");
			printf("  u:         .     :BB        \n");
			printf("  BB.          .jBBMbg  EBQBBB\n");
			printf("   UB:  BE     :ii7YPQMI7i:vBB\n");
			printf("     jBrivr77..:.i75irBM.   BB\n");
			printf("     BB5.7QDgUi.:..:YQBK :gBZ:\n");
			printf("     iBS  YSgDr..:.7vUBZ BBd  \n");
			printf("       MZi7i:...:.. .rBBZBB   \n");
			printf("         BBBr. .... JBvBBB    \n");
			printf("         :BBi...:ZBBBQBD      \n");
			printf("          :gBBBBBB:.          \n");
			printf("            .....             \n");
			
			break;
			
		case 2:
			printf("\n               gBBBBBZ        \n");
			printf("            qBBBBBBBB:        \n");
			printf("    ..QBBBBB7.rBBBBB          \n");
			printf(" :P2SU    . jQBb7DBQBBBs      \n");
			printf(" iS.       .5Bq.  :BBBS       \n");
			printf(".          :     .BBi         \n");
			printf("QD.           rPBRBK  rKS51gQi\n");
			printf(" UBi  BX    .:iirsSgBE7rriiBBQ\n");
			printf("   1B..ir7r..:.7IQirQE.    KQR\n");
			printf("   BBj:LZPPr:.:::ivQB2. .iJBBv\n");
			printf("   iEu  rrrZr....r7DQE: SBd.  \n");
			printf("     BBiS5Pr:.:... .BBsrBQ    \n");
			printf("     BBBBBB: ......1BX:BBg    \n");
			printf("      .MMU2U.  .:i:rBBBBB     \n");
			printf("       SBBBBBBBR:.QB          \n");
			printf("        .  ...:QBBB           \n");
			printf("                .:            \n");
			break;
			
		case 3:

			printf("\n\n                 BBBBBQE      \n");
			printf("             .BBBBBBBBB:      \n");
			printf("      .1BBQBQQ...BBBBB.       \n");
			printf("   .I5K:     .BBB5JBBBBBB     \n");
			printf("   :K        7BBB   BBBB      \n");
			printf("  :         :.     PBBP       \n");
			printf(" 2Bb:          .:ZQBB:  IIuEB7\n");
			printf("   LB. sB1    :::isIKRBEiiiBBQ\n");
			printf("     Q7.:irv:.::.7RX sBE   JBB\n");
			printf("     BB:rYPEs::.::irXBBu :vQBK\n");
			printf("     sB.  iPPv.:..:v7ZQUvBB.  \n");
			printf("      iQJJ1i....:.. iYgQBQ    \n");
			printf("       .BBQg ..... :BBiBBB    \n");
			printf("         2BB. ...PBBBBBQ      \n");
			printf("           BBBBBQs            \n");
			printf("            :...:             \n");
			break;
			
		case 4:
			printf("\n               .BBBBBB        \n");
			printf("             BBBBBBBBR        \n");
			printf("       BBBQBBY.EBBBBB         \n");
			printf("   uBRZ. .L:.7bgBBBBBQBB      \n");
			printf("  i:        .JP:   7BBi       \n");
			printf(" i         .i     vBB         \n");
			printf(" BJ            iKQBBv  :::::::\n");
			printf("  dr   Er     :sBX7SbJ5KPq2ZBB\n");
			printf("   vB2..r1Lr.:.:IPg:uB  .. .BB\n");
			printf("   5BBKYUIjr::::i::iBQ. .  :BB\n");
			printf("   vBBr .qgZXi...ivsBB   5QB  \n");
			printf("     .2jKU:::.:....:bE .YBB   \n");
			printf("       rBB .....   gB. BBBi   \n");
			printf("        BB...  .1JvBBBBBB:    \n");
			printf("       iBD:iiBBBBBBb 7r       \n");
			printf("         YBQBr                \n");
			printf("          ...                 \n");
			break;

		default : 	
			printf("  ERROR 404- runleft \n");
			system("PAUSE");
	 		break;
	}

}

void runright(int a){
	printf("\n");
	switch(a){
		
		case 1:
			
			printf("\n\n       :7iirr                 \n");
			printf("       BBBBBBBB7              \n");
			printf("        BBBBBBQBBBBBBX        \n");
			printf("     iM7BBBBBU :BBBQPKujS.    \n");
			printf("     qBBBB.. DQd      :i:57   \n");
			printf("       gBK      v.            \n");
			printf("        DBQs              :B  \n");
			printf(" BBgBBE uQ7MBK:      i   .BP  \n");
			printf(" BI ...BqrgKs:::..::v2 .LY    \n");
			printf(" Bs   .BP.r7j:..:rUK7:UBBv    \n");
			printf(" 5BQU. BBUi:...iLIKbv:iBBg    \n");
			printf("   BBBiBS:i::..:vvuv  Qj:     \n");
			printf("   7BBQXRu ..:.... BBB        \n");
			printf("    .QBgBQ..:.. .:rBB         \n");
			printf("       BgZBBBDLus5KBJ         \n");
			printf("             rBRQgR           \n");
			break;

		case 2:
			printf("\n        .7riir                \n");
			printf("        BBQBQBQBB.            \n");
			printf("         gBQBQBBQBBBBBB.      \n");
			printf("       qLBBBBBb  7QBBKbXuS.   \n");
			printf("       BBQBqi 2BBr      ::1u  \n");
			printf("        uBBr     :v           \n");
			printf("         7BQB.              BI\n");
			printf(" BBQBBQR iBd7BE:      r.   gQi\n");
			printf(" Q7 ....BR:uQUi.:...:rPr iu   \n");
			printf(" B:  .  BR.irsi.::.LPv:rvBM   \n");
			printf(" EBQU:  BBd17...:rv5ZJii:BB   \n");
			printf("   BBD  Bg.ir:.::ir1u. :Qs    \n");
			printf("   KBBB.:QBi  ..:.. QBBs      \n");
			printf("    .BBXiBBY     .  BB        \n");
			printf("       QBgIBBBBvL:  JBP.      \n");
			printf("           :BBQgQBBBQi        \n");
			printf("                  BB.         \n");
			break;
			
		case 3:
			printf("\n\n        7BBBBB                \n");
			printf("        BBBBBBBQQ             \n");
			printf("         gQBBBBBggEQRQZ:      \n");
			printf("       BBBBBBBg.:ivZqirJdB1   \n");
			printf("       BBBBU. rBBS        iB  \n");
			printf("        qBBr     :s.          \n");
			printf("         .BBBu.             BM\n");
			printf("  BBPMQg:7BS7RE:      Mv  .B7 \n");
			printf("  BB    BB.IBU:.:. ..iBs .Y:  \n");
			printf("  BB    QB:ivur.:..7Xv::iBB   \n");
			printf("   PQBB PBP5Y:.::7uZgY ..BB   \n");
			printf("     BBZQP .:...:::r7. iBv    \n");
			printf("     gBBQXQr  ..... 2BBR.     \n");
			printf("       QBBBBUs:     BB        \n");
			printf("        :Y 7DQQBBBQBB7        \n");
			printf("              .BBBBQ:         \n");
			break;
			
		case 4:
			printf("\n\n        .7rir:                \n");
			printf("        BBBBBBQBB.            \n");
			printf("          BBBBBBBBBBBBBr      \n");
			printf("      .Bu7BBBBQ: rBBBDqXju.   \n");
			printf("      jBBBBP. jQBv      :iJQ: \n");
			printf("        :BB7     :i           \n");
			printf("          BBP               uB\n");
			printf("QBBBQBBq  BMPBgj.     .:  .JBj\n");
			printf("BQX ...:BB7sZ7i::..:::U7 YYr  \n");
			printf("BBu  . .ZB7:rYi:..:SISi:QBP   \n");
			printf(":BBQQ. .PBBu:....isSXS7.2BB   \n");
			printf("   iBP rQBi::..:.75rii  M     \n");
			printf("    BBBrQB: ..:.. 7QBBBBB     \n");
			printf("     BB71EBr.:...  i1BQBB     \n");
			printf("      sBBQB5Ju2u17dQBBBi      \n");
			printf("       vi  7MQRMBgM           \n");

			break;
			
		default : 	
			printf("  ERROR 404- runlright \n");
			system("PAUSE");
	 		break;
	}
	
}

void runup(int a){
	printf("\n");
	switch(a){
		
		case 1:

			printf("\n\n   7QEZP              MZEB. \n");
			printf("   BBBBBB:          JBBBBBQ   \n");
			printf("   bQBBD BQ       1Br BBBB:   \n");
			printf("    BB7   bBBQBQBQB.  .BB     \n");
			printf("    .BEU  .s.   .Y.  .dB.     \n");
			printf("      5Br            DB       \n");
			printf("     s77              :.      \n");
			printf("    BBv             i5BBB1r.  \n");
			printf("    uB5.          7BQrrrrrBB  \n");
			printf("     LBr:.       MBE     BB   \n");
			printf("    iBSi.uqr:..BQBBB: ....BB  \n");
			printf("    BBE  :Ug27BB::::.UBBBBv   \n");
			printf("    .QEd..vPi:BB  DBBBB7      \n");
			printf("      BBJ :KBQBBBBBBIQB       \n");
			printf("      rBBi  BBBBBBv.UBP       \n");
			printf("       :QBMUriivZDDP          \n");

			break;
			
		case 2:

			printf("\n   XBBBP              BBBB   \n");
			printf("   BBBBQB           iBBBBQs   \n");
			printf("   BBBBZ:B7       LB7rBBBB.   \n");
			printf("    BB:   BBBBBQBBE   :B1     \n");
			printf("    DBS.  iX:   :X:   qB7     \n");
			printf("      BBi            QB       \n");
			printf("    .Sri              :.      \n");
			printf("    BBi              .BBBRSqi \n");
			printf("    QB7             7BRQBBQBB \n");
			printf("     :5M..          BB     UB \n");
			printf("    XB2:.qdYi:.rBBQBBi :::.BB \n");
			printf("    BQ1 .:UQgKIBB:i:. rBBBBB  \n");
			printf("    XBK: :JdLi.BB   BBBBd     \n");
			printf("      BBr :vriBBBBBBBBB:      \n");
			printf("      :BB7.:.:BRgBQBQB:       \n");
			printf("        BBU...BBBBBBB.        \n");
			printf("         .gBQQBB              \n");
			break;
			
		case 3:
			printf("\n\n   QRR               UgQL \n");
			printf("   BBBBQr         :BQBBBB     \n");
			printf("   BBB. BB.      ZB :qBBM     \n");
			printf("    B:   .BBBBBBBQ    BB      \n");
			printf("    MQ:   r.    7.  :vB:      \n");
			printf("     BB            .MB        \n");
			printf("    7j.              .i       \n");
			printf("    B:            .dXUBBii    \n");
			printf("    Bj           jB777r:BBB   \n");
			printf("     B2.:i       BB     :BQ   \n");
			printf("    BK.:uDY..7BBBBu  .. uQB   \n");
			printf("    BJ .:rbsQBB7:::iPBBBg     \n");
			printf("    2Bi :iS:BBB. QBBBBQ       \n");
			printf("     BB ..rBBBBBBBB:BB:       \n");
			printf("     KBQi  BBBBQBr:BBB        \n");
			printf("       5ZBQJirii5gPr          \n");
			break;
			
		case 4:
			printf("\n   rBBBB              BBBB: \n");
			printf("   BBQBBB           .BBBBBB   \n");
			printf("   1BBBB:SBi       dXiQBBBv   \n");
			printf("     BB   .BBBBBBBB7   uB:    \n");
			printf("     RBr   rS.   rX.  :QB:    \n");
			printf("       B5            sB7      \n");
			printf("     .U7              .::     \n");
			printf("     BB            JBQMBBB    \n");
			printf("     BB.         iQBBBQQdBB   \n");
			printf("      .Ri..      BBr     QB   \n");
			printf("     PBr.JQSLsBBBBQ. i:..Bd   \n");
			printf("     BB. .rLMBB::.  ZQBQBY    \n");
			printf("     dBP .::vBQ  PQBP:JQB     \n");
			printf("       sBuiZBQBBBBBi 7Br      \n");
			printf("        rBBBB7BBBP. 2BM.      \n");
			printf("         :BBBBBB  .gBJ        \n");
			printf("             .BBdQBP          \n");
			break;
			
		default : 	
			printf("  ERROR 404- runup \n");
			system("PAUSE");
	 		break;
	}
	
}
