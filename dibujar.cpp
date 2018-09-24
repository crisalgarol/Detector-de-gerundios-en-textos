#include <winbgim.h>

void dibujar (){
	initwindow(830,550);
	
	settextstyle(3, HORIZ_DIR, 2);
	
	//Lineas que conecte horizontalmente a cada caso
	line(210,280,474,280);
	line(474,280,592,280);
	line(592,280,550,280);
	outtextxy(302, 269, ">");
	outtextxy(432, 269, ">");
	outtextxy(552, 269, ">");
	
	//Etiquetas de i, n, g
	setcolor (COLOR(255,149,0));
	outtextxy(295,315, "i");
	outtextxy(402,315, "n");
	outtextxy(534,315, "g");
	setcolor(15);

	//Arcos Conectores
	
	//CONECTOR CIRCULAR DE i
	arc(300,280,0,270,28);
	arc(300,281,0,270,28);
	outtextxy(292,294, ">");
	
//ARCO DE 	Q1 A Q0	
	arc(280,280,0,180, 60);
	arc(280,281,0,180, 60);
	outtextxy(234,226, "v");

	
	//ARCO DE N a i
	arc(405,281,0,180, 60);
	arc(405,282,0,180, 60);
	outtextxy(360,226, "v");
	
	
	//ARCO DE G A N	
	arc(467,280,0,180, 120);
	outtextxy(350,223, "v");

	
	//ARCO DE G A Q0
	outtextxy(199,320, "^");
	arc(330, 300, 180,360, 130);



	//ARCO DE Q A G
	arc(400,280,0,180, 200);
	outtextxy(204,217, "V");

		
	//CIRCULO ROJO Q0


	outtextxy(165,305, ">");
	arc(165,280,0,270,38); //conector circular
	arc(165,281,0,270,38);

	setcolor(COLOR(255, 59, 48)); //COLOR DE LINEA ROJO
	setfillstyle(1, COLOR (255, 59, 48)); //ROJO
	fillellipse(210,280, 43, 45); //CIRCULO INICIAL
	
			
	setcolor(COLOR(255, 149, 0)); //COLOR NARANJA
	setfillstyle(1, COLOR (255, 149, 0));
	fillellipse(350,280, 38, 38);	//Q1
	fillellipse(480,280, 38, 38);	//Q2
	fillellipse(600,280, 38, 38);	//Q3
	circle (600,280,43);
	circle (600,280,45);
	
	
	//TEXTOS
	outtextxy(45,250, "No  es \"i\"");
	outtextxy(240, 190, "No \"i\" o \"n\" ");
	outtextxy(635, 230, "\"ing\" encontrado");
	outtextxy(397, 194, "\"i\" vista");
	outtextxy(292, 438, "No es \"g\"");
	
	//TEXTO INICIO	 
	setbkcolor(0);
	setcolor(15);
	outtextxy(145,330,"Inicio");
	
	setbkcolor(COLOR(255,59,48));
	outtextxy(198,276, "q0");
	
	setbkcolor(COLOR(255,149,0));
	outtextxy(338,274, "q1");
	outtextxy(470,274, "q2");
	outtextxy(588,274, "q3");

	getch();
	closegraph();
	
}

