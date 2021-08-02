#include<stdio.h>
#include<windows.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
# define PI           3.14159265358979323846

int scene = 0,x=0,y=-195,opt=0, clouds =0; ;
int wx1[] ={-670,-150,418};
int wy1=-232;
float cx[]={-540,-150,520,-30,-540,-150,520,-30};
float cy[]={210,130,250,250,-210,-130,-250,-250};
float i =-245;
float j= 400;
int Bombed=0, flag2 = 0,h=0,flag3=0;
float expFactor;
float explodeTx = 1.0;
float explodeTy = 1.0;

void options(int id)//menu option
{
    if(id == 1 && scene == 9)
        opt = 1;
    else if (id == 2)
       exit(0);
}

typedef struct stColor
 {
    double red, green, blue;
    double alpha;
}
RgbColor;

RgbColor createColor(int red, int green, int blue, double alpha)
{
    RgbColor color;
    color.red = (double) red / 256;
    color.green = (double) green / 256;
    color.blue = (double) blue / 256;
    color.alpha = (double) alpha;
    return color;
}

RgbColor color;

void Circle(float cx, float cy, float cz, float r, int num_segments)
{

	int ii;
	float theta, x, y, i , j;
	if(clouds == 1) j=num_segments/2;  //half circle or full circle
	else j=num_segments;
	glBegin(GL_POLYGON);
        for(ii = 0; ii < j; ii++)
        {
            i = (float)ii/(float)num_segments;
            theta = 2.0f*3.1415926f*i;
            x = r * cosf(theta);
            y = r * sinf(theta);
            glVertex3f(x + cx, y + cy, cz);
        }
	glEnd();
}

void Text(char text[], int x, int y, int z)
{
    // The color
    glColor3f(1, 1, 1);
    // Position of the text to be printer
    glRasterPos3f(x, y, z);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void printLines(char **s, int offsetY, int n, int x, int y)
{
    int i = 0;
    for (; i < n; i++)
    {
        Text(s[i],x, y + offsetY,0 );
        offsetY -= 35;
    }
}

void Candles()
{

    glBegin(GL_QUADS); //candle
        color = createColor(227, 242, 249, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex3f(-40,-360,0);
        glVertex3f(0,-360,0);
        glVertex3f(0,-150,0);
        glVertex3f(-40,-150,0);
    glEnd();

    glBegin(GL_LINES); //candle thread
        color = createColor(0, 0, 0, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex3f(-20,-150,0);
        glVertex3f(-20,-100,0);
    glEnd();
}

void Flames(int xflame, int yflame)
{
    glBegin(GL_POLYGON);

        color = createColor(230, 78, 58, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f(xflame,yflame+20);

        color = createColor(241, 119, 57, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f((xflame+15.0),(yflame-12.0));

        color = createColor(246, 166, 63, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f((xflame+18.5),(yflame-26.0));

        color = createColor(241, 196, 101, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f((xflame+18.0),(yflame-45.0));

        color = createColor(6, 206, 255, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f((xflame),(yflame-77));

        color = createColor(241, 196, 101, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f((xflame-18.0),(yflame-45.0));

        color = createColor(246, 166, 63, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f((xflame-18.5),(yflame-26.0));

        color = createColor(241, 119, 57, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f((xflame-15.0),(yflame-12.0));

    glEnd();
}

void MainScene1()
{
    glBegin(GL_QUADS);
        color = createColor(69, 46,69, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f(-670.0,350.0);
        glVertex2f(670.0,350.0);
        color = createColor(23, 63, 46, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f(670.0,-350.0);
        glVertex2f(-670.0,-350.0);
    glEnd();

    glClearColor(1.0,1.0, 1.0, 1.0);
    char h1[] = "Scene 1";
    char h2[] = "ENOLA GAY";
    char *name1[] = {"The Enola Gay (Model number B-29-45-MO, Serial number 44-86292, Victor number 82) was built by the Glenn L. Martin Company (later part of",
"Lockheed Martin) at its bomber plant in Bellevue, Nebraska, located at Offutt Field, now Offutt Air Force Base. The bomber was one of the first",
"fifteen B-29s built to the 'Silverplate' specification— of 65 eventually completed during and after World War II—giving them the primary ability",
"to function as nuclear 'weapon delivery' aircraft. These modifications included an extensively modified bomb bay with pneumatic doors and British",
"bomb attachment and release systems, reversible pitch propellers that gave more braking power on landing, improved engines with fuel injection and",
"better cooling,and the removal of protective armor and gun turrets."
};
    char message1[] = "Press 1 for next scene";

    Text(h1, -70, 320, 0);
    Text(h2, -90, 170, 0);
    printLines(name1, 0, 6,-600, 0);
    Text(message1, -500, -300, 0);
}

void MainScene2()
{
    glBegin(GL_QUADS);
        color = createColor(69, 46,69, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f(-670.0,350.0);
        glVertex2f(670.0,350.0);
        color = createColor(23, 63, 46, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f(670.0,-350.0);
        glVertex2f(-670.0,-350.0);
    glEnd();

    glClearColor(1.0,1.0, 1.0, 1.0);
    char h1[] = "Scene 2";
    char h2[] = "HIROSHIMA City";
    char *name1[] = {"At the time of its bombing, Hiroshima was a City of industrial and military significance. A number of military units were located nearby,",
"the most important of which was the headquarters of Field Marshal Shunroku Hata's Second General Army, which commanded the defense of all of",
"southern Japan,and was located in Hiroshima Castle. Hata's command consisted of some 400,000 men, most of whom were on Kyushu where an Allied",
"invasion was correctly anticipated.Also present in Hiroshima were the headquarters of the 59th Army, the 5th Division and the 224th Division,",
"a recently formed mobile unit.The City was defended by five batteries of 70 mm and 80 mm (2.8 and 3.1 inch) anti-aircraft guns of the 3rd",
"Anti-Aircraft Division, including units from the 121st and 122nd Anti-Aircraft Regiments and the 22nd and 45th Separate Anti-Aircraft Battalions.",
"In total, an estimated 40,000 Japanese military personnel were stationed in the City.Hiroshima was a supply and logistics base for the Japanese",
"military."
};
    char message1[] = "Press 1 for next scene";
    char message2[] = "Press 2 for previous scene";

    Text(h1, -70, 320, 0);
    Text(h2, -80, 170, 0);
    printLines(name1, 0, 8,-600, 0);
    Text(message1, -500, -300, 0);
    Text(message2, 300, -300, 0);
}

void MainScene3()
{
    glBegin(GL_QUADS);
        color = createColor(69, 46,69, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f(-670.0,350.0);
        glVertex2f(670.0,350.0);
        color = createColor(23, 63, 46, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f(670.0,-350.0);
        glVertex2f(-670.0,-350.0);
    glEnd();

    glClearColor(1.0,1.0, 1.0, 1.0);
    char h1[] = "Scene 3";
    char h2[] = "LITTLE BOY";
    char *name1[] = {"'Little Boy' was the codename for the type of atomic bomb dropped on the Japanese City of Hiroshima on 6 August 1945 during World War II.",
"It was the first nuclear weapon used in warfare. The bomb was dropped by the Boeing B-29 Superfortress Enola Gay piloted by Colonel Paul W:",
"Tibbets, Jr., commander of the 509th Composite Group of the United States Army Air Forces and Captain Robert A. Lewis. It exploded with an",
"energy of approximately 15 kilotons of TNT (63 TJ) and caused widespread death and destruction throughout the City. The Hiroshima bombing was",
"the second man-made nuclear explosion in history, after the Trinity nuclear test."
};
    char message1[] = "Press 1 for next scene";
    char message2[] = "Press 2 for previous scene";

    Text(h1, -70, 320, 0);
    Text(h2, -85, 170, 0);
    printLines(name1, 0, 5,-600, 0);
    Text(message1, -500, -300, 0);
    Text(message2, 300, -300, 0);
}

void MainScene4()
{
    glBegin(GL_QUADS);
        color = createColor(69, 46,69, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f(-670.0,350.0);
        glVertex2f(670.0,350.0);
        color = createColor(23, 63, 46, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f(670.0,-350.0);
        glVertex2f(-670.0,-350.0);
    glEnd();

    glClearColor(1.0,1.0, 1.0, 1.0);
    char h1[] = "Scene 4";
    char h2[] = "BOMBING OF HIROSHIMA";
    char *name1[] = {"People on the ground reported a pika —a brilliant flash of light—followed by a don —a loud booming sound.Some 70,000–80,000 people, around",
"30 percent of the population of Hiroshima at the time, were killed by the blast and resultant firestorm,and another 70,000 were injured.It is",
"estimated that as many as 20,000 Japanese military personnel were killed.U.S. surveys estimated that 4.7 square miles (12 km2) of the City were",
"destroyed. Japanese officials determined that 69 percent of Hiroshima's buildings were destroyed and another 6 to 7 percent damaged.",
"Some of the reinforced concrete buildings in Hiroshima had been very strongly constructed because of the earthquake danger in Japan, and their",
"framework did not collapse even though they were fairly close to the blast center. Since the bomb detonated in the air, the blast was directed",
"more downward than sideways, which was largely responsible for the survival of the Prefectural Industrial Promotional Hall, now commonly known",
"as the Genbaku (A-bomb) dome, which was only 150 m (490 ft) from ground zero (the hypocenter)."
};
    char message1[] = "Press 1 for next scene";
    char message2[] = "Press 2 for previous scene";

    Text(h1, -70, 320, 0);
    Text(h2, -100, 170, 0);
    printLines(name1, 0, 8,-600, 0);
    Text(message1, -500, -300, 0);
    Text(message2, 300, -300, 0);
}

void MainScene5()
{
    glBegin(GL_QUADS);
        color = createColor(69, 46,69, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f(-670.0,350.0);
        glVertex2f(670.0,350.0);
        color = createColor(23, 63, 46, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f(670.0,-350.0);
        glVertex2f(-670.0,-350.0);
    glEnd();

    glClearColor(1.0,1.0, 1.0, 1.0);
    char h2[] = "CONCLUSION";
    char *name1[] = {"As a result of the atomic bombing on August 6th, 1945, Hiroshima City was completely destroyed, losing many medical facilities and medical",
"professionals. The rescue of survivors was extremely difficult. However, Hiroshima’s medical reconstruction was quicker than expected. It was",
"revealed that several factors contributed to this early reconstruction: Medical facilities had been constructed during wartime, and promotion",
"measures on training physicians and nurses were implemented. Also, unprecedented improvement of medical treatment had been realized in the military",
"City of Hiroshima. All those medical facilities were restored after the war, like a phoenix rising from the ashes. Yong physicians who had been",
"conscripted came back and passionately engaged in medical Bombe for A-bomb survivors. However, this report tells only part of the story, and there",
"remains much to be investigated by future research."
};
    char message1[] = "Press 1 for next scene";
    char message2[] = "Press 2 for previous scene";

    Text(h2, -90, 170, 0);
    printLines(name1, 0, 7,-600, 0);
    Text(message1, -500, -300, 0);
    Text(message2, 300, -300, 0);
}

void MainScene6()
{
    glPushMatrix();
    glBegin(GL_QUADS);
        color = createColor(69, 46,69, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f(-670.0,350.0);
        glVertex2f(670.0,350.0);
        color = createColor(23, 63, 46, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex2f(670.0,-350.0);
        glVertex2f(-670.0,-350.0);
    glEnd();

    glClearColor(1.0,1.0, 1.0, 1.0);
    char h1[] = "COMPUTER GRAPHICS MINI PROJECT";
    char h2[] = "A";
    char h3[] = "PROJECT ON";
    char h4[] = "BOMBING OF HIROSHIMA";
    char h5[] = "BY";
    char h6[] = "PUNEETH K SHETTY";
    char h7[] = "4SF18CS133";
    char h8[] = "SPANDAN H SHETTY";
    char h9[] = "4SF18CS156";
    char message2[] = "Press 2 for previous scene";

    Text(h1, -190, 240, 0);
    Text(h2, -40, 190, 0);
    Text(h3, -100, 140, 0);
    Text(h4, -150, 90, 0);
    Text(h5, -40, 40, 0);
    Text(h6, -400, -220, 0);
    Text(h7, -400, -240, 0);
    Text(h8, 200, -220, 0);
    Text(h9, 200, -240, 0);
    Text(message2, 300, -300, 0);

    Candles();
    if(opt == 1)
    {
        Flames(-20,-50);
    }
    glPopMatrix();
}

void reset()
{
    i =-245;
    j= 400;
    h=0;
    Bombed=0, flag2 = 0,flag3=0;
    expFactor=0;
    explodeTx = 1.0;
    explodeTy = 1.0;
}

void explode()
{
    color = createColor(237, 105, 74, 0);
    glColor3f(color.red, color.green, color.blue);
    Circle(-25, -130,0, 1.0f * expFactor,200);

    color = createColor(216, 85, 58, 0);
    glColor3f(color.red, color.green, color.blue);
    Circle(-5, -135,0, 1.0f * expFactor,200);
}

void Clouds(int r)
{
    int c = 0;
    clouds=1;
    for(;c<8;c++)
    {
        color = createColor(255, 255, 255, 0);
        glColor3f(color.red, color.green, color.blue);

        //clouds half circle
        Circle(cx[c],cy[c],0,r,200);
        Circle(cx[c]+40,cy[c]+20,0,r,200);
        Circle(cx[c]+70,cy[c],0,r,200);
        Circle(cx[c]+100,cy[c],0,r,200);
        Circle(cx[c],cy[c],0,r,200);
        Circle(cx[c]+40,cy[c]+20,0,r,200);
        Circle(cx[c]+70,cy[c],0,r,200);
        Circle(cx[c]+100,cy[c],0,r,200);

        glBegin(GL_POLYGON); //fill polygon
            glColor3f(color.red, color.green, color.blue);
            glVertex2f(cx[c]-5,cy[c]);
            glVertex2f(cx[c]+40,cy[c]+45);
            glVertex2f(cx[c]+70,cy[c]);
            glVertex2f(cx[c]+100,cy[c]);
            glVertex2f(cx[c]-5,cy[c]);
            glVertex2f(cx[c]+40,cy[c]+45);
            glVertex2f(cx[c]+70,cy[c]);
            glVertex2f(cx[c]+100,cy[c]);
        glEnd();


        if(scene == 1|| scene == 3 || scene == 5 || scene == 7 && !Bombed)
        {
            if(cx[c]+300>-670)
             cx[c]=cx[c]-0.03;
            else
             cx[c]=670;
        }

    }
    clouds=0;
}

void Jet()
{
    if(Bombed == 0)
    {
        if(scene == 3)
            i+=0.6;
        else
            i+=0.7;
    }

    glBegin(GL_POLYGON); //body
        color = createColor(0, 0, 0, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex3f(-600+i,130,0);
        glVertex3f(-300+i,130,0);
        glVertex3f(-350+i,170,0);
        glVertex3f(-550+i,170,0);
        glVertex3f(-600+i,245,0);
    glEnd();

    glBegin(GL_POLYGON); //glass
        color = createColor(168, 225, 232, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex3f(-380+i,150,0);
        glVertex3f(-340+i,150,0);
        glVertex3f(-360+i,160,0);
        glVertex3f(-380+i,160,0);
    glEnd();
}

void Bomb()
{
    if(Bombed == 0)
    {
        if(scene == 8)
            j-=4;
        else
            j-=0.4;
    }

    glBegin(GL_POLYGON);
        color = createColor(34, 139, 34, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex3f(-5,205+j,0);
        glVertex3f(0,200+j,0);
        glVertex3f(100,200+j,0);
        glVertex3f(120,215+j,0);
        glVertex3f(100,230+j,0);
        glVertex3f(0,230+j,0);
        glVertex3f(-5,225+j,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    color = createColor(34, 139, 34, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex3f(100,215+j,0);
        glVertex3f(140,205+j,0);
        glVertex3f(140,225+j,0);
        glEnd();

    glLineWidth(12.5);
}

void City()
{
     glBegin(GL_QUADS);//b1
     color = createColor(163, 163, 194,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,-210,0);
     glVertex3f(-500,-210,0);
     glVertex3f(-500,100,0);
     glVertex3f(-670,100,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass1
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,-200,0);
     glVertex3f(-500,-200,0);
     glVertex3f(-500,-190,0);
     glVertex3f(-670,-190,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass2
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,-180,0);
     glVertex3f(-500,-180,0);
     glVertex3f(-500,-170,0);
     glVertex3f(-670,-170,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass3
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,-160,0);
     glVertex3f(-500,-160,0);
     glVertex3f(-500,-150,0);
     glVertex3f(-670,-150,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass4
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,-140,0);
     glVertex3f(-500,-140,0);
     glVertex3f(-500,-130,0);
     glVertex3f(-670,-130,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass5
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,-120,0);
     glVertex3f(-500,-120,0);
     glVertex3f(-500,-110,0);
     glVertex3f(-670,-110,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass6
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,-100,0);
     glVertex3f(-500,-100,0);
     glVertex3f(-500,-90,0);
     glVertex3f(-670,-90,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass7
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,-80,0);
     glVertex3f(-500,-80,0);
     glVertex3f(-500,-70,0);
     glVertex3f(-670,-70,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass8
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,-60,0);
     glVertex3f(-500,-60,0);
     glVertex3f(-500,-50,0);
     glVertex3f(-670,-50,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass9
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,-40,0);
     glVertex3f(-500,-40,0);
     glVertex3f(-500,-30,0);
     glVertex3f(-670,-30,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass10
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,-20,0);
     glVertex3f(-500,-20,0);
     glVertex3f(-500,-10,0);
     glVertex3f(-670,-10,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass11
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,0,0);
     glVertex3f(-500,0,0);
     glVertex3f(-500,10,0);
     glVertex3f(-670,10,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass12
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,20,0);
     glVertex3f(-500,20,0);
     glVertex3f(-500,30,0);
     glVertex3f(-670,30,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass13
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,40,0);
     glVertex3f(-500,40,0);
     glVertex3f(-500,50,0);
     glVertex3f(-670,50,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass14
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,60,0);
     glVertex3f(-500,60,0);
     glVertex3f(-500,70,0);
     glVertex3f(-670,70,0);
     glEnd();

     glBegin(GL_QUADS);//b1 glass15
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,80,0);
     glVertex3f(-500,80,0);
     glVertex3f(-500,90,0);
     glVertex3f(-670,90,0);
     glEnd();

     glBegin(GL_QUADS);//b2
     color = createColor(102, 153, 153,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-500,-210,0);
     glVertex3f(-350,-210,0);
     glVertex3f(-350,60,0);
     glVertex3f(-500,60,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass1
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-495,-200,0);
     glVertex3f(-430,-200,0);
     glVertex3f(-430,-190,0);
     glVertex3f(-495,-190,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass2
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-495,-180,0);
     glVertex3f(-430,-180,0);
     glVertex3f(-430,-170,0);
     glVertex3f(-495,-170,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass3
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-495,-160,0);
     glVertex3f(-430,-160,0);
     glVertex3f(-430,-150,0);
     glVertex3f(-495,-150,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass4
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-495,-140,0);
     glVertex3f(-430,-140,0);
     glVertex3f(-430,-130,0);
     glVertex3f(-495,-130,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass5
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-495,-120,0);
     glVertex3f(-430,-120,0);
     glVertex3f(-430,-110,0);
     glVertex3f(-495,-110,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass6
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-495,-100,0);
     glVertex3f(-430,-100,0);
     glVertex3f(-430,-90,0);
     glVertex3f(-495,-90,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass7
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-495,-80,0);
     glVertex3f(-430,-80,0);
     glVertex3f(-430,-70,0);
     glVertex3f(-495,-70,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass8
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-495,-60,0);
     glVertex3f(-430,-60,0);
     glVertex3f(-430,-50,0);
     glVertex3f(-495,-50,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass9
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-495,-40,0);
     glVertex3f(-430,-40,0);
     glVertex3f(-430,-30,0);
     glVertex3f(-495,-30,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass10
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-495,-20,0);
     glVertex3f(-430,-20,0);
     glVertex3f(-430,-10,0);
     glVertex3f(-495,-10,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass11
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-495,0,0);
     glVertex3f(-430,0,0);
     glVertex3f(-430,10,0);
     glVertex3f(-495,10,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass12
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-495,20,0);
     glVertex3f(-430,20,0);
     glVertex3f(-430,30,0);
     glVertex3f(-495,30,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass13
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-495,40,0);
     glVertex3f(-430,40,0);
     glVertex3f(-430,50,0);
     glVertex3f(-495,50,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass14
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-420,-200,0);
     glVertex3f(-355,-200,0);
     glVertex3f(-355,-190,0);
     glVertex3f(-420,-190,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass15
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-420,-180,0);
     glVertex3f(-355,-180,0);
     glVertex3f(-355,-170,0);
     glVertex3f(-420,-170,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass16
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-420,-160,0);
     glVertex3f(-355,-160,0);
     glVertex3f(-355,-150,0);
     glVertex3f(-420,-150,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass17
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-420,-140,0);
     glVertex3f(-355,-140,0);
     glVertex3f(-355,-130,0);
     glVertex3f(-420,-130,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass18
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-420,-120,0);
     glVertex3f(-355,-120,0);
     glVertex3f(-355,-110,0);
     glVertex3f(-420,-110,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass19
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-420,-100,0);
     glVertex3f(-355,-100,0);
     glVertex3f(-355,-90,0);
     glVertex3f(-420,-90,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass20
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-420,-80,0);
     glVertex3f(-355,-80,0);
     glVertex3f(-355,-70,0);
     glVertex3f(-420,-70,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass21
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-420,-60,0);
     glVertex3f(-355,-60,0);
     glVertex3f(-355,-50,0);
     glVertex3f(-420,-50,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass22
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-420,-40,0);
     glVertex3f(-355,-40,0);
     glVertex3f(-355,-30,0);
     glVertex3f(-420,-30,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass23
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-420,-20,0);
     glVertex3f(-355,-20,0);
     glVertex3f(-355,-10,0);
     glVertex3f(-420,-10,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass24
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-420,0,0);
     glVertex3f(-355,0,0);
     glVertex3f(-355,10,0);
     glVertex3f(-420,10,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass25
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-420,20,0);
     glVertex3f(-355,20,0);
     glVertex3f(-355,30,0);
     glVertex3f(-420,30,0);
     glEnd();

     glBegin(GL_QUADS);//b2 glass26
     color = createColor(193, 215, 215,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-420,40,0);
     glVertex3f(-355,40,0);
     glVertex3f(-355,50,0);
     glVertex3f(-420,50,0);
     glEnd();

     glBegin(GL_QUADS);//b3 base
     color = createColor(179, 179, 204,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-350,-210,0);
     glVertex3f(-200,-210,0);
     glVertex3f(-200,-70,0);
     glVertex3f(-350,-70,0);
     glEnd();


     glBegin(GL_QUADS);//b3 middle
     color = createColor(179, 179, 204,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-325,-70,0);
     glVertex3f(-225,-70,0);
     glVertex3f(-225,70,0);
     glVertex3f(-325,70,0);
     glEnd();

     glBegin(GL_QUADS);//b3 top
     color = createColor(0,0, 0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-280,70,0);
     glVertex3f(-270,70,0);
     glVertex3f(-270,210,0);
     glVertex3f(-280,210,0);
     glEnd();

     glBegin(GL_TRIANGLES);//b3 triangular glass
     color = createColor(255, 253, 208,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-310,0,0);
     glVertex3f(-240,0,0);
     glVertex3f(-275,50,0);
     glEnd();

     glBegin(GL_QUADS);//b3 extended glass
     color = createColor(255, 253, 208,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-310,-210,0);
     glVertex3f(-240,-210,0);
     glVertex3f(-240,0,0);
     glVertex3f(-310,0,0);
     glEnd();

     glBegin(GL_QUADS);//flag
     color = createColor(255,255,255,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-270,150,0);
     glVertex3f(-180,150,0);
     glVertex3f(-180,210,0);
     glVertex3f(-270,210,0);
     glEnd();

    //flag circle
    color = createColor(242, 0, 0,0);
    glColor3f(color.red, color.green, color.blue);
    {
    int k;
    GLfloat x=-228.0f; GLfloat y=180.0f; GLfloat z=0.0f;GLfloat radius =20.0f;
	 int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(x,y,z); // center of circle
		for(k= 0; k<= triangleAmount;k++)
        {
			glVertex3f(
		            x + (radius * cos(k *  twicePi / triangleAmount)),
			    y + (radius * sin(k * twicePi / triangleAmount)),z
			);
		}
	glEnd();
    }

     glBegin(GL_QUADS);//b4
     color = createColor(102, 153, 153,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-200,-210,0);
     glVertex3f(0,-210,0);
     glVertex3f(0,0,0);
     glVertex3f(-200,0,0);
     glEnd();

     glBegin(GL_QUADS);//b4 glass
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-190,-200,0);
     glVertex3f(-10,-200,0);
     glVertex3f(-10,-110,0);
     glVertex3f(-190,-110,0);
     glEnd();

     glBegin(GL_QUADS);//b4 glass1
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-190,-100,0);
     glVertex3f(-110,-100,0);
     glVertex3f(-110,-90,0);
     glVertex3f(-190,-90,0);
     glEnd();

     glBegin(GL_QUADS);//b4 glass2
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-190,-80,0);
     glVertex3f(-110,-80,0);
     glVertex3f(-110,-70,0);
     glVertex3f(-190,-70,0);
     glEnd();

     glBegin(GL_QUADS);//b4 glass3
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-190,-60,0);
     glVertex3f(-110,-60,0);
     glVertex3f(-110,-50,0);
     glVertex3f(-190,-50,0);
     glEnd();

     glBegin(GL_QUADS);//b4 glass4
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-190,-40,0);
     glVertex3f(-110,-40,0);
     glVertex3f(-110,-30,0);
     glVertex3f(-190,-30,0);
     glEnd();

     glBegin(GL_QUADS);//b4 glass5
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-190,-20,0);
     glVertex3f(-110,-20,0);
     glVertex3f(-110,-10,0);
     glVertex3f(-190,-10,0);
     glEnd();

     glBegin(GL_QUADS);//b4 glass6
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-90,-100,0);
     glVertex3f(-10,-100,0);
     glVertex3f(-10,-90,0);
     glVertex3f(-90,-90,0);
     glEnd();

     glBegin(GL_QUADS);//b4 glass7
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-90,-80,0);
     glVertex3f(-10,-80,0);
     glVertex3f(-10,-70,0);
     glVertex3f(-90,-70,0);
     glEnd();

     glBegin(GL_QUADS);//b4 glass8
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-90,-60,0);
     glVertex3f(-10,-60,0);
     glVertex3f(-10,-50,0);
     glVertex3f(-90,-50,0);
     glEnd();

     glBegin(GL_QUADS);//b4 glass9
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-90,-40,0);
     glVertex3f(-10,-40,0);
     glVertex3f(-10,-30,0);
     glVertex3f(-90,-30,0);
     glEnd();

     glBegin(GL_QUADS);//b4 glass10
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-90,-20,0);
     glVertex3f(-10,-20,0);
     glVertex3f(-10,-10,0);
     glVertex3f(-90,-10,0);
     glEnd();

     glBegin(GL_QUADS);//b5
     color = createColor(179, 179, 204,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(0,-210,0);
     glVertex3f(250,-210,0);
     glVertex3f(250,-100,0);
     glVertex3f(0,-100,0);
     glEnd();

     glBegin(GL_QUADS);//b5 main glass
     color = createColor(255, 255, 204,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(10,-200,0);
     glVertex3f(120,-200,0);
     glVertex3f(120,-110,0);
     glVertex3f(10,-110,0);
     glEnd();

     glBegin(GL_QUADS);//b5 glass1
     color = createColor(255, 255, 204,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(130,-200,0);
     glVertex3f(240,-200,0);
     glVertex3f(240,-190,0);
     glVertex3f(130,-190,0);
     glEnd();

     glBegin(GL_QUADS);//b5 glass2
     color = createColor(255, 255, 204,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(130,-180,0);
     glVertex3f(240,-180,0);
     glVertex3f(240,-170,0);
     glVertex3f(130,-170,0);
     glEnd();

     glBegin(GL_QUADS);//b5 glass3
     color = createColor(255, 255, 204,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(130,-160,0);
     glVertex3f(240,-160,0);
     glVertex3f(240,-150,0);
     glVertex3f(130,-150,0);
     glEnd();

     glBegin(GL_QUADS);//b5 glass4
     color = createColor(255, 255, 204,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(130,-140,0);
     glVertex3f(240,-140,0);
     glVertex3f(240,-130,0);
     glVertex3f(130,-130,0);
     glEnd();

     glBegin(GL_QUADS);//b5 glass5
     color = createColor(255, 255, 204,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(130,-120,0);
     glVertex3f(240,-120,0);
     glVertex3f(240,-110,0);
     glVertex3f(130,-110,0);
     glEnd();

     glBegin(GL_QUADS);//b6
     color = createColor(102, 153, 153,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(30,-100,0);
     glVertex3f(210,-100,0);
     glVertex3f(210,90,0);
     glVertex3f(30,90,0);
     glEnd();

     glBegin(GL_QUADS);//b6 glass1
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(40,-90,0);
     glVertex3f(200,-90,0);
     glVertex3f(200,-80,0);
     glVertex3f(40,-80,0);
     glEnd();

     glBegin(GL_QUADS);//b6 glass12
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(40,-70,0);
     glVertex3f(200,-70,0);
     glVertex3f(200,-60,0);
     glVertex3f(40,-60,0);
     glEnd();

     glBegin(GL_QUADS);//b6 glass3
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(40,-50,0);
     glVertex3f(200,-50,0);
     glVertex3f(200,-40,0);
     glVertex3f(40,-40,0);
     glEnd();

     glBegin(GL_QUADS);//b6 glass4
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(40,-30,0);
     glVertex3f(200,-30,0);
     glVertex3f(200,-20,0);
     glVertex3f(40,-20,0);
     glEnd();

     glBegin(GL_QUADS);//b6 glass5
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(40,-10,0);
     glVertex3f(200,-10,0);
     glVertex3f(200,0,0);
     glVertex3f(40,0,0);
     glEnd();

     glBegin(GL_QUADS);//b6 glass6
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(40,10,0);
     glVertex3f(200,10,0);
     glVertex3f(200,20,0);
     glVertex3f(40,20,0);
     glEnd();

     glBegin(GL_QUADS);//b6 glass7
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(40,30,0);
     glVertex3f(200,30,0);
     glVertex3f(200,40,0);
     glVertex3f(40,40,0);
     glEnd();

     glBegin(GL_QUADS);//b6 glass8
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(40,50,0);
     glVertex3f(200,50,0);
     glVertex3f(200,60,0);
     glVertex3f(40,60,0);
     glEnd();

     glBegin(GL_QUADS);//b6 glass9
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(40,70,0);
     glVertex3f(200,70,0);
     glVertex3f(200,80,0);
     glVertex3f(40,80,0);
     glEnd();

     glBegin(GL_QUADS);//b7
     color = createColor(102, 153, 153,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,-210,0);
     glVertex3f(400,-210,0);
     glVertex3f(400,180,0);
     glVertex3f(250,180,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass1
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,-200,0);
     glVertex3f(400,-200,0);
     glVertex3f(400,-190,0);
     glVertex3f(250,-190,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass2
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,-180,0);
     glVertex3f(400,-180,0);
     glVertex3f(400,-170,0);
     glVertex3f(250,-170,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass3
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,-160,0);
     glVertex3f(400,-160,0);
     glVertex3f(400,-150,0);
     glVertex3f(250,-150,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass4
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,-140,0);
     glVertex3f(400,-140,0);
     glVertex3f(400,-130,0);
     glVertex3f(250,-130,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass5
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,-120,0);
     glVertex3f(400,-120,0);
     glVertex3f(400,-110,0);
     glVertex3f(250,-110,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass6
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,-100,0);
     glVertex3f(400,-100,0);
     glVertex3f(400,-90,0);
     glVertex3f(250,-90,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass7
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,-80,0);
     glVertex3f(400,-80,0);
     glVertex3f(400,-70,0);
     glVertex3f(250,-70,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass8
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,-60,0);
     glVertex3f(400,-60,0);
     glVertex3f(400,-50,0);
     glVertex3f(250,-50,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass9
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,-40,0);
     glVertex3f(400,-40,0);
     glVertex3f(400,-30,0);
     glVertex3f(250,-30,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass10
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,-20,0);
     glVertex3f(400,-20,0);
     glVertex3f(400,-10,0);
     glVertex3f(250,-10,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass11
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,0,0);
     glVertex3f(400,0,0);
     glVertex3f(400,10,0);
     glVertex3f(250,10,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass12
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,20,0);
     glVertex3f(400,20,0);
     glVertex3f(400,30,0);
     glVertex3f(250,30,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass13
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,40,0);
     glVertex3f(400,40,0);
     glVertex3f(400,50,0);
     glVertex3f(250,50,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass14
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,60,0);
     glVertex3f(400,60,0);
     glVertex3f(400,70,0);
     glVertex3f(250,70,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass15
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,80,0);
     glVertex3f(400,80,0);
     glVertex3f(400,90,0);
     glVertex3f(250,90,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass16
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,100,0);
     glVertex3f(400,100,0);
     glVertex3f(400,110,0);
     glVertex3f(250,110,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass17
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,120,0);
     glVertex3f(400,120,0);
     glVertex3f(400,130,0);
     glVertex3f(250,130,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass18
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,140,0);
     glVertex3f(400,140,0);
     glVertex3f(400,150,0);
     glVertex3f(250,150,0);
     glEnd();

     glBegin(GL_QUADS);//b7 glass19
     color = createColor(0,0,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(250,160,0);
     glVertex3f(400,160,0);
     glVertex3f(400,170,0);
     glVertex3f(250,170,0);
     glEnd();

     glBegin(GL_QUADS);//b8
     color = createColor(153, 153, 255,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(400,-210,0);
     glVertex3f(470,-210,0);
     glVertex3f(470,210,0);
     glVertex3f(400,210,0);
     glEnd();

     glBegin(GL_QUADS);//b8 middle
     color = createColor(255, 165, 0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(410,-200,0);
     glVertex3f(460,-200,0);
     glVertex3f(460,200,0);
     glVertex3f(410,200,0);
     glEnd();

     glBegin(GL_QUADS);//b9
     color = createColor(150, 75,0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,-210,0);
     glVertex3f(670,-210,0);
     glVertex3f(670,120,0);
     glVertex3f(470,120,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass1
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,-200,0);
     glVertex3f(670,-200,0);
     glVertex3f(670,-190,0);
     glVertex3f(470,-190,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass2
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,-180,0);
     glVertex3f(670,-180,0);
     glVertex3f(670,-170,0);
     glVertex3f(470,-170,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass3
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,-160,0);
     glVertex3f(670,-160,0);
     glVertex3f(670,-150,0);
     glVertex3f(470,-150,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass4
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,-140,0);
     glVertex3f(670,-140,0);
     glVertex3f(670,-130,0);
     glVertex3f(470,-130,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass5
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,-120,0);
     glVertex3f(670,-120,0);
     glVertex3f(670,-110,0);
     glVertex3f(470,-110,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass6
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,-100,0);
     glVertex3f(670,-100,0);
     glVertex3f(670,-90,0);
     glVertex3f(470,-90,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass7
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,-80,0);
     glVertex3f(670,-80,0);
     glVertex3f(670,-70,0);
     glVertex3f(470,-70,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass8
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,-60,0);
     glVertex3f(670,-60,0);
     glVertex3f(670,-50,0);
     glVertex3f(470,-50,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass9
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,-40,0);
     glVertex3f(670,-40,0);
     glVertex3f(670,-30,0);
     glVertex3f(470,-30,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass10
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,-20,0);
     glVertex3f(670,-20,0);
     glVertex3f(670,-10,0);
     glVertex3f(470,-10,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass11
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,0,0);
     glVertex3f(670,0,0);
     glVertex3f(670,10,0);
     glVertex3f(470,10,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass12
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,20,0);
     glVertex3f(670,20,0);
     glVertex3f(670,30,0);
     glVertex3f(470,30,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass13
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,40,0);
     glVertex3f(670,40,0);
     glVertex3f(670,50,0);
     glVertex3f(470,50,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass14
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,60,0);
     glVertex3f(670,60,0);
     glVertex3f(670,70,0);
     glVertex3f(470,70,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass15
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,80,0);
     glVertex3f(670,80,0);
     glVertex3f(670,90,0);
     glVertex3f(470,90,0);
     glEnd();

     glBegin(GL_QUADS);//b9 glass16
     color = createColor(255, 255, 20,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(470,100,0);
     glVertex3f(670,100,0);
     glVertex3f(670,110,0);
     glVertex3f(470,110,0);
     glEnd();

     glBegin(GL_QUADS);//road
     color = createColor(115, 115, 115,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,-280,0);
     glVertex3f(670,-280,0);
     glVertex3f(670,-210,0);
     glVertex3f(-670,-210,0);
     glEnd();

     glBegin(GL_QUADS);//road line1
     color = createColor(230, 255, 255,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-600,-250,0);
     glVertex3f(-550,-250,0);
     glVertex3f(-550,-240,0);
     glVertex3f(-600,-240,0);
     glEnd();

     glBegin(GL_QUADS);//road line2
     color = createColor(230, 255, 255,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-500,-250,0);
     glVertex3f(-450,-250,0);
     glVertex3f(-450,-240,0);
     glVertex3f(-500,-240,0);
     glEnd();

     glBegin(GL_QUADS);//road line3
     color = createColor(230, 255, 255,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-400,-250,0);
     glVertex3f(-350,-250,0);
     glVertex3f(-350,-240,0);
     glVertex3f(-400,-240,0);
     glEnd();

     glBegin(GL_QUADS);//road line4
     color = createColor(230, 255, 255,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-300,-250,0);
     glVertex3f(-250,-250,0);
     glVertex3f(-250,-240,0);
     glVertex3f(-300,-240,0);
     glEnd();

     glBegin(GL_QUADS);//road line5
     color = createColor(230, 255, 255,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-200,-250,0);
     glVertex3f(-150,-250,0);
     glVertex3f(-150,-240,0);
     glVertex3f(-200,-240,0);
     glEnd();

     glBegin(GL_QUADS);//road line6
     color = createColor(230, 255, 255,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-100,-250,0);
     glVertex3f(-50,-250,0);
     glVertex3f(-50,-240,0);
     glVertex3f(-100,-240,0);
     glEnd();

     glBegin(GL_QUADS);//road line7
     color = createColor(230, 255, 255,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(0,-250,0);
     glVertex3f(50,-250,0);
     glVertex3f(50,-240,0);
     glVertex3f(0,-240,0);
     glEnd();

     glBegin(GL_QUADS);//road line8
     color = createColor(230, 255, 255,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(100,-250,0);
     glVertex3f(150,-250,0);
     glVertex3f(150,-240,0);
     glVertex3f(100,-240,0);
     glEnd();

     glBegin(GL_QUADS);//road line9
     color = createColor(230, 255, 255,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(200,-250,0);
     glVertex3f(250,-250,0);
     glVertex3f(250,-240,0);
     glVertex3f(200,-240,0);
     glEnd();

     glBegin(GL_QUADS);//road line10
     color = createColor(230, 255, 255,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(300,-250,0);
     glVertex3f(350,-250,0);
     glVertex3f(350,-240,0);
     glVertex3f(300,-240,0);
     glEnd();

     glBegin(GL_QUADS);//road line11
     color = createColor(230, 255, 255,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(400,-250,0);
     glVertex3f(450,-250,0);
     glVertex3f(450,-240,0);
     glVertex3f(400,-240,0);
     glEnd();

     glBegin(GL_QUADS);//road line12
     color = createColor(230, 255, 255,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(500,-250,0);
     glVertex3f(550,-250,0);
     glVertex3f(550,-240,0);
     glVertex3f(500,-240,0);
     glEnd();

     glBegin(GL_QUADS);//lawn
     color = createColor(102, 153, 0,0);
     glColor3f(color.red, color.green, color.blue);
     glVertex3f(-670,-350,0);
     glVertex3f(670,-350,0);
     glVertex3f(670,-280,0);
     glVertex3f(-670,-280,0);
     glEnd();

     //sun
    color = createColor(242, 255, 0,0);
    glColor3f(color.red, color.green, color.blue);
    {

    int k;
    GLfloat x=-600.0f; GLfloat y=250.0f; GLfloat z=0.0f;GLfloat radius =50.0f;
	 int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(x,y,z); // center of circle
		for(k = 0; k <= triangleAmount;k++)
        {
			glVertex3f(
		            x + (radius * cos(k *  twicePi / triangleAmount)),
			    y + (radius * sin(k * twicePi / triangleAmount)),z
			);
		}
    }
	glEnd();
    glLineWidth(12.5);
}

void Background()
{
    glPushMatrix();
  //gradient BG
    glBegin(GL_POLYGON);
        color = createColor(109, 209, 241, 0);
        glColor3f(color.red, color.green, color.blue);
        glVertex3f(-670,-350, -2);
        glVertex3f(670, -350, -2);
        glVertex3f(670, 350, -2);
        glVertex3f(-670, 350, -2);
    glEnd();
      //drawing clouds
      Clouds(25);
      Clouds(25);
      Clouds(25);
      Clouds(25);
    glPopMatrix();
}

void keyboardDown(unsigned char key, int x, int y)
{
  switch(key)
  {
  case 49: //enter 1
    scene += 1;
    if (scene >9)
        exit(0);
    break;
  case 50: //enter 2
    scene -= 1;
    if (scene<0)
        scene=0;
    break;
  case 'Q':
  case 'q':
  case  27:   // ESC
    exit(0);
  }
}

void reshape(int width, int height)
{
  GLfloat fieldOfView = 90.0f;
  glViewport (0, 0, (GLsizei) width, (GLsizei) height);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-662, 662, -350, 350, -450, 450);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void scene1()
{
    glPushMatrix();
        MainScene1();
    glPopMatrix();

}

void scene2()
{
    glPushMatrix();
        Background();
        Jet();
    glPopMatrix();
}

void scene3()
{
    glPushMatrix();
        MainScene2();
    glPopMatrix();
}

void scene4()
{
    glPushMatrix();
        Background();
        City();
    glPopMatrix();
}

void scene5()
{
    glPushMatrix();
        MainScene3();
    glPopMatrix();
}

void scene6()
{
    glPushMatrix();
        if(flag3 == 0)
        {
            i =-420;
            j= -100;
            flag3=1;
        }
        Background();
        Jet();
        if(int(i) == 400)
         h = 1;
        if (h)
        {
            glPushMatrix();
                Bomb();
            glPopMatrix();
        }
    glPopMatrix();
}

void scene7()
{
    glPushMatrix();
        MainScene4();
    glPopMatrix();
}

void scene8()
{
    glPushMatrix();
        if(flag2 == 0)
        {
            i =-690;
            j= 400;
            flag2=1;
        }
        Background();
        City();
        Bomb();
        if(int(j) == -420)
         Bombed = 1;
        if (Bombed)
        {
            glPushMatrix();
                glLoadIdentity();
                glScalef(explodeTx, explodeTy, 0);
                glTranslatef(0.05, 0, 0);
                explode();
            glPopMatrix();

            glPushMatrix();
                glLoadIdentity();
                glScalef(explodeTx, explodeTy, 0);
                glTranslatef(0.1, 0, 0);
                explode();
            glPopMatrix();

            if (explodeTx <= 1.3)
            {
                explodeTx = explodeTy += 0.001;
            }
        expFactor = (float) (expFactor >= 1000 ? expFactor : expFactor + 3); //0.97
    }
    glPopMatrix();
}

void scene9()
{
    glPushMatrix();
        MainScene5();
    glPopMatrix();
}

void scene10()
{
    glPushMatrix();
        MainScene6();
    glPopMatrix();
}

void draw()
{
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();

      /* render the scene here */
      switch(scene)
      {
        case 0:
          scene1();
          break;
        case 1:
          scene2();
          break;
        case 2:
          scene3();
          break;
        case 3:
          scene4();
          break;
        case 4:
          scene5();
          break;
        case 5:
          scene6();
          break;
        case 6:
          scene7();
          break;
        case 7:
          scene8();
          break;
        case 8:
          scene9();
          break;
        case 9:
          scene10();
          break;
      }
      glFlush();
      glutSwapBuffers();
}

void idle()
{
  glutPostRedisplay();
}

void initGL(int width, int height)
{
  reshape(width, height);
  glClearColor(0.2f, 0.8f, 1.0f, 1.0f );
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1244, 700);
  glutInitWindowPosition(100, 0);
  glutCreateWindow("HIROSHIMA BOMBING");

  // register glut call backs
  glutKeyboardFunc(keyboardDown);
  glutReshapeFunc(reshape);
  glutDisplayFunc(draw);
  glutIdleFunc(idle);
  glutIgnoreKeyRepeat(1); // ignore keys held down

  int submenu = glutCreateMenu(options); //sub menu
  glutAddMenuEntry("Really quit",2);
  glutAddMenuEntry("No",0);

  glutCreateMenu(options);//menu
  glutAddMenuEntry("Light candles for Peace",1);
  glutAddSubMenu("Quit",submenu);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  initGL(1244, 700);
  glutMainLoop();
  return 0;
}
